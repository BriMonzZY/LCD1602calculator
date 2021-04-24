/**
 * @project					LCD1602 caculator
 * @author					BriMonzZY (1610937885@qq.com)
 * @brief						caculator based on 51
 * @version					0.1
 * @date						2021-03-22
 * @paltform				STC89C52 & STC89C52RC
 * @copyright				Copyright (c) 2021
 * 
 *
 *
 * ���󰴼����ܣ�
 *
 * 7			8			9			��
 * 4			5			6			x
 * 1			2			3			-
 * �˸�	  0			=			+
 *
 *
 *
 *
 *
 * ��ֵ��Ӧ��
 * 
 * 0	1		2		3 
 * 4 	5	 	6		7
 * 8 	9 	10	11
 * 12	13	14	15
 *
 */
#define __MAIN_C
#include "config.h"
#include "main.h"
#include "lcd1602.h"
#include "app.h"
#include "key.h"




void timer0Init();
bit keyjudge = 0;
uint8 cursor1;
uint8 cursor2; // LCD ��һ��λ��ָ�룬 �ڶ���λ��ָ��
float num_in_buff = 0.1;
char str[40];  //�洢�������׺���ʽ


uchar backup[4][4] = { //��ʼ������ֵ����
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
};


//#define INITSIZE  20
//#define INCREMENT 10
//#define MAXBUFFER 20
//#define LEN  sizeof(Elemtype)
/*ջ�Ķ�̬����洢�ṹ*/ 
//typedef char Elemtype;
//struct SqStack{
//	Elemtype *base;
//	Elemtype *top;
//	int StackSize;
//};




/**
 * @brief   ������
 * @param   ��
 * @return  ��
 */
void main()
{
	timer0Init(); // ��ʼ����ʱ��0�ж�
	Init_LCD1602();
	LCD1602_Clear_Screen();
	LCD1602_Dis_Str(0, 0, "Welcome");
	while(1) {
		keydriver(); // ѭ����ⰴ��
		
	}
}

/**
 * @brief ��ʱ��0�жϷ�����
 * 
 * @param		�� 
 * @return	�� 
 */
void timer0() interrupt 1
{
	TH0 = 0xfc; //���¼��س�ֵ1ms
	TL0 = 0x66;
	keyscan();
}

/**
 * @brief ��ʱ���ж�0��ʼ������
 * 
 * @param 	��
 * @return 	�� 
 */
void timer0Init()
{
	EA = 1;
	TMOD = 0x00; //���� T0 Ϊģʽ 1
	TH0 = 0xfc; //Ϊ T0 ����ֵ 0xFC67����ʱ 1ms
	TL0 = 0x66;
	ET0 = 1; //ʹ�� T0 �ж�
	TR0 = 1; //���� T0
}
