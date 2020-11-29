#include "board.hpp"


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
    
    
    
  [[noreturn]] void ResetHandler() {
    __set_MSP(reinterpret_cast<std::uint32_t>(&__initial_sp__));

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
      *bs = 0;
      bs++;
    }       

    board::Init();
    
    //  Call static constructors
    __libc_init_array();
    
    main();

    while(1) __NOP();
  }
    
    
    
  
    
    
  __attribute__ ((section(".isr_flash"), used)) 
  void (* const InterruptTable[])(void) =
  {
    /*  0 The initial stack pointer */
    reinterpret_cast< void(*)() >(&__initial_sp__),      
     
    /******  Cortex Interrupt   ************/ 
    ResetHandler,                 // 1 The reset handler
    DefaultHandler,               // 2 The NMI handler
    DefaultHandler,               // 3 The hard fault handler
    nullptr,                      // 4 Memory Management (MemManage) Fault
    nullptr,                      // 5 The bus fault handler
    nullptr,                      // 6 The usage fault handler
    nullptr,                      // 7 Reserved
    nullptr,                      // 8 Reserved
    nullptr,                      // 9 Reserved
    nullptr,                      // 10 Reserved
    DefaultHandler,               // 11 Supervisor Call (SVCall)
    nullptr,                      // 12 Debug monitor handler
    nullptr,                      // 13 Reserved
    DefaultHandler,               // 14 The PendSV handler
    board::Systick::Interrupt,    // 15 The SysTick handler

    /******  STM32  specific Interrupt  ************/
    DefaultHandler,               // 16 Window WatchDog Interrupt                                         
    DefaultHandler,               // 17 PVD through EXTI Line detection Interrupt(EXTI line 16)           
    DefaultHandler,               // 18 RTC interrupt through the EXTI line 19 & 21                       
    DefaultHandler,               // 19 FLASH global Interrupt                                          
    DefaultHandler,               // 20 RCC global Interrupt                                              
    DefaultHandler,               // 21 EXTI 0 and 1 Interrupts                                           
    DefaultHandler,               // 22 EXTI Line 2 and 3 Interrupts                                      
    DefaultHandler,               // 23 EXTI Line 4 to 15 Interrupts                                      
    DefaultHandler,               // 24 UCPD1 and UCPD2 global Interrupt                                  
    DefaultHandler,               // 25 DMA1 Channel 1 Interrupt                                          
    DefaultHandler,               // 26 DMA1 Channel 2 and Channel 3 Interrupts                           
    DefaultHandler,               // 27 DMA1 Channel 4 to Channel 7 and DMAMUX1 Overrun Interrupts        
    DefaultHandler,               // 28 ADC1, COMP1 and COMP2 Interrupts (combined with EXTI 17 & 18)     
    DefaultHandler,               // 29 TIM1 Break, Update, Trigger and Commutation Interrupts            
    DefaultHandler,               // 30 TIM1 Capture Compare Interrupt                                    
    DefaultHandler,               // 31 TIM2 Interrupt                                                    
    DefaultHandler,               // 32 TIM3 global Interrupt                                             
    DefaultHandler,               // 33 TIM6, DAC and LPTIM1 global Interrupts                            
    DefaultHandler,               // 34 TIM7 and LPTIM2 global Interrupt                                  
    DefaultHandler,               // 35 TIM14 global Interrupt                                            
    DefaultHandler,               // 36 TIM15 global Interrupt                                            
    DefaultHandler,               // 37 TIM16 global Interrupt                                            
    DefaultHandler,               // 38 TIM17 global Interrupt                                            
    DefaultHandler,               // 39 I2C1 Interrupt  (combined with EXTI 23)                           
    DefaultHandler,               // 40 I2C2 Interrupt                                                    
    DefaultHandler,               // 41 SPI1/I2S1 Interrupt                                               
    DefaultHandler,               // 42 SPI2 Interrupt                                                    
    DefaultHandler,               // 43 USART1 Interrupt                                                  
    DefaultHandler,               // 44 USART2 Interrupt                                                  
    DefaultHandler,               // 45 USART3, USART4 and LPUART1 globlal Interrupts (combined with EXTI 28)
    DefaultHandler,               // 46 CEC Interrupt(combined with EXTI 27)                               
  };
      
} //  extern "C"




