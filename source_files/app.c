#include "config.h"


void key_0()
{
	
}

void key_1()
{

}

void key_2()
{
	
}

void key_3()
{
	
}
void key_4()
{
	
}

void key_5()
{
	
}

void key_6()
{
	
}

void key_7()
{
	
}

void key_8()
{
	
}

void key_9()
{
	
}

void key_10()
{
	
}

void key_11()
{
	
}

void key_12()
{
	
}

void key_13()
{
	
}

void key_14()
{
	
}

void key_15()
{
	
}





/**
 * @brief 	��������ӳ�亯��
 * 
 * @param 	keyvalue 
 * @return 	��
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
		case 10: key_10(); keyjudge = 1; break;
		case 11: key_11(); keyjudge = 1; break;
		case 12: key_12(); keyjudge = 1; break;
		case 13: key_13(); keyjudge = 1; break;
		case 14: key_14(); keyjudge = 1; break;
		case 15: key_15(); keyjudge = 1; break;		
		default: break;
	}
}