/*
 * OMAP54xx CTRL_MODULE_WKUP_PAD registers and bitfields
 *
 * Copyright (C) 2012 Texas Instruments Incorporated - http://www.ti.com
 *
 * Benoit Cousson (b-cousson@ti.com)
 *
 * This file is automatically generated from the OMAP hardware databases.
 * We respectfully ask that any modifications to this file be coordinated
 * with the public linux-omap@vger.kernel.org mailing list and the
 * authors above to ensure that the autogeneration scripts are kept
 * up-to-date with the file contents.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#ifndef __ARCH_ARM_MACH_OMAP2_CTRL_MODULE_WKUP_PAD_54XX_H
#define __ARCH_ARM_MACH_OMAP2_CTRL_MODULE_WKUP_PAD_54XX_H

/* Base address */
#define OMAP5_CTRL_MODULE_WKUP_PAD					0x4ae0c800

#define OMAP5_CTRL_MODULE_WKUP_PAD_REGADDR(reg)	\
		OMAP2_L4_IO_ADDRESS(OMAP5_CTRL_MODULE_WKUP_PAD + (reg))

/* Registers offset */
#define OMAP5_CTRL_MODULE_WKUP_PAD_IP_REVISION				0x0000
#define OMAP5_CTRL_MODULE_WKUP_PAD_IP_HWINFO				0x0004
#define OMAP5_CTRL_MODULE_WKUP_PAD_IP_SYSCONFIG				0x0010
#define OMAP5_CTRL_MODULE_WKUP_PAD_PADCONF_WAKEUPEVENT_0		0x0080
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_SMART1NOPMIO_PADCONF_0	0x05a0
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_SMART1NOPMIO_PADCONF_1	0x05a4
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_PADCONF_MODE			0x05a8
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_XTAL_OSCILLATOR		0x05ac
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_I2C_2			0x05b0
#define OMAP5_CTRL_MODULE_WKUP_PAD_CONTROL_CKOBUFFER			0x05b4
#define OMAP5_CTRL_MODULE_WKUP_PAD_WKUP_CONTROL_SPARE_RW		0x05b8
#define OMAP5_CTRL_MODULE_WKUP_PAD_WKUP_CONTROL_SPARE_R			0x05bc
#define OMAP5_CTRL_MODULE_WKUP_PAD_WKUP_CONTROL_SPARE_R_C0		0x05c0
#define OMAP5_CTRL_MODULE_WKUP_PAD_SRCOMP_EAST_SIDE_WKUP		0x05c4
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_1				0x05c8
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_2				0x05cc
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_3				0x05d0
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_4				0x05d4
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_5				0x05d8
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_6				0x05dc
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_7				0x05e0
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_8				0x05e4
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_9				0x05e8
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_10				0x05ec
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_11				0x05f0
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_12				0x05f4
#define OMAP5_CTRL_MODULE_WKUP_PAD_EFUSE_13				0x05f8

/* Registers shifts and masks */

/* IP_REVISION */
#define OMAP5_IP_REV_SCHEME_SHIFT			30
#define OMAP5_IP_REV_SCHEME_MASK			(0x3 << 30)
#define OMAP5_IP_REV_FUNC_SHIFT				16
#define OMAP5_IP_REV_FUNC_MASK				(0xfff << 16)
#define OMAP5_IP_REV_RTL_SHIFT				11
#define OMAP5_IP_REV_RTL_MASK				(0x1f << 11)
#define OMAP5_IP_REV_MAJOR_SHIFT			8
#define OMAP5_IP_REV_MAJOR_MASK				(0x7 << 8)
#define OMAP5_IP_REV_CUSTOM_SHIFT			6
#define OMAP5_IP_REV_CUSTOM_MASK			(0x3 << 6)
#define OMAP5_IP_REV_MINOR_SHIFT			0
#define OMAP5_IP_REV_MINOR_MASK				(0x3f << 0)

/* IP_HWINFO */
#define OMAP5_IP_HWINFO_SHIFT				0
#define OMAP5_IP_HWINFO_MASK				(0xffffffff << 0)

/* IP_SYSCONFIG */
#define OMAP5_IP_SYSCONFIG_IDLEMODE_SHIFT		2
#define OMAP5_IP_SYSCONFIG_IDLEMODE_MASK		(0x3 << 2)

