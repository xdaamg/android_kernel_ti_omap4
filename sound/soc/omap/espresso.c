/*
 *  sound/soc/omap/omap4_wm8994.c
 *
 *  Copyright (c) 2009 Samsung Electronics Co. Ltd
 *
 *  This program is free software; you can redistribute  it and/or  modify it
 *  under  the terms of  the GNU General  Public License as published by the
 *  Free Software Foundation;  either version 2 of the  License, or (at your
 *  option) any later version.
 */

#include <linux/module.h>
#include <linux/clk.h>
#include <linux/platform_device.h>
#include <linux/i2c.h>
#include <linux/i2c/twl.h>
#include <sound/core.h>
#include <linux/slab.h>
#include <linux/workqueue.h>
#include <linux/regulator/machine.h>
#include <linux/input.h>
#include <linux/wakelock.h>
#include <linux/suspend.h>
#include <linux/delay.h>

#include <sound/soc.h>
#include <sound/soc-dapm.h>
#include <sound/pcm.h>
#include <sound/pcm_params.h>
#include <sound/jack.h>

#include <linux/mfd/wm8994/core.h>
#include <linux/mfd/wm8994/registers.h>
#include <linux/mfd/wm8994/pdata.h>

#include <asm/mach-types.h>
#include <plat/hardware.h>
#include <plat/mcbsp.h>
#include <linux/gpio.h>

#include "omap-pcm.h"
#include "omap-mcbsp.h"
#include "../codecs/wm8994.h"

#include "../../../arch/arm/mach-omap2/board-espresso.h"

#define WM8994_DEFAULT_MCLK1	26000000
#define WM8994_DEFAULT_MCLK2	32768
#define WM8994_DEFAULT_SYNC_CLK	11289600

#define USE_SND_EAR_GND_SEL

struct snd_soc_codec *the_codec;
int dock_status;

static struct pm_qos_request pm_qos_handle;

static struct gpio mclk = {
	.flags = GPIOF_OUT_INIT_LOW,
	.label = "CODEC_CLK_REQ",
};

static struct gpio main_mic_bias = {
	.flags  = GPIOF_OUT_INIT_LOW,
	.label  = "MICBIAS_EN",
};

static struct gpio sub_mic_bias = {
	.flags  = GPIOF_OUT_INIT_LOW,
	.label  = "SUB_MICBIAS_EN",
};

#ifdef USE_SND_EAR_GND_SEL
static struct gpio ear_select = {
	.flags = GPIOF_OUT_INIT_LOW,
	.label = "EAR_GND_SEL",
};

static int hp_output_mode;
const char *hp_analogue_text[] = {
	"VoiceCall Mode", "Playback Mode"
};
#endif /* USE_SND_EAR_GND_SEL */

static int input_clamp;
const char *input_clamp_text[] = {
	"Off", "On"
};

static int aif2_mode;
const char *aif2_mode_text[] = {
	"Slave", "Master"
};

static int pm_mode;
const char *pm_mode_text[] = {
	"Off", "On"
};

static void set_mclk(bool on)
{
	if (on)
		gpio_set_value(mclk.gpio, 1);
	else
		gpio_set_value(mclk.gpio, 0);
}

static int main_mic_bias_event(struct snd_soc_dapm_widget *w,
			struct snd_kcontrol *kcontrol, int event)
{
	gpio_set_value(main_mic_bias.gpio, SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

static int sub_mic_bias_event(struct snd_soc_dapm_widget *w,
			struct snd_kcontrol *kcontrol, int event)
{
	gpio_set_value(sub_mic_bias.gpio, SND_SOC_DAPM_EVENT_ON(event));
	return 0;
}

#ifdef USE_SND_EAR_GND_SEL
static const struct soc_enum hp_mode_enum[] = {
	SOC_ENUM_SINGLE_EXT(ARRAY_SIZE(hp_analogue_text), hp_analogue_text),
};

static int get_hp_output_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = hp_output_mode;
	return 0;
}

static int set_hp_output_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	if (hp_output_mode == ucontrol->value.integer.value[0])
		return 0;

	hp_output_mode = ucontrol->value.integer.value[0];
	gpio_set_value(ear_select.gpio, hp_output_mode);

	pr_debug("set hp mode : %s\n", hp_analogue_text[hp_output_mode]);

