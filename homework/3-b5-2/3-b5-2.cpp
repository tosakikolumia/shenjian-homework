/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;
int main()
{
        cout << "�������꣬�£���" << endl;
    int year, month, day,a;
    bool leap;
    cin >> year >> month >> day;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if (month > 0 && month <= 12) {
        if (leap == 1) {
            
            switch (month) {
                case 2:
                    if (day >= 1 && day <= 29) {
                        a = 31 + day;
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
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
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
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
                                a = 31 + 29 + 31 + 30 + 31 +30+31+31+ day;
                                break;                        
                            case 11:
                                a = 31 + 29 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + day;
                                break;
                        }
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
                    }
                    break;
                    
            } 

        }
        else  {
            switch (month) {
                case 2:
                    if (day >= 1 && day <= 28) {
                        a = 31 + day;
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
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
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
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
                        cout << year << "-" << month << "-" << day << "��" << year << "��ĵ�" << a << "��" << endl;
                    }
                    else {
                        cout << "�������-�����µĹ�ϵ�Ƿ�" << endl;
                    }
                    break;
            }
        }
    }
    else {
        cout << "�������-�·ݲ���ȷ";
    }
    
    return 0;
}