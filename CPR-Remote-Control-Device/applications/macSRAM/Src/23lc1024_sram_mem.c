/*
 * Copyright (c) 2006-2021, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2025-08-22     Administrator       the first version
 */
#include "23lc1024_sram_mem.h"


#define EX_SARM_POOL_START 0x00000  // 23LC1024 内部偏移 0
static uint32_t pool_offset = 0;    // 简易“指针”


typedef struct {
    uint32_t addr;
    size_t   size;
} block_hdr_t;



//void *sram_malloc(size_t size)
//{
//    if (pool_offset + sizeof(block_hdr_t) + size > 128 * 1024){
//        return NULL;                // 超出容量
//    }
//
//    uint32_t addr = POOL_START + pool_offset;
//    block_hdr_t hdr = { .addr = addr + sizeof(block_hdr_t), .size = size };
//    sram_write_sequence(addr, (uint8_t *)&hdr, sizeof(hdr));
//    sram_write_sequence(hdr.addr, (uint8_t *)"", size); // 清零
//    pool_offset += sizeof(block_hdr_t) + size;
//    return (void *)(uintptr_t)hdr.addr;   // 返回“伪指针”
//}




