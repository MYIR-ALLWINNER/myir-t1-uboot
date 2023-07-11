/**
 * SPDX-License-Identifier: GPL-2.0+
 * aw_rawnand_ids.c
 *
 * (C) Copyright 2020 - 2021
 * Allwinner Technology Co., Ltd. <www.allwinnertech.com>
 * cuizhikui <cuizhikui@allwinnertech.com>
 *
 */
#include <common.h>
#include <linux/mtd/aw-rawnand.h>
#include <linux/sizes.h>




struct aw_nand_flash_dev giga[] = {
	{
		.name = "GD9FU2G8F2A",
		.id = {0xc8, 0xda, 0x90, 0x95, 0x46},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_PAGE,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ERASE,
	},
	{
		.name = "GD9FU1G8F2A",
		.id = {0xc8, 0xf1, 0x80, 0x1d, 0x42},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_ROW_ADDR_2,
	},
	{
		.name = "GD9FU1G8F2G",
		.id = {0xc8, 0xf1, 0x80, 0x95, 0x43},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_AND_LAST_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_ROW_ADDR_2,
	},
	{
		.name = "GD9FU4G8F2A",
		.id = {0xc8, 0xdc, 0x90, 0x95, 0x16},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_AND_LAST_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
};

struct aw_nand_flash_dev mxic[] = {
	{
		.name = "MX30LF2G18AC",
		.id = {0xc2, 0xda, 0x90, 0x95, 0x06},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_PAGE,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
};

struct aw_nand_flash_dev mircon[] = {
	{
		.name = "MT29F1G08ABAEA",
		.id = {0x2c, 0xf1, 0x80, 0x95, 0x04},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_PAGE,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
	{
		.name = "MT29F2G08ABAGA",
		.id = {0x2c, 0xda, 0x90, 0x95, 0x06},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_PAGE,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
};

struct aw_nand_flash_dev windbond[] = {
	{
		.name = "W29N02KV",
		.id = {0xef, 0xda, 0x10, 0x95, 0x06},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
	{
		.name = "W29N04GV",
		.id = {0xef, 0xdc, 0x90, 0x95, 0x54},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
	{
		.name = "W29N01HV",
		.id = {0xef, 0xf1, 0x00, 0x95, 0x00},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM,
	},
};

struct aw_nand_flash_dev foresee[] = {
	{
		.name = "FS33ND01GS1",
		.id = {0xec, 0xf1, 0x00, 0x95, 0x42},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM,
	},
	{
		.name = "FS33ND04GS1",
		.id = {0xec, 0xdc, 0x10, 0x95, 0x56},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_JEDEC_MULTI_WRITE | RAWNAND_MULTI_ERASE,
	},
};

struct aw_nand_flash_dev spansion[] = {
	{
		.name = "S34ML04G2",
		.id = {0x01, 0xdc, 0x90, 0x95, 0x56},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
	{
		.name = "S34ML01G1",
		.id = {0x01, 0xf1, 0x80, 0x1d},
		.id_len = 4,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_AND_LAST_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_ROW_ADDR_2,
	},
	{
		.name = "S34ML02G1",
		.id = {0x01, 0xda, 0x90, 0x95, 0x46},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_AND_LAST_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
	{
		.name = "S34ML04G3",
		.id = {0x01, 0xdc, 0x00, 0x05, 0x04},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_AND_LAST_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM,
	},
};

struct aw_nand_flash_dev toshiba[] = {
	{
		.name = "TC58NVG1S3HTA00",
		.id = {0x98, 0xda, 0x90, 0x15, 0x76},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_PAGE,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_JEDEC_MULTI_WRITE | RAWNAND_MULTI_ERASE,
	},
};

struct aw_nand_flash_dev fidelix[] = {
	{
		.name = "FMND1G08U3J",
		.id = {0xad, 0xf1, 0x80, 0x1d},
		.id_len = 4,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_50K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_ROW_ADDR_2,
	},
};

struct aw_nand_flash_dev unilc[] = {
	{
		.name = "SCN00SA1T1AI6A",
		.id = {0xc8, 0xd1, 0x80, 0x95, 0x42},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 1024,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_ROW_ADDR_2,
	},
	{
		.name = "SCN01SA1T1AI7A",
		.id = {0xc8, 0xda, 0x90, 0x95, 0x44},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ERASE,
	},
};

struct aw_nand_flash_dev jsc[] = {
	{
		.name = "JS27HU2G08SCN",
		.id = {0xad, 0xda, 0x90, 0x95, 0x46},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 64,
		.pages_per_blk = 64,
		.blks_per_die = 2048,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
};

struct aw_nand_flash_dev dosilicon[] = {
	{
		.name = "FMND4G08U3C",
		.id = {0xf8, 0xdc, 0x90, 0x95, 0x46},
		.id_len = 5,
		.dies_per_chip = 1,
		.pagesize = SZ_2K,
		.sparesize = 128,
		.pages_per_blk = 64,
		.blks_per_die = 4096,
		.access_freq = 40,
		.badblock_flag_pos = PST_FIRST_TWO_PAGES,
		.pe_cycles = PE_CYCLES_100K,
		.options = RAWNAND_ITF_SDR | RAWNAND_NFC_RANDOM | RAWNAND_MULTI_WRITE | RAWNAND_MULTI_ONFI_ERASE,
	},
};

struct rawnand_manufacture aw_manuf_tbl[] = {
	RAWNAND_MANUFACTURE(RAWNAND_MFR_GIGA, GIGA_NAME, giga),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_MXIC, MXIC_NAME, mxic),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_MICRON, MICRON_NAME, mircon),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_WINBOND, WINBOND_NAME, windbond),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_FORESEE, FORESEE_NAME, foresee),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_SPANSION, SPANSION_NAME, spansion),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_TOSHIBA, TOSHIBA_NAME, toshiba),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_FIDELIX, FIDELIX_NAME, fidelix),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_UNILC, UNILC_NAME, unilc),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_JSC, JSC_NAME, jsc),
	RAWNAND_MANUFACTURE(RAWNAND_MFR_DOSILICON, DOSILICON_NAME, dosilicon),
};

AW_NAND_MANUFACTURE(aw_nand_manufs, aw_manuf_tbl);
