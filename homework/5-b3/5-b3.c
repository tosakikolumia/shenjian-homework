/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int f1(int year) {
    int leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    return leap;
}
void f2(int year, int month, int day) {

    int num[12] = { 31,28 + f1(year),31,30,31,30,31,31,30,31,30,31 };
    int i,days=0;
    if (month >= 1 && month <= 12) {
        if (day <= num[month-1] && day >=1) {
            for (i = 0; i < month - 1; i++) {
                days = days + num[i];
            }
            days = days + day;     
            printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, days);
        }
        else {
            printf("�������-�����µĹ�ϵ�Ƿ�\n");
        }
    }
    else {
        printf("�������-�·ݲ���ȷ\n");
    }

  
    
}


int main()
{
    printf("�������꣬�£���\n");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    f2(year, month, day);
    return 0;
}