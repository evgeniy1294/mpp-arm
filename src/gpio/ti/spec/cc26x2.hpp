/**
  ***********************************************************
  @file   /src/gpio/ti/spec/cc26x2.hpp
  @brief          
  ***********************************************************
**/

#pragma once

//____________________INCLUDE_____________________//
#include <cstdint>

/* 
#if !defined (CC1352R)||(CC1352P)||(CC2652R)||(CC2652P)||(CC2652RB)
  #error "You must define supported MCU"
#endif
*/

//_____________________CMSIS______________________//
struct GPIO_TypeDef
{
  volatile std::uint32_t DOUT_3_0;             //!< Data Out 0 to 3
  volatile std::uint32_t DOUT_7_4;             //!< Data Out 7 to 4
  volatile std::uint32_t DOUT_11_8;            //!< Data Out 11 to 8
  volatile std::uint32_t DOUT_15_12;           //!< Data Out 15 to 12
  volatile std::uint32_t DOUT_19_16;           //!< Data Out 19 to 16
  volatile std::uint32_t DOUT_23_20;           //!< Data Out 23 to 20
  volatile std::uint32_t DOUT_27_24;           //!< Data Out 27 to 24
  volatile std::uint32_t DOUT_31_28;           //!< Data Out 31 to 28
  volatile std::uint32_t __resv0[24];          //!< Reserved
  volatile std::uint32_t DOUT;                 //!< Data Output for DIO 0 to 31
  volatile std::uint32_t __resv1[3];           //!< Reserved
  volatile std::uint32_t DOUTSET;              //!< Data Out Set
  volatile std::uint32_t __resv2[3];           //!< Reserved
  volatile std::uint32_t DOUTCLR;              //!< Data Out Clear
  volatile std::uint32_t __resv3[3];           //!< Reserved
  volatile std::uint32_t DOUTTGL;              //!< Data Out Toggle
  volatile std::uint32_t __resv4[3];           //!< Reserved
  volatile std::uint32_t DIN;                  //!< Data Input from DIO 0 to 31
  volatile std::uint32_t __resv5[3];           //!< Reserved
  volatile std::uint32_t DOE;                  //!< Data Output Enable for DIO 0 to 31
  volatile std::uint32_t __resv6[3];           //!< Reserved
  volatile std::uint32_t EVFLAGS;              //!< Event Register for DIO 0 to 31
};



struct IOC_TypeDef
{
  volatile std::uint32_t IOCFG[32];
};



#define GPIO_BASE               0x40022000
#define GPIO_NONBUF_BASE        0x60022000
#define IOC_BASE                0x40081000
#define IOC_NONBUF_BASE         0x60081000
#define GPIO                    ((GPIO_TypeDef *) GPIO_BASE)
#define GPIO_NB                 ((GPIO_TypeDef *) GPIO_NONBUF_BASE)
#define IOC                     ((IOC_TypeDef *)  IOC_BASE)
#define IOC_NB                  ((IOC_TypeDef *)  IOC_NONBUF_BASE)


// Register: GPIO_DOUT3_0
// Field:    [24] DIO3
#define GPIO_DOUT3_0_DIO3                                           0x01000000
#define GPIO_DOUT3_0_DIO3_BITN                                              24
#define GPIO_DOUT3_0_DIO3_M                                         0x01000000
#define GPIO_DOUT3_0_DIO3_S                                                 24

// Field:    [16] DIO2
#define GPIO_DOUT3_0_DIO2                                           0x00010000
#define GPIO_DOUT3_0_DIO2_BITN                                              16
#define GPIO_DOUT3_0_DIO2_M                                         0x00010000
#define GPIO_DOUT3_0_DIO2_S                                                 16

// Field:     [8] DIO1
#define GPIO_DOUT3_0_DIO1                                           0x00000100
#define GPIO_DOUT3_0_DIO1_BITN                                               8
#define GPIO_DOUT3_0_DIO1_M                                         0x00000100
#define GPIO_DOUT3_0_DIO1_S                                                  8

// Field:     [0] DIO0
#define GPIO_DOUT3_0_DIO0                                           0x00000001
#define GPIO_DOUT3_0_DIO0_BITN                                               0
#define GPIO_DOUT3_0_DIO0_M                                         0x00000001
#define GPIO_DOUT3_0_DIO0_S                                                  0



// Register: GPIO_DOUT7_4
// Field:    [24] DIO7
#define GPIO_DOUT7_4_DIO7                                           0x01000000
#define GPIO_DOUT7_4_DIO7_BITN                                              24
#define GPIO_DOUT7_4_DIO7_M                                         0x01000000
#define GPIO_DOUT7_4_DIO7_S                                                 24

// Field:    [16] DIO6
#define GPIO_DOUT7_4_DIO6                                           0x00010000
#define GPIO_DOUT7_4_DIO6_BITN                                              16
#define GPIO_DOUT7_4_DIO6_M                                         0x00010000
#define GPIO_DOUT7_4_DIO6_S                                                 16

// Field:     [8] DIO5
#define GPIO_DOUT7_4_DIO5                                           0x00000100
#define GPIO_DOUT7_4_DIO5_BITN                                               8
#define GPIO_DOUT7_4_DIO5_M                                         0x00000100
#define GPIO_DOUT7_4_DIO5_S                                                  8

// Field:     [0] DIO4
#define GPIO_DOUT7_4_DIO4                                           0x00000001
#define GPIO_DOUT7_4_DIO4_BITN                                               0
#define GPIO_DOUT7_4_DIO4_M                                         0x00000001
#define GPIO_DOUT7_4_DIO4_S                                                  0



// Register: GPIO_DOUT11_8
// Field:    [24] DIO11
#define GPIO_DOUT11_8_DIO11                                         0x01000000
#define GPIO_DOUT11_8_DIO11_BITN                                            24
#define GPIO_DOUT11_8_DIO11_M                                       0x01000000
#define GPIO_DOUT11_8_DIO11_S                                               24

// Field:    [16] DIO10
#define GPIO_DOUT11_8_DIO10                                         0x00010000
#define GPIO_DOUT11_8_DIO10_BITN                                            16
#define GPIO_DOUT11_8_DIO10_M                                       0x00010000
#define GPIO_DOUT11_8_DIO10_S                                               16

// Field:     [8] DIO9
#define GPIO_DOUT11_8_DIO9                                          0x00000100
#define GPIO_DOUT11_8_DIO9_BITN                                              8
#define GPIO_DOUT11_8_DIO9_M                                        0x00000100
#define GPIO_DOUT11_8_DIO9_S                                                 8

// Field:     [0] DIO8
#define GPIO_DOUT11_8_DIO8                                          0x00000001
#define GPIO_DOUT11_8_DIO8_BITN                                              0
#define GPIO_DOUT11_8_DIO8_M                                        0x00000001
#define GPIO_DOUT11_8_DIO8_S                                                 0



// Register: GPIO_DOUT15_12
// Field:    [24] DIO15
#define GPIO_DOUT15_12_DIO15                                        0x01000000
#define GPIO_DOUT15_12_DIO15_BITN                                           24
#define GPIO_DOUT15_12_DIO15_M                                      0x01000000
#define GPIO_DOUT15_12_DIO15_S                                              24

// Field:    [16] DIO14
#define GPIO_DOUT15_12_DIO14                                        0x00010000
#define GPIO_DOUT15_12_DIO14_BITN                                           16
#define GPIO_DOUT15_12_DIO14_M                                      0x00010000
#define GPIO_DOUT15_12_DIO14_S                                              16

// Field:     [8] DIO13
#define GPIO_DOUT15_12_DIO13                                        0x00000100
#define GPIO_DOUT15_12_DIO13_BITN                                            8
#define GPIO_DOUT15_12_DIO13_M                                      0x00000100
#define GPIO_DOUT15_12_DIO13_S                                               8

// Field:     [0] DIO12
#define GPIO_DOUT15_12_DIO12                                        0x00000001
#define GPIO_DOUT15_12_DIO12_BITN                                            0
#define GPIO_DOUT15_12_DIO12_M                                      0x00000001
#define GPIO_DOUT15_12_DIO12_S                                               0



// Register: GPIO_DOUT19_16
// Field:    [24] DIO19
#define GPIO_DOUT19_16_DIO19                                        0x01000000
#define GPIO_DOUT19_16_DIO19_BITN                                           24
#define GPIO_DOUT19_16_DIO19_M                                      0x01000000
#define GPIO_DOUT19_16_DIO19_S                                              24

// Field:    [16] DIO18
#define GPIO_DOUT19_16_DIO18                                        0x00010000
#define GPIO_DOUT19_16_DIO18_BITN                                           16
#define GPIO_DOUT19_16_DIO18_M                                      0x00010000
#define GPIO_DOUT19_16_DIO18_S                                              16

// Field:     [8] DIO17
#define GPIO_DOUT19_16_DIO17                                        0x00000100
#define GPIO_DOUT19_16_DIO17_BITN                                            8
#define GPIO_DOUT19_16_DIO17_M                                      0x00000100
#define GPIO_DOUT19_16_DIO17_S                                               8

// Field:     [0] DIO16
#define GPIO_DOUT19_16_DIO16                                        0x00000001
#define GPIO_DOUT19_16_DIO16_BITN                                            0
#define GPIO_DOUT19_16_DIO16_M                                      0x00000001
#define GPIO_DOUT19_16_DIO16_S                                               0



// Register: GPIO_DOUT23_20
// Field:    [24] DIO23
#define GPIO_DOUT23_20_DIO23                                        0x01000000
#define GPIO_DOUT23_20_DIO23_BITN                                           24
#define GPIO_DOUT23_20_DIO23_M                                      0x01000000
#define GPIO_DOUT23_20_DIO23_S                                              24

// Field:    [16] DIO22
#define GPIO_DOUT23_20_DIO22                                        0x00010000
#define GPIO_DOUT23_20_DIO22_BITN                                           16
#define GPIO_DOUT23_20_DIO22_M                                      0x00010000
#define GPIO_DOUT23_20_DIO22_S                                              16

// Field:     [8] DIO21
#define GPIO_DOUT23_20_DIO21                                        0x00000100
#define GPIO_DOUT23_20_DIO21_BITN                                            8
#define GPIO_DOUT23_20_DIO21_M                                      0x00000100
#define GPIO_DOUT23_20_DIO21_S                                               8

// Field:     [0] DIO20
#define GPIO_DOUT23_20_DIO20                                        0x00000001
#define GPIO_DOUT23_20_DIO20_BITN                                            0
#define GPIO_DOUT23_20_DIO20_M                                      0x00000001
#define GPIO_DOUT23_20_DIO20_S                                               0



// Register: GPIO_DOUT27_24
// Field:    [24] DIO27
#define GPIO_DOUT27_24_DIO27                                        0x01000000
#define GPIO_DOUT27_24_DIO27_BITN                                           24
#define GPIO_DOUT27_24_DIO27_M                                      0x01000000
#define GPIO_DOUT27_24_DIO27_S                                              24

// Field:    [16] DIO26
#define GPIO_DOUT27_24_DIO26                                        0x00010000
#define GPIO_DOUT27_24_DIO26_BITN                                           16
#define GPIO_DOUT27_24_DIO26_M                                      0x00010000
#define GPIO_DOUT27_24_DIO26_S                                              16

// Field:     [8] DIO25
#define GPIO_DOUT27_24_DIO25                                        0x00000100
#define GPIO_DOUT27_24_DIO25_BITN                                            8
#define GPIO_DOUT27_24_DIO25_M                                      0x00000100
#define GPIO_DOUT27_24_DIO25_S                                               8

// Field:     [0] DIO24
#define GPIO_DOUT27_24_DIO24                                        0x00000001
#define GPIO_DOUT27_24_DIO24_BITN                                            0
#define GPIO_DOUT27_24_DIO24_M                                      0x00000001
#define GPIO_DOUT27_24_DIO24_S                                               0