/* PADCONF_WAKEUPEVENT_0 */
#define OMAP5_SYS_NIRQ2_DUPLICATEWAKEUPEVENT_SHIFT	11
#define OMAP5_SYS_NIRQ2_DUPLICATEWAKEUPEVENT_MASK	(1 << 11)
#define OMAP5_SYS_NIRQ1_DUPLICATEWAKEUPEVENT_SHIFT	10
#define OMAP5_SYS_NIRQ1_DUPLICATEWAKEUPEVENT_MASK	(1 << 10)
#define OMAP5_FREF_CLK1_REQ_DUPLICATEWAKEUPEVENT_SHIFT	9
#define OMAP5_FREF_CLK1_REQ_DUPLICATEWAKEUPEVENT_MASK	(1 << 9)
#define OMAP5_FREF_CLK2_REQ_DUPLICATEWAKEUPEVENT_SHIFT	8
#define OMAP5_FREF_CLK2_REQ_DUPLICATEWAKEUPEVENT_MASK	(1 << 8)
#define OMAP5_FREF_CLK2_OUT_DUPLICATEWAKEUPEVENT_SHIFT	7
#define OMAP5_FREF_CLK2_OUT_DUPLICATEWAKEUPEVENT_MASK	(1 << 7)
#define OMAP5_FREF_CLK1_OUT_DUPLICATEWAKEUPEVENT_SHIFT	6
#define OMAP5_FREF_CLK1_OUT_DUPLICATEWAKEUPEVENT_MASK	(1 << 6)
#define OMAP5_FREF_CLK0_OUT_DUPLICATEWAKEUPEVENT_SHIFT	5
#define OMAP5_FREF_CLK0_OUT_DUPLICATEWAKEUPEVENT_MASK	(1 << 5)
#define OMAP5_FREF_CLK_IOREQ_DUPLICATEWAKEUPEVENT_SHIFT	4
#define OMAP5_FREF_CLK_IOREQ_DUPLICATEWAKEUPEVENT_MASK	(1 << 4)
#define OMAP5_DRM_EMU1_DUPLICATEWAKEUPEVENT_SHIFT	3
#define OMAP5_DRM_EMU1_DUPLICATEWAKEUPEVENT_MASK	(1 << 3)
#define OMAP5_DRM_EMU0_DUPLICATEWAKEUPEVENT_SHIFT	2
#define OMAP5_DRM_EMU0_DUPLICATEWAKEUPEVENT_MASK	(1 << 2)
#define OMAP5_LLIB_WAKEREQIN_DUPLICATEWAKEUPEVENT_SHIFT	1
#define OMAP5_LLIB_WAKEREQIN_DUPLICATEWAKEUPEVENT_MASK	(1 << 1)
#define OMAP5_LLIA_WAKEREQIN_DUPLICATEWAKEUPEVENT_SHIFT	0
#define OMAP5_LLIA_WAKEREQIN_DUPLICATEWAKEUPEVENT_MASK	(1 << 0)

/* CONTROL_SMART1NOPMIO_PADCONF_0 */
#define OMAP5_BOOT_GPO_DS_SHIFT				30
#define OMAP5_BOOT_GPO_DS_MASK				(0x3 << 30)
#define OMAP5_FREF_IOREQ_DS_SHIFT			26
#define OMAP5_FREF_IOREQ_DS_MASK			(0x3 << 26)
#define OMAP5_FREF_OUT0_DS_SHIFT			24
#define OMAP5_FREF_OUT0_DS_MASK				(0x3 << 24)
#define OMAP5_FREF_OUT1_DS_SHIFT			22
#define OMAP5_FREF_OUT1_DS_MASK				(0x3 << 22)
#define OMAP5_FREF_OUT2_DS_SHIFT			20
#define OMAP5_FREF_OUT2_DS_MASK				(0x3 << 20)
#define OMAP5_FREF_REQ1_DS_SHIFT			18
#define OMAP5_FREF_REQ1_DS_MASK				(0x3 << 18)
#define OMAP5_FREF_REQ2_DS_SHIFT			16
#define OMAP5_FREF_REQ2_DS_MASK				(0x3 << 16)
#define OMAP5_JTAG_PART0_DS_SHIFT			14
#define OMAP5_JTAG_PART0_DS_MASK			(0x3 << 14)
#define OMAP5_JTAG_PART1_DS_SHIFT			12
#define OMAP5_JTAG_PART1_DS_MASK			(0x3 << 12)
#define OMAP5_LLIA_WKUP0_DS_SHIFT			10
#define OMAP5_LLIA_WKUP0_DS_MASK			(0x3 << 10)
#define OMAP5_SYS_DS_SHIFT				8
#define OMAP5_SYS_DS_MASK				(0x3 << 8)
#define OMAP5_SR_LB_SHIFT				6
#define OMAP5_SR_LB_MASK				(0x3 << 6)

