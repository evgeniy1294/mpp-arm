/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /bsp/blue_pill/bsp.hpp
  @brief  Compatible board: blue pill
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include "mpp/stm32f103xb.hpp"


int main();


namespace bsp
{
  // Systick and DWT
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 8'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 8'000'000u; 
  };

  using Systick = mpp::core::Systick < FakeClk >;
	
	
	
    
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::On;
  };
    

  using LedGreen  = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::C, 13 >,  LedTrait >;  
	
	
  // Specific function 
  void Init();
  bool TestSequenceCheck();
  void ErrorSignal();
  void OkSignal();
    
} // namespace board
