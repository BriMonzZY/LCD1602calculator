# LCD1602计算器

作者：BriMon

时间：2021.3.21

1610937885@qq.com

平台：STC89C52  或 STC89C52RC

部分注释遵循Doxygen协议



**功能：**

实现+-*/

**显示介质：**

LCD1602

**输入：**

矩阵按键



**硬件引脚：**

LCD：

#define LCD1602_DB  P0      //data bus 数据总线
sbit LCD1602_RS = P3^5;		//LCD1602液晶命令/数据选择引脚
sbit LCD1602_RW = P3^6;		//LCD1602液晶读/写选择引脚
sbit LCD1602_EN = P3^4;	 	//LCD1602液晶使能引脚



矩阵按键：

sbit KEY_OUT_1 = P3^0;
sbit KEY_OUT_2 = P3^1;
sbit KEY_OUT_3 = P3^2;
sbit KEY_OUT_4 = P3^3;
sbit KEY_IN_1 = P3^4;
sbit KEY_IN_2 = P3^5;
sbit KEY_IN_3 = P3^6;
sbit KEY_IN_4 = P3^7;



