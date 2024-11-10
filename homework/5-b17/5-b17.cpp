/* 2351753 信08 黄保翔 */
#include <iostream>
using namespace std;

int main() {
	static const char other[] = "!@#$%^&*-_=+,.?";
	int length, up, lw, num, oth;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> up >> lw >> num >> oth;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(65536, '\n');
		cout << "输入非法" << endl;
		return 0;
	}
	else {
		if (length < 12 || length >16) {
			cout << "密码长度" << "[" << length << "]" << "不正确" << endl;
			return 0;
		}
		if (up < 2||up>length) {
			cout << "大写字母个数" << "[" << up << "]" << "不正确" << endl;
			return 0;
		}
		if (lw < 2||lw>length) {
			cout << "小写字母个数" << "[" << lw << "]" << "不正确" << endl;
			return 0;
		}
		if (num < 2||num>length) {
			cout << "数字个数" << "[" << num << "]" << "不正确" << endl;
			return 0;
		}
		if (oth < 2||oth>length) {
			cout << "其它符号个数" << "[" << oth << "]" << "不正确" << endl;
			return 0;
		}
		if ((up + lw + num + oth)>length) {
			cout << "所有字符类型之和" << "[" << up<<"+"<<lw<<"+"<<num<<"+"<<oth<< "]" << "大于总密码长度"<<length << endl;
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