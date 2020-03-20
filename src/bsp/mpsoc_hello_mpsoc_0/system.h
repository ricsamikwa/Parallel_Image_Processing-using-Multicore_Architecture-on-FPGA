/*
 * system.h - SOPC Builder system and BSP software package information
 *
 * Machine generated for CPU 'cpu_0' in SOPC Builder design 'nios_system'
 * SOPC Builder design path: ../../../quartus/H4_/nios_system.sopcinfo
 *
 * Generated: Sat Sep 21 22:50:11 UTC 2019
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

#define ALT_CPU_ARCHITECTURE "altera_nios2_qsys"
#define ALT_CPU_BIG_ENDIAN 0
#define ALT_CPU_BREAK_ADDR 0x400820
#define ALT_CPU_CPU_FREQ 50000000u
#define ALT_CPU_CPU_ID_SIZE 1
#define ALT_CPU_CPU_ID_VALUE 0x00000000
#define ALT_CPU_CPU_IMPLEMENTATION "tiny"
#define ALT_CPU_DATA_ADDR_WIDTH 0x1c
#define ALT_CPU_DCACHE_LINE_SIZE 0
#define ALT_CPU_DCACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_DCACHE_SIZE 0
#define ALT_CPU_EXCEPTION_ADDR 0x200020
#define ALT_CPU_FLUSHDA_SUPPORTED
#define ALT_CPU_FREQ 50000000
#define ALT_CPU_HARDWARE_DIVIDE_PRESENT 0
#define ALT_CPU_HARDWARE_MULTIPLY_PRESENT 0
#define ALT_CPU_HARDWARE_MULX_PRESENT 0
#define ALT_CPU_HAS_DEBUG_CORE 1
#define ALT_CPU_HAS_DEBUG_STUB
#define ALT_CPU_HAS_JMPI_INSTRUCTION
#define ALT_CPU_ICACHE_LINE_SIZE 0
#define ALT_CPU_ICACHE_LINE_SIZE_LOG2 0
#define ALT_CPU_ICACHE_SIZE 0
#define ALT_CPU_INST_ADDR_WIDTH 0x1c
#define ALT_CPU_NAME "cpu_0"
#define ALT_CPU_RESET_ADDR 0x200000


/*
 * CPU configuration (with legacy prefix - don't use these anymore)
 *
 */

#define NIOS2_BIG_ENDIAN 0
#define NIOS2_BREAK_ADDR 0x400820
#define NIOS2_CPU_FREQ 50000000u
#define NIOS2_CPU_ID_SIZE 1
#define NIOS2_CPU_ID_VALUE 0x00000000
#define NIOS2_CPU_IMPLEMENTATION "tiny"
#define NIOS2_DATA_ADDR_WIDTH 0x1c
#define NIOS2_DCACHE_LINE_SIZE 0
#define NIOS2_DCACHE_LINE_SIZE_LOG2 0
#define NIOS2_DCACHE_SIZE 0
#define NIOS2_EXCEPTION_ADDR 0x200020
#define NIOS2_FLUSHDA_SUPPORTED
#define NIOS2_HARDWARE_DIVIDE_PRESENT 0
#define NIOS2_HARDWARE_MULTIPLY_PRESENT 0
#define NIOS2_HARDWARE_MULX_PRESENT 0
#define NIOS2_HAS_DEBUG_CORE 1
#define NIOS2_HAS_DEBUG_STUB
#define NIOS2_HAS_JMPI_INSTRUCTION
#define NIOS2_ICACHE_LINE_SIZE 0
#define NIOS2_ICACHE_LINE_SIZE_LOG2 0
#define NIOS2_ICACHE_SIZE 0
#define NIOS2_INST_ADDR_WIDTH 0x1c
#define NIOS2_RESET_ADDR 0x200000


/*
 * Custom instruction macros
 *
 */

#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0(n,A,B) __builtin_custom_inii(ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N+(n&ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK),(A),(B))
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N 0xfc
#define ALT_CI_NIOS_CUSTOM_INSTR_FLOATING_POINT_0_N_MASK ((1<<2)-1)


/*
 * Define for each module class mastered by the CPU
 *
 */

