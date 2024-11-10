/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>  
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
void calender(int year)
{
	int i = 1, day = 1, month;
	int week;//起始星期
	bool leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	int number[12] = { 31,0,31,30,31,30,31,31,30,31,30,31 };//每月天数
	number[1] = 28 + leap;
	int month_2;//实际月份
	for (int n = 0; n <= 3; n++) {
		int date[7][21] = { 0 };//记录日期
		for (month = 1; month <= 3; month++) {
			month_2 = month + 3 * n;
			week = zeller(year, month_2, day);
			int k = 1;
			for (int j = (month - 1) * 7 + week; j <= month * 7 - 1; j++) {
				date[1][j] = k;
				k++;
			}
		}
		int j = 0;
		for (month = 1; month <= 3; month++) {
			bool t = 1;
			month_2 = month + 3 * n;
			for (i = 2; i <= 6; i++) {
				if (t) {
					if (date[i - 1][month * 7 - 1] < number[month_2 - 1]) {
						date[i][(month - 1) * 7] = date[i - 1][month * 7 - 1] + 1;//每行第一个等于上一行最后一个+1
					}
					for (j = (month - 1) * 7 + 1; j <= month * 7 - 1; j++) {
						if (date[i][j - 1] < number[month_2 - 1]) {//控制上限天数
							date[i][j] = date[i][j - 1] + 1;
							if (date[i][j] == number[month_2 - 1]) {
								t = 0;//停止增加
							}
						}
						else {
							break;
						}

					}
				}


			}
		}
		if (n == 3) {
			cout << "           " << 1 + 3 * n << "月                            " << 2 + 3 * n << "月                            " << 3 + 3 * n << "月" << endl;
		}
		else {
			cout << "            " << 1 + 3 * n << "月                             " << 2 + 3 * n << "月                             " << 3 + 3 * n << "月" << endl;
		}
		cout << "Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat     Sun Mon Tue Wed Thu Fri Sat" << endl;
		for (i = 1; i <= 6; i++) {
			for (int j = 0; j <= 20; j++) {
				if (date[i][j] != 0) {
					cout << setiosflags(ios::left) << setw(4) << date[i][j];
				}
				else {
					cout << setw(4) << "";
				}

				if ((j + 1) % 7 == 0) {
					cout << "    ";
				}
			}
			cout << endl;
		}
		cout << endl;



	}
	
	
}

int main()
{
	int year;

	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> year ;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else {
			if (year >= 1900 && year <= 2100) {			
					break;
			}
			else {
				cout << "年份不正确，请重新输入" << endl;
			}
		}

	}
	cout << year << "年的日历:" << endl;
	cout << endl;
	calender(year);
	cout << endl;

	return 0;
}