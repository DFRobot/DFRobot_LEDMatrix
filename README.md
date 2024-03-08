DFRobot_LEDMatrix
===========================

* [English Version](./README.md)

DFR1135 is an 8x8 dot matrix screen that can display custom characters, built-in characters, and expressions.

![Product Effect Image](../../resources/images/DFR1135.png)

## Product Link (https://www.dfrobot.com)

    SKU：SEN0540
  
## Table of Contents

  * [Overview](#Overview)
  * [LibraryInstallation](#LibraryInstallation)
  * [Methods](#Methods)
  * [Compatibility](#Compatibility)
  * [History](#History)
  * [Creator](#Creator)

## Overview

DFR1135 is an 8x8 dot matrix screen that can display custom characters, built-in characters, and expressions.

## Library Installation

Before using this library, please download the library files, paste them into the \Arduino\libraries directory, and then open the examples folder to run the demo.

## Methods

```C++
    /**
     * @fn begin
     * @brief Initialize the module
     * @param lum LED brightness, 0~16
    */
    void begin(uint8_t lum);
    /**
     * @fn disPlay 
     * @brief Specify which LED to light up in a row
     * @param line Row number, 1~8
     * @param number LED number, 1~8
    */
    void disPlay(uint8_t line, uint8_t number);
    /**
     * @fn disPlay 
     * @brief Display according to the data in the matrix
     * @param numBuf Matrix data
    */
    void disPlay(byte *numBuf);
    /**
     * @fn disPlay 
     * @brief Used to scroll and display strings
     * @param ch The string to be displayed
     * @param time Scroll speed 
    */
    void disPlay(const char* ch, uint8_t time);
    /**
     * @fn disPlay 
     * @brief Display icon
     * @param image Icon
    */
    void disPlay(eImage_t image);
    /**
     * @fn cleanDisPlay 
     * @brief Clear the screen display
    */
    void cleanDisPlay(void);



```


## Compatibility

MCU                |      SPI     | 
------------------ | :----------: | 
Arduino Uno        |      √       |
Mega2560           |      √       |
Leonardo           |      √       |
ESP32              |      √       |
ESP8266            |      √       | 
FireBeetle M0      |      √       |  

## History
- 2023-12-11 - Version 1.0.0

## Creator

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))