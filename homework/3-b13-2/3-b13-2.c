/* 2351753 ��08 �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int year, month, day, i = 1,ret1,ret2, number = 0;//ÿ������
	while (1) {
		printf("���������(2000-2030)���·�(1-12) : ");
		ret1=scanf("%d %d", &year, &month);
		if (!ret1) {
			char ch;
			while ((ch = getchar()) != '\n');
		}
		else {
			if (year >= 2000 && year <= 2030 && month >= 1 && month <= 12)
				break;
		}
		printf("����Ƿ�������������\n");
	}
	while (1) {
		printf("������%d��%d��1�յ�����(0-6��ʾ������-������) : ", year, month);
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
		printf("����Ƿ�������������\n");
	}
	printf("\n");
	printf("%d��%d�µ�����Ϊ:\n", year, month);
	int leap;
	leap = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0);
	printf("������  ����һ  ���ڶ�  ������  ������  ������  ������\n");
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
	printf("\n");//�����һ��
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

