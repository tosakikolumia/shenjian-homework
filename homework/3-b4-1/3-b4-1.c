/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h> 
int main()
{
	printf("请输入三角形的两边及其夹角（角度）\n");
	int a, b, c;
	float s;
	scanf("%d%d%d", &a, &b, &c);
	const double pi = 3.14159;
	s = a * b * sin(c * pi / 180) / 2;
	printf("三角形面积为 : ");
	printf("%.3f \n", s);

	return 0;
}