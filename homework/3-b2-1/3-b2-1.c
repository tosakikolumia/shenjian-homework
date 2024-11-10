/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int a, b1, b2, b3, b4, b5;
	printf("请输入一个[1..30000]间的整数:\n");
	scanf("%d", &a);
	b1 = a / 10000;
	b2 = a % 10000 / 1000;
	b3 = a % 10000 % 1000 / 100;
	b4 = a % 10000 % 1000 % 100 / 10;
	b5 = a % 10000 % 1000 % 100 % 10;

	printf("万位 : %d \n", b1);
	printf("千位 : %d \n", b2);
	printf("百位 : %d \n", b3);
	printf("十位 : %d \n", b4);
	printf("个位 : %d \n", b5);
	return 0;
}