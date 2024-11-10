/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>  
using namespace std;

int main(){
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入" << endl;
	int number[20];
	 int i = 0;
	 bool leap = 1;
	for (i; i < 20; i++) {
		cin >> number[i];
		if (number[i] <= 0) {
			leap = 0;
			if (i == 0) {
				cout << "无有效输入" << endl;
				return 0;
			}
			break;
		}
		
	}
	cin.clear();
	cin.ignore(65536, '\n');
	cout << "原数组为：" << endl;
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
	cout << "请输入要插入的正整数" << endl;
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