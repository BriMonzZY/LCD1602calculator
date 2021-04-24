#ifndef _CONFIG_H
#define _CONFIG_H


/****************************************************************
ͨ��ͷ�ļ�
****************************************************************/
#include <reg52.h>
#include <intrins.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
//#include <assert.h>

/*�û��ļ�*/
//#include "main.h"
//#include "app.h"
//#include "key.h"
//#include "lcd1602.h"

#define MAIN_Fosc		11059200UL	//�궨����ʱ��HZ  11.0592MHz

/****************************************************************
���������������¶���
****************************************************************/

typedef signed char int8;  //8λ�з�����
typedef signed int  int16; //16λ�з�����
typedef unsigned char uint8;  //8λ�޷�����
typedef unsigned char uchar;  //8λ�޷�����
typedef unsigned int  uint16; //16λ�޷�����
typedef unsigned int  uint; //16λ�޷�����
typedef unsigned long uint32; //32λ�޷�����

/****************************************************************
Ӳ���ӿڶ���
****************************************************************/

/*4λ������������*/
sbit KEY_S2 = P3^0;	//S2��������
sbit KEY_S3 = P3^1;	//S3��������
sbit KEY_S4 = P3^2;	//S4��������
sbit KEY_S5 = P3^3;	//S5��������

/*�����������*/
sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;

/*���������*/
sbit DU = P2^6;
sbit WE = P2^7;


/*IIC����*/
sbit sda = P2^0;
sbit scl = P2^1;

/*LED����*/
sbit L1 = P1^0;
sbit L7 = P1^6;
sbit L8 = P1^7;

/*DS1302IO�ӿ� ����3P�Ű������Ӧ��P1������*/
sbit TSCLK = P1^0;   //DS1302ʱ������
sbit TIO   = P1^1;   //DS1302��������
sbit TRST  = P1^2;   //DS1302ʹ������

/*LCD1602Һ������*/
#define LCD1602_DB  P0      //data bus ��������
sbit LCD1602_RS = P3^5;		//LCD1602Һ������/����ѡ������
sbit LCD1602_RW = P3^6;		//LCD1602Һ����/дѡ������
sbit LCD1602_EN = P3^4;	 	//LCD1602Һ��ʹ������

/*DS18B20�¶ȴ���������*/
sbit DS18B20_IO = P2^2;   //DS18B20ͨ������

/*5V��Դ����������*/
sbit BUZZER = P2^3;	//����������


#endif