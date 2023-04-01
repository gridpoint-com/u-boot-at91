/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * Configuration file for the SAMA5D27 SOM1 EK Board.
 *
 * Copyright (C) 2017 Microchip Corporation
 *		      Wenyou Yang <wenyou.yang@microchip.com>
 */

#ifndef __CONFIG_H
#define __CONFIG_H

#include "at91-sama5_common.h"

#undef CONFIG_SYS_AT91_MAIN_CLOCK
#define CONFIG_SYS_AT91_MAIN_CLOCK      24000000 /* from 24 MHz crystal */

#ifdef CONFIG_SPL_BUILD
#define CONFIG_SYS_INIT_SP_ADDR     0x218000
#elif CONFIG_CLK_SCMI
#define CONFIG_SYS_INIT_SP_ADDR \
    (0x22000000 + 16 * 1024 + CONFIG_SYS_MALLOC_F_LEN - \
     GENERATED_GBL_DATA_SIZE)
#else
#define CONFIG_SYS_INIT_SP_ADDR \
    (0x20000000 + 16 * 1024 + CONFIG_SYS_MALLOC_F_LEN - \
     GENERATED_GBL_DATA_SIZE)
#endif

/* USB */
#ifdef CONFIG_CMD_USB
#define CONFIG_USB_ATMEL
#define CONFIG_USB_ATMEL_CLK_SEL_UPLL
#define CONFIG_USB_OHCI_NEW
#define CONFIG_SYS_USB_OHCI_CPU_INIT
#define CONFIG_SYS_USB_OHCI_REGS_BASE            ATMEL_BASE_OHCI
#define CONFIG_SYS_USB_OHCI_SLOT_NAME "ec3"
#define CONFIG_SYS_USB_OHCI_MAX_ROOT_PORTS       3
#define ATMEL_ID_UHP ATMEL_ID_UHPHS
#define ATMEL_PMC_UHP ATMEL_ID_SYS
#endif

/* NAND flash */
/*#undef CONFIG_CMD_NAND*/
/*#define CONFIG_SYS_MAX_NAND_DEVICE 1*/

/* Ethernet Hardware */
#define CONFIG_RMII
#define CONFIG_NET_RETRY_COUNT		20
#define CONFIG_MACB_SEARCH_PHY

#define CONFIG_ENV_SECT_SIZE		0x1000

/* SPL */
#define CONFIG_SPL_MAX_SIZE		0x10000
#define CONFIG_SPL_BSS_START_ADDR	0x20000000
#define CONFIG_SPL_BSS_MAX_SIZE		0x80000
#define CONFIG_SYS_SPL_MALLOC_START	0x20080000
#define CONFIG_SYS_SPL_MALLOC_SIZE	0x80000

#define CONFIG_SYS_MONITOR_LEN		(512 << 10)

#endif
