/* 2351753 –≈08 ª∆±£œË */
/* 2353939 ’‘ﬁ»∫≠ 2352747 Õı–«¥Ô 2352037 ÷£“´ª‘ 2351433 ¡ı“› 2353586 …€ºŒ–¿*/
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
		printf("¥ÌŒÛ1\n");
	}
	else {
		if (leap == 1) {
			printf("¥ÌŒÛ2\n");
		}
		else {
			printf("’˝»∑\n");
		}
	}
}