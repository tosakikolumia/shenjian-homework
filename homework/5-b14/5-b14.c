/* 2351753 ��08 �Ʊ��� */
/* 2353939 ���Ⱥ� 2352747 ���Ǵ� 2352037 ֣ҫ�� 2351433 ���� 2353586 �ۼ���*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  

int main() 
{
	char landmine[28][12] = { 0 };
	for (int j = 1; j <= 10; j++) {
		for (int i = 1; i <= 26; ) {
			scanf("%c", &landmine[i][j]);
			if (landmine[i][j] != ' '&&landmine[i][j]!='\n') {
				i++;
			}

				
		}
	}
	int count = 0, leap = 0;
	for (int j = 1; j <= 10; j++) {
		for (int i = 1; i <= 27; i = i++) {
			if (landmine[i][j] == '*') {
				count++;
			}
		}
	}
	for (int j = 1; j <= 10; j++) {
		for (int i = 1; i <= 26; i++) {
			if (landmine[i][j] != '*') {
				int number = 0;
				if (landmine[i - 1][j - 1] == '*') {
					number++;
				}
				if (landmine[i][j - 1] == '*') {
					number++;
				}
				if (landmine[i + 1][j - 1] == '*') {
					number++;
				}
				if (landmine[i - 1][j] == '*') {
					number++;
				}
				if (landmine[i + 1][j] == '*') {
					number++;
				}
				if (landmine[i - 1][j + 1] == '*') {
					number++;
				}
				if (landmine[i][j + 1] == '*') {
					number++;
				}
				if (landmine[i + 1][j + 1] == '*') {
					number++;
				}
				if (landmine[i][j] != (number + '0')) {
					leap = 1;
					break;
				}
			}
		}
	}
	if (count != 50) {
		printf("����1\n");
	}
	else {
		if (leap == 1) {
			printf("����2\n");
		}
		else {
			printf("��ȷ\n");
		}
	}
}