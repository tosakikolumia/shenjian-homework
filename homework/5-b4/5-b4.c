/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 

int main() {
	printf("请输入成绩（最多1000个），负数结束输入\n");
	int number[1000];
	int score[101][2];
	int i = 0, j = 0;
	int leap = 1;
	for (j = 0; j < 101; j++) {
		score[j][0] = j;  // 存储数字本身   
		score[j][1] = 0;
	}
	for (i = 0; i < 1000; i++) {
		scanf("%d", &number[i]);
		if (number[i] < 0) {
			leap = 0;
			if (i == 0) {
				printf("无有效输入\n");
				return 0;
			}
			break;
		}

	}


	char ch;
	while ((ch = getchar()) != '\n');

	printf("输入的数组为:\n");
	int i2 = 0;
	if (leap) {
		for (i2; i2 <= i; i2 = i2 + 1) {
			printf("%d ", number[i2]);
			if ((i2 + 1) % 10 == 0) {
				if (i2 != i) {
					printf("\n");
				}
				
			}
		}
	}
	else {
		for (i2; i2 < i; i2 = i2 + 1) {
			printf("%d ", number[i2]);
			if ((i2 + 1) % 10 == 0) {
				if (i2 != i-1) {
					printf("\n");
				}
			}

		}
	}
	if ((i2 + 1) % 10 != 0) {
		printf("\n");
	}
	printf("分数与人数的对应关系为:\n");
	for (i = 0; i < i2 + 1; i++) {
		for (j = 0; j < 101; j++) {
			if (number[i] == score[j][0]) {
				score[j][1]++;
			}

		}
	}
	for (j = 100; j >= 0; j--) {
		if (score[j][1] > 0) {
			printf("%d %d\n", score[j][0], score[j][1]);
		}
	}
	return 0;
}