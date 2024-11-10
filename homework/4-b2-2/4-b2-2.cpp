/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip>  
#include <limits>
using namespace std;
int zeller(int y, int m, int d) {
	int w,c,y1,m1;
	c = y / 100;
	y1 = y % 100;
	if (m >= 3) {
		y1 = y1;
		m1 = m;
	}
	else {
		if (y1 == 0) {
			y1 = 99;
			c = c - 1;
		}
		else {
			y1 = y1 - 1;
		}
		m1 = m + 12;
	}

	w = y1 + (y1 / 4) + (c / 4) - 2 * c + (13 * (m1 + 1) / 5) + d - 1;
	cout << w << endl;
	int n;
	for (n = 0; w <= 0; n = n + 1) {
		w = w + n * 7;
	}
	cout << w << endl;
	return (w % 7);
}



int main()
{
	int year, month, day;

	while (1) {
		cout << "��������[1900-2100]���¡��գ�" << endl;
		cin >> year >> month >> day; 
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else {
			if (year >= 1900 && year <= 2100) {

				if (month >= 1 && month <= 12) {
					bool leap;
					leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
					int number;
					switch (month) {
						case 1:
						case 3:
						case 5:
						case 7:
						case 8:
						case 10:
						case 12:
							number = 31;
							break;
						case 4:
						case 6:
						case 9:
						case 11:
							number = 30;
							break;
						case 2:
							number = 28 + leap;
							break;
					}
					if (day >= 1 && day <= number) {
						break;
					}
					else {
						cout << "�ղ���ȷ������������" << endl;
					}
				}
				else {
					cout << "�·ݲ���ȷ������������" << endl;
				}
			}
			else {
				cout << "��ݲ���ȷ������������" << endl;
			}
		}

	}
	switch (zeller(year, month, day)) {
		case 1:
			cout << "����һ" << endl;
			break;
		case 2:
			cout << "���ڶ�" << endl;
			break;
		case 3:
			cout << "������" << endl;
			break;
		case 4:
			cout << "������" << endl;
			break;
		case 5:
			cout << "������" << endl;
			break;
		case 6:
			cout << "������" << endl;
			break;
		case 0:
			cout << "������" << endl;
			break;
	}
	return 0;
}

	