/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct student {
	int no;//ѧ�ţ�������0��ͷ
	char name[9];//�������4������(����Ƨ�֣���Ϊ˫�ֽ� GB ����)
	int score;//�ɼ���������С����
	int rank;//����
};


int main() {
	int num;
	FILE* fin;
	/*FILE* fout;*/
	fin = fopen("student.txt", "r");
	if (fin == NULL) {
		printf("�������ļ�ʧ��\n");
		return -1;
	}
	/*fout = fopen("13_b2_3_output.txt", "w");
	if (fout == NULL) {
		printf("������ļ�ʧ��\n");
		fclose(fin);
		return -1;
	}*/
	fscanf(fin, "%d", &num);//����ѧ������
	struct student* L = (struct student*)malloc(num * sizeof(struct student));//������
	if (L == NULL) {
		printf("����ʧ��\n");
		return -1;
	}
	/*-----------------����ѧ����Ϣ----------------*/
	for (int i = 0; i < num; i++) {
		fscanf(fin, "%d", &L[i].no);
		fscanf(fin, "%s", L[i].name);
		fscanf(fin, "%d", &L[i].score);
	}

	/*-----------------��������----------------*/
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (j+1<num && L[j].score < L[j + 1].score) {
				struct student temp_score = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp_score;
			}
		}
	}
	/*-------------------�������ĳ�Ա����������ֵ----------------------*/
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].score == L[i - 1].score) {
			L[i].rank = L[i - 1].rank; // ��ͬ����������ͬ
		}
		else {
			L[i].rank = i + 1; // ���δ�1��ʼ
		}
	}
	/*-------------------����ѧ�Ž�������----------------------*/
	int start, end;
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].rank == L[i - 1].rank) {
			start = i - 1;//�ҵ���ͬ���εĿ�ʼλ��
			int j;
			for (j = i ; j<num && L[j].rank == L[j - 1].rank; j++);
			end = j - 1;//�ҵ���ͬ���εĽ���λ��
			for (int m = start; m < end; m++) {//����
				for (int n = start; n < end - m +start; n++) {
					if (L[n].no > L[n + 1].no) {
						struct student temp_no = L[n];
						L[n] = L[n + 1];
						L[n + 1] = temp_no;
					}
				}
			}
			i = end;//������ͬ���εĺ�����Ա
		}
	
	}

	/*-----------------���ѧ����Ϣ----------------*/
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