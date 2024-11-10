/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <cstring>
#include <conio.h>
#include"7-b2.h" 
#include "cmd_console_tools.h"
# define caidanshu 20
using namespace std;
/* 1���������ͷ�ļ�
   2����������ȫ�ֱ�����������̬ȫ�֣���������const��define
   3����������Ҫ�Ľṹ�塢�����ȣ������ޱ�Դ�����ļ�ʹ�� */

/* ������������Դ�����ļ���Ҫ�Ľṹ�壬��Ҫ�ŵ�.h��
       ��Ϊʾ��������Ҫ��ɾ�� */
struct temp {
	const char* title;	//����
	int start_x;	//���Ͻ�x����
	int start_y;	//���Ͻ�y����
	int width;		//�˵���ȣ��������ұ߿�+4����ʾ��ʵ����������������ż��
	int high;		//�˵��߶ȣ��������±߿�+2����ʾ��ʵ����������
	int bg_color;	//���ñ���ɫ��ע��ѡ����background/foregroundΪ���ԣ�
	int fg_color;	//����ǰ��ɫ
};

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������Դ�����ļ���Ҫ�ĺ���������Ϊstatic����
***************************************************************************/
//static int fun(xxx)
//{
//    
//}
static bool chinese(char c) {//���ϲ�ģ��ж��Ƿ���
	return (unsigned char)c >= 0xA1 && (unsigned char)c <= 0xFE;
}

