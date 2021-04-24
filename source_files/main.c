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
 * 矩阵按键功能：
 *
 * 7			8			9			÷
 * 4			5			6			x
 * 1			2			3			-
 * 退格	  0			=			+
 *
 *
 *
 *
 *
 * 键值对应：
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
uint8 cursor2; // LCD 第一行位置指针， 第二行位置指针
float num_in_buff = 0.1;
char str[40];  //存储输入的中缀表达式


uchar backup[4][4] = { //初始化按键值备份
			{1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
};


//#define INITSIZE  20
//#define INCREMENT 10
//#define MAXBUFFER 20
//#define LEN  sizeof(Elemtype)
/*栈的动态分配存储结构*/ 
//typedef char Elemtype;
//struct SqStack{
//	Elemtype *base;
//	Elemtype *top;
//	int StackSize;
//};




/**
 * @brief   主函数
 * @param   无
 * @return  无
 */
void main()
{
	timer0Init(); // 初始化定时器0中断
	Init_LCD1602();
	LCD1602_Clear_Screen();
	LCD1602_Dis_Str(0, 0, "Welcome");
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
	TMOD = 0x00; //设置 T0 为模式 1
	TH0 = 0xfc; //为 T0 赋初值 0xFC67，定时 1ms
	TL0 = 0x66;
	ET0 = 1; //使能 T0 中断
	TR0 = 1; //启动 T0
}
