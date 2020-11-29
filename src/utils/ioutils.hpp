/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/utils/ioutil.hpp
  @brief  Compatible series: all
  ***********************************************************
**/

#pragma once


namespace mpp::utils {
  template < class... dev >
  class DeviceSet
  {
    public:
      inline constexpr static void Init()  { ( dev::Init(), ... ); };   
  };

  template < class... IO >
  class IoSet final: public DeviceSet< IO... >
  {
    public:
      inline constexpr static void Set()   { ( IO::Set(), ... ); };
      inline constexpr static void Reset() { ( IO::Reset(), ... ); };
      inline constexpr static void Toggle(){ ( IO::Toggle(), ... ); };
  };
    
  

      
}  // namespace mpp
