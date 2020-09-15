/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file  /src/crypto/st/stgpiof4.hpp
  @brief   Compatible series: STM32F4 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>



namespace mpp::crypto
{
  inline  namespace f4 
  {
    class Crc32
    {
      public:
        constexpr static std::uint32_t kPolynominal = 0x04C1'1DB7u;
        
        inline static void Reset() noexcept(true) { CRC->CR = CRC_CR_RESET; } 
        
        template< typename T >
        static std::uint32_t Calculate(const T* first, const T* last, bool reset) noexcept(true)
        {
          std::size_t SzInByte = (last - first) * sizeof(T);
          const std::uint32_t* fu32 = reinterpret_cast< const std::uint32_t* >(first);
          const std::uint32_t* lu32 = fu32 + ( SzInByte >> 2u );
          
          if (reset)
            Reset();
          
          while ( fu32 != lu32 )
            CRC->DR = *fu32++;
          
          if constexpr ( (sizeof(T) % 4u) != 0u )
          {
            std::uint32_t TailByte = SzInByte & 0b11u;
            
            if ( TailByte != 0u ) {
              std::uint32_t tmp = *lu32 & (~(0xFFFF'FFFFu << (TailByte << 3u))); 
              CRC->DR = tmp; 
            }
          }
          
          return CRC->DR;
      }
    }; 
  } //  inline namespace 
} // namespace mpp::crypto
