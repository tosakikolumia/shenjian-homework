/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
int main()
{
	printf("�����������ε����߼���нǣ��Ƕȣ�\n");
	int a, b, c;
	float s;
	scanf("%d%d%d", &a, &b, &c);
	const double pi = 3.14159;
	s = a * b * sin(c * pi / 180) / 2;
	printf("���������Ϊ : ");
	printf("%.3f \n", s);

	return 0;
}