#define __ALTERA_AVALON_JTAG_UART
#define __ALTERA_AVALON_NEW_SDRAM_CONTROLLER
#define __ALTERA_AVALON_PERFORMANCE_COUNTER
#define __ALTERA_AVALON_PIO
#define __ALTERA_AVALON_SYSID_QSYS
#define __ALTERA_AVALON_TIMER
#define __ALTERA_NIOS2_QSYS
#define __ALTERA_NIOS_CUSTOM_INSTR_FLOATING_POINT
#define __ALTERA_UP_AVALON_SRAM


/*
 * System configuration
 *
 */

#define ALT_DEVICE_FAMILY "Cyclone IV E"
#define ALT_ENHANCED_INTERRUPT_API_PRESENT
#define ALT_IRQ_BASE NULL
#define ALT_LOG_PORT "/dev/null"
#define ALT_LOG_PORT_BASE 0x0
#define ALT_LOG_PORT_DEV null
#define ALT_LOG_PORT_TYPE ""
#define ALT_NUM_EXTERNAL_INTERRUPT_CONTROLLERS 0
#define ALT_NUM_INTERNAL_INTERRUPT_CONTROLLERS 1
#define ALT_NUM_INTERRUPT_CONTROLLERS 1
#define ALT_STDERR "/dev/jtag_uart_0"
#define ALT_STDERR_BASE 0x401128
#define ALT_STDERR_DEV jtag_uart_0
#define ALT_STDERR_IS_JTAG_UART
#define ALT_STDERR_PRESENT
#define ALT_STDERR_TYPE "altera_avalon_jtag_uart"
#define ALT_STDIN "/dev/jtag_uart_0"
#define ALT_STDIN_BASE 0x401128
#define ALT_STDIN_DEV jtag_uart_0
#define ALT_STDIN_IS_JTAG_UART
#define ALT_STDIN_PRESENT
#define ALT_STDIN_TYPE "altera_avalon_jtag_uart"
#define ALT_STDOUT "/dev/jtag_uart_0"
#define ALT_STDOUT_BASE 0x401128
#define ALT_STDOUT_DEV jtag_uart_0
#define ALT_STDOUT_IS_JTAG_UART
#define ALT_STDOUT_PRESENT
#define ALT_STDOUT_TYPE "altera_avalon_jtag_uart"
#define ALT_SYSTEM_NAME "nios_system"


