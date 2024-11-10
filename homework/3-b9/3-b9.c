/* 2351753 ÐÅ08 »Æ±£Ïè */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
    int a, b,n=1;
    while (n <= 9) {
        for (a = n, b = 1; b <= n; ++b) {         
                printf("%dx%d=%-4d", b, a, a * b);
        }
        n = n + 1;
        printf("\n");
    }
    printf("\n");
    return 0;
}