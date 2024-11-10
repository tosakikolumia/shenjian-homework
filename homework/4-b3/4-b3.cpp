/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>  
#include <limits>
using namespace std;
int zeller(int y, int m, int d) {
	int w, c, y1, m1;
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
	int n;
	for (n = 0; w <= 0; n = n + 1) {
		w = w + n * 7;
	}
	return (w % 7);
}
void calender(int year, int month)
{
	/* 按需添加代码 */
	int i = 1, day = 1, number = 0;//每月天数
	int week;
	week = zeller(year, month, day);
	bool leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	cout << endl;
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
	cout << "======================================================" << endl;

	/* 按需添加代码 */

	cout << setw(8 * week) << "" << setiosflags(ios::right) << setw(4) << i << setw(4) << "";
	for (i = 2; i <= (7 - week); ++i) {
		cout << setiosflags(ios::right) << setw(4) << i << setw(4) << "";
	}
	cout << endl;//计算第一行
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
	for (i = (8 - week); i <= number; ++i) {
		cout << setiosflags(ios::right) << setw(4) << i << setw(4) << "";
		if (line % 7 == 0) {
			cout << endl;
		}
		line = line + 1;
	}
	if (line != 29) {
		cout << endl;
	}
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}


int main()
{
	int year, month, day=1;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month ;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else {
			if (year >= 1900 && year <= 2100) {

				if (month >= 1 && month <= 12) {
					break;
				}
				else {
					cout << "月份不正确，请重新输入" << endl;
				}
			}
			else {
				cout << "年份不正确，请重新输入" << endl;
			}
		}

	}
	calender(year, month);
	
	return 0;
}