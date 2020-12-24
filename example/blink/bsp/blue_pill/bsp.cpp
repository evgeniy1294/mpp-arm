#include "bsp.hpp"


void bsp::Init()
{
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
  
  bsp::Systick::Init();
  bsp::Leds::Init();
	
  return;
}