/* CONTROL_SMART1NOPMIO_PADCONF_1 */
#define OMAP5_BOOT_GPO_SC_SHIFT				30
#define OMAP5_BOOT_GPO_SC_MASK				(0x3 << 30)
#define OMAP5_FREF_IOREQ_SC_SHIFT			26
#define OMAP5_FREF_IOREQ_SC_MASK			(0x3 << 26)
#define OMAP5_FREF_OUT0_SC_SHIFT			24
#define OMAP5_FREF_OUT0_SC_MASK				(0x3 << 24)
#define OMAP5_FREF_OUT1_SC_SHIFT			22
#define OMAP5_FREF_OUT1_SC_MASK				(0x3 << 22)
#define OMAP5_FREF_OUT2_SC_SHIFT			20
#define OMAP5_FREF_OUT2_SC_MASK				(0x3 << 20)
#define OMAP5_FREF_REQ1_SC_SHIFT			18
#define OMAP5_FREF_REQ1_SC_MASK				(0x3 << 18)
#define OMAP5_FREF_REQ2_SC_SHIFT			16
#define OMAP5_FREF_REQ2_SC_MASK				(0x3 << 16)
#define OMAP5_JTAG_PART0_SC_SHIFT			14
#define OMAP5_JTAG_PART0_SC_MASK			(0x3 << 14)
#define OMAP5_JTAG_PART1_SC_SHIFT			12
#define OMAP5_JTAG_PART1_SC_MASK			(0x3 << 12)
#define OMAP5_LLIA_WKUP0_SC_SHIFT			10
#define OMAP5_LLIA_WKUP0_SC_MASK			(0x3 << 10)
#define OMAP5_SYS_SC_SHIFT				8
#define OMAP5_SYS_SC_MASK				(0x3 << 8)

/* CONTROL_PADCONF_MODE */
#define OMAP5_VDDS_25_MODE_SHIFT			31
#define OMAP5_VDDS_25_MODE_MASK				(1 << 31)
#define OMAP5_VDDS_26_MODE_SHIFT			30
#define OMAP5_VDDS_26_MODE_MASK				(1 << 30)

/* CONTROL_XTAL_OSCILLATOR */
#define OMAP5_OSCILLATOR_BOOST_SHIFT			31
#define OMAP5_OSCILLATOR_BOOST_MASK			(1 << 31)
#define OMAP5_OSCILLATOR_OS_OUT_SHIFT			30
#define OMAP5_OSCILLATOR_OS_OUT_MASK			(1 << 30)

/* CONTROL_I2C_2 */
#define OMAP5_SR_PMIC_SDA_GLFENB_SHIFT			31
#define OMAP5_SR_PMIC_SDA_GLFENB_MASK			(1 << 31)
#define OMAP5_SR_PMIC_SDA_PULLUPRESX_SHIFT		30
#define OMAP5_SR_PMIC_SDA_PULLUPRESX_MASK		(1 << 30)
#define OMAP5_SR_PMIC_SCL_GLFENB_SHIFT			29
#define OMAP5_SR_PMIC_SCL_GLFENB_MASK			(1 << 29)
#define OMAP5_SR_PMIC_SCL_PULLUPRESX_SHIFT		28
#define OMAP5_SR_PMIC_SCL_PULLUPRESX_MASK		(1 << 28)

/* CONTROL_CKOBUFFER */
#define OMAP5_CKOBUFFER_OUT_EN_SHIFT			31
#define OMAP5_CKOBUFFER_OUT_EN_MASK			(1 << 31)
#define OMAP5_CKOBUFFER_ALTSEL_SHIFT			30
#define OMAP5_CKOBUFFER_ALTSEL_MASK			(1 << 30)
#define OMAP5_CKOBUFFER_POLARITY_SHIFT			29
#define OMAP5_CKOBUFFER_POLARITY_MASK			(1 << 29)
#define OMAP5_CKOBUFFER_CLK_EN_SHIFT			28
#define OMAP5_CKOBUFFER_CLK_EN_MASK			(1 << 28)

