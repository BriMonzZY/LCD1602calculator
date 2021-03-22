#include "config.h"
#include "main.h"
#include "lcd1602.h"
#include "app.h"
#include "key.h"

void key_0(uint8 keyvalue)  // 7
{
	
}

void key_1(uint8 keyvalue)  // 8
{

}

void key_2(uint8 keyvalue)  // 9
{
	
}

void key_3(uint8 keyvalue)  // ÷
{
	
}
void key_4(uint8 keyvalue)  // 4
{
	
}

void key_5(uint8 keyvalue)  // 5
{
	
}

void key_6(uint8 keyvalue)  // 6
{
	
}

void key_7(uint8 keyvalue)  // ×
{
	
}

void key_8(uint8 keyvalue)  // 1
{
	
}

void key_9(uint8 keyvalue)  // 2
{
	
}

void key_10(uint8 keyvalue)  // 3
{
	
}

void key_11(uint8 keyvalue)  // -
{
	
}

void key_12(uint8 keyvalue)  // back
{
	
}

void key_13(uint8 keyvalue)  // 0
{
	
}

void key_14(uint8 keyvalue)  // .
{
	
}

void key_15(uint8 keyvalue)  // +
{
	
}





/**
 * @brief 	按键功能映射函数
 * 
 * @param 	keyvalue 
 * @return 	无
 */
void KeyAction(uchar keyvalue) {
	switch (keyvalue)
	{
		case 0: key_0(keyvalue); keyjudge = 1; break;
		case 1: key_1(keyvalue); keyjudge = 1; break;	
		case 2: key_2(keyvalue); keyjudge = 1; break;	
		case 3: key_3(keyvalue); keyjudge = 1; break;
		case 4: key_4(keyvalue); keyjudge = 1; break;
		case 5: key_5(keyvalue); keyjudge = 1; break;
		case 6: key_6(keyvalue); keyjudge = 1; break;
		case 7: key_7(keyvalue); keyjudge = 1; break;
		case 8: key_8(keyvalue); keyjudge = 1; break;
		case 9: key_9(keyvalue); keyjudge = 1; break;
		case 10: key_10(keyvalue); keyjudge = 1; break;
		case 11: key_11(keyvalue); keyjudge = 1; break;
		case 12: key_12(keyvalue); keyjudge = 1; break;
		case 13: key_13(keyvalue); keyjudge = 1; break;
		case 14: key_14(keyvalue); keyjudge = 1; break;
		case 15: key_15(keyvalue); keyjudge = 1; break;		
		default: break;
	}
}