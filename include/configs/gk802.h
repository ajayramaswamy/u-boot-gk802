/*
 * Copyright (C) 2012 Freescale Semiconductor, Inc.
 * Copyright (C) 2013 James Laird <jhl@mafipulation.org>
 *
 * Configuration settings for the Freescale i.MX6Q-based GK802
 * and HI802 (and related) family of HDMI "dongle" computers.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.         See the
 * GNU General Public License for more details.
 */

#ifndef __MX6Q_GK802_CONFIG_H
#define __MX6Q_GK802_CONFIG_H

#define CONFIG_MACH_TYPE	3980
#define CONFIG_MXC_UART_BASE	UART4_BASE
#define CONFIG_CONSOLE_DEV	"ttymxc3"
#define PHYS_SDRAM_SIZE		(1u * 1024 * 1024 * 1024)


#define CONFIG_MX6
#define CONFIG_MX6Q
#define CONFIG_DISPLAY_CPUINFO
#define CONFIG_DISPLAY_BOARDINFO

#define CONFIG_VIDEO
#define CONFIG_VIDEO_IPUV3
#define CONFIG_CFB_CONSOLE
#define CONFIG_CFB_CONSOLE_ANSI
#define CONFIG_VGA_AS_SINGLE_DEVICE
#define CONFIG_VIDEO_BMP_RLE8
#define CONFIG_SPLASH_SCREEN
#define CONFIG_BMP_16BPP
#define CONFIG_VIDEO_LOGO
#define CONFIG_IPUV3_CLK 260000000
#define CONFIG_CMD_HDMIDETECT
#define CONFIG_SYS_CONSOLE_IS_IN_ENV
#define CONFIG_CONSOLE_MUX

#define CONFIG_CMD_USB
#define CONFIG_USB_EHCI
#define CONFIG_USB_EHCI_MX6
#define CONFIG_EHCI_IS_TDI
#define CONFIG_USB_STORAGE
#define CONFIG_USB_KEYBOARD
#define CONFIG_MXC_USB_PORT	0
#define CONFIG_MXC_USB_PORTSC	(PORT_PTS_UTMI | PORT_PTS_PTW)
#define CONFIG_MXC_USB_FLAGS	0

#define CONFIG_HDMI_XRES 1024
#define CONFIG_HDMI_YRES 768
#define CONFIG_HDMI_REFRESH 60

#include <asm/arch/imx-regs.h>

#define CONFIG_CMDLINE_TAG
#define CONFIG_SETUP_MEMORY_TAGS
#define CONFIG_INITRD_TAG
#define CONFIG_REVISION_TAG

/* Size of malloc() pool */
#define CONFIG_SYS_MALLOC_LEN		(10 * 1024 * 1024)

#define CONFIG_BOARD_EARLY_INIT_F
#define CONFIG_BOARD_RECOVERY_INIT_F
#define CONFIG_MXC_GPIO

#define CONFIG_MXC_UART

/* MMC Configs */
#define CONFIG_FSL_ESDHC
#define CONFIG_FSL_USDHC
#define CONFIG_SYS_FSL_ESDHC_ADDR      0

#define CONFIG_MMC
#define CONFIG_CMD_MMC
#define CONFIG_GENERIC_MMC
#define CONFIG_MMC_BOUNCE_BUFFER
#define CONFIG_CMD_EXT2
#define CONFIG_CMD_EXT4
#define CONFIG_CMD_FAT
#define CONFIG_CMD_FS_GENERIC
#define CONFIG_DOS_PARTITION
#define CONFIG_EFI_PARTITION

/* allow to overwrite serial and ethaddr */
#define CONFIG_ENV_OVERWRITE
#define CONFIG_BAUDRATE                115200

/* Command definition */
#include <config_cmd_default.h>

#define CONFIG_CMD_BOOTZ
#define CONFIG_SUPPORT_RAW_INITRD
#undef CONFIG_CMD_IMLS

#define CONFIG_BOOTDELAY               5
#define CONFIG_PREBOOT

#define CONFIG_LOADADDR                0x10800000
#define CONFIG_SYS_TEXT_BASE           0x27800000

#define CONFIG_SYS_SKIP_ARM_RELOCATION

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=" CONFIG_CONSOLE_DEV "\0" \
	"bootscript=boot.scr\0" \
	"uimage=uImage\0" \
	"trymmcdev=1 0\0" \
	"trymmcpart=2 1\0" \
	"trymmcdir=/boot/ /\0" \
	"tryusbpart=3 2 1\0" \
	"tryusbdir=/boot/ /\0"