/* WKUP_CONTROL_SPARE_RW */
#define OMAP5_WKUP_CONTROL_SPARE_RW_SHIFT		0
#define OMAP5_WKUP_CONTROL_SPARE_RW_MASK		(0xffffffff << 0)

/* WKUP_CONTROL_SPARE_R */
#define OMAP5_WKUP_CONTROL_SPARE_R_SHIFT		0
#define OMAP5_WKUP_CONTROL_SPARE_R_MASK			(0xffffffff << 0)

/* WKUP_CONTROL_SPARE_R_C0 */
#define OMAP5_WKUP_CONTROL_SPARE_R_C0_SHIFT		31
#define OMAP5_WKUP_CONTROL_SPARE_R_C0_MASK		(1 << 31)
#define OMAP5_WKUP_CONTROL_SPARE_R_C1_SHIFT		30
#define OMAP5_WKUP_CONTROL_SPARE_R_C1_MASK		(1 << 30)
#define OMAP5_WKUP_CONTROL_SPARE_R_C2_SHIFT		29
#define OMAP5_WKUP_CONTROL_SPARE_R_C2_MASK		(1 << 29)
#define OMAP5_WKUP_CONTROL_SPARE_R_C3_SHIFT		28
#define OMAP5_WKUP_CONTROL_SPARE_R_C3_MASK		(1 << 28)
#define OMAP5_WKUP_CONTROL_SPARE_R_C4_SHIFT		27
#define OMAP5_WKUP_CONTROL_SPARE_R_C4_MASK		(1 << 27)
#define OMAP5_WKUP_CONTROL_SPARE_R_C5_SHIFT		26
#define OMAP5_WKUP_CONTROL_SPARE_R_C5_MASK		(1 << 26)
#define OMAP5_WKUP_CONTROL_SPARE_R_C6_SHIFT		25
#define OMAP5_WKUP_CONTROL_SPARE_R_C6_MASK		(1 << 25)
#define OMAP5_WKUP_CONTROL_SPARE_R_C7_SHIFT		24
#define OMAP5_WKUP_CONTROL_SPARE_R_C7_MASK		(1 << 24)

/* SRCOMP_EAST_SIDE_WKUP */
#define OMAP5_OVERFLOW_ES_SHIFT				31
#define OMAP5_OVERFLOW_ES_MASK				(1 << 31)
#define OMAP5_OVERRIDE_IO_ES_SHIFT			30
#define OMAP5_OVERRIDE_IO_ES_MASK			(1 << 30)
#define OMAP5_SRCODE_OVERRIDE_ES_SHIFT			22
#define OMAP5_SRCODE_OVERRIDE_ES_MASK			(0xff << 22)
#define OMAP5_WKUP_PAD_CODE_LATCH_ES_SHIFT		21
#define OMAP5_WKUP_PAD_CODE_LATCH_ES_MASK		(1 << 21)
#define OMAP5_CODE_UPDATE_ES_SHIFT			20
#define OMAP5_CODE_UPDATE_ES_MASK			(1 << 20)
#define OMAP5_SRCODE_READ_ES_SHIFT			12
#define OMAP5_SRCODE_READ_ES_MASK			(0xff << 12)
#define OMAP5_DIVIDE_FACTOR_ES_SHIFT			4
#define OMAP5_DIVIDE_FACTOR_ES_MASK			(0x7f << 4)
#define OMAP5_MULTIPLY_FACTOR_ES_SHIFT			1
#define OMAP5_MULTIPLY_FACTOR_ES_MASK			(0x7 << 1)
#define OMAP5_SRCODE_OVERRIDE_SEL_ES_SHIFT		0
#define OMAP5_SRCODE_OVERRIDE_SEL_ES_MASK		(1 << 0)

