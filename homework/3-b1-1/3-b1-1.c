/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    printf("请输入半径和高度\n");
    double r, h;
    

    const double pi = 3.14159;
    double c = pi * r * 2;
    double s = pi * r * r;
    double s2 = 4 * pi * r * r;
    double  v = 4 * pi * r * r * r / 3;
    double  v2 = s * h;
    printf("圆周长      : %.2lf\n", c);
    printf("圆面积      : %.2lf\n", s);
    printf("圆球表面积  : %.2lf\n", s2);
    printf("圆球体积    : %.2lf\n", v);
    printf("圆柱体体积  : %.2f\n", v2);
    return 0;
}