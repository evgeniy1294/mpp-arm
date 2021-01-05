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
        
        
        
        template< typename T >
        static void Calculate( CRC_TypeDef* crc, const T* first, const T* last ) noexcept(true)
        {
          static_assert( sizeof(T) % 4 == 0 );
          const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
          
          while ( pu32 < reinterpret_cast<const std::uint32_t*>(last) )
            crc->DR = *pu32++;
        
          return;
        }
        
        


        template< typename T >
        static std::uint32_t CalculateEther( CRC_TypeDef* crc, const T* first, const T* last )
        {
          std::size_t SzInByte = (last - first) * sizeof(T);
          const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
          const std::uint32_t* lu32 = pu32 + ( SzInByte >> 2u );
          
  
          while ( pu32 < lu32 )
            crc->DR = __REV(*pu32++);
            
          std::uint32_t result = __REV(crc->DR);
  
          if constexpr ( (sizeof(T) % 4u) != 0u )
          {
            std::size_t TailByte = SzInByte & 0b11u;
            
            if ( TailByte != 0u ) {
              crc->DR = crc->DR;
            
              switch(TailByte) {
                case 1:
                  crc->DR = __REV((*pu32 & 0xFFu) ^ result) >> 24;
                  result = ( result >> 8 ) ^ __REV(crc->DR);
                  break;
                case 2:
                  crc->DR = __REV((*pu32 & 0xFFFFu) ^ result) >> 16;
                  result = ( result >> 16 ) ^ __REV(crc->DR);
                  break;
                case 3:
                  crc->DR = __REV((*pu32 & 0xFFFFFFu) ^ result) >> 8;
                  result = ( result >> 24 ) ^ __REV(crc->DR);
                break;
              }
            }
          }
  
          crc->CR = CRC_CR_RESET;  // Not used with Finalize
          return ~__REV(result);
        }
    }; 
        
        
        
        
  } //  inline namespace 
} // namespace mpp::crypto