/*
 * de2_pio_greenled9 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_greenled9 altera_avalon_pio
#define DE2_PIO_GREENLED9_BASE 0x4010e0
#define DE2_PIO_GREENLED9_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_GREENLED9_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_GREENLED9_CAPTURE 0
#define DE2_PIO_GREENLED9_DATA_WIDTH 9
#define DE2_PIO_GREENLED9_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_GREENLED9_DRIVEN_SIM_VALUE 0
#define DE2_PIO_GREENLED9_EDGE_TYPE "NONE"
#define DE2_PIO_GREENLED9_FREQ 50000000
#define DE2_PIO_GREENLED9_HAS_IN 0
#define DE2_PIO_GREENLED9_HAS_OUT 1
#define DE2_PIO_GREENLED9_HAS_TRI 0
#define DE2_PIO_GREENLED9_IRQ -1
#define DE2_PIO_GREENLED9_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_GREENLED9_IRQ_TYPE "NONE"
#define DE2_PIO_GREENLED9_NAME "/dev/de2_pio_greenled9"
#define DE2_PIO_GREENLED9_RESET_VALUE 0
#define DE2_PIO_GREENLED9_SPAN 16
#define DE2_PIO_GREENLED9_TYPE "altera_avalon_pio"


/*
 * de2_pio_hex_high28 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_hex_high28 altera_avalon_pio
#define DE2_PIO_HEX_HIGH28_BASE 0x4010d0
#define DE2_PIO_HEX_HIGH28_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_HEX_HIGH28_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_HEX_HIGH28_CAPTURE 0
#define DE2_PIO_HEX_HIGH28_DATA_WIDTH 28
#define DE2_PIO_HEX_HIGH28_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_HEX_HIGH28_DRIVEN_SIM_VALUE 0
#define DE2_PIO_HEX_HIGH28_EDGE_TYPE "NONE"
#define DE2_PIO_HEX_HIGH28_FREQ 50000000
#define DE2_PIO_HEX_HIGH28_HAS_IN 0
#define DE2_PIO_HEX_HIGH28_HAS_OUT 1
#define DE2_PIO_HEX_HIGH28_HAS_TRI 0
#define DE2_PIO_HEX_HIGH28_IRQ -1
#define DE2_PIO_HEX_HIGH28_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_HEX_HIGH28_IRQ_TYPE "NONE"
#define DE2_PIO_HEX_HIGH28_NAME "/dev/de2_pio_hex_high28"
#define DE2_PIO_HEX_HIGH28_RESET_VALUE 0
#define DE2_PIO_HEX_HIGH28_SPAN 16
#define DE2_PIO_HEX_HIGH28_TYPE "altera_avalon_pio"


/*
 * de2_pio_hex_low28 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_hex_low28 altera_avalon_pio
#define DE2_PIO_HEX_LOW28_BASE 0x4010c0
#define DE2_PIO_HEX_LOW28_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_HEX_LOW28_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_HEX_LOW28_CAPTURE 0
#define DE2_PIO_HEX_LOW28_DATA_WIDTH 28
#define DE2_PIO_HEX_LOW28_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_HEX_LOW28_DRIVEN_SIM_VALUE 0
#define DE2_PIO_HEX_LOW28_EDGE_TYPE "NONE"
#define DE2_PIO_HEX_LOW28_FREQ 50000000
#define DE2_PIO_HEX_LOW28_HAS_IN 0
#define DE2_PIO_HEX_LOW28_HAS_OUT 1
#define DE2_PIO_HEX_LOW28_HAS_TRI 0
#define DE2_PIO_HEX_LOW28_IRQ -1
#define DE2_PIO_HEX_LOW28_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_HEX_LOW28_IRQ_TYPE "NONE"
#define DE2_PIO_HEX_LOW28_NAME "/dev/de2_pio_hex_low28"
#define DE2_PIO_HEX_LOW28_RESET_VALUE 0
#define DE2_PIO_HEX_LOW28_SPAN 16
#define DE2_PIO_HEX_LOW28_TYPE "altera_avalon_pio"


/*
 * de2_pio_keys4 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_keys4 altera_avalon_pio
#define DE2_PIO_KEYS4_BASE 0x401100
#define DE2_PIO_KEYS4_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_KEYS4_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_KEYS4_CAPTURE 0
#define DE2_PIO_KEYS4_DATA_WIDTH 4
#define DE2_PIO_KEYS4_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_KEYS4_DRIVEN_SIM_VALUE 0
#define DE2_PIO_KEYS4_EDGE_TYPE "NONE"
#define DE2_PIO_KEYS4_FREQ 50000000
#define DE2_PIO_KEYS4_HAS_IN 1
#define DE2_PIO_KEYS4_HAS_OUT 0
#define DE2_PIO_KEYS4_HAS_TRI 0
#define DE2_PIO_KEYS4_IRQ -1
#define DE2_PIO_KEYS4_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_KEYS4_IRQ_TYPE "NONE"
#define DE2_PIO_KEYS4_NAME "/dev/de2_pio_keys4"
#define DE2_PIO_KEYS4_RESET_VALUE 0
#define DE2_PIO_KEYS4_SPAN 16
#define DE2_PIO_KEYS4_TYPE "altera_avalon_pio"


/*
 * de2_pio_redled18 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_redled18 altera_avalon_pio
#define DE2_PIO_REDLED18_BASE 0x4010f0
#define DE2_PIO_REDLED18_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_REDLED18_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_REDLED18_CAPTURE 0
#define DE2_PIO_REDLED18_DATA_WIDTH 18
#define DE2_PIO_REDLED18_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_REDLED18_DRIVEN_SIM_VALUE 0
#define DE2_PIO_REDLED18_EDGE_TYPE "NONE"
#define DE2_PIO_REDLED18_FREQ 50000000
#define DE2_PIO_REDLED18_HAS_IN 0
#define DE2_PIO_REDLED18_HAS_OUT 1
#define DE2_PIO_REDLED18_HAS_TRI 0
#define DE2_PIO_REDLED18_IRQ -1
#define DE2_PIO_REDLED18_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_REDLED18_IRQ_TYPE "NONE"
#define DE2_PIO_REDLED18_NAME "/dev/de2_pio_redled18"
#define DE2_PIO_REDLED18_RESET_VALUE 0
#define DE2_PIO_REDLED18_SPAN 16
#define DE2_PIO_REDLED18_TYPE "altera_avalon_pio"


/*
 * de2_pio_toggles18 configuration
 *
 */

