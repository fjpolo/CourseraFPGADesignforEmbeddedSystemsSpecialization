/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'nios' in SOPC Builder design 'nios_sys'
 * SOPC Builder design path: ../../nios_sys.sopcinfo
 *
 * Generated: Thu Aug 17 09:50:17 BST 2017
 */

/*
 * DO NOT MODIFY THIS FILE
 *
 * Changing this file will have subtle consequences
 * which will almost certainly lead to a nonfunctioning
 * system. If you do modify this file, be aware that your
 * changes will be overwritten and lost when this file
 * is generated again.
 *
 * DO NOT MODIFY THIS FILE
 */

/*
 * License Agreement
 *
 * Copyright (c) 2008
 * Altera Corporation, San Jose, California, USA.
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 * This agreement shall be governed in all respects by the laws of the State
 * of California and by the laws of the United States of America.
 */

#ifndef __SYSTEM_H_
#define __SYSTEM_H_

/* Include definitions from linker script generator */
#include "linker.h"


/*
 * CPU configuration
 *
 */

#define ALT_CPU_ARCHITECTURE "altera_nios2_gen2"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x00010820
#define ALT_CPU_CPU_ARCH_NIOS2_R1
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x11
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x00008020
#define ALT_CPU_FLASH_ACCELERATOR_LINES 0
#define ALT_CPU_FLASH_ACCELERATOR_LINE_SIZE 0
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x11
#define ALT_CPU_NAME "nios"
#define ALT_CPU_OCI_VERSION 1
#define ALT_CPU_RESET_ADDR 0x00008000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x00010820
#define NIOS2_CPU_ARCH_NIOS2_R1
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x11
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x00008020
#define NIOS2_FLASH_ACCELERATOR_LINES 0
#define NIOS2_FLASH_ACCELERATOR_LINE_SIZE 0
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_ILLEGAL_INSTRUCTION_EXCEPTION
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x11
#define NIOS2_OCI_VERSION 1
#define NIOS2_RESET_ADDR 0x00008000


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_ONCHIP_MEMORY2
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SPI
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_NIOS2_GEN2
#define __ALTPLL


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "MAX 10"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart"
#define ALT_STDERR_BASE 0x10058
#define ALT_STDERR_DEV jtag_uart
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart"
#define ALT_STDIN_BASE 0x10058
#define ALT_STDIN_DEV jtag_uart
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart"
#define ALT_STDOUT_BASE 0x10058
#define ALT_STDOUT_DEV jtag_uart
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_sys"


/*
 * hal configuration
 *
 */

#define ALT_INCLUDE_INSTRUCTION_RELATED_EXCEPTION_API
#define ALT_MAX_FD 32
#define ALT_SYS_CLK none
#define ALT_TIMESTAMP_CLK none


/*
 * jtag_uart configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart altera_avalon_jtag_uart
#define JTAG_UART_BASE 0x10058
#define JTAG_UART_IRQ 1
#define JTAG_UART_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_NAME "/dev/jtag_uart"
#define JTAG_UART_READ_DEPTH 64
#define JTAG_UART_READ_THRESHOLD 8
#define JTAG_UART_SPAN 8
#define JTAG_UART_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_WRITE_DEPTH 64
#define JTAG_UART_WRITE_THRESHOLD 8


/*
 * onchip_ram configuration
 *
 */

#define ALT_MODULE_CLASS_onchip_ram altera_avalon_onchip_memory2
#define ONCHIP_RAM_ALLOW_IN_SYSTEM_MEMORY_CONTENT_EDITOR 0
#define ONCHIP_RAM_ALLOW_MRAM_SIM_CONTENTS_ONLY_FILE 0
#define ONCHIP_RAM_BASE 0x8000
#define ONCHIP_RAM_CONTENTS_INFO ""
#define ONCHIP_RAM_DUAL_PORT 0
#define ONCHIP_RAM_GUI_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_INIT_CONTENTS_FILE "nios_sys_onchip_ram"
#define ONCHIP_RAM_INIT_MEM_CONTENT 1
#define ONCHIP_RAM_INSTANCE_ID "NONE"
#define ONCHIP_RAM_IRQ -1
#define ONCHIP_RAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define ONCHIP_RAM_NAME "/dev/onchip_ram"
#define ONCHIP_RAM_NON_DEFAULT_INIT_FILE_ENABLED 0
#define ONCHIP_RAM_RAM_BLOCK_TYPE "AUTO"
#define ONCHIP_RAM_READ_DURING_WRITE_MODE "DONT_CARE"
#define ONCHIP_RAM_SINGLE_CLOCK_OP 0
#define ONCHIP_RAM_SIZE_MULTIPLE 1
#define ONCHIP_RAM_SIZE_VALUE 32768
#define ONCHIP_RAM_SPAN 32768
#define ONCHIP_RAM_TYPE "altera_avalon_onchip_memory2"
#define ONCHIP_RAM_WRITABLE 1


/*
 * pio_leds configuration
 *
 */

