#include <array>
#include "board.hpp"

mpp::utils::Timer< board::Systick > tim;
mpp::utils::Timer< board::ClockCounter > dwt;

std::array<std::uint32_t, 12> test = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
std::array<std::uint8_t, 51> test_byte = { 0x00, 0x00, 0x00, 0x00, // 0
                                           0x01, 0x00, 0x00, 0x00, // 1
                                           0x02, 0x00, 0x00, 0x00, // 2
                                           0x03, 0x00, 0x00, 0x00, // 3
                                           0x04, 0x00, 0x00, 0x00, // 4
										   0x05, 0x00, 0x00, 0x00, // 5
										   0x06, 0x00, 0x00, 0x00, // 6
										   0x07, 0x00, 0x00, 0x00, // 7
										   0x08, 0x00, 0x00, 0x00, // 8
										   0x09, 0x00, 0x00, 0x00, // 9
										   0x0A, 0x00, 0x00, 0x00, // 10
										   0x0B, 0x00, 0x00, 0x00, // 11
										   0xDE, 0xAD
										 };



std::uint32_t crc1 = 0;
std::uint32_t crc2 = 0;


int main() {
  tim.Start(100);
	
  // CRC calculate test 1
  crc1 = mpp::crypto::Crc32::Calculate< std::uint32_t >( test.data(), test.end(), true );
  crc2 = mpp::crypto::Crc32::Calculate< std::uint8_t  >( test_byte.data(), test_byte.end(), true );
  
	
  while(1){
    if (tim.IsTimeOut())
    {
      tim.Reload();
      board::Leds::Toggle();
    } 
  } 
}
