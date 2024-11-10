/* 2351753 ÐÅ08 »Æ±£Ïè */
#include <iostream>
#include <cstring>
# define X 10
# define Y 17
using namespace std;
int main() {
	static const char other[] = "!@#$%^&*-_=+,.?";
	cin.ignore(INT_MAX, '\n');
	int length, up, lw, num, oth;
	cin >> length >> up >> lw >> num >> oth;
	if (cin.fail()) {
		cout << "´íÎó" << endl;
		return 0;
	}
	else {
		if (length < 12 || length >16) {
			cout << "´íÎó" << endl;
			return 0;
		}
		if (up < 2 || up>length) {
			cout << "´íÎó" << endl;
			return 0;
		}
		if (lw < 2 || lw>length) {
			cout << "´íÎó" << endl;
			return 0;
		}
		if (num < 2 || num>length) {
			cout << "´íÎó" << endl;
			return 0;
		}
		if (oth < 2 || oth>length) {
			cout << "´íÎó" << endl;
			return 0;
		}
		if ((up + lw + num + oth) > length) {
			cout << "´íÎó" << endl;
			return 0;
		}
	}
	char str[X][Y] = { 0 };
	for (int i = 0; i <10; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 10; i++) {
		int count1 = 0, count2 = 0, count3 = 0,count4=0;
		if (strlen(str[i]) != length ) {
			cout << "´íÎó" << endl;
			return 0;
		}
		else {
			for (int j = 0; j < length; j++){
				if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
					count1++;
				}
				if (str[i][j] >= 'a' && str[i][j] <= 'z') {
					count2++;
				}
				if (str[i][j] >= '0' && str[i][j] <= '9') {
					count3++;
				}
				for (int k = 0; k <= 15; k++) {
					if (str[i][j] == other[k]) {
						count4++;
					}
				}
			}
			if (count1 < up || count2 < lw || count3 < num||count4<oth) {
				cout << "´íÎó" << endl;
				return 0;
			}
			if (count1+count2 + count3 + count4 !=length) {
				cout << "´íÎó" << endl;
				return 0;
			}
		}
		
	}
	cout << "ÕýÈ·" << endl;
	return 0;

}