/* EFUSE_1 */
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N5_SHIFT		31
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N5_MASK		(1 << 31)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N4_SHIFT		30
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N4_MASK		(1 << 30)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N3_SHIFT		29
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N3_MASK		(1 << 29)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N2_SHIFT		28
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N2_MASK		(1 << 28)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N1_SHIFT		27
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N1_MASK		(1 << 27)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N0_SHIFT		26
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_N0_MASK		(1 << 26)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P5_SHIFT		25
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P5_MASK		(1 << 25)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P4_SHIFT		24
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P4_MASK		(1 << 24)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P3_SHIFT		23
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P3_MASK		(1 << 23)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P2_SHIFT		22
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P2_MASK		(1 << 22)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P1_SHIFT		21
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P1_MASK		(1 << 21)
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P0_SHIFT		20
#define OMAP5_DDRDIFF_PTV_NORTH_SIDE_P0_MASK		(1 << 20)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N5_SHIFT		19
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N5_MASK		(1 << 19)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N4_SHIFT		18
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N4_MASK		(1 << 18)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N3_SHIFT		17
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N3_MASK		(1 << 17)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N2_SHIFT		16
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N2_MASK		(1 << 16)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N1_SHIFT		15
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N1_MASK		(1 << 15)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N0_SHIFT		14
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_N0_MASK		(1 << 14)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P5_SHIFT		13
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P5_MASK		(1 << 13)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P4_SHIFT		12
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P4_MASK		(1 << 12)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P3_SHIFT		11
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P3_MASK		(1 << 11)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P2_SHIFT		10
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P2_MASK		(1 << 10)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P1_SHIFT		9
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P1_MASK		(1 << 9)
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P0_SHIFT		8
#define OMAP5_DDRDIFF_PTV_EAST_SIDE_P0_MASK		(1 << 8)

/* EFUSE_2 */
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N5_SHIFT		31
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N5_MASK		(1 << 31)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N4_SHIFT		30
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N4_MASK		(1 << 30)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N3_SHIFT		29
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N3_MASK		(1 << 29)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N2_SHIFT		28
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N2_MASK		(1 << 28)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N1_SHIFT		27
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N1_MASK		(1 << 27)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N0_SHIFT		26
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_N0_MASK		(1 << 26)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P5_SHIFT		25
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P5_MASK		(1 << 25)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P4_SHIFT		24
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P4_MASK		(1 << 24)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P3_SHIFT		23
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P3_MASK		(1 << 23)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P2_SHIFT		22
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P2_MASK		(1 << 22)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P1_SHIFT		21
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P1_MASK		(1 << 21)
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P0_SHIFT		20
#define OMAP5_DDRDIFF_PTV_SOUTH_SIDE_P0_MASK		(1 << 20)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N5_SHIFT		19
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N5_MASK		(1 << 19)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N4_SHIFT		18
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N4_MASK		(1 << 18)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N3_SHIFT		17
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N3_MASK		(1 << 17)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N2_SHIFT		16
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N2_MASK		(1 << 16)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N1_SHIFT		15
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N1_MASK		(1 << 15)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N0_SHIFT		14
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_N0_MASK		(1 << 14)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P5_SHIFT		13
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P5_MASK		(1 << 13)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P4_SHIFT		12
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P4_MASK		(1 << 12)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P3_SHIFT		11
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P3_MASK		(1 << 11)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P2_SHIFT		10
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P2_MASK		(1 << 10)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P1_SHIFT		9
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P1_MASK		(1 << 9)
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P0_SHIFT		8
#define OMAP5_DDRDIFF_PTV_WEST_SIDE_P0_MASK		(1 << 8)

