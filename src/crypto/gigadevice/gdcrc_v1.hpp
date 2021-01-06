/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file  /src/crypto/gigadevice/gdcrc_v1.hpp
  @brief   Compatible series: gd32vf103
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <type_traits>



namespace mpp::crc
{
  inline namespace gdcrc_v1 
  {
      
      
    class HardwareLogic final {
      public:

        inline static void Reset() {
          CRC_CTL = CRC_CTL_RST; 
        }


        inline static std::uint32_t Finalize() noexcept(true)
        {
          std::uint32_t ret = CRC_DATA; 
          CRC_CTL = CRC_CTL_RST; 
        
          return ret;
        }
        
        
        
        static void Calculate( const std::uint32_t* data, const std::uint32_t* end ) 
        noexcept(true)
        {
          while ( data < end )
            CRC_DATA = *data++;
        }
    };




  } //  inline namespace 
} // namespace mpp::crypto
