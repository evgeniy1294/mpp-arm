#include "bsp.hpp"

std::array<std::uint8_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

void bsp::Init()
{
  Eclic::Init<MachineTimerInterrupt>();

  // Настраиваем машинный таймер. Таймер будет переполнятся раз в 1 мс.     
  bsp::Systick::Init();

  //Разрешить прерывание таймера - прерывание номер 7
  MachineTimerInterrupt::Enable();

  // Разрешаем глобальное машинное прерывание 
  mpp::core::MSTATUS::Set( MSTATUS_MIE );

  RCU_APB2EN = RCU_APB2EN | RCU_APB2EN_PAEN | RCU_APB2EN_PCEN;
  RCU_AHBEN  = RCU_AHBEN  | RCU_AHBEN_CRCEN;
  
  bsp::Leds::Init();
  bsp::Leds::Reset();

  return;
}





bool bsp::TestSequenceCheck()
{
  using namespace mpp::crc;
  volatile std::uint32_t crc = 0;

  //HardwareLogic::Reset();
  CRC_CTL = CRC_CTL_RST;
  crc = HardwareLogic::CalculateEther(TestSequence.data(), TestSequence.end());
  
  if (crc != 0xFC891918)
    return false;
  
  return true;  
}







void bsp::ErrorSignal() {
  LedGreen::Reset();  
  LedRed::Set();
}





void bsp::OkSignal() {
  LedGreen::Set();  
  LedRed::Reset();  
}

