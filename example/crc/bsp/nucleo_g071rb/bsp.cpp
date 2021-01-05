#include "bsp.hpp"

// Checksum models
std::array<std::uint8_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};



void bsp::Init()
{
  RCC->AHBENR |= RCC_AHBENR_CRCEN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  RCC->IOPSMENR |= RCC_IOPSMENR_GPIOASMEN;
  
  Systick::Init();
  Leds::Init();
	
  return;
}




bool bsp::TestSequenceCheck()
{
  using namespace mpp::crc;
  volatile std::uint32_t crc = 0;

  // [ Name: Posix32, Poly = 0x4C11DB7, Seed = 0x00, XorOut = 0xFFFFFFFF, RefIn = false, RefOut = false, Check = 0x765E7680 ] 
  HardwareLogic::Configure< POSIX_32 >(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != POSIX_32::kCheck)
    return false;

  // Part test
  HardwareLogic::Calculate(CRC, TestSequence.data() , TestSequence.data() + 5);
  HardwareLogic::Calculate(CRC, TestSequence.data() + 5, TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != POSIX_32::kCheck)
    return false;


  // [ Name: ZLib, Poly = 0x4C11DB7, Seed = 0xFFFFFFFF, XorOut = 0xFFFFFFFF, RefIn = true, RefOut = true, Check = 0xCBF43926 ]
  HardwareLogic::Configure< ZLIB_32 >(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != ZLIB_32::kCheck)
    return false; 


  // [ Name: CRC16 Modbus, Poly = 0x8005, Seed = 0xFFFF, XorOut = 0x0000, RefIn = true, RefOut = true, Check = 0x4B37 ]
  HardwareLogic::Configure< MODBUS_16 >(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != MODBUS_16::kCheck)
    return false; 
  

  // [ Name: CRC8 CDMA2000, Poly = 0x9B, Seed = 0xFF, XorOut = 0x00, RefIn = false, RefOut = false, Check = 0xDA ]
  HardwareLogic::Configure< CDMA2000_8 >(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != CDMA2000_8::kCheck)
    return false; 
  
  
  // [ Name: CRC7, Poly = 0x09, Seed = 0x00, XorOut = 0x00, RefIn = false, RefOut = false, Check = 0x75 ]
  HardwareLogic::Configure< CRC_7 >(CRC);
  HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
  crc = HardwareLogic::Finalize(CRC);
  
  if (crc != CRC_7::kCheck)
    return false; 
  
  
  // Test complete!!!
  return true;
}







void bsp::ErrorSignal() {
  LedGreen::Reset();	
}





void bsp::OkSignal() {
  LedGreen::Set();	
}