#define ALT_MODULE_CLASS_de2_pio_toggles18 altera_avalon_pio
#define DE2_PIO_TOGGLES18_BASE 0x401110
#define DE2_PIO_TOGGLES18_BIT_CLEARING_EDGE_REGISTER 0
#define DE2_PIO_TOGGLES18_BIT_MODIFYING_OUTPUT_REGISTER 0
#define DE2_PIO_TOGGLES18_CAPTURE 1
#define DE2_PIO_TOGGLES18_DATA_WIDTH 18
#define DE2_PIO_TOGGLES18_DO_TEST_BENCH_WIRING 0
#define DE2_PIO_TOGGLES18_DRIVEN_SIM_VALUE 0
#define DE2_PIO_TOGGLES18_EDGE_TYPE "FALLING"
#define DE2_PIO_TOGGLES18_FREQ 50000000
#define DE2_PIO_TOGGLES18_HAS_IN 1
#define DE2_PIO_TOGGLES18_HAS_OUT 0
#define DE2_PIO_TOGGLES18_HAS_TRI 0
#define DE2_PIO_TOGGLES18_IRQ -1
#define DE2_PIO_TOGGLES18_IRQ_INTERRUPT_CONTROLLER_ID -1
#define DE2_PIO_TOGGLES18_IRQ_TYPE "NONE"
#define DE2_PIO_TOGGLES18_NAME "/dev/de2_pio_toggles18"
#define DE2_PIO_TOGGLES18_RESET_VALUE 0
#define DE2_PIO_TOGGLES18_SPAN 16
#define DE2_PIO_TOGGLES18_TYPE "altera_avalon_pio"


/*
 * hal configuration
 *
 */

#define ALT_MAX_FD 4
#define ALT_SYS_CLK TIMER_0_A
#define ALT_TIMESTAMP_CLK none


/*
 * ht19_Samikwa_Yaacoub configuration
 *
 */

#define ALT_MODULE_CLASS_ht19_Samikwa_Yaacoub altera_avalon_sysid_qsys
#define HT19_SAMIKWA_YAACOUB_BASE 0x401120
#define HT19_SAMIKWA_YAACOUB_ID 34566365
#define HT19_SAMIKWA_YAACOUB_IRQ -1
#define HT19_SAMIKWA_YAACOUB_IRQ_INTERRUPT_CONTROLLER_ID -1
#define HT19_SAMIKWA_YAACOUB_NAME "/dev/ht19_Samikwa_Yaacoub"
#define HT19_SAMIKWA_YAACOUB_SPAN 8
#define HT19_SAMIKWA_YAACOUB_TIMESTAMP 1569103094
#define HT19_SAMIKWA_YAACOUB_TYPE "altera_avalon_sysid_qsys"


/*
 * jtag_uart_0 configuration
 *
 */

#define ALT_MODULE_CLASS_jtag_uart_0 altera_avalon_jtag_uart
#define JTAG_UART_0_BASE 0x401128
#define JTAG_UART_0_IRQ 5
#define JTAG_UART_0_IRQ_INTERRUPT_CONTROLLER_ID 0
#define JTAG_UART_0_NAME "/dev/jtag_uart_0"
#define JTAG_UART_0_READ_DEPTH 64
#define JTAG_UART_0_READ_THRESHOLD 8
#define JTAG_UART_0_SPAN 8
#define JTAG_UART_0_TYPE "altera_avalon_jtag_uart"
#define JTAG_UART_0_WRITE_DEPTH 64
#define JTAG_UART_0_WRITE_THRESHOLD 8


/*
 * p_counter configuration
 *
 */

#define ALT_MODULE_CLASS_p_counter altera_avalon_performance_counter
#define P_COUNTER_BASE 0x401000
#define P_COUNTER_HOW_MANY_SECTIONS 7
#define P_COUNTER_IRQ -1
#define P_COUNTER_IRQ_INTERRUPT_CONTROLLER_ID -1
#define P_COUNTER_NAME "/dev/p_counter"
#define P_COUNTER_SPAN 128
#define P_COUNTER_TYPE "altera_avalon_performance_counter"


/*
 * sdram configuration
 *
 */

