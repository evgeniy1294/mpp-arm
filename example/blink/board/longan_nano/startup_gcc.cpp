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
    nullptr,                      // 0  RISC-V reserved
    nullptr,                      // 1  Reserved
    nullptr,                      // 2  Reserved
    DefaultHandler,               // 3  Software interrupt
    nullptr,                      // 4  Reserved
    nullptr,                      // 5  Reserved
    nullptr,                      // 6  Reserved
    board::Systick::Interrupt,    // 7  CPU Timer interrupt
    nullptr,                      // 8  Reserved
    nullptr,                      // 9  Reserved
    nullptr,                      // 10 Reserved
    nullptr,                      // 11 Reserved
    nullptr,                      // 12 Reserved
    nullptr,                      // 13 Reserved
    nullptr,                      // 14 Reserved
    nullptr,                      // 15 Reserved
    nullptr,                      // 16 Reserved
    DefaultHandler,               // 17 Bus Error interrupt
    DefaultHandler,               // 18 Performance Monitor
    

    /******  GD32VF103  specific Interrupt  ************/
    WWDGT_IRQn,                   // 19 window watchDog timer interrupt                          
    LVD_IRQn,                     // 20 LVD through EXTI line detect interrupt                   
    TAMPER_IRQn,                  // 21 tamper through EXTI line detect                          
    RTC_IRQn,                     // 22 RTC alarm interrupt                                      
    FMC_IRQn,                     // 23 FMC interrupt                                            
    RCU_CTC_IRQn,                 // 24 RCU and CTC interrupt                                    
    EXTI0_IRQn,                   // 25 EXTI line 0 interrupts                                   
    EXTI1_IRQn,                   // 26 EXTI line 1 interrupts                                   
    EXTI2_IRQn,                   // 27 EXTI line 2 interrupts                                   
    EXTI3_IRQn,                   // 28 EXTI line 3 interrupts                                   
    EXTI4_IRQn,                   // 29 EXTI line 4 interrupts                                   
    DMA0_Channel0_IRQn,           // 30 DMA0 channel0 interrupt                                  
    DMA0_Channel1_IRQn,           // 31 DMA0 channel1 interrupt                                  
    DMA0_Channel2_IRQn,           // 32 DMA0 channel2 interrupt                                  
    DMA0_Channel3_IRQn,           // 33 DMA0 channel3 interrupt                                  
    DMA0_Channel4_IRQn,           // 34 DMA0 channel4 interrupt                                  
    DMA0_Channel5_IRQn,           // 35 DMA0 channel5 interrupt                                  
    DMA0_Channel6_IRQn,           // 36 DMA0 channel6 interrupt                                  
    ADC0_1_IRQn,                  // 37 ADC0 and ADC1 interrupt                                  
    CAN0_TX_IRQn,                 // 38 CAN0 TX interrupts                                       
    CAN0_RX0_IRQn,                // 39 CAN0 RX0 interrupts                                      
    CAN0_RX1_IRQn,                // 40 CAN0 RX1 interrupts                                      
    CAN0_EWMC_IRQn,               // 41 CAN0 EWMC interrupts                                     
    EXTI5_9_IRQn,                 // 42 EXTI[9:5] interrupts                                     
    TIMER0_BRK_IRQn,              // 43 TIMER0 break interrupts                                  
    TIMER0_UP_IRQn,               // 44 TIMER0 update interrupts                                 
    TIMER0_TRG_CMT_IRQn,          // 45 TIMER0 trigger and commutation interrupts                
    TIMER0_Channel_IRQn,          // 46 TIMER0 channel capture compare interrupts                
    TIMER1_IRQn,                  // 47 TIMER1 interrupt                                         
    TIMER2_IRQn,                  // 48 TIMER2 interrupt                                         
    TIMER3_IRQn,                  // 49 TIMER3 interrupts                                        
    I2C0_EV_IRQn,                 // 50 I2C0 event interrupt                                     
    I2C0_ER_IRQn,                 // 51 I2C0 error interrupt                                     
    I2C1_EV_IRQn,                 // 52 I2C1 event interrupt                                     
    I2C1_ER_IRQn,                 // 53 I2C1 error interrupt                                     
    SPI0_IRQn,                    // 54 SPI0 interrupt                                           
    SPI1_IRQn,                    // 55 SPI1 interrupt                                           
    USART0_IRQn,                  // 56 USART0 interrupt                                         
    USART1_IRQn,                  // 57 USART1 interrupt                                         
    USART2_IRQn,                  // 58 USART2 interrupt                                         
    EXTI10_15_IRQn,               // 59 EXTI[15:10] interrupts                                   
    RTC_ALARM_IRQn,               // 60 RTC alarm interrupt EXTI                                 
    USBFS_WKUP_IRQn,              // 61 USBFS wakeup interrupt                                   
    nullptr,                      // 62 Reserved 
    nullptr,                      // 63 Reserved
    nullptr,                      // 64 Reserved
    nullptr,                      // 65 Reserved
    nullptr,                      // 66 Reserved
    EXMC_IRQn,                    // 67 EXMC global interrupt                                    
    nullptr,                      // 68 Reserved
    TIMER4_IRQn,                  // 69 TIMER4 global interrupt                                  
    SPI2_IRQn,                    // 70 SPI2 global interrupt                                    
    UART3_IRQn,                   // 71 UART3 global interrupt                                   
    UART4_IRQn,                   // 72 UART4 global interrupt                                   
    TIMER5_IRQn,                  // 73 TIMER5 global interrupt                                  
    TIMER6_IRQn,                  // 74 TIMER6 global interrupt                                  
    DMA1_Channel0_IRQn,           // 75 DMA1 channel0 global interrupt                           
    DMA1_Channel1_IRQn,           // 76 DMA1 channel1 global interrupt                           
    DMA1_Channel2_IRQn,           // 77 DMA1 channel2 global interrupt                           
    DMA1_Channel3_IRQn,           // 78 DMA1 channel3 global interrupt                           
    DMA1_Channel4_IRQn,           // 79 DMA1 channel3 global interrupt                           
    nullptr,                      // 80 Unused
    nullptr,                      // 81 Unused
    CAN1_TX_IRQn,                 // 82 CAN1 TX interrupt                                        
    CAN1_RX0_IRQn,                // 83 CAN1 RX0 interrupt                                       
    CAN1_RX1_IRQn,                // 84 CAN1 RX1 interrupt                                       
    CAN1_EWMC_IRQn,               // 85 CAN1 EWMC interrupt                                      
    USBFS_IRQn,                   // 86 USBFS global interrupt                                   
  };
      
} //  extern "C"