/* EFUSE_3 */
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N5_SHIFT		31
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N5_MASK		(1 << 31)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N4_SHIFT		30
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N4_MASK		(1 << 30)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N3_SHIFT		29
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N3_MASK		(1 << 29)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N2_SHIFT		28
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N2_MASK		(1 << 28)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N1_SHIFT		27
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N1_MASK		(1 << 27)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N0_SHIFT		26
#define OMAP5_DDRSE_PTV_NORTH_SIDE_N0_MASK		(1 << 26)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P5_SHIFT		25
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P5_MASK		(1 << 25)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P4_SHIFT		24
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P4_MASK		(1 << 24)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P3_SHIFT		23
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P3_MASK		(1 << 23)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P2_SHIFT		22
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P2_MASK		(1 << 22)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P1_SHIFT		21
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P1_MASK		(1 << 21)
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P0_SHIFT		20
#define OMAP5_DDRSE_PTV_NORTH_SIDE_P0_MASK		(1 << 20)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N5_SHIFT		19
#define OMAP5_DDRSE_PTV_EAST_SIDE_N5_MASK		(1 << 19)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N4_SHIFT		18
#define OMAP5_DDRSE_PTV_EAST_SIDE_N4_MASK		(1 << 18)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N3_SHIFT		17
#define OMAP5_DDRSE_PTV_EAST_SIDE_N3_MASK		(1 << 17)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N2_SHIFT		16
#define OMAP5_DDRSE_PTV_EAST_SIDE_N2_MASK		(1 << 16)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N1_SHIFT		15
#define OMAP5_DDRSE_PTV_EAST_SIDE_N1_MASK		(1 << 15)
#define OMAP5_DDRSE_PTV_EAST_SIDE_N0_SHIFT		14
#define OMAP5_DDRSE_PTV_EAST_SIDE_N0_MASK		(1 << 14)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P5_SHIFT		13
#define OMAP5_DDRSE_PTV_EAST_SIDE_P5_MASK		(1 << 13)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P4_SHIFT		12
#define OMAP5_DDRSE_PTV_EAST_SIDE_P4_MASK		(1 << 12)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P3_SHIFT		11
#define OMAP5_DDRSE_PTV_EAST_SIDE_P3_MASK		(1 << 11)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P2_SHIFT		10
#define OMAP5_DDRSE_PTV_EAST_SIDE_P2_MASK		(1 << 10)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P1_SHIFT		9
#define OMAP5_DDRSE_PTV_EAST_SIDE_P1_MASK		(1 << 9)
#define OMAP5_DDRSE_PTV_EAST_SIDE_P0_SHIFT		8
#define OMAP5_DDRSE_PTV_EAST_SIDE_P0_MASK		(1 << 8)

/* EFUSE_4 */
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N5_SHIFT		31
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N5_MASK		(1 << 31)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N4_SHIFT		30
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N4_MASK		(1 << 30)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N3_SHIFT		29
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N3_MASK		(1 << 29)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N2_SHIFT		28
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N2_MASK		(1 << 28)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N1_SHIFT		27
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N1_MASK		(1 << 27)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N0_SHIFT		26
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_N0_MASK		(1 << 26)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P5_SHIFT		25
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P5_MASK		(1 << 25)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P4_SHIFT		24
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P4_MASK		(1 << 24)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P3_SHIFT		23
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P3_MASK		(1 << 23)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P2_SHIFT		22
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P2_MASK		(1 << 22)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P1_SHIFT		21
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P1_MASK		(1 << 21)
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P0_SHIFT		20
#define OMAP5_DDRSE_PTV_SOUTH_SIDE_P0_MASK		(1 << 20)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N5_SHIFT		19
#define OMAP5_DDRSE_PTV_WEST_SIDE_N5_MASK		(1 << 19)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N4_SHIFT		18
#define OMAP5_DDRSE_PTV_WEST_SIDE_N4_MASK		(1 << 18)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N3_SHIFT		17
#define OMAP5_DDRSE_PTV_WEST_SIDE_N3_MASK		(1 << 17)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N2_SHIFT		16
#define OMAP5_DDRSE_PTV_WEST_SIDE_N2_MASK		(1 << 16)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N1_SHIFT		15
#define OMAP5_DDRSE_PTV_WEST_SIDE_N1_MASK		(1 << 15)
#define OMAP5_DDRSE_PTV_WEST_SIDE_N0_SHIFT		14
#define OMAP5_DDRSE_PTV_WEST_SIDE_N0_MASK		(1 << 14)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P5_SHIFT		13
#define OMAP5_DDRSE_PTV_WEST_SIDE_P5_MASK		(1 << 13)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P4_SHIFT		12
#define OMAP5_DDRSE_PTV_WEST_SIDE_P4_MASK		(1 << 12)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P3_SHIFT		11
#define OMAP5_DDRSE_PTV_WEST_SIDE_P3_MASK		(1 << 11)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P2_SHIFT		10
#define OMAP5_DDRSE_PTV_WEST_SIDE_P2_MASK		(1 << 10)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P1_SHIFT		9
#define OMAP5_DDRSE_PTV_WEST_SIDE_P1_MASK		(1 << 9)
#define OMAP5_DDRSE_PTV_WEST_SIDE_P0_SHIFT		8
#define OMAP5_DDRSE_PTV_WEST_SIDE_P0_MASK		(1 << 8)