// Register: GPIO_DOUT31_28
// Field:    [24] DIO31
#define GPIO_DOUT31_28_DIO31                                        0x01000000
#define GPIO_DOUT31_28_DIO31_BITN                                           24
#define GPIO_DOUT31_28_DIO31_M                                      0x01000000
#define GPIO_DOUT31_28_DIO31_S                                              24

// Field:    [16] DIO30
#define GPIO_DOUT31_28_DIO30                                        0x00010000
#define GPIO_DOUT31_28_DIO30_BITN                                           16
#define GPIO_DOUT31_28_DIO30_M                                      0x00010000
#define GPIO_DOUT31_28_DIO30_S                                              16

// Field:     [8] DIO29
#define GPIO_DOUT31_28_DIO29                                        0x00000100
#define GPIO_DOUT31_28_DIO29_BITN                                            8
#define GPIO_DOUT31_28_DIO29_M                                      0x00000100
#define GPIO_DOUT31_28_DIO29_S                                               8

// Field:     [0] DIO28
#define GPIO_DOUT31_28_DIO28                                        0x00000001
#define GPIO_DOUT31_28_DIO28_BITN                                            0
#define GPIO_DOUT31_28_DIO28_M                                      0x00000001
#define GPIO_DOUT31_28_DIO28_S                                               0



// Register: GPIO_DOUT
// Field:    [31] DIO31
#define GPIO_DOUT_DIO31                                         0x80000000
#define GPIO_DOUT_DIO31_BITN                                            31
#define GPIO_DOUT_DIO31_M                                       0x80000000
#define GPIO_DOUT_DIO31_S                                               31

// Field:    [30] DIO30
#define GPIO_DOUT_DIO30                                         0x40000000
#define GPIO_DOUT_DIO30_BITN                                            30
#define GPIO_DOUT_DIO30_M                                       0x40000000
#define GPIO_DOUT_DIO30_S                                               30

// Field:    [29] DIO29
#define GPIO_DOUT_DIO29                                         0x20000000
#define GPIO_DOUT_DIO29_BITN                                            29
#define GPIO_DOUT_DIO29_M                                       0x20000000
#define GPIO_DOUT_DIO29_S                                               29

// Field:    [28] DIO28
#define GPIO_DOUT_DIO28                                         0x10000000
#define GPIO_DOUT_DIO28_BITN                                            28
#define GPIO_DOUT_DIO28_M                                       0x10000000
#define GPIO_DOUT_DIO28_S                                               28

// Field:    [27] DIO27
#define GPIO_DOUT_DIO27                                         0x08000000
#define GPIO_DOUT_DIO27_BITN                                            27
#define GPIO_DOUT_DIO27_M                                       0x08000000
#define GPIO_DOUT_DIO27_S                                               27

// Field:    [26] DIO26
#define GPIO_DOUT_DIO26                                         0x04000000
#define GPIO_DOUT_DIO26_BITN                                            26
#define GPIO_DOUT_DIO26_M                                       0x04000000
#define GPIO_DOUT_DIO26_S                                               26

// Field:    [25] DIO25
#define GPIO_DOUT_DIO25                                         0x02000000
#define GPIO_DOUT_DIO25_BITN                                            25
#define GPIO_DOUT_DIO25_M                                       0x02000000
#define GPIO_DOUT_DIO25_S                                               25

// Field:    [24] DIO24
#define GPIO_DOUT_DIO24                                         0x01000000
#define GPIO_DOUT_DIO24_BITN                                            24
#define GPIO_DOUT_DIO24_M                                       0x01000000
#define GPIO_DOUT_DIO24_S                                               24

// Field:    [23] DIO23
#define GPIO_DOUT_DIO23                                         0x00800000
#define GPIO_DOUT_DIO23_BITN                                            23
#define GPIO_DOUT_DIO23_M                                       0x00800000
#define GPIO_DOUT_DIO23_S                                               23

// Field:    [22] DIO22
#define GPIO_DOUT_DIO22                                         0x00400000
#define GPIO_DOUT_DIO22_BITN                                            22
#define GPIO_DOUT_DIO22_M                                       0x00400000
#define GPIO_DOUT_DIO22_S                                               22

// Field:    [21] DIO21
#define GPIO_DOUT_DIO21                                         0x00200000
#define GPIO_DOUT_DIO21_BITN                                            21
#define GPIO_DOUT_DIO21_M                                       0x00200000
#define GPIO_DOUT_DIO21_S                                               21

// Field:    [20] DIO20
#define GPIO_DOUT_DIO20                                         0x00100000
#define GPIO_DOUT_DIO20_BITN                                            20
#define GPIO_DOUT_DIO20_M                                       0x00100000
#define GPIO_DOUT_DIO20_S                                               20

// Field:    [19] DIO19
#define GPIO_DOUT_DIO19                                         0x00080000
#define GPIO_DOUT_DIO19_BITN                                            19
#define GPIO_DOUT_DIO19_M                                       0x00080000
#define GPIO_DOUT_DIO19_S                                               19

// Field:    [18] DIO18
#define GPIO_DOUT_DIO18                                         0x00040000
#define GPIO_DOUT_DIO18_BITN                                            18
#define GPIO_DOUT_DIO18_M                                       0x00040000
#define GPIO_DOUT_DIO18_S                                               18

// Field:    [17] DIO17
#define GPIO_DOUT_DIO17                                         0x00020000
#define GPIO_DOUT_DIO17_BITN                                            17
#define GPIO_DOUT_DIO17_M                                       0x00020000
#define GPIO_DOUT_DIO17_S                                               17

// Field:    [16] DIO16
#define GPIO_DOUT_DIO16                                         0x00010000
#define GPIO_DOUT_DIO16_BITN                                            16
#define GPIO_DOUT_DIO16_M                                       0x00010000
#define GPIO_DOUT_DIO16_S                                               16

// Field:    [15] DIO15
#define GPIO_DOUT_DIO15                                         0x00008000
#define GPIO_DOUT_DIO15_BITN                                            15
#define GPIO_DOUT_DIO15_M                                       0x00008000
#define GPIO_DOUT_DIO15_S                                               15

// Field:    [14] DIO14
#define GPIO_DOUT_DIO14                                         0x00004000
#define GPIO_DOUT_DIO14_BITN                                            14
#define GPIO_DOUT_DIO14_M                                       0x00004000
#define GPIO_DOUT_DIO14_S                                               14

// Field:    [13] DIO13
#define GPIO_DOUT_DIO13                                         0x00002000
#define GPIO_DOUT_DIO13_BITN                                            13
#define GPIO_DOUT_DIO13_M                                       0x00002000
#define GPIO_DOUT_DIO13_S                                               13

// Field:    [12] DIO12
#define GPIO_DOUT_DIO12                                         0x00001000
#define GPIO_DOUT_DIO12_BITN                                            12
#define GPIO_DOUT_DIO12_M                                       0x00001000
#define GPIO_DOUT_DIO12_S                                               12

// Field:    [11] DIO11
#define GPIO_DOUT_DIO11                                         0x00000800
#define GPIO_DOUT_DIO11_BITN                                            11
#define GPIO_DOUT_DIO11_M                                       0x00000800
#define GPIO_DOUT_DIO11_S                                               11

// Field:    [10] DIO10
#define GPIO_DOUT_DIO10                                         0x00000400
#define GPIO_DOUT_DIO10_BITN                                            10
#define GPIO_DOUT_DIO10_M                                       0x00000400
#define GPIO_DOUT_DIO10_S                                               10

// Field:     [9] DIO9
#define GPIO_DOUT_DIO9                                          0x00000200
#define GPIO_DOUT_DIO9_BITN                                              9
#define GPIO_DOUT_DIO9_M                                        0x00000200
#define GPIO_DOUT_DIO9_S                                                 9

// Field:     [8] DIO8
#define GPIO_DOUT_DIO8                                          0x00000100
#define GPIO_DOUT_DIO8_BITN                                              8
#define GPIO_DOUT_DIO8_M                                        0x00000100
#define GPIO_DOUT_DIO8_S                                                 8

// Field:     [7] DIO7
#define GPIO_DOUT_DIO7                                          0x00000080
#define GPIO_DOUT_DIO7_BITN                                              7
#define GPIO_DOUT_DIO7_M                                        0x00000080
#define GPIO_DOUT_DIO7_S                                                 7

// Field:     [6] DIO6
#define GPIO_DOUT_DIO6                                          0x00000040
#define GPIO_DOUT_DIO6_BITN                                              6
#define GPIO_DOUT_DIO6_M                                        0x00000040
#define GPIO_DOUT_DIO6_S                                                 6

// Field:     [5] DIO5
#define GPIO_DOUT_DIO5                                          0x00000020
#define GPIO_DOUT_DIO5_BITN                                              5
#define GPIO_DOUT_DIO5_M                                        0x00000020
#define GPIO_DOUT_DIO5_S                                                 5

// Field:     [4] DIO4
#define GPIO_DOUT_DIO4                                          0x00000010
#define GPIO_DOUT_DIO4_BITN                                              4
#define GPIO_DOUT_DIO4_M                                        0x00000010
#define GPIO_DOUT_DIO4_S                                                 4

// Field:     [3] DIO3
#define GPIO_DOUT_DIO3                                          0x00000008
#define GPIO_DOUT_DIO3_BITN                                              3
#define GPIO_DOUT_DIO3_M                                        0x00000008
#define GPIO_DOUT_DIO3_S                                                 3

// Field:     [2] DIO2
#define GPIO_DOUT_DIO2                                          0x00000004
#define GPIO_DOUT_DIO2_BITN                                              2
#define GPIO_DOUT_DIO2_M                                        0x00000004
#define GPIO_DOUT_DIO2_S                                                 2

// Field:     [1] DIO1
#define GPIO_DOUT_DIO1                                          0x00000002
#define GPIO_DOUT_DIO1_BITN                                              1
#define GPIO_DOUT_DIO1_M                                        0x00000002
#define GPIO_DOUT_DIO1_S                                                 1

// Field:     [0] DIO0
#define GPIO_DOUT_DIO0                                          0x00000001
#define GPIO_DOUT_DIO0_BITN                                              0
#define GPIO_DOUT_DIO0_M                                        0x00000001
#define GPIO_DOUT_DIO0_S                                                 0



// Register: GPIO_DOUTSET
// Field:    [31] DIO31
#define GPIO_DOUTSET_DIO31                                      0x80000000
#define GPIO_DOUTSET_DIO31_BITN                                         31
#define GPIO_DOUTSET_DIO31_M                                    0x80000000
#define GPIO_DOUTSET_DIO31_S                                            31

// Field:    [30] DIO30
#define GPIO_DOUTSET_DIO30                                      0x40000000
#define GPIO_DOUTSET_DIO30_BITN                                         30
#define GPIO_DOUTSET_DIO30_M                                    0x40000000
#define GPIO_DOUTSET_DIO30_S                                            30

// Field:    [29] DIO29
#define GPIO_DOUTSET_DIO29                                      0x20000000
#define GPIO_DOUTSET_DIO29_BITN                                         29
#define GPIO_DOUTSET_DIO29_M                                    0x20000000
#define GPIO_DOUTSET_DIO29_S                                            29

// Field:    [28] DIO28
#define GPIO_DOUTSET_DIO28                                      0x10000000
#define GPIO_DOUTSET_DIO28_BITN                                         28
#define GPIO_DOUTSET_DIO28_M                                    0x10000000
#define GPIO_DOUTSET_DIO28_S                                            28

// Field:    [27] DIO27
#define GPIO_DOUTSET_DIO27                                      0x08000000
#define GPIO_DOUTSET_DIO27_BITN                                         27
#define GPIO_DOUTSET_DIO27_M                                    0x08000000
#define GPIO_DOUTSET_DIO27_S                                            27

