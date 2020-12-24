#include "bsp.hpp"


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
    
    
    
  using tInterruptFunction = void(*)() ;
  constexpr std::array<tInterruptFunction, 87> InterruptVectorTable
  {
    /******  RISC-V Interrupt   ************/ 
    nullptr,                      // 0  RISC-V reserved
    nullptr,                      // 1  Reserved
    nullptr,                      // 2  Reserved
    DefaultHandler,               // 3  Software interrupt
    nullptr,                      // 4  Reserved
    nullptr,                      // 5  Reserved
    nullptr,                      // 6  Reserved
    bsp::Systick::Interrupt,      // 7  CPU Timer interrupt
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
    DefaultHandler,               // 19 window watchDog timer interrupt                          
    DefaultHandler,               // 20 LVD through EXTI line detect interrupt                   
    DefaultHandler,               // 21 tamper through EXTI line detect                          
    DefaultHandler,               // 22 RTC alarm interrupt                                      
    DefaultHandler,               // 23 FMC interrupt                                            
    DefaultHandler,               // 24 RCU and CTC interrupt                                    
    DefaultHandler,               // 25 EXTI line 0 interrupts                                   
    DefaultHandler,               // 26 EXTI line 1 interrupts                                   
    DefaultHandler,               // 27 EXTI line 2 interrupts                                   
    DefaultHandler,               // 28 EXTI line 3 interrupts                                   
    DefaultHandler,               // 29 EXTI line 4 interrupts                                   
    DefaultHandler,               // 30 DMA0 channel0 interrupt                                  
    DefaultHandler,               // 31 DMA0 channel1 interrupt                                  
    DefaultHandler,               // 32 DMA0 channel2 interrupt                                  
    DefaultHandler,               // 33 DMA0 channel3 interrupt                                  
    DefaultHandler,               // 34 DMA0 channel4 interrupt                                  
    DefaultHandler,               // 35 DMA0 channel5 interrupt                                  
    DefaultHandler,               // 36 DMA0 channel6 interrupt                                  
    DefaultHandler,               // 37 ADC0 and ADC1 interrupt                                  
    DefaultHandler,               // 38 CAN0 TX interrupts                                       
    DefaultHandler,               // 39 CAN0 RX0 interrupts                                      
    DefaultHandler,               // 40 CAN0 RX1 interrupts                                      
    DefaultHandler,               // 41 CAN0 EWMC interrupts                                     
    DefaultHandler,               // 42 EXTI[9:5] interrupts                                     
    DefaultHandler,               // 43 TIMER0 break interrupts                                  
    DefaultHandler,               // 44 TIMER0 update interrupts                                 
    DefaultHandler,               // 45 TIMER0 trigger and commutation interrupts                
    DefaultHandler,               // 46 TIMER0 channel capture compare interrupts                
    DefaultHandler,               // 47 TIMER1 interrupt                                         
    DefaultHandler,               // 48 TIMER2 interrupt                                         
    DefaultHandler,               // 49 TIMER3 interrupts                                        
    DefaultHandler,               // 50 I2C0 event interrupt                                     
    DefaultHandler,               // 51 I2C0 error interrupt                                     
    DefaultHandler,               // 52 I2C1 event interrupt                                     
    DefaultHandler,               // 53 I2C1 error interrupt                                     
    DefaultHandler,               // 54 SPI0 interrupt                                           
    DefaultHandler,               // 55 SPI1 interrupt                                           
    DefaultHandler,               // 56 USART0 interrupt                                         
    DefaultHandler,               // 57 USART1 interrupt                                         
    DefaultHandler,               // 58 USART2 interrupt                                         
    DefaultHandler,               // 59 EXTI[15:10] interrupts                                   
    DefaultHandler,               // 60 RTC alarm interrupt EXTI                                 
    DefaultHandler,               // 61 USBFS wakeup interrupt                                   
    nullptr,                      // 62 Reserved 
    nullptr,                      // 63 Reserved
    nullptr,                      // 64 Reserved
    nullptr,                      // 65 Reserved
    nullptr,                      // 66 Reserved
    DefaultHandler,               // 67 EXMC global interrupt                                    
    nullptr,                      // 68 Reserved
    DefaultHandler,               // 69 TIMER4 global interrupt                                  
    DefaultHandler,               // 70 SPI2 global interrupt                                    
    DefaultHandler,               // 71 UART3 global interrupt                                   
    DefaultHandler,               // 72 UART4 global interrupt                                   
    DefaultHandler,               // 73 TIMER5 global interrupt                                  
    DefaultHandler,               // 74 TIMER6 global interrupt                                  
    DefaultHandler,               // 75 DMA1 channel0 global interrupt                           
    DefaultHandler,               // 76 DMA1 channel1 global interrupt                           
    DefaultHandler,               // 77 DMA1 channel2 global interrupt                           
    DefaultHandler,               // 78 DMA1 channel3 global interrupt                           
    DefaultHandler,               // 79 DMA1 channel3 global interrupt                           
    nullptr,                      // 80 Unused
    nullptr,                      // 81 Unused
    DefaultHandler,               // 82 CAN1 TX interrupt                                        
    DefaultHandler,               // 83 CAN1 RX0 interrupt                                       
    DefaultHandler,               // 84 CAN1 RX1 interrupt                                       
    DefaultHandler,               // 85 CAN1 EWMC interrupt                                      
    DefaultHandler,               // 86 USBFS global interrupt                                   
  };

  
  
  
  constexpr std::array<tInterruptFunction, 12> ExceptionVectorTable
  {
    DefaultHandler,               // 0 Instruction address misaligned
    DefaultHandler,               // 1 Instruction access fault
    DefaultHandler,               // 2 Illegal instruction
    DefaultHandler,               // 3 Breakpoint
    DefaultHandler,               // 4 Load address misaligned
    DefaultHandler,               // 5 Load access fault
    DefaultHandler,               // 6 Store/AMO address  misaligned
    DefaultHandler,               // 7 Store/AMO access fault
    DefaultHandler,               // 8 Environment call from  U-mode
    nullptr,
    nullptr,
    DefaultHandler,               // 11 Environment call from  M-mode
  };
  
  
  
  
  
  
  [[gnu::interrupt]] void InterruptEntry() {
    clear_csr(CSR_MMISC_CTL, 3u);
    
    const auto mcause = read_csr(CSR_MCAUSE);
    const auto mepc   = read_csr(CSR_MEPC);
    const auto msubm  = read_csr(CSR_MSUBM);
    
    set_csr(CSR_MMISC_CTL, 3u);
  
    const auto exceptionCode =  mcause & 0xFFF ; 
    
    if (exceptionCode < InterruptVectorTable.size());
    {
      tInterruptFunction fp = InterruptVectorTable[exceptionCode];
      if (fp != nullptr)
      {
        fp(); // вызываем обработчик
      }
    }
    
    clear_csr(CSR_MMISC_CTL, 3u);
    
    write_csr(CSR_MCAUSE, mcause);
    write_csr(CSR_MEPC, mepc);
    write_csr(CSR_MSUBM, msubm);
    
    set_csr(CSR_MMISC_CTL, 3u);
    
    return;
  }
   
  
  
  
  
  
  
  [[gnu::interrupt]] void ExceptionEntry()
  {
    clear_csr(CSR_MMISC_CTL, 3u);
    
    const auto mcause = read_csr(CSR_MCAUSE);
    const auto mepc   = read_csr(CSR_MEPC);
    const auto msubm  = read_csr(CSR_MSUBM);
    
    set_csr(CSR_MMISC_CTL, 3u);

    const auto exceptionCode =  mcause & 0xFFF ;
    
    if (exceptionCode != 0xFFF) {
      if (exceptionCode < ExceptionVectorTable.size()) 
      {
        tInterruptFunction fp = ExceptionVectorTable[exceptionCode];
        if (fp != nullptr)
        {
          fp();
        }
      }
    } 
    else {
      DefaultHandler() ;
    }

    clear_csr(CSR_MMISC_CTL, 3u);
    
    write_csr(CSR_MCAUSE, mcause);
    write_csr(CSR_MEPC, mepc);
    write_csr(CSR_MSUBM, msubm);
    
    set_csr(CSR_MMISC_CTL, 3u);
    
    return;
  }
  
  
  
  
  
  
  
  [[noreturn]] void ResetHandler() {
    
    /* Устанавливаем указание адреса обработчика NMI через общий обработчик, 
       адрес которого указан в mtvec. Номер обработчика NMI будет 0xFFF */
    set_csr(CSR_MMISC_CTL, 9u /* CSR_MMISC_CTL_NMI_CAUSE_FFF */);

    /* Настраиваем адрес единого обработчика прерываний. 
       Указываем, что он будет находится в регистре MTVT2 */
    write_csr(CSR_MTVT2, reinterpret_cast<std::uintptr_t>(&InterruptEntry));
    set_csr(CSR_MMISC_CTL, 0u /* CSR_MMISC_CTL_NMI_CAUSE_FFF */);
    
    /* Переключаемся на режим работы с ECLIC и устанавливаем 
       адрес единого обработчика исключений */
    write_csr( CSR_MTVEC, 0b000011u | (reinterpret_cast<std::uintptr_t>(&ExceptionEntry) & 0xffff'ffc0) );
    
    // Включаем машинный таймер и счетчик команд
    clear_csr(CSR_MCOUNTINHIBIT, 2 /* CSR_MCOUNTINHIBIT_IR */);
    
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

    bsp::Init();
    
    //  Call static constructors
    __libc_init_array();
    
    main();

    while(1) __NOP();
  }
  
  
} //  extern "C"




