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
 * 矩阵按键功能：
 *
 * 7			8			9			÷
 * 4			5			6			x
 * 1			2			3			-
 * 退格	  0			.			+
 *
 *
 *
 *
 *
 * 键值对应：
 * 
 *
 */
#define __MAIN_C
#include "config.h"

void timer0Init();

uint8 pointer1, pointer2； // LCD 第一行位置指针， 第二行位置指针



/**
 * @brief   主函数
 * @param   无
 * @return  无
 */
void main()
{
	timer0Init(); // 初始化定时器0中断
	while(1) {
		keydriver(); // 循环检测按键
		
		
	}
}

/**
 * @brief 定时器0中断服务函数
 * 
 * @param		无 
 * @return	无 
 */
void timer0() interrupt 1
{
	TH0 = 0xfc; //重新加载初值1ms
	TL0 = 0x66;
	keyscan();
}

/**
 * @brief 定时器中断0初始化函数
 * 
 * @param 	无
 * @return 	无 
 */
void timer0Init()
{
	EA = 1;
	TMOD = 0x01; //设置 T0 为模式 1
	TH0 = 0xfc; //为 T0 赋初值 0xFC67，定时 1ms
	TL0 = 0x66;
	ET0 = 1; //使能 T0 中断
	TR0 = 1; //启动 T0
}
