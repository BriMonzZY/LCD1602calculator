#ifndef _CONFIG_H
#define _CONFIG_H


/****************************************************************
通用头文件
****************************************************************/
#include <reg52.h>
#include <intrins.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#include <assert.h>

/*用户文件*/
//#include "main.h"
//#include "app.h"
//#include "key.h"
//#include "lcd1602.h"

#define MAIN_Fosc		11059200UL	//宏定义主时钟HZ  11.0592MHz

/****************************************************************
已有数据类型重新定义
****************************************************************/

typedef signed char int8;  //8位有符号型
typedef signed int  int16; //16位有符号型
typedef unsigned char uint8;  //8位无符号型
typedef unsigned char uchar;  //8位无符号型
typedef unsigned int  uint16; //16位无符号型
typedef unsigned int  uint; //16位无符号型
typedef unsigned long uint32; //32位无符号型

/****************************************************************
硬件接口定义
****************************************************************/

/*4位独立按键引脚*/
sbit KEY_S2 = P3^0;	//S2独立按键
sbit KEY_S3 = P3^1;	//S3独立按键
sbit KEY_S4 = P3^2;	//S4独立按键
sbit KEY_S5 = P3^3;	//S5独立按键

/*矩阵键盘引脚*/
sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;

/*数码管引脚*/
sbit DU = P2^6;
sbit WE = P2^7;


/*IIC引脚*/
sbit sda = P2^0;
sbit scl = P2^1;

/*LED引脚*/
sbit L1 = P1^0;
sbit L7 = P1^6;
sbit L8 = P1^7;

/*DS1302IO接口 请用3P杜邦线与对应的P1口链接*/
sbit TSCLK = P1^0;   //DS1302时钟引脚
sbit TIO   = P1^1;   //DS1302数据引脚
sbit TRST  = P1^2;   //DS1302使能引脚

/*LCD1602液晶引脚*/
#define LCD1602_DB  P0      //data bus 数据总线
sbit LCD1602_RS = P3^5;		//LCD1602液晶命令/数据选择引脚
sbit LCD1602_RW = P3^6;		//LCD1602液晶读/写选择引脚
sbit LCD1602_EN = P3^4;	 	//LCD1602液晶使能引脚

/*DS18B20温度传感器引脚*/
sbit DS18B20_IO = P2^2;   //DS18B20通信引脚

/*5V有源蜂鸣器引脚*/
sbit BUZZER = P2^3;	//蜂鸣器引脚


#endif