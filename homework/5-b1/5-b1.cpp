/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip>  
using namespace std;

int main(){
	cout << "��������������������������20������0������������" << endl;
	int number[20];
	 int i = 0;
	 bool leap = 1;
	for (i; i < 20; i++) {
		cin >> number[i];
		if (number[i] <= 0) {
			leap = 0;
			if (i == 0) {
				cout << "����Ч����" << endl;
				return 0;
			}
			break;
		}
		
	}
	cin.clear();
	cin.ignore(65536, '\n');
	cout << "ԭ����Ϊ��" << endl;
	int i2 = 0;
	if (leap) {
		for (i2; i2 <= i; i2 = i2 + 1) {
			cout << number[i2] << " ";
		}
	}
	else {
		for (i2; i2 < i; i2 = i2 + 1) {
			cout << number[i2] << " ";
		}
	}
	cout << endl;
	cout << "������Ҫ�����������" << endl;
	int x;
	cin >> x;
	 i2=0;
	if (leap) {
		for (i2; i2 <= i; i2 = i2 + 1) {
			if (x <= number[i2]&&x>number[i2-1]) {
				cout << x << " ";
			}
			cout << number[i2] << " ";
		}
	}
	else {
		for (i2; i2 < i; i2 = i2 + 1) {
			if (x <= number[i2] && x > number[i2 - 1]) {
				cout << x << " ";
			}
			cout << number[i2] << " ";
		}
	}
	return 0;
}