	return 0;
}
#endif /* USE_SND_EAR_GND_SEL */

static const struct soc_enum input_clamp_enum[] = {
	SOC_ENUM_SINGLE_EXT(ARRAY_SIZE(input_clamp_text), input_clamp_text),
};

static int get_input_clamp(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = input_clamp;
	return 0;
}

static int set_input_clamp(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	struct snd_soc_codec *codec = snd_kcontrol_chip(kcontrol);

	input_clamp = ucontrol->value.integer.value[0];

	if (input_clamp) {
		snd_soc_update_bits(codec, WM8994_INPUT_MIXER_1,
				WM8994_INPUTS_CLAMP, WM8994_INPUTS_CLAMP);
		msleep(100);
	} else {
		snd_soc_update_bits(codec, WM8994_INPUT_MIXER_1,
				WM8994_INPUTS_CLAMP, 0);
	}
	pr_info("set fm input_clamp : %s\n", input_clamp_text[input_clamp]);

	return 0;
}

static const struct soc_enum aif2_mode_enum[] = {
	SOC_ENUM_SINGLE_EXT(ARRAY_SIZE(aif2_mode_text), aif2_mode_text),
};

static int get_aif2_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = aif2_mode;
	return 0;
}

static int set_aif2_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	if (aif2_mode == ucontrol->value.integer.value[0])
		return 0;

	aif2_mode = ucontrol->value.integer.value[0];

	pr_info("set aif2 mode : %s\n", aif2_mode_text[aif2_mode]);

	return 0;
}

static const struct soc_enum pm_mode_enum[] = {
	SOC_ENUM_SINGLE_EXT(ARRAY_SIZE(pm_mode_text), pm_mode_text),
};

static int get_pm_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	ucontrol->value.integer.value[0] = pm_mode;
	return 0;
}

static int set_pm_mode(struct snd_kcontrol *kcontrol,
	struct snd_ctl_elem_value *ucontrol)
{
	if (pm_mode == ucontrol->value.integer.value[0])
		return 0;

	if (pm_mode)
		pm_qos_update_request(&pm_qos_handle, PM_QOS_DEFAULT_VALUE);
	else
		pm_qos_update_request(&pm_qos_handle, 7);

	pm_mode = ucontrol->value.integer.value[0];

	pr_info("set pm mode : %s\n", pm_mode_text[pm_mode]);

	return 0;
}

void notify_dock_status(int status)
{
	if (!the_codec)
		return;

	dock_status = status;
	pr_info("%s: status=%d", __func__, dock_status);

	if (the_codec->suspended)
		return;

	if (status)
		wm8994_vmid_mode(the_codec, WM8994_VMID_FORCE);
	else
		wm8994_vmid_mode(the_codec, WM8994_VMID_NORMAL);
}

static int omap4_wm8994_start_fll1(struct snd_soc_dai *aif1_dai)
{
	int ret;

	dev_dbg(aif1_dai->dev, "Moving to audio clocking settings\n");

	/* Switch the FLL */
	ret = snd_soc_dai_set_pll(aif1_dai,
				  WM8994_FLL1,
				  WM8994_FLL_SRC_MCLK1,
				  WM8994_DEFAULT_MCLK1, 44100 * 256);
	if (ret < 0)
		dev_err(aif1_dai->dev, "Unable to start FLL1: %d\n", ret);

	/* Then switch AIF1CLK to it */
	ret = snd_soc_dai_set_sysclk(aif1_dai,
				     WM8994_SYSCLK_FLL1,
				     44100 * 256,
				     SND_SOC_CLOCK_IN);
	if (ret < 0)
		dev_err(aif1_dai->dev, "Unable to switch to FLL1: %d\n", ret);

	return ret;
}

static int omap4_hifi_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	struct snd_soc_dai *cpu_dai = rtd->cpu_dai;
	int ret;

	ret = snd_soc_dai_set_fmt(codec_dai,
				SND_SOC_DAIFMT_I2S |
				SND_SOC_DAIFMT_NB_NF |
				SND_SOC_DAIFMT_CBM_CFM);
	if (ret < 0) {
		pr_err("can't set codec DAI configuration\n");
		return ret;
	}

	ret = snd_soc_dai_set_fmt(cpu_dai,
				SND_SOC_DAIFMT_I2S |
				SND_SOC_DAIFMT_NB_NF |
				SND_SOC_DAIFMT_CBM_CFM);
	if (ret < 0) {
		pr_err("can't set CPU DAI configuration\n");
		return ret;
	}

	ret = omap4_wm8994_start_fll1(codec_dai);
	if (ret < 0) {
		pr_err("can't start fll1\n");
		return ret;
	}

	return 0;
}

