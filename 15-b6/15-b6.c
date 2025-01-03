/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage(const char* const procname)
{
	printf("Usage : %s --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名\n", procname);
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
			fseek(fin, -2, SEEK_CUR); //回退一个字符
			if ((c = fgetc(fin)) == '\r')//判断是否为windows格式文件
				*iswin = 1;//有\r\n结尾
			else
				*islinux = 1; //只有\n结尾
			fseek(fin, pos, SEEK_SET); //回退到原来的位置

		}


	}
}
int main(int argc, char* argv[]) {
	if (argc == 3 || argc == 5) {}
	else
		return usage(argv[0]);
	if (strcmp(argv[1], "--check") == 0) {
		FILE* fin = fopen(argv[2], "rb");//以二进制方式打开文件，防止出现\r\n结尾
		if (!fin) {
			printf("文件打开失败: %s\n", argv[2]);
			return 1;
		}
		int iswin = 0;//判断是否为windows格式文件,有\r\n结尾
		int islinux = 0;//判断是否为linux格式文件，只有\n结尾
		check(fin, &iswin, &islinux);
		if (iswin && !islinux)
			printf("Windows格式\n");
		else if (islinux && !iswin)
			printf("Linux格式\n");
		else
			printf("文件格式未知\n");
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
				printf("输入文件 %s 打开失败\n", argv[3]);
				return 1;
			}
			int iswin = 0;
			int islinux = 0;
			check(fin, &iswin, &islinux); // 判断输入文件是否为 Windows 格式文件
			if (!(iswin && !islinux)) {
				printf("文件格式无法识别\n");
				fclose(fin);
				return 1;
			}
			FILE* fout = fopen(argv[4], "wb");
			if (!fout) {
				printf("输出文件 %s 打开失败\n", argv[4]);
				return 1;
			}
			signed char c;
			clearerr(fin); // 清除文件状态
			fseek(fin, 0, SEEK_SET); // 回到文件开头
			while ((c = fgetc(fin)) != EOF) {
				signed char c2;
				printf("%d\n", c);
				if (c == '\r' && (c2 =fgetc(fin)) == '\n') {
					ungetc(c2, fin); // 退回一个字符
					count++;
					continue;
				}
				fputc(c, fout);
			}
			printf("转换完成，去除 %d 个 0x0D\n", count);
			fclose(fout);
			fclose(fin);
			return 0;
		}
		else if (strcmp(argv[2], "ltow") == 0) {
			int count = 0;
			FILE* fin = fopen(argv[3], "rb");
			if (!fin) {
				printf("文件打开失败: %s\n", argv[3]);
				return 1;
			}
			int iswin = 0;
			int islinux = 0;
			check(fin, &iswin, &islinux); // 判断输入文件是否为 Linux 格式文件
			if (!(islinux && !iswin)) {
				printf("文件格式无法识别\n");
				fclose(fin);
				return 1;
			}
			FILE* fout = fopen(argv[4], "wb");
			if (!fout) {
				printf("输出文件 %s 打开失败\n", argv[4]);
				return 1;
			}
			signed char c;
			clearerr(fin); // 清除文件状态
			fseek(fin, 0, SEEK_SET); // 回到文件开头
			while ((c = fgetc(fin)) != EOF) {
				if (c == '\n') {
					count++;
					fputc('\r', fout);
				}
				fputc(c, fout);
			}
			printf("转换完成，加入 %d 个 0x0D\n", count);
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