#define ALT_MODULE_CLASS_pio_leds altera_avalon_pio
#define PIO_LEDS_BASE 0x10020
#define PIO_LEDS_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LEDS_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LEDS_CAPTURE 0
#define PIO_LEDS_DATA_WIDTH 8
#define PIO_LEDS_DO_TEST_BENCH_WIRING 0
#define PIO_LEDS_DRIVEN_SIM_VALUE 0
#define PIO_LEDS_EDGE_TYPE "NONE"
#define PIO_LEDS_FREQ 50000000
#define PIO_LEDS_HAS_IN 0
#define PIO_LEDS_HAS_OUT 1
#define PIO_LEDS_HAS_TRI 0
#define PIO_LEDS_IRQ -1
#define PIO_LEDS_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PIO_LEDS_IRQ_TYPE "NONE"
#define PIO_LEDS_NAME "/dev/pio_leds"
#define PIO_LEDS_RESET_VALUE 0
#define PIO_LEDS_SPAN 16
#define PIO_LEDS_TYPE "altera_avalon_pio"


/*
 * pio_lis3dh configuration
 *
 */

#define ALT_MODULE_CLASS_pio_lis3dh altera_avalon_pio
#define PIO_LIS3DH_BASE 0x10030
#define PIO_LIS3DH_BIT_CLEARING_EDGE_REGISTER 0
#define PIO_LIS3DH_BIT_MODIFYING_OUTPUT_REGISTER 0
#define PIO_LIS3DH_CAPTURE 1
#define PIO_LIS3DH_DATA_WIDTH 2
#define PIO_LIS3DH_DO_TEST_BENCH_WIRING 1
#define PIO_LIS3DH_DRIVEN_SIM_VALUE 0
#define PIO_LIS3DH_EDGE_TYPE "RISING"
#define PIO_LIS3DH_FREQ 50000000
#define PIO_LIS3DH_HAS_IN 1
#define PIO_LIS3DH_HAS_OUT 0
#define PIO_LIS3DH_HAS_TRI 0
#define PIO_LIS3DH_IRQ 2
#define PIO_LIS3DH_IRQ_INTERRUPT_CONTROLLER_ID 0
#define PIO_LIS3DH_IRQ_TYPE "EDGE"
#define PIO_LIS3DH_NAME "/dev/pio_lis3dh"
#define PIO_LIS3DH_RESET_VALUE 0
#define PIO_LIS3DH_SPAN 16
#define PIO_LIS3DH_TYPE "altera_avalon_pio"


/*
 * pll configuration
 *
 */

#define ALT_MODULE_CLASS_pll altpll
#define PLL_BASE 0x10040
#define PLL_IRQ -1
#define PLL_IRQ_INTERRUPT_CONTROLLER_ID -1
#define PLL_NAME "/dev/pll"
#define PLL_SPAN 16
#define PLL_TYPE "altpll"


/*
 * spi_lis3dh configuration
 *
 */

#define ALT_MODULE_CLASS_spi_lis3dh altera_avalon_spi
#define SPI_LIS3DH_BASE 0x10000
#define SPI_LIS3DH_CLOCKMULT 1
#define SPI_LIS3DH_CLOCKPHASE 1
#define SPI_LIS3DH_CLOCKPOLARITY 1
#define SPI_LIS3DH_CLOCKUNITS "Hz"
#define SPI_LIS3DH_DATABITS 8
#define SPI_LIS3DH_DATAWIDTH 16
#define SPI_LIS3DH_DELAYMULT "1.0E-9"
#define SPI_LIS3DH_DELAYUNITS "ns"
#define SPI_LIS3DH_EXTRADELAY 0
#define SPI_LIS3DH_INSERT_SYNC 0
#define SPI_LIS3DH_IRQ 0
#define SPI_LIS3DH_IRQ_INTERRUPT_CONTROLLER_ID 0
#define SPI_LIS3DH_ISMASTER 1
#define SPI_LIS3DH_LSBFIRST 0
#define SPI_LIS3DH_NAME "/dev/spi_lis3dh"
#define SPI_LIS3DH_NUMSLAVES 1
#define SPI_LIS3DH_PREFIX "spi_"
#define SPI_LIS3DH_SPAN 32
#define SPI_LIS3DH_SYNC_REG_DEPTH 2
#define SPI_LIS3DH_TARGETCLOCK 1000000u
#define SPI_LIS3DH_TARGETSSDELAY "0.0"
#define SPI_LIS3DH_TYPE "altera_avalon_spi"


/*
 * sys_id configuration
 *
 */

#define ALT_MODULE_CLASS_sys_id altera_avalon_sysid_qsys
#define SYS_ID_BASE 0x10050
#define SYS_ID_ID 4660
#define SYS_ID_IRQ -1
#define SYS_ID_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SYS_ID_NAME "/dev/sys_id"
#define SYS_ID_SPAN 8
#define SYS_ID_TIMESTAMP 1502959301
#define SYS_ID_TYPE "altera_avalon_sysid_qsys"

#endif /* __SYSTEM_H_ */