static struct snd_soc_ops hifi_ops = {
	.hw_params = omap4_hifi_hw_params,
};

static int omap4_wm8994_aif2_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params)
{
	struct snd_soc_pcm_runtime *rtd = substream->private_data;
	struct snd_soc_dai *codec_dai = rtd->codec_dai;
	int ret;
	int prate;
	int bclk;

	pr_debug("%s: enter, aif2_mode=%d\n", __func__, aif2_mode);

	prate = params_rate(params);
	switch (prate) {
	case 8000:
	case 16000:
		break;
	default:
		dev_warn(codec_dai->dev, "Unsupported LRCLK %d, falling back to 8000Hz\n",
			(int)params_rate(params));
		prate = 8000;
	}

	/* Set the codec DAI configuration */
	if (aif2_mode == 0) {
		ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S
				| SND_SOC_DAIFMT_NB_NF
				| SND_SOC_DAIFMT_CBS_CFS);
	} else {
		ret = snd_soc_dai_set_fmt(codec_dai, SND_SOC_DAIFMT_I2S
				| SND_SOC_DAIFMT_NB_NF
				| SND_SOC_DAIFMT_CBM_CFM);
	}
	if (ret < 0)
		return ret;

	switch (prate) {
	case 8000:
		bclk = 256000;
		break;
	case 16000:
		bclk = 512000;
		break;
	default:
		return -EINVAL;
	}

	if (aif2_mode == 0) {
		ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL2,
				WM8994_FLL_SRC_BCLK,
				bclk, prate * 256);
	} else {
		ret = snd_soc_dai_set_pll(codec_dai, WM8994_FLL2,
				WM8994_FLL_SRC_MCLK1,
				WM8994_DEFAULT_MCLK1, prate * 256);
	}
	if (ret < 0)
		dev_err(codec_dai->dev, "Unable to configure FLL2: %d\n", ret);

	ret = snd_soc_dai_set_sysclk(codec_dai, WM8994_SYSCLK_FLL2,
				prate * 256, SND_SOC_CLOCK_IN);
	if (ret < 0)
		dev_err(codec_dai->dev, "Unable to switch to FLL2: %d\n", ret);

	return 0;
}

static struct snd_soc_ops omap4_wm8994_aif2_ops = {
	.hw_params = omap4_wm8994_aif2_hw_params,
};

static int omap4_wm8994_aif3_hw_params(struct snd_pcm_substream *substream,
			      struct snd_pcm_hw_params *params)
{
	pr_err("%s: enter\n", __func__);
	return 0;
}

static struct snd_soc_ops omap4_wm8994_aif3_ops = {
	.hw_params = omap4_wm8994_aif3_hw_params,
};

static const struct snd_kcontrol_new omap4_controls[] = {
	SOC_DAPM_PIN_SWITCH("HP"),
	SOC_DAPM_PIN_SWITCH("SPK"),
	SOC_DAPM_PIN_SWITCH("RCV"),
	SOC_DAPM_PIN_SWITCH("LINEOUT"),

	SOC_DAPM_PIN_SWITCH("Main Mic"),

	SOC_DAPM_PIN_SWITCH("Headset Mic"),

#ifdef USE_SND_EAR_GND_SEL
	SOC_ENUM_EXT("HP Output Mode", hp_mode_enum[0],
		get_hp_output_mode, set_hp_output_mode),
#endif /* USE_SND_EAR_GND_SEL */

	SOC_ENUM_EXT("Input Clamp", input_clamp_enum[0],
		get_input_clamp, set_input_clamp),
	SOC_ENUM_EXT("AIF2 Mode", aif2_mode_enum[0],
		get_aif2_mode, set_aif2_mode),
	SOC_ENUM_EXT("PM Constraints Mode", pm_mode_enum[0],
		get_pm_mode, set_pm_mode),
};

