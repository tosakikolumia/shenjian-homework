/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2��������һ��ȫ�ֱ������������徲̬�ֲ�����
   3�������������������
   4��main�����������룬����ѭ��
   --------------------------------------------------------------------- */


   /***************************************************************************
     �������ƣ�
     ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
     ���������int n������
               char src����ʼ��
               char tmp���м���
               char dst��Ŀ����
     �� �� ֵ��
     ˵    ����1�����������βΡ��������;���׼��
               2������������������κ���ʽ��ѭ��
   ***************************************************************************/
int number_quanju = 1;
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        printf("%5d:  %d# %c-->%c\n", number_quanju , n, src, dst);
        number_quanju = number_quanju + 1;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    printf("%5d:%3d# %c-->%c\n", number_quanju, n, src, dst);
    number_quanju = number_quanju + 1;
    hanoi(n - 1, tmp, src, dst);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����1��������롢���õݹ麯��
            2�������������ʱ������ʹ��ѭ��
            3��Ϊ��ͳһ��飬���������������������������ʼ/Ŀ�����Ĵ��벻Ҫ��ͳһ����������ֱ�ӷ���main�У�
***************************************************************************/
int main()
{
    int number,ret;
    char ch1, ch2;
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-16)\n");
        ret=scanf("%d", &number);
        if (!ret) {
            char ch;
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (number >= 1 && number <= 16) {
                char ch;
                while ((ch = getchar()) != '\n');
                break;
            }

        }
    }
    while (1) {
        printf("��������ʼ��(A-C)\n");
        ret=scanf("%c", &ch1);
        if (!ret) {
            char ch;
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if ((ch1 >= 'A' && ch1 <= 'C') || (ch1 >= 'a' && ch1 <= 'c')) {
                switch (ch1) {
                    case('A'):
                    case('a'):
                        ch1 = 'A';
                        break;
                    case('B'):
                    case('b'):
                        ch1 = 'B';
                        break;
                    case('C'):
                    case('c'):
                        ch1 = 'C';
                        break;
                }
                char ch;
                while ((ch = getchar()) != '\n');
                break;
            }

        }
        char ch;
        while ((ch = getchar()) != '\n');
    }
    while (1) {
        printf("������Ŀ����(A-C)\n");
        ret = scanf("%c", &ch2);
        if (!ret) {
            char ch;
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if ((ch2 >= 'A' && ch2 <= 'C') || (ch2 >= 'a' && ch2 <= 'c')) {
                if (ch1 == ch2 || ch1 + 32 == ch2) {
                    switch (ch2) {
                        case('A'):
                        case('a'):
                            printf("Ŀ����(A)��������ʼ��(A)��ͬ\n");
                            break;
                        case('b'):
                        case('B'):
                            printf("Ŀ����(B)��������ʼ��(B)��ͬ\n");
                            break;
                        case('c'):
                        case('C'):
                            printf("Ŀ����(C)��������ʼ��(C)��ͬ\n");
                            break;

                    }
                    char ch;
                    while ((ch = getchar()) != '\n');
                    continue;
                }
                switch (ch2) {
                    case('A'):
                    case('a'):
                        ch2 = 'A';
                        break;
                    case('B'):
                    case('b'):
                        ch2 = 'B';
                        break;
                    case('C'):
                    case('c'):
                        ch2 = 'C';
                        break;
                }
                char ch;
                while ((ch = getchar()) != '\n');
                break;
            }

        }
        char ch;
        while ((ch = getchar()) != '\n');
    }
    printf("�ƶ�����Ϊ:\n");
    int x = 198 - (int)ch1 - (int)ch2;
    hanoi(number, ch1, (char)x, ch2);
}