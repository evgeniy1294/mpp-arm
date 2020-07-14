/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/spec/gpio401.hpp
  @brief  Сompatibility with target: STM32F401xx          
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>
#include "target.h"
 


namespace mpp::gpio
{
  inline namespace gpio401
  {
	enum class Port
	{
	  A = GPIOA_BASE,
      B = GPIOB_BASE,
      C = GPIOC_BASE,
      D = GPIOD_BASE,
      E = GPIOE_BASE,
      H = GPIOH_BASE
	};
	  
	 
	namespace Af 
	{  
      // PORT A		
	  namespace PA0  { enum { TIM2_CH1  = 1ul, TIM2_ETR   = 1ul, TIM5_CH1   = 2ul, USART2_CTS  = 7ul }; }
	  namespace PA1  { enum { TIM2_CH2  = 1ul, TIM5_CH2   = 2ul, USART2_RTS = 7ul }; }
	  namespace PA2  { enum { TIM2_CH3  = 1ul, TIM5_CH3   = 2ul, TIM9_CH1   = 3ul, USART2_TX   = 7ul }; }
	  namespace PA3  { enum { TIM2_CH4  = 1ul, TIM5_CH4   = 2ul, TIM9_CH2   = 3ul, USART2_RX   = 4ul }; }
	  namespace PA4  { enum { SPI1_NSS  = 5ul, SPI3_NSS   = 6ul, I2S3_WS    = 6ul, USART2_CK   = 7ul }; }
      namespace PA5  { enum { TIM2_CH1  = 1ul, TIM2_ETR   = 1ul, SPI1_SCK   = 5ul }; }
	  namespace PA6  { enum { TIM1_BKIN = 1ul, TIM3_CH1   = 2ul, SPI1_MISO  = 5ul }; }
	  namespace PA7  { enum { TIM1_CH1N = 1ul, TIM3_CH2   = 2ul, SPI1_MOSI  = 5ul }; }
	  namespace PA8  { enum { MCO_1     = 0ul, TIM1_CH1   = 1ul, I2C3_SCL   = 4ul, USART1_CK   = 7ul, OTG_FS_SOF = 10ul }; }
      namespace PA9  { enum { TIM1_CH2  = 1ul, I2C3_SMBA  = 4ul, USART1_TX  = 7ul, OTG_FS_VBUS = 10ul }; }
	  namespace PA10 { enum { TIM1_CH3  = 1ul, USART1_RX  = 7ul, OTG_FS_ID  = 10ul }; }
      namespace PA11 { enum { TIM1_CH4  = 1ul, USART1_CTS = 7ul, USART6_TX  = 8ul, OTG_FS_DM   = 10ul }; }
	  namespace PA12 { enum { TIM1_ETR  = 1ul, USART1_RTS = 7ul, USART6_RX  = 8ul, OTG_FS_DP   = 10ul }; }
	  namespace PA13 { enum { JTMS      = 0ul, SWDIO      = 0ul }; }
      namespace PA14 { enum { JTCK      = 0ul, SWCLK      = 0ul }; }
      namespace PA15 { enum { JTDI      = 0ul, TIM2_CH1   = 1ul, TIM2_ETR   = 1ul, SPI1_NSS    = 5ul, SPI3_NSS = 6ul,   I2S3_WS = 6ul }; }
	
		
      // PORT B
      namespace PB0  { enum { TIM1_CH2N = 1ul, TIM3_CH3   = 2ul }; }
      namespace PB1  { enum { TIM1_CH3N = 1ul, TIM3_CH4   = 2ul }; }
      namespace PB2  {}
      namespace PB3  { enum { JTDO      = 0ul, SWO        = 0ul, TIM2_CH2   = 1ul, SPI1_SCK  = 5ul, SPI3_SCK   = 6ul, I2S3_CK  = 6ul, I2C2_SDA = 9ul }; }
      namespace PB4  { enum { JTRST     = 0ul, TIM3_CH1   = 2ul, SPI1_MISO  = 5ul, SPI3_MISO = 6ul, I2S3ext_SD = 7ul, I2C3_SDA = 9ul }; }
      namespace PB5  { enum { TIM3_CH2  = 2ul, I2C1_SMBA  = 4ul, SPI1_MOSI  = 5ul, SPI3_MOSI = 6ul, I2S3_SD    = 6ul }; }
      namespace PB6  { enum { TIM4_CH1  = 2ul, I2C1_SCL   = 4ul, USART1_TX  = 7ul }; }
      namespace PB7  { enum { TIM4_CH2  = 2ul, I2C1_SDA   = 4ul, USART1_RX  = 7ul }; }
      namespace PB8  { enum { TIM4_CH3  = 2ul, TIM10_CH1  = 3ul, I2C1_SCL   = 4ul, SDIO_D4   = 12ul }; }
      namespace PB9  { enum { TIM4_CH4  = 2ul, TIM11_CH1  = 3ul, I2C1_SDA   = 4ul, SPI2_NSS  = 5ul, I2S2_WS    = 5ul, SDIO_D5  = 12ul }; }
      namespace PB10 { enum { TIM2_CH3  = 1ul, I2C2_SCL   = 4ul, SPI2_SCK   = 5ul, I2S2_CK   = 5ul }; }
      namespace PB11 { enum { TIM2_CH4  = 1ul, I2C2_SDA   = 4ul }; }
      namespace PB12 { enum { TIM1_BKIN = 1ul, I2C2_SMBA  = 4ul, SPI2_NSS   = 5ul, I2S2_WS   = 5ul }; }
      namespace PB13 { enum { TIM1_CH1N = 1ul, SPI2_SCK   = 5ul, I2S2_CK    = 5ul }; }
      namespace PB14 { enum { TIM1_CH2N = 1ul, SPI2_MISO  = 5ul, I2S2ext_SD = 6ul }; }
      namespace PB15 { enum { RTC_REFN  = 0ul, TIM1_CH3N  = 1ul, SPI2_MOSI  = 5ul, I2S2_SD   = 5ul }; }
		
		
      // PORT C
	  namespace PC0 {}
      namespace PC1 {}
      
		
	} // namespace Af
  } // inline namespace gpio401
} // namespace mpp::gpio 
