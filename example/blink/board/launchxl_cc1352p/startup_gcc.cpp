#include "board.hpp"
#include "setup.h"

extern "C" {
	
  extern void __libc_init_array();
    
  /* The following are constructs created by the linker, indicating where the
    the "data"  and "bss" segments reside in memory */
  extern std::uint32_t __data_start__, __data_end__, __data_load__;
  extern std::uint32_t __bss_start__, __bss_end__;
  extern std::uint32_t __initial_sp__; 

    
    
  [[noreturn]] void DefaultHandler() {
    while(1) __NOP();
  }
	
	
  
  [[noreturn]] void ResetHandler()
  {
    __set_MSP(reinterpret_cast<std::uint32_t>(&__initial_sp__));
    SetupTrimDevice();

    //  Relocate the .data section 
    std::uint32_t*  dl = & __data_load__;
    std::uint32_t*  ds = & __data_start__;
    std::uint32_t*  de = & __data_end__;
    if (dl != ds) {
      while(ds < de) {
        *ds = *dl;
        dl++;
        ds++;
      }
    }


    //  Initiailize .bss to zero
    std::uint32_t*  bs = & __bss_start__;
    std::uint32_t*  be = & __bss_end__;
    while (bs < be) {
      *bs =   0;
      bs++;
    }       

    board::Init();
    
    //  Call static constructors
    __libc_init_array();
    
    main();

    while(1) __NOP();
  }
	
	
	
	
	
	
  __attribute__ ((section(".flash_vectors"), used)) 
  void (* const InterruptTable[])(void) =
  {
    /* 0 The initial stack pointer */
    reinterpret_cast< void(*)() >(&__initial_sp__),         
     
    /******  Cortex Interrupt  ************/ 
    ResetHandler,                              //  1 The reset handler
    DefaultHandler,                            //  2 The NMI handler
    DefaultHandler,                            //  3 The hard fault handler
    DefaultHandler,                            //  4 Memory Management (MemManage) Fault
    DefaultHandler,                            //  5 The bus fault handler
    DefaultHandler,                            //  6 The usage fault handler
    0,                                         //  7 Reserved
    0,                                         //  8 Reserved
    0,                                         //  9 Reserved
    0,                                         // 10 Reserved
    DefaultHandler,                            // 11 Supervisor Call (SVCall)
    DefaultHandler,                            // 12 Debug monitor handler
    0,                                         // 13 Reserved
    DefaultHandler,                            // 14 The PendSV handler
    board::Systick::Interrupt,                 // 15 The SysTick handler
	  
	/******  STM32 specific Interrupt  ************/
	DefaultHandler,                            // 16 AON edge detect
    DefaultHandler,                            // 17 I2C
    DefaultHandler,                            // 18 RF Core Command & Packet Engine 1
    DefaultHandler,                            // 19 PKA Interrupt event
    DefaultHandler,                            // 20 AON RTC
    DefaultHandler,                            // 21 UART0 Rx and Tx
    DefaultHandler,                            // 22 AUX software event 0
    DefaultHandler,                            // 23 SSI0 Rx and Tx
    DefaultHandler,                            // 24 SSI1 Rx and Tx
    DefaultHandler,                            // 25 RF Core Command & Packet Engine 0
    DefaultHandler,                            // 26 RF Core Hardware
    DefaultHandler,                            // 27 RF Core Command Acknowledge
    DefaultHandler,                            // 28 I2S
    DefaultHandler,                            // 29 AUX software event 1
    DefaultHandler,                            // 30 Watchdog timer
    DefaultHandler,                            // 31 Timer 0 subtimer A
    DefaultHandler,                            // 32 Timer 0 subtimer B
    DefaultHandler,                            // 33 Timer 1 subtimer A
    DefaultHandler,                            // 34 Timer 1 subtimer B
    DefaultHandler,                            // 35 Timer 2 subtimer A
    DefaultHandler,                            // 36 Timer 2 subtimer B
    DefaultHandler,                            // 37 Timer 3 subtimer A
    DefaultHandler,                            // 38 Timer 3 subtimer B
    DefaultHandler,                            // 39 Crypto Core Result available
    DefaultHandler,                            // 40 uDMA Software
    DefaultHandler,                            // 41 uDMA Error
    DefaultHandler,                            // 42 Flash controller
    DefaultHandler,                            // 43 Software Event 0
    DefaultHandler,                            // 44 AUX combined event
    DefaultHandler,                            // 45 AON programmable 0
    DefaultHandler,                            // 46 Dynamic Programmable interrupt source (Default: PRCM)
    DefaultHandler,                            // 47 AUX Comparator A
    DefaultHandler,                            // 48 AUX ADC new sample or ADC DMA done, ADC underflow, ADC overflow
    DefaultHandler,                            // 49 TRNG event
    DefaultHandler,                            // 50 Combined event from Oscillator control
    DefaultHandler,                            // 51 AUX Timer2 event 0
    DefaultHandler,                            // 52 UART1 combined interrupt
    DefaultHandler                             // 53 Combined event from battery monitor  
  };
  
} // extern "C"


