﻿/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F427_gpio_v1_0.hpp
  @brief  This is autogenerated file        
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F427xx)
  #include "stm32f427xx.h"
#elif defined (STM32F429xx)
  #include "stm32f429xx.h"
#elif defined (STM32F437xx)
  #include "stm32f437xx.h"
#elif defined (STM32F439xx)
  #include "stm32f439xx.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace STM32F427_gpio_v1_0
  {
    enum class Port { 
      A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      F = GPIOF_BASE,
      G = GPIOG_BASE,
      H = GPIOH_BASE,
      I = GPIOI_BASE,
      J = GPIOJ_BASE,
      K = GPIOK_BASE,
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
        case Port::F: return pin < 16u;
        case Port::G: return pin < 16u;
        case Port::H: return pin < 16u;
        case Port::I: return pin < 16u;
        case Port::J: return pin < 16u;
        case Port::K: return pin < 8u;

        default: return false;
      }
    }

    namespace Af 
    { 
      namespace PA0  { enum { ETH_CRS = 11ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul,  TIM5_CH1 = 2ul,  TIM8_ETR = 3ul,  UART4_TX = 8ul,  USART2_CTS = 7ul, }; }
      namespace PA1  { enum { ETH_REF_CLK = 11ul,  ETH_RX_CLK = 11ul,  TIM2_CH2 = 1ul,  TIM5_CH2 = 2ul,  UART4_RX = 8ul,  USART2_RTS = 7ul, }; }
      namespace PA10 { enum { DCMI_D1 = 13ul,  TIM1_CH3 = 1ul,  USART1_RX = 7ul,  USB_OTG_FS_ID = 10ul, }; }
      namespace PA11 { enum { CAN1_RX = 9ul,  LTDC_R4 = 14ul,  TIM1_CH4 = 1ul,  USART1_CTS = 7ul,  USB_OTG_FS_DM = 10ul, }; }
      namespace PA12 { enum { CAN1_TX = 9ul,  LTDC_R5 = 14ul,  TIM1_ETR = 1ul,  USART1_RTS = 7ul,  USB_OTG_FS_DP = 10ul, }; }
      namespace PA13 { enum { SYS_JTMS_SWDIO = 0ul, }; }
      namespace PA14 { enum { SYS_JTCK_SWCLK = 0ul, }; }
      namespace PA15 { enum { I2S3_WS = 6ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  SYS_JTDI = 0ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul, }; }
      namespace PA2  { enum { ETH_MDIO = 11ul,  TIM2_CH3 = 1ul,  TIM5_CH3 = 2ul,  TIM9_CH1 = 3ul,  USART2_TX = 7ul, }; }
      namespace PA3  { enum { ETH_COL = 11ul,  LTDC_B5 = 14ul,  TIM2_CH4 = 1ul,  TIM5_CH4 = 2ul,  TIM9_CH2 = 3ul,  USART2_RX = 7ul,  USB_OTG_HS_ULPI_D0 = 10ul, }; }
      namespace PA4  { enum { DCMI_HSYNC = 13ul,  I2S3_WS = 6ul,  LTDC_VSYNC = 14ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  USART2_CK = 7ul,  USB_OTG_HS_SOF = 12ul, }; }
      namespace PA5  { enum { SPI1_SCK = 5ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul,  TIM8_CH1N = 3ul,  USB_OTG_HS_ULPI_CK = 10ul, }; }
      namespace PA6  { enum { DCMI_PIXCLK = 13ul,  LTDC_G2 = 14ul,  SPI1_MISO = 5ul,  TIM13_CH1 = 9ul,  TIM1_BKIN = 1ul,  TIM3_CH1 = 2ul,  TIM8_BKIN = 3ul, }; }
      namespace PA7  { enum { ETH_CRS_DV = 11ul,  ETH_RX_DV = 11ul,  SPI1_MOSI = 5ul,  TIM14_CH1 = 9ul,  TIM1_CH1N = 1ul,  TIM3_CH2 = 2ul,  TIM8_CH1N = 3ul, }; }
      namespace PA8  { enum { I2C3_SCL = 4ul,  LTDC_R6 = 14ul,  RCC_MCO_1 = 0ul,  TIM1_CH1 = 1ul,  USART1_CK = 7ul,  USB_OTG_FS_SOF = 10ul, }; }
      namespace PA9  { enum { DCMI_D0 = 13ul,  I2C3_SMBA = 4ul,  TIM1_CH2 = 1ul,  USART1_TX = 7ul, }; }
      namespace PB0  { enum { ETH_RXD2 = 11ul,  LTDC_R3 = 9ul,  TIM1_CH2N = 1ul,  TIM3_CH3 = 2ul,  TIM8_CH2N = 3ul,  USB_OTG_HS_ULPI_D1 = 10ul, }; }
      namespace PB1  { enum { ETH_RXD3 = 11ul,  LTDC_R6 = 9ul,  TIM1_CH3N = 1ul,  TIM3_CH4 = 2ul,  TIM8_CH3N = 3ul,  USB_OTG_HS_ULPI_D2 = 10ul, }; }
      namespace PB10 { enum { ETH_RX_ER = 11ul,  I2C2_SCL = 4ul,  I2S2_CK = 5ul,  LTDC_G4 = 14ul,  SPI2_SCK = 5ul,  TIM2_CH3 = 1ul,  USART3_TX = 7ul,  USB_OTG_HS_ULPI_D3 = 10ul, }; }
      namespace PB11 { enum { ETH_TX_EN = 11ul,  I2C2_SDA = 4ul,  LTDC_G5 = 14ul,  TIM2_CH4 = 1ul,  USART3_RX = 7ul,  USB_OTG_HS_ULPI_D4 = 10ul, }; }
      namespace PB12 { enum { CAN2_RX = 9ul,  ETH_TXD0 = 11ul,  I2C2_SMBA = 4ul,  I2S2_WS = 5ul,  SPI2_NSS = 5ul,  TIM1_BKIN = 1ul,  USART3_CK = 7ul,  USB_OTG_HS_ID = 12ul,  USB_OTG_HS_ULPI_D5 = 10ul, }; }
      namespace PB13 { enum { CAN2_TX = 9ul,  ETH_TXD1 = 11ul,  I2S2_CK = 5ul,  SPI2_SCK = 5ul,  TIM1_CH1N = 1ul,  USART3_CTS = 7ul,  USB_OTG_HS_ULPI_D6 = 10ul, }; }
      namespace PB14 { enum { I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  TIM12_CH1 = 9ul,  TIM1_CH2N = 1ul,  TIM8_CH2N = 3ul,  USART3_RTS = 7ul,  USB_OTG_HS_DM = 12ul, }; }
      namespace PB15 { enum { I2S2_SD = 5ul,  RTC_REFIN = 0ul,  SPI2_MOSI = 5ul,  TIM12_CH2 = 9ul,  TIM1_CH3N = 1ul,  TIM8_CH3N = 3ul,  USB_OTG_HS_DP = 12ul, }; }
      namespace PB2  { enum {}; }
      namespace PB3  { enum { I2S3_CK = 6ul,  SPI1_SCK = 5ul,  SPI3_SCK = 6ul,  SYS_JTDO_SWO = 0ul,  TIM2_CH2 = 1ul, }; }
      namespace PB4  { enum { I2S3_ext_SD = 7ul,  SPI1_MISO = 5ul,  SPI3_MISO = 6ul,  SYS_JTRST = 0ul,  TIM3_CH1 = 2ul, }; }
      namespace PB5  { enum { CAN2_RX = 9ul,  DCMI_D10 = 13ul,  ETH_PPS_OUT = 11ul,  FMC_SDCKE1 = 12ul,  I2C1_SMBA = 4ul,  I2S3_SD = 6ul,  SPI1_MOSI = 5ul,  SPI3_MOSI = 6ul,  TIM3_CH2 = 2ul,  USB_OTG_HS_ULPI_D7 = 10ul, }; }
      namespace PB6  { enum { CAN2_TX = 9ul,  DCMI_D5 = 13ul,  FMC_SDNE1 = 12ul,  I2C1_SCL = 4ul,  TIM4_CH1 = 2ul,  USART1_TX = 7ul, }; }
      namespace PB7  { enum { DCMI_VSYNC = 13ul,  FMC_NL = 12ul,  I2C1_SDA = 4ul,  TIM4_CH2 = 2ul,  USART1_RX = 7ul, }; }
      namespace PB8  { enum { CAN1_RX = 9ul,  DCMI_D6 = 13ul,  ETH_TXD3 = 11ul,  I2C1_SCL = 4ul,  LTDC_B6 = 14ul,  SDIO_D4 = 12ul,  TIM10_CH1 = 3ul,  TIM4_CH3 = 2ul, }; }
      namespace PB9  { enum { CAN1_TX = 9ul,  DCMI_D7 = 13ul,  I2C1_SDA = 4ul,  I2S2_WS = 5ul,  LTDC_B7 = 14ul,  SDIO_D5 = 12ul,  SPI2_NSS = 5ul,  TIM11_CH1 = 3ul,  TIM4_CH4 = 2ul, }; }
      namespace PC0  { enum { FMC_SDNWE = 12ul,  USB_OTG_HS_ULPI_STP = 10ul, }; }
      namespace PC1  { enum { ETH_MDC = 11ul, }; }
      namespace PC10 { enum { DCMI_D8 = 13ul,  I2S3_CK = 6ul,  LTDC_R2 = 14ul,  SDIO_D2 = 12ul,  SPI3_SCK = 6ul,  UART4_TX = 8ul,  USART3_TX = 7ul, }; }
      namespace PC11 { enum { DCMI_D4 = 13ul,  I2S3_ext_SD = 5ul,  SDIO_D3 = 12ul,  SPI3_MISO = 6ul,  UART4_RX = 8ul,  USART3_RX = 7ul, }; }
      namespace PC12 { enum { DCMI_D9 = 13ul,  I2S3_SD = 6ul,  SDIO_CK = 12ul,  SPI3_MOSI = 6ul,  UART5_TX = 8ul,  USART3_CK = 7ul, }; }
      namespace PC13 { enum {}; }
      namespace PC14 { enum {}; }
      namespace PC15 { enum {}; }
      namespace PC2  { enum { ETH_TXD2 = 11ul,  FMC_SDNE0 = 12ul,  I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  USB_OTG_HS_ULPI_DIR = 10ul, }; }
      namespace PC3  { enum { ETH_TX_CLK = 11ul,  FMC_SDCKE0 = 12ul,  I2S2_SD = 5ul,  SPI2_MOSI = 5ul,  USB_OTG_HS_ULPI_NXT = 10ul, }; }
      namespace PC4  { enum { ETH_RXD0 = 11ul, }; }
      namespace PC5  { enum { ETH_RXD1 = 11ul, }; }
      namespace PC6  { enum { DCMI_D0 = 13ul,  I2S2_MCK = 5ul,  LTDC_HSYNC = 14ul,  SDIO_D6 = 12ul,  TIM3_CH1 = 2ul,  TIM8_CH1 = 3ul,  USART6_TX = 8ul, }; }
      namespace PC7  { enum { DCMI_D1 = 13ul,  I2S3_MCK = 6ul,  LTDC_G6 = 14ul,  SDIO_D7 = 12ul,  TIM3_CH2 = 2ul,  TIM8_CH2 = 3ul,  USART6_RX = 8ul, }; }
      namespace PC8  { enum { DCMI_D2 = 13ul,  SDIO_D0 = 12ul,  TIM3_CH3 = 2ul,  TIM8_CH3 = 3ul,  USART6_CK = 8ul, }; }
      namespace PC9  { enum { DCMI_D3 = 13ul,  I2C3_SDA = 4ul,  I2S_CKIN = 5ul,  RCC_MCO_2 = 0ul,  SDIO_D1 = 12ul,  TIM3_CH4 = 2ul,  TIM8_CH4 = 3ul, }; }
      namespace PD0  { enum { CAN1_RX = 9ul,  FMC_D2 = 12ul,  FMC_DA2 = 12ul, }; }
      namespace PD1  { enum { CAN1_TX = 9ul,  FMC_D3 = 12ul,  FMC_DA3 = 12ul, }; }
      namespace PD10 { enum { FMC_D15 = 12ul,  FMC_DA15 = 12ul,  LTDC_B3 = 14ul,  USART3_CK = 7ul, }; }
      namespace PD11 { enum { FMC_A16 = 12ul,  FMC_CLE = 12ul,  USART3_CTS = 7ul, }; }
      namespace PD12 { enum { FMC_A17 = 12ul,  FMC_ALE = 12ul,  TIM4_CH1 = 2ul,  USART3_RTS = 7ul, }; }
      namespace PD13 { enum { FMC_A18 = 12ul,  TIM4_CH2 = 2ul, }; }
      namespace PD14 { enum { FMC_D0 = 12ul,  FMC_DA0 = 12ul,  TIM4_CH3 = 2ul, }; }
      namespace PD15 { enum { FMC_D1 = 12ul,  FMC_DA1 = 12ul,  TIM4_CH4 = 2ul, }; }
      namespace PD2  { enum { DCMI_D11 = 13ul,  SDIO_CMD = 12ul,  TIM3_ETR = 2ul,  UART5_RX = 8ul, }; }
      namespace PD3  { enum { DCMI_D5 = 13ul,  FMC_CLK = 12ul,  I2S2_CK = 5ul,  LTDC_G7 = 14ul,  SPI2_SCK = 5ul,  USART2_CTS = 7ul, }; }
      namespace PD4  { enum { FMC_NOE = 12ul,  USART2_RTS = 7ul, }; }
      namespace PD5  { enum { FMC_NWE = 12ul,  USART2_TX = 7ul, }; }
      namespace PD6  { enum { DCMI_D10 = 13ul,  FMC_NWAIT = 12ul,  I2S3_SD = 5ul,  LTDC_B2 = 14ul,  SAI1_SD_A = 6ul,  SPI3_MOSI = 5ul,  USART2_RX = 7ul, }; }
      namespace PD7  { enum { FMC_NCE2 = 12ul,  FMC_NE1 = 12ul,  USART2_CK = 7ul, }; }
      namespace PD8  { enum { FMC_D13 = 12ul,  FMC_DA13 = 12ul,  USART3_TX = 7ul, }; }
      namespace PD9  { enum { FMC_D14 = 12ul,  FMC_DA14 = 12ul,  USART3_RX = 7ul, }; }
      namespace PE0  { enum { DCMI_D2 = 13ul,  FMC_NBL0 = 12ul,  TIM4_ETR = 2ul,  UART8_RX = 8ul, }; }
      namespace PE1  { enum { DCMI_D3 = 13ul,  FMC_NBL1 = 12ul,  UART8_TX = 8ul, }; }
      namespace PE10 { enum { FMC_D7 = 12ul,  FMC_DA7 = 12ul,  TIM1_CH2N = 1ul, }; }
      namespace PE11 { enum { FMC_D8 = 12ul,  FMC_DA8 = 12ul,  LTDC_G3 = 14ul,  SPI4_NSS = 5ul,  TIM1_CH2 = 1ul, }; }
      namespace PE12 { enum { FMC_D9 = 12ul,  FMC_DA9 = 12ul,  LTDC_B4 = 14ul,  SPI4_SCK = 5ul,  TIM1_CH3N = 1ul, }; }
      namespace PE13 { enum { FMC_D10 = 12ul,  FMC_DA10 = 12ul,  LTDC_DE = 14ul,  SPI4_MISO = 5ul,  TIM1_CH3 = 1ul, }; }
      namespace PE14 { enum { FMC_D11 = 12ul,  FMC_DA11 = 12ul,  LTDC_CLK = 14ul,  SPI4_MOSI = 5ul,  TIM1_CH4 = 1ul, }; }
      namespace PE15 { enum { FMC_D12 = 12ul,  FMC_DA12 = 12ul,  LTDC_R7 = 14ul,  TIM1_BKIN = 1ul, }; }
      namespace PE2  { enum { ETH_TXD3 = 11ul,  FMC_A23 = 12ul,  SAI1_MCLK_A = 6ul,  SPI4_SCK = 5ul,  SYS_TRACECLK = 0ul, }; }
      namespace PE3  { enum { FMC_A19 = 12ul,  SAI1_SD_B = 6ul,  SYS_TRACED0 = 0ul, }; }
      namespace PE4  { enum { DCMI_D4 = 13ul,  FMC_A20 = 12ul,  LTDC_B0 = 14ul,  SAI1_FS_A = 6ul,  SPI4_NSS = 5ul,  SYS_TRACED1 = 0ul, }; }
      namespace PE5  { enum { DCMI_D6 = 13ul,  FMC_A21 = 12ul,  LTDC_G0 = 14ul,  SAI1_SCK_A = 6ul,  SPI4_MISO = 5ul,  SYS_TRACED2 = 0ul,  TIM9_CH1 = 3ul, }; }
      namespace PE6  { enum { DCMI_D7 = 13ul,  FMC_A22 = 12ul,  LTDC_G1 = 14ul,  SAI1_SD_A = 6ul,  SPI4_MOSI = 5ul,  SYS_TRACED3 = 0ul,  TIM9_CH2 = 3ul, }; }
      namespace PE7  { enum { FMC_D4 = 12ul,  FMC_DA4 = 12ul,  TIM1_ETR = 1ul,  UART7_RX = 8ul, }; }
      namespace PE8  { enum { FMC_D5 = 12ul,  FMC_DA5 = 12ul,  TIM1_CH1N = 1ul,  UART7_TX = 8ul, }; }
      namespace PE9  { enum { FMC_D6 = 12ul,  FMC_DA6 = 12ul,  TIM1_CH1 = 1ul, }; }
      namespace PF0  { enum { FMC_A0 = 12ul,  I2C2_SDA = 4ul, }; }
      namespace PF1  { enum { FMC_A1 = 12ul,  I2C2_SCL = 4ul, }; }
      namespace PF10 { enum { DCMI_D11 = 13ul,  FMC_INTR = 12ul,  LTDC_DE = 14ul, }; }
      namespace PF11 { enum { DCMI_D12 = 13ul,  FMC_SDNRAS = 12ul,  SPI5_MOSI = 5ul, }; }
      namespace PF12 { enum { FMC_A6 = 12ul, }; }
      namespace PF13 { enum { FMC_A7 = 12ul, }; }
      namespace PF14 { enum { FMC_A8 = 12ul, }; }
      namespace PF15 { enum { FMC_A9 = 12ul, }; }
      namespace PF2  { enum { FMC_A2 = 12ul,  I2C2_SMBA = 4ul, }; }
      namespace PF3  { enum { FMC_A3 = 12ul, }; }
      namespace PF4  { enum { FMC_A4 = 12ul, }; }
      namespace PF5  { enum { FMC_A5 = 12ul, }; }
      namespace PF6  { enum { FMC_NIORD = 12ul,  SAI1_SD_B = 6ul,  SPI5_NSS = 5ul,  TIM10_CH1 = 3ul,  UART7_RX = 8ul, }; }
      namespace PF7  { enum { FMC_NREG = 12ul,  SAI1_MCLK_B = 6ul,  SPI5_SCK = 5ul,  TIM11_CH1 = 3ul,  UART7_TX = 8ul, }; }
      namespace PF8  { enum { FMC_NIOWR = 12ul,  SAI1_SCK_B = 6ul,  SPI5_MISO = 5ul,  TIM13_CH1 = 9ul, }; }
      namespace PF9  { enum { FMC_CD = 12ul,  SAI1_FS_B = 6ul,  SPI5_MOSI = 5ul,  TIM14_CH1 = 9ul, }; }
      namespace PG0  { enum { FMC_A10 = 12ul, }; }
      namespace PG1  { enum { FMC_A11 = 12ul, }; }
      namespace PG10 { enum { DCMI_D2 = 13ul,  FMC_NCE4_1 = 12ul,  FMC_NE3 = 12ul,  LTDC_B2 = 14ul,  LTDC_G3 = 9ul, }; }
      namespace PG11 { enum { DCMI_D3 = 13ul,  ETH_TX_EN = 11ul,  FMC_NCE4_2 = 12ul,  LTDC_B3 = 14ul, }; }
      namespace PG12 { enum { FMC_NE4 = 12ul,  LTDC_B1 = 14ul,  LTDC_B4 = 9ul,  SPI6_MISO = 5ul,  USART6_RTS = 8ul, }; }
      namespace PG13 { enum { ETH_TXD0 = 11ul,  FMC_A24 = 12ul,  SPI6_SCK = 5ul,  USART6_CTS = 8ul, }; }
      namespace PG14 { enum { ETH_TXD1 = 11ul,  FMC_A25 = 12ul,  SPI6_MOSI = 5ul,  USART6_TX = 8ul, }; }
      namespace PG15 { enum { DCMI_D13 = 13ul,  FMC_SDNCAS = 12ul,  USART6_CTS = 8ul, }; }
      namespace PG2  { enum { FMC_A12 = 12ul, }; }
      namespace PG3  { enum { FMC_A13 = 12ul, }; }
      namespace PG4  { enum { FMC_A14 = 12ul,  FMC_BA0 = 12ul, }; }
      namespace PG5  { enum { FMC_A15 = 12ul,  FMC_BA1 = 12ul, }; }
      namespace PG6  { enum { DCMI_D12 = 13ul,  FMC_INT2 = 12ul,  LTDC_R7 = 14ul, }; }
      namespace PG7  { enum { DCMI_D13 = 13ul,  FMC_INT3 = 12ul,  LTDC_CLK = 14ul,  USART6_CK = 8ul, }; }
      namespace PG8  { enum { ETH_PPS_OUT = 11ul,  FMC_SDCLK = 12ul,  SPI6_NSS = 5ul,  USART6_RTS = 8ul, }; }
      namespace PG9  { enum { DCMI_VSYNC = 13ul,  FMC_NCE3 = 12ul,  FMC_NE2 = 12ul,  USART6_RX = 8ul, }; }
      namespace PH0  { enum {}; }
      namespace PH1  { enum {}; }
      namespace PH10 { enum { DCMI_D1 = 13ul,  FMC_D18 = 12ul,  LTDC_R4 = 14ul,  TIM5_CH1 = 2ul, }; }
      namespace PH11 { enum { DCMI_D2 = 13ul,  FMC_D19 = 12ul,  LTDC_R5 = 14ul,  TIM5_CH2 = 2ul, }; }
      namespace PH12 { enum { DCMI_D3 = 13ul,  FMC_D20 = 12ul,  LTDC_R6 = 14ul,  TIM5_CH3 = 2ul, }; }
      namespace PH13 { enum { CAN1_TX = 9ul,  FMC_D21 = 12ul,  LTDC_G2 = 14ul,  TIM8_CH1N = 3ul, }; }
      namespace PH14 { enum { DCMI_D4 = 13ul,  FMC_D22 = 12ul,  LTDC_G3 = 14ul,  TIM8_CH2N = 3ul, }; }
      namespace PH15 { enum { DCMI_D11 = 13ul,  FMC_D23 = 12ul,  LTDC_G4 = 14ul,  TIM8_CH3N = 3ul, }; }
      namespace PH2  { enum { ETH_CRS = 11ul,  FMC_SDCKE0 = 12ul,  LTDC_R0 = 14ul, }; }
      namespace PH3  { enum { ETH_COL = 11ul,  FMC_SDNE0 = 12ul,  LTDC_R1 = 14ul, }; }
      namespace PH4  { enum { I2C2_SCL = 4ul,  USB_OTG_HS_ULPI_NXT = 10ul, }; }
      namespace PH5  { enum { FMC_SDNWE = 12ul,  I2C2_SDA = 4ul,  SPI5_NSS = 5ul, }; }
      namespace PH6  { enum { DCMI_D8 = 13ul,  ETH_RXD2 = 11ul,  FMC_SDNE1 = 12ul,  I2C2_SMBA = 4ul,  SPI5_SCK = 5ul,  TIM12_CH1 = 9ul, }; }
      namespace PH7  { enum { DCMI_D9 = 13ul,  ETH_RXD3 = 11ul,  FMC_SDCKE1 = 12ul,  I2C3_SCL = 4ul,  SPI5_MISO = 5ul, }; }
      namespace PH8  { enum { DCMI_HSYNC = 13ul,  FMC_D16 = 12ul,  I2C3_SDA = 4ul,  LTDC_R2 = 14ul, }; }
      namespace PH9  { enum { DCMI_D0 = 13ul,  FMC_D17 = 12ul,  I2C3_SMBA = 4ul,  LTDC_R3 = 14ul,  TIM12_CH2 = 9ul, }; }
      namespace PI0  { enum { DCMI_D13 = 13ul,  FMC_D24 = 12ul,  I2S2_WS = 5ul,  LTDC_G5 = 14ul,  SPI2_NSS = 5ul,  TIM5_CH4 = 2ul, }; }
      namespace PI1  { enum { DCMI_D8 = 13ul,  FMC_D25 = 12ul,  I2S2_CK = 5ul,  LTDC_G6 = 14ul,  SPI2_SCK = 5ul, }; }
      namespace PI10 { enum { ETH_RX_ER = 11ul,  FMC_D31 = 12ul,  LTDC_HSYNC = 14ul, }; }
      namespace PI11 { enum { USB_OTG_HS_ULPI_DIR = 10ul, }; }
      namespace PI12 { enum { LTDC_HSYNC = 14ul, }; }
      namespace PI13 { enum { LTDC_VSYNC = 14ul, }; }
      namespace PI14 { enum { LTDC_CLK = 14ul, }; }
      namespace PI15 { enum { LTDC_R0 = 14ul, }; }
      namespace PI2  { enum { DCMI_D9 = 13ul,  FMC_D26 = 12ul,  I2S2_ext_SD = 6ul,  LTDC_G7 = 14ul,  SPI2_MISO = 5ul,  TIM8_CH4 = 3ul, }; }
      namespace PI3  { enum { DCMI_D10 = 13ul,  FMC_D27 = 12ul,  I2S2_SD = 5ul,  SPI2_MOSI = 5ul,  TIM8_ETR = 3ul, }; }
      namespace PI4  { enum { DCMI_D5 = 13ul,  FMC_NBL2 = 12ul,  LTDC_B4 = 14ul,  TIM8_BKIN = 3ul, }; }
      namespace PI5  { enum { DCMI_VSYNC = 13ul,  FMC_NBL3 = 12ul,  LTDC_B5 = 14ul,  TIM8_CH1 = 3ul, }; }
      namespace PI6  { enum { DCMI_D6 = 13ul,  FMC_D28 = 12ul,  LTDC_B6 = 14ul,  TIM8_CH2 = 3ul, }; }
      namespace PI7  { enum { DCMI_D7 = 13ul,  FMC_D29 = 12ul,  LTDC_B7 = 14ul,  TIM8_CH3 = 3ul, }; }
      namespace PI8  { enum {}; }
      namespace PI9  { enum { CAN1_RX = 9ul,  FMC_D30 = 12ul,  LTDC_VSYNC = 14ul, }; }
      namespace PJ0  { enum { LTDC_R1 = 14ul, }; }
      namespace PJ1  { enum { LTDC_R2 = 14ul, }; }
      namespace PJ10 { enum { LTDC_G3 = 14ul, }; }
      namespace PJ11 { enum { LTDC_G4 = 14ul, }; }
      namespace PJ12 { enum { LTDC_B0 = 14ul, }; }
      namespace PJ13 { enum { LTDC_B1 = 14ul, }; }
      namespace PJ14 { enum { LTDC_B2 = 14ul, }; }
      namespace PJ15 { enum { LTDC_B3 = 14ul, }; }
      namespace PJ2  { enum { LTDC_R3 = 14ul, }; }
      namespace PJ3  { enum { LTDC_R4 = 14ul, }; }
      namespace PJ4  { enum { LTDC_R5 = 14ul, }; }
      namespace PJ5  { enum { LTDC_R6 = 14ul, }; }
      namespace PJ6  { enum { LTDC_R7 = 14ul, }; }
      namespace PJ7  { enum { LTDC_G0 = 14ul, }; }
      namespace PJ8  { enum { LTDC_G1 = 14ul, }; }
      namespace PJ9  { enum { LTDC_G2 = 14ul, }; }
      namespace PK0  { enum { LTDC_G5 = 14ul, }; }
      namespace PK1  { enum { LTDC_G6 = 14ul, }; }
      namespace PK2  { enum { LTDC_G7 = 14ul, }; }
      namespace PK3  { enum { LTDC_B4 = 14ul, }; }
      namespace PK4  { enum { LTDC_B5 = 14ul, }; }
      namespace PK5  { enum { LTDC_B6 = 14ul, }; }
      namespace PK6  { enum { LTDC_B7 = 14ul, }; }
      namespace PK7  { enum { LTDC_DE = 14ul, }; }
    } // namespace Af
  } // inline namespace 
} // namespace mpp::gpio 
 
