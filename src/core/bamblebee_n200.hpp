/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/core/bamblebee_n200.hpp
  @brief  Compatible with gd32f103 family and based on 
          RISC-V N200 core chip
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>

#include "riscv.hpp"

#define TIMER_MTIME_LO           (TIMER_MTIME)
#define TIMER_MTIME_HI           (TIMER_MTIME + 4)
#define TIMER_MTIMECMP_LO        (TIMER_MTIMECMP)
#define TIMER_MTIMECMP_HI        (TIMER_MTIMECMP + 4)
#define TIMER_MSTOP              (0xFF8)


namespace mpp::core {
    
  namespace __private { std::uint32_t GetTick(); void IncTick(); void ResetTick(); } // namespace __private
    
  inline namespace n2000 {
    
    // TODO: Move standart RISC-V registers to "riscv.hpp"
    
    // RISC-V Standart CSR (Machine mode)
    using MVENDORID         = AbstractCsr < 0xF11ul, Accessibility::MRO >;  //!< Machine Vendor ID Register
    using MARCHID           = AbstractCsr < 0xF12ul, Accessibility::MRO >;  //!< Machine Architecture Register
    using MIMPID            = AbstractCsr < 0xF13ul, Accessibility::MRO >;  //!< Machine Implementation ID Register
    using MHARTID           = AbstractCsr < 0xF14ul, Accessibility::MRO >;  //!< Machine Hart ID Register
    using MSTATUS           = AbstractCsr < 0x300ul, Accessibility::MRW >;  //!< Machine Status Register
    using MISA              = AbstractCsr < 0x301ul, Accessibility::MRO >;  //!< Machine ISA Register
    using MIE               = AbstractCsr < 0x304ul, Accessibility::MRW >;  //!< Machine Interrupt Enable Register
    using MTVEC             = AbstractCsr < 0x305ul, Accessibility::MRW >;  //!< Machine Trap-Vector Base-Address Register
    using MTVT              = AbstractCsr < 0x307ul, Accessibility::MRW >;  //!< Machine ECLIC Interrupt Vector Table Base Address Register
    using MSCRATCH          = AbstractCsr < 0x340ul, Accessibility::MRW >;  //!< Machine Scratch Register
    using MEPC              = AbstractCsr < 0x341ul, Accessibility::MRW >;  //!< Machine Exception Program Counter Register
    using MCAUSE            = AbstractCsr < 0x342ul, Accessibility::MRW >;  //!< Machine Cause Register
    using MTVAL             = AbstractCsr < 0x343ul, Accessibility::MRW >;  //!< Machine Trap Value Register
    using MIP               = AbstractCsr < 0x344ul, Accessibility::MRW >;  //!< Machine Interrupt Pending Register
    using MNXTI             = AbstractCsr < 0x345ul, Accessibility::MRW >;  //!< Machine the Next Interrupt handler address and enable modifier
    using MINTSTATUS        = AbstractCsr < 0x346ul, Accessibility::MRO >;  //!< Machine Current Interrupt Level Register
    using MSCRATCHCSW       = AbstractCsr < 0x348ul, Accessibility::MRW >;  //!< Machine Scratch Swap Register for privileged mode
    using MSCRATCHCSWL      = AbstractCsr < 0x349ul, Accessibility::MRW >;  //!< Machine Scratch Swap Register for interrupt levels
    using MCYCLE            = AbstractCsr < 0xB00ul, Accessibility::MRW >;  //!< Machine Lower 32-bits of Cycle counter 
    using MCYCLEH           = AbstractCsr < 0xB80ul, Accessibility::MRW >;  //!< Machine Upper 32-bits of Cycle counter 
    using MINSTRET          = AbstractCsr < 0xB02ul, Accessibility::MRW >;  //!< Machine Lower 32-bits of Instruction-retired counter
    using MINSTRETH         = AbstractCsr < 0xB82ul, Accessibility::MRW >;  //!< Machine Upper 32-bits of Instruction-retired counter
    
    
    // RISC-V Standart CSR (User Mode)
    using CYCLE             = AbstractCsr < 0xC00ul, Accessibility::URO >;  //!< MCYCLE read-only copy
    using TIME              = AbstractCsr < 0xC01ul, Accessibility::URO >;  //!< MTIME read-only copy
    using ISTRET            = AbstractCsr < 0xC02ul, Accessibility::URO >;  //!< MINSTRET read-only copy
    using CYCLEH            = AbstractCsr < 0xC80ul, Accessibility::URO >;  //!< MCYCLEH read-only copy
    using TIMEH             = AbstractCsr < 0xC81ul, Accessibility::URO >;  //!< MTIMEH read-only copy
    using ISTRETH           = AbstractCsr < 0xC82ul, Accessibility::URO >;  //!< MINSTRETH read-only copy
    
    
    // Bumblebee Customized CSR 
    using MCOUNTINHIBIT    = AbstractCsr < 0x320ul, Accessibility::MRW >;  //!< Customized register for counters on & off
    using MNVEC            = AbstractCsr < 0x7C3ul, Accessibility::MRO >;  //!< NMI Entry Address
    using MSUBM            = AbstractCsr < 0x7C4ul, Accessibility::MRW >;  //!< Customized Register Storing Type of Trap
    using MMISC_CTL        = AbstractCsr < 0x7D0ul, Accessibility::MRW >;  //!< Customized Register holding NMI Handler Entry Address
    using MSAVESTATUS      = AbstractCsr < 0x7D6ul, Accessibility::MRW >;  //!< Customized Register holding the value of mstatus
    using MSAVEEPC1        = AbstractCsr < 0x7D7ul, Accessibility::MRW >;  //!< Customized Register holding the value of mepc for the first-level preempted NMI or Exception.
    using MSAVECAUSE1      = AbstractCsr < 0x7D8ul, Accessibility::MRW >;  //!< Customized Register holding the value of mcause for the first-level preempted NMI or Exception.
    using MSAVEEPC2        = AbstractCsr < 0x7D9ul, Accessibility::MRW >;  //!< Customized Register holding the value of mepc for the second-level preempted NMI or Exception.
    using MSAVECAUSE2      = AbstractCsr < 0x7DAul, Accessibility::MRW >;  //!< Customized Register holding the value of mcause for the second-level preempted NMI or Exception.
    using PUSHMSUBM        = AbstractCsr < 0x7EBul, Accessibility::MRW >;  //!< Push msubm to stack
    using MTVT2            = AbstractCsr < 0x7ECul, Accessibility::MRW >;  //!< ECLIC non-vectored interrupt handler address register
    using JALMNXTI         = AbstractCsr < 0x7EDul, Accessibility::MRW >;  //!< Jumping to next interrupt handler address and interrupt-enable register
    using PUSHMCAUSE       = AbstractCsr < 0x7EEul, Accessibility::MRW >;  //!< Push mcause to stack
    using PUSHMEPC         = AbstractCsr < 0x7EFul, Accessibility::MRW >;  //!< Push mepc to stack
    using SLEEPVALUE       = AbstractCsr < 0x811ul, Accessibility::MRW >;  //!< WFI Sleep Mode Register
    using TXEVT            = AbstractCsr < 0x812ul, Accessibility::MRW >;  //!< Send Event Register
    using WFE              = AbstractCsr < 0x810ul, Accessibility::MRW >;  //!< Wait for Event Control Register
    
  
    template< class ClockSystem >
    class MachineTimer {
      public:
        constexpr static std::uint32_t TickPerSec = 1000u;
        constexpr static std::uint32_t TimeCmp    = ClockSystem::kMachineTimerClkHz / 1000u;
      
        inline static std::uint32_t GetTick() { return __private::GetTick(); }
        
      
        inline static void Init() { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          TIMER_REG(TIMER_MTIMECMP_LO) = TimeCmp;
          TIMER_REG(TIMER_MTIMECMP_HI) = 0;
          
          __private::ResetTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }
      
        
        static void InterruptHandler ()
        { 
          TIMER_REG(TIMER_MSTOP) = 1u;
          TIMER_REG(TIMER_MTIME_LO) = 0;
          TIMER_REG(TIMER_MTIME_HI) = 0;
          
          __private::IncTick();
          TIMER_REG(TIMER_MSTOP) = 0u;
        }         
    };
    
      
      
      
    template< class ClockSystem >
    class MachineTickCounter {
      public:
        constexpr static std::uint32_t TickPerSec = ClockSystem::kSysClkHz;
        
        inline static void Init() { 
          MCOUNTINHIBIT::Clear( 1u << 0 /* CSR_MCOUNTINHIBIT_CY */);
        }
        
        inline static std::uint32_t GetTick() { 
          // auto mcountinhibit = MCOUNTINHIBIT::Read();
          
          // MCOUNTINHIBIT::Set( 1u << 0 /* CSR_MCOUNTINHIBIT_CY */);
          // std::uint32_t tmp = CYCLE::Read(); 
          
          // MCOUNTINHIBIT::Write( mcountinhibit );

          return CYCLE::Read(); 
        }
    };
    
    
    
    
    enum class PriorityLevelGroup { L0P4 = 0, L1P3 = 1, L2P2 = 2, L3P1 = 3, L4P0 = 4 };
    
    struct EclicExampleTrait final {
      constexpr static PriorityLevelGroup kPriorityLevelGroup = PriorityLevelGroup::L3P1;
      constexpr static std::size_t kThresholdLevel  = 0;
    };
    
    
    
    
    template < class Trait >
    class Eclic final {
      static_assert(std::is_same_v< Trait, std::decay_t< decltype(Trait()) > >);
      
      private:
        constexpr static bool IsValidTrait() noexcept(true) {
          static_assert( Trait::kThresholdLevel <= 
              ((1 << static_cast< std::uint8_t >(Trait::kPriorityLevelGroup)) - 1), "Invalid threshold level");
          
          return true;
        }    
      
        template < class T, class... Ts >
        constexpr static bool IsValidInterrupt() { 
          return ( (static_cast<std::uint32_t>(T::kInterruptSource) != static_cast<std::uint32_t>(Ts::kInterruptSource)) && ... );
        }

        template < class T, class... Ts >
        constexpr static bool IsValidInterruptGroup()
        {
          if constexpr (sizeof...(Ts) == 0u)
            return true;
          else
            return IsValidInterrupt<T, Ts...>() && IsValidInterruptGroup<Ts...>();
        }
      
        static_assert(IsValidTrait(), "This trait contains error");
      
      public:
      
        constexpr static PriorityLevelGroup kPriorityLevelGroup = Trait::kPriorityLevelGroup;
        constexpr static std::size_t kThresholdLevel = Trait::kThresholdLevel;
       
        constexpr static std::uint8_t kCfgMask = static_cast<std::uint8_t>(kPriorityLevelGroup) << 1;
        constexpr static std::uint8_t kMthMask = kThresholdLevel;
      
      
        template < class... Interrupt >
        constexpr static void Init() {
          static_assert(IsValidInterruptGroup<Interrupt...>(), "All <kInterruptSource> fields must be unique");
          
		  typedef volatile uint32_t vuint32_t;

          //clear cfg register 
          *(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_CFG_OFFSET)=0;
        
          //clear minthresh register 
          *(volatile uint8_t*)(ECLIC_ADDR_BASE+ECLIC_MTH_OFFSET)=0;
        
          //clear all IP/IE/ATTR/CTRL bits for all interrupt sources
          vuint32_t * ptr;
        
          vuint32_t * base = (vuint32_t*)(ECLIC_ADDR_BASE + ECLIC_INT_IP_OFFSET);
          vuint32_t * upper = (vuint32_t*)(base + ECLIC_NUM_INTERRUPTS*4);
        
          for (ptr = base; ptr < upper; ptr=ptr+4){
            *ptr = 0;
          }        
			
          REG32(ECLIC_ADDR_BASE + ECLIC_CFG_OFFSET) = kCfgMask;
          REG32(ECLIC_ADDR_BASE + ECLIC_MTH_OFFSET) = kMthMask;
      
          ( Interrupt::Init(), ... ); 
        }
      
        constexpr static void EmitSoftwareInterrupt() {
          TIMER_REG(TIMER_MSIP) = 1u; 
        }
      
        template < class... Interrupt >
        constexpr static void EnableInterrupts() { ( Interrupt::Enable(), ... ); }
      
      
        template < class... Interrupt >
        constexpr static void DisableInterrupts() { ( Interrupt::Disable(), ... ); }
    };
  } // inline namespace
}


