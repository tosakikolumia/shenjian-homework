/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
struct student {
	int no;//学号，不考虑0开头
	char name[9];//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int score;//成绩，不考虑小数点
	struct student* next;
};
int main() {
	FILE* fin;
	/*FILE* fout;*/
	fin = fopen("list.txt", "r");
	if (fin == NULL) {
		printf("打开输入文件失败\n");
		return -1;
	}
	/*fout = fopen("13-b3-1.txt", "w");*/
	/*if (fout == NULL) {
		printf("打开输出文件失败\n");
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
				printf("内存分配失败！");
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
	while (count != NULL) {//输出
		/*fprintf(fout, "%d %s %d\n", count->no, count->name, count->score);*/
		printf("%d %s %d\n", count->no, count->name, count->score);
		count = count->next;
	}
	fclose(fin);
	/*fclose(fout);*/
	struct student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//释放内存
		n=m->next;
		free(m);
		m=n;
	}
	return 0;
}