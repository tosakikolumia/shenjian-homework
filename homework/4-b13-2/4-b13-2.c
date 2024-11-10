/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */


   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
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
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int number,ret;
    char ch1, ch2;
    while (1) {
        printf("请输入汉诺塔的层数(1-16)\n");
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
        printf("请输入起始柱(A-C)\n");
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
        printf("请输入目标柱(A-C)\n");
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
                            printf("目标柱(A)不能与起始柱(A)相同\n");
                            break;
                        case('b'):
                        case('B'):
                            printf("目标柱(B)不能与起始柱(B)相同\n");
                            break;
                        case('c'):
                        case('C'):
                            printf("目标柱(C)不能与起始柱(C)相同\n");
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
    printf("移动步骤为:\n");
    int x = 198 - (int)ch1 - (int)ch2;
    hanoi(number, ch1, (char)x, ch2);
}