// Field:    [26] DIO26
#define GPIO_DOUTSET_DIO26                                      0x04000000
#define GPIO_DOUTSET_DIO26_BITN                                         26
#define GPIO_DOUTSET_DIO26_M                                    0x04000000
#define GPIO_DOUTSET_DIO26_S                                            26

// Field:    [25] DIO25
#define GPIO_DOUTSET_DIO25                                      0x02000000
#define GPIO_DOUTSET_DIO25_BITN                                         25
#define GPIO_DOUTSET_DIO25_M                                    0x02000000
#define GPIO_DOUTSET_DIO25_S                                            25

// Field:    [24] DIO24
#define GPIO_DOUTSET_DIO24                                      0x01000000
#define GPIO_DOUTSET_DIO24_BITN                                         24
#define GPIO_DOUTSET_DIO24_M                                    0x01000000
#define GPIO_DOUTSET_DIO24_S                                            24

// Field:    [23] DIO23
#define GPIO_DOUTSET_DIO23                                      0x00800000
#define GPIO_DOUTSET_DIO23_BITN                                         23
#define GPIO_DOUTSET_DIO23_M                                    0x00800000
#define GPIO_DOUTSET_DIO23_S                                            23

// Field:    [22] DIO22
#define GPIO_DOUTSET_DIO22                                      0x00400000
#define GPIO_DOUTSET_DIO22_BITN                                         22
#define GPIO_DOUTSET_DIO22_M                                    0x00400000
#define GPIO_DOUTSET_DIO22_S                                            22

// Field:    [21] DIO21
#define GPIO_DOUTSET_DIO21                                      0x00200000
#define GPIO_DOUTSET_DIO21_BITN                                         21
#define GPIO_DOUTSET_DIO21_M                                    0x00200000
#define GPIO_DOUTSET_DIO21_S                                            21

// Field:    [20] DIO20
#define GPIO_DOUTSET_DIO20                                      0x00100000
#define GPIO_DOUTSET_DIO20_BITN                                         20
#define GPIO_DOUTSET_DIO20_M                                    0x00100000
#define GPIO_DOUTSET_DIO20_S                                            20

// Field:    [19] DIO19
#define GPIO_DOUTSET_DIO19                                      0x00080000
#define GPIO_DOUTSET_DIO19_BITN                                         19
#define GPIO_DOUTSET_DIO19_M                                    0x00080000
#define GPIO_DOUTSET_DIO19_S                                            19

// Field:    [18] DIO18
#define GPIO_DOUTSET_DIO18                                      0x00040000
#define GPIO_DOUTSET_DIO18_BITN                                         18
#define GPIO_DOUTSET_DIO18_M                                    0x00040000
#define GPIO_DOUTSET_DIO18_S                                            18

// Field:    [17] DIO17
#define GPIO_DOUTSET_DIO17                                      0x00020000
#define GPIO_DOUTSET_DIO17_BITN                                         17
#define GPIO_DOUTSET_DIO17_M                                    0x00020000
#define GPIO_DOUTSET_DIO17_S                                            17

// Field:    [16] DIO16
#define GPIO_DOUTSET_DIO16                                      0x00010000
#define GPIO_DOUTSET_DIO16_BITN                                         16
#define GPIO_DOUTSET_DIO16_M                                    0x00010000
#define GPIO_DOUTSET_DIO16_S                                            16

// Field:    [15] DIO15
#define GPIO_DOUTSET_DIO15                                      0x00008000
#define GPIO_DOUTSET_DIO15_BITN                                         15
#define GPIO_DOUTSET_DIO15_M                                    0x00008000
#define GPIO_DOUTSET_DIO15_S                                            15

// Field:    [14] DIO14
#define GPIO_DOUTSET_DIO14                                      0x00004000
#define GPIO_DOUTSET_DIO14_BITN                                         14
#define GPIO_DOUTSET_DIO14_M                                    0x00004000
#define GPIO_DOUTSET_DIO14_S                                            14

// Field:    [13] DIO13
#define GPIO_DOUTSET_DIO13                                      0x00002000
#define GPIO_DOUTSET_DIO13_BITN                                         13
#define GPIO_DOUTSET_DIO13_M                                    0x00002000
#define GPIO_DOUTSET_DIO13_S                                            13

// Field:    [12] DIO12
#define GPIO_DOUTSET_DIO12                                      0x00001000
#define GPIO_DOUTSET_DIO12_BITN                                         12
#define GPIO_DOUTSET_DIO12_M                                    0x00001000
#define GPIO_DOUTSET_DIO12_S                                            12

// Field:    [11] DIO11
#define GPIO_DOUTSET_DIO11                                      0x00000800
#define GPIO_DOUTSET_DIO11_BITN                                         11
#define GPIO_DOUTSET_DIO11_M                                    0x00000800
#define GPIO_DOUTSET_DIO11_S                                            11

// Field:    [10] DIO10
#define GPIO_DOUTSET_DIO10                                      0x00000400
#define GPIO_DOUTSET_DIO10_BITN                                         10
#define GPIO_DOUTSET_DIO10_M                                    0x00000400
#define GPIO_DOUTSET_DIO10_S                                            10

// Field:     [9] DIO9
#define GPIO_DOUTSET_DIO9                                       0x00000200
#define GPIO_DOUTSET_DIO9_BITN                                           9
#define GPIO_DOUTSET_DIO9_M                                     0x00000200
#define GPIO_DOUTSET_DIO9_S                                              9

// Field:     [8] DIO8
#define GPIO_DOUTSET_DIO8                                       0x00000100
#define GPIO_DOUTSET_DIO8_BITN                                           8
#define GPIO_DOUTSET_DIO8_M                                     0x00000100
#define GPIO_DOUTSET_DIO8_S                                              8

// Field:     [7] DIO7
#define GPIO_DOUTSET_DIO7                                       0x00000080
#define GPIO_DOUTSET_DIO7_BITN                                           7
#define GPIO_DOUTSET_DIO7_M                                     0x00000080
#define GPIO_DOUTSET_DIO7_S                                              7

// Field:     [6] DIO6
#define GPIO_DOUTSET_DIO6                                       0x00000040
#define GPIO_DOUTSET_DIO6_BITN                                           6
#define GPIO_DOUTSET_DIO6_M                                     0x00000040
#define GPIO_DOUTSET_DIO6_S                                              6

// Field:     [5] DIO5
#define GPIO_DOUTSET_DIO5                                       0x00000020
#define GPIO_DOUTSET_DIO5_BITN                                           5
#define GPIO_DOUTSET_DIO5_M                                     0x00000020
#define GPIO_DOUTSET_DIO5_S                                              5

// Field:     [4] DIO4
#define GPIO_DOUTSET_DIO4                                       0x00000010
#define GPIO_DOUTSET_DIO4_BITN                                           4
#define GPIO_DOUTSET_DIO4_M                                     0x00000010
#define GPIO_DOUTSET_DIO4_S                                              4

// Field:     [3] DIO3
#define GPIO_DOUTSET_DIO3                                       0x00000008
#define GPIO_DOUTSET_DIO3_BITN                                           3
#define GPIO_DOUTSET_DIO3_M                                     0x00000008
#define GPIO_DOUTSET_DIO3_S                                              3

// Field:     [2] DIO2
#define GPIO_DOUTSET_DIO2                                       0x00000004
#define GPIO_DOUTSET_DIO2_BITN                                           2
#define GPIO_DOUTSET_DIO2_M                                     0x00000004
#define GPIO_DOUTSET_DIO2_S                                              2

// Field:     [1] DIO1
#define GPIO_DOUTSET_DIO1                                       0x00000002
#define GPIO_DOUTSET_DIO1_BITN                                           1
#define GPIO_DOUTSET_DIO1_M                                     0x00000002
#define GPIO_DOUTSET_DIO1_S                                              1

// Field:     [0] DIO0
#define GPIO_DOUTSET_DIO0                                       0x00000001
#define GPIO_DOUTSET_DIO0_BITN                                           0
#define GPIO_DOUTSET_DIO0_M                                     0x00000001
#define GPIO_DOUTSET_DIO0_S                                              0



// Register: GPIO_DOUTCLR
// Field:    [31] DIO31
#define GPIO_DOUTCLR_DIO31                                      0x80000000
#define GPIO_DOUTCLR_DIO31_BITN                                         31
#define GPIO_DOUTCLR_DIO31_M                                    0x80000000
#define GPIO_DOUTCLR_DIO31_S                                            31

// Field:    [30] DIO30
#define GPIO_DOUTCLR_DIO30                                      0x40000000
#define GPIO_DOUTCLR_DIO30_BITN                                         30
#define GPIO_DOUTCLR_DIO30_M                                    0x40000000
#define GPIO_DOUTCLR_DIO30_S                                            30

// Field:    [29] DIO29
#define GPIO_DOUTCLR_DIO29                                      0x20000000
#define GPIO_DOUTCLR_DIO29_BITN                                         29
#define GPIO_DOUTCLR_DIO29_M                                    0x20000000
#define GPIO_DOUTCLR_DIO29_S                                            29

// Field:    [28] DIO28
#define GPIO_DOUTCLR_DIO28                                      0x10000000
#define GPIO_DOUTCLR_DIO28_BITN                                         28
#define GPIO_DOUTCLR_DIO28_M                                    0x10000000
#define GPIO_DOUTCLR_DIO28_S                                            28

// Field:    [27] DIO27
#define GPIO_DOUTCLR_DIO27                                      0x08000000
#define GPIO_DOUTCLR_DIO27_BITN                                         27
#define GPIO_DOUTCLR_DIO27_M                                    0x08000000
#define GPIO_DOUTCLR_DIO27_S                                            27

// Field:    [26] DIO26
#define GPIO_DOUTCLR_DIO26                                      0x04000000
#define GPIO_DOUTCLR_DIO26_BITN                                         26
#define GPIO_DOUTCLR_DIO26_M                                    0x04000000
#define GPIO_DOUTCLR_DIO26_S                                            26

// Field:    [25] DIO25
#define GPIO_DOUTCLR_DIO25                                      0x02000000
#define GPIO_DOUTCLR_DIO25_BITN                                         25
#define GPIO_DOUTCLR_DIO25_M                                    0x02000000
#define GPIO_DOUTCLR_DIO25_S                                            25

// Field:    [24] DIO24
#define GPIO_DOUTCLR_DIO24                                      0x01000000
#define GPIO_DOUTCLR_DIO24_BITN                                         24
#define GPIO_DOUTCLR_DIO24_M                                    0x01000000
#define GPIO_DOUTCLR_DIO24_S                                            24

// Field:    [23] DIO23
#define GPIO_DOUTCLR_DIO23                                      0x00800000
#define GPIO_DOUTCLR_DIO23_BITN                                         23
#define GPIO_DOUTCLR_DIO23_M                                    0x00800000
#define GPIO_DOUTCLR_DIO23_S                                            23

// Field:    [22] DIO22
#define GPIO_DOUTCLR_DIO22                                      0x00400000
#define GPIO_DOUTCLR_DIO22_BITN                                         22
#define GPIO_DOUTCLR_DIO22_M                                    0x00400000
#define GPIO_DOUTCLR_DIO22_S                                            22

// Field:    [21] DIO21
#define GPIO_DOUTCLR_DIO21                                      0x00200000
#define GPIO_DOUTCLR_DIO21_BITN                                         21
#define GPIO_DOUTCLR_DIO21_M                                    0x00200000
#define GPIO_DOUTCLR_DIO21_S                                            21

// Field:    [20] DIO20
#define GPIO_DOUTCLR_DIO20                                      0x00100000
#define GPIO_DOUTCLR_DIO20_BITN                                         20
#define GPIO_DOUTCLR_DIO20_M                                    0x00100000
#define GPIO_DOUTCLR_DIO20_S                                            20

