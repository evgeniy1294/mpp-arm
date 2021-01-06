/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file  /src/crypto/st/stgpiof4.hpp
  @brief   Compatible series: STM32F4, STM32F1
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <type_traits>



namespace mpp::crc
{
  inline namespace stcrc_v1 
  {
      
      
    class HardwareLogic final {
      public:

        inline static void Reset(CRC_TypeDef* crc) {
          crc->CR = CRC_CR_RESET; 
        }


        inline static std::uint32_t Finalize(CRC_TypeDef* crc) noexcept(true)
        {
          std::uint32_t ret = crc->DR; 
          crc->CR = CRC_CR_RESET; 
        
          return ret;
        }
        
        
        
        static void Calculate( CRC_TypeDef* crc, const std::uint32_t* data, const std::uint32_t* end ) 
        noexcept(true)
        {
          while ( data < end )
            crc->DR = *data++;
        }
        
    }; 
        
        
        
        
  } //  inline namespace 
} // namespace mpp::crypto
