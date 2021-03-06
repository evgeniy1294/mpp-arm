#include "bsp.hpp"



std::array<std::uint32_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};


void bsp::Init()
{
  RCC->AHBENR  |= RCC_AHBENR_CRCEN;
  RCC->APB2ENR |= RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPBEN | RCC_APB2ENR_IOPCEN;
  
  Systick::Init();
  LedGreen::Init();
  LedGreen::Reset();
    
  return;
}






bool bsp::TestSequenceCheck()
{
  using namespace mpp::crc;
  volatile std::uint32_t crc = 0;

  HardwareLogic::Reset(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.size());
  crc = HardwareLogic::Finalize(CRC); 
	  
  if (crc != 0x1556f485)
    return false;
  
  return true;  
}







void bsp::ErrorSignal() {
  LedGreen::Reset();  
}





void bsp::OkSignal() {
  LedGreen::Set();  
}