// Field:    [19] DIO19
#define GPIO_DOUTCLR_DIO19                                      0x00080000
#define GPIO_DOUTCLR_DIO19_BITN                                         19
#define GPIO_DOUTCLR_DIO19_M                                    0x00080000
#define GPIO_DOUTCLR_DIO19_S                                            19

// Field:    [18] DIO18
#define GPIO_DOUTCLR_DIO18                                      0x00040000
#define GPIO_DOUTCLR_DIO18_BITN                                         18
#define GPIO_DOUTCLR_DIO18_M                                    0x00040000
#define GPIO_DOUTCLR_DIO18_S                                            18

// Field:    [17] DIO17
#define GPIO_DOUTCLR_DIO17                                      0x00020000
#define GPIO_DOUTCLR_DIO17_BITN                                         17
#define GPIO_DOUTCLR_DIO17_M                                    0x00020000
#define GPIO_DOUTCLR_DIO17_S                                            17

// Field:    [16] DIO16
#define GPIO_DOUTCLR_DIO16                                      0x00010000
#define GPIO_DOUTCLR_DIO16_BITN                                         16
#define GPIO_DOUTCLR_DIO16_M                                    0x00010000
#define GPIO_DOUTCLR_DIO16_S                                            16

// Field:    [15] DIO15
#define GPIO_DOUTCLR_DIO15                                      0x00008000
#define GPIO_DOUTCLR_DIO15_BITN                                         15
#define GPIO_DOUTCLR_DIO15_M                                    0x00008000
#define GPIO_DOUTCLR_DIO15_S                                            15

// Field:    [14] DIO14
#define GPIO_DOUTCLR_DIO14                                      0x00004000
#define GPIO_DOUTCLR_DIO14_BITN                                         14
#define GPIO_DOUTCLR_DIO14_M                                    0x00004000
#define GPIO_DOUTCLR_DIO14_S                                            14

// Field:    [13] DIO13
#define GPIO_DOUTCLR_DIO13                                      0x00002000
#define GPIO_DOUTCLR_DIO13_BITN                                         13
#define GPIO_DOUTCLR_DIO13_M                                    0x00002000
#define GPIO_DOUTCLR_DIO13_S                                            13

// Field:    [12] DIO12
#define GPIO_DOUTCLR_DIO12                                      0x00001000
#define GPIO_DOUTCLR_DIO12_BITN                                         12
#define GPIO_DOUTCLR_DIO12_M                                    0x00001000
#define GPIO_DOUTCLR_DIO12_S                                            12

// Field:    [11] DIO11
#define GPIO_DOUTCLR_DIO11                                      0x00000800
#define GPIO_DOUTCLR_DIO11_BITN                                         11
#define GPIO_DOUTCLR_DIO11_M                                    0x00000800
#define GPIO_DOUTCLR_DIO11_S                                            11

// Field:    [10] DIO10
#define GPIO_DOUTCLR_DIO10                                      0x00000400
#define GPIO_DOUTCLR_DIO10_BITN                                         10
#define GPIO_DOUTCLR_DIO10_M                                    0x00000400
#define GPIO_DOUTCLR_DIO10_S                                            10

// Field:     [9] DIO9
#define GPIO_DOUTCLR_DIO9                                       0x00000200
#define GPIO_DOUTCLR_DIO9_BITN                                           9
#define GPIO_DOUTCLR_DIO9_M                                     0x00000200
#define GPIO_DOUTCLR_DIO9_S                                              9

// Field:     [8] DIO8
#define GPIO_DOUTCLR_DIO8                                       0x00000100
#define GPIO_DOUTCLR_DIO8_BITN                                           8
#define GPIO_DOUTCLR_DIO8_M                                     0x00000100
#define GPIO_DOUTCLR_DIO8_S                                              8

// Field:     [7] DIO7
#define GPIO_DOUTCLR_DIO7                                       0x00000080
#define GPIO_DOUTCLR_DIO7_BITN                                           7
#define GPIO_DOUTCLR_DIO7_M                                     0x00000080
#define GPIO_DOUTCLR_DIO7_S                                              7

// Field:     [6] DIO6
#define GPIO_DOUTCLR_DIO6                                       0x00000040
#define GPIO_DOUTCLR_DIO6_BITN                                           6
#define GPIO_DOUTCLR_DIO6_M                                     0x00000040
#define GPIO_DOUTCLR_DIO6_S                                              6

// Field:     [5] DIO5
#define GPIO_DOUTCLR_DIO5                                       0x00000020
#define GPIO_DOUTCLR_DIO5_BITN                                           5
#define GPIO_DOUTCLR_DIO5_M                                     0x00000020
#define GPIO_DOUTCLR_DIO5_S                                              5

// Field:     [4] DIO4
#define GPIO_DOUTCLR_DIO4                                       0x00000010
#define GPIO_DOUTCLR_DIO4_BITN                                           4
#define GPIO_DOUTCLR_DIO4_M                                     0x00000010
#define GPIO_DOUTCLR_DIO4_S                                              4

// Field:     [3] DIO3
#define GPIO_DOUTCLR_DIO3                                       0x00000008
#define GPIO_DOUTCLR_DIO3_BITN                                           3
#define GPIO_DOUTCLR_DIO3_M                                     0x00000008
#define GPIO_DOUTCLR_DIO3_S                                              3

// Field:     [2] DIO2
#define GPIO_DOUTCLR_DIO2                                       0x00000004
#define GPIO_DOUTCLR_DIO2_BITN                                           2
#define GPIO_DOUTCLR_DIO2_M                                     0x00000004
#define GPIO_DOUTCLR_DIO2_S                                              2

// Field:     [1] DIO1
#define GPIO_DOUTCLR_DIO1                                       0x00000002
#define GPIO_DOUTCLR_DIO1_BITN                                           1
#define GPIO_DOUTCLR_DIO1_M                                     0x00000002
#define GPIO_DOUTCLR_DIO1_S                                              1

// Field:     [0] DIO0
#define GPIO_DOUTCLR_DIO0                                       0x00000001
#define GPIO_DOUTCLR_DIO0_BITN                                           0
#define GPIO_DOUTCLR_DIO0_M                                     0x00000001
#define GPIO_DOUTCLR_DIO0_S                                              0



// Register: GPIO_DOUTTGL
// Field:    [31] DIO31
#define GPIO_DOUTTGL_DIO31                                      0x80000000
#define GPIO_DOUTTGL_DIO31_BITN                                         31
#define GPIO_DOUTTGL_DIO31_M                                    0x80000000
#define GPIO_DOUTTGL_DIO31_S                                            31

// Field:    [30] DIO30
#define GPIO_DOUTTGL_DIO30                                      0x40000000
#define GPIO_DOUTTGL_DIO30_BITN                                         30
#define GPIO_DOUTTGL_DIO30_M                                    0x40000000
#define GPIO_DOUTTGL_DIO30_S                                            30

// Field:    [29] DIO29
#define GPIO_DOUTTGL_DIO29                                      0x20000000
#define GPIO_DOUTTGL_DIO29_BITN                                         29
#define GPIO_DOUTTGL_DIO29_M                                    0x20000000
#define GPIO_DOUTTGL_DIO29_S                                            29

// Field:    [28] DIO28
#define GPIO_DOUTTGL_DIO28                                      0x10000000
#define GPIO_DOUTTGL_DIO28_BITN                                         28
#define GPIO_DOUTTGL_DIO28_M                                    0x10000000
#define GPIO_DOUTTGL_DIO28_S                                            28

// Field:    [27] DIO27
#define GPIO_DOUTTGL_DIO27                                      0x08000000
#define GPIO_DOUTTGL_DIO27_BITN                                         27
#define GPIO_DOUTTGL_DIO27_M                                    0x08000000
#define GPIO_DOUTTGL_DIO27_S                                            27

// Field:    [26] DIO26
#define GPIO_DOUTTGL_DIO26                                      0x04000000
#define GPIO_DOUTTGL_DIO26_BITN                                         26
#define GPIO_DOUTTGL_DIO26_M                                    0x04000000
#define GPIO_DOUTTGL_DIO26_S                                            26

// Field:    [25] DIO25
#define GPIO_DOUTTGL_DIO25                                      0x02000000
#define GPIO_DOUTTGL_DIO25_BITN                                         25
#define GPIO_DOUTTGL_DIO25_M                                    0x02000000
#define GPIO_DOUTTGL_DIO25_S                                            25

// Field:    [24] DIO24
#define GPIO_DOUTTGL_DIO24                                      0x01000000
#define GPIO_DOUTTGL_DIO24_BITN                                         24
#define GPIO_DOUTTGL_DIO24_M                                    0x01000000
#define GPIO_DOUTTGL_DIO24_S                                            24

// Field:    [23] DIO23
#define GPIO_DOUTTGL_DIO23                                      0x00800000
#define GPIO_DOUTTGL_DIO23_BITN                                         23
#define GPIO_DOUTTGL_DIO23_M                                    0x00800000
#define GPIO_DOUTTGL_DIO23_S                                            23

// Field:    [22] DIO22
#define GPIO_DOUTTGL_DIO22                                      0x00400000
#define GPIO_DOUTTGL_DIO22_BITN                                         22
#define GPIO_DOUTTGL_DIO22_M                                    0x00400000
#define GPIO_DOUTTGL_DIO22_S                                            22

// Field:    [21] DIO21
#define GPIO_DOUTTGL_DIO21                                      0x00200000
#define GPIO_DOUTTGL_DIO21_BITN                                         21
#define GPIO_DOUTTGL_DIO21_M                                    0x00200000
#define GPIO_DOUTTGL_DIO21_S                                            21

// Field:    [20] DIO20
#define GPIO_DOUTTGL_DIO20                                      0x00100000
#define GPIO_DOUTTGL_DIO20_BITN                                         20
#define GPIO_DOUTTGL_DIO20_M                                    0x00100000
#define GPIO_DOUTTGL_DIO20_S                                            20

// Field:    [19] DIO19
#define GPIO_DOUTTGL_DIO19                                      0x00080000
#define GPIO_DOUTTGL_DIO19_BITN                                         19
#define GPIO_DOUTTGL_DIO19_M                                    0x00080000
#define GPIO_DOUTTGL_DIO19_S                                            19

// Field:    [18] DIO18
#define GPIO_DOUTTGL_DIO18                                      0x00040000
#define GPIO_DOUTTGL_DIO18_BITN                                         18
#define GPIO_DOUTTGL_DIO18_M                                    0x00040000
#define GPIO_DOUTTGL_DIO18_S                                            18

// Field:    [17] DIO17
#define GPIO_DOUTTGL_DIO17                                      0x00020000
#define GPIO_DOUTTGL_DIO17_BITN                                         17
#define GPIO_DOUTTGL_DIO17_M                                    0x00020000
#define GPIO_DOUTTGL_DIO17_S                                            17

// Field:    [16] DIO16
#define GPIO_DOUTTGL_DIO16                                      0x00010000
#define GPIO_DOUTTGL_DIO16_BITN                                         16
#define GPIO_DOUTTGL_DIO16_M                                    0x00010000
#define GPIO_DOUTTGL_DIO16_S                                            16

// Field:    [15] DIO15
#define GPIO_DOUTTGL_DIO15                                      0x00008000
#define GPIO_DOUTTGL_DIO15_BITN                                         15
#define GPIO_DOUTTGL_DIO15_M                                    0x00008000
#define GPIO_DOUTTGL_DIO15_S                                            15

// Field:    [14] DIO14
#define GPIO_DOUTTGL_DIO14                                      0x00004000
#define GPIO_DOUTTGL_DIO14_BITN                                         14
#define GPIO_DOUTTGL_DIO14_M                                    0x00004000
#define GPIO_DOUTTGL_DIO14_S                                            14

