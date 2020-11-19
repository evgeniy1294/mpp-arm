/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/utils.hpp
  @brief  Compatible series: all
  ***********************************************************
**/


#pragma once



//____________________INCLUDE_____________________//
#include <type_traits>
#include <limits>


namespace mpp::crc {
  
  template< class Trait >
  class CrcLogic {
    static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
    static_assert((Trait::Width <= sizeof(typename Trait::result_type) * 8), "Fields 'result_type' and 'Width' is incorrect");
    static_assert((Trait::Width >= 4), "Fields 'Width' must be greater or equal 4");
    
    public:
      using result_type = typename Trait::result_type;
    
      static constexpr std::size_t Width = Trait::Width;
      static constexpr result_type kPoly     = Trait::kPoly;
      static constexpr result_type kSeed     = Trait::kSeed;
      static constexpr result_type kXorOut   = Trait::kXorOut;
      static constexpr bool kRefIn  = Trait::kRefIn;
      static constexpr bool kRefOut = Trait::kRefOut;
      static constexpr result_type kResultMask = std::numeric_limits< result_type >::max() >> ( sizeof( result_type )*8u - Width);
        
    private:
      std::array< result_type, 16 > Table;
    
    
    public:
      constexpr CrcLogic() noexcept(true)
      {
        constexpr result_type kRefPoly = Reflect<result_type, Width>(Trait::kPoly);
        constexpr result_type mask = (kRefIn) ? static_cast<result_type>(1u) : 
                                                static_cast<result_type>(1u) << ( Width - 1u );
        
        for (std::size_t i = 0u; i < Table.size(); i++) {
          result_type x = 0;
          
          if constexpr (kRefIn)
          {
            for (std::size_t j = 0x01; j < 0x10; j <<= 1) {
              bool bit = x & mask;
              bit = ( i & j ) ? !bit : bit;
              x = (bit) ? (x >> 1) ^ kRefPoly : (x >> 1);
            }
          }
          else
          {
            for (std::size_t j = 0x08; j > 0; j >>= 1) {
              bool bit = x & mask;
              bit = ( i & j ) ? !bit : bit;
              x = (bit) ? (x << 1) ^ kPoly : (x << 1);
            }
            
          }
          
          Table[i] = x & kResultMask;
        }       
      }
      
      
      
      
      inline result_type Finalize( result_type crc ) noexcept(true)
      {
        if constexpr (kRefIn)
        {  
          if constexpr (!kRefOut)
            crc = Reflect<result_type, Width>(crc);
        }
        else
        {
          if constexpr (kRefOut)
            crc = Reflect<result_type, Width>(crc);   
        }
        
        return (crc ^ kXorOut) & kResultMask;
      }
      
      
      
    
      template< typename T, bool finalize = true >
      result_type Calculate( const T* first, const T* last, result_type  crc = kSeed ) noexcept(true)
      { 
        const std::uint8_t* ptr = reinterpret_cast< const std::uint8_t* >( first );

        if constexpr (kRefIn)
        { 
          while ( ptr < reinterpret_cast< const std::uint8_t* >( last ) ) {
            crc = crc ^ ( static_cast < result_type >(*ptr++) << 0 );
              
            crc = (crc >> 4u) ^ Table[ crc & 0b1111u ];
            crc = (crc >> 4u) ^ Table[ crc & 0b1111u ];
          }
        }
        else
        {
          constexpr std::size_t shift_data = (Width < 8) ? Width - 4 : Width - 8u;
            
          while ( ptr < reinterpret_cast< const std::uint8_t* >( last ) ) {
            if constexpr ( Width  < 8 ) {
              std::size_t tbl_idx = (crc >> shift_data) ^ (*ptr >> 4);
              crc = (crc << 4u) ^ Table[ tbl_idx & 0b1111 ];
             
              tbl_idx = (crc >> shift_data) ^ (*ptr++);
              crc = (crc << 4u) ^ Table[ tbl_idx & 0b1111 ];
            }
            else
            {
              constexpr std::size_t shift_idx = Width - 4;
                            
              crc = crc ^ ( static_cast < result_type >(*ptr++) << shift_data );
  
              crc = (crc << 4u) ^ Table[ ( crc >> shift_idx ) & 0b1111 ];
              crc = (crc << 4u) ^ Table[ ( crc >> shift_idx ) & 0b1111 ];
            }
          }
        }
          
        if constexpr (finalize)
          crc = Finalize(crc);
          
        return crc;
      }
    
      
  };
    
   
} // namespace crc 








