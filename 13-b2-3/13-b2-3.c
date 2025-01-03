/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct student {
	int no;//学号，不考虑0开头
	char name[9];//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int score;//成绩，不考虑小数点
	int rank;//名次
};


int main() {
	int num;
	FILE* fin;
	/*FILE* fout;*/
	fin = fopen("student.txt", "r");
	if (fin == NULL) {
		printf("打开输入文件失败\n");
		return -1;
	}
	/*fout = fopen("13_b2_3_output.txt", "w");
	if (fout == NULL) {
		printf("打开输出文件失败\n");
		fclose(fin);
		return -1;
	}*/
	fscanf(fin, "%d", &num);//输入学生人数
	struct student* L = (struct student*)malloc(num * sizeof(struct student));//建立表
	if (L == NULL) {
		printf("申请失败\n");
		return -1;
	}
	/*-----------------输入学生信息----------------*/
	for (int i = 0; i < num; i++) {
		fscanf(fin, "%d", &L[i].no);
		fscanf(fin, "%s", L[i].name);
		fscanf(fin, "%d", &L[i].score);
	}

	/*-----------------进行排序----------------*/
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (j+1<num && L[j].score < L[j + 1].score) {
				struct student temp_score = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp_score;
			}
		}
	}
	/*-------------------将排序后的成员进行排名赋值----------------------*/
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].score == L[i - 1].score) {
			L[i].rank = L[i - 1].rank; // 相同分数名次相同
		}
		else {
			L[i].rank = i + 1; // 名次从1开始
		}
	}
	/*-------------------根据学号进行排名----------------------*/
	int start, end;
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].rank == L[i - 1].rank) {
			start = i - 1;//找到相同名次的开始位置
			int j;
			for (j = i ; j<num && L[j].rank == L[j - 1].rank; j++);
			end = j - 1;//找到相同名次的结束位置
			for (int m = start; m < end; m++) {//排序
				for (int n = start; n < end - m +start; n++) {
					if (L[n].no > L[n + 1].no) {
						struct student temp_no = L[n];
						L[n] = L[n + 1];
						L[n + 1] = temp_no;
					}
				}
			}
			i = end;//跳过相同名次的后续成员
		}
	
	}

	/*-----------------输出学生信息----------------*/
	for (int i = 0; i < num; i++) {
	/*	fprintf(fout, "%d", L[i].no);
		fprintf(fout, " ");
		fprintf(fout, "%s", L[i].name);
		fprintf(fout, " ");
		fprintf(fout, "%d", L[i].score);
		fprintf(fout, " ");
		fprintf(fout, "%d", L[i].rank);
		fprintf(fout, "\n");*/
		printf("%d %s %d %d\n", L[i].no, L[i].name, L[i].score, L[i].rank);
	}
	fclose(fin);
	/*fclose(fout);*/
	free(L);
	return 0;
};