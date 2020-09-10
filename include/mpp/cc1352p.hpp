/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /include/mpp/cc1352p.hpp
  @brief  Main header file for cc1352 mcu 
  ***********************************************************
**/

#pragma once

//___________________DEFINITION___________________//
#define CC1352P                   (1ul)



//________________CMSIS COMPABILITY_______________//
#define __CM4_REV                 0x0001  // Cortex-M4 revision r0p1                       
#define __MPU_PRESENT             0       // CM4 provides an MPU                           
#define __NVIC_PRIO_BITS          3       // CM4 uses 4 Bits for the Priority Levels       
#define __Vendor_SysTickConfig    0       // Set to 1 if different SysTick Config is used  
#define __FPU_PRESENT             0       // FPU present
 


typedef enum IRQn
{
  // Cortex-M Processor Exceptions Numbers 
  NonMaskableInt_IRQn         = -14,   // 2 Non Maskable Interrupt                                             
  MemoryManagement_IRQn       = -12,   // 4 Cortex-M Memory Management Interrupt                               
  BusFault_IRQn               = -11,   // 5 Cortex-M Bus Fault Interrupt                                       
  UsageFault_IRQn             = -10,   // 6 Cortex-M Usage Fault Interrupt                                     
  SVCall_IRQn                 = -5,    // 11 Cortex-M SV Call Interrupt                                        
  DebugMonitor_IRQn           = -4,    // 12 Cortex-M Debug Monitor Interrupt                                  
  PendSV_IRQn                 = -2,    // 14 Cortex-M Pend SV Interrupt                                        
  SysTick_IRQn                = -1,    // 15 Cortex-M System Tick Interrupt                                    

  //  Device specific Interrupt Numbers 
  AON_GPIO_EDGE_IRQn          = 0,     // Edge detect event from IOC                                           
  I2C_IRQn                    = 1,     // Interrupt event from I2C                                             
  RFC_CPE_1_IRQn              = 2,     // Combined Interrupt for CPE (Generated events)                        
  PKA_IRQn                    = 3,     // PKA Interrupt event                                                  
  AON_RTC_COMB_IRQn           = 4,     // Event from AON_RTC                                                   
  UART0_COMB_IRQn             = 5,     // UART0 combined interrupt                                             
  AUX_SWEV0_IRQn              = 6,     // AUX software event 0                                                 
  SSI0_COMB_IRQn              = 7,     // SSI0 combined interrupt                                              
  SSI1_COMB_IRQn              = 8,     // SSI1 combined interrupt                                              
  RFC_CPE_0_IRQn              = 9,     // Combined Interrupt for CPE (Generated events)                        
  RFC_HW_COMB_IRQn            = 10,    // Combined RFC hardware interrupt                                      
  RFC_CMD_ACK_IRQn            = 11,    // RFC Doorbell Command Acknowledgement Interrupt                       
  I2S_IRQn                    = 12,    // Interrupt event from I2S                                             
  AUX_SWEV1_IRQn              = 13,    // AUX software event 1                                                 
  WDT_IRQn                    = 14,    // Watchdog interrupt event                                             
  GPT0A_IRQn                  = 15,    // GPT0A interrupt event                                                
  GPT0B_IRQn                  = 16,    // GPT0B interrupt event                                                
  GPT1A_IRQn                  = 17,    // GPT1A interrupt event                                                
  GPT1B_IRQn                  = 18,    // GPT1B interrupt event                                                
  GPT2A_IRQn                  = 19,    // GPT2A interrupt event                                                
  GPT2B_IRQn                  = 20,    // GPT2B interrupt event                                                
  GPT3A_IRQn                  = 21,    // GPT3A interrupt event                                                
  GPT3B_IRQn                  = 22,    // GPT3B interrupt event                                                
  CRYPTO_RESULT_AVAIL_IRQn    = 23,    // CRYPTO result available interupt event                               
  DMA_DONE_COMB_IRQn          = 24,    // Combined DMA done                                                    
  DMA_ERR_IRQn                = 25,    // DMA bus error                                                        
  FLASH_IRQn                  = 26,    // FLASH controller error event                                         
  SWEV0_IRQn                  = 27,    // Software event 0                                                     
  AUX_COMB_IRQn               = 28,    // AUX combined event                                                   
  AON_PROG0_IRQn              = 29,    // AON programmable event 0                                             
  PROG0_IRQn                  = 30,    // Programmable Interrupt 0                                             
  AUX_COMPA_IRQn              = 31,    // AUX Compare A event                                                  
  AUX_ADC_IRQn                = 32,    // AUX ADC interrupt event                                              
  TRNG_IRQn                   = 33,    // TRNG Interrupt event                                                 
  OSC_COMB_IRQn               = 34,    // Combined event from Oscillator control                               
  AUX_TIMER2_EV0_IRQn         = 35,    // AUX Timer2 event 0                                                   
  UART1_COMB_IRQn             = 36,    // UART1 combined interrupt                                             
  BATMON_COMB_IRQn            = 37,    // Combined event from battery monitor                                  

  MAX_IRQ_n
} IRQn_Type;







//____________________INCLUDE_____________________//
#include "cmsis_gcc.h"
#include "core_cm4.h"
#include "../../src/utils.hpp"
#include "../../src/core/cortex_m.hpp"
#include "../../src/gpio/ti/cc26x2_gpio.hpp"

 
