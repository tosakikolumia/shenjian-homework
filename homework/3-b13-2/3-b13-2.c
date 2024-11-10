/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day, i = 1,ret1,ret2, number = 0;//每月天数
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1=scanf("%d %d", &year, &month);
		if (!ret1) {
			char ch;
			while ((ch = getchar()) != '\n');
		}
		else {
			if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
				break;
		}
		printf("输入非法，请重新输入\n");
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		ret2=scanf("%d", &day);
		if (!ret2) {
			char ch2;
			while ((ch2 = getchar()) != '\n');
		}
		else {
			if (day <= 6 && day >= 0) {
				break;
			}
		}
		printf("输入非法，请重新输入\n");
	}
	printf("\n");
	printf("%d年%d月的月历为:\n", year, month);
	int leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	switch (day) {
		case 1:
			printf("%8s%4d%4s", "", i, "");
			break;
		case 2:
			printf("%16s%4d%4s", "", i, "");
			break;
		case 3:
			printf("%24s%4d%4s", "", i, "");
			break;
		case 4:
			printf("%32s%4d%4s", "", i, "");
			break;
		case 5:
			printf("%40s%4d%4s", "", i, "");
			break;
		case 6:
			printf("%48s%4d%4s", "", i, "");
			break;
		case 0:
			printf("%4d%4s", i, "");
			break;
	}
	for (i = 2; i <= (7 - day); ++i) {
		printf("%4d%4s", i, "");
	}
	printf("\n");//计算第一行
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
	for (i = (8 - day); i <= number; ++i) {
		printf("%4d%4s", i, "");

		if (line % 7 == 0) {
			printf("\n");
		}
		line = line + 1;
	}
    printf("\n");
	return 0;
}

