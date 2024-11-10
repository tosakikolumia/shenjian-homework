/* 2351753 信08 黄保翔 */
#include <iostream>
#include <cstring>
#include <conio.h>
#include"7-b2.h" 
#include "cmd_console_tools.h"
# define caidanshu 20
using namespace std;
/* 1、按需加入头文件
   2、不允许定义全局变量，包括静态全局，但不限制const及define
   3、允许定义需要的结构体、函数等，但仅限本源程序文件使用 */

/* 例：声明仅本源程序文件需要的结构体，不要放到.h中
       仅为示例，不需要可删除 */
struct temp {
	const char* title;	//标题
	int start_x;	//左上角x坐标
	int start_y;	//左上角y坐标
	int width;		//菜单宽度，不含左右边框（+4是显示的实际列数），必须是偶数
	int high;		//菜单高度，不含上下边框（+2是显示的实际行数），
	int bg_color;	//所用背景色（注：选中项background/foreground为反显）
	int fg_color;	//所用前景色
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：定义仅本源程序文件需要的函数，设置为static即可
***************************************************************************/
//static int fun(xxx)
//{
//    
//}
static bool chinese(char c) {//网上查的，判断是否汉字
	return (unsigned char)c >= 0xA1 && (unsigned char)c <= 0xFE;
}

// 处理截断字符串，避免半个汉字问题
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

	// 补充空格
	while (width < width_max - 1) {
		result[width++] = ' ';
	}

	result[width] = '\0';  // 确保字符串以 null 结尾
}
/***************************************************************************
  函数名称：
  功    能：供测试用例调用的函数，函数声明在头文件中
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int pop_menu(const char menu[][MAX_ITEM_LEN], const struct PopMenu* original_para)
{
	int cols, lines, buffer_cols, buffer_lines;
	cct_getconsoleborder(cols,lines, buffer_cols, buffer_lines);


	//
	cct_setcolor();
	int i = 0;
	for (; menu[i][0] != 0; i++);//菜单选项数
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
	//第一行
	cct_showstr(Temp.start_x, Temp.start_y, "╔", Temp.bg_color, Temp.fg_color, 1);
	cct_showstr(Temp.start_x+2, Temp.start_y, "═", Temp.bg_color, Temp.fg_color, Temp.width/2);
	cct_showstr(Temp.start_x + Temp.width/2-length/2/2-2, Temp.start_y, Temp.title, Temp.bg_color, Temp.fg_color, 1);
	if (Temp.width + Temp.start_x > buffer_cols) {
		cct_showstr(Temp.start_x + Temp.width - buffer_cols +2, Temp.start_y + 1, "╗", Temp.bg_color, Temp.fg_color, 1);
	}
	else {
		cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y, "╗", Temp.bg_color, Temp.fg_color, 1);
	}
	//
	int j = 1;
	char temp_menu[caidanshu][MAX_ITEM_LEN] = { 0 };
	for (int c = 0; c < i; c++) {
		trans(menu[c], temp_menu[c], Temp.width);
	}
	for (; j <= Temp.high; j++) {
		cct_showstr(Temp.start_x, Temp.start_y+j, "║", Temp.bg_color, Temp.fg_color, 1);
		//
		cct_showstr(Temp.start_x + 2, Temp.start_y + j, " ", Temp.bg_color, Temp.fg_color, Temp.width);
		cct_showstr(Temp.start_x+2, Temp.start_y + j, temp_menu[j-1], Temp.bg_color, Temp.fg_color, 1);
		//
		if (Temp.width + Temp.start_x > buffer_cols) {
			cct_showstr(Temp.start_x + Temp.width - buffer_cols +2, Temp.start_y + j+1, "║", Temp.bg_color, Temp.fg_color, 1);
		}
		else {
			cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y + j, "║", Temp.bg_color, Temp.fg_color, 1);
		}
		
	}
	//最后一行
	cct_showstr(Temp.start_x, Temp.start_y + Temp.high + 1, "╚", Temp.bg_color, Temp.fg_color, 1);
	cct_showstr(Temp.start_x + 2, Temp.start_y + Temp.high + 1, "═", Temp.bg_color, Temp.fg_color, Temp.width / 2);
	if (Temp.width + Temp.start_x > buffer_cols) {
		cct_showstr(Temp.start_x + Temp.width - buffer_cols+2, Temp.start_y + Temp.high + 1+1, "╝", Temp.bg_color, Temp.fg_color, 1);
	}
	else {
		cct_showstr(Temp.start_x + Temp.width + 2, Temp.start_y + Temp.high + 1, "╝", Temp.bg_color, Temp.fg_color, 1);
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
	
	return (sentence + 1) % 10; //按需返回
}