// Field:    [13] DIO13
#define GPIO_DOUTTGL_DIO13                                      0x00002000
#define GPIO_DOUTTGL_DIO13_BITN                                         13
#define GPIO_DOUTTGL_DIO13_M                                    0x00002000
#define GPIO_DOUTTGL_DIO13_S                                            13

// Field:    [12] DIO12
#define GPIO_DOUTTGL_DIO12                                      0x00001000
#define GPIO_DOUTTGL_DIO12_BITN                                         12
#define GPIO_DOUTTGL_DIO12_M                                    0x00001000
#define GPIO_DOUTTGL_DIO12_S                                            12

// Field:    [11] DIO11
#define GPIO_DOUTTGL_DIO11                                      0x00000800
#define GPIO_DOUTTGL_DIO11_BITN                                         11
#define GPIO_DOUTTGL_DIO11_M                                    0x00000800
#define GPIO_DOUTTGL_DIO11_S                                            11

// Field:    [10] DIO10
#define GPIO_DOUTTGL_DIO10                                      0x00000400
#define GPIO_DOUTTGL_DIO10_BITN                                         10
#define GPIO_DOUTTGL_DIO10_M                                    0x00000400
#define GPIO_DOUTTGL_DIO10_S                                            10

// Field:     [9] DIO9
#define GPIO_DOUTTGL_DIO9                                       0x00000200
#define GPIO_DOUTTGL_DIO9_BITN                                           9
#define GPIO_DOUTTGL_DIO9_M                                     0x00000200
#define GPIO_DOUTTGL_DIO9_S                                              9

// Field:     [8] DIO8
#define GPIO_DOUTTGL_DIO8                                       0x00000100
#define GPIO_DOUTTGL_DIO8_BITN                                           8
#define GPIO_DOUTTGL_DIO8_M                                     0x00000100
#define GPIO_DOUTTGL_DIO8_S                                              8

// Field:     [7] DIO7
#define GPIO_DOUTTGL_DIO7                                       0x00000080
#define GPIO_DOUTTGL_DIO7_BITN                                           7
#define GPIO_DOUTTGL_DIO7_M                                     0x00000080
#define GPIO_DOUTTGL_DIO7_S                                              7

// Field:     [6] DIO6
#define GPIO_DOUTTGL_DIO6                                       0x00000040
#define GPIO_DOUTTGL_DIO6_BITN                                           6
#define GPIO_DOUTTGL_DIO6_M                                     0x00000040
#define GPIO_DOUTTGL_DIO6_S                                              6

// Field:     [5] DIO5
#define GPIO_DOUTTGL_DIO5                                       0x00000020
#define GPIO_DOUTTGL_DIO5_BITN                                           5
#define GPIO_DOUTTGL_DIO5_M                                     0x00000020
#define GPIO_DOUTTGL_DIO5_S                                              5

// Field:     [4] DIO4
#define GPIO_DOUTTGL_DIO4                                       0x00000010
#define GPIO_DOUTTGL_DIO4_BITN                                           4
#define GPIO_DOUTTGL_DIO4_M                                     0x00000010
#define GPIO_DOUTTGL_DIO4_S                                              4

// Field:     [3] DIO3
#define GPIO_DOUTTGL_DIO3                                       0x00000008
#define GPIO_DOUTTGL_DIO3_BITN                                           3
#define GPIO_DOUTTGL_DIO3_M                                     0x00000008
#define GPIO_DOUTTGL_DIO3_S                                              3

// Field:     [2] DIO2
#define GPIO_DOUTTGL_DIO2                                       0x00000004
#define GPIO_DOUTTGL_DIO2_BITN                                           2
#define GPIO_DOUTTGL_DIO2_M                                     0x00000004
#define GPIO_DOUTTGL_DIO2_S                                              2

// Field:     [1] DIO1
#define GPIO_DOUTTGL_DIO1                                       0x00000002
#define GPIO_DOUTTGL_DIO1_BITN                                           1
#define GPIO_DOUTTGL_DIO1_M                                     0x00000002
#define GPIO_DOUTTGL_DIO1_S                                              1

// Field:     [0] DIO0
#define GPIO_DOUTTGL_DIO0                                       0x00000001
#define GPIO_DOUTTGL_DIO0_BITN                                           0
#define GPIO_DOUTTGL_DIO0_M                                     0x00000001
#define GPIO_DOUTTGL_DIO0_S                                              0



// Register: GPIO_DIN
// Field:    [31] DIO31
#define GPIO_DIN_DIO31                                          0x80000000
#define GPIO_DIN_DIO31_BITN                                             31
#define GPIO_DIN_DIO31_M                                        0x80000000
#define GPIO_DIN_DIO31_S                                                31

// Field:    [30] DIO30
#define GPIO_DIN_DIO30                                          0x40000000
#define GPIO_DIN_DIO30_BITN                                             30
#define GPIO_DIN_DIO30_M                                        0x40000000
#define GPIO_DIN_DIO30_S                                                30

// Field:    [29] DIO29
#define GPIO_DIN_DIO29                                          0x20000000
#define GPIO_DIN_DIO29_BITN                                             29
#define GPIO_DIN_DIO29_M                                        0x20000000
#define GPIO_DIN_DIO29_S                                                29

// Field:    [28] DIO28
#define GPIO_DIN_DIO28                                          0x10000000
#define GPIO_DIN_DIO28_BITN                                             28
#define GPIO_DIN_DIO28_M                                        0x10000000
#define GPIO_DIN_DIO28_S                                                28

// Field:    [27] DIO27
#define GPIO_DIN_DIO27                                          0x08000000
#define GPIO_DIN_DIO27_BITN                                             27
#define GPIO_DIN_DIO27_M                                        0x08000000
#define GPIO_DIN_DIO27_S                                                27

// Field:    [26] DIO26
#define GPIO_DIN_DIO26                                          0x04000000
#define GPIO_DIN_DIO26_BITN                                             26
#define GPIO_DIN_DIO26_M                                        0x04000000
#define GPIO_DIN_DIO26_S                                                26

// Field:    [25] DIO25
#define GPIO_DIN_DIO25                                          0x02000000
#define GPIO_DIN_DIO25_BITN                                             25
#define GPIO_DIN_DIO25_M                                        0x02000000
#define GPIO_DIN_DIO25_S                                                25

// Field:    [24] DIO24
#define GPIO_DIN_DIO24                                          0x01000000
#define GPIO_DIN_DIO24_BITN                                             24
#define GPIO_DIN_DIO24_M                                        0x01000000
#define GPIO_DIN_DIO24_S                                                24

// Field:    [23] DIO23
#define GPIO_DIN_DIO23                                          0x00800000
#define GPIO_DIN_DIO23_BITN                                             23
#define GPIO_DIN_DIO23_M                                        0x00800000
#define GPIO_DIN_DIO23_S                                                23

// Field:    [22] DIO22
#define GPIO_DIN_DIO22                                          0x00400000
#define GPIO_DIN_DIO22_BITN                                             22
#define GPIO_DIN_DIO22_M                                        0x00400000
#define GPIO_DIN_DIO22_S                                                22

// Field:    [21] DIO21
#define GPIO_DIN_DIO21                                          0x00200000
#define GPIO_DIN_DIO21_BITN                                             21
#define GPIO_DIN_DIO21_M                                        0x00200000
#define GPIO_DIN_DIO21_S                                                21

// Field:    [20] DIO20
#define GPIO_DIN_DIO20                                          0x00100000
#define GPIO_DIN_DIO20_BITN                                             20
#define GPIO_DIN_DIO20_M                                        0x00100000
#define GPIO_DIN_DIO20_S                                                20

// Field:    [19] DIO19
#define GPIO_DIN_DIO19                                          0x00080000
#define GPIO_DIN_DIO19_BITN                                             19
#define GPIO_DIN_DIO19_M                                        0x00080000
#define GPIO_DIN_DIO19_S                                                19

// Field:    [18] DIO18
#define GPIO_DIN_DIO18                                          0x00040000
#define GPIO_DIN_DIO18_BITN                                             18
#define GPIO_DIN_DIO18_M                                        0x00040000
#define GPIO_DIN_DIO18_S                                                18

// Field:    [17] DIO17
#define GPIO_DIN_DIO17                                          0x00020000
#define GPIO_DIN_DIO17_BITN                                             17
#define GPIO_DIN_DIO17_M                                        0x00020000
#define GPIO_DIN_DIO17_S                                                17

// Field:    [16] DIO16
#define GPIO_DIN_DIO16                                          0x00010000
#define GPIO_DIN_DIO16_BITN                                             16
#define GPIO_DIN_DIO16_M                                        0x00010000
#define GPIO_DIN_DIO16_S                                                16

// Field:    [15] DIO15
#define GPIO_DIN_DIO15                                          0x00008000
#define GPIO_DIN_DIO15_BITN                                             15
#define GPIO_DIN_DIO15_M                                        0x00008000
#define GPIO_DIN_DIO15_S                                                15

// Field:    [14] DIO14
#define GPIO_DIN_DIO14                                          0x00004000
#define GPIO_DIN_DIO14_BITN                                             14
#define GPIO_DIN_DIO14_M                                        0x00004000
#define GPIO_DIN_DIO14_S                                                14

// Field:    [13] DIO13
#define GPIO_DIN_DIO13                                          0x00002000
#define GPIO_DIN_DIO13_BITN                                             13
#define GPIO_DIN_DIO13_M                                        0x00002000
#define GPIO_DIN_DIO13_S                                                13

// Field:    [12] DIO12
#define GPIO_DIN_DIO12                                          0x00001000
#define GPIO_DIN_DIO12_BITN                                             12
#define GPIO_DIN_DIO12_M                                        0x00001000
#define GPIO_DIN_DIO12_S                                                12

// Field:    [11] DIO11
#define GPIO_DIN_DIO11                                          0x00000800
#define GPIO_DIN_DIO11_BITN                                             11
#define GPIO_DIN_DIO11_M                                        0x00000800
#define GPIO_DIN_DIO11_S                                                11

// Field:    [10] DIO10
#define GPIO_DIN_DIO10                                          0x00000400
#define GPIO_DIN_DIO10_BITN                                             10
#define GPIO_DIN_DIO10_M                                        0x00000400
#define GPIO_DIN_DIO10_S                                                10

// Field:     [9] DIO9
#define GPIO_DIN_DIO9                                           0x00000200
#define GPIO_DIN_DIO9_BITN                                               9
#define GPIO_DIN_DIO9_M                                         0x00000200
#define GPIO_DIN_DIO9_S                                                  9

// Field:     [8] DIO8
#define GPIO_DIN_DIO8                                           0x00000100
#define GPIO_DIN_DIO8_BITN                                               8
#define GPIO_DIN_DIO8_M                                         0x00000100
#define GPIO_DIN_DIO8_S                                                  8

// Field:     [7] DIO7
#define GPIO_DIN_DIO7                                           0x00000080
#define GPIO_DIN_DIO7_BITN                                               7
#define GPIO_DIN_DIO7_M                                         0x00000080
#define GPIO_DIN_DIO7_S                                                  7

// Field:     [6] DIO6
#define GPIO_DIN_DIO6                                           0x00000040
#define GPIO_DIN_DIO6_BITN                                               6
#define GPIO_DIN_DIO6_M                                         0x00000040
#define GPIO_DIN_DIO6_S                                                  6

// Field:     [5] DIO5
#define GPIO_DIN_DIO5                                           0x00000020
#define GPIO_DIN_DIO5_BITN                                               5
#define GPIO_DIN_DIO5_M                                         0x00000020
#define GPIO_DIN_DIO5_S                                                  5