/* EFUSE_5 */
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N9_MASK	(1 << 31)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N8_MASK	(1 << 30)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N7_MASK	(1 << 29)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N6_MASK	(1 << 28)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N5_MASK	(1 << 27)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N4_MASK	(1 << 26)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N3_MASK	(1 << 25)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N2_MASK	(1 << 24)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N1_MASK	(1 << 23)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_N0_MASK	(1 << 22)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P9_MASK	(1 << 21)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P8_MASK	(1 << 20)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P7_MASK	(1 << 19)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P6_MASK	(1 << 18)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P5_MASK	(1 << 17)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P4_MASK	(1 << 16)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P3_MASK	(1 << 15)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P2_MASK	(1 << 14)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P1_MASK	(1 << 13)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V2_P0_MASK	(1 << 12)

/* EFUSE_6 */
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N9_MASK		(1 << 31)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N8_MASK		(1 << 30)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N7_MASK		(1 << 29)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N6_MASK		(1 << 28)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N5_MASK		(1 << 27)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N4_MASK		(1 << 26)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N3_MASK		(1 << 25)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N2_MASK		(1 << 24)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N1_MASK		(1 << 23)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_N0_MASK		(1 << 22)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P9_MASK		(1 << 21)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P8_MASK		(1 << 20)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P7_MASK		(1 << 19)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P6_MASK		(1 << 18)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P5_MASK		(1 << 17)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P4_MASK		(1 << 16)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P3_MASK		(1 << 15)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P2_MASK		(1 << 14)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P1_MASK		(1 << 13)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V2_P0_MASK		(1 << 12)

/* EFUSE_7 */
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N9_MASK	(1 << 31)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N8_MASK	(1 << 30)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N7_MASK	(1 << 29)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N6_MASK	(1 << 28)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N5_MASK	(1 << 27)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N4_MASK	(1 << 26)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N3_MASK	(1 << 25)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N2_MASK	(1 << 24)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N1_MASK	(1 << 23)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_N0_MASK	(1 << 22)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P9_MASK	(1 << 21)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P8_MASK	(1 << 20)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P7_MASK	(1 << 19)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P6_MASK	(1 << 18)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P5_MASK	(1 << 17)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P4_MASK	(1 << 16)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P3_MASK	(1 << 15)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P2_MASK	(1 << 14)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P1_MASK	(1 << 13)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V2_P0_MASK	(1 << 12)

/* EFUSE_8 */
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N9_MASK		(1 << 31)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N8_MASK		(1 << 30)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N7_MASK		(1 << 29)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N6_MASK		(1 << 28)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N5_MASK		(1 << 27)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N4_MASK		(1 << 26)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N3_MASK		(1 << 25)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N2_MASK		(1 << 24)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N1_MASK		(1 << 23)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_N0_MASK		(1 << 22)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P9_MASK		(1 << 21)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P8_MASK		(1 << 20)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P7_MASK		(1 << 19)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P6_MASK		(1 << 18)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P5_MASK		(1 << 17)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P4_MASK		(1 << 16)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P3_MASK		(1 << 15)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P2_MASK		(1 << 14)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P1_MASK		(1 << 13)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V2_P0_MASK		(1 << 12)

/* EFUSE_9 */
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N9_MASK	(1 << 31)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N8_MASK	(1 << 30)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N7_MASK	(1 << 29)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N6_MASK	(1 << 28)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N5_MASK	(1 << 27)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N4_MASK	(1 << 26)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N3_MASK	(1 << 25)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N2_MASK	(1 << 24)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N1_MASK	(1 << 23)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_N0_MASK	(1 << 22)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P9_MASK	(1 << 21)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P8_MASK	(1 << 20)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P7_MASK	(1 << 19)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P6_MASK	(1 << 18)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P5_MASK	(1 << 17)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P4_MASK	(1 << 16)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P3_MASK	(1 << 15)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P2_MASK	(1 << 14)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P1_MASK	(1 << 13)
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_NORTH_SIDE_1V8_P0_MASK	(1 << 12)

/* EFUSE_10 */
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N9_MASK		(1 << 31)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N8_MASK		(1 << 30)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N7_MASK		(1 << 29)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N6_MASK		(1 << 28)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N5_MASK		(1 << 27)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N4_MASK		(1 << 26)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N3_MASK		(1 << 25)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N2_MASK		(1 << 24)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N1_MASK		(1 << 23)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_N0_MASK		(1 << 22)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P9_MASK		(1 << 21)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P8_MASK		(1 << 20)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P7_MASK		(1 << 19)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P6_MASK		(1 << 18)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P5_MASK		(1 << 17)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P4_MASK		(1 << 16)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P3_MASK		(1 << 15)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P2_MASK		(1 << 14)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P1_MASK		(1 << 13)
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_EAST_SIDE_1V8_P0_MASK		(1 << 12)

