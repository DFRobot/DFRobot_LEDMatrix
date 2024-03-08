DFRobot_LEDMatrix
===========================

* [English Version](./README.md)

DFR1135是一个8*8的点阵屏，能够显示自定义字符、内置字符和表情。

![产品效果图片](../../resources/images/DFR1135.png)

## 产品链接（https://www.dfrobot.com）

    SKU：SEN0540
  
## 目录

  * [概述](#概述)
  * [库安装](#库安装)
  * [方法](#方法)
  * [兼容性](#兼容性)
  * [历史](#历史)
  * [创作者](#创作者)

## 概述

DFR1135是一个8*8的点阵屏，能够显示自定义字符、内置字符和表情。

## 库安装

使用此库前，请首先下载库文件，将其粘贴到\Arduino\libraries目录中，然后打开examples文件夹并在该文件夹中运行演示。

## 方法

```C++
  /**
     * @fn begin
     * @brief 初始化模块
     * @param lum LED灯亮度,0~16
    */
    void begin(uint8_t lum);
    /**
     * @fn disPlay 
     * @brief 指定某一行那个灯点亮
     * @param line 行号 1~8
     * @param number 那个灯1~8
    */
    void disPlay(uint8_t line,uint8_t number);
    /**
     * @fn disPlay 
     * @brief 按矩阵中数据显示
     * @param numBuf 矩阵数据
    */
    void disPlay(byte *numBuf);
    /**
     * @fn disPlay 
     * @brief 用于滚动显示字符串
     * @param ch 需要显示的字符串
     * @param time 滚动速度 
    */
    void disPlay(const char* ch,uint8_t time);
    /**
     * @fn disPlay 
     * @brief 显示图标
     * @param image 图标
    */
    void disPlay(eImage_t image);
    /**
     * @fn cleanDisPlay 
     * @brief 清楚屏幕显示
    */
    void cleanDisPlay(void);

```


## 兼容性

MCU                |      SPI     | 
------------------ | :----------: | 
Arduino Uno        |      √       |
Mega2560           |      √       |
Leonardo           |      √       |
ESP32              |      √       |
ESP8266            |      √       | 
FireBeetle M0      |      √       |  

## 历史
- 2023-12-11 - 1.0.0 版本

## 创作者

Written by TangJie(jie.tang@dfrobot.com), 2021. (Welcome to our [website](https://www.dfrobot.com/))