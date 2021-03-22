#include "config.h"
#include "main.h"
#include "lcd1602.h"
#include "app.h"
#include "key.h"



/**
 * @brief 判断液晶繁忙
 * 
 * @param 	无
 * @return 	无 
 */
void Read_Busy()
{
	uint8 busy;
	LCD1602_DB = 0xff;//复位数据总线
	LCD1602_RS = 0;	  //拉低RS
	LCD1602_RW = 1;	  //拉高RW读
	do
	{
		LCD1602_EN = 1;//使能EN
		busy = LCD1602_DB;//读回数据
		LCD1602_EN = 0;	 //拉低使能以便于下一次产生上升沿
	}while(busy & 0x80); //判断状态字BIT7位是否为1，为1则表示忙，程序等待
}



/**
 * @brief 写命令
 * 
 * @param 	cmd
 * @return 	无 
 */
void LCD1602_Write_Cmd(uint8 cmd)
{
	Read_Busy();	 //判断忙，忙则等待
	LCD1602_RS = 0;	 //选择为写命令
	LCD1602_RW = 0;	//模式为写
	LCD1602_DB = cmd;//写入命令
	LCD1602_EN = 1;	 //拉高使能端 数据被传输到LCD1602内
	LCD1602_EN = 0;	 //拉低使能以便于下一次产生上升沿
}


/**
 * @brief 写数据
 * 
 * @param 	dat 
 * @return 	无 
 */
void LCD1602_Write_Dat(uint8 dat)
{
	Read_Busy();  //判断忙，忙则等待
	LCD1602_RS = 1;	//选择为写数据
	LCD1602_RW = 0;	//模式为写
	LCD1602_DB = dat; //写入8位数据
	LCD1602_EN = 1;	  //拉高使能端 数据被传输到LCD1602内
	LCD1602_EN = 0;	  //拉低使能以便于下一次产生上升沿
}


/**
 * @brief 清屏
 * 
 * @param 	无 
 * @return 	无 
 */
void LCD1602_Clear_Screen()
{
	LCD1602_Write_Cmd(0x01);
}


/**
 * @brief 打开光标闪烁效果
 * 
 * @param  无
 * @return 无 
 */
void LCD1602_Open_Cursor()
{
	LCD1602_Write_Cmd(0x0F);
}



/**
 * @brief 关闭光标显示
 * 
 * @param 	无
 * @return 	无 
 */
void LCD1602_Close_Cursor()
{
	LCD1602_Write_Cmd(0x0C);
}



/**
 * @brief Get the year object
 * 
 * @param x
 * @param y
 * @return 	无
 */
void LCD1602_Set_Cursor(uint8 x, uint8 y)
{
	if(y) x |= 0x40;
	x |= 0x80;
	LCD1602_Write_Cmd(x);
}


/**
 * @brief 显示一个字符
 * 
 * @param 	x 	要显示的横坐标取值0-40
 * @param 	y 	要显示的行坐标取值0-1（0为第一行,1为第二行）
 * @param 	dat 需要显示的数据以ASCLL形式显示
 * @return 	无 
 */
void LCD1602_Dis_OneChar(uint8 x, uint8 y, uint8 dat)
{
	LCD1602_Set_Cursor(x, y);//设置RAM起始位置
	LCD1602_Write_Dat(dat);	 //写入一个字节的数据	
}




/**
 * @brief 显示字符串
 * 
 * @param 	x
 * @param		y
 * @return 	无
 */
void LCD1602_Dis_Str(uint8 x, uint8 y, uint8 *str)
{
	LCD1602_Set_Cursor(x, y);//设置RAM起始位置
	while(*str != '\0')	     //写入字符串数据
	{
		LCD1602_Write_Dat(*str++);
	}
}


/**
 * @brief 初始化LCD
 * 
 * @param 	无
 * @return 	无
 */
void Init_LCD1602()
{
	LCD1602_Write_Cmd(0x38); //	设置16*2显示，5*7点阵，8位数据接口
	LCD1602_Write_Cmd(0x0c); //开显示,关闭光标
	LCD1602_Write_Cmd(0x06); //读写一字节后地址指针加1
	LCD1602_Write_Cmd(0x01); // 清屏
}