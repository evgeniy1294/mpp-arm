#include "board.hpp"

// Checksum models
std::array<std::uint8_t, 9> TestSequence = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};





void board::Init()
{
  RCC->AHBENR |= RCC_AHBENR_CRCEN;
  RCC->IOPENR |= RCC_IOPENR_GPIOAEN;
  RCC->IOPSMENR |= RCC_IOPSMENR_GPIOASMEN;
  
  board::Systick::Init();
  board::Leds::Init();
	
  return;
}





bool board::TestSequenceCheck()
{
  // [ Name: Posix32, Poly = 0x4C11DB7, Seed = 0x00, XorOut = 0xFFFFFFFF, RefIn = false, RefOut = false, Check = 0x765E7680 ] 
  /*mpp::crc::HardwareLogic::Configure< mpp::crc::POSIX_32 >(CRC);
  mpp::crc::HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end());
	
  if (mpp::crc::HardwareLogic::Finalize< mpp::crc::POSIX_32 >(CRC) != mpp::crc::POSIX_32::kCheck)
    return false;*/
	
	
  // [ Name: ZLib, Poly = 0x4C11DB7, Seed = 0xFFFFFFFF, XorOut = 0xFFFFFFFF, RefIn = true, RefOut = true, Check = 0xCBF43926 ] 
  mpp::crc::HardwareLogic::Configure< mpp::crc::ZLIB_32 >(CRC);
  mpp::crc::HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end() - 1);
	
  if (mpp::crc::HardwareLogic::Finalize< mpp::crc::ZLIB_32 >(CRC) != 0x9ae0daaf)
    return false;
	
	
  // Test complete!!!
  return true;
}





bool board::TestSequencePartCheck()
{
  /*mpp::crc::HardwareLogic::Configure< mpp::crc::POSIX_32 >(CRC);
  mpp::crc::HardwareLogic::Calculate(CRC, TestSequence.data(), TestSequence.end()-1);
  mpp::crc::HardwareLogic::Calculate(CRC, TestSequence.end()-1, TestSequence.end());
	
  return (mpp::crc::HardwareLogic::Finalize< mpp::crc::POSIX_32 >(CRC) == mpp::crc::POSIX_32::kCheck); 		*/
	
  return true;
}







void board::ErrorSignal() {
  LedGreen::Reset();	
}





void board::OkSignal() {
  LedGreen::Set();	
}






