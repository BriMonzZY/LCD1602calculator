#include "config.h"


uchar KeySta[4][4] = { //ȫ�����󰴼��ĵ�ǰ״̬
    {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 1, 1}
};
uchar keyvalue = 0;  //��ֵ


/**
 * @brief ���󰴼�ɨ�躯������while��1���е��ã�
 * 
 * @param  �� 
 * @return �� 
 */
void keydriver() { 
	uchar i, j, gg;//ѭ������
	for (i=0; i<4; i++){
		for (j=0; j<4; j++){
				if (backup[i][j] != KeySta[i][j]){//��ⰴ������
					if (backup[i][j] != 0){
						keyvalue = i * 4 + j; // �����ֵ
						KeyAction(keyvalue); // ���ݼ�ֵѡ�񰴼�����
					}//if (backup[i][j] != 0) ��������ʱִ�ж���
					backup[i][j] = KeySta[i][j]; //����ǰһ�εı���ֵ
				}
		}
	}
}


/**
 * @brief		���󰴼�ɨ�輰��������
 * 
 * @param 	�� 
 * @return 	�� 
 */
void keyscan()
{ //���ж��е���
	uchar m;
	static uchar keyout = 0; //���󰴼�ɨ���������

	static uchar keybuf[4][4] = { //���󰴼�ɨ�軺����
		{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF},
		{0xFF, 0xFF, 0xFF, 0xFF}, {0xFF, 0xFF, 0xFF, 0xFF}
	};
	/*���������°���״̬*/
	//��һ�е� 4 ������ֵ���뻺����
	keybuf[keyout][0] = (keybuf[keyout][0] << 1) | KEY_IN_1;
	keybuf[keyout][1] = (keybuf[keyout][1] << 1) | KEY_IN_2;
	keybuf[keyout][2] = (keybuf[keyout][2] << 1) | KEY_IN_3;
	keybuf[keyout][3] = (keybuf[keyout][3] << 1) | KEY_IN_4;
	//��������°���״̬
	for (m = 0; m < 4; m++){ //ÿ�� 4 ������������ѭ�� 4 ��
			if ((keybuf[keyout][m] & 0x0F) == 0x00){    //���� 4 ��ɨ��ֵΪ 0���� 4*4ms �ڶ��ǰ���״̬ʱ������Ϊ�������ȶ��İ���
					KeySta[keyout][m] = 0;
			}
			else if ((keybuf[keyout][m] & 0x0F) == 0x0F){    //���� 4 ��ɨ��ֵΪ 1���� 4*4ms �ڶ��ǵ���״̬ʱ������Ϊ�������ȶ��ĵ���
					KeySta[keyout][m] = 1;
			}
	}
	
	/*���о��󰴼�ɨ��*/
	//ִ����һ�ε�ɨ�����
	keyout++; //�����������
	keyout = keyout & 0x03; //����ֵ�ӵ� 4 ������
	switch (keyout){ //�����������ͷŵ�ǰ������ţ������´ε��������
			case 0: KEY_OUT_4 = 1; KEY_OUT_1 = 0; break;
			case 1: KEY_OUT_1 = 1; KEY_OUT_2 = 0; break;
			case 2: KEY_OUT_2 = 1; KEY_OUT_3 = 0; break;
			case 3: KEY_OUT_3 = 1; KEY_OUT_4 = 0; break;
			default: break;
	}
}
