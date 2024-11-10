/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <string.h>  
#define N 10
void input(char name[][9], char number[][8], int score[10]) {
	for (int i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		scanf("%s", number[i]);
		scanf("%s", name[i]);
		scanf("%d", &score[i]);
	}
}

void rank(char s[10][8], char s2[10][9], int num[10]) {
	char temp[8] = { 0 };
	char temp2[9] = { 0 };
	int t, g;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (num[j]<num[j+1]) {
				t = num[j];
				strcpy(temp, s[j]);
				strcpy(temp2, s2[j]);
				num[j] = num[j+1];
				strcpy(s2[j], s2[j+1]);
				strcpy(s[j], s[j+1]);
				num[j + 1] = t;
				strcpy(s[j+1],temp);
				strcpy(s2[j+1], temp2);
			}
		}
	}
}
void output(char s[][8], char s2[][9], int num[10]) {
	printf("全部学生(成绩降序):\n");
	for (int i = 0; i <10; i++) {
		printf("%s %s %d\n", s2[i], s[i], num[i]);
	}

}
int main()
{
	char name[10][9];
	char number[10][8];
	int score[10] = { 0 };
	input(name, number, score);
	rank(number, name, score);
	output(number, name, score);
	return 0;
}