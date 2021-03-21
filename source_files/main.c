/**
 * @project caculator
 * @author BriMonzZY (1610937885@qq.com)
 * @brief 
 * @version 0.1
 * @date 2021-03-21
 * @paltform STC89C52 & STC89C52RC
 * @copyright Copyright (c) 2021
 * 
 *
 *
 * ���󰴼����ܣ�
 *
 * 7			8			9			��
 * 4			5			6			x
 * 1			2			3			-
 * �˸�	  0			.			+
 *
 *
 *
 *
 *
 * ��ֵ��Ӧ��
 * 
 *
 */
#define __MAIN_C
#include "config.h"

void timer0Init();

uint8 pointer1, pointer2�� // LCD ��һ��λ��ָ�룬 �ڶ���λ��ָ��



/**
 * @brief   ������
 * @param   ��
 * @return  ��
 */
void main()
{
	timer0Init(); // ��ʼ����ʱ��0�ж�
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
	TMOD = 0x01; //���� T0 Ϊģʽ 1
	TH0 = 0xfc; //Ϊ T0 ����ֵ 0xFC67����ʱ 1ms
	TL0 = 0x66;
	ET0 = 1; //ʹ�� T0 �ж�
	TR0 = 1; //���� T0
}
