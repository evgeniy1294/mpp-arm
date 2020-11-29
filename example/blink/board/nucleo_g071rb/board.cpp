#include "board.hpp"


void board::Init()
{
  RCC->IOPENR   |= RCC_IOPENR_GPIOAEN;
  RCC->IOPSMENR |= RCC_IOPSMENR_GPIOASMEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}

