/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>  

//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/


int main()
{
	const char ch[] = "ʰ��Ǫ����Բ�Ƿ���";
	double a;
	int ret;
	while (1) {
		printf("������[0-100��)֮�������:\n");
		ret = scanf("%lf", &a);
		if (!ret) {
			char ch;
			while ((ch = getchar()) != '\n');
		}
		else {
				break;
		}
		printf("�����������������\n");

	}
	printf("��д�����:\n");
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = (int)(a / 10);//��С��û�н�������������
	shiyi = (int)(a / 1000000000);
	yi = k % 100000000 / 10000000;
	qianwan = k % 100000000 % 10000000 / 1000000;
	baiwan = k % 100000000 % 10000000 % 1000000 / 100000;
	shiwan = k % 100000000 % 10000000 % 1000000 % 100000 / 10000;
	wan = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
	qian = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
	bai = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
	shi = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;
	d = a / 10 - k;
	yuan = (int)((int)(d * 1000+0.5) / 100);//ϵͳ��������ֱ��ʹ�ã���������δ���ܹ��ģ���������в���
	jiao = (int)((int)(d * 1000+0.5)) % 100 / 10;
	fen = (int)((int)(d * 1000+0.5)) % 100 % 10 / 1;
	int count = 0;//��¼result����λ��
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			result[count++] = chnstr[shiyi*2];
			result[count++] = chnstr[shiyi * 2+1];
			result[count++] = ch[0];//ʰ
			result[count++] = ch[1];
		}
		if (yi != 0) {
			result[count++] = chnstr[yi * 2];
			result[count++] = chnstr[yi * 2 + 1];
		}
		result[count++] = ch[8];//��
		result[count++] = ch[9];
	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			result[count++] = chnstr[qianwan * 2];
			result[count++] = chnstr[qianwan * 2 + 1];
			result[count++] = ch[4];//Ǫ
			result[count++] = ch[5];
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (baiwan != 0) {
			result[count++] = chnstr[baiwan * 2];
			result[count++] = chnstr[baiwan * 2 + 1];
	        result[count++] = ch[2];//��
			result[count++] = ch[3];
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];

			}
		}
		if (shiwan != 0) {
			result[count++] = chnstr[shiwan * 2];
			result[count++] = chnstr[shiwan * 2 + 1];
			result[count++] = ch[0];//ʰ
			result[count++] = ch[1];
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (wan != 0) {
			result[count++] = chnstr[wan * 2];
			result[count++] = chnstr[wan * 2 + 1];
		}
		result[count++] = ch[6];//��
		result[count++] = ch[7];
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			result[count++] = chnstr[qian * 2];
			result[count++] = chnstr[qian * 2 + 1];
			result[count++] = ch[4];//Ǫ
			result[count++] = ch[5];
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (bai != 0) {
			result[count++] = chnstr[bai * 2];
			result[count++] = chnstr[bai * 2 + 1];
			result[count++] = ch[2];//��
			result[count++] = ch[3];
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (shi != 0) {
			result[count++] = chnstr[shi * 2];
			result[count++] = chnstr[shi * 2 + 1];
			result[count++] = ch[0];//ʰ
			result[count++] = ch[1];
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (yuan != 0) {
			result[count++] = chnstr[yuan * 2];
			result[count++] = chnstr[yuan * 2 + 1];
		}
		result[count++] = ch[10];//Բ
		result[count++] = ch[11];
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			result[count++] = ch[10];//Բ
			result[count++] = ch[11];
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			result[count++] = chnstr[0];//��
			result[count++] = chnstr[1];
			result[count++] = ch[10];//Բ
			result[count++] = ch[11];
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			result[count++] = chnstr[jiao * 2];
			result[count++] = chnstr[jiao * 2 + 1];
			result[count++] = ch[12];//��
			result[count++] = ch[13];
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) {
				result[count++] = chnstr[0];//��
				result[count++] = chnstr[1];
			}
		}
		if (fen != 0) {
			result[count++] = chnstr[fen * 2];
			result[count++] = chnstr[fen * 2 + 1];
			result[count++] = ch[14];//��
			result[count++] = ch[15];
		}
		else {
			result[count++] = ch[16];//��
			result[count++] = ch[17];
		}
	}
	else {
		result[count++] = ch[16];//��
		result[count++] = ch[17];
	}


	printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
	return 0;
}