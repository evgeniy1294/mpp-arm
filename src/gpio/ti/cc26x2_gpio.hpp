/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/ti/cc26x2_gpio.hpp
  @brief  Сompatibility series: TI Simplelink
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>

#ifdef (CC1352R)||(CC1352P)||(CC2652R)||(CC2652P)||(CC2652RB)
  #include "spec/cc26x2.hpp"
#else
  #error "You must define supported MCU"
#endif

namespace mpp::gpio
{
  inline namespace cc26x2
  {
    enum class Type          { Input, Output, Analog };
    enum class DefaultState  { None, High, Low };
    enum class CurrentMode   { LC_AUTO = 0x0ul, LC_MIN = 0x1ul, LC_MED = 0x2ul, LC_MAX = 0x3ul, HC = 0x4ul, EC = 0x8ul, None };
    enum class Pull          { Down = 0x1ul, Up = 0x2ul, None = 0x3ul };
    enum class SlewRate      { Normal = 0x0ul, Reduced = 0x1ul, None };
    enum class Driver        { Normal = 0x0ul, OpenDrain = 0x2ul, OpenSource = 0x3ul, None };
    enum class EdgeDetection { None = 0x0ul, Neg = 0x1ul, Pos = 0x2ul, Both = 0x3ul };
    enum class WakeUp        { None = 0x0ul, Negedge = 0x2ul, Posedge = 0x3ul };
    enum class Hysteresis    { Off = 0x0ul, On = 0x1ul, None };
    enum class Inversion     { Off = 0x0ul, On = 0x1ul, None };
    enum class InputBuffer   { Off = 0x0ul, On = 0x1ul, None };
    enum class OutputBuffer  { Off = 0x0ul, On = 0x1ul, None };
    enum class EdgeDetIrq    { Off = 0x0ul, On = 0x1ul, None };
    enum class DefaultState  { High = 0x01ul, Low = 0x00, None };
    enum class EventAssertion
    { 
      None       = 0x0ul;
      MCU_WakeUp = IOC_IOCFG_IOEV_MCU_WU_EN, 
      RTC        = IOC_IOCFG_IOEV_RTC_EN, 
      AON_PROG0  = IOC_IOCFG_IOEV_AON_PROG0_EN,
      AON_PROG1  = IOC_IOCFG_IOEV_AON_PROG1_EN,
      AON_PROG2  = IOC_IOCFG_IOEV_AON_PROG2_EN,
    };
      
    inline constexpr EventAssertion operator| (EventAssertion a, EventAssertion b) { return static_cast<EventAssertion>( static_cast<uint32_t>(a) | static_cast<uint32_t>(b) ); }
    
    
    template< class IO, class Trait > constexpr bool IsValidTrait noexcept(true) ()
    {
      if constexpr ( Trait::Type() == Type::Analog )
      {
        static_assert( IO::IsAnalogCapable(), "This IO haven't analog capability" );
        static_assert( Trait::PortId() == PortId::AUX_IO, "Port ID must be equal AUX IO (0x08) for analog Pin" );
        static_assert( Trait::DefaultState() == DefaultState::None, "Use DefaultState::None for analog pin" );
        static_assert( Trait::CurrentMode() == CurrentMode::None, "Use CurrentMode::None for analog pin" );
        static_assert( Trait::SlewRate() == SlewRate::None, "Use SlewRate::None for analog pin" );
        static_assert( Trait::Driver() == Driver::None, "Use Driver::None for analog pin" );
        static_assert( Trait::Pull() == Pull::None, "Use Pull::None for analog pin" );
        static_assert( Trait::EdgeDetection() == EdgeDetection::None, "Use EdgeDetection::None for analog pin" );
        static_assert( Trait::EventAssertion() == EventAssertion::None, "Use EventAssertion::None for analog pin" );
        static_assert( Trait::WakeUp() == WakeUp::None, "Use WakeUp::None for analog pin" );
        static_assert( Trait::Inversion() == Inversion::None, "Use Inversion::None for analog pin" );
        static_assert( Trait::Hysteresis() == Hysteresis::None, "Use Hysteresis::None for analog pin" );
        static_assert( Trait::OutputBuffer() == OutputBuffer::None, "Use OutputBuffer::None for analog pin" );
        static_assert( Trait::InputBuffer() == InputBuffer::None, "Use InputBuffer::None for analog pin" );
        static_assert( Trait::EdgeDetIrq() == EdgeDetIrq::None, "Use EdgeDetIrq::None for analog pin" );
        static_assert( Trait::DefaultState() == DefaultState::None, "Use DefaultState::None for analog pin" );
        
        return true;
      }
        
        
      if constexpr ( Trait::Type() == Type::Input )
      {
        if constexpr ( Trait::PortId() == PortId::AUX_IO )
          static_assert( Trait::InputBuffer() == InputBuffer::Off, "For AUX IO InputBuffer::On will be ignored" );
                      
        if constexpr ( ( Trait::PortId() == PortId::AUX_IO ) || ( Trait::PortId() == PortId::AON_CLK32K ) )
          static_assert( Trait::Inversion() == Inversion::None, "Use Inversion::None for AON/AUX IO" );
        
        static_assert( Trait::DefaultState() == DefaultState::None, "Use DefaultState::None for input pin" );
        static_assert( Trait::CurrentMode() == CurrentMode::None, "Use CurrentMode::None for input pin" );
        static_assert( Trait::SlewRate() == SlewRate::None, "Use SlewRate::None for input pin" );
        static_assert( Trait::Driver() == Driver::None, "Use Driver::None for input pin" );
        static_assert( Trait::Inversion() != Inversion::None, "Don't use Inversion::None for input pin" );
        static_assert( Trait::Hysteresis() != Hysteresis::None, "Don't use Hysteresis::None for input pin" );
        static_assert( Trait::OutputBuffer() == OutputBuffer::Off, "Use OutputBuffer::Off for input pin" );
        static_assert( Trait::InputBuffer() != InputBuffer::None, "Don't use InputBuffer::None for input pin" );
        
        return true;
      }
      
      
      if constexpr ( Trait::Type() == Type::Output )
      {
        if constexpr ( Trait::CurrentMode() == CurrentMode::EC )
          static_assert( IO::IsHighDriveCapable(), "This pin haven't high drive capable" );
        
        if constexpr (( Trait::PortId() == PortId::AUX_IO ) || ( Trait::PortId() == PortId::AON_CLK32K ) )
        {
          static_assert( Trait::Inversion() == Inversion::None, "Use Inversion::None for AON/AUX IO" );
          static_assert( Trait::Driver() == Driver::None, "Use Driver::None for AON/AUX output pin" );
        }
        else
        {
          static_assert( Trait::Inversion() != Inversion::None, "Don't use Inversion::None for non AON/AUX output pin" );
          static_assert( Trait::Driver() != Driver::None, "Don't use Driver::None for non AON/AUX output pin" );
        }
        
        static_assert( Trait::CurrentMode() != CurrentMode::None, "Don't use CurrentMode::None for output pin" );
        static_assert( Trait::SlewRate() != SlewRate::None, "Don't use SlewRate::None for output pin" );
        static_assert( Trait::Pull() == Pull::None, "Use Pull::None for output pin" );
        static_assert( Trait::EdgeDetection() == EdgeDetection::None, "Use EdgeDetection::None for output pin" );
        static_assert( Trait::EventAssertion() == EventAssertion::None, "Use EventAssertion::None for output pin" );
        static_assert( Trait::WakeUp() == WakeUp::None, "Use WakeUp::None for output pin" );
        static_assert( Trait::Hysteresis() == Hysteresis::None, "Use Hysteresis::None for output pin" );
        static_assert( Trait:::OutputBuffer() != OutputBuffer::None, "Don't use OutputBuffer::None for output pin" );
        static_assert( Trait::InputBuffer() == InputBuffer::Off, "Use InputBuffer::Off for output pin" );
        static_assert( Trait::DefaultState() == DefaultState::None, "Use DefaultState::None for output pin" );
        
        return true;
      }
      
      return false; 
    }    
    
    
    
    template < CurrentMode current_mode, Inversion inv >
    struct LedTrait final {
      constexpr inline static auto Type()           noexcept(true) { return Type::Output; }
      constexpr inline static auto PortId()         noexcept(true) { return PortId::GPIO; }
      constexpr inline static auto CurrentMode()    noexcept(true) { return current_mode; }
      constexpr inline static auto Pull()           noexcept(true) { return Pull::None; }
      constexpr inline static auto SlewRate()       noexcept(true) { return SlewRate::Normal; }
      constexpr inline static auto Driver()         noexcept(true) { return Driver::Normal; }
      constexpr inline static auto EdgeDetection()  noexcept(true) { return EdgeDetection::None; }
      constexpr inline static auto WakeUp()         noexcept(true) { return WakeUp::None; }
      constexpr inline static auto EventAssertion() noexcept(true) { return EventAssertion::None; }
      constexpr inline static auto DefaultState()   noexcept(true) { return DefaultState::Low; }
      constexpr inline static auto Inversion()      noexcept(true) { return inv; }
      constexpr inline static auto Hysteresis()     noexcept(true) { return Hysteresis::None; }
      constexpr inline static auto InputBuffer()    noexcept(true) { return InputBuffer::Off; }
      constexpr inline static auto OutputBuffer()   noexcept(true) { return OutputBuffer::On; }
      constexpr inline static auto DefaultState()   noexcept(true) { return DefaultState::Off; }
      constexpr inline static auto EdgeDetIrq()     noexcept(true) { return EdgeDetIrq::None; }
    };
    
    
      
      
      
      
      
    template < class IO, class Trait >
    class Gpio final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);
      static_assert(IsValidIo< IO >(), "You try use invalid IO");
      static_assert(IsValidTrait< IO, Trait >(), "This trait is invalid");
      
        
      public:
        static constexpr std::uint32_t kPin                = IO::Pin();
        static constexpr std::uint32_t kAuxPin             = IO::AuxPin();
        static constexpr bool kAnalogCapable               = IO::IsAnalogCapable();
        static constexpr bool kHighDriveCapable            = IO::IsHighDriveCapable();
        static constexpr Type kType                        = Trait::Type();
        static constexpr PortId kPortId                    = Trait::PortId();
        static constexpr Pull kPull                        = Trait::Pull();
        static constexpr CurrentMode kCurrentMode          = Trait::CurrentMode();
        static constexpr SlewRate kSlewRate                = Trait::SlewRate();
        static constexpr Driver kDriver                    = Trait::Driver();
        static constexpr EdgeDetection kEdgeDetection      = Trait::EdgeDetection();
        static constexpr WakeUp kWakeUp                    = Trait::WakeUp();
        static constexpr EventAssertion kEventAssertion    = Trait::EventAssertion();
        static constexpr EdgeDetIrq kEdgeDetIrq            = Trait::EdgeDetIrq();
        static constexpr Inversion kInversion              = Trait::Inversion();
        static constexpr Hysteresis kHysteresis            = Trait::Hysteresis();
        static constexpr InputBuffer kInputBufferDefault   = Trait::InputBuffer();
        static constexpr OutputBuffer kOutputBufferDefault = Trait::OutputBuffer();
        static constexpr DefaultState kDefaultState        = Trait::DefaultState();
        
