/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip> 
#include <limits>
using namespace std;
int main()
{
	int year, month, day, i=1 , number=0;//ÿ������
	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');			
		}
		else {
			if (year >= 2000 && year <= 2030 && month>=1 && month<=12)
				break;
		}
		cout << "����Ƿ�������������" << endl;
	}


	while (1) {
		cout << "������" << year << "��" << month << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> day;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else {
			if (day <= 6 && day >= 0) {
				break;
			}
		}
		cout << "����Ƿ�������������" << endl;
	}
	cout << endl;
	cout << year << "��" << month << "�µ�����Ϊ:" << endl;
	bool leap;
	leap =( year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << setw(8 * day) << "" << setiosflags(ios::right) << setw(4) << i << setw(4) << "";
	for (i = 2; i <= (7 - day); ++i) {
		cout << setiosflags(ios::right) << setw(4) << i << setw(4) << "";
	}
	cout << endl;//�����һ��
	int line = 1;
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
	for (i = (8-day); i <= number;++i) {
	    cout <<setiosflags(ios::right) << setw(4) << i << setw(4)<<"";
		if (line % 7 == 0) {
			cout << endl;
		}
		line = line + 1;
	}
	cout << endl;
	return 0;
}