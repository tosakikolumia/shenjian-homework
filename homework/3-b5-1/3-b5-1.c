/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>    

int main()
{
    printf("�������꣬�£���\n");
    int year, month, day, a;
    int leap;
    scanf("%d %d %d", & year ,& month, & day);
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 0 && month <= 12) {
        if (leap == 1) {

            switch (month) {
                case 2:
                    if (day >= 1 && day <= 29) {
                        a = 31 + day;
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if (day >= 1 && day <= 31) {
                        switch (month) {
                            case 1:
                                a = day;
                                break;
                            case 3:
                                a = 31 + 29 + day;
                                break;
                            case 5:
                                a = 31 + 29 + 31 + 30 + day;
                                break;
                            case 7:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + day;
                                break;
                            case 8:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + day;
                                break;
                            case 10:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
                                break;
                            case 12:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
                                break;
                        }
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (day >= 1 && day <= 30) {
                        switch (month) {
                            case 4:
                                a = 31 + 29 + 31 + day;
                                break;
                            case 6:
                                a = 31 + 29 + 31 + 30 + 31 + day;
                                break;
                            case 9:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + day;
                                break;
                            case 11:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
                                break;
                        }
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;

            }

        }
        else {
            switch (month) {
                case 2:
                    if (day >= 1 && day <= 28) {
                        a = 31 + day;
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                case 12:
                    if (day >= 1 && day <= 31) {
                        switch (month) {
                            case 1:
                                a = day;
                                break;
                            case 3:
                                a = 31 + 28 + day;
                                break;
                            case 5:
                                a = 31 + 28 + 31 + 30 + day;
                                break;
                            case 7:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + day;
                                break;
                            case 8:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + day;
                                break;
                            case 10:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + day;
                                break;
                            case 12:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30 + day;
                                break;
                        }
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    if (day >= 1 && day <= 30) {
                        switch (month) {
                            case 4:
                                a = 31 + 28 + 31 + day;
                                break;
                            case 6:
                                a = 31 + 28 + 31 + 30 + 31 + day;
                                break;
                            case 9:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + day;
                                break;
                            case 11:
                                a = 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
                                break;
                        }
                        printf("%d-%d-%d��%d��ĵ�%d��\n",year,month,day,year,a);
                    }
                    else {
                        printf("�������-�����µĹ�ϵ�Ƿ�\n");
                    }
                    break;
            }
        }
    }
    else {
        printf("�������-�·ݲ���ȷ\n");
    }

    return 0;
}