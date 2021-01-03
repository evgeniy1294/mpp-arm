/*
 @file      cc26x2r1f.lds
 @brief     CC26x2R1F rev2 linker configuration file for GNU compiler.

 Revised    $Date$
 Revision   $Revision$

 This file is auto-generated.

  Copyright (C) 2017 Texas Instruments Incorporated - http:www.ti.com/


  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:

    Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

    Neither the name of Texas Instruments Incorporated nor the names of
    its contributors may be used to endorse or promote products derived
    from this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/* Entry Point */
ENTRY( ResetHandler )

/* System memory map */
MEMORY
{
    /* Application is stored in and executes from internal flash */
    FLASH (RX) : ORIGIN = 0x0, LENGTH = 0x57FA8

    /* Customer Configuration Area (CCFG) */
    FLASH_CCFG (RX) : ORIGIN = 0x57FA8, LENGTH = 88
   
   /* Application uses internal RAM for data */
    SRAM (RWX) : ORIGIN = 0x20000000, LENGTH = 0x13C00
    SRAM_DMA (RWX) : ORIGIN = 0x20013C00, LENGTH = 0x400
   
   /* Application can use GPRAM region as RAM if cache is disabled in the CCFG
      (DEFAULT_CCFG_SIZE_AND_DIS_FLAGS.SET_CCFG_SIZE_AND_DIS_FLAGS_DIS_GPRAM = 0) */
    GPRAM (RWX) : ORIGIN = 0x11000000, LENGTH = 0x2000
}

/*. Highest address of the stack. Used in startup file .*/
__initial_sp__ = ORIGIN(SRAM) + LENGTH(SRAM); /*end of SRAM .*/

/*. Generate a link error if heap and stack does not fit into RAM .*/
_Min_Heap_Size = 0x2400;
_Min_Stack_Size = 0x2400;


/* Section allocation in memory */
SECTIONS
{
    /* UDMACC26XX_CONFIG_BASE = 0x20000000; */
	
    .text :
    {
        _text = .;
        KEEP(*(.flash_vectors))
        *(.text*)
        *(.rodata*)
        *(.init)
        *(.fini*)
        *(.eh_frame*)
        _etext = .;
    } > FLASH = 0


    .init_array :
    {
        _init_array = .;
        KEEP(*(SORT(.init_array.*)))
        KEEP(*(.init_array*))
        _einit_array = .;
    } > FLASH

    .data :
    {
        _data = .;
		__data_start__ = _data;
		
        *(vtable)
        *(.data*)
		
        _edata = .;
		__data_end__ = _edata;
    } > SRAM AT > FLASH
    __data_load__ = LOADADDR(.data);

    .bss :
    {
        __bss_start__ = .;
        _bss = .;
        *(.bss*)
        *(COMMON)
        _ebss = .;
        __bss_end__ = .;
    } > SRAM
	
	
    /* .udma UDMACC26XX_CONFIG_BASE (NOLOAD) : AT (UDMACC26XX_CONFIG_BASE) {KEEP(*(.udma))} > SRAM */
	
    .udma (NOLOAD):
    {
      KEEP(*(.udma));
    } > SRAM_DMA

    .ccfg :
    {
        KEEP(*(.ccfg));
    } > FLASH_CCFG
	
	

    /* User_heap_stack section, used to check that there is enough SRAM left */
    ._user_heap_stack :
    {
      . = ALIGN(4);
      . = . + _Min_Heap_Size;
      . = . + _Min_Stack_Size;
      . = ALIGN(4);
    } > SRAM

    .heap : 
    {
        __heap_start__ = .;
        end = __heap_start__;
        _end = end;
        __end = end;
        . = . + _Min_Heap_Size;
        KEEP(*(.heap))
        __heap_end__ = .;
        __HeapLimit = __heap_end__;
    } > SRAM
	
    .gpram :
    {
    } > GPRAM
}
