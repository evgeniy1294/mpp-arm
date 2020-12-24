/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /bsp/stm32f407g_disco/bsp.hpp
  @brief  Compatible board stm32g071-nucleo 
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "mpp/stm32g071xx.hpp"


int main();


namespace bsp
{
  // Systick
  struct FakeClk {
    constexpr static std::uint32_t kSysClkHz     = 16'000'000u;
    constexpr static std::uint32_t kSysTickClkHz = 16'000'000u; 
  };

  using Systick = mpp::core::Systick < FakeClk >;
    
	
	
	
  // Leds
  struct LedTrait final: mpp::gpio::LedTrait
  {
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
    
  using LedGreen  = mpp::gpio::Gpio < mpp::gpio::PA5, LedTrait >;  

  using Leds = mpp::gpio::IoGroup < LedGreen >;
	
	
	
	
  // Specific function 
  void Init();
  bool TestSequenceCheck();
  bool TestSequencePartCheck();
  void ErrorSignal();
  void OkSignal();
	
	
	
    
} // namespace bsp




