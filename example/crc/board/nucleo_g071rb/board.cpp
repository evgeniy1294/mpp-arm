#include "board.hpp"


void board::Init()
{
  RCC->AHBENR |= RCC_AHBENR_CRCEN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}