// ����ض��ַ�������������������
static void trans(const char* str, char* result, int width_max) {
	int width = 0;
	int i = 0;

	while (str[i] && width < width_max) {
		if (chinese(str[i])) {
			if (width + 2 > width_max) {
				break;
			}
			result[width++] = str[i++];
			result[width++] = str[i++];
		}
		else {
			result[width++] = str[i++];
		}
	}

	// ����ո�
	while (width < width_max - 1) {
		result[width++] = ' ';
	}

	result[width] = '\0';  // ȷ���ַ����� null ��β
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ��������������õĺ���������������ͷ�ļ���
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols,lines, buffer_cols, buffer_lines);


	//
	cct_setcolor();
	int i = 0;
	for (; menu[i][0] != 0; i++);//�˵�ѡ����
	struct temp Temp;
	Temp.title = original_para->title;
	int length = strlen(Temp.title);
	if (length % 2 != 0) {
		length += 1;
	}
	Temp.start_x= original_para->start_x;
	Temp.start_y = original_para->start_y;
	Temp.width = original_para->width;
	if (Temp.width % 2 != 0) {
		Temp.width += 1;
	}
	if (Temp.width < length) {
		Temp.width = length;
	}
	if ((original_para->high) > i) {
		Temp.high = i;
	}
	else
		Temp.high = original_para->high;

	Temp.bg_color = original_para->bg_color;
	Temp.fg_color = original_para->fg_color;
	//��һ��
	cct_showstr(Temp.start_x, Temp.start_y, "�X", Temp.bg_color, Temp.fg_color, 1);
	cct_showstr(Temp.start_x+2, Temp.start_y, "�T", Temp.bg_color, Temp.fg_color, Temp.width/2);
	cct_showstr(Temp.start_x + Temp.width/2-length/2/2-2, Temp.start_y, Temp.title, Temp.bg_color, Temp.fg_color, 1);
	if (Temp.width + Temp.start_x > buffer_cols) {
		cct_showstr(Temp.start_x + Temp.width - buffer_cols +2, Temp.start_y + 1, "�[", Temp.bg_color, Temp.fg_color, 1);
	}
	else {
		cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y, "�[", Temp.bg_color, Temp.fg_color, 1);
	}
	//
	int j = 1;
	char temp_menu[caidanshu][MAX_ITEM_LEN] = { 0 };
	for (int c = 0; c < i; c++) {
		trans(menu[c], temp_menu[c], Temp.width);
	}
	for (; j <= Temp.high; j++) {
		cct_showstr(Temp.start_x, Temp.start_y+j, "�U", Temp.bg_color, Temp.fg_color, 1);
		//
		cct_showstr(Temp.start_x + 2, Temp.start_y + j, " ", Temp.bg_color, Temp.fg_color, Temp.width);
		cct_showstr(Temp.start_x+2, Temp.start_y + j, temp_menu[j-1], Temp.bg_color, Temp.fg_color, 1);
		//
		if (Temp.width + Temp.start_x > buffer_cols) {
			cct_showstr(Temp.start_x + Temp.width - buffer_cols +2, Temp.start_y + j+1, "�U", Temp.bg_color, Temp.fg_color, 1);
		}
		else {
			cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y + j, "�U", Temp.bg_color, Temp.fg_color, 1);
		}
		
	}
	//���һ��
	cct_showstr(Temp.start_x, Temp.start_y + Temp.high + 1, "�^", Temp.bg_color, Temp.fg_color, 1);
	cct_showstr(Temp.start_x + 2, Temp.start_y + Temp.high + 1, "�T", Temp.bg_color, Temp.fg_color, Temp.width / 2);
	if (Temp.width + Temp.start_x > buffer_cols) {
		cct_showstr(Temp.start_x + Temp.width - buffer_cols+2, Temp.start_y + Temp.high + 1+1, "�a", Temp.bg_color, Temp.fg_color, 1);
	}
	else {
		cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y + Temp.high + 1, "�a", Temp.bg_color, Temp.fg_color, 1);
	}
	int kx = Temp.start_x, ky = Temp.start_y+1;
	int sentence = 0;
	cct_showstr(Temp.start_x + 2, ky, " ", Temp.fg_color, Temp.bg_color, Temp.width);
	cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.fg_color, Temp.bg_color,1);
	while (1) {
		int word = _getch();
		if (word == 224) {
			int word2 = _getch();
			if ((word2 == KB_ARROW_UP) && sentence>0) {
				if (ky > Temp.start_y +1) {
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.bg_color, Temp.fg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.bg_color, Temp.fg_color, 1);
					ky--;
					sentence--;
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.fg_color, Temp.bg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.fg_color, Temp.bg_color, 1);
				}
				else {
					sentence--;
					for (int k = 0; k < Temp.high; k++) {
						//
						cct_showstr(Temp.start_x + 2, Temp.start_y + k+1, " ", Temp.bg_color, Temp.fg_color, Temp.width);
						cct_showstr(Temp.start_x + 2, Temp.start_y + k+1, temp_menu[sentence + k], Temp.bg_color, Temp.fg_color, 1);
						//
					}
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.fg_color, Temp.bg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.fg_color, Temp.bg_color, 1);
				}
				
			}
			if ((word2 == KB_ARROW_DOWN) && sentence < 9) {
				
				if (ky < Temp.start_y + Temp.high) {
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.bg_color, Temp.fg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.bg_color, Temp.fg_color, 1);
					ky++;
					sentence++;
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.fg_color, Temp.bg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.fg_color, Temp.bg_color, 1);
				}
				else {
					sentence++;
					for (int k = 0; k < Temp.high; k++) {
						//
						cct_showstr(Temp.start_x + 2, Temp.start_y + Temp.high-k, " ", Temp.bg_color, Temp.fg_color, Temp.width);
						cct_showstr(Temp.start_x + 2, Temp.start_y + Temp.high - k, temp_menu[sentence - k], Temp.bg_color, Temp.fg_color, 1);
						//
					}
					cct_showstr(Temp.start_x + 2, ky, " ", Temp.fg_color, Temp.bg_color, Temp.width);
					cct_showstr(Temp.start_x + 2, ky, temp_menu[sentence], Temp.fg_color, Temp.bg_color, 1);
				}
				
			}
		}
		else {
			if (word == '\r') {
				break;
			}
		}

	}
	cct_setcolor();
	
	return (sentence + 1) % 10; //���践��
}
