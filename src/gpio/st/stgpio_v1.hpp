/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/gpio/st/stgpio_v1.hpp
  @brief  Compatible series: STM32F1 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>



namespace mpp::gpio
{
  inline namespace stgpio_v1
  {      
    
    enum class Type         { Output = 0b0111u, Alternate = 0b1111u, Analog = 0b0000, Input = 0b1100 };
    enum class Driver       { PushPull = 0b1000u, OpenDrain = 0b1100u , None = 0b0000u };
    enum class Pull         { Floating = 0b0100u, Up = 0b1000u, Down = 0b1001u, None = 0b0000u };  
    enum class Speed        { None  = 0b0000u, Low = 0b0010u, Medium = 0b0001u, High = 0b0011u };
    enum class DefaultState { High, Low, None };
    enum class Inversion    { Off, On, None };
    
    
    template < class IO, class Trait > class Gpio final {
      static_assert(::std::is_same_v< Trait, ::std::decay_t< decltype(Trait()) > >);
      static_assert(::std::is_same_v< IO,    ::std::decay_t< decltype(IO()) > >);
      
      
      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          if constexpr (Trait::kType == Type::Input) {
            static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for input pin");
            static_assert((Trait::kSpeed == Speed::None),   "Use 'Speed::None' for input pin");
            static_assert((Trait::kPull != Pull::None),   "Don't use 'Pull::None' for input pin");
            static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
            static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' input pin");
            
           return true;
         }
        
       
         if constexpr (Trait::kType == Type::Output) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for output pin");
           static_assert((Trait::kPull == Pull::None),   "Use 'Pull::None' for output pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for output pin");
           static_assert((Trait::kDefaultState != DefaultState::None), "Don't use 'DefaultState::None' for output pin");
           static_assert((Trait::kInversion != Inversion::None), "Don't use 'Inversion::None' for output pin");
         
           return true;
         }
        
        
         if constexpr (Trait::kType == Type::Analog) {
           static_assert((Trait::kDriver == Driver::None), "Use 'Driver::None' for analog pin"); 
           static_assert((Trait::kSpeed == Speed::None), "Use 'Speed::None' for analog pin");
           static_assert((Trait::kPull == Pull::None), "Use 'Pull::None' for analog pin");
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for analog pin");
          
           return true;
         }
          
          
         if constexpr (Trait::kType == Type::Alternate) {
           static_assert((Trait::kDriver != Driver::None), "Don't use 'Driver::None' for AF pin");
           static_assert((Trait::kSpeed != Speed::None), "Don't use 'Speed::None' for AF pin"); 
           static_assert((Trait::kPull == Pull::None),   "Use 'Pull::None' for AF pin");
           static_assert((Trait::kDefaultState == DefaultState::None), "Use 'DefaultState::None' for non output pin");
           static_assert((Trait::kInversion == Inversion::None), "Use 'Inversion::None' for AF pin");
          
           return true;
         }
          

         return false; 
       }
        
       static_assert(IsValidTrait(), "This trait contains error");
       static_assert(IsValidIo< IO >(), "You try use incorrect pin id");
      
      
      
      
      public:
        static constexpr Port kPort                 = IO::kPort;
        static constexpr std::uint32_t kPin         = IO::kPin;
        static constexpr Type kType                 = Trait::kType;
        static constexpr Driver kDriver             = Trait::Driver;
        static constexpr Pull kPull                 = Trait::kPull;
        static constexpr Speed kSpeed               = Trait::kSpeed;
        static constexpr Inversion kInversion       = Trait::kInversion;
        static constexpr DefaultState kStateDefault = Trait::kDefaultState;
      
        static constexpr  std::uint32_t CR = (((kType == Type::Input) ? 
                               static_cast<std::uint32_t>(kPull) : static_cast<std::uint32_t>(kDriver)) |
                               static_cast<std::uint32_t>(kSpeed)) & static_cast<std::uint32_t>(kType);
          
        static constexpr std::uint32_t kCrlMask       = (kPin < 8u) ? CR << (kPin << 2u) : 0u;
        static constexpr std::uint32_t kCrlClearMask  = ~((kPin < 8u) ? ~(0b1111 << (kPin << 2ul)) : 0u);
        static constexpr std::uint32_t kCrhMask       = (kPin > 7u) ? CR << ((kPin-8) << 2u) : 0u;
        static constexpr std::uint32_t kCrhClearMask  = ~((kPin > 7u) ? ~(0b1111 << ((kPin-8) << 2ul)) : 0u);
        static constexpr std::uint32_t kOdrMask       = (kType != Type::Output) ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kIdrMask       = (kType != Type::Input)  ? 0u : 1ul << kPin;
        static constexpr std::uint32_t kBsrrSetMask   = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << (kPin+16u) : 0b1ul << kPin;
        static constexpr std::uint32_t kBsrrResetMask = (kType != Type::Output) ? 0u : (kInversion == Inversion::On) ? 0b1ul << kPin : 0b1ul << (kPin+16u);
        static constexpr std::uint32_t kBsrrInitMask  = (kType != Type::Output) ? 
                                                          (kType == Type::Input && kPull == Pull::Up) ?
                                                             0b1ul << kPin :
                                                             0b1ul << (kPin+16u) :
                                                          (kInversion == Inversion::On) ? 
                                                            (kStateDefault == DefaultState::High) ? 0b1u << (kPin+16u) : 0b1u << kPin :
                                                            (kStateDefault == DefaultState::High) ? 0b1u << kPin : 0b1u << (kPin+16u);
      
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          
          if constexpr (kPin < 8) 
          {
            regs->CRL &= kCrlClearMask;
            if constexpr (kCrlMask != 0) regs->CRL |= kCrlMask;
          }
          else
          {
            regs->CRH &= kCrhClearMask;
            if constexpr (kCrhMask != 0) regs->CRH |= kCrhMask;
          }
          
