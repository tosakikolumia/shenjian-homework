/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double definite_integration(double (*p)(double x), double low, double high, int number) {
    int  i;
    double sum = 0;
    double weight = fabs(low - high) / number;//ÿС����
    for (i = 1; i <= number; i++) {
        sum += (((*p)(low + i * weight)) * weight);
    }
    return sum;

}
int main() {
    int n;
    double low, high, value;
    printf("������sinxdx�����ޡ����޼����仮������\n");
    scanf("%lf%lf%d", &low, &high, &n);
    //���������޼���������(�������������)
    value = definite_integration(sin, low, high, n);//sinΪmath.h �����к���      
    // printf sinxdx��ֵ
    printf("sinxdx[%g~%0g/n=%d] : %g\n", low, high, n, value);
    // ���������޼���������(�������������)
    printf("������cosxdx�����ޡ����޼����仮������\n");
    scanf("%lf%lf%d", &low, &high, &n);
    value = definite_integration(cos, low, high, n);//cos Ϊmath.h �����к���
    // printf cosxdx��ֵ
    printf("cosxdx[%g~%g/n=%d] : %g\n", low, high, n, value);
    //  ���������޼���������(�������������)
    printf("������e^xdx�����ޡ����޼����仮������\n");
    scanf("%lf%lf%d", &low, &high, &n);
    value = definite_integration(exp, low, high, n);//expΪmath.�����к���
    printf("e^xdx[%g~%g/n=%d] : %g\n", low, high, n, value);
    // printf edx��ֵ
    return 0;
}