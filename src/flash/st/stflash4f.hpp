/**
  ***********************************************************
  @author Evgenii Fedoseev
  @file   /src/flash/st/stflash4f.hpp
  @brief  Compatible series: STM32F4 
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>
#include <type_traits>

#if defined (STM32F405xx)||(STM32F407xx)||(STM32F415xx)|| \
            (STM32F417xx)||(STM32F427xx)||(STM32F429xx)|| \
            (STM32F437xx)||(STM32F439xx)||(STM32F446xx)|| \
            (STM32F469xx)||(STM32F479xx)
  #include "spec/stm32f407_flash.hpp"
#elif defined (STM32F401xc)||(STM32F401xe)
  #include "spec/stm32f401_flash.hpp"
#elif defined (STM32F410cx)||(STM32F410rx)||(STM32F410tx)|| \
              (STM32F411xe)|| \
              (STM32F412cx)||(STM32F412rx)||(STM32F412vx)||(STM32F412zx)
  #include "spec/stm32f410_flash.hpp"
#elif defined (STM32F413xx)||(STM32F423xx)
  #include "spec/stm32f413_flash.hpp"
#else
  #error "You must define supported MCU"
#endif


namespace mpp::flash
{
  inline namespace stflash4f
  {
    enum class ParallelismSize
    {
      x64 = 0b11u,
      x32 = 0b10u,
      x16 = 0b01u,
      x8  = 0b00u
    };
      
      
      
    struct FlashTraitExample {
      constexpr static std::uint32_t kClockFrequencyHz = 168'000'000u;
      constexpr static std::uint32_t kBankNum = 1u;
      constexpr static std::uint32_t kSectorInBank = 12u;
      constexpr static auto kParallelismSize = ParallelismSize::x32;
      constexpr static bool kPrefetch = true;
      constexpr static bool kICache = false;
      constexpr static bool kDCache = false;
    };
      
      
      
      
    template < std::uint32_t tSectorFirst, std::uint32_t tSectorLast >
    struct Region
    {
      constexpr static std::uint32_t kSectorFirst = tSectorFirst;
      constexpr static std::uint32_t kSectorLast  = tSectorLast;
      constexpr static std::uint32_t kSizeInByte  = []( std::uint32_t fsector, std::uint32_t lsector ) -> std::uint32_t {
            std::uint32_t SizeInKbytes = 0,
            iter = (fsector >= kFlashMaxSectorInBank) ? fsector - kFlashMaxSectorInBank : fsector;
      
            lsector = ( lsector >= kFlashMaxSectorInBank ) ? lsector - kFlashMaxSectorInBank : lsector;
          
            do
            {
              SizeInKbytes += ( iter < 4u ) ? 16u :
                                ( iter == 4u ) ? 64u : 128u; 
    
            } while ( iter++ != lsector );
        
            return SizeInKbytes * 1024u; } ( kSectorFirst, kSectorLast );
    };
      
      
      
      
      
    template < class Trait, class PowerProfile >
    class Flash final
    {
      private:
        constexpr bool IsValidTrait() noexcept(true) {
          static_assert( ( (Trait::kBankNum == 1u) || (Trait::kBankNum == 2u) ), "Bank number must be equal 1 or 2" );
          static_assert( ( Trait::kSectorInBank <= kFlashMaxSectorInBank ), "kSectorInBank has incorrect value" );
            
          if constexpr ( PowerProfile::kVoltageMin < 2.1f )
            static_assert( (!Trait::KPrefetch), "Turn off flash prefetch for low voltage ( < 2.1V )" );
            
          return true;
        }
        
        static_assert( IsValidTrait(), "Incorrect trait" );
                
      public:
        constexpr static std::uint32_t kStartAddress = FLASH_BASE;
        constexpr static std::uint32_t kEndAddress   = FLASH_END;
        constexpr static std::uint32_t kBankNum      = Trait::kBankNum;
        constexpr static std::uint32_t kSectorInBank = Trait::kSectorInBank;
        constexpr static std::uint32_t   kClockFrequencyHz = Trait::kClockFrequencyHz;
        constexpr static ParallelismSize kParallelismSize  = Trait::kParallelismSize;
        constexpr static bool kPrefetch = Trait::KPrefetch;
        constexpr static bool kICache   = Trait::kICache;
        constexpr static bool kDCache   = Trait::kDCache;
        constexpr static std::uint32_t kWaitState = GetWaitState( Trait::kClockFrequencyHz , PowerProfile::kVoltageMin );
                
        constexpr static std::uint32_t kAcrMask = ( kWaitState << FLASH_ACR_LATENCY_Pos )   |
                                           ( ( kPrefetch ) ? FLASH_ACR_PRFTEN : 0u ) |
                                           ( ( kICache ) ? FLASH_ACR_ICEN : 0u )     |
                                           ( ( kDCache ) ? FLASH_ACR_DCEN : 0u );
        
        constexpr static std::uint32_t kAcrClearMask = ~( FLASH_ACR_LATENCY_Msk | FLASH_ACR_ICEN_Msk | FLASH_ACR_DCEN_Msk | FLASH_ACR_DCEN_Msk );
        
        constexpr static std::uint32_t kCrMask  = ( static_cast< std::uint32_t >(kParallelismSize) << FLASH_CR_PSIZE_Pos );
        constexpr static std::uint32_t kCrClearMask = ~FLASH_CR_PSIZE_Msk;
        
        
        inline static void Init() {
          Unlock();
          FLASH->CR  &= kCrClearMask;
          FLASH->CR  |= kCrMask;
          Lock();
            
          FLASH->ACR &= kAcrClearMask;
          FLASH->ACR |= kAcrMask;
            
          return;
        }
        
        
        
        inline static bool IsBusy() noexcept( true ) {
          return static_cast<bool>( FLASH->SR & FLASH_SR_BSY );
        }
            
            
        
        inline static void Unlock() noexcept( true ) { 
          FLASH->KEYR = 0x45670123u;                  
          FLASH->KEYR = 0xCDEF89ABu;           
          FLASH->CR  |= FLASH_CR_PG;   
            
          while( IsBusy() );
        }
        
        
        inline static void Lock() noexcept( true ) {
          FLASH->CR &= ~FLASH_CR_PG;
          FLASH->CR |= FLASH_CR_LOCK;
 
          while( IsBusy() );
        }
        
        

        template < class Region > 
        static void Erase() noexcept( true ) {
          static_assert( ( Region::kSectorFirst <= Region::kSectorLast ), "Incorrect sectors number");
          
          if constexpr ( Region::kSectorLast >= kFlashMaxSectorInBank )
            static_assert( ( (Region::kSectorLast - kFlashMaxSectorInBank ) < kSectorInBank ), "Incorrect sectors number" );
            
          if constexpr ( Region::kSectorFirst >= kFlashMaxSectorInBank ) 
            static_assert( ( ( Region::kSectorFirst - kFlashMaxSectorInBank ) < kSectorInBank ), "Incorrect sectors number" );
                    
          while( IsBusy() );
          Unlock();                

          FLASH->CR |= FLASH_CR_EOPIE | FLASH_CR_SER;   
            
          std::uint32_t sector = Region::kSectorFirst;
          do 
          {
            FLASH->CR &= ~FLASH_CR_SNB_Msk;
            FLASH->CR |= static_cast< std::uint32_t >( sector ) << FLASH_CR_SNB_Pos;                                      
            FLASH->CR |= FLASH_CR_STRT;                               
    
            while(!(FLASH->SR & FLASH_SR_EOP));  
            FLASH->SR  = FLASH_SR_EOP;
              
          } while ( sector++ != Region::kSectorLast );
            
          FLASH->CR &= ~( FLASH_CR_EOPIE | FLASH_CR_SER );           
          Lock();
            
          return;
        }
        
        
        template < std::uint32_t tBankId > 
        static void BankErase() noexcept( true ) {
          static_assert( ( kBankNum > 1u ), "Unsupported operation" );
          static_assert( ( (tBankId == 1u) || (tBankId == 2u) ), "Bank number must be equal 1 or 2" );
            
          while( IsBusy() );
          Unlock(); 
          
          FLASH->CR |= FLASH_CR_EOPIE;

          if constexpr (tBankId == 1)
            FLASH->CR |= FLASH_CR_MER;
          else
            FLASH->CR |= 1ul << 15u;
          
          FLASH->CR |= FLASH_CR_STRT;   
            
          while(!(FLASH->SR & FLASH_SR_EOP));  
          FLASH->SR  = FLASH_SR_EOP;

          FLASH->CR &= ~FLASH_CR_EOPIE;           
          Lock();
        }
        
        
            
        inline static void ReadProtection() noexcept( true ) { 
          UnlockOptionByte();
  
          if (!IsReadProtected())
          {
            //FLASH->OPTCR = OPTCR | (0x00A5 << FLASH_OPTCR_RDP_Pos);
            *(volatile std::uint8_t*) 0x40023C15U = 0x55; // Read protection level 1

            //FLASH->OPTCR |= FLASH_OPTCR_OPTSTRT;
            *(volatile std::uint8_t *) 0x40023C14U |= FLASH_OPTCR_OPTSTRT;

            while( IsBusy() );
          }
            
          LockOptionByte(); 
        }
        
        
        
        
        inline static bool IsReadProtected() noexcept( true ) {
           std::uint32_t RDP = (FLASH->OPTCR >> FLASH_OPTCR_RDP_Pos) & 0xFFu;
           return RDP != 0xAA;  
        }
        
      private:
        inline static void UnlockOptionByte() noexcept( true ) {
          FLASH->OPTKEYR = 0x08192A3Bu;
          FLASH->OPTKEYR = 0x4C5D6E7Fu; 

          while( IsBusy() );
        }
        
        
        
        inline static void LockOptionByte() noexcept( true ) {
          FLASH->OPTCR |= FLASH_OPTCR_OPTLOCK;  
          while( IsBusy() );
        }
    };
      
      
  } // inline namespace 
} // namespace mpp::flash

