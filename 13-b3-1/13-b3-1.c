/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct student {
	int no;//ѧ�ţ�������0��ͷ
	char name[9];//�������4������(����Ƨ�֣���Ϊ˫�ֽ� GB ����)
	int score;//�ɼ���������С����
	struct student* next;
};
int main() {
	FILE* fin;
	/*FILE* fout;*/
	fin = fopen("list.txt", "r");
	if (fin == NULL) {
		printf("�������ļ�ʧ��\n");
		return -1;
	}
	/*fout = fopen("13-b3-1.txt", "w");*/
	/*if (fout == NULL) {
		printf("������ļ�ʧ��\n");
		fclose(fin);
		return -1;
	}*/
	struct student* head = NULL,*p=NULL,*q=NULL;
	int i = 0;
	while (1) {
		int temp_no;
		fscanf(fin, "%d", &temp_no);
		if (temp_no == 9999999) {
			break;
		}
		else {
			if (i > 0) {
				q = p;
			}
			p = (struct student*)malloc(sizeof(struct student));
			if (p == NULL) {
				printf("�ڴ����ʧ�ܣ�");
				return -1;
			}
			p->no = temp_no;
			fscanf(fin, "%s", p->name);
			fscanf(fin, "%d", &p->score);
			p->next = NULL;
			if (i==0) {
				head = p;
			}
			else {
				q->next = p;

			}

		}
		i++;
	}
	struct student* count = NULL;
	count = head;
	while (count != NULL) {//���
		/*fprintf(fout, "%d %s %d\n", count->no, count->name, count->score);*/
		printf("%d %s %d\n", count->no, count->name, count->score);
		count = count->next;
	}
	fclose(fin);
	/*fclose(fout);*/
	struct student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//�ͷ��ڴ�
		n=m->next;
		free(m);
		m=n;
	}
	return 0;
}