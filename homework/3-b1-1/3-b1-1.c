/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    printf("������뾶�͸߶�\n");
    double r, h;
    

    const double pi = 3.14159;
    double c = pi * r * 2;
    double s = pi * r * r;
    double s2 = 4 * pi * r * r;
    double  v = 4 * pi * r * r * r / 3;
    double  v2 = s * h;
    printf("Բ�ܳ�      : %.2lf\n", c);
    printf("Բ���      : %.2lf\n", s);
    printf("Բ������  : %.2lf\n", s2);
    printf("Բ�����    : %.2lf\n", v);
    printf("Բ�������  : %.2f\n", v2);
    return 0;
}