#include "board.hpp"


void board::Init()
{
  RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN | RCC_AHB1ENR_CRCEN;
  
  board::Systick::Init();
  board::ClockCounter::Init();
  board::Leds::Init();
	
  return;
}

