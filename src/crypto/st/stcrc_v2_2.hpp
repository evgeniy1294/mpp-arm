/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   src/crypto/st/stcrc_v2_2.hpp
  @brief  Compatible series: 
  ***********************************************************
**/


#pragma once



//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>
#include <limits>




namespace mpp::crc {
  inline namespace stcrc_v2_2 {
    
    
    class HardwareLogic {
	  private:
		
		template < class Model >
        constexpr static bool IsValidModel() noexcept(true) {
          static_assert( ((Model::kWidth == 7 )||
                          (Model::kWidth == 8 )||
                          (Model::kWidth == 16)||
                          (Model::kWidth == 32)), "Field 'Width' is incorrect, must be 7, 8, 16, 32");
         
          return true;
        }
		
		
      public:    
		
        template < class Model >
        static void Configure( CRC_TypeDef* crc ) noexcept(true) {
          static_assert( IsValidModel < Model >(), "This model not supported" );
          
          enum RevIn: std::uint32_t { 
            None     = 0b00 << CRC_CR_REV_IN_Pos,
            Byte     = 0b01 << CRC_CR_REV_IN_Pos,
            HalfWord = 0b10 << CRC_CR_REV_IN_Pos,
            Word     = 0b11 << CRC_CR_REV_IN_Pos
          };
          
          enum Width: std::uint32_t { 
            _32b = 0b00 << CRC_CR_POLYSIZE_Pos,
            _16b = 0b01 << CRC_CR_POLYSIZE_Pos,
            _8b  = 0b10 << CRC_CR_POLYSIZE_Pos,
            _7b  = 0b11 << CRC_CR_POLYSIZE_Pos
          };
              
          
          
          constexpr std::uint32_t CR_REV_OUT = Model::kRefOut ? CRC_CR_REV_OUT : 0 ;
          constexpr std::uint32_t CR_REV_IN  = []() -> std::uint32_t {            
            if (!Model::kRefIn)
              return RevIn::None;
            else switch(Model::kWidth) {
              case 32u:
                return RevIn::Word;
              case 16u:
                return RevIn::HalfWord;
              default:
                return RevIn::Byte;   
            }
          } ();
          
          
          constexpr std::uint32_t CR_POLYSIZE = []() -> std::uint32_t {
            switch (Model::kWidth)
            {
              case 32u:
                return Width::_32b;
              case 16u:
                return Width::_16b;
              case 8u:
                return Width::_8b;
              default:
                return Width::_7b;
            }
          } ();
          
          
          constexpr std::uint32_t CR  = CR_REV_OUT | CR_REV_IN | CR_POLYSIZE;
          constexpr std::uint32_t IDR = (Model::kRefIn ? RevIn::Byte : RevIn::None) | 
                                        CR_REV_OUT | CR_POLYSIZE;
          
          crc->CR   = CR;
          crc->IDR  = IDR;
          crc->INIT = static_cast < std::uint32_t >(Model::kSeed);
          crc->POL  = static_cast < std::uint32_t >(Model::kPoly);
		  crc->CR   = CRC_CR_RESET; 
        }
          
      
      
      
      
      template< typename T >
      static void Calculate( CRC_TypeDef* crc, const T* first, const T* last ) noexcept(true)
      { 
        std::size_t SzInByte = (last - first) * sizeof(T);
        const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
        const std::uint32_t* lu32 = pu32 + ( SzInByte >> 2u );
          
        
        while ( pu32 < lu32 )
          crc->DR = __REV(*pu32++);
        
        
        if constexpr ( (sizeof(T) % 4u) != 0u )
        {
          std::uint32_t TailByte = SzInByte & 0b11u;
            
          if ( TailByte != 0u ) {
            const std::uint8_t* pu8 = reinterpret_cast< const std::uint8_t* >(lu32);

            std::uint32_t tmp = crc->CR;
            crc->CR = crc->IDR;
           
            while ( TailByte-- )  
              *reinterpret_cast< volatile std::uint8_t* >(&crc->DR) = *pu8++;
            
            crc->CR = tmp;
          }
        }
        
        return;
      }
      
		
		
		
		
     
		
      template< typename T >
      static void CalculateByByte( CRC_TypeDef* crc, const T* first, const T* last ) noexcept(true)
      { 
        const std::uint8_t* pu8 = reinterpret_cast< const std::uint8_t* >(first);
		  
        while ( pu8 < reinterpret_cast<const std::uint8_t*>(last) )
          *reinterpret_cast< volatile std::uint8_t* >(&crc->DR) = *pu8++;
        
        
        return;
      }
		
		
		
		
		
		
	  template< typename T >
      static void CalculateFast( CRC_TypeDef* crc, const T* first, const T* last ) noexcept(true)
      { 
        const std::uint32_t* pu32 = reinterpret_cast< const std::uint32_t* >(first);
		  
        while ( pu32 < reinterpret_cast<const std::uint32_t*>(last) )
          crc->DR = *pu32++;
        
        
        return;
      }
		
		
		
      
      template < class Model >
      inline static std::uint32_t Finalize(CRC_TypeDef* crc) noexcept(true)
      {
        static_assert( IsValidModel < Model >(), "This model not supported" );  
		static constexpr std::uint32_t kResultMask = std::numeric_limits< std::uint32_t >::max() >> 
			                                         ( 32u - Model::kWidth );
		  
        std::uint32_t ret = (crc->DR ^ Model::kXorOut) & kResultMask; 
        crc->CR = CRC_CR_RESET; 
        
        return ret;
      }
      
    };
  }
} // namespace mpp::crypto
