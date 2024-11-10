/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量
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
void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {

        cout << " "<< n << "# " << src << "-->" << dst << endl;
        return;
    }
    hanoi(n - 1, src, dst, tmp);  
    cout << setw(2)<< n << "# " << src << "-->" << dst << endl;
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
    int number;
    char ch1, ch2;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> number;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        else {
            if (number >= 1 && number <= 16) {
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
                if (ch1 == ch2 || ch1 + 32 == ch2 ) {
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
    cout << "移动步骤为:" << endl;
    int x = 198 - int(ch1) -int(ch2);
    hanoi(number, ch1,char(x), ch2);
}