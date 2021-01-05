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
        
        
        
        template< typename T >
        static void Calculate( const T* first, const T* last ) noexcept(true)
        {
          static_assert( sizeof(T) % 4 == 0 );
          const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
          
          while ( pu32 < reinterpret_cast<const std::uint32_t*>(last) )
            CRC_DATA = *pu32++;
        }
        
        


        template< typename T >
        __attribute__((noinline)) 
        static std::uint32_t CalculateEther( const T* first, const T* last )
        {
          std::size_t SzInByte = (last - first) * sizeof(T);
          const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
          const std::uint32_t* lu32 = pu32 + ( SzInByte >> 2u );
          
  
          while ( pu32 < lu32 )
            CRC_DATA = __builtin_bswap32(*pu32++);
            
          std::uint32_t result = __builtin_bswap32(CRC_DATA);
  
          if constexpr ( (sizeof(T) % 4u) != 0u )
          {
            std::size_t TailByte = SzInByte & 0b11u;
            
            if ( TailByte != 0u ) {
              CRC_DATA = CRC_DATA;
            
              switch(TailByte) {
                case 1:
                  CRC_DATA = __builtin_bswap32((*pu32 & 0xFFu) ^ result) >> 24;
                  result = ( result >> 8 ) ^ __builtin_bswap32(CRC_DATA);
                  break;
                case 2:
                  CRC_DATA = __builtin_bswap32((*pu32 & 0xFFFFu) ^ result) >> 16;
                  result = ( result >> 16 ) ^ __builtin_bswap32(CRC_DATA);
                  break;
                case 3:
                  CRC_DATA = __builtin_bswap32((*pu32 & 0xFFFFFFu) ^ result) >> 8;
                  result = ( result >> 24 ) ^ __builtin_bswap32(CRC_DATA);
                break;
              }
            }
          }
  
          CRC_CTL = CRC_CTL_RST;  // Not used with Finalize
          return ~__builtin_bswap32(result);
        }
    }; 
        
        
        
        
  } //  inline namespace 
} // namespace mpp::crypto
