/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   include/mpp/utils.hpp
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
	
  
  template < class Source >
  class Timer
  {
	public:
      void Start(std::uint32_t interval)
	  {
        this->timestamp = Source::GetTick(); 
		this->interval  = interval;
        this->active    = true;
	  }
	  
	  void Reload()
	  {
		this->timestamp = Source::GetTick();   
	  }

      bool IsTimeOut()
      {
        return (((Source::GetTick() - this->timestamp) > this->interval) && this->active);
      };

	  void Delay(std::uint32_t tick)
	  {
        std::uint32_t start = Source::GetTick();
        while((Source::GetTick() - start) < tick);
	  }
	  
    private:
	  bool active = false;
	  std::uint32_t interval  = 0u;
      std::uint32_t timestamp = 0u;
  };
	  
}  // namespace mpp
