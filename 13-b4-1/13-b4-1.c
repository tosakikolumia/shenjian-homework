/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student {
	int* no;//学号，不考虑0开头
	char* name;//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int* score;//成绩，不考虑小数点
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
	/*fout = fopen("13-b4-1.txt", "w");
	if (fout == NULL) {
		printf("打开输出文件失败\n");
		fclose(fin);
		return -1;
	}*/
	struct student* head = NULL, * p = NULL, * q = NULL;
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

			/*----------学号--------------------------*/
			p->no = (int*)malloc(sizeof(int));
			if (p->no == NULL) {
				printf("内存分配失败！");
				return -1;
			}
			*p->no = temp_no;
			/*-------------姓名-------------------*/
			char temp_name[9];
			fscanf(fin, "%s", temp_name);
			/*scanf("%s", temp_name);*/
			temp_name[8] = '\0';//手动加0
			unsigned int length = strlen(temp_name);
			p->name = (char*)malloc((length + 1) * sizeof(char));
			if (p->name == NULL) {
				printf("内存分配失败！");
				return -1;
			}
			strcpy(p->name, temp_name);
			/*-------------成绩-------------------*/
			p->score = (int*)malloc(sizeof(int));
			if (p->score == NULL) {
				printf("内存分配失败！");
				return -1;
			}
			fscanf(fin, "%d", p->score);
			/*scanf("%d", p->score);*/
			/*-------------链接----------------*/
			p->next = NULL;
			if (i == 0) {
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
		/*fprintf(fout, "%d %s %d\n", *count->no, count->name, *count->score);*/
		printf("%d %s %d\n", *count->no, count->name, *count->score);
		count = count->next;
	}
	fclose(fin);
	/*fclose(fout);*/
	struct student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//释放内存
		n = m->next;
		free(m->score);//反序释放内存，防止内存泄漏
		free(m->name);
		free(m->no);
		free(m);
		m = n;
	}
	return 0;
}