/* 2351753 信08 黄保翔 */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout：输出设备句柄
			int X      ：指定位置的x坐标
			int Y      ：指定位置的y坐标
			char ch    ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	printf("***********************************************************************\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("*                                                                     *\n");
	printf("***********************************************************************\n");

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);
	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int menu() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	cls(hout);
	printf("1.用I、J、K、L键控制上下左右(大小写均可，边界停止)\n");
	printf("2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)\n");
	printf("3.用箭头键控制上下左右，边界停止\n");
	printf("4.用箭头键控制上下左右，边界回绕\n");
	printf("5.用I、J、K、L键控制上下左右(边界停止,按左键头键不准向下移动)\n");
	printf("6.用I、J、K、L键控制上下左右(边界回绕,按左键头键不准向下移动)\n");
	printf("0.退出\n");
	printf("[请选择0 - 6]\n");
	int number;
	number = _getche();
	return (number - 48);
}
void move_by_ijkl(int a) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	if (a == 1) {
		while (1) {
			int word = _getch();
			if ((word == 73 || word == 105) && y >= 2) {
				y = y - 1;
			}
			if ((word == 74 || word == 106) && x >= 2) {
				x = x - 1;
			}
			if ((word == 75 || word == 107) && y <= 16) {
				y = y + 1;
			}
			if ((word == 76 || word == 108) && x <= 68) {
				x = x + 1;
			}
			gotoxy(hout, x, y);
			if (word == 32) {
				printf(" ");
			}
			if (word == 113 || word == 81) {
				break;
			}
		}

	}
	if (a == 2) {
		while (1) {
			int word = _getch();
			if (word == 73 || word == 105) {
				if (y >= 2) {
					y = y - 1;
				}
				if (y == 1) {
					y = 17;
				}
			}
			if (word == 74 || word == 106) {
				if (x >= 2) {
					x = x - 1;
				}
				if (x == 1) {
					x = 69;
				}
			}
			if (word == 75 || word == 107) {
				if (y <= 16) {
					y = y + 1;
				}
				if (y == 17) {
					y = 1;
				}
			}
			if (word == 76 || word == 108) {
				if (x <= 68) {
					x = x + 1;
				}
				if (x == 69) {
					x = 1;
				}
			}
			gotoxy(hout, x, y);
			if (word == 32) {
				printf(" ");
			}
			if (word == 113 || word == 81) {
				break;
			}
		}

	}
	if (a == 6) {
		while (1) {
			int word = _getch();
			if (word != 224) {
				if (word == 73 || word == 105) {
					if (y >= 2) {
						y = y - 1;
					}
					if (y == 1) {
						y = 17;
					}
				}
				if (word == 74 || word == 106) {
					if (x >= 2) {
						x = x - 1;
					}
					if (x == 1) {
						x = 69;
					}
				}
				if (word == 75 || word == 107) {
					if (y <= 16) {
						y = y + 1;
					}
					if (y == 17) {
						y = 1;
					}
				}
				if (word == 76 || word == 108) {
					if (x <= 68) {
						x = x + 1;
					}
					if (x == 69) {
						x = 1;
					}
				}
			}
			else {
				word = _getch();
			}

			gotoxy(hout, x, y);
			if (word == 32) {
				printf(" ");
			}
			if (word == 113 || word == 81) {
				break;
			}
		}
	}
	if (a == 5) {
		while (1) {
			int word = _getch();
			if (word != 224) {
				if ((word == 73 || word == 105) && y >= 2) {
					y = y - 1;
				}
				if ((word == 74 || word == 106) && x >= 2) {
					x = x - 1;
				}
				if ((word == 75 || word == 107) && y <= 16) {
					y = y + 1;
				}
				if ((word == 76 || word == 108) && x <= 68) {
					x = x + 1;
				}
				gotoxy(hout, x, y);
				if (word == 32) {
					printf(" ");
				}
				if (word == 113 || word == 81) {
					break;
				}
			}
			else {
				word = _getch();
			}

		}
	}
}
void move_by_arrow(int b) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int x = 35, y = 9;
	gotoxy(hout, x, y);
	if (b == 3) {
		while (1) {
			int word = _getch();
			if (word == 224) {
				word = _getch();
				if ((word == 72) && y >= 2) {
					y = y - 1;
				}
				if ((word == 75) && x >= 2) {
					x = x - 1;
				}
				if ((word == 80) && y <= 16) {
					y = y + 1;
				}
				if ((word == 77) && x <= 68) {
					x = x + 1;
				}
				gotoxy(hout, x, y);

			}
			if (word == 32) {
				printf(" ");
			}
			if (word == 113 || word == 81) {
				break;
			}

		}
	}
	if (b == 4) {
		while (1) {
			int word = _getch();
			if (word == 224) {
				if (word == 72) {
					if (y >= 2) {
						y = y - 1;
					}
					if (y == 1) {
						y = 17;
					}
				}
				if (word == 75) {
					if (x >= 2) {
						x = x - 1;
					}
					if (x == 1) {
						x = 69;
					}
				}
				if (word == 80) {
					if (y <= 16) {
						y = y + 1;
					}
					if (y == 17) {
						y = 1;
					}
				}
				if (word == 77) {
					if (x <= 68) {
						x = x + 1;
					}
					if (x == 69) {
						x = 1;
					}
				}
				gotoxy(hout, x, y);


			}
			if (word == 32) {
				printf(" ");
			}
			if (word == 113 || word == 81) {
				break;
			}
		}
	}
}
int main()
{
	int choice;
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄

	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	while (1) {
		choice = menu();
		if (choice >= 0 && choice <= 6) {
			if (choice == 0) {
				break;
			}
			else {
				/* 此句的作用是调用系统的cls命令清屏 */
				cls(hout);
				/* 显示初始的边框及其中的随机字符 */
				init_border(hout);
				if (choice == 1 || choice == 2 || choice == 5 || choice == 6) {
					move_by_ijkl(choice);
				}
				if (choice == 3 || choice == 4) {
					move_by_arrow(choice);
				}

				gotoxy(hout, 0, 23);
				printf("游戏结束，按回车键退出.");

				//暂停(此处作业要求是只能按回车退出，目前的getchar示例，是允许按任意键+回车退出，且任意键会出现在屏幕上)
				while (1) {
					char ch;
					ch = _getch();
					if (ch == 13) {
						break;
					}


				}

				// 在这里可以添加其他逻辑来处理非回车键字符  
				// 如果不添加任何逻辑，程序将只是继续等待用户输入  

			}
		}
	}



	return 0;
}
//左箭头ASCII码为224 75若只取一次字符则和K一致
//当随机数两次取值相同时，后一次打印的字符会将前一次打印的字符覆盖，少于20个