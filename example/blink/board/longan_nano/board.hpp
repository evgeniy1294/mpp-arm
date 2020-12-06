/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /board/longan_nano/board.hpp
  @brief  Compatible board: longan nano
  ***********************************************************
**/

#pragma once


//____________________INCLUDE_____________________//
#include <cstdint>
#include "mpp/gd32vf103.hpp"


int main();


namespace board
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
    constexpr static mpp::gpio::Inversion kInversion = mpp::gpio::Inversion::Off;
  };
    

  using LedRed   = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::C, 13 >,  LedTrait >;  
  using LedGreen = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::A, 1  >,  LedTrait >;  
  using LedBlue  = mpp::gpio::Gpio < mpp::gpio::IO< mpp::gpio::Port::A, 2  >,  LedTrait >;  
	
	
  using Leds = mpp::gpio::IoSet < LedRed, LedGreen, LedBlue >;
	
	
  // Specific function 
  void Init();
    
} // namespace board
