#include "config.h"
#include "main.h"
#include "lcd1602.h"
#include "app.h"
#include "key.h"


uchar KeySta[4][4] = { //全部矩阵按键的当前状态
    {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
};
uchar keyvalue = 0;  //键值


/**
 * @brief 矩阵按键扫描函数（在while（1）中调用）
 * 
 * @param  无 
 * @return 无 
 */
void keydriver() { 
	uchar i, j, gg;//循环变量
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
				if (backup[i][j] != KeySta[i][j]){//检测按键动作
					if (backup[i][j] != 0){
						keyvalue = i * 4 + j; // 计算键值
						KeyAction(keyvalue); // 根据键值选择按键动作
					}//if (backup[i][j] != 0) 按键按下时执行动作
					backup[i][j] = KeySta[i][j]; //更新前一次的备份值
				}
		}
	}
}


/**
 * @brief		矩阵按键扫描及消抖函数
 * 
 * @param 	无 
 * @return 	无 
 */
void keyscan()
{ //在中断中调用
	uchar m;
	static uchar keyout = 0; //矩阵按键扫描输出索引

	static uchar keybuf[4][4] = { //矩阵按键扫描缓冲区
		{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
		{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}
	};
	/*消抖并更新按键状态*/
	//将一行的 4 个按键值移入缓冲区
	keybuf[keyout][0] = (keybuf[keyout][0] << 1) | KEY_IN_1;
	keybuf[keyout][1] = (keybuf[keyout][1] << 1) | KEY_IN_2;
	keybuf[keyout][2] = (keybuf[keyout][2] << 1) | KEY_IN_3;
	keybuf[keyout][3] = (keybuf[keyout][3] << 1) | KEY_IN_4;
	//消抖后更新按键状态
	for (m = 0; m < 4; m++){ //每行 4 个按键，所以循环 4 次
			if ((keybuf[keyout][m] & 0x0F) == 0x00){    //连续 4 次扫描值为 0，即 4*4ms 内都是按下状态时，可认为按键已稳定的按下
					KeySta[keyout][m] = 0;
			}
			else if ((keybuf[keyout][m] & 0x0F) == 0x0F){    //连续 4 次扫描值为 1，即 4*4ms 内都是弹起状态时，可认为按键已稳定的弹起
					KeySta[keyout][m] = 1;
			}
	}
	
	/*进行矩阵按键扫描*/
	//执行下一次的扫描输出
	keyout++; //输出索引递增
	keyout = keyout & 0x03; //索引值加到 4 即归零
	switch (keyout){ //根据索引，释放当前输出引脚，拉低下次的输出引脚
			case 0: KEY_OUT_4 = 1; KEY_OUT_1 = 0; break;
			case 1: KEY_OUT_1 = 1; KEY_OUT_2 = 0; break;
			case 2: KEY_OUT_2 = 1; KEY_OUT_3 = 0; break;
			case 3: KEY_OUT_3 = 1; KEY_OUT_4 = 0; break;
			default: break;
	}
}

/**
 * @brief 延时500us
 * 
 * @param  无 
 * @return 无 
 */
void delay_500us(void)   //误差 -0.868055555556us
{
    unsigned char a,b;
    for(b=1;b>0;b--)
        for(a=227;a>0;a--);
}

/**
 * @brief 蜂鸣器
 * 
 * @param  无 
 * @return 无 
 */
void beep()
{
	BUZZER = 0;
	delay_500us();
	BUZZER = 1;
}