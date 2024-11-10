/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



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
int number_quanju = 1;//��¼����
int top_a=0, top_b=0, top_c=0;
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };


void f2() {//��ӡabcջ
    printf("A: ");
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            printf("%d ", a[i]);
        }
        else {
            printf("  ");
        }
    }
    printf("B: ");
    for (int i = 0; i < 10; i++) {
        if (b[i] != 0) {
            printf("%d ", b[i]);
        }
        else {
            printf("  ");
        }
    }
    printf("C: ");
    for (int i = 0; i < 10; i++) {
        if (c[i] != 0) {
            printf("%d ", c[i]);
        }
        else {
            printf("  ");
        }
    }
    printf("\n");
}
void f1(char src, char dst) {//�ƶ�����
    int temp=1;//�����
    if (src == 'A') {
        temp = a[--top_a];
        a[top_a] = 0;
    }
    else if (src == 'B') {
        temp = b[--top_b];
        b[top_b] = 0;
    }
    else if (src == 'C') {
        temp = c[--top_c];
        c[top_c] = 0;
    }
    if (dst == 'A') {
        a[top_a++] = temp;
    }
    else if (dst == 'B') {
        b[top_b++] = temp;
    }
    else if (dst == 'C') {
        c[top_c++] = temp;
    }
    f2();
 
  
}
void hanoi(int n, char src, char tmp, char dst)
{

    if (n == 1) {
        printf("��%4d ��(%2d): %c-->%c ", number_quanju, n, src, dst);
        f1(src, dst);
        number_quanju = number_quanju + 1;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    printf("��%4d ��(%2d): %c-->%c ", number_quanju, n, src, dst);
    f1(src,dst);
    number_quanju = number_quanju + 1;
    hanoi(n - 1, tmp, src, dst);
}
int main()
{
    int number, ret;
    char ch1, ch2;
    while (1) {
        printf("�����뺺ŵ���Ĳ���(1-10)\n");
        ret = scanf("%d", &number);
        if (!ret) {
            char ch;
            while ((ch = getchar()) != '\n');
            continue;
        }
        else {
            if (number >= 1 && number <= 10) {
                char ch;
                while ((ch = getchar()) != '\n');
                break;
            }

        }
    }
    while (1) {
        printf("��������ʼ��(A-C)\n");
        ret = scanf("%c", &ch1);
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
    int number2 = number;//����������
    if (ch1 == 'A') {//��ʼ������
        top_a = number;
        for (int i = 0; i < number; i++) {
            a[i] = number2;
            number2--;

        }
    }
    else if(ch1 == 'B') {
        top_b = number;
        for (int i = 0; i < number; i++) {
            b[i] = number2;
            number2--;

        }
    }
    else if (ch1 == 'C') {
        top_c = number;
        for (int i = 0; i < number; i++) {
            c[i] = number2;
            number2--;

        }
    }
    printf("%-21s","��ʼ:");
    f2();
    int x = 198 - (int)ch1 - (int)ch2;
    hanoi(number, ch1, (char)x, ch2);

}