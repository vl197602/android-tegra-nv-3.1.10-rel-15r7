/*
 * tegra30_spdif.h - Definitions for Tegra30 SPDIF driver
 *
 * Author: Sumit Bhattacharya <sumitb@nvidia.com>
 * Copyright (C) 2011 - NVIDIA, Inc.
 *
 * Based on code copyright/by:
 *
 * Copyright (c) 2009-2011, NVIDIA Corporation.
 * Scott Peterson <speterson@nvidia.com>
 *
 * Copyright (C) 2010 Google, Inc.
 * Iliyan Malchev <malchev@google.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
 *
 */

#ifndef __TEGRA30_SPDIF_H__
#define __TEGRA30_SPDIF_H__

#include "tegra_pcm.h"
#include "tegra30_ahub.h"

/* Register offsets from TEGRA_SPDIF_BASE */

#define TEGRA30_SPDIF_CTRL			0x0
#define TEGRA30_SPDIF_STROBE_CTRL		0x4
#define TEGRA30_SPDIF_CIF_TXD_CTRL		0x08
#define TEGRA30_SPDIF_CIF_RXD_CTRL		0x0C
#define TEGRA30_SPDIF_CIF_TXU_CTRL		0x10
#define TEGRA30_SPDIF_CIF_RXU_CTRL		0x14
#define TEGRA30_SPDIF_CH_STA_RX_A		0x18
#define TEGRA30_SPDIF_CH_STA_RX_B		0x1C
#define TEGRA30_SPDIF_CH_STA_RX_C		0x20
#define TEGRA30_SPDIF_CH_STA_RX_D		0x24
#define TEGRA30_SPDIF_CH_STA_RX_E		0x28
#define TEGRA30_SPDIF_CH_STA_RX_F		0x2C
#define TEGRA30_SPDIF_CH_STA_TX_A		0x30
#define TEGRA30_SPDIF_CH_STA_TX_B		0x34
#define TEGRA30_SPDIF_CH_STA_TX_C		0x38
#define TEGRA30_SPDIF_CH_STA_TX_D		0x3C
#define TEGRA30_SPDIF_CH_STA_TX_E		0x40
#define TEGRA30_SPDIF_CH_STA_TX_F		0x44
#define TEGRA30_SPDIF_FLOWCTL_CTRL		0x70
#define TEGRA30_SPDIF_TX_STEP			0x74
#define TEGRA30_SPDIF_FLOW_STATUS		0x78
#define TEGRA30_SPDIF_FLOW_TOTAL		0x7c
#define TEGRA30_SPDIF_FLOW_OVER			0x80
#define TEGRA30_SPDIF_FLOW_UNDER		0x84
#define TEGRA30_SPDIF_LCOEF_1_4_0		0x88
#define TEGRA30_SPDIF_LCOEF_1_4_1		0x8c
#define TEGRA30_SPDIF_LCOEF_1_4_2		0x90
#define TEGRA30_SPDIF_LCOEF_1_4_3		0x94
#define TEGRA30_SPDIF_LCOEF_1_4_4		0x98
#define TEGRA30_SPDIF_LCOEF_1_4_5		0x9c
#define TEGRA30_SPDIF_LCOEF_2_4_0		0xa0
#define TEGRA30_SPDIF_LCOEF_2_4_1		0xa4
#define TEGRA30_SPDIF_LCOEF_2_4_2		0xa8

/* Fields in TEGRA30_SPDIF_CTRL */
#define TEGRA30_SPDIF_CTRL_FLOWCTL_EN_ENABLE	(1<<31)
#define TEGRA30_SPDIF_CTRL_CAP_LC_LEFT_CH	(1<<30)
#define TEGRA30_SPDIF_CTRL_RX_EN_ENABLE		(1<<29)
#define TEGRA30_SPDIF_CTRL_TX_EN_ENABLE		(1<<28)
#define TEGRA30_SPDIF_CTRL_TC_EN_ENABLE		(1<<27)
#define TEGRA30_SPDIF_CTRL_TU_EN_ENABLE		(1<<26)
#define TEGRA30_SPDIF_CTRL_IE_P_RSVD_ENABLE	(1<<23)
#define TEGRA30_SPDIF_CTRL_IE_B_RSVD_ENABLE	(1<<22)
#define TEGRA30_SPDIF_CTRL_IE_C_RSVD_ENABLE	(1<<21)
#define TEGRA30_SPDIF_CTRL_IE_U_RSVD_ENABLE	(1<<20)
#define TEGRA30_SPDIF_CTRL_LBK_EN_ENABLE	(1<<15)
#define TEGRA30_SPDIF_CTRL_PACK_ENABLE		(1<<14)