// Field:     [4] DIO4
#define GPIO_DIN_DIO4                                           0x00000010
#define GPIO_DIN_DIO4_BITN                                               4
#define GPIO_DIN_DIO4_M                                         0x00000010
#define GPIO_DIN_DIO4_S                                                  4

// Field:     [3] DIO3
#define GPIO_DIN_DIO3                                           0x00000008
#define GPIO_DIN_DIO3_BITN                                               3
#define GPIO_DIN_DIO3_M                                         0x00000008
#define GPIO_DIN_DIO3_S                                                  3

// Field:     [2] DIO2
#define GPIO_DIN_DIO2                                           0x00000004
#define GPIO_DIN_DIO2_BITN                                               2
#define GPIO_DIN_DIO2_M                                         0x00000004
#define GPIO_DIN_DIO2_S                                                  2

// Field:     [1] DIO1
#define GPIO_DIN_DIO1                                           0x00000002
#define GPIO_DIN_DIO1_BITN                                               1
#define GPIO_DIN_DIO1_M                                         0x00000002
#define GPIO_DIN_DIO1_S                                                  1

// Field:     [0] DIO0
#define GPIO_DIN_DIO0                                           0x00000001
#define GPIO_DIN_DIO0_BITN                                               0
#define GPIO_DIN_DIO0_M                                         0x00000001
#define GPIO_DIN_DIO0_S                                                  0



// Register: GPIO_DOE
// Field:    [31] DIO31
#define GPIO_DOE_DIO31                                          0x80000000
#define GPIO_DOE_DIO31_BITN                                             31
#define GPIO_DOE_DIO31_M                                        0x80000000
#define GPIO_DOE_DIO31_S                                                31

// Field:    [30] DIO30
#define GPIO_DOE_DIO30                                          0x40000000
#define GPIO_DOE_DIO30_BITN                                             30
#define GPIO_DOE_DIO30_M                                        0x40000000
#define GPIO_DOE_DIO30_S                                                30

// Field:    [29] DIO29
#define GPIO_DOE_DIO29                                          0x20000000
#define GPIO_DOE_DIO29_BITN                                             29
#define GPIO_DOE_DIO29_M                                        0x20000000
#define GPIO_DOE_DIO29_S                                                29

// Field:    [28] DIO28
#define GPIO_DOE_DIO28                                          0x10000000
#define GPIO_DOE_DIO28_BITN                                             28
#define GPIO_DOE_DIO28_M                                        0x10000000
#define GPIO_DOE_DIO28_S                                                28

// Field:    [27] DIO27
#define GPIO_DOE_DIO27                                          0x08000000
#define GPIO_DOE_DIO27_BITN                                             27
#define GPIO_DOE_DIO27_M                                        0x08000000
#define GPIO_DOE_DIO27_S                                                27

// Field:    [26] DIO26
#define GPIO_DOE_DIO26                                          0x04000000
#define GPIO_DOE_DIO26_BITN                                             26
#define GPIO_DOE_DIO26_M                                        0x04000000
#define GPIO_DOE_DIO26_S                                                26

// Field:    [25] DIO25
#define GPIO_DOE_DIO25                                          0x02000000
#define GPIO_DOE_DIO25_BITN                                             25
#define GPIO_DOE_DIO25_M                                        0x02000000
#define GPIO_DOE_DIO25_S                                                25

// Field:    [24] DIO24
#define GPIO_DOE_DIO24                                          0x01000000
#define GPIO_DOE_DIO24_BITN                                             24
#define GPIO_DOE_DIO24_M                                        0x01000000
#define GPIO_DOE_DIO24_S                                                24

// Field:    [23] DIO23
#define GPIO_DOE_DIO23                                          0x00800000
#define GPIO_DOE_DIO23_BITN                                             23
#define GPIO_DOE_DIO23_M                                        0x00800000
#define GPIO_DOE_DIO23_S                                                23

// Field:    [22] DIO22
#define GPIO_DOE_DIO22                                          0x00400000
#define GPIO_DOE_DIO22_BITN                                             22
#define GPIO_DOE_DIO22_M                                        0x00400000
#define GPIO_DOE_DIO22_S                                                22

// Field:    [21] DIO21
#define GPIO_DOE_DIO21                                          0x00200000
#define GPIO_DOE_DIO21_BITN                                             21
#define GPIO_DOE_DIO21_M                                        0x00200000
#define GPIO_DOE_DIO21_S                                                21

// Field:    [20] DIO20
#define GPIO_DOE_DIO20                                          0x00100000
#define GPIO_DOE_DIO20_BITN                                             20
#define GPIO_DOE_DIO20_M                                        0x00100000
#define GPIO_DOE_DIO20_S                                                20

// Field:    [19] DIO19
#define GPIO_DOE_DIO19                                          0x00080000
#define GPIO_DOE_DIO19_BITN                                             19
#define GPIO_DOE_DIO19_M                                        0x00080000
#define GPIO_DOE_DIO19_S                                                19

// Field:    [18] DIO18
#define GPIO_DOE_DIO18                                          0x00040000
#define GPIO_DOE_DIO18_BITN                                             18
#define GPIO_DOE_DIO18_M                                        0x00040000
#define GPIO_DOE_DIO18_S                                                18

// Field:    [17] DIO17
#define GPIO_DOE_DIO17                                          0x00020000
#define GPIO_DOE_DIO17_BITN                                             17
#define GPIO_DOE_DIO17_M                                        0x00020000
#define GPIO_DOE_DIO17_S                                                17

// Field:    [16] DIO16
#define GPIO_DOE_DIO16                                          0x00010000
#define GPIO_DOE_DIO16_BITN                                             16
#define GPIO_DOE_DIO16_M                                        0x00010000
#define GPIO_DOE_DIO16_S                                                16

// Field:    [15] DIO15
#define GPIO_DOE_DIO15                                          0x00008000
#define GPIO_DOE_DIO15_BITN                                             15
#define GPIO_DOE_DIO15_M                                        0x00008000
#define GPIO_DOE_DIO15_S                                                15

// Field:    [14] DIO14
#define GPIO_DOE_DIO14                                          0x00004000
#define GPIO_DOE_DIO14_BITN                                             14
#define GPIO_DOE_DIO14_M                                        0x00004000
#define GPIO_DOE_DIO14_S                                                14

// Field:    [13] DIO13
#define GPIO_DOE_DIO13                                          0x00002000
#define GPIO_DOE_DIO13_BITN                                             13
#define GPIO_DOE_DIO13_M                                        0x00002000
#define GPIO_DOE_DIO13_S                                                13

// Field:    [12] DIO12
#define GPIO_DOE_DIO12                                          0x00001000
#define GPIO_DOE_DIO12_BITN                                             12
#define GPIO_DOE_DIO12_M                                        0x00001000
#define GPIO_DOE_DIO12_S                                                12

// Field:    [11] DIO11
#define GPIO_DOE_DIO11                                          0x00000800
#define GPIO_DOE_DIO11_BITN                                             11
#define GPIO_DOE_DIO11_M                                        0x00000800
#define GPIO_DOE_DIO11_S                                                11

// Field:    [10] DIO10
#define GPIO_DOE_DIO10                                          0x00000400
#define GPIO_DOE_DIO10_BITN                                             10
#define GPIO_DOE_DIO10_M                                        0x00000400
#define GPIO_DOE_DIO10_S                                                10

// Field:     [9] DIO9
#define GPIO_DOE_DIO9                                           0x00000200
#define GPIO_DOE_DIO9_BITN                                               9
#define GPIO_DOE_DIO9_M                                         0x00000200
#define GPIO_DOE_DIO9_S                                                  9

// Field:     [8] DIO8
#define GPIO_DOE_DIO8                                           0x00000100
#define GPIO_DOE_DIO8_BITN                                               8
#define GPIO_DOE_DIO8_M                                         0x00000100
#define GPIO_DOE_DIO8_S                                                  8

// Field:     [7] DIO7
#define GPIO_DOE_DIO7                                           0x00000080
#define GPIO_DOE_DIO7_BITN                                               7
#define GPIO_DOE_DIO7_M                                         0x00000080
#define GPIO_DOE_DIO7_S                                                  7

// Field:     [6] DIO6
#define GPIO_DOE_DIO6                                           0x00000040
#define GPIO_DOE_DIO6_BITN                                               6
#define GPIO_DOE_DIO6_M                                         0x00000040
#define GPIO_DOE_DIO6_S                                                  6

// Field:     [5] DIO5
#define GPIO_DOE_DIO5                                           0x00000020
#define GPIO_DOE_DIO5_BITN                                               5
#define GPIO_DOE_DIO5_M                                         0x00000020
#define GPIO_DOE_DIO5_S                                                  5

// Field:     [4] DIO4
#define GPIO_DOE_DIO4                                           0x00000010
#define GPIO_DOE_DIO4_BITN                                               4
#define GPIO_DOE_DIO4_M                                         0x00000010
#define GPIO_DOE_DIO4_S                                                  4

// Field:     [3] DIO3
#define GPIO_DOE_DIO3                                           0x00000008
#define GPIO_DOE_DIO3_BITN                                               3
#define GPIO_DOE_DIO3_M                                         0x00000008
#define GPIO_DOE_DIO3_S                                                  3

// Field:     [2] DIO2
#define GPIO_DOE_DIO2                                           0x00000004
#define GPIO_DOE_DIO2_BITN                                               2
#define GPIO_DOE_DIO2_M                                         0x00000004
#define GPIO_DOE_DIO2_S                                                  2

// Field:     [1] DIO1
#define GPIO_DOE_DIO1                                           0x00000002
#define GPIO_DOE_DIO1_BITN                                               1
#define GPIO_DOE_DIO1_M                                         0x00000002
#define GPIO_DOE_DIO1_S                                                  1

// Field:     [0] DIO0
#define GPIO_DOE_DIO0                                           0x00000001
#define GPIO_DOE_DIO0_BITN                                               0
#define GPIO_DOE_DIO0_M                                         0x00000001
#define GPIO_DOE_DIO0_S                                                  0



// Register: GPIO_O_EVFLAGS31_0
// Field:    [31] DIO31
#define GPIO_EVFLAGS_DIO31                                      0x80000000
#define GPIO_EVFLAGS_DIO31_BITN                                         31
#define GPIO_EVFLAGS_DIO31_M                                    0x80000000
#define GPIO_EVFLAGS_DIO31_S                                            31

// Field:    [30] DIO30
#define GPIO_EVFLAGS_DIO30                                      0x40000000
#define GPIO_EVFLAGS_DIO30_BITN                                         30
#define GPIO_EVFLAGS_DIO30_M                                    0x40000000
#define GPIO_EVFLAGS_DIO30_S                                            30

// Field:    [29] DIO29
#define GPIO_EVFLAGS_DIO29                                      0x20000000
#define GPIO_EVFLAGS_DIO29_BITN                                         29
#define GPIO_EVFLAGS_DIO29_M                                    0x20000000
#define GPIO_EVFLAGS_DIO29_S                                            29

// Field:    [28] DIO28
#define GPIO_EVFLAGS_DIO28                                      0x10000000
#define GPIO_EVFLAGS_DIO28_BITN                                         28
#define GPIO_EVFLAGS_DIO28_M                                    0x10000000
#define GPIO_EVFLAGS_DIO28_S                                            28

// Field:    [27] DIO27
#define GPIO_EVFLAGS_DIO27                                      0x08000000
#define GPIO_EVFLAGS_DIO27_BITN                                         27
#define GPIO_EVFLAGS_DIO27_M                                    0x08000000
#define GPIO_EVFLAGS_DIO27_S                                            27

// Field:    [26] DIO26
#define GPIO_EVFLAGS_DIO26                                      0x04000000
#define GPIO_EVFLAGS_DIO26_BITN                                         26
#define GPIO_EVFLAGS_DIO26_M                                    0x04000000
#define GPIO_EVFLAGS_DIO26_S                                            26

