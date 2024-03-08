/*!
 * @file  play.ino
 * @brief This is a demo for dot matrix display, demonstrating its usage methods
 * @copyright   Copyright (c) 2021 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author      [TangJie](jie.tang@dfrobot.com)
 * @version     V1.0
 * @date        2023-12-11
 * @url         https://github.com/DFRobot/DFRobot_LEDMatrix
 */

#include "DFRobot_LEDMatrix.h"

DFRobot_LEDMatrix dp;
byte character_A[8]={
    0b00111100,
    0b01000010,
    0b01000010,
    0b01111110,
    0b01000010,
    0b01000010,
    0b01000010,
    0b00000000
  };


void setup() {
  Serial.begin(115200);
  dp.begin(5);
  dp.disPlay(1,0x00);
  dp.disPlay(2,0x00);
  dp.disPlay(3,0x3C);
  dp.disPlay(4,0x42);
  dp.disPlay(5,0x7E);
  dp.disPlay(6,0x42);
  dp.disPlay(7,0x42);
  dp.disPlay(8,0x00);
  delay(1000);
  dp.cleanDisPlay();
  delay(500);
  dp.disPlay(character_A);
  delay(1000);
  dp.cleanDisPlay();
  delay(500);
}

void loop() {
    dp.disPlay("1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz",50);
    delay(1000);
    dp.disPlay(dp.eYes);
    delay(1000);
    dp.disPlay(dp.eNo);
    delay(1000);
}
