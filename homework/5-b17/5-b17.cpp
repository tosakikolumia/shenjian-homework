/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;

int main() {
	static const char other[] = "!@#$%^&*-_=+,.?";
	int length, up, lw, num, oth;
	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> length >> up >> lw >> num >> oth;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "����Ƿ�" << endl;
		return 0;
	}
	else {
		if (length < 12 || length >16) {
			cout << "���볤��" << "[" << length << "]" << "����ȷ" << endl;
			return 0;
		}
		if (up < 2||up>length) {
			cout << "��д��ĸ����" << "[" << up << "]" << "����ȷ" << endl;
			return 0;
		}
		if (lw < 2||lw>length) {
			cout << "Сд��ĸ����" << "[" << lw << "]" << "����ȷ" << endl;
			return 0;
		}
		if (num < 2||num>length) {
			cout << "���ָ���" << "[" << num << "]" << "����ȷ" << endl;
			return 0;
		}
		if (oth < 2||oth>length) {
			cout << "�������Ÿ���" << "[" << oth << "]" << "����ȷ" << endl;
			return 0;
		}
		if ((up + lw + num + oth)>length) {
			cout << "�����ַ�����֮��" << "[" << up<<"+"<<lw<<"+"<<num<<"+"<<oth<< "]" << "���������볤��"<<length << endl;
			return 0;
		}
	}
	cout << length << " " << up << " " << lw << " " << num << " " << oth << " " << endl;
	for (int i = 1; i <= 10; i++) {
		char str[17] = { 0 };
		for (int i = 1; i <= up; ) {
			int k = rand() % length;
			if (str[k] == 0) {
				str[k] = 'A' + rand() % 24;
				i++;
			}
		}
		for (int i = 1; i <= lw; ) {
			int k = rand() % length;
			if (str[k] == 0) {
				str[k] = 'a' + rand() % 24;
				i++;
			}
		}
		for (int i = 1; i <= num; ) {
			int k = rand() % length;
			if (str[k] == 0) {
				str[k] = '0' + rand() % 10;
				i++;
			}
		}
		for (int i = 1; i <= oth; ) {
			int k = rand() % length;
			if (str[k] == 0) {
				str[k] = other[rand() % 15];
				i++;
			}
		}
		for (int i = 0; i < length; i++) {
			if (str[i] == 0) {
				switch (rand() % 4 + 1) {
					case 1:
						str[i]= 'A' + rand() % 24;
						break;
					case 2:
						str[i] = 'a' + rand() % 24;
						break;
					case 3:
						str[i] = '0' + rand() % 10;
						break;
					case 4:
						str[i] = other[rand() % 15];
						break;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}