// Field:    [25] DIO25
#define GPIO_EVFLAGS_DIO25                                      0x02000000
#define GPIO_EVFLAGS_DIO25_BITN                                         25
#define GPIO_EVFLAGS_DIO25_M                                    0x02000000
#define GPIO_EVFLAGS_DIO25_S                                            25

// Field:    [24] DIO24
#define GPIO_EVFLAGS_DIO24                                      0x01000000
#define GPIO_EVFLAGS_DIO24_BITN                                         24
#define GPIO_EVFLAGS_DIO24_M                                    0x01000000
#define GPIO_EVFLAGS_DIO24_S                                            24

// Field:    [23] DIO23
#define GPIO_EVFLAGS_DIO23                                      0x00800000
#define GPIO_EVFLAGS_DIO23_BITN                                         23
#define GPIO_EVFLAGS_DIO23_M                                    0x00800000
#define GPIO_EVFLAGS_DIO23_S                                            23

// Field:    [22] DIO22
#define GPIO_EVFLAGS_DIO22                                      0x00400000
#define GPIO_EVFLAGS_DIO22_BITN                                         22
#define GPIO_EVFLAGS_DIO22_M                                    0x00400000
#define GPIO_EVFLAGS_DIO22_S                                            22

// Field:    [21] DIO21
#define GPIO_EVFLAGS_DIO21                                      0x00200000
#define GPIO_EVFLAGS_DIO21_BITN                                         21
#define GPIO_EVFLAGS_DIO21_M                                    0x00200000
#define GPIO_EVFLAGS_DIO21_S                                            21

// Field:    [20] DIO20
#define GPIO_EVFLAGS_DIO20                                      0x00100000
#define GPIO_EVFLAGS_DIO20_BITN                                         20
#define GPIO_EVFLAGS_DIO20_M                                    0x00100000
#define GPIO_EVFLAGS_DIO20_S                                            20

// Field:    [19] DIO19
#define GPIO_EVFLAGS_DIO19                                      0x00080000
#define GPIO_EVFLAGS_DIO19_BITN                                         19
#define GPIO_EVFLAGS_DIO19_M                                    0x00080000
#define GPIO_EVFLAGS_DIO19_S                                            19

// Field:    [18] DIO18
#define GPIO_EVFLAGS_DIO18                                      0x00040000
#define GPIO_EVFLAGS_DIO18_BITN                                         18
#define GPIO_EVFLAGS_DIO18_M                                    0x00040000
#define GPIO_EVFLAGS_DIO18_S                                            18

// Field:    [17] DIO17
#define GPIO_EVFLAGS_DIO17                                      0x00020000
#define GPIO_EVFLAGS_DIO17_BITN                                         17
#define GPIO_EVFLAGS_DIO17_M                                    0x00020000
#define GPIO_EVFLAGS_DIO17_S                                            17

// Field:    [16] DIO16
#define GPIO_EVFLAGS_DIO16                                      0x00010000
#define GPIO_EVFLAGS_DIO16_BITN                                         16
#define GPIO_EVFLAGS_DIO16_M                                    0x00010000
#define GPIO_EVFLAGS_DIO16_S                                            16

// Field:    [15] DIO15
#define GPIO_EVFLAGS_DIO15                                      0x00008000
#define GPIO_EVFLAGS_DIO15_BITN                                         15
#define GPIO_EVFLAGS_DIO15_M                                    0x00008000
#define GPIO_EVFLAGS_DIO15_S                                            15

// Field:    [14] DIO14
#define GPIO_EVFLAGS_DIO14                                      0x00004000
#define GPIO_EVFLAGS_DIO14_BITN                                         14
#define GPIO_EVFLAGS_DIO14_M                                    0x00004000
#define GPIO_EVFLAGS_DIO14_S                                            14

// Field:    [13] DIO13
#define GPIO_EVFLAGS_DIO13                                      0x00002000
#define GPIO_EVFLAGS_DIO13_BITN                                         13
#define GPIO_EVFLAGS_DIO13_M                                    0x00002000
#define GPIO_EVFLAGS_DIO13_S                                            13

// Field:    [12] DIO12
#define GPIO_EVFLAGS_DIO12                                      0x00001000
#define GPIO_EVFLAGS_DIO12_BITN                                         12
#define GPIO_EVFLAGS_DIO12_M                                    0x00001000
#define GPIO_EVFLAGS_DIO12_S                                            12

// Field:    [11] DIO11
#define GPIO_EVFLAGS_DIO11                                      0x00000800
#define GPIO_EVFLAGS_DIO11_BITN                                         11
#define GPIO_EVFLAGS_DIO11_M                                    0x00000800
#define GPIO_EVFLAGS_DIO11_S                                            11

// Field:    [10] DIO10
#define GPIO_EVFLAGS_DIO10                                      0x00000400
#define GPIO_EVFLAGS_DIO10_BITN                                         10
#define GPIO_EVFLAGS_DIO10_M                                    0x00000400
#define GPIO_EVFLAGS_DIO10_S                                            10

// Field:     [9] DIO9
#define GPIO_EVFLAGS_DIO9                                       0x00000200
#define GPIO_EVFLAGS_DIO9_BITN                                           9
#define GPIO_EVFLAGS_DIO9_M                                     0x00000200
#define GPIO_EVFLAGS_DIO9_S                                              9

// Field:     [8] DIO8
#define GPIO_EVFLAGS_DIO8                                       0x00000100
#define GPIO_EVFLAGS_DIO8_BITN                                           8
#define GPIO_EVFLAGS_DIO8_M                                     0x00000100
#define GPIO_EVFLAGS_DIO8_S                                              8

// Field:     [7] DIO7
#define GPIO_EVFLAGS_DIO7                                       0x00000080
#define GPIO_EVFLAGS_DIO7_BITN                                           7
#define GPIO_EVFLAGS_DIO7_M                                     0x00000080
#define GPIO_EVFLAGS_DIO7_S                                              7

// Field:     [6] DIO6
#define GPIO_EVFLAGS_DIO6                                       0x00000040
#define GPIO_EVFLAGS_DIO6_BITN                                           6
#define GPIO_EVFLAGS_DIO6_M                                     0x00000040
#define GPIO_EVFLAGS_DIO6_S                                              6

// Field:     [5] DIO5
#define GPIO_EVFLAGS_DIO5                                       0x00000020
#define GPIO_EVFLAGS_DIO5_BITN                                           5
#define GPIO_EVFLAGS_DIO5_M                                     0x00000020
#define GPIO_EVFLAGS_DIO5_S                                              5

// Field:     [4] DIO4
#define GPIO_EVFLAGS_DIO4                                       0x00000010
#define GPIO_EVFLAGS_DIO4_BITN                                           4
#define GPIO_EVFLAGS_DIO4_M                                     0x00000010
#define GPIO_EVFLAGS_DIO4_S                                              4

// Field:     [3] DIO3
#define GPIO_EVFLAGS_DIO3                                       0x00000008
#define GPIO_EVFLAGS_DIO3_BITN                                           3
#define GPIO_EVFLAGS_DIO3_M                                     0x00000008
#define GPIO_EVFLAGS_DIO3_S                                              3

// Field:     [2] DIO2
#define GPIO_EVFLAGS_DIO2                                       0x00000004
#define GPIO_EVFLAGS_DIO2_BITN                                           2
#define GPIO_EVFLAGS_DIO2_M                                     0x00000004
#define GPIO_EVFLAGS_DIO2_S                                              2

// Field:     [1] DIO1
#define GPIO_EVFLAGS_DIO1                                       0x00000002
#define GPIO_EVFLAGS_DIO1_BITN                                           1
#define GPIO_EVFLAGS_DIO1_M                                     0x00000002
#define GPIO_EVFLAGS_DIO1_S                                              1

// Field:     [0] DIO0
#define GPIO_EVFLAGS_DIO0                                       0x00000001
#define GPIO_EVFLAGS_DIO0_BITN                                           0
#define GPIO_EVFLAGS_DIO0_M                                     0x00000001
#define GPIO_EVFLAGS_DIO0_S                                              0



// Register: IOC_O_IOCFG0
// Field:    [30] HYST_EN
#define IOC_IOCFG_HYST_EN                                          0x40000000
#define IOC_IOCFG_HYST_EN_BITN                                             30
#define IOC_IOCFG_HYST_EN_M                                        0x40000000
#define IOC_IOCFG_HYST_EN_S                                                30

// Field:    [29] IE
#define IOC_IOCFG_IE                                               0x20000000
#define IOC_IOCFG_IE_BITN                                                  29
#define IOC_IOCFG_IE_M                                             0x20000000
#define IOC_IOCFG_IE_S                                                     29

// Field: [28:27] WU_CFG
#define IOC_IOCFG_WU_CFG_W                                                  2
#define IOC_IOCFG_WU_CFG_M                                         0x18000000
#define IOC_IOCFG_WU_CFG_S                                                 27

// Field: [26:24] IOMODE
#define IOC_IOCFG_IOMODE_W                                                  3
#define IOC_IOCFG_IOMODE_M                                         0x07000000
#define IOC_IOCFG_IOMODE_S                                                 24
#define IOC_IOCFG_IOMODE_OPENSRC_INV                               0x07000000
#define IOC_IOCFG_IOMODE_OPENSRC                                   0x06000000
#define IOC_IOCFG_IOMODE_OPENDR_INV                                0x05000000
#define IOC_IOCFG_IOMODE_OPENDR                                    0x04000000
#define IOC_IOCFG_IOMODE_INV                                       0x01000000
#define IOC_IOCFG_IOMODE_NORMAL                                    0x00000000

// Field:    [23] IOEV_AON_PROG2_EN
#define IOC_IOCFG_IOEV_AON_PROG2_EN                                0x00800000
#define IOC_IOCFG_IOEV_AON_PROG2_EN_BITN                                   23
#define IOC_IOCFG_IOEV_AON_PROG2_EN_M                              0x00800000
#define IOC_IOCFG_IOEV_AON_PROG2_EN_S                                      23

// Field:    [22] IOEV_AON_PROG1_EN
#define IOC_IOCFG_IOEV_AON_PROG1_EN                                0x00400000
#define IOC_IOCFG_IOEV_AON_PROG1_EN_BITN                                   22
#define IOC_IOCFG_IOEV_AON_PROG1_EN_M                              0x00400000
#define IOC_IOCFG_IOEV_AON_PROG1_EN_S                                      22

// Field:    [21] IOEV_AON_PROG0_EN
#define IOC_IOCFG_IOEV_AON_PROG0_EN                                0x00200000
#define IOC_IOCFG_IOEV_AON_PROG0_EN_BITN                                   21
#define IOC_IOCFG_IOEV_AON_PROG0_EN_M                              0x00200000
#define IOC_IOCFG_IOEV_AON_PROG0_EN_S                                      21

// Field:    [18] EDGE_IRQ_EN
#define IOC_IOCFG_EDGE_IRQ_EN                                      0x00040000
#define IOC_IOCFG_EDGE_IRQ_EN_BITN                                         18
#define IOC_IOCFG_EDGE_IRQ_EN_M                                    0x00040000
#define IOC_IOCFG_EDGE_IRQ_EN_S                                            18

// Field: [17:16] EDGE_DET
#define IOC_IOCFG_EDGE_DET_W                                                2
#define IOC_IOCFG_EDGE_DET_M                                       0x00030000
#define IOC_IOCFG_EDGE_DET_S                                               16
#define IOC_IOCFG_EDGE_DET_BOTH                                    0x00030000
#define IOC_IOCFG_EDGE_DET_POS                                     0x00020000
#define IOC_IOCFG_EDGE_DET_NEG                                     0x00010000
#define IOC_IOCFG_EDGE_DET_NONE                                    0x00000000

