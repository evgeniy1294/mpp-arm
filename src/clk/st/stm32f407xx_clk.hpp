/**
***********************************************************
  @author Evgenii Fedoseev
  @file   /src/clk/st/stm32f407xx_clk.hpp
  @brief  STM32F407xx clocking system interface 
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "stm32f407xx.h"


namespace mpp::clk
{
  inline namespace stm32f407xx
  {
    constexpr std::uint32_t kHsiFrequencyHz = 16'000'000u;  
    constexpr std::uint32_t kLsiFrequencyHz = 32'000;
      
    enum class PllClkSource    { hsi = 0b0u, hse = 0b1u };
    enum class SystemClkSource { hsi = 0b00u, hse = 0b01u, pll = 0b10u };
    enum class RtcClkSource    { hse = 0b11u, lse = 0b01u, lsi = 0b10u, none = 0b00u };
    enum class I2SClkSource    { plli2s = 0b0u, external = 0b1, none };
    enum class Mco2Source      { sysclk = 0b00u, plli2s = 0b01u, hse = 0b10u, pllclk = 0b11, none };
    enum class Mco1Source      { lse = 0b01u, hse = 0b10u, hsi = 0b00u, pllclk = 0b11u, none };  
      
      
      
    struct ClkTraitExample {
      constexpr static std::uint32_t kHseFrequencyHz = 20'000'000u;
      constexpr static std::uint32_t kLseFrequencyHz = 32'768u;
      constexpr static SystemClkSource kSystemClkSource = SystemClkSource::pll;
      constexpr static PllClkSource kPllClkSource = PllClkSource::hse;
      constexpr static RtcClkSource kRtcClkSource = RtcClkSource::lse;
      constexpr static I2SClkSource kI2SClkSource = I2SClkSource::none;
      constexpr static std::uint32_t kPllM = 20u;
      constexpr static std::uint32_t kPllN = 336u;
      constexpr static std::uint32_t kPllP = 2u;
      constexpr static std::uint32_t kPllQ = 4u;
      constexpr static std::uint32_t kI2SPllN = 0u;
      constexpr static std::uint32_t kI2SPllR = 0u;
      constexpr static std::uint32_t kAhbPrescaler  = 1u;
      constexpr static std::uint32_t kApb1Prescaler = 4u;
      constexpr static std::uint32_t kApb2Prescaler = 2u;
      constexpr static std::uint32_t kSystickPrescaler = 1u;
      constexpr static std::uint32_t kRtcHsePrescaler = 0u;
      constexpr static bool kClockSecuritySystem = false;
      constexpr static Mco2Source kMco2Source = Mco2Source::none;
      constexpr static Mco1Source kMco1Source = Mco1Source::none;
      constexpr static std::uint32_t kMco2Prescaler = 1u;
      constexpr static std::uint32_t kMco1Prescaler = 1u;
    };
        
    
      
      
    template < class Trait, class Flash, class PowerProfile >
    class ClockSystem final {
      private:
		
		
        constexpr static bool IsTraitValid() {                  
          // Check HSE value
          if constexpr ( (Trait::kPllClkSource == PllClkSource::hse)||(Trait::kSystemClkSource == SystemClkSource::hse)||
                         (Trait::kRtcClkSource == RtcClkSource::hse) )
          {
            static_assert( (Trait::kHseFrequencyHz >= 4'000'000u)&&(Trait::kHseFrequencyHz <= 26'000'000),
                           "kHseFrequencyHz value must be from 4 to 26 MHz" );  
          }
          else
          {
            static_assert( Trait::kHseFrequencyHz == 0u, "kHseFrequencyHz value must be 0 if unused" );  
          }
            
            
          // Check LSE value
          if constexpr ( Trait::kRtcClkSource == RtcClkSource::lse )
            static_assert( Trait::kLseFrequencyHz == 32'768u );
          else
            static_assert( Trait::kLseFrequencyHz == 0u );
            
          if constexpr (Trait::kRtcClkSource == RtcClkSource::hse) 
            static_assert( (kRtcHsePrescaler >= 2u) && (kRtcHsePrescaler <= 31u),
                           "RTC HSE prescaler must be from 2 to 31" );
          else
            static_assert( kRtcHsePrescaler == 0u, "RTC HSE prescaler must be 0 if unused");
			
          
          // Check main pll
          if constexpr ( (Trait::kSystemClkSource == SystemClkSource::pll) ||  
                         (Trait::kI2SClkSource == I2SClkSource::plli2s) )
          {
            static_assert( (Trait::kPllM >= 2u)&&(Trait::kPllM <= 63u), "PLLM value must be from 2 to 63" );
            static_assert( (Trait::kPllN >= 50u)&&(Trait::kPllN <= 432u), "PLLN value must be from 50 to 432" );
            static_assert( (Trait::kPllP == 2u)||(Trait::kPllP == 4u)||
                           (Trait::kPllP == 6u)||(Trait::kPllP == 8u), "PLLP value must be equal 2, 4, 6, 8" );
            static_assert( ((Trait::kPllQ >= 2u)&&(Trait::kPllQ <= 15u))||(Trait::kPllQ == 0), 
                           "PLLQ value must be from 2 to 15, or 0 if unused" );
          }
          else
          {
            static_assert( Trait::kPllM == 0u, "PLLM value must be 0 if unused" );  
            static_assert( Trait::kPllN == 0u, "PLLN value must be 0 if unused" );
            static_assert( Trait::kPllP == 0u, "PLLP value must be 0 if unused" );
            static_assert( Trait::kPllQ == 0u, "PLLQ value must be 0 if unused" );
          }
            

          // Check PLLI2S
          if constexpr (Trait::kI2SClkSource == I2SClkSource::plli2s)
          {
            static_assert( (Trait::kI2SPllN >= 50u)&&(Trait::kI2SPllN <= 432u),
                           "I2S PLLN value must be from 50 to 432" );
            static_assert( (Trait::kI2SPllR >= 2u)&&(Trait::kI2SPllR <= 7u),
                           "I2S PLLR value must be from 2 to 7" );                       
          } else 
          {
            static_assert( Trait::kI2SPllN == 0u, "I2S PLLN must be equal 0 if unused" );           
            static_assert( Trait::kI2SPllR == 0u, "I2S PLLR must be equal 0 if unused" );  
          }
            
          
          // Check Bus Prescalers
          static_assert( (Trait::kAhbPrescaler == 1u)   || (Trait::kAhbPrescaler == 2u)  ||
                         (Trait::kAhbPrescaler == 4u)   || (Trait::kAhbPrescaler == 8u)  ||
                         (Trait::kAhbPrescaler == 16u)  || (Trait::kAhbPrescaler == 64u) ||
                         (Trait::kAhbPrescaler == 128u) || (Trait::kAhbPrescaler == 256u)||
                         (Trait::kAhbPrescaler == 512u),
                         "AHB prescaler must be equal 1,2,4,8,16,64,128,256 or 512" );
            
          static_assert( (Trait::kApb1Prescaler == 1u) || (Trait::kApb1Prescaler == 2u) ||
                         (Trait::kApb1Prescaler == 4u) || (Trait::kApb1Prescaler == 8u) ||
                         (Trait::kApb1Prescaler == 16u), "APB1 prescaler must be equal 1,2,4,8,16" );
            
          static_assert( (Trait::kApb2Prescaler == 1u) || (Trait::kApb2Prescaler == 2u) ||
                         (Trait::kApb2Prescaler == 4u) || (Trait::kApb2Prescaler == 8u) ||
                         (Trait::kApb2Prescaler == 16u), "APB1 prescaler must be equal 1,2,4,8,16" );

          // Check MCO Prescalers
          static_assert( (Trait::kMco1Prescaler > 0u)&&(Trait::kMco1Prescaler < 6u), 
                         "MCO Prescaler must be equal 1,2,3,4 or 5" );

          static_assert( (Trait::kMco2Prescaler > 0u)&&(Trait::kMco2Prescaler < 6u), 
                         "MCO Prescaler must be equal 1,2,3,4 or 5" );
                          
          if constexpr (Trait::kClockSecuritySystem)
            static_assert(Trait::kSystemClkSource != SystemClkSource::hsi);
              
          return true;
        }
        
        static_assert( IsTraitValid(), "Trait is incorrect" );
		
		
		
		
        
      public:
        constexpr static std::uint32_t kHseFrequencyHz = Trait::kHseFrequencyHz;
        constexpr static std::uint32_t kLseFrequencyHz = Trait::kLseFrequencyHz;
        constexpr static SystemClkSource kSystemClkSource = Trait::kSystemClkSource;
        constexpr static PllClkSource kPllClkSource = Trait::kPllClkSource;
        constexpr static RtcClkSource kRtcClkSource = Trait::kRtcClkSource;
        constexpr static I2SClkSource kI2SClkSource = Trait::kI2SClkSource;
        constexpr static std::uint32_t kPllM = Trait::kPllM;
        constexpr static std::uint32_t kPllN = Trait::kPllN;
        constexpr static std::uint32_t kPllP = Trait::kPllP;
        constexpr static std::uint32_t kPllQ = Trait::kPllQ;
        constexpr static std::uint32_t kI2SPllN = Trait::kI2SPllN;
        constexpr static std::uint32_t kI2SPllR = Trait::kI2SPllR;
        constexpr static std::uint32_t kAhbPrescaler  = Trait::kAhbPrescaler;
        constexpr static std::uint32_t kApb1Prescaler = Trait::kApb1Prescaler;
        constexpr static std::uint32_t kApb2Prescaler = Trait::kApb2Prescaler;
        constexpr static std::uint32_t kSystickPrescaler = Trait::kSystickPrescaler;
		constexpr static std::uint32_t kRtcHsePrescaler = Trait::kRtcHsePrescaler;
        constexpr static bool kClockSecuritySystem = Trait::kClockSecuritySystem;
        constexpr static Mco2Source kMco2Source = Trait::kMco2Source;
        constexpr static Mco1Source kMco1Source = Trait::kMco1Source;
        constexpr static std::uint32_t kMco2Prescaler = Trait::kMco2Prescaler;
        constexpr static std::uint32_t kMco1Prescaler = Trait::kMco1Prescaler;
        
		
		
        constexpr static std::uint32_t kSysClkHz = []() -> std::uint32_t {
          switch(kSystemClkSource)
          {
            case SystemClkSource::pll: {
              constexpr std::uint64_t PllMOutput = (((kPllClkSource == PllClkSource::hsi) ? 
                static_cast< std::uint64_t >(kHsiFrequencyHz) :
                static_cast< std::uint64_t >(kHseFrequencyHz))*1000u) / kPllM;
              static_assert( (PllMOutput >= 950'000'000u)&&(PllMOutput <= 2'100'000'000u), 
                             "PLLM output must be from 0.95MHz to 2.1MHz" );
              
              constexpr std::uint64_t PllNOutput = PllMOutput * kPllN;
              static_assert( (PllNOutput >= 100'000'000'000u)&&(PllNOutput <= 432'000'000'000u), 
                             "PLLN output must be from 100MHz to 432MHz" );

              constexpr std::uint64_t PllPOutput = PllNOutput / kPllP;
              static_assert( (PllPOutput >= 24'000'000'000u)&&(PllPOutput <= 168'000'000'000u), 
                              "PLLP output must be from 24MHz to 168MHz" );
      
              return static_cast< std::uint32_t >( PllPOutput / 1000u );
          }
      
          case SystemClkSource::hse:  
            return kHseFrequencyHz;

          default:
            return kHsiFrequencyHz; 
        } } ();
    
		
		
		
		
        constexpr static std::uint32_t kAhbClkHz = kSysClkHz / kAhbPrescaler;
        constexpr static std::uint32_t kSysTickClkHz = kAhbClkHz / kSystickPrescaler;
        static_assert( kAhbClk >= 14'200'000u, "AHB Clock must be greater 14.2MHz" );  
        
        constexpr static std::uint32_t kApb1ClkHz = kAhbClkHz / kApb1Prescaler;
        constexpr static std::uint32_t kApb1TimClkHz = (kApb1Prescaler == 1u) ? kApb1ClkHz : kApb1ClkHz * 2u;  
        static_assert( kApb1Clk <= 42'000'000u, "APB1 Clock must be less or equal 42MHz" );
        
        constexpr static std::uint32_t kApb2ClkHz = kAhbClkHz / kApb2Prescaler;
        constexpr static std::uint32_t kApb2TimClkHz = (kApb2Prescaler == 1u) ? kApb2ClkHz : kApb2ClkHz * 2u;  
        static_assert( kApb2Clk <= 84'000'000u, "APB2 Clock must be less or equal 84MHz" );
        
        
        constexpr static std::uint32_t k48ClkHz = []() -> std::uint32_t {
          if constexpr (kPllQ != 0)
          {
            constexpr std::uint64_t PllMOutput = (((kPllClkSource == PllClkSource::hsi) ? 
            static_cast< std::uint64_t >(kHsiFrequencyHz) :
            static_cast< std::uint64_t >(kHseFrequencyHz))*1000u) / kPllM;
       
              
            constexpr std::uint64_t PllNOutput = PllMOutput * kPllN;
            constexpr std::uint64_t PllQOutput = PllNOutput / kPllQ;
            static_assert( (PllQOutput >= 47'880'000'000u)&&(PllQOutput <= 48'120'000'000u),
                           "48Mhz clock must be from 47.88MHz to 48.12MHz");

            return static_cast< std::uint32_t >( PllQOutput / 1000u );
          } 
          else
            return 0u;
      } ();
        
		
		
        
      constexpr static std::uint32_t kI2SClkHz = []() -> std::uint32_t {
        if constexpr (kI2SClkSource == I2SClkSource::plli2s) {
          constexpr std::uint64_t PllMOutput = (((kPllClkSource == PllClkSource::hsi) ? 
          static_cast< std::uint64_t >(kHsiFrequencyHz) :
          static_cast< std::uint64_t >(kHseFrequencyHz))*1000u) / kPllM;

          constexpr std::uint64_t PllNOutput = PllMOutput * kI2SPllN;
          static_assert( (PllNOutput >= 100'000'000'000u)&&(PllNOutput <= 432'000'000'000u), 
                         "PLL_I2S_N output must be from 100MHz to 432MHz" );
            
          constexpr std::uint64_t PllROutput = PllNOutput / kI2SPllR;
          static_assert( PllROutput <= 216'000'000'000,
                         "PLL_I2S_R output must be less or equal 216MHz" );

          return static_cast< std::uint32_t >( PllROutput / 1000u );
        }
        else
          return 0u;
      } ();
        
        
		
		
		
      constexpr static std::uint32_t kRtcClkHz = []() -> std::uint32_t {
        if constexpr (kRtcClkSource == RtcClkSource::hse)
          return kHseFrequencyHz / kRtcHsePrescaler;
        else if constexpr (kRtcClkSource == RtcClkSource::lse)
          return kLseFrequencyHz;
        else
          return kLsiFrequencyHz;
      } ();
      static_assert( kRtcClk <= 1'000'000u, "RTC clock must be less or equal 1MHz" );

		
		
		

      constexpr static std::uint32_t kCrInit0 = RCC_CR_HSION | RCC_CR_HSITRIM_0;
      constexpr static std::uint32_t kCrInit1 =  ((kHseFrequencyHz != 0u) ? RCC_CR_HSEON : 0u) |
                                                 ((kClockSecuritySystem)  ? RCC_CR_CSSON : 0u) |
                                                 ((kSystemClkSource == SystemClkSource::pll) ? RCC_CR_PLLON : 0u) |
                                                 ((kI2SClkSource == I2SClkSource::plli2s) ? RCC_CR_PLLI2SON : 0u) | kCrInit0;                        

		
		
		
      constexpr static std::uint32_t kPllcfgrInit = []() -> std::uint32_t {
        std::uint32_t ret = ( kPllQ << RCC_PLLCFGR_PLLQ_Pos ) |
                            ( ((kPllP-1)>>1) << RCC_PLLCFGR_PLLP_Pos ) |
                            ( kPllN << RCC_PLLCFGR_PLLN_Pos ) |
                            ( kPllM << RCC_PLLCFGR_PLLM_Pos ) | 
                            0x2000'0000 /* Keep reserved bit */;
 
        if constexpr ( kPllClkSource == PllClkSource::hse )
          ret |= RCC_PLLCFGR_PLLSRC_HSE;
          
        return ret;
      } ();

		
		
      constexpr static std::uint32_t kCfgrInit = []() -> std::uint32_t {
        std::uint32_t ret = ( static_cast< std::uint32_t >(kSystemClkSource) << RCC_CFGR_SW_Pos ) |
                            ( kRtcHsePrescaler << RCC_CFGR_RTCPRE_Pos );
		  
		if constexpr (kMco1Prescaler != 1u)
          ret |= (kMco1Prescaler + 2u) << RCC_CFGR_MCO1PRE_Pos;

        if constexpr (kMco2Prescaler != 1u)
          ret |= (kMco2Prescaler + 2u) << RCC_CFGR_MCO2PRE_Pos;
		  
        if constexpr (kMco1Source != Mco1Source::none)
		  ret |= static_cast< std::uint32_t >(kMco1Source) << RCC_CFGR_MCO1_Pos;
		  
		if constexpr (kMco2Source != Mco2Source::none)
		  ret |= static_cast< std::uint32_t >(kMco2Source) << RCC_CFGR_MCO2_Pos;

        if constexpr (kI2SClkSource == I2SClkSource::external)
          ret |= RCC_CFGR_I2SSRC;
		  
			
        ret |= []() -> std::uint32_t {
          switch(kAhbPrescaler)
		  {
			case 2u:   return RCC_CFGR_HPRE_DIV2;
            case 4u:   return RCC_CFGR_HPRE_DIV4;
            case 8u:   return RCC_CFGR_HPRE_DIV8;
			case 16u:  return RCC_CFGR_HPRE_DIV16;
            case 64u:  return RCC_CFGR_HPRE_DIV64;
            case 128u: return RCC_CFGR_HPRE_DIV128;
            case 256u: return RCC_CFGR_HPRE_DIV256;
			case 512u: return RCC_CFGR_HPRE_DIV512;
			default:   return RCC_CFGR_HPRE_DIV1;
		  }
		} ();
		  
        ret |= []() -> std::uint32_t {
          switch(kApb1Prescaler)
		  {
			case 2u:  return RCC_CFGR_PPRE1_DIV2;
			case 4u:  return RCC_CFGR_PPRE1_DIV4;
			case 8u:  return RCC_CFGR_PPRE1_DIV8;
            case 16u: return RCC_CFGR_PPRE1_DIV16;
			default:  return RCC_CFGR_PPRE1_DIV1;	  
		  }
		} ();

		  
        ret |= []() -> std::uint32_t {
          switch(kApb2Prescaler)
		  {
			case 2u:  return RCC_CFGR_PPRE2_DIV2;
			case 4u:  return RCC_CFGR_PPRE2_DIV4;
			case 8u:  return RCC_CFGR_PPRE2_DIV8;
            case 16u: return RCC_CFGR_PPRE2_DIV16;
			default:  return RCC_CFGR_PPRE2_DIV1;
		  }
		} ();
		  
		return ret;  
      } ();

		  
      constexpr static std::uint32_t kPlli2sInit = (kI2SPllN << RCC_PLLI2SCFGR_PLLI2SN_Pos) |
                                                   (kI2SPllR << RCC_PLLI2SCFGR_PLLI2SR_Pos);  
		  
      inline static void Init() {
        RCC->CR = kCrInit0;
		  
        RCC->PLLCFGR = kPllcfgrInit;
        if constexpr (kPlli2sInit != 0u)
          RCC->PLLI2S = kPlli2sInit; 
		  
        RCC->CR = kCrInit1;
		  
        Flash::Init();
        RCC->CFGR = kCfgrInit;
		  
        return;
      }
        
    };
        
      

  }
} // namepsace mpp::clk