#define CONFIG_BOOTCOMMAND                                      \
"for mmcdev in ${trymmcdev}; do "                               \
"for mmcpart in ${trymmcpart}; do "				\
"for mmcdir in ${trymmcdir}; do "				\
"    if mmc dev ${mmcdev}; then"                                \
"        echo ===> Executing load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${mmcdir}${bootscript};" \
"        if load mmc ${mmcdev}:${mmcpart} ${loadaddr} ${mmcdir}${bootscript}; then"   \
"            source;"                                           \
"        fi;"                                                   \
"    fi;"                                                       \
"done;"                                                         \
"done;"                                                         \
"done;"                                                         \
"usb start;"                                                    \
"setenv usbdev 0;"                                              \
"while usb dev ${usbdev}; do "                                  \
"for usbpart in ${tryusbpart}; do "				\
"for usbdir in ${tryusbdir}; do "				\
"    echo ===> Executing load usb ${usbdev}:${usbpart} ${loadaddr} ${usbdir}${bootscript};" \
"    if load ${usbdev}:${usbpart} ${loadaddr} ${usbdir}${bootscript}; then"       \
"        source;"                                               \
"    fi;"                                                       \
"    setexpr usbdev ${usbdev} + 1; "                             \
"done;"                                                         \
"done;"                                                         \
"done;"                                                         \
"echo No boot devices found."

/* Miscellaneous configurable options */
#define CONFIG_SYS_LONGHELP
#define CONFIG_SYS_HUSH_PARSER
#define CONFIG_SYS_PROMPT_HUSH_PS2     "> "
#define CONFIG_SYS_PROMPT              "U-Boot > "
#define CONFIG_AUTO_COMPLETE
#define CONFIG_SYS_CBSIZE              256

/* Print Buffer Size */
#define CONFIG_SYS_PBSIZE (CONFIG_SYS_CBSIZE + sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_MAXARGS             16
#define CONFIG_SYS_BARGSIZE CONFIG_SYS_CBSIZE

#define CONFIG_SYS_MEMTEST_START       0x10000000
#define CONFIG_SYS_MEMTEST_END         0x10010000

#define CONFIG_SYS_LOAD_ADDR           CONFIG_LOADADDR
#define CONFIG_SYS_HZ                  1000

#define CONFIG_CMDLINE_EDITING
#define CONFIG_STACKSIZE               (128 * 1024)

/* Physical Memory Map */
#define CONFIG_NR_DRAM_BANKS           1
#define PHYS_SDRAM                     MMDC0_ARB_BASE_ADDR

#define CONFIG_SYS_SDRAM_BASE          PHYS_SDRAM
#define CONFIG_SYS_INIT_RAM_ADDR       IRAM_BASE_ADDR
#define CONFIG_SYS_INIT_RAM_SIZE       IRAM_SIZE

#define CONFIG_SYS_INIT_SP_OFFSET \
	(CONFIG_SYS_INIT_RAM_SIZE - GENERATED_GBL_DATA_SIZE)
#define CONFIG_SYS_INIT_SP_ADDR \
	(CONFIG_SYS_INIT_RAM_ADDR + CONFIG_SYS_INIT_SP_OFFSET)

/* FLASH and environment organization */
#define CONFIG_SYS_NO_FLASH

#define CONFIG_ENV_SIZE			(8 * 1024)

#define CONFIG_ENV_IS_IN_MMC

#if defined(CONFIG_ENV_IS_IN_MMC)
#define CONFIG_ENV_OFFSET		(6 * 64 * 1024)
#define CONFIG_SYS_MMC_ENV_DEV		0
#endif

#define CONFIG_OF_LIBFDT

#ifndef CONFIG_SYS_DCACHE_OFF
#define CONFIG_CMD_CACHE
#endif

#define CONFIG_CMD_SETEXPR

#undef CONFIG_CMD_FPGA		/* FPGA configuration Support	*/
#undef CONFIG_CMD_NET		/* bootp, tftpboot, rarpboot	*/
#undef CONFIG_CMD_NFS		/* NFS support			*/
#undef CONFIG_CMD_SETGETDCR	/* DCR support on 4xx		*/

#endif
