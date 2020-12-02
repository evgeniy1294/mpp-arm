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



namespace mpp::crc
{
  inline namespace stcrc_v1 
  {
	  
	  
    class HardwareLogic final {
      public:

        inline static std::uint32_t Finalize(CRC_TypeDef* crc) noexcept(true)
        {
          std::uint32_t ret = crc->DR; 
          crc->CR = CRC_CR_RESET; 
        
          return ret;
        }
		
		
		
        template< typename T >
        static void Calculate( CRC_TypeDef* crc, const T* first, const T* last ) noexcept(true)
        {
          std::size_t SzInByte = (last - first) * sizeof(T);
          const std::uint32_t* fu32 = reinterpret_cast< const std::uint32_t* >(first);
          const std::uint32_t* lu32 = fu32 + ( SzInByte >> 2u );
          
          while ( fu32 != lu32 )
            CRC->DR = *fu32++;
          
          if constexpr ( (sizeof(T) % 4u) != 0u )
          {
            std::uint32_t TailByte = SzInByte & 0b11u;
            
            if ( TailByte != 0u ) {
              const std::uint8_t* pu8 = reinterpret_cast< const std::uint8_t* >(lu32);
           
              while ( TailByte-- )  
                crc->DR = *pu8++ << 24;
            
            }
          }
        
        return;
      }
		
		
		
    }; 
		
		
		
		
  } //  inline namespace 
} // namespace mpp::crypto
