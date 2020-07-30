﻿/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F401_gpio_v1_0.hpp
  @brief  This is autogenerated file        
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F401xc)
  #include "stm32f401xc.h"
#elif defined (STM32F401xe)
  #include "stm32f401xe.h"
#else
  #error "You must define supported target"
#endif


namespace mpp::gpio
{
  inline namespace STM32F401_gpio_v1_0
  {
    enum class Port { 
      A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      H = GPIOH_BASE,
    };

    constexpr bool IsValidPinId(Port port, std::uint32_t pin)
    {
      switch(port)
      { 
        case Port::A: return pin < 16u;
        case Port::B: return pin < 16u;
        case Port::C: return pin < 16u;
        case Port::D: return pin < 16u;
        case Port::E: return pin < 16u;
        case Port::H: return pin < 2u;

        default: return false;
      }
    }

    namespace Af 
    { 
      namespace PA0  { enum { TIM2_CH1 = 1ul,  TIM2_ETR = 1ul,  TIM5_CH1 = 2ul,  USART2_CTS = 7ul, }; }
      namespace PA1  { enum { TIM2_CH2 = 1ul,  TIM5_CH2 = 2ul,  USART2_RTS = 7ul, }; }
      namespace PA10 { enum { TIM1_CH3 = 1ul,  USART1_RX = 7ul,  USB_OTG_FS_ID = 10ul, }; }
      namespace PA11 { enum { TIM1_CH4 = 1ul,  USART1_CTS = 7ul,  USART6_TX = 8ul,  USB_OTG_FS_DM = 10ul, }; }
      namespace PA12 { enum { TIM1_ETR = 1ul,  USART1_RTS = 7ul,  USART6_RX = 8ul,  USB_OTG_FS_DP = 10ul, }; }
      namespace PA13 { enum { SYS_JTMS_SWDIO = 0ul, }; }
      namespace PA14 { enum { I2S3ext_WS = 5ul,  SYS_JTCK_SWCLK = 0ul, }; }
      namespace PA15 { enum { I2S3_WS = 6ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  SYS_JTDI = 0ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul, }; }
      namespace PA2  { enum { TIM2_CH3 = 1ul,  TIM5_CH3 = 2ul,  TIM9_CH1 = 3ul,  USART2_TX = 7ul, }; }
      namespace PA3  { enum { TIM2_CH4 = 1ul,  TIM5_CH4 = 2ul,  TIM9_CH2 = 3ul,  USART2_RX = 7ul, }; }
      namespace PA4  { enum { I2S3_WS = 6ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  USART2_CK = 7ul, }; }
      namespace PA5  { enum { SPI1_SCK = 5ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul, }; }
      namespace PA6  { enum { SPI1_MISO = 5ul,  TIM1_BKIN = 1ul,  TIM3_CH1 = 2ul, }; }
      namespace PA7  { enum { SPI1_MOSI = 5ul,  TIM1_CH1N = 1ul,  TIM3_CH2 = 2ul, }; }
      namespace PA8  { enum { I2C3_SCL = 4ul,  RCC_MCO_1 = 0ul,  TIM1_CH1 = 1ul,  USART1_CK = 7ul,  USB_OTG_FS_SOF = 10ul, }; }
      namespace PA9  { enum { I2C3_SMBA = 4ul,  TIM1_CH2 = 1ul,  USART1_TX = 7ul, }; }
      namespace PB0  { enum { TIM1_CH2N = 1ul,  TIM3_CH3 = 2ul, }; }
      namespace PB1  { enum { TIM1_CH3N = 1ul,  TIM3_CH4 = 2ul, }; }
      namespace PB10 { enum { I2C2_SCL = 4ul,  I2S2_CK = 5ul,  SPI2_SCK = 5ul,  TIM2_CH3 = 1ul, }; }
      namespace PB11 { enum { I2C2_SDA = 4ul,  TIM2_CH4 = 1ul, }; }
      namespace PB12 { enum { I2C2_SMBA = 4ul,  I2S2_WS = 5ul,  I2S2ext_WS = 6ul,  SPI2_NSS = 5ul,  TIM1_BKIN = 1ul, }; }
      namespace PB13 { enum { I2S2_CK = 5ul,  I2S2ext_CK = 6ul,  SPI2_SCK = 5ul,  TIM1_CH1N = 1ul, }; }
      namespace PB14 { enum { I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  TIM1_CH2N = 1ul, }; }
      namespace PB15 { enum { I2S2_SD = 5ul,  I2S2ext_MISO = 6ul,  RTC_REFIN = 0ul,  SPI2_MOSI = 5ul,  TIM1_CH3N = 1ul, }; }
      namespace PB2  { enum {}; }
      namespace PB3  { enum { I2C2_SDA = 9ul,  I2S3_CK = 6ul,  SPI1_SCK = 5ul,  SPI3_SCK = 6ul,  SYS_JTDO_SWO = 0ul,  TIM2_CH2 = 1ul, }; }
      namespace PB4  { enum { I2C3_SDA = 9ul,  I2S3_ext_SD = 7ul,  SPI1_MISO = 5ul,  SPI3_MISO = 6ul,  SYS_JTRST = 0ul,  TIM3_CH1 = 2ul, }; }
      namespace PB5  { enum { I2C1_SMBA = 4ul,  I2S3_SD = 6ul,  SPI1_MOSI = 5ul,  SPI3_MOSI = 6ul,  TIM3_CH2 = 2ul, }; }
      namespace PB6  { enum { I2C1_SCL = 4ul,  TIM4_CH1 = 2ul,  USART1_TX = 7ul, }; }
      namespace PB7  { enum { I2C1_SDA = 4ul,  TIM4_CH2 = 2ul,  USART1_RX = 7ul, }; }
      namespace PB8  { enum { I2C1_SCL = 4ul,  SDIO_D4 = 12ul,  TIM10_CH1 = 3ul,  TIM4_CH3 = 2ul, }; }
      namespace PB9  { enum { I2C1_SDA = 4ul,  I2S2_WS = 5ul,  SDIO_D5 = 12ul,  SPI2_NSS = 5ul,  TIM11_CH1 = 3ul,  TIM4_CH4 = 2ul, }; }
      namespace PC0  { enum {}; }
      namespace PC1  { enum {}; }
      namespace PC10 { enum { I2S3_CK = 6ul,  I2S3ext_CK = 5ul,  SDIO_D2 = 12ul,  SPI3_SCK = 6ul, }; }
      namespace PC11 { enum { I2S3_ext_SD = 5ul,  SDIO_D3 = 12ul,  SPI3_MISO = 6ul, }; }
      namespace PC12 { enum { I2S3_SD = 6ul,  I2S3ext_MISO = 5ul,  SDIO_CK = 12ul,  SPI3_MOSI = 6ul, }; }
      namespace PC13 { enum {}; }
      namespace PC14 { enum {}; }
      namespace PC15 { enum {}; }
      namespace PC2  { enum { I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul, }; }
      namespace PC3  { enum { I2S2_SD = 5ul,  SPI2_MOSI = 5ul, }; }
      namespace PC4  { enum {}; }
      namespace PC5  { enum {}; }
      namespace PC6  { enum { I2S2_MCK = 5ul,  SDIO_D6 = 12ul,  TIM3_CH1 = 2ul,  USART6_TX = 8ul, }; }
      namespace PC7  { enum { I2S3_MCK = 6ul,  SDIO_D7 = 12ul,  TIM3_CH2 = 2ul,  USART6_RX = 8ul, }; }
      namespace PC8  { enum { SDIO_D0 = 12ul,  TIM3_CH3 = 2ul,  USART6_CK = 8ul, }; }
      namespace PC9  { enum { I2C3_SDA = 4ul,  I2S_CKIN = 5ul,  RCC_MCO_2 = 0ul,  SDIO_D1 = 12ul,  TIM3_CH4 = 2ul, }; }
      namespace PD0  { enum {}; }
      namespace PD1  { enum {}; }
      namespace PD10 { enum {}; }
      namespace PD11 { enum {}; }
      namespace PD12 { enum { TIM4_CH1 = 2ul, }; }
      namespace PD13 { enum { TIM4_CH2 = 2ul, }; }
      namespace PD14 { enum { TIM4_CH3 = 2ul, }; }
      namespace PD15 { enum { TIM4_CH4 = 2ul, }; }
      namespace PD2  { enum { SDIO_CMD = 12ul,  TIM3_ETR = 2ul, }; }
      namespace PD3  { enum { I2S2_CK = 5ul,  SPI2_SCK = 5ul,  USART2_CTS = 7ul, }; }
      namespace PD4  { enum { USART2_RTS = 7ul, }; }
      namespace PD5  { enum { USART2_TX = 7ul, }; }
      namespace PD6  { enum { I2S3_SD = 5ul,  SPI3_MOSI = 5ul,  USART2_RX = 7ul, }; }
      namespace PD7  { enum { USART2_CK = 7ul, }; }
      namespace PD8  { enum {}; }
      namespace PD9  { enum {}; }
      namespace PE0  { enum { TIM4_ETR = 2ul, }; }
      namespace PE1  { enum {}; }
      namespace PE10 { enum { TIM1_CH2N = 1ul, }; }
      namespace PE11 { enum { SPI4_NSS = 5ul,  TIM1_CH2 = 1ul, }; }
      namespace PE12 { enum { SPI4_SCK = 5ul,  TIM1_CH3N = 1ul, }; }
      namespace PE13 { enum { SPI4_MISO = 5ul,  TIM1_CH3 = 1ul, }; }
      namespace PE14 { enum { SPI4_MOSI = 5ul,  TIM1_CH4 = 1ul, }; }
      namespace PE15 { enum { TIM1_BKIN = 1ul, }; }
      namespace PE2  { enum { SPI4_SCK = 5ul,  SYS_TRACECLK = 0ul, }; }
      namespace PE3  { enum { SYS_TRACED0 = 0ul, }; }
      namespace PE4  { enum { SPI4_NSS = 5ul,  SYS_TRACED1 = 0ul, }; }
      namespace PE5  { enum { SPI4_MISO = 5ul,  SYS_TRACED2 = 0ul,  TIM9_CH1 = 3ul, }; }
      namespace PE6  { enum { SPI4_MOSI = 5ul,  SYS_TRACED3 = 0ul,  TIM9_CH2 = 3ul, }; }
      namespace PE7  { enum { TIM1_ETR = 1ul, }; }
      namespace PE8  { enum { TIM1_CH1N = 1ul, }; }
      namespace PE9  { enum { TIM1_CH1 = 1ul, }; }
      namespace PH0  { enum {}; }
      namespace PH1  { enum {}; }
    } // namespace Af
  } // inline namespace
} // namespace mpp::gpio 
 
