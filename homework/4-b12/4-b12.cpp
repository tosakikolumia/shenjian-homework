/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----����Ҫ��----
   1���������������ͷ�ļ�
   2����������ȫ�ֱ�������̬�ֲ�����
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
    int number;
    char ch1, ch2;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-16)" << endl;
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
        cout << "��������ʼ��(A-C)" << endl;
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
        cout << "������Ŀ����(A-C)" << endl;
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
                            cout << "Ŀ����(A)��������ʼ��(A)��ͬ" << endl;
                            break;
                        case('b'):
                        case('B'):
                            cout << "Ŀ����(B)��������ʼ��(B)��ͬ" << endl;
                            break;
                        case('c'):
                        case('C'):
                            cout << "Ŀ����(C)��������ʼ��(C)��ͬ" << endl;
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
    cout << "�ƶ�����Ϊ:" << endl;
    int x = 198 - int(ch1) -int(ch2);
    hanoi(number, ch1,char(x), ch2);
}