/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;
int max(int a1, int a2) {
	return a1 > a2 ? a1 : a2;
}
int max(int a1, int a2,int a3) {
	int p;
	if (a1 > a2) {
		p = a1;
	}
	else {
		p = a2;
	}
	return p > a3 ? p : a3;
}
int max(int a1, int a2, int a3,int a4) {
	int p;
	if (a1 > a2) {
		p = a1;
	}
	else {
		p = a2;
	}
	if (a3 > p) {
		p = a3;
	}
	return p > a4 ? p : a4;
}
int main() {
	int number, x1, x2, x3, x4;

	while (1) {
		cout << "���������num��num����������" << endl;
		cin >> number;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else if(number >= 2 && number <= 4) {
				switch (number) {
					case 2:
						cin >> x1 >> x2;
						if (cin.fail()|| x1<=0||x2<=0) {
							cin.clear();
							cin.ignore(65536, '\n');
							continue;
						}
						else {
							cout << "max=" << max(x1, x2) << endl;
							break;
						}
					case 3:
						cin >> x1 >> x2 >> x3;
						if (cin.fail() || x1 <= 0 || x2 <= 0||x3<=0) {
							cin.clear();
							cin.ignore(65536, '\n');
							continue;
						}
						else {
							cout << "max=" << max(x1, x2, x3) << endl;
							break;
						}
					case 4:
						cin >> x1 >> x2 >> x3 >> x4;
						if (cin.fail() || x1 <= 0 || x2 <= 0 || x3 <= 0 ||x4<0) {
							cin.clear();
							cin.ignore(65536, '\n');
							continue;
						}
						else {
							cout << "max=" << max(x1, x2, x3, x4) << endl;
							break;
						}

				}
				break;
		}		
		else {
			cout << "�����������" << endl;
			break;
		}
	}
	return 0;

}