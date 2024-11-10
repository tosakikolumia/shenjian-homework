/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>
#include <windows.h>
#include "5-b7.h"
#include <conio.h>
using namespace std;

int number_quanju = 1;//记录步数
int top_a = 0, top_b = 0, top_c = 0;//
int a[10] = { 0 }, b[10] = { 0 }, c[10] = { 0 };
int speed;//记录延时
bool monitor;//显示内部数组值
void f2() {//打印abc栈
    cct_gotoxy(10, 21);
    cout << "=========================" << endl;
    cct_gotoxy(12, 22);
    cout << "A         B         C";
    int x = 12, y = 20;
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(x, y);
        if (a[i] != 0) {
            cout << a[i];
        }
        else {
            cout << " ";
        }
        y--;
    }
    x = 22, y = 20;
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(x, y);
        if (b[i] != 0) {
            cout << b[i];
        }
        else {
            cout << " ";
        }
        y--;
    }
    x = 32, y = 20;
    for (int i = 0; i < 10; i++) {
        cct_gotoxy(x, y);
        if (c[i] != 0) {
            cout << c[i];
        }
        else {
            cout << " ";
        }
        y--;
    }
}
void f3() {

    cout << "A: ";
    for (int i = 0; i < 10; i++) {
        if (a[i] != 0) {
            cout << a[i] << " ";
        }
        else {
            cout << " ";
        }
    }
    cout << "B: ";
    for (int i = 0; i < 10; i++) {
        if (b[i] != 0) {
            cout << b[i] << " ";
        }
        else {
            cout << " ";
        }
    }
    cout << "C: ";
    for (int i = 0; i < 10; i++) {
        if (c[i] != 0) {
            cout << c[i] << " ";
        }
        else {
            cout << " ";
        }
    }

}
void f1(char src, char dst) {//移动盘子
    int temp = 1;//存放盘
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

}
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        if (speed != 0) {
            Sleep(600 - speed * 100);
        }
        else {
            int ch;
            while ((ch = _getch()) != 13);
        }
        cct_gotoxy(22, 26);
        cout << "第" << setw(4) << number_quanju << " 步" << "(" << setw(2) << n << ")" << ":" << src << "-->" << dst << " ";
        f1(src, dst);
        if (monitor) {
            f3();
            if (speed != 0) {
                Sleep(600 - speed * 100);
            }
            else {
                int ch;
                while ((ch = _getch()) != 13);
            }
        }
        f2();
        number_quanju = number_quanju + 1;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    if (speed != 0) {
        Sleep(600 - speed * 100);
    }
    else {
        int ch;
        while ((ch = _getch()) != 13);
    }
    cct_gotoxy(22, 26);
    cout << "第" << setw(4) << number_quanju << " 步" << "(" << setw(2) << n << ")" << ":" << src << "-->" << dst << " ";
    f1(src, dst);
    if (monitor) {
        f3();
        if (speed != 0) {
            Sleep(600 - speed * 100);
        }
        else {
            int ch;
            while ((ch = _getch()) != 13);
        }
    }
    f2();
    number_quanju = number_quanju + 1;
    hanoi(n - 1, tmp, src, dst);
}

int main()
{
    static int number;
    static char ch1, ch2;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            if (number >= 1 && number <= 10) {
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            }

        }
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
        cin >> ch1;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
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
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            }

        }
        cin.clear();
        cin.ignore(65536, '\n');
    }
    while (1) {
        cout << "请输入目标柱(A-C)" << endl;
        cin >> ch2;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            if ((ch2 >= 'A' && ch2 <= 'C') || (ch2 >= 'a' && ch2 <= 'c')) {
                if (ch1 == ch2 || ch1 + 32 == ch2) {
                    switch (ch2) {
                        case('A'):
                        case('a'):
                            cout << "目标柱(A)不能与起始柱(A)相同" << endl;
                            break;
                        case('b'):
                        case('B'):
                            cout << "目标柱(B)不能与起始柱(B)相同" << endl;
                            break;
                        case('c'):
                        case('C'):
                            cout << "目标柱(C)不能与起始柱(C)相同" << endl;
                            break;

                    }
                    cin.clear();
                    cin.ignore(65536, '\n');
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
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            }

        }
        cin.clear();
        cin.ignore(65536, '\n');
    }

    int number2 = number;//将盘数复制
    if (ch1 == 'A') {//初始化数组
        top_a = number;
        for (int i = 0; i < number; i++) {
            a[i] = number2;
            number2--;

        }
    }
    else if (ch1 == 'B') {
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
    while (1) {
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            if (speed >= 0 && speed <= 5) {
                cin.clear();
                cin.ignore(65536, '\n');
                break;
            }

        }
    }
    while (1) {
        cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
        cin >> monitor;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            break;
        }
    }
    cct_cls();
    if (monitor) {
        cout << "从 " << ch1 << " 移动到 " << ch2 << "，共 " << number << " 层，延时设置为 " << speed << "，显示内部数组值" << endl;
    }
    else {
        cout << "从 " << ch1 << " 移动到 " << ch2 << "，共 " << number << " 层，延时设置为 " << speed << "，不显示内部数组值" << endl;
    }
    if (monitor) {
        cct_gotoxy(22, 26);
        cout << setw(21) << setiosflags(ios::left) << "初始:";
        f3();
    }
    int x = 198 - (int)ch1 - (int)ch2;
    hanoi(number, ch1, (char)x, ch2);
    cct_gotoxy(20, 30);
    system("pause"); //最后用这句表示暂停（注意：只适合于特定程序，无特别声明的程序加此句则得分为0）
    return 0;
}
