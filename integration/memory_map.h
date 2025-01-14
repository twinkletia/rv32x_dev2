#ifndef MEMORY_MAP_H
#define MEMORY_MAP_H

#include "clint.h"

#define BOOTROM_BASE 			0x0000_0000
#define BOOTROM_LENGTH 			0x0000_1000
#define CLINT_BASE				CLINT_BASE_ADDR
#define CLINT_LENGTH			CLINT_SIZE
#define IO_BASE					0x1000_0000
#define IO_LENGTH				0x0001_0000
#define IO0_BASE				0x4000_0000
#define IO0_LENGTH				0x0000_1000
#define IO1_BASE				0x4000_1000
#define IO1_LENGTH				0x0000_2000
#define SDRAM_BASE				0x8000_0000
#define SDRAM_LENGTH			0x0400_0000
#define PLIC_BASE 				0x0c00_0000
#define PLIC_LENGTH				0x1000_0000

#endif