#define TEGRA30_SPDIF_BIT_MODE16		0
#define TEGRA30_SPDIF_BIT_MODE20		1
#define TEGRA30_SPDIF_BIT_MODE24		2
#define TEGRA30_SPDIF_BIT_MODERAW		3

#define TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT	12
#define TEGRA30_SPDIF_CTRL_BIT_MODE_MASK	(3                         << TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA30_SPDIF_CTRL_BIT_MODE_16BIT	(TEGRA30_SPDIF_BIT_MODE16  << TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA30_SPDIF_CTRL_BIT_MODE_20BIT	(TEGRA30_SPDIF_BIT_MODE20  << TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA30_SPDIF_CTRL_BIT_MODE_24BIT	(TEGRA30_SPDIF_BIT_MODE24  << TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT)
#define TEGRA30_SPDIF_CTRL_BIT_MODE_RAW		(TEGRA30_SPDIF_BIT_MODERAW << TEGRA30_SPDIF_CTRL_BIT_MODE_SHIFT)

#define TEGRA30_SPDIF_CTRL_CG_EN_ENABLE		(1<<11)

#define TEGRA30_SPDIF_CTRL_OBS_SEL_SHIFT	8
#define TEGRA30_SPDIF_CTRL_OBS_SEL_NASK		(0x7 << TEGRA30_SPDIF_CTRL_OBS_SEL_SHIFT)

#define TEGRA30_SPDIF_CTRL_SOFT_RESET_ENABLE	(1<<7)

/* Fields in TEGRA30_SPDIF_STROBE_CTRL */
#define TEGRA30_SPDIF_STROBE_CTRL_PERIOD_SHIFT		16
#define TEGRA30_SPDIF_STROBE_CTRL_PERIOD_MASK		(0xff << TEGRA30_SPDIF_STROBE_CTRL_PERIOD_SHIFT)

#define TEGRA30_SPDIF_STROBE_CTRL_STROBE		(1<<15)

#define TEGRA30_SPDIF_STROBE_CTRL_DATA_STROBES_SHIFT	8
#define TEGRA30_SPDIF_STROBE_CTRL_DATA_STROBES_MASK	(0x1f << TEGRA30_SPDIF_STROBE_CTRL_DATA_STROBES_SHIFT)

#define TEGRA30_SPDIF_STROBE_CTRL_CLOCK_PERIOD_SHIFT	0
#define TEGRA30_SPDIF_STROBE_CTRL_CLOCK_PERIOD_MASK	(0x3f << TEGRA30_SPDIF_STROBE_CTRL_CLOCK_PERIOD_SHIFT)

/* Fields in TEGRA30_SPDIF_CIF_TXD_CTRL */
#define TEGRA30_SPDIF_CIF_TXD_CTRL_MONO_CONV_COPY	(1<<0)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_TRUNCATE_CHOP	(1<<1)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_DIRECTION_RXCIF	(1<<2)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_REPLICATE_ENABLE	(1<<3)

#define TEGRA30_SPDIF_CIF_STEREO_CH0			0
#define TEGRA30_SPDIF_CIF_STEREO_CH1			1
#define TEGRA30_SPDIF_CIF_STEREO_AVG			2
#define TEGRA30_SPDIF_CIF_STEREO_RSVD			3