static const struct snd_kcontrol_new omap4_submic_controls[] = {
	SOC_DAPM_PIN_SWITCH("Sub Mic"),
};

const struct snd_soc_dapm_widget omap4_dapm_widgets[] = {
	SND_SOC_DAPM_HP("HP", NULL),
	SND_SOC_DAPM_SPK("SPK", NULL),
	SND_SOC_DAPM_SPK("RCV", NULL),
	SND_SOC_DAPM_LINE("LINEOUT", NULL),

	SND_SOC_DAPM_MIC("Main Mic", main_mic_bias_event),

	SND_SOC_DAPM_MIC("Headset Mic", NULL),
};

const struct snd_soc_dapm_widget omap4_dapm_submic_widgets[] = {
	SND_SOC_DAPM_MIC("Sub Mic", sub_mic_bias_event),
};

const struct snd_soc_dapm_route omap4_dapm_routes[] = {
	{ "HP", NULL, "HPOUT1L" },
	{ "HP", NULL, "HPOUT1R" },

	{ "SPK", NULL, "SPKOUTLN" },
	{ "SPK", NULL, "SPKOUTLP" },
	{ "SPK", NULL, "SPKOUTRN" },
	{ "SPK", NULL, "SPKOUTRP" },

	{ "RCV", NULL, "HPOUT2N" },
	{ "RCV", NULL, "HPOUT2P" },

	{ "LINEOUT", NULL, "LINEOUT1N" },
	{ "LINEOUT", NULL, "LINEOUT1P" },

	{ "IN1LP", NULL, "Main Mic" },
	{ "IN1LN", NULL, "Main Mic" },

	{ "IN1RP", NULL, "MICBIAS2" },
	{ "IN1RN", NULL, "MICBIAS2" },
	{ "MICBIAS2", NULL, "Headset Mic" },
};

const struct snd_soc_dapm_route omap4_submic_dapm_routes[] = {
	{ "IN2RP:VXRP", NULL, "Sub Mic" },
	{ "IN2RN", NULL, "Sub Mic" },
};

int omap4_wm8994_init(struct snd_soc_pcm_runtime *rtd)
{
	struct snd_soc_codec *codec = rtd->codec;
	struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);
	struct snd_soc_dapm_context *dapm = &codec->dapm;
	struct snd_soc_dai *aif1_dai = rtd->codec_dai;
	int ret;

	the_codec = codec;

	mclk.gpio = wm8994->pdata->mclk_gpio;
	ret = gpio_request(mclk.gpio, "mclk");
	if (ret < 0)
		goto mclk_err;
	gpio_direction_output(mclk.gpio, 0);

	main_mic_bias.gpio = wm8994->pdata->main_mic_bias_gpio;
	ret = gpio_request(main_mic_bias.gpio, "main_mic_bias");
	if (ret < 0)
		goto main_mic_err;
	gpio_direction_output(main_mic_bias.gpio, 0);

#ifdef USE_SND_EAR_GND_SEL
	hp_output_mode = 1;
	ear_select.gpio = wm8994->pdata->ear_select_gpio;
	ret = gpio_request(ear_select.gpio, "ear_select");
	if (ret < 0)
		goto ear_select_err;
	gpio_direction_output(ear_select.gpio, hp_output_mode);
#endif /* USE_SND_EAR_GND_SEL */

	set_mclk(true); /* enable 26M CLK */

	ret = snd_soc_add_card_controls(dapm->card, omap4_controls,
				ARRAY_SIZE(omap4_controls));

	if (wm8994->pdata->use_submic) {
		sub_mic_bias.gpio = wm8994->pdata->submic_gpio;
		ret = gpio_request(sub_mic_bias.gpio, "sub_mic_bias");
		if (ret < 0) {
			pr_err("%s: failed to request gpio %s\n", __func__, sub_mic_bias.label);
			wm8994->pdata->use_submic = false;
			goto submic_error;
		}
		gpio_direction_output(sub_mic_bias.gpio, 0);

		snd_soc_add_card_controls(dapm->card, omap4_submic_controls,
					ARRAY_SIZE(omap4_submic_controls));
	}