          regs->BSRR = kBsrrInitMask;
        }
      
      
        inline static void Set() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrSetMask;
        }
      
      
      
        inline static void Reset() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrResetMask; 
        }
        
        
        inline static void Toggle() noexcept(true) {
          static_assert((kType == Type::Output), "This gpio not output, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->ODR ^= kOdrMask;            
        }
      
      
      
        inline static bool Read() noexcept(true) {
          static_assert((kType == Type::Input), "This gpio not input, check 'Type' field");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          bool ret = static_cast<bool>(regs->IDR & kIdrMask);   
          return (kInversion == Inversion::On) ? !ret : ret; 
        }
    };
    
    
    
    template< class... IO > class IoGroup final
    {
      private:
        template < class T, class... Ts >
        constexpr static Port ExtractPort() { return T::kPort; }
            
        template < class T, class... Ts >
        constexpr static bool IsValidIo() { return ( ((static_cast<std::uint32_t>(T::kPort) == static_cast<std::uint32_t>(Ts::kPort)) && (T::kPin != Ts::kPin)) && ... ); }

        template < class T, class... Ts >
        constexpr static bool IsValidGroup()
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidIo<Ts...>() && IsValidGroup<Ts...>();
        }
      
        static_assert(IsValidGroup<IO...>(), "All <kPort> fields must be equal, all <kPin> fields must be unique");
      
      public:
        static constexpr Port kPort = ExtractPort< IO... >();
        constexpr static std::uint32_t kCrlMask       = ( ... | IO::kCrlMask );
        constexpr static std::uint32_t kCrlClearMask  = ( ... & IO::kCrlClearMask );
        constexpr static std::uint32_t kCrhMask       = ( ... | IO::kCrhMask );
        constexpr static std::uint32_t kCrhClearMask  = ( ... & IO::kCrhClearMask );
        constexpr static std::uint32_t kOdrMask       = ( ... | IO::kOdrMask );
        constexpr static std::uint32_t kIdrMask       = ( ... | IO::kIdrMask );
        constexpr static std::uint32_t kBsrrInitMask  = ( ... | IO::kBsrrInitMask );
        constexpr static std::uint32_t kBsrrSetMask   = ( ... | IO::kBsrrSetMask );
        constexpr static std::uint32_t kBsrrResetMask = ( ... | IO::kBsrrResetMask );
        constexpr static std::uint32_t kInputInvMask  = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Input))  ? 1u << IO::kPin : 0u) );
        constexpr static std::uint32_t kOutputInvMask = ( ... | (((IO::kInversion == Inversion::On)&&(IO::kType == Type::Output)) ? 1u << IO::kPin : 0u) );
         
      
        inline static void Init() noexcept(true) {
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
          
          if constexpr (kCrlClearMask != 0xffff'ffff) 
            regs->CRL &= kCrlClearMask;
          
          if constexpr (kCrhClearMask != 0xffff'ffff) 
            regs->CRH &= kCrhClearMask;
          
          if constexpr (kCrlMask != 0)
            regs->CRL |= kCrlMask;
          
          if constexpr (kCrhMask != 0)
            regs->CRH |= kCrhMask;
             
          regs->BSRR = kBsrrInitMask;
        }
      
      
        inline static void Set() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };

          regs->BSRR = kBsrrSetMask;
        }
        
      
        inline static void Reset() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->BSRR = kBsrrResetMask; 
        }
        
      
        inline static void Toggle() noexcept(true) {
          static_assert((kBsrrSetMask != 0u), "IoGroup haven't output pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          regs->ODR ^= kOdrMask;            
        }
        
      
        inline static std::uint32_t Read() noexcept(true) {
          static_assert((kIdrMask != 0u), "IoGroup haven't input pin");
          GPIO_TypeDef* regs { reinterpret_cast<GPIO_TypeDef*>(kPort) };
            
          std::uint32_t ret = regs->IDR & kIdrMask;
          if constexpr (kInputInvMask != 0u) ret ^= kInputInvMask;
           
          return ret;
        }
      
    };
    
  } // inline namespace
} // mpp::gpio