        inline constexpr static auto Init() noexcept(true) 
        {
          constexpr std::uint32_t IOCURR   = ( kCurrentMode != CurrentMode::None ) ? (static_cast< std::uint32_t >(kCurrentMode) << IOC_IOCFG_IOSTR_S) : 0ul;
          constexpr std::uint32_t SLEW_RED = ( kSlewRate != SlewRate::None ) ? (static_cast< std::uint32_t >(kSlewRate) << IOC_IOCFG_SLEW_RED_BITN) : 0ul;
          constexpr std::uint32_t EDGE_DET = ( kEdgeDetIrq != EdgeDetIrq::None ) ?  (static_cast< std::uint32_t >(kEdgeDetIrq) << IOC_IOCFG_EDGE_IRQ_EN_BITN) : 0ul;
          constexpr std::uint32_t INV      = ( kInversion != Inversion::None ) ? (static_cast< std::uint32_t >(kInversion) << 24ul) : 0ul;
          constexpr std::uint32_t DRV      = ( kDriver != Driver::None ) ? (static_cast< std::uint32_t >(kDriver) << 25ul) : 0ul;
          constexpr std::uint32_t IE       = ( kInputBufferDefault != InputBuffer::None ) ? (static_cast< std::uint32_t >(kInputDefault) << IOC_IOCFG_IE_BITN) : 0ul;
          constexpr std::uint32_t HYST     = ( kHysteresis != Hysteresis::None ) ? (static_cast< std::uint32_t >(kHysteresis) << IOC_IOCFG_HYST_EN_BITN) : 0ul;
          
          constexpr std::uint32_t iocfg = static_cast< std::uint32_t >(kPortId) |
                                          static_cast< std::uint32_t >(kEventAssertion) |
                                         (static_cast< std::uint32_t >(kPull) << IOC_IOCFG_PULL_CTL_S) |
                                         (static_cast< std::uint32_t >(kEdgeDetection) << IOC_IOCFG_EDGE_DET_S) |
                                         (static_cast< std::uint32_t >(kWakeUp) << IOC_IOCFG_WU_CFG_S) |
                                          IOCURR | SLEW_RED | EDGE_DET | INV | DRV | IE | HYST ;
            
          IOC->IOCFG[kPin] = iocfg;
          
          if constexpr (kOutputBufferDefault == OutputBufferDefault::On)
            GPIO->DOE  |= 1 << kPin;
          
          if constexpr (kDefaultState != DefaultState::None)
          {
            if constexpr (kDefaultState == DefaultState::High)
              GPIO->DOUTSET = 1 << kPin;
            else
              GPIO->DOUTCLR = 1 << kPin;
          }
            
          return;
        }
      
      
        inline static auto Set() noexcept(true) 
        { 
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO->DOUTSET = 1 << pin;
        }
        
        inline static auto Reset() noexcept(true)
        {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO->DOUTCLR = 1 << pin;
        }
      
        inline static auto Toggle() noexcept(true)
        {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO->DOUTTGL = 1 << pin;
        }
      
        inline static auto Read() noexcept(true)
        {
          static_assert((kType == Type::Input), "This gpio not input, check 'Type' field");
          return static_cast<bool>(GPIO->DIN & (1 << pin));
        }
    };
  } // inline namespace 
} // namespace mpp::gpio