submic_error:

	ret = snd_soc_dapm_new_controls(dapm, omap4_dapm_widgets,
					ARRAY_SIZE(omap4_dapm_widgets));

	if (wm8994->pdata->use_submic) {
		snd_soc_dapm_new_controls(dapm, omap4_dapm_submic_widgets,
					ARRAY_SIZE(omap4_dapm_submic_widgets));
	}

	if (ret != 0)
		dev_err(codec->dev, "Failed to add DAPM widgets: %d\n", ret);

	ret = snd_soc_dapm_add_routes(dapm, omap4_dapm_routes,
					ARRAY_SIZE(omap4_dapm_routes));

	if (wm8994->pdata->use_submic) {
		snd_soc_dapm_add_routes(dapm, omap4_submic_dapm_routes,
						ARRAY_SIZE(omap4_submic_dapm_routes));
	}

	if (ret != 0)
		dev_err(codec->dev, "Failed to add DAPM routes: %d\n", ret);

	ret = snd_soc_dai_set_sysclk(aif1_dai, WM8994_SYSCLK_MCLK2,
				     WM8994_DEFAULT_MCLK2, SND_SOC_CLOCK_IN);
	if (ret < 0)
		dev_err(codec->dev, "Failed to boot clocking\n");

	ret = snd_soc_dapm_force_enable_pin(dapm, "AIF1CLK");
	if (ret < 0)
		dev_err(codec->dev, "Failed to enable AIF1CLK: %d\n", ret);

	/* set up NC codec pins */
	snd_soc_dapm_nc_pin(dapm, "IN2LP:VXRN");
	snd_soc_dapm_nc_pin(dapm, "IN2LN");

	/* set up ignore pins */
	snd_soc_dapm_ignore_suspend(dapm, "RCV");
	snd_soc_dapm_ignore_suspend(dapm, "SPK");
	snd_soc_dapm_ignore_suspend(dapm, "LINEOUT");
	snd_soc_dapm_ignore_suspend(dapm, "HP");
	snd_soc_dapm_ignore_suspend(dapm, "Main Mic");
	if (wm8994->pdata->use_submic) {
		snd_soc_dapm_ignore_suspend(dapm, "Sub Mic");
	}

	snd_soc_dapm_ignore_suspend(dapm, "Headset Mic");
	snd_soc_dapm_ignore_suspend(dapm, "AIF1DACDAT");
	snd_soc_dapm_ignore_suspend(dapm, "AIF2DACDAT");
	snd_soc_dapm_ignore_suspend(dapm, "AIF3DACDAT");
	snd_soc_dapm_ignore_suspend(dapm, "AIF1ADCDAT");
	snd_soc_dapm_ignore_suspend(dapm, "AIF2ADCDAT");
	snd_soc_dapm_ignore_suspend(dapm, "AIF3ADCDAT");

	/* By default use idle_bias_off, will override for WM8994 */
	codec->dapm.idle_bias_off = 0;

	return snd_soc_dapm_sync(dapm);

#ifdef USE_SND_EAR_GND_SEL
ear_select_err:
	gpio_free(ear_select.gpio);
#endif /* USE_SND_EAR_GND_SEL */
main_mic_err:
	gpio_free(main_mic_bias.gpio);
mclk_err:
	gpio_free(mclk.gpio);

	return ret;
}

static struct snd_soc_dai_driver ext_dai[] = {
{
	.name = "CP",
	.playback = {
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = 8000,
		.rate_max = 16000,
		.rates = SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
	},
	.capture = {
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = 8000,
		.rate_max = 16000,
		.rates = SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
	},
},
{
	.name = "BT",
	.playback = {
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = 8000,
		.rate_max = 16000,
		.rates = SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
	},
	.capture = {
		.channels_min = 1,
		.channels_max = 2,
		.rate_min = 8000,
		.rate_max = 16000,
		.rates = SNDRV_PCM_RATE_8000 | SNDRV_PCM_RATE_16000,
		.formats = SNDRV_PCM_FMTBIT_S16_LE,
	},
},
};

