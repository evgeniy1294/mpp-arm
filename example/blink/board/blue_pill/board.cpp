#include "board.hpp"


void board::Init()
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}

