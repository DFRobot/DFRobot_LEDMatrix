/*!
 * @file DFRobot_LEDMatrix.cpp
 * @brief This is the method documentation file for DFRobot_LEDMatrix
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie](jie.tang@dfrobot.com)
 * @version  V1.0
 * @date  2023-12-7
 * @url https://github.com/DFRobot/DFRobot_LEDMatrix
 */

#include "DFRobot_LEDMatrix.h"


DFRobot_LEDMatrix::DFRobot_LEDMatrix(SPIClass *pspi,uint8_t cs):_pspi(pspi),_csPin(cs){}

void DFRobot_LEDMatrix::begin(uint8_t lum){
  pinMode(_csPin, OUTPUT);  
  _pspi->beginTransaction(SPISettings(10000000, MSBFIRST, SPI_MODE0));
  _pspi->begin();
  sendData(DISPLAY_TEST,   0x01);       // Run test - All LED segments lit.
  delay(500);
  sendData(DISPLAY_TEST,   0x00);           // Finish test mode.
  sendData(DECODE_MODE, 0x00);            //   Disable BCD mode. 
  sendData(INTENSITY, lum);              // Use lowest intensity.   
  sendData(SCAN_LIMIT, 0x0f);             // Scan all digits.
  sendData(SHUTDOWN,   0x01);               // Turn on chip.
  cleanDisPlay();
}

void DFRobot_LEDMatrix::sendData(uint8_t address, uint8_t value) {  
  digitalWrite(_csPin, LOW);   
  _pspi->transfer(address);      // Send address.
  _pspi->transfer(value);        //   Send the value.
  digitalWrite(_csPin, HIGH); // Finish transfer.
}

void DFRobot_LEDMatrix::disPlay(uint8_t line,uint8_t number){
  sendData(line,number);
}

void DFRobot_LEDMatrix::disPlay(byte *numBuf){
  for (int i=1;i<9;i++){
  sendData(i,numBuf[i-1]);
  } 
}

void DFRobot_LEDMatrix::cleanDisPlay(void){
  for(uint8_t i = 1; i < 9;i++){
    sendData(i,0);
  }
}

void DFRobot_LEDMatrix::disPlay(const char* ch,uint16_t time){
  uint8_t len = strlen(ch);
  uint8_t i,j,k,f;
  uint8_t ascill = ch[0];
  uint8_t charBufA[8];
  uint8_t charBufB[8];
  getBuf(ascill,charBufA);//Gets the first character data
  for(i = 1;i < len;i++){
    ascill = ch[i];
    getBuf(ascill,charBufB);//Get the second and second data
    for(j = 0;j< 10;j++){//Data displacement quantity
      for(k = 1;k < 9;k++){//data display
        sendData(k,charBufA[k-1]);//send data
        charBufA[k-1] <<=1;
      }
      if(j > 2){
        for(f = 0; f < 8; f++){//Append the next data to the tail
          charBufA[f] |= charBufB[f]>>(9-j);
        }
      }
      delay(time);
      }
  }
}

void DFRobot_LEDMatrix::getBuf(uint8_t ascillValue,uint8_t* buf){
  for(uint8_t i = 0;i < sizeof(mapTableFont);i++){
      if(ascillValue== mapTableFont[i]){
        for(uint8_t j = 0;j< 8;j++){
          buf[j] = pgm_read_byte (&MAX7219_Dot_Matrix_font[i][j]);
        }
        break;
      }
    }
}

void DFRobot_LEDMatrix::disPlay(eImage_t image){
  uint8_t charBufA[8];
  for(uint8_t i = 0;i< 8;i++){
          charBufA[i] = pgm_read_byte (&MAX7219_Dot_Matrix_iamge[image][i]);
  }
  for (int i=1;i<9;i++){
    sendData(i,charBufA[i-1]);
  } 
}