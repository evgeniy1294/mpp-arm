﻿/**
  ***********************************************************
  @file   /src/gpio/st/spec/STM32F417_gpio_v1_0.hpp
  @brief  This is autogenerated file        
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

#if defined (STM32F405xx)
  #include "stm32f405xx.h"
#elif defined (STM32F407xx)
  #include "stm32f407xx.h"
#elif defined (STM32F415xx)
  #include "stm32f415xx.h"
#elif defined (STM32F417xx)
  #include "stm32f417xx.h"
#else
  #error "You must define supported target"
#endif



namespace mpp::gpio
{
  inline namespace STM32F417_gpio_v1_0
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
    };

    template< typename IO >
    constexpr bool IsValidIo()
    {
      switch(IO::Port())
      { 
        case Port::A: return IO::Pin() < 16u;
        case Port::B: return IO::Pin() < 16u;
        case Port::C: return IO::Pin() < 16u;
        case Port::D: return IO::Pin() < 16u;
        case Port::E: return IO::Pin() < 16u;
        case Port::F: return IO::Pin() < 16u;
        case Port::G: return IO::Pin() < 16u;
        case Port::H: return IO::Pin() < 16u;
        case Port::I: return IO::Pin() < 12u;

        default: return false;
      }
    }


    

    struct PA0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { ETH_CRS = 11ul,  SYS_WKUP = 0ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul,  TIM5_CH1 = 2ul,  TIM8_ETR = 3ul,  UART4_TX = 8ul,  USART2_CTS = 7ul, }; 
    };

    struct PA1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { ETH_REF_CLK = 11ul,  ETH_RX_CLK = 11ul,  TIM2_CH2 = 1ul,  TIM5_CH2 = 2ul,  UART4_RX = 8ul,  USART2_RTS = 7ul, }; 
    };

    struct PA10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { DCMI_D1 = 13ul,  TIM1_CH3 = 1ul,  USART1_RX = 7ul,  USB_OTG_FS_ID = 10ul, }; 
    };

    struct PA11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { CAN1_RX = 9ul,  TIM1_CH4 = 1ul,  USART1_CTS = 7ul,  USB_OTG_FS_DM = 10ul, }; 
    };

    struct PA12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { CAN1_TX = 9ul,  TIM1_ETR = 1ul,  USART1_RTS = 7ul,  USB_OTG_FS_DP = 10ul, }; 
    };

    struct PA13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { SYS_JTMS_SWDIO = 0ul, }; 
    };

    struct PA14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { SYS_JTCK_SWCLK = 0ul, }; 
    };

    struct PA15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { I2S3_WS = 6ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  SYS_JTDI = 0ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul, }; 
    };

    struct PA2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { ETH_MDIO = 11ul,  TIM2_CH3 = 1ul,  TIM5_CH3 = 2ul,  TIM9_CH1 = 3ul,  USART2_TX = 7ul, }; 
    };

    struct PA3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { ETH_COL = 11ul,  TIM2_CH4 = 1ul,  TIM5_CH4 = 2ul,  TIM9_CH2 = 3ul,  USART2_RX = 7ul,  USB_OTG_HS_ULPI_D0 = 10ul, }; 
    };

    struct PA4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { DCMI_HSYNC = 13ul,  I2S3_WS = 6ul,  SPI1_NSS = 5ul,  SPI3_NSS = 6ul,  USART2_CK = 7ul,  USB_OTG_HS_SOF = 12ul, }; 
    };

    struct PA5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { SPI1_SCK = 5ul,  TIM2_CH1 = 1ul,  TIM2_ETR = 1ul,  TIM8_CH1N = 3ul,  USB_OTG_HS_ULPI_CK = 10ul, }; 
    };

    struct PA6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { DCMI_PIXCLK = 13ul,  SPI1_MISO = 5ul,  TIM13_CH1 = 9ul,  TIM1_BKIN = 1ul,  TIM3_CH1 = 2ul,  TIM8_BKIN = 3ul, }; 
    };

    struct PA7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { ETH_CRS_DV = 11ul,  ETH_RX_DV = 11ul,  SPI1_MOSI = 5ul,  TIM14_CH1 = 9ul,  TIM1_CH1N = 1ul,  TIM3_CH2 = 2ul,  TIM8_CH1N = 3ul, }; 
    };

    struct PA8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { I2C3_SCL = 4ul,  RCC_MCO_1 = 0ul,  TIM1_CH1 = 1ul,  USART1_CK = 7ul,  USB_OTG_FS_SOF = 10ul, }; 
    };

    struct PA9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::A; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { DCMI_D0 = 13ul,  I2C3_SMBA = 4ul,  TIM1_CH2 = 1ul,  USART1_TX = 7ul, }; 
    };

    struct PB0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { ETH_RXD2 = 11ul,  TIM1_CH2N = 1ul,  TIM3_CH3 = 2ul,  TIM8_CH2N = 3ul,  USB_OTG_HS_ULPI_D1 = 10ul, }; 
    };

    struct PB1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { ETH_RXD3 = 11ul,  TIM1_CH3N = 1ul,  TIM3_CH4 = 2ul,  TIM8_CH3N = 3ul,  USB_OTG_HS_ULPI_D2 = 10ul, }; 
    };

    struct PB10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { ETH_RX_ER = 11ul,  I2C2_SCL = 4ul,  I2S2_CK = 5ul,  SPI2_SCK = 5ul,  TIM2_CH3 = 1ul,  USART3_TX = 7ul,  USB_OTG_HS_ULPI_D3 = 10ul, }; 
    };

    struct PB11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { ETH_TX_EN = 11ul,  I2C2_SDA = 4ul,  TIM2_CH4 = 1ul,  USART3_RX = 7ul,  USB_OTG_HS_ULPI_D4 = 10ul, }; 
    };

    struct PB12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { CAN2_RX = 9ul,  ETH_TXD0 = 11ul,  I2C2_SMBA = 4ul,  I2S2_WS = 5ul,  SPI2_NSS = 5ul,  TIM1_BKIN = 1ul,  USART3_CK = 7ul,  USB_OTG_HS_ID = 12ul,  USB_OTG_HS_ULPI_D5 = 10ul, }; 
    };

    struct PB13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { CAN2_TX = 9ul,  ETH_TXD1 = 11ul,  I2S2_CK = 5ul,  SPI2_SCK = 5ul,  TIM1_CH1N = 1ul,  USART3_CTS = 7ul,  USB_OTG_HS_ULPI_D6 = 10ul, }; 
    };

    struct PB14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  TIM12_CH1 = 9ul,  TIM1_CH2N = 1ul,  TIM8_CH2N = 3ul,  USART3_RTS = 7ul,  USB_OTG_HS_DM = 12ul, }; 
    };

    struct PB15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { I2S2_SD = 5ul,  RTC_REFIN = 0ul,  SPI2_MOSI = 5ul,  TIM12_CH2 = 9ul,  TIM1_CH3N = 1ul,  TIM8_CH3N = 3ul,  USB_OTG_HS_DP = 12ul, }; 
    };

    struct PB2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum {}; 
    };

    struct PB3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { I2S3_CK = 6ul,  SPI1_SCK = 5ul,  SPI3_SCK = 6ul,  SYS_JTDO_SWO = 0ul,  TIM2_CH2 = 1ul, }; 
    };

    struct PB4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { I2S3_ext_SD = 7ul,  SPI1_MISO = 5ul,  SPI3_MISO = 6ul,  SYS_JTRST = 0ul,  TIM3_CH1 = 2ul, }; 
    };

    struct PB5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { CAN2_RX = 9ul,  DCMI_D10 = 13ul,  ETH_PPS_OUT = 11ul,  I2C1_SMBA = 4ul,  I2S3_SD = 6ul,  SPI1_MOSI = 5ul,  SPI3_MOSI = 6ul,  TIM3_CH2 = 2ul,  USB_OTG_HS_ULPI_D7 = 10ul, }; 
    };

    struct PB6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { CAN2_TX = 9ul,  DCMI_D5 = 13ul,  I2C1_SCL = 4ul,  TIM4_CH1 = 2ul,  USART1_TX = 7ul, }; 
    };

    struct PB7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { DCMI_VSYNC = 13ul,  FSMC_NL = 12ul,  I2C1_SDA = 4ul,  TIM4_CH2 = 2ul,  USART1_RX = 7ul, }; 
    };

    struct PB8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { CAN1_RX = 9ul,  DCMI_D6 = 13ul,  ETH_TXD3 = 11ul,  I2C1_SCL = 4ul,  SDIO_D4 = 12ul,  TIM10_CH1 = 3ul,  TIM4_CH3 = 2ul, }; 
    };

    struct PB9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::B; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { CAN1_TX = 9ul,  DCMI_D7 = 13ul,  I2C1_SDA = 4ul,  I2S2_WS = 5ul,  SDIO_D5 = 12ul,  SPI2_NSS = 5ul,  TIM11_CH1 = 3ul,  TIM4_CH4 = 2ul, }; 
    };

    struct PC0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { USB_OTG_HS_ULPI_STP = 10ul, }; 
    };

    struct PC1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { ETH_MDC = 11ul, }; 
    };

    struct PC10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { DCMI_D8 = 13ul,  I2S3_CK = 6ul,  SDIO_D2 = 12ul,  SPI3_SCK = 6ul,  UART4_TX = 8ul,  USART3_TX = 7ul, }; 
    };

    struct PC11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { DCMI_D4 = 13ul,  I2S3_ext_SD = 5ul,  SDIO_D3 = 12ul,  SPI3_MISO = 6ul,  UART4_RX = 8ul,  USART3_RX = 7ul, }; 
    };

    struct PC12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { DCMI_D9 = 13ul,  I2S3_SD = 6ul,  SDIO_CK = 12ul,  SPI3_MOSI = 6ul,  UART5_TX = 8ul,  USART3_CK = 7ul, }; 
    };

    struct PC13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { RTC_AF1 = 0ul, }; 
    };

    struct PC14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { RCC_OSC32_IN = 0ul, }; 
    };

    struct PC15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { RCC_OSC32_OUT = 0ul, }; 
    };

    struct PC2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { ETH_TXD2 = 11ul,  I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  USB_OTG_HS_ULPI_DIR = 10ul, }; 
    };

    struct PC3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { ETH_TX_CLK = 11ul,  I2S2_SD = 5ul,  SPI2_MOSI = 5ul,  USB_OTG_HS_ULPI_NXT = 10ul, }; 
    };

    struct PC4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { ETH_RXD0 = 11ul, }; 
    };

    struct PC5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { ETH_RXD1 = 11ul, }; 
    };

    struct PC6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { DCMI_D0 = 13ul,  I2S2_MCK = 5ul,  SDIO_D6 = 12ul,  TIM3_CH1 = 2ul,  TIM8_CH1 = 3ul,  USART6_TX = 8ul, }; 
    };

    struct PC7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { DCMI_D1 = 13ul,  I2S3_MCK = 6ul,  SDIO_D7 = 12ul,  TIM3_CH2 = 2ul,  TIM8_CH2 = 3ul,  USART6_RX = 8ul, }; 
    };

    struct PC8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { DCMI_D2 = 13ul,  SDIO_D0 = 12ul,  TIM3_CH3 = 2ul,  TIM8_CH3 = 3ul,  USART6_CK = 8ul, }; 
    };

    struct PC9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::C; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { DCMI_D3 = 13ul,  I2C3_SDA = 4ul,  I2S_CKIN = 5ul,  RCC_MCO_2 = 0ul,  SDIO_D1 = 12ul,  TIM3_CH4 = 2ul,  TIM8_CH4 = 3ul, }; 
    };

    struct PD0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { CAN1_RX = 9ul,  FSMC_D2 = 12ul,  FSMC_DA2 = 12ul, }; 
    };

    struct PD1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { CAN1_TX = 9ul,  FSMC_D3 = 12ul,  FSMC_DA3 = 12ul, }; 
    };

    struct PD10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { FSMC_D15 = 12ul,  FSMC_DA15 = 12ul,  USART3_CK = 7ul, }; 
    };

    struct PD11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { FSMC_A16 = 12ul,  FSMC_CLE = 12ul,  USART3_CTS = 7ul, }; 
    };

    struct PD12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { FSMC_A17 = 12ul,  FSMC_ALE = 12ul,  TIM4_CH1 = 2ul,  USART3_RTS = 7ul, }; 
    };

    struct PD13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { FSMC_A18 = 12ul,  TIM4_CH2 = 2ul, }; 
    };

    struct PD14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { FSMC_D0 = 12ul,  FSMC_DA0 = 12ul,  TIM4_CH3 = 2ul, }; 
    };

    struct PD15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { FSMC_D1 = 12ul,  FSMC_DA1 = 12ul,  TIM4_CH4 = 2ul, }; 
    };

    struct PD2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { DCMI_D11 = 13ul,  SDIO_CMD = 12ul,  TIM3_ETR = 2ul,  UART5_RX = 8ul, }; 
    };

    struct PD3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { FSMC_CLK = 12ul,  USART2_CTS = 7ul, }; 
    };

    struct PD4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { FSMC_NOE = 12ul,  USART2_RTS = 7ul, }; 
    };

    struct PD5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { FSMC_NWE = 12ul,  USART2_TX = 7ul, }; 
    };

    struct PD6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { FSMC_NWAIT = 12ul,  USART2_RX = 7ul, }; 
    };

    struct PD7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { FSMC_NCE2 = 12ul,  FSMC_NE1 = 12ul,  USART2_CK = 7ul, }; 
    };

    struct PD8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { FSMC_D13 = 12ul,  FSMC_DA13 = 12ul,  USART3_TX = 7ul, }; 
    };

    struct PD9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::D; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { FSMC_D14 = 12ul,  FSMC_DA14 = 12ul,  USART3_RX = 7ul, }; 
    };

    struct PE0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { DCMI_D2 = 13ul,  FSMC_NBL0 = 12ul,  TIM4_ETR = 2ul, }; 
    };

    struct PE1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { DCMI_D3 = 13ul,  FSMC_NBL1 = 12ul, }; 
    };

    struct PE10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { FSMC_D7 = 12ul,  FSMC_DA7 = 12ul,  TIM1_CH2N = 1ul, }; 
    };

    struct PE11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { FSMC_D8 = 12ul,  FSMC_DA8 = 12ul,  TIM1_CH2 = 1ul, }; 
    };

    struct PE12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { FSMC_D9 = 12ul,  FSMC_DA9 = 12ul,  TIM1_CH3N = 1ul, }; 
    };

    struct PE13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { FSMC_D10 = 12ul,  FSMC_DA10 = 12ul,  TIM1_CH3 = 1ul, }; 
    };

    struct PE14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { FSMC_D11 = 12ul,  FSMC_DA11 = 12ul,  TIM1_CH4 = 1ul, }; 
    };

    struct PE15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { FSMC_D12 = 12ul,  FSMC_DA12 = 12ul,  TIM1_BKIN = 1ul, }; 
    };

    struct PE2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { ETH_TXD3 = 11ul,  FSMC_A23 = 12ul,  SYS_TRACECLK = 0ul, }; 
    };

    struct PE3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { FSMC_A19 = 12ul,  SYS_TRACED0 = 0ul, }; 
    };

    struct PE4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { DCMI_D4 = 13ul,  FSMC_A20 = 12ul,  SYS_TRACED1 = 0ul, }; 
    };

    struct PE5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { DCMI_D6 = 13ul,  FSMC_A21 = 12ul,  SYS_TRACED2 = 0ul,  TIM9_CH1 = 3ul, }; 
    };

    struct PE6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { DCMI_D7 = 13ul,  FSMC_A22 = 12ul,  SYS_TRACED3 = 0ul,  TIM9_CH2 = 3ul, }; 
    };

    struct PE7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { FSMC_D4 = 12ul,  FSMC_DA4 = 12ul,  TIM1_ETR = 1ul, }; 
    };

    struct PE8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { FSMC_D5 = 12ul,  FSMC_DA5 = 12ul,  TIM1_CH1N = 1ul, }; 
    };

    struct PE9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::E; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { FSMC_D6 = 12ul,  FSMC_DA6 = 12ul,  TIM1_CH1 = 1ul, }; 
    };

    struct PF0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { FSMC_A0 = 12ul,  I2C2_SDA = 4ul, }; 
    };

    struct PF1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { FSMC_A1 = 12ul,  I2C2_SCL = 4ul, }; 
    };

    struct PF10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { FSMC_INTR = 12ul, }; 
    };

    struct PF11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { DCMI_D12 = 13ul, }; 
    };

    struct PF12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { FSMC_A6 = 12ul, }; 
    };

    struct PF13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { FSMC_A7 = 12ul, }; 
    };

    struct PF14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { FSMC_A8 = 12ul, }; 
    };

    struct PF15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { FSMC_A9 = 12ul, }; 
    };

    struct PF2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { FSMC_A2 = 12ul,  I2C2_SMBA = 4ul, }; 
    };

    struct PF3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { FSMC_A3 = 12ul, }; 
    };

    struct PF4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { FSMC_A4 = 12ul, }; 
    };

    struct PF5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { FSMC_A5 = 12ul, }; 
    };

    struct PF6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { FSMC_NIORD = 12ul,  TIM10_CH1 = 3ul, }; 
    };

    struct PF7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { FSMC_NREG = 12ul,  TIM11_CH1 = 3ul, }; 
    };

    struct PF8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { FSMC_NIOWR = 12ul,  TIM13_CH1 = 9ul, }; 
    };

    struct PF9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::F; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { FSMC_CD = 12ul,  TIM14_CH1 = 9ul, }; 
    };

    struct PG0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { FSMC_A10 = 12ul, }; 
    };

    struct PG1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { FSMC_A11 = 12ul, }; 
    };

    struct PG10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { FSMC_NCE4_1 = 12ul,  FSMC_NE3 = 12ul, }; 
    };

    struct PG11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { ETH_TX_EN = 11ul,  FSMC_NCE4_2 = 12ul, }; 
    };

    struct PG12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { FSMC_NE4 = 12ul,  USART6_RTS = 8ul, }; 
    };

    struct PG13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { ETH_TXD0 = 11ul,  FSMC_A24 = 12ul,  USART6_CTS = 8ul, }; 
    };

    struct PG14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { ETH_TXD1 = 11ul,  FSMC_A25 = 12ul,  USART6_TX = 8ul, }; 
    };

    struct PG15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { DCMI_D13 = 13ul,  USART6_CTS = 8ul, }; 
    };

    struct PG2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { FSMC_A12 = 12ul, }; 
    };

    struct PG3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { FSMC_A13 = 12ul, }; 
    };

    struct PG4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { FSMC_A14 = 12ul, }; 
    };

    struct PG5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { FSMC_A15 = 12ul, }; 
    };

    struct PG6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { FSMC_INT2 = 12ul, }; 
    };

    struct PG7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { FSMC_INT3 = 12ul,  USART6_CK = 8ul, }; 
    };

    struct PG8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { ETH_PPS_OUT = 11ul,  USART6_RTS = 8ul, }; 
    };

    struct PG9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::G; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { FSMC_NCE3 = 12ul,  FSMC_NE2 = 12ul,  USART6_RX = 8ul, }; 
    };

    struct PH0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { RCC_OSC_IN = 0ul, }; 
    };

    struct PH1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { RCC_OSC_OUT = 0ul, }; 
    };

    struct PH10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { DCMI_D1 = 13ul,  TIM5_CH1 = 2ul, }; 
    };

    struct PH11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { DCMI_D2 = 13ul,  TIM5_CH2 = 2ul, }; 
    };

    struct PH12 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 12u; }
      enum { DCMI_D3 = 13ul,  TIM5_CH3 = 2ul, }; 
    };

    struct PH13 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 13u; }
      enum { CAN1_TX = 9ul,  TIM8_CH1N = 3ul, }; 
    };

    struct PH14 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 14u; }
      enum { DCMI_D4 = 13ul,  TIM8_CH2N = 3ul, }; 
    };

    struct PH15 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 15u; }
      enum { DCMI_D11 = 13ul,  TIM8_CH3N = 3ul, }; 
    };

    struct PH2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { ETH_CRS = 11ul, }; 
    };

    struct PH3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { ETH_COL = 11ul, }; 
    };

    struct PH4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { I2C2_SCL = 4ul,  USB_OTG_HS_ULPI_NXT = 10ul, }; 
    };

    struct PH5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { I2C2_SDA = 4ul, }; 
    };

    struct PH6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { ETH_RXD2 = 11ul,  I2C2_SMBA = 4ul,  TIM12_CH1 = 9ul, }; 
    };

    struct PH7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { ETH_RXD3 = 11ul,  I2C3_SCL = 4ul, }; 
    };

    struct PH8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { DCMI_HSYNC = 13ul,  I2C3_SDA = 4ul, }; 
    };

    struct PH9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::H; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { DCMI_D0 = 13ul,  I2C3_SMBA = 4ul,  TIM12_CH2 = 9ul, }; 
    };

    struct PI0  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 0u; }
      enum { DCMI_D13 = 13ul,  I2S2_WS = 5ul,  SPI2_NSS = 5ul,  TIM5_CH4 = 2ul, }; 
    };

    struct PI1  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 1u; }
      enum { DCMI_D8 = 13ul,  I2S2_CK = 5ul,  SPI2_SCK = 5ul, }; 
    };

    struct PI10 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 10u; }
      enum { ETH_RX_ER = 11ul, }; 
    };

    struct PI11 
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 11u; }
      enum { USB_OTG_HS_ULPI_DIR = 10ul, }; 
    };

    struct PI2  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 2u; }
      enum { DCMI_D9 = 13ul,  I2S2_ext_SD = 6ul,  SPI2_MISO = 5ul,  TIM8_CH4 = 3ul, }; 
    };

    struct PI3  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 3u; }
      enum { DCMI_D10 = 13ul,  I2S2_SD = 5ul,  SPI2_MOSI = 5ul,  TIM8_ETR = 3ul, }; 
    };

    struct PI4  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 4u; }
      enum { DCMI_D5 = 13ul,  TIM8_BKIN = 3ul, }; 
    };

    struct PI5  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 5u; }
      enum { DCMI_VSYNC = 13ul,  TIM8_CH1 = 3ul, }; 
    };

    struct PI6  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 6u; }
      enum { DCMI_D6 = 13ul,  TIM8_CH2 = 3ul, }; 
    };

    struct PI7  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 7u; }
      enum { DCMI_D7 = 13ul,  TIM8_CH3 = 3ul, }; 
    };

    struct PI8  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 8u; }
      enum { RTC_AF2 = 0ul, }; 
    };

    struct PI9  
    {
      constexpr inline static auto const Port() noexcept(true) { return Port::I; }
	  constexpr inline static std::uint32_t const Pin()  noexcept(true) { return 9u; }
      enum { CAN1_RX = 9ul, }; 
    };
    
  } // inline namespace 
} // namespace mpp::gpio 
 