static struct snd_soc_dai_link omap4_dai[] = {
{
	.name = "MCBSP AIF1",
	.stream_name = "HIFI MCBSP Tx/RX",
	.cpu_dai_name = "omap-mcbsp.3",
	.codec_dai_name = "wm8994-aif1",
	.platform_name = "omap-pcm-audio",
	.codec_name = "wm8994-codec",
	.init = omap4_wm8994_init,
	.ops = &hifi_ops,
},
{
	.name = "WM1811 Voice",
	.stream_name = "Voice Tx/Rx",
	.cpu_dai_name = "CP",
	.codec_dai_name = "wm8994-aif2",
	.platform_name = "snd-soc-dummy",
	.codec_name = "wm8994-codec",
	.ignore_suspend = 1,
	.ops = &omap4_wm8994_aif2_ops,
},
{
	.name = "WM1811 BT",
	.stream_name = "BT Tx/Rx",
	.cpu_dai_name = "BT",
	.codec_dai_name = "wm8994-aif3",
	.platform_name = "snd-soc-dummy",
	.codec_name = "wm8994-codec",
	.ignore_suspend = 1,
	.ops = &omap4_wm8994_aif3_ops,
},
};

static int wm8994_suspend_pre(struct snd_soc_card *card)
{
	struct snd_soc_codec *codec = card->rtd->codec;
	struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);

	if (dock_status == 1 && wm8994->vmid_mode == WM8994_VMID_FORCE) {
		pr_info("%s: entering force vmid mode\n", __func__);
		wm8994_vmid_mode(codec, WM8994_VMID_NORMAL);
	}

	snd_soc_dapm_disable_pin(&codec->dapm, "AIF1CLK");

	return 0;
}

static int wm8994_resume_post(struct snd_soc_card *card)
{
	struct snd_soc_codec *codec = card->rtd->codec;
	struct wm8994_priv *wm8994 = snd_soc_codec_get_drvdata(codec);

	if (dock_status == 1 && wm8994->vmid_mode == WM8994_VMID_NORMAL) {
		pr_info("%s: entering normal vmid mode\n", __func__);
		wm8994_vmid_mode(codec, WM8994_VMID_FORCE);
	}

	snd_soc_dapm_force_enable_pin(&codec->dapm, "AIF1CLK");

	return 0;
}

static int wm8994_suspend_post(struct snd_soc_card *card)
{
	struct snd_soc_codec *codec = card->rtd->codec;

	if (!codec->active) {
		set_mclk(false); /* disble 26M CLK */
	}
	return 0;
}

static int wm8994_resume_pre(struct snd_soc_card *card)
{
	set_mclk(true); /* enable 26M CLK */
	return 0;
}

static struct snd_soc_card omap4_wm8994 = {
	.name = "omap4_wm8994",
	.dai_link = omap4_dai,
	.num_links = ARRAY_SIZE(omap4_dai),
	.suspend_post = wm8994_suspend_post,
	.resume_pre = wm8994_resume_pre,
	.suspend_pre = wm8994_suspend_pre,
	.resume_post = wm8994_resume_post,
};

static int __devinit espresso_audio_probe(struct platform_device *pdev)
{
	struct snd_soc_card *card = &omap4_wm8994;
	int ret;

	card->dev = &pdev->dev;

	pm_qos_add_request(&pm_qos_handle, PM_QOS_CPU_DMA_LATENCY,
						PM_QOS_DEFAULT_VALUE);

	ret = snd_soc_register_dais(&pdev->dev,
				ext_dai, ARRAY_SIZE(ext_dai));
	if (ret != 0) {
		pr_err("%s: failed to register external DAIs: %d\n",
			__func__, ret);
		goto err;
	}

	ret = snd_soc_register_card(card);
	if (ret)
		dev_err(&pdev->dev, "snd_soc_register_card() failed: %d\n",
			ret);

err:
	return ret;
}

static int __devexit espresso_audio_remove(struct platform_device *pdev)
{
	struct snd_soc_card *card = platform_get_drvdata(pdev);

	snd_soc_unregister_card(card);

	pm_qos_remove_request(&pm_qos_handle);

	return 0;
}

static struct platform_driver espresso_audio_driver = {
	.driver		= {
		.name	= "espresso-audio",
		.owner	= THIS_MODULE,
	},
	.probe		= espresso_audio_probe,
	.remove		= __devexit_p(espresso_audio_remove),
};

module_platform_driver(espresso_audio_driver);

MODULE_AUTHOR("Quartz.Jang <quartz.jang@samsung.com");
MODULE_DESCRIPTION("ALSA Soc WM8994 omap4");
MODULE_LICENSE("GPL");
MODULE_ALIAS("platform:espresso-audio");
