# LCD1602计算器

作者：BriMon_zZY

时间：2021.3.22

邮箱：1610937885@qq.com

硬件平台：STC89C52  或 STC89C52RC

实现语言：C

IDE版本：Keil5

注释：Doxygen注释框架



**核心技术路线：**

使用==逆波兰表达式==表示计算式，将中缀表达式转换为后缀表达式。

数据结构：堆栈



**功能：**

实现  + - * / ( )



**显示介质：**

LCD1602

**输入：**

矩阵按键

独立按键



**硬件引脚：**

LCD：

#define LCD1602_DB  P0      //data bus 数据总线
LCD1602_RS = P3^5;		//LCD1602液晶命令/数据选择引脚
LCD1602_RW = P3^6;		//LCD1602液晶读/写选择引脚
LCD1602_EN = P3^4;	 	//LCD1602液晶使能引脚



矩阵按键：

KEY_OUT_1 = P3^0;
KEY_OUT_2 = P3^1;
KEY_OUT_3 = P3^2;
KEY_OUT_4 = P3^3;
KEY_IN_1 = P3^4;
KEY_IN_2 = P3^5;
KEY_IN_3 = P3^6;
KEY_IN_4 = P3^7;



