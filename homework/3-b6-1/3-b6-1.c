/* 2351753 ÐÅ08 »Æ±£Ïè */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>  

int main()
{
	double a;
	printf("ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊý×Ö:\n");
	scanf("%lf", &a);
    printf("´óÐ´½á¹ûÊÇ:\n");
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = (int)(a / 10);//ËõÐ¡£¬Ã»ÓÐ½«¸ÃÊýÕûÌåÀ©´ó
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
	yuan = (int)((int)(round(d * 1000)) / 100);//ÏµÍ³º¯Êý¿ÉÒÔÖ±½ÓÊ¹ÓÃ£¬°üÀ¨¿ÎÉÏÎ´½éÉÜ¹ýµÄ£¬¾ßÌå¿É×ÔÐÐ²éÔÄ
	jiao = (int)((int)(round(d * 1000))) % 100 / 10;
	fen = (int)((int)(round(d * 1000))) % 100 % 10 / 1;
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			switch (shiyi) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}

		if (yi != 0) {
			switch (yi) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}

		}
		printf("ÒÚ");

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			switch (qianwan) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				printf("Áã");
			}
		}
		if (baiwan != 0) {
			switch (baiwan) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				printf("Áã");
			}
		}
		if (shiwan != 0) {
			switch (shiwan) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				printf("Áã");
			}
		}
		if (wan != 0) {
			switch (wan) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}

		}
		printf("Íò");
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			switch (qian) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Çª");
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				printf("Áã");
			}
		}
		if (bai != 0) {
			switch (bai) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("°Û");
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				printf("Áã");
			}
		}
		if (shi != 0) {
			switch (shi) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("Ê°");
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				printf("Áã");
			}
		}
		if (yuan != 0) {
			switch (yuan) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
		}
		printf("Ô²");
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {

			printf("Ô²");
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			printf("Áã");
			printf("Ô²");
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			switch (jiao) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("½Ç");
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0)
				printf("Áã");
		}
		if (fen != 0) {
			switch (fen) {
				case 1:
					printf("Ò¼");
					break;
				case 2:
					printf("·¡");
					break;
				case 3:
					printf("Èþ");
					break;
				case 4:
					printf("ËÁ");
					break;
				case 5:
					printf("Îé");
					break;
				case 6:
					printf("Â½");
					break;
				case 7:
					printf("Æâ");
					break;
				case 8:
					printf("°Æ");
					break;
				case 9:
					printf("¾Á");
					break;
			}
			printf("·Ö");
		}
		else {
			printf("Õû");
		}
	}
	else {
		printf("Õû");
	}


	printf("\n");
	return 0;
}