/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>
using namespace std;



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
int number_quanju = 1;//记录步数
int top[3] = { 0 };
int zhu[3][10];

void f2() {//打印abc栈
    cout << "A: ";
    for (int i = 0; i < 10; i++) {
        if (zhu[0][i] != 0) {
            cout << zhu[0][i] << " ";
        }
        else {
            cout << "  ";
        }
    }
    cout << "B: ";
    for (int i = 0; i < 10; i++) {
        if (zhu[1][i] != 0) {
            cout << zhu[1][i] << " ";
        }
        else {
            cout << "  ";
        }
    }
    cout << "C: ";
    for (int i = 0; i < 10; i++) {
        if (zhu[2][i] != 0) {
            cout << zhu[2][i] << " ";
        }
        else {
            cout << "  ";
        }
    }
    cout << endl;
}
void f1(char src, char dst) {//移动盘子
    int temp = 1;//存放盘
    if (src == 'A') {
        temp = zhu[0][--top[0]];
        zhu[0][top[0]] = 0;
    }
    else if (src == 'B') {
        temp = zhu[1][--top[1]];
        zhu[1][top[1]] = 0;
    }
    else if (src == 'C') {
        temp = zhu[2][--top[2]];
        zhu[2][top[2]] = 0;
    }
    if (dst == 'A') {
        zhu[0][top[0]++] = temp;
    }
    else if (dst == 'B') {
        zhu[1][top[1]++] = temp;
    }
    else if (dst == 'C') {
        zhu[2][top[2]++] = temp;
    }
    f2();


}
void hanoi(int n, char src, char tmp, char dst)
{

    if (n == 1) {
        cout << "第" << setw(4)<< setiosflags(ios::right) << number_quanju << " 步" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst << " ";
        f1(src, dst);
        number_quanju = number_quanju + 1;
        return;
    }
    hanoi(n - 1, src, dst, tmp);
    cout << "第" << setw(4)<< setiosflags(ios::right) << number_quanju << " 步" << "(" << setw(2) << n << ")" << ": " << src << "-->" << dst<<" ";
    f1(src, dst);
    number_quanju = number_quanju + 1;
    hanoi(n - 1, tmp, src, dst);
}
int main()
{
    int number;
    char ch1, ch2;
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
        top[0] = number;
        for (int i = 0; i < number; i++) {
            zhu[0][i] = number2;
            number2--;

        }
    }
    else if (ch1 == 'B') {
        top[1] = number;
        for (int i = 0; i < number; i++) {
            zhu[1][i] = number2;
            number2--;

        }
    }
    else if (ch1 == 'C') {
        top[2] = number;
        for (int i = 0; i < number; i++) {
            zhu[2][i] = number2;
            number2--;

        }
    }
    cout << setw(21) << setiosflags(ios::left) << "初始:";
    f2();
    int x = 198 - (int)ch1 - (int)ch2;
    hanoi(number, ch1, (char)x, ch2);

}