/* EFUSE_11 */
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N9_MASK	(1 << 31)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N8_MASK	(1 << 30)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N7_MASK	(1 << 29)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N6_MASK	(1 << 28)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N5_MASK	(1 << 27)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N4_MASK	(1 << 26)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N3_MASK	(1 << 25)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N2_MASK	(1 << 24)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N1_MASK	(1 << 23)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_N0_MASK	(1 << 22)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P9_MASK	(1 << 21)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P8_MASK	(1 << 20)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P7_MASK	(1 << 19)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P6_MASK	(1 << 18)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P5_MASK	(1 << 17)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P4_MASK	(1 << 16)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P3_MASK	(1 << 15)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P2_MASK	(1 << 14)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P1_MASK	(1 << 13)
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_SOUTH_SIDE_1V8_P0_MASK	(1 << 12)

/* EFUSE_12 */
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N9_SHIFT	31
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N9_MASK		(1 << 31)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N8_SHIFT	30
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N8_MASK		(1 << 30)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N7_SHIFT	29
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N7_MASK		(1 << 29)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N6_SHIFT	28
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N6_MASK		(1 << 28)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N5_SHIFT	27
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N5_MASK		(1 << 27)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N4_SHIFT	26
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N4_MASK		(1 << 26)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N3_SHIFT	25
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N3_MASK		(1 << 25)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N2_SHIFT	24
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N2_MASK		(1 << 24)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N1_SHIFT	23
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N1_MASK		(1 << 23)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N0_SHIFT	22
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_N0_MASK		(1 << 22)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P9_SHIFT	21
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P9_MASK		(1 << 21)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P8_SHIFT	20
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P8_MASK		(1 << 20)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P7_SHIFT	19
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P7_MASK		(1 << 19)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P6_SHIFT	18
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P6_MASK		(1 << 18)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P5_SHIFT	17
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P5_MASK		(1 << 17)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P4_SHIFT	16
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P4_MASK		(1 << 16)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P3_SHIFT	15
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P3_MASK		(1 << 15)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P2_SHIFT	14
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P2_MASK		(1 << 14)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P1_SHIFT	13
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P1_MASK		(1 << 13)
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P0_SHIFT	12
#define OMAP5_SMARTIO_PTV_WEST_SIDE_1V8_P0_MASK		(1 << 12)

/* EFUSE_13 */
#define OMAP5_SDIO1833_PTV_N5_SHIFT			31
#define OMAP5_SDIO1833_PTV_N5_MASK			(1 << 31)
#define OMAP5_SDIO1833_PTV_N4_SHIFT			30
#define OMAP5_SDIO1833_PTV_N4_MASK			(1 << 30)
#define OMAP5_SDIO1833_PTV_N3_SHIFT			29
#define OMAP5_SDIO1833_PTV_N3_MASK			(1 << 29)
#define OMAP5_SDIO1833_PTV_N2_SHIFT			28
#define OMAP5_SDIO1833_PTV_N2_MASK			(1 << 28)
#define OMAP5_SDIO1833_PTV_N1_SHIFT			27
#define OMAP5_SDIO1833_PTV_N1_MASK			(1 << 27)
#define OMAP5_SDIO1833_PTV_N0_SHIFT			26
#define OMAP5_SDIO1833_PTV_N0_MASK			(1 << 26)
#define OMAP5_SDIO1833_PTV_P5_SHIFT			25
#define OMAP5_SDIO1833_PTV_P5_MASK			(1 << 25)
#define OMAP5_SDIO1833_PTV_P4_SHIFT			24
#define OMAP5_SDIO1833_PTV_P4_MASK			(1 << 24)
#define OMAP5_SDIO1833_PTV_P3_SHIFT			23
#define OMAP5_SDIO1833_PTV_P3_MASK			(1 << 23)
#define OMAP5_SDIO1833_PTV_P2_SHIFT			22
#define OMAP5_SDIO1833_PTV_P2_MASK			(1 << 22)
#define OMAP5_SDIO1833_PTV_P1_SHIFT			21
#define OMAP5_SDIO1833_PTV_P1_MASK			(1 << 21)
#define OMAP5_SDIO1833_PTV_P0_SHIFT			20
#define OMAP5_SDIO1833_PTV_P0_MASK			(1 << 20)

#endif