#define ALT_MODULE_CLASS_sdram altera_avalon_new_sdram_controller
#define SDRAM_BASE 0x8000000
#define SDRAM_CAS_LATENCY 3
#define SDRAM_CONTENTS_INFO
#define SDRAM_INIT_NOP_DELAY 0.0
#define SDRAM_INIT_REFRESH_COMMANDS 2
#define SDRAM_IRQ -1
#define SDRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SDRAM_IS_INITIALIZED 1
#define SDRAM_NAME "/dev/sdram"
#define SDRAM_POWERUP_DELAY 200.0
#define SDRAM_REFRESH_PERIOD 7.8125
#define SDRAM_REGISTER_DATA_IN 1
#define SDRAM_SDRAM_ADDR_WIDTH 0x19
#define SDRAM_SDRAM_BANK_WIDTH 2
#define SDRAM_SDRAM_COL_WIDTH 10
#define SDRAM_SDRAM_DATA_WIDTH 32
#define SDRAM_SDRAM_NUM_BANKS 4
#define SDRAM_SDRAM_NUM_CHIPSELECTS 1
#define SDRAM_SDRAM_ROW_WIDTH 13
#define SDRAM_SHARED_DATA 0
#define SDRAM_SIM_MODEL_BASE 0
#define SDRAM_SPAN 134217728
#define SDRAM_STARVATION_INDICATOR 0
#define SDRAM_TRISTATE_BRIDGE_SLAVE ""
#define SDRAM_TYPE "altera_avalon_new_sdram_controller"
#define SDRAM_T_AC 5.5
#define SDRAM_T_MRD 3
#define SDRAM_T_RCD 20.0
#define SDRAM_T_RFC 70.0
#define SDRAM_T_RP 20.0
#define SDRAM_T_WR 14.0


/*
 * sram configuration
 *
 */

#define ALT_MODULE_CLASS_sram altera_up_avalon_sram
#define SRAM_BASE 0x200000
#define SRAM_IRQ -1
#define SRAM_IRQ_INTERRUPT_CONTROLLER_ID -1
#define SRAM_NAME "/dev/sram"
#define SRAM_SPAN 2097152
#define SRAM_TYPE "altera_up_avalon_sram"


/*
 * timer_0_A configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0_A altera_avalon_timer
#define TIMER_0_A_ALWAYS_RUN 0
#define TIMER_0_A_BASE 0x4010a0
#define TIMER_0_A_COUNTER_SIZE 32
#define TIMER_0_A_FIXED_PERIOD 0
#define TIMER_0_A_FREQ 50000000
#define TIMER_0_A_IRQ 2
#define TIMER_0_A_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_A_LOAD_VALUE 49999
#define TIMER_0_A_MULT 0.0010
#define TIMER_0_A_NAME "/dev/timer_0_A"
#define TIMER_0_A_PERIOD 1
#define TIMER_0_A_PERIOD_UNITS "ms"
#define TIMER_0_A_RESET_OUTPUT 0
#define TIMER_0_A_SNAPSHOT 1
#define TIMER_0_A_SPAN 32
#define TIMER_0_A_TICKS_PER_SEC 1000.0
#define TIMER_0_A_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_A_TYPE "altera_avalon_timer"


/*
 * timer_0_B configuration
 *
 */

#define ALT_MODULE_CLASS_timer_0_B altera_avalon_timer
#define TIMER_0_B_ALWAYS_RUN 0
#define TIMER_0_B_BASE 0x401080
#define TIMER_0_B_COUNTER_SIZE 32
#define TIMER_0_B_FIXED_PERIOD 0
#define TIMER_0_B_FREQ 50000000
#define TIMER_0_B_IRQ 3
#define TIMER_0_B_IRQ_INTERRUPT_CONTROLLER_ID 0
#define TIMER_0_B_LOAD_VALUE 99999
#define TIMER_0_B_MULT 0.0010
#define TIMER_0_B_NAME "/dev/timer_0_B"
#define TIMER_0_B_PERIOD 2
#define TIMER_0_B_PERIOD_UNITS "ms"
#define TIMER_0_B_RESET_OUTPUT 0
#define TIMER_0_B_SNAPSHOT 1
#define TIMER_0_B_SPAN 32
#define TIMER_0_B_TICKS_PER_SEC 500.0
#define TIMER_0_B_TIMEOUT_PULSE_OUTPUT 0
#define TIMER_0_B_TYPE "altera_avalon_timer"

#endif /* __SYSTEM_H_ */
