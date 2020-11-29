/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/utils/binutils.hpp
  @brief  Compatible series: all
  ***********************************************************
**/

#pragma once


namespace mpp::utils {


  template < typename T, std::size_t bits = sizeof(T) * 8 > 
  inline constexpr T Reflect ( T x )
  {
    T reflection = 0;
    constexpr T one = 1; 
  
    for ( std::size_t i = 0 ; i < bits ; ++i, x >>= 1 )
    {
      if ( x & one )
        reflection |= ( one << (bits - 1u - i) );
    }
        
    return reflection;
  }

	
	

}  // namespace mpp 
