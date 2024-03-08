/*!
 * @file DFRobot_LEDMatrix.h
 * @brief This is the method implementation file for DFRobot_LEDMatrix
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version  V1.0
 * @date  2023-12-11
 * @url https://github.com/DFRobot/DFRobot_LEDMatrix
 */

#ifndef DFROBOT_LEDMATRIX_H
#define DFROBOT_LEDMATRIX_H
#include "Arduino.h"
#include "SPI.h"
#include "DFRobot_LEDMatrix_Font.h"


class DFRobot_LEDMatrix{
public:
    #define DECODE_MODE 0x09   ///< BCD encoding configuration
    #define INTENSITY 0x0A     ///< Brightness register
    #define SCAN_LIMIT 0x0B    ///< Scan limit register
    #define SHUTDOWN 0x0C      ///< Shutdown mode register
    #define DISPLAY_TEST 0x0F  ///< Test register

    /**
     * @enum eImage_t
     * @brief Icons
     */
    typedef enum{
        eHeart,
        eSmallHeart,
        eYes,
        eNo,
        eHappy,
        eSad,
        eConfused,
        eAngry,
        eAsleep,
        eSurprised,
        eSilly,
        eFabulous,
        eMeh,
        eTShirt,
        eRollerskate,
        eDuck,
        eHouse,
        eTortoise,
        eButterfly,
        eStickFigure,
        eGhost,
        eSword,
        eGiraffe,
        eSkull,
        eUmbrella,
        eSnake,
        eRabbit,
        eCow,
        eQuarterNote,
        eEigthNote,
        ePitchfork,
        eTarget,
        eTriangle,
        eLeftTriangle,
        eChessboard,
        eDiamond,
        eSmallDiamond,
        eSquare,
        eSmallSquare,
        eScissors
    }eImage_t;
/**
 * @fn DFRobot_LEDMatrix
 * @brief Constructor
 * @param pspi SPI object
 * @param cs CS pin
 * @return None 
 */
DFRobot_LEDMatrix(SPIClass *pspi = &SPI, uint8_t cs = 4);

/**
 * @fn begin
 * @brief Initialize the module
 * @param lum LED brightness, 0~16
 */
void begin(uint8_t lum);

/**
 * @fn disPlay 
 * @brief Light up a specific LED in a certain row
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
 * @param ch String to be displayed
 * @param time Scroll speed 
 */
void disPlay(const char* ch, uint16_t time);

/**
 * @fn disPlay 
 * @brief Display an icon
 * @param image Icon
 */
void disPlay(eImage_t image);

/**
 * @fn cleanDisPlay 
 * @brief Clear the screen display
 */
void cleanDisPlay(void);

private:
void sendData(uint8_t address, uint8_t value);
void getBuf(uint8_t ascillValue,uint8_t* buf);
SPIClass *_pspi;
uint8_t _csPin;
};
#endif 
