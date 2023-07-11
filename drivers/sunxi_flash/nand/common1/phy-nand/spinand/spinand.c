/* SPDX-License-Identifier: GPL-2.0 */

#include <linux/mtd/aw-spinand-nftl.h>
#include "spinand.h"
#include "spinand_debug.h"
#include "../nand_boot.h"
#include "../nand_physic_interface.h"
#include "../nand_secure_storage.h"
#include "../nand_weak.h"
/*#include "../nand.h"*/

spinand_storage_info_t spinand_storage_info;

void spinand_get_phy_storage_info(void)
{
	spinand_storage_info.ChipCnt = (__u8)spinand_nftl_get_chip_cnt();
	spinand_storage_info.ChipConnectInfo = 0x01; /*now only support one chip*/
	spinand_storage_info.ConnectMode = 0x01;
	spinand_storage_info.BankCntPerChip = 1;
	spinand_storage_info.DieCntPerChip = (__u8)spinand_nftl_get_die_cnt();
	spinand_storage_info.PlaneCntPerDie = spinand_nftl_get_multi_plane_flag() ? 2 : 1;
	spinand_storage_info.SectorCntPerPage = (__u8)spinand_nftl_get_single_page_size(SECTOR);
	spinand_storage_info.PageCntPerPhyBlk = (__u16)spinand_nftl_get_single_block_size(PAGE);
	spinand_storage_info.BlkCntPerDie = spinand_nftl_get_die_size(BLOCK);
	spinand_storage_info.OperationOpt = spinand_nftl_get_operation_opt();
	spinand_nftl_get_chip_id(spinand_storage_info.NandChipId);
	spinand_storage_info.MaxEraseTimes = spinand_nftl_get_max_erase_times();
}

unsigned int spinand_get_arch_info_str(char *buf)
{
	__s32 ret = 0;
	u32 id = (spinand_storage_info.NandChipId[0] << 0) |
		 (spinand_storage_info.NandChipId[1] << 8) |
		 (spinand_storage_info.NandChipId[2] << 16) |
		 (spinand_storage_info.NandChipId[3] << 24);
	u32 size = SECTOR_SIZE * spinand_storage_info.SectorCntPerPage *
		   spinand_storage_info.PageCntPerPhyBlk *
		   spinand_storage_info.BlkCntPerDie * spinand_storage_info.DieCntPerChip *
		   spinand_storage_info.ChipCnt / 1024 / 1024;

	ret += sprintf(buf + ret, "NandID: 0x%x\n", id);
	ret += sprintf(buf + ret, "Size: %dM\n", size);
	ret += sprintf(buf + ret, "DieCntPerChip: %d\n",
		       spinand_storage_info.DieCntPerChip);
	ret += sprintf(buf + ret, "SectCntPerPage: %d\n",
		       spinand_storage_info.SectorCntPerPage);
	ret += sprintf(buf + ret, "PageCntPerBlk: %d\n",
		       spinand_storage_info.PageCntPerPhyBlk);
	ret += sprintf(buf + ret, "BlkCntPerDie: %d\n",
		       spinand_storage_info.BlkCntPerDie);
	ret += sprintf(buf + ret, "OperationOpt: 0x%x\n",
		       spinand_storage_info.OperationOpt);
	return ret;
}

/**
 * @spinand_nftl_get_lsb_page_cnt_per_block(void)
 *
 * @Returns the lsb page count in per block.
 */
unsigned int spinand_lsb_page_cnt_per_block(void)
{
	/*spi nand have no lsb/msb page at present*/
	return 0;
}

/**
 * @spinand_get_page_num(unsigned int lsb_page_no)
 *
 * @Returns the lsb page num.
 */
unsigned int spinand_get_page_num(unsigned int lsb_page_no)
{
	return lsb_page_no;
}

void spinand_get_nand_info(struct _nand_info *aw_nand_info)
{

	//memset(aw_nand_info, 0x0, sizeof(struct _nand_info));

	aw_nand_info->type = 2; //NAND_STORAGE_TYPE_SPINAND;
	aw_nand_info->SectorNumsPerPage = (unsigned short)spinand_nftl_get_super_page_size(SECTOR);
	aw_nand_info->BytesUserData = AW_NFTL_OOB_LEN;
	//LogicArchiPar.LogicBlkCntPerLogicDie;
	aw_nand_info->BlkPerChip = (unsigned short)spinand_nftl_get_chip_size(BLOCK);
	//LogicArchiPar.LogicDieCnt;
	aw_nand_info->ChipNum = (unsigned short)spinand_nftl_get_die_cnt();
	//LogicArchiPar.PageCntPerLogicBlk;
	aw_nand_info->PageNumsPerBlk = (unsigned short)spinand_nftl_get_super_block_size(PAGE);

	aw_nand_info->FullBitmap = SPINAND_FULL_BITMAP_OF_SUPER_PAGE;

	aw_nand_info->MaxBlkEraseTimes = spinand_nftl_get_max_erase_times();

	if (SPINAND_SUPPORT_READ_RECLAIM)
		aw_nand_info->EnableReadReclaim = 1;
	else
		aw_nand_info->EnableReadReclaim = 0;

	aw_nand_info->boot = phyinfo_buf;

	if (aw_nand_info->boot->physic_block_reserved == 0)
		aw_nand_info->boot->physic_block_reserved = PHYSIC_RECV_BLOCK;
	/*get uboot physical domain into aw_nand_info */
	set_uboot_start_and_end_block();
	return;
}

/*
 *void spinand_pr_version(void)
 *{
 *        int ver[4] = {0};
 *
 *        nand_get_drv_version(&ver[0], &ver[1], &ver[2], &ver[3]);
 *        spinand_print("kernel: version: %x %x %x %x\n",
 *                      ver[0], ver[1], ver[2], ver[3]);
 *}
 */

/*
 *  spinand_hardware_init - spinand hardware init in aw_spinand_probe,
 *  which in where /drivers/mtd/aw-spinand/sunxi-nftl-core.c ;here only
 *  to do 1@get boot info,2@get nand info,3@secure_storage_init
 *
 *  returns: nand_info success; NULL fail
 */

struct _nand_info *spinand_hardware_init(void)
{
	__s32 ret = 0;

	SPINAND_INFO("%s: Start to get nand info and boot inf\n", __func__);

	/*spinand_pr_version();*/

	/*get boot info*/
	ret = nand_physic_info_read();

	/*get nand_info*/
	spinand_get_nand_info(&aw_nand_info);

	/*get physic storage info*/
	spinand_get_phy_storage_info();

	nand_secure_storage_init(1);

	if (ret < 0)
		SPINAND_ERR("%s: End Nand Hardware initializing ..... FAIL!\n", __func__);
	else
		SPINAND_INFO("%s: End Nand Hardware initializing ..... OK!\n", __func__);

	return (ret < 0) ? (struct _nand_info *)NULL : &aw_nand_info;
}

__s32 spinand_hardware_exit(void)
{
	//PHY_Exit();
	return 0;
}