#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT	4
#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_MASK	\
		(0x3                           << TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_CH0	\
		(TEGRA30_SPDIF_CIF_STEREO_CH0  << TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_CH1	\
		(TEGRA30_SPDIF_CIF_STEREO_CH1  << TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_AVG	\
		(TEGRA30_SPDIF_CIF_STEREO_AVG  << TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_RSVD	\
		(TEGRA30_SPDIF_CIF_STEREO_RSVD << TEGRA30_SPDIF_CIF_TXD_CTRL_STEREO_CONV_SHIFT)

#define TEGRA30_SPDIF_CIF_EXPAND_ZERO			0
#define TEGRA30_SPDIF_CIF_EXPAND_ONE			1
#define TEGRA30_SPDIF_CIF_EXPAND_LFSR			2
#define TEGRA30_SPDIF_CIF_EXPAND_RSVD 			3

#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT		6
#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_MASK		\
		(0x3                           << TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_ZERO		\
		(TEGRA30_SPDIF_CIF_EXPAND_ZERO << TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_ONE		\
		(TEGRA30_SPDIF_CIF_EXPAND_ONE  << TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_LFSR		\
		(TEGRA30_SPDIF_CIF_EXPAND_LFSR << TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_RSVD		\
		(TEGRA30_SPDIF_CIF_EXPAND_RSVD << TEGRA30_SPDIF_CIF_TXD_CTRL_EXPAND_SHIFT)

#define TEGRA30_SPDIF_CIF_BIT4				0
#define TEGRA30_SPDIF_CIF_BIT8				1
#define TEGRA30_SPDIF_CIF_BIT12				2
#define TEGRA30_SPDIF_CIF_BIT16				3
#define TEGRA30_SPDIF_CIF_BIT20				4
#define TEGRA30_SPDIF_CIF_BIT24				5
#define TEGRA30_SPDIF_CIF_BIT28				6
#define TEGRA30_SPDIF_CIF_BIT32				7

#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT	8
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT	12
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_BITS_SHIFT)

#define TEGRA30_SPDIF_CIF_CH1				0
#define TEGRA30_SPDIF_CIF_CH2				1
#define TEGRA30_SPDIF_CIF_CH3				2
#define TEGRA30_SPDIF_CIF_CH4				3
#define TEGRA30_SPDIF_CIF_CH5				4
#define TEGRA30_SPDIF_CIF_CH6				5
#define TEGRA30_SPDIF_CIF_CH7				6
#define TEGRA30_SPDIF_CIF_CH8				7

#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT	16
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_TXD_CTRL_CLIENT_CH_SHIFT)


#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT	24
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_TXD_CTRL_AUDIO_CH_SHIFT)

#define TEGRA30_SPDIF_CIF_TXD_CTRL_FIFO_TH_SHIFT	28
#define TEGRA30_SPDIF_CIF_TXD_CTRL_FIFO_TH_MASK		(0x7 << TEGRA30_SPDIF_CIF_TXD_CTRL_FIFO_TH_SHIFT)

/* Fields in TEGRA30_TEGRA30_SPDIF_CIF_RXD_CTRL */
#define TEGRA30_SPDIF_CIF_RXD_CTRL_MONO_CONV_COPY	(1<<0)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_TRUNCATE_CHOP	(1<<1)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_DIRECTION_RXCIF	(1<<2)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_REPLICATE_ENABLE	(1<<3)

#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT	4
#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_MASK	\
		(0x3                           << TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_CH0	\
		(TEGRA30_SPDIF_CIF_STEREO_CH0  << TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_CH1	\
		(TEGRA30_SPDIF_CIF_STEREO_CH1  << TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_AVG	\
		(TEGRA30_SPDIF_CIF_STEREO_AVG  << TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_RSVD	\
		(TEGRA30_SPDIF_CIF_STEREO_RSVD << TEGRA30_SPDIF_CIF_RXD_CTRL_STEREO_CONV_SHIFT)


#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_SHIFT		6
#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_MASK		\
		(0x3                           << TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_ZERO		\
		(TEGRA30_SPDIF_CIF_EXPAND_ZERO << TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_ONE		\
		(TEGRA30_SPDIF_CIF_EXPAND_ONE  << TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_LFSR		\
		(TEGRA30_SPDIF_CIF_EXPAND_LFSR << TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_EXPAND_RSVD		\


#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT	8
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_BITS_SHIFT)

#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT	12
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT 16
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_RXD_CTRL_CLIENT_CH_SHIFT)


#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT	24
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_RXD_CTRL_AUDIO_CHANNELS_SHIFT)

#define TEGRA30_SPDIF_CIF_RXD_CTRL_FIFO_TH_SHIFT	28
#define TEGRA30_SPDIF_CIF_RXD_CTRL_FIFO_TH_MASK		(0x7  << TEGRA30_SPDIF_CIF_RXD_CTRL_FIFO_TH_SHIFT)

/* Fields in TEGRA30_TEGRA30_SPDIF_CIF_TXU_CTRL */
#define TEGRA30_SPDIF_CIF_TXU_CTRL_MONO_CONV_COPY	(1<<0)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_TRUNCATE_CHOP	(1<<1)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_DIRECTION_RXCIF	(1<<2)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_REPLICATE_ENABLE	(1<<3)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_SHIFT	4
#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_MASK	\
		(0x3                                    << TEGRA30_SPDIF_CIF_TXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_CH0	\
		(TEGRA30_SPDIF_CIF_STEREO_CH0  << TEGRA30_SPDIF_CIF_TXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_CH1	\
		(TEGRA30_SPDIF_CIF_STEREO_CH1  << TEGRA30_SPDIF_CIF_TXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_AVG	\
		(TEGRA30_SPDIF_CIF_STEREO_AVG  << TEGRA30_SPDIF_CIF_TXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_STEREO_CONV_RSVD	\
		(TEGRA30_SPDIF_CIF_STEREO_RSVD << TEGRA30_SPDIF_CIF_TXU_CTRL_0_STEREO_CONV_SHIFT)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT		6
#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_MASK		\
		(0x3                           << TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_ZERO		\
		(TEGRA30_SPDIF_CIF_EXPAND_ZERO << TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_ONE		\
		(TEGRA30_SPDIF_CIF_EXPAND_ONE  << TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_LFSR		\
		(TEGRA30_SPDIF_CIF_EXPAND_LFSR << TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_RSVD		\
		(TEGRA30_SPDIF_CIF_EXPAND_RSVD << TEGRA30_SPDIF_CIF_TXU_CTRL_EXPAND_SHIFT)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT	8
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT	12
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT 16
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_TXU_CTRL_CLIENT_CH_SHIFT)


#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT	24
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_TXU_CTRL_AUDIO_CH_SHIFT)

#define TEGRA30_SPDIF_CIF_TXU_CTRL_FIFO_TH_SHIFT	28
#define TEGRA30_SPDIF_CIF_TXU_CTRL_FIFO_TH_MASK		(0x7 << TEGRA30_SPDIF_CIF_TXU_CTRL_FIFO_TH_SHIFT)

/* Fields in TEGRA30_TEGRA30_SPDIF_CIF_RXU_CTRL */
#define TEGRA30_SPDIF_CIF_RXU_CTRL_MONO_CONV_COPY	(1<<0)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_TRUNCATE_CHOP	(1<<1)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_DIRECTION_RXCIF	(1<<2)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_REPLICATE_ENABLE	(1<<3)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_SHIFT	4
#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_MASK	\
		(0x3                           << TEGRA30_SPDIF_CIF_RXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_CH0	\
		(TEGRA30_SPDIF_CIF_STEREO_CH0  << TEGRA30_SPDIF_CIF_RXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_CH1	\
		(TEGRA30_SPDIF_CIF_STEREO_CH1  << TEGRA30_SPDIF_CIF_RXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_AVG	\
		(TEGRA30_SPDIF_CIF_STEREO_AVG  << TEGRA30_SPDIF_CIF_RXU_CTRL_0_STEREO_CONV_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_STEREO_CONV_RSVD	\
		(TEGRA30_SPDIF_CIF_STEREO_RSVD << TEGRA30_SPDIF_CIF_RXU_CTRL_0_STEREO_CONV_SHIFT)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT		6
#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_MASK		\
		(0x3                           << TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_ZERO		\
		(TEGRA30_SPDIF_CIF_EXPAND_ZERO << TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_ONE		\
		(TEGRA30_SPDIF_CIF_EXPAND_ONE  << TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_LFSR		\
		(TEGRA30_SPDIF_CIF_EXPAND_LFSR << TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_RSVD		\
		(TEGRA30_SPDIF_CIF_EXPAND_RSVD << TEGRA30_SPDIF_CIF_RXU_CTRL_EXPAND_SHIFT)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT	8
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT	12
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_MASK	\
		(0x7                     << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT4		\
		(TEGRA30_SPDIF_CIF_BIT4  << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT8		\
		(TEGRA30_SPDIF_CIF_BIT8  << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT12		\
		(TEGRA30_SPDIF_CIF_BIT12 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT16		\
		(TEGRA30_SPDIF_CIF_BIT16 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT20		\
		(TEGRA30_SPDIF_CIF_BIT20 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT24		\
		(TEGRA30_SPDIF_CIF_BIT24 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT28		\
		(TEGRA30_SPDIF_CIF_BIT28 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BIT32		\
		(TEGRA30_SPDIF_CIF_BIT32 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_BITS_SHIFT)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT 16
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_RXU_CTRL_CLIENT_CH_SHIFT)


#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT	24
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_MASK	\
		(0x7                   << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH1		\
		(TEGRA30_SPDIF_CIF_CH1 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH2		\
		(TEGRA30_SPDIF_CIF_CH2 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH3		\
		(TEGRA30_SPDIF_CIF_CH3 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH4		\
		(TEGRA30_SPDIF_CIF_CH4 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH5		\
		(TEGRA30_SPDIF_CIF_CH5 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH6		\
		(TEGRA30_SPDIF_CIF_CH6 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH7		\
		(TEGRA30_SPDIF_CIF_CH7 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)
#define TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH8		\
		(TEGRA30_SPDIF_CIF_CH8 << TEGRA30_SPDIF_CIF_RXU_CTRL_AUDIO_CH_SHIFT)

#define TEGRA30_SPDIF_CIF_RXU_CTRL_FIFO_TH_SHIFT	28
#define TEGRA30_SPDIF_CIF_RXU_CTRL_FIFO_TH_MASK		(0x7 << TEGRA30_SPDIF_CIF_RXU_CTRL_FIFO_TH_SHIFT)

/* Fields in TEGRA30_SPDIF_CH_STA_RX_A */
/* Fields in TEGRA30_SPDIF_CH_STA_RX_B */
/* Fields in TEGRA30_SPDIF_CH_STA_RX_C */
/* Fields in TEGRA30_SPDIF_CH_STA_RX_D */
/* Fields in TEGRA30_SPDIF_CH_STA_RX_E */
/* Fields in TEGRA30_SPDIF_CH_STA_RX_F */

/*
 * The 6-word receive channel data page buffer holds a block (192 frames) of
 * channel status information. The order of receive is from LSB to MSB
 * bit, and from CH_STA_RX_A to CH_STA_RX_F then back to CH_STA_RX_A.
 */

/* Fields in TEGRA30_SPDIF_CH_STA_TX_A */
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_22050			0x4
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_24000			0x6
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_32000			0x3
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_44100			0x0
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_48000			0x2
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_88200			0x8
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_96000			0xA
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_176400			0xC
#define TEGRA30_SPDIF_CH_STA_TX_A_SF_192000			0xE

#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT		24
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_MASK		\
		(0xF                                 << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_22050	\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_22050  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_24000		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_24000  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_32000		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_32000  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_44100		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_44100  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_48000		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_48000  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_88200		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_88200  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_96000		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_96000  << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_176400		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_176400 << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_192000		\
		(TEGRA30_SPDIF_CH_STA_TX_A_SF_192000 << TEGRA30_SPDIF_CH_STA_TX_A_SAMP_FREQ_SHIFT)

/* Fields in TEGRA30_SPDIF_CH_STA_TX_B */
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_8000			0x6
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_11025			0xA
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_12000			0x2
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_16000			0x8
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_22050			0xB
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_24000			0x9
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_32000			0xC
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_44100			0xF
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_48000			0xD
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_88200			0x7
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_96000			0x5
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_176400			0x3
#define TEGRA30_SPDIF_CH_STA_TX_B_SF_192000			0x1

#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT		4
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_MASK		\
		(0xF                                 << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_8000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_8000   << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_11025		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_11025  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_12000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_12000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_16000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_16000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_22050		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_22025  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_24000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_24000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_32000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_32000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_44100		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_44100  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_48000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_48000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_88200		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_88200  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_96000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_96000  << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_176400		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_176400 << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)
#define TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_192000		\
		(TEGRA30_SPDIF_CH_STA_TX_B_SF_192000 << TEGRA30_SPDIF_CH_STA_TX_B_ORIG_SAMP_FREQ_SHIFT)

/* Fields in TEGRA30_SPDIF_CH_STA_TX_C */
/* Fields in TEGRA30_SPDIF_CH_STA_TX_D */
/* Fields in TEGRA30_SPDIF_CH_STA_TX_E */
/* Fields in TEGRA30_SPDIF_CH_STA_TX_F */

/* Fields in TEGRA30_SPDIF_FLOWCTL_CTRL */
#define TEGRA30_SPDIF_FLOWCTL_CTRL_FILTER_QUAD		(1<<31)

/* Fields in TEGRA30_SPDIF_TX_STEP */
#define TEGRA30_SPDIF_TX_STEP_STEP_SIZE_SHIFT		0
#define TEGRA30_SPDIF_TX_STEP_STEP_SIZE_MASK		(0xffff << TEGRA30_SPDIF_TX_STEP_STEP_SIZE_SHIFT)

/* Fields in TEGRA30_SPDIF_FLOW_STATUS */
#define TEGRA30_SPDIF_FLOW_STATUS_COUNTER_EN_ENABLE	(1<<1)
#define TEGRA30_SPDIF_FLOW_STATUS_MONITOR_CLR_CLEAR	(1<<2)
#define TEGRA30_SPDIF_FLOW_STATUS_COUNTER_CLR_CLEAR	(1<<3)
#define TEGRA30_SPDIF_FLOW_STATUS_MONITOR_INT_EN_ENABLE	(1<<4)
#define TEGRA30_SPDIF_FLOW_STATUS_FLOW_OVERFLOW_OVER	(1<<30)
#define TEGRA30_SPDIF_FLOW_STATUS_FLOW_UNDERFLOW_UNDER	(1<<31)

/* Fields in TEGRA30_SPDIF_FLOW_TOTAL */
/* Fields in TEGRA30_SPDIF_FLOW_OVER */
/* Fields in TEGRA30_SPDIF_FLOW_UNDER */

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_0 */
#define TEGRA30_SPDIF_LCOEF_1_4_0_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_0_COEF_MASK		(0xffff << TEGRA30_TEGRA30_SPDIF_LCOEF_1_4_0_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_1 */
#define TEGRA30_SPDIF_LCOEF_1_4_1_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_1_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_1_4_1_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_2 */
#define TEGRA30_SPDIF_LCOEF_1_4_2_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_2_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_1_4_2_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_3 */
#define TEGRA30_SPDIF_LCOEF_1_4_3_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_3_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_1_4_3_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_4 */
#define TEGRA30_SPDIF_LCOEF_1_4_4_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_4_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_1_4_4_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_1_4_5 */
#define TEGRA30_SPDIF_LCOEF_1_4_5_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_1_4_5_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_1_4_5_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_2_4_0 */
#define TEGRA30_SPDIF_LCOEF_2_4_0_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_2_4_0_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_2_4_0_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_2_4_1 */
#define TEGRA30_SPDIF_LCOEF_2_4_1_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_2_4_1_COEF_MASK		(0xffff << TEGRA30_SPDIF_LCOEF_2_4_1_COEF_SHIFT)

/* Fields in TEGRA30_SPDIF_LCOEF_2_4_2 */
#define TEGRA30_SPDIF_LCOEF_2_4_2_COEF_SHIFT		0
#define TEGRA30_SPDIF_LCOEF_2_4_2_COEF_MASK		(0xffff << SPDIF_LCOEF_2_4_2_COEF_SHIFT)

struct tegra30_spdif {
	struct clk *clk_spdif_out;
	struct clk *clk_hda2codec;
	enum tegra30_ahub_txcif txcif;
	struct tegra_pcm_dma_params playback_dma_data;
	void __iomem *regs;
	struct dentry *debug;
	u32 reg_ctrl;
	u32 reg_ch_sta_a;
	u32 reg_ch_sta_b;
};

#endif