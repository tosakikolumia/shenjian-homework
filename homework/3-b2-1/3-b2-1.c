/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b1, b2, b3, b4, b5;
	printf("������һ��[1..30000]�������:\n");
	scanf("%d", &a);
	b1 = a / 10000;
	b2 = a % 10000 / 1000;
	b3 = a % 10000 % 1000 / 100;
	b4 = a % 10000 % 1000 % 100 / 10;
	b5 = a % 10000 % 1000 % 100 % 10;

	printf("��λ : %d \n", b1);
	printf("ǧλ : %d \n", b2);
	printf("��λ : %d \n", b3);
	printf("ʮλ : %d \n", b4);
	printf("��λ : %d \n", b5);
	return 0;
}