/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
double definite_integration(double (*p)(double x), double low, double high, int number) {
    int  i;
    double sum = 0;
    double weight = fabs(low - high) / number;//每小格宽度
    for (i = 1; i <= number; i++) {
        sum += (((*p)(low + i * weight)) * weight);
    }
    return sum;

}
int main() {
    int n;
    double low, high, value;
    printf("请输入sinxdx的下限、上限及区间划分数量\n");
    scanf("%lf%lf%d", &low, &high, &n);
    //输入上下限及划分数量(不考虑输入错误)
    value = definite_integration(sin, low, high, n);//sin为math.h 中已有函数      
    // printf sinxdx的值
    printf("sinxdx[%g~%0g/n=%d] : %g\n", low, high, n, value);
    // 输入上下限及划分数量(不考虑输入错误)
    printf("请输入cosxdx的下限、上限及区间划分数量\n");
    scanf("%lf%lf%d", &low, &high, &n);
    value = definite_integration(cos, low, high, n);//cos 为math.h 中已有函数
    // printf cosxdx的值
    printf("cosxdx[%g~%g/n=%d] : %g\n", low, high, n, value);
    //  输入上下限及划分数量(不考虑输入错误)
    printf("请输入e^xdx的下限、上限及区间划分数量\n");
    scanf("%lf%lf%d", &low, &high, &n);
    value = definite_integration(exp, low, high, n);//exp为math.中已有函数
    printf("e^xdx[%g~%g/n=%d] : %g\n", low, high, n, value);
    // printf edx的值
    return 0;
}