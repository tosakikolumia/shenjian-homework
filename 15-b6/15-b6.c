/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage(const char* const procname)
{
	printf("Usage : %s --check �ļ��� | --convert { wtol|ltow } Դ�ļ��� Ŀ���ļ���\n", procname);
	printf("        %s --check a.txt\n", procname);
	printf("        %s --convert wtol a.win.txt a.linux.txt\n", procname);
	printf("        %s --convert ltow a.linux.txt a.win.txt\n", procname);
	return 0;
}
void check(FILE* fin, int* iswin, int* islinux) {
	while (!feof(fin)) {
		unsigned char c;
		c = fgetc(fin);
		long pos = ftell(fin);
		if (c == '\n') {
			fseek(fin, -2, SEEK_CUR); //����һ���ַ�
			if ((c = fgetc(fin)) == '\r')//�ж��Ƿ�Ϊwindows��ʽ�ļ�
				*iswin = 1;//��\r\n��β
			else
				*islinux = 1; //ֻ��\n��β
			fseek(fin, pos, SEEK_SET); //���˵�ԭ����λ��

		}


	}
}
int main(int argc, char* argv[]) {
	if (argc == 3 || argc == 5) {}
	else
		return usage(argv[0]);
	if (strcmp(argv[1], "--check") == 0) {
		FILE* fin = fopen(argv[2], "rb");//�Զ����Ʒ�ʽ���ļ�����ֹ����\r\n��β
		if (!fin) {
			printf("�ļ���ʧ��: %s\n", argv[2]);
			return 1;
		}
		int iswin = 0;//�ж��Ƿ�Ϊwindows��ʽ�ļ�,��\r\n��β
		int islinux = 0;//�ж��Ƿ�Ϊlinux��ʽ�ļ���ֻ��\n��β
		check(fin, &iswin, &islinux);
		if (iswin && !islinux)
			printf("Windows��ʽ\n");
		else if (islinux && !iswin)
			printf("Linux��ʽ\n");
		else
			printf("�ļ���ʽδ֪\n");
		fclose(fin);
		return 0;

	}
	else if (strcmp(argv[1], "--convert") == 0) {
		if (argc != 5)
			return usage(argv[0]);
		if (strcmp(argv[2], "wtol") == 0) {
			int count = 0;
			FILE* fin = fopen(argv[3], "rb");
			if (!fin) {
				printf("�����ļ� %s ��ʧ��\n", argv[3]);
				return 1;
			}
			int iswin = 0;
			int islinux = 0;
			check(fin, &iswin, &islinux); // �ж������ļ��Ƿ�Ϊ Windows ��ʽ�ļ�
			if (!(iswin && !islinux)) {
				printf("�ļ���ʽ�޷�ʶ��\n");
				fclose(fin);
				return 1;
			}
			FILE* fout = fopen(argv[4], "wb");
			if (!fout) {
				printf("����ļ� %s ��ʧ��\n", argv[4]);
				return 1;
			}
			signed char c;
			clearerr(fin); // ����ļ�״̬
			fseek(fin, 0, SEEK_SET); // �ص��ļ���ͷ
			while ((c = fgetc(fin)) != EOF) {
				signed char c2;
				printf("%d\n", c);
				if (c == '\r' && (c2 =fgetc(fin)) == '\n') {
					ungetc(c2, fin); // �˻�һ���ַ�
					count++;
					continue;
				}
				fputc(c, fout);
			}
			printf("ת����ɣ�ȥ�� %d �� 0x0D\n", count);
			fclose(fout);
			fclose(fin);
			return 0;
		}
		else if (strcmp(argv[2], "ltow") == 0) {
			int count = 0;
			FILE* fin = fopen(argv[3], "rb");
			if (!fin) {
				printf("�ļ���ʧ��: %s\n", argv[3]);
				return 1;
			}
			int iswin = 0;
			int islinux = 0;
			check(fin, &iswin, &islinux); // �ж������ļ��Ƿ�Ϊ Linux ��ʽ�ļ�
			if (!(islinux && !iswin)) {
				printf("�ļ���ʽ�޷�ʶ��\n");
				fclose(fin);
				return 1;
			}
			FILE* fout = fopen(argv[4], "wb");
			if (!fout) {
				printf("����ļ� %s ��ʧ��\n", argv[4]);
				return 1;
			}
			signed char c;
			clearerr(fin); // ����ļ�״̬
			fseek(fin, 0, SEEK_SET); // �ص��ļ���ͷ
			while ((c = fgetc(fin)) != EOF) {
				if (c == '\n') {
					count++;
					fputc('\r', fout);
				}
				fputc(c, fout);
			}
			printf("ת����ɣ����� %d �� 0x0D\n", count);
			fclose(fout);
			fclose(fin);
			return 0;
		}
		else
			return usage(argv[0]);
	}
	else
		return usage(argv[0]);



}