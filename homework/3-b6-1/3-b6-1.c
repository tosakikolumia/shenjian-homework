/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>  

int main()
{
	double a;
	printf("������[0-100��)֮�������:\n");
	scanf("%lf", &a);
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
	yuan = (int)((int)(round(d * 1000)) / 100);//ϵͳ��������ֱ��ʹ�ã���������δ���ܹ��ģ���������в���
	jiao = (int)((int)(round(d * 1000))) % 100 / 10;
	fen = (int)((int)(round(d * 1000))) % 100 % 10 / 1;
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			switch (shiyi) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}

		if (yi != 0) {
			switch (yi) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}

		}
		printf("��");

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			switch (qianwan) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				printf("��");
			}
		}
		if (baiwan != 0) {
			switch (baiwan) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				printf("��");
			}
		}
		if (shiwan != 0) {
			switch (shiwan) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				printf("��");
			}
		}
		if (wan != 0) {
			switch (wan) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}

		}
		printf("��");
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			switch (qian) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("Ǫ");
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				printf("��");
			}
		}
		if (bai != 0) {
			switch (bai) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				printf("��");
			}
		}
		if (shi != 0) {
			switch (shi) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("ʰ");
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				printf("��");
			}
		}
		if (yuan != 0) {
			switch (yuan) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
		}
		printf("Բ");
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {

			printf("Բ");
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			printf("��");
			printf("Բ");
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			switch (jiao) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0)
				printf("��");
		}
		if (fen != 0) {
			switch (fen) {
				case 1:
					printf("Ҽ");
					break;
				case 2:
					printf("��");
					break;
				case 3:
					printf("��");
					break;
				case 4:
					printf("��");
					break;
				case 5:
					printf("��");
					break;
				case 6:
					printf("½");
					break;
				case 7:
					printf("��");
					break;
				case 8:
					printf("��");
					break;
				case 9:
					printf("��");
					break;
			}
			printf("��");
		}
		else {
			printf("��");
		}
	}
	else {
		printf("��");
	}


	printf("\n");
	return 0;
}