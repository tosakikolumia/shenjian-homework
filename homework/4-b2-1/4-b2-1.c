/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
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



int main()
{
	int year, month, day, ret;

	while (1) {
		printf("请输入年[1900-2100]、月、日：\n");
		 ret = scanf("%d%d%d", &year, &month, &day);
		if (ret!=3) {
			char ch;
			while ((ch = getchar()) != '\n');
			printf("输入错误，请重新输入\n");
		}
		else {
			if (year >= 1900 && year <= 2100) {

				if (month >= 1 && month <= 12) {
					int leap;
					leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
					int number=0;
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
						printf("日不正确，请重新输入\n");
					}
				}
				else {
					printf("月份不正确，请重新输入\n");
				}
			}
			else {
				printf("年份不正确，请重新输入\n");
			}
		}

	}
	switch (zeller(year, month, day)) {
		case 1:
			printf("星期一\n");
			break;
		case 2:
			printf("星期二\n");
			break;
		case 3:
			printf("星期三\n");
			break;
		case 4:
			printf("星期四\n");
			break;
		case 5:
			printf("星期五\n");
			break;
		case 6:
			printf("星期六\n");
			break;
		case 0:
			printf("星期日\n");
			break;
	}
	return 0;
}