// Field: [14:13] PULL_CTL
#define IOC_IOCFG_PULL_CTL_W                                                2
#define IOC_IOCFG_PULL_CTL_M                                       0x00006000
#define IOC_IOCFG_PULL_CTL_S                                               13
#define IOC_IOCFG_PULL_CTL_DIS                                     0x00006000
#define IOC_IOCFG_PULL_CTL_UP                                      0x00004000
#define IOC_IOCFG_PULL_CTL_DWN                                     0x00002000

// Field:    [12] SLEW_RED
#define IOC_IOCFG_SLEW_RED                                         0x00001000
#define IOC_IOCFG_SLEW_RED_BITN                                            12
#define IOC_IOCFG_SLEW_RED_M                                       0x00001000
#define IOC_IOCFG_SLEW_RED_S                                               12

// Field: [11:10] IOCURR
#define IOC_IOCFG_IOCURR_W                                                  2
#define IOC_IOCFG_IOCURR_M                                         0x00000C00
#define IOC_IOCFG_IOCURR_S                                                 10
#define IOC_IOCFG_IOCURR_4_8MA                                     0x00000800
#define IOC_IOCFG_IOCURR_4MA                                       0x00000400
#define IOC_IOCFG_IOCURR_2MA                                       0x00000000

// Field:   [9:8] IOSTR
#define IOC_IOCFG_IOSTR_W                                                   2
#define IOC_IOCFG_IOSTR_M                                          0x00000300
#define IOC_IOCFG_IOSTR_S                                                   8
#define IOC_IOCFG_IOSTR_MAX                                        0x00000300
#define IOC_IOCFG_IOSTR_MED                                        0x00000200
#define IOC_IOCFG_IOSTR_MIN                                        0x00000100
#define IOC_IOCFG_IOSTR_AUTO                                       0x00000000

// Field:     [7] IOEV_RTC_EN
#define IOC_IOCFG_IOEV_RTC_EN                                      0x00000080
#define IOC_IOCFG_IOEV_RTC_EN_BITN                                          7
#define IOC_IOCFG_IOEV_RTC_EN_M                                    0x00000080
#define IOC_IOCFG_IOEV_RTC_EN_S                                             7

// Field:     [6] IOEV_MCU_WU_EN
#define IOC_IOCFG_IOEV_MCU_WU_EN                                   0x00000040
#define IOC_IOCFG_IOEV_MCU_WU_EN_BITN                                       6
#define IOC_IOCFG_IOEV_MCU_WU_EN_M                                 0x00000040
#define IOC_IOCFG_IOEV_MCU_WU_EN_S                                          6

// Field:   [5:0] PORT_ID
#define IOC_IOCFG_PORT_ID_W                                                 6
#define IOC_IOCFG_PORT_ID_M                                        0x0000003F
#define IOC_IOCFG_PORT_ID_S                                                 0





namespace mpp::gpio
{
  inline namespace cc26x2
  {
    enum class PortId
    {
      DIO          = 0u,        //!< Default GPIO usage
		
      // 1-6 Reserved
      AON_CLK32K    = 7u,        //!< AON 32-kHz clock pin
      AUX_IO        = 8u,        //!< AUX Domain I/O pin
      SSI0_RX       = 9u,        //!< SSI 0 RX pin
      SSI0_TX       = 10u,       //!< SSI 0 TX pin
      SSI0_FSS      = 11u,       //!< SSI 0 FSS pin
      SSI0_CLK      = 12u,       //!< SSI 0 CLK pin
      I2C_MSSDA     = 13u,       //!< I2C data
      I2C_MSSCL     = 14u,       //!< I2C clock
      UART0_RX      = 15u,       //!< UART 0 RX pin
      UART0_TX      = 16u,       //!< UART 0 TX pin
      UART0_CTS     = 17u,       //!< UART 0 CTS pin
      UART0_RTS     = 18u,       //!< UART 0 RTS pin
      UART1_RX      = 19u,       //!< UART 1 RX pin
      UART1_TX      = 20u,       //!< UART 1 TX pin
      UART1_CTS     = 21u,       //!< UART 1 CTS pin
      UART1_RTS     = 22u,       //!< UART 1 RTS pin
      EVENT0        = 23u,       //!< General-purpose I/O event 0
      EVENT1        = 24u,       //!< General-purpose I/O event 1
      EVENT2        = 25u,       //!< General-purpose I/O event 2
      EVENT3        = 26u,       //!< General-purpose I/O event 3
      EVENT4        = 27u,       //!< General-purpose I/O event 4
      EVENT5        = 28u,       //!< General-purpose I/O event 5
      EVENT6        = 29u,       //!< General-purpose I/O event 6
      EVENT7        = 30u,       //!< General-purpose I/O event 7
      // 31 Reserved
      CPU_SWV       = 32u,       //!< CPU SWV
      SSI1_RX       = 33u,       //!< SSI 1 RX pin
      SSI1_TX       = 34u,       //!< SSI 1 TX pin
      SSI1_FSS      = 35u,       //!< SSI 1 FSS pin
      SSI1_CLK      = 36u,       //!< SSI 1 CLK pin
      I2S_AD0       = 37u,       //!< I2S data 0 pin
      I2S_AD1       = 38u,       //!< I2S data 1 pin
      I2S_WCLK      = 39u,       //!< I2S WCLK pin
      I2S_BCLK      = 40u,       //!< I2S BCLK pin
      I2S_MCLK      = 41u,       //!< I2S MCLK pin
      // 42-45 Reserved
      RFC_TRACE     = 46u,       //!< RF Core Trace
      RFC_GPO0      = 47u,       //!< RF Core general-purpose output 0 (LNA Enable)
      RFC_GPO1      = 48u,       //!< RF Core general-purpose output 1 (PA Enable)
      RFC_GPO2      = 49u,       //!< RF Core general-purpose output 2 (Synthesizer calibration enable)
      RFC_GPO3      = 50u,       //!< RF Core general-purpose output 3 (TX Start)
      RFC_GPI0      = 51u,       //!< RF Core Data In 0
      RFC_GPI1      = 52u,       //!< RF Core Data In 1
      RFC_SMI_DLO   = 53u,       //!< RF Core SMI Data Link Out
      RFC_SMI_DLI   = 54u,       //!< RF Core SMI Data Link In
      RFC_SMI_CLO   = 55u,       //!< RF Core SMI Command Link Out
      RFC_SMI_CLI   = 56u,       //!< RF Core SMI Command Link In
    };

      
    template< class IO > constexpr bool IsValidIo() noexcept(true)
    {
      static_assert(::std::is_same_v< IO, ::std::decay_t< decltype(IO()) > >);

      #if defined (CC1352R)
        return (IO::kPin > 2)&&(IO::kPin < 31);
      #elif  defined (CC1352P)
        return (IO::kPin > 4)&&(IO::kPin < 31);
      #else
        return IO::kPin < 31;
      #endif
    }
    
    
    struct DIO30 final
    {
      constexpr static std::uint32_t kPin     = 30u;
      constexpr static std::uint32_t kAuxPin  = 19u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;    
    };
    
    
    struct DIO29 final
    {
      constexpr static std::uint32_t kPin     = 29u;
      constexpr static std::uint32_t kAuxPin  = 20u; 
      constexpr static bool kAnalogCapable    = true;   
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    
    struct DIO28 final
    {
      constexpr static std::uint32_t kPin     = 28u;
      constexpr static std::uint32_t kAuxPin  = 21u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO27 final
    {
      constexpr static std::uint32_t kPin     = 27u;
      constexpr static std::uint32_t kAuxPin  = 22u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO26 final
    {
      constexpr static std::uint32_t kPin     = 26u;
      constexpr static std::uint32_t kAuxPin  = 23u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO25 final
    {
      constexpr static std::uint32_t kPin     = 25u;
      constexpr static std::uint32_t kAuxPin  = 24u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO24 final
    {
      constexpr static std::uint32_t kPin     = 24u;
      constexpr static std::uint32_t kAuxPin  = 25u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO23 final
    {
      constexpr static std::uint32_t kPin     = 23u;
      constexpr static std::uint32_t kAuxPin  = 26u;
      constexpr static bool kAnalogCapable    = true;  
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO22 final
    {
      constexpr static std::uint32_t kPin     = 22u; 
      constexpr static std::uint32_t kAuxPin  = 27u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO21 final
    {
      constexpr static std::uint32_t kPin     = 21u;
      constexpr static std::uint32_t kAuxPin  = 28u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO20 final
    {
      constexpr static std::uint32_t kPin     = 20u;
      constexpr static std::uint32_t kAuxPin  = 29u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO19 final
    {
      constexpr static std::uint32_t kPin     = 19u;
      constexpr static std::uint32_t kAuxPin  = 30u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO18 final
    {
      constexpr static std::uint32_t kPin     = 18u;
      constexpr static std::uint32_t kAuxPin  = 31u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO17 final
    {
      constexpr static std::uint32_t kPin     = 17u;
      constexpr static std::uint32_t kAuxPin  = 1u;
      constexpr static bool kAnalogCapable    = false;  
      constexpr static bool kHighDriveCapable = true;     
    };
    
    
    struct DIO16 final
    {
      constexpr static std::uint32_t kPin     = 16u;
      constexpr static std::uint32_t kAuxPin  = 2u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = true;    
    };
    
    
    struct DIO15 final
    {
      constexpr static std::uint32_t kPin     = 15u;
      constexpr static std::uint32_t kAuxPin  = 3u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO14 final
    {
      constexpr static std::uint32_t kPin     = 14u;
      constexpr static std::uint32_t kAuxPin  = 4u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO13 final
    {
      constexpr static std::uint32_t kPin     = 13u;
      constexpr static std::uint32_t kAuxPin  = 5u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO12 final
    {
      constexpr static std::uint32_t kPin     = 12u;
      constexpr static std::uint32_t kAuxPin  = 6u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO11 final
    {
      constexpr static std::uint32_t kPin     = 11u;
      constexpr static std::uint32_t kAuxPin  = 7u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO10 final
    {
      constexpr static std::uint32_t kPin     = 10u;
      constexpr static std::uint32_t kAuxPin  = 8u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO9 final
    {
      constexpr static std::uint32_t kPin     = 9u;
      constexpr static std::uint32_t kAuxPin  = 9u; 
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO8 final
    {
      constexpr static std::uint32_t kPin     = 8u;
      constexpr static std::uint32_t kAuxPin  = 10u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO7 final
    {
      constexpr static std::uint32_t kPin     = 7u;
      constexpr static std::uint32_t kAuxPin  = 11u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = true;    
    };
    
    
    struct DIO6 final
    {
      constexpr static std::uint32_t kPin     = 6u;
      constexpr static std::uint32_t kAuxPin  = 12u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = true;    
    };
    
    
    struct DIO5 final
    {
      constexpr static std::uint32_t kPin     = 5u;
      constexpr static std::uint32_t kAuxPin  = 13u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = true;    
    };
    
    
    struct DIO4 final
    {
      constexpr static std::uint32_t kPin     = 4u;
      constexpr static std::uint32_t kAuxPin  = 14u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO3 final
    {
      constexpr static std::uint32_t kPin     = 3u;
      constexpr static std::uint32_t kAuxPin  = 15u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO2 final
    {
      constexpr static std::uint32_t kPin     = 2u;
      constexpr static std::uint32_t kAuxPin  = 16u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO1 final
    {
      constexpr static std::uint32_t kPin     = 1u;
      constexpr static std::uint32_t kAuxPin  = 17u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
    
    
    struct DIO0 final
    {
      constexpr static std::uint32_t kPin     = 0u;
      constexpr static std::uint32_t kAuxPin  = 18u;
      constexpr static bool kAnalogCapable    = false; 
      constexpr static bool kHighDriveCapable = false;   
    };
  } // inline namespace 
} // namespace mpp::gpio
