/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>  
int main()
{
	printf("����������ֵ��\n");
	double a;
	int rmb50, rmb20, rmb10, rmb5, rmb1, rmb05, rmb01, rmb005, rmb002, rmb001;
	scanf("%lf",&a);
	rmb50 = (int)(a / 50);
	a = a - rmb50 * 50;
	rmb20 = (int)(a / 20);
	a = a - rmb20 * 20;
	rmb10 = (int)(a / 10);
	a = a - rmb10 * 10;
	rmb5 = (int)(a / 5);
	a = a - rmb5 * 5;
	rmb1 = (int)(a / 1);
	a = a - rmb1 * 1;
	rmb05 = (int)(a / 0.5);
	a = a - rmb05 * 0.5;
	rmb01 = (int)(a / 0.1);
	a = a - rmb01 * 0.1;
	rmb005 = (int)(a / 0.05);
	a = a - rmb005 * 0.05;
	rmb002 = (int)(a / 0.02);
	a = a - rmb002 * 0.02;
	rmb001 = (int)(a / 0.01);
	a = a - rmb001 * 0.01;
	printf("��%d�����㣬�������£�\n",(rmb50 + rmb20 + rmb10 + rmb5 + rmb1 + rmb05 + rmb01 + rmb005 + rmb002 + rmb001));
	if (rmb50 != 0) {
		printf("50Ԫ : %d��\n", rmb50);
	}
	if (rmb20 != 0) {
		printf("20Ԫ : %d��\n", rmb20);
	}
	if (rmb10 != 0) {
		printf("10Ԫ : %d��\n", rmb10);
	}
	if (rmb5 != 0) {
		printf("5Ԫ  : %d��\n", rmb5);
	}
	if (rmb1 != 0) {
		printf("1Ԫ  : %d��\n", rmb1);
	}
	if (rmb05 != 0) {
		printf("5��  : %d��\n", rmb05);
	}
	if (rmb01 != 0) {
		printf("1��  : %d��\n", rmb01);
	}
	if (rmb005 != 0) {
		printf("5��  : %d��\n", rmb005);
	}
	if (rmb002 != 0) {
		printf("2��  : %d��\n", rmb002);
	}
	if (rmb001 != 0) {
		printf("1��  : %d��\n", rmb001);
	}
	return 0;
}