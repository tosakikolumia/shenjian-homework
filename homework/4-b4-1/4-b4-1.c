/* 2351753 ��08 �Ʊ��� */
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout������豸���
			int X      ��ָ��λ�õ�x����
			int Y      ��ָ��λ�õ�y����
			char ch    ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);
	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int menu() {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	cls(hout);
	printf("1.��I��J��K��L��������������(��Сд���ɣ��߽�ֹͣ)\n");
	printf("2.��I��J��K��L��������������(��Сд���ɣ��߽����)\n");
	printf("3.�ü�ͷ�������������ң��߽�ֹͣ\n");
	printf("4.�ü�ͷ�������������ң��߽����\n");
	printf("5.��I��J��K��L��������������(�߽�ֹͣ,�����ͷ����׼�����ƶ�)\n");
	printf("6.��I��J��K��L��������������(�߽����,�����ͷ����׼�����ƶ�)\n");
	printf("0.�˳�\n");
	printf("[��ѡ��0 - 6]\n");
	int number;
	number = _getche();
	return (number - 48);
}
void move_by_ijkl(int a) {
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
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
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��

	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
	srand((unsigned int)(time(0)));
	while (1) {
		choice = menu();
		if (choice >= 0 && choice <= 6) {
			if (choice == 0) {
				break;
			}
			else {
				/* �˾�������ǵ���ϵͳ��cls�������� */
				cls(hout);
				/* ��ʾ��ʼ�ı߿����е�����ַ� */
				init_border(hout);
				if (choice == 1 || choice == 2 || choice == 5 || choice == 6) {
					move_by_ijkl(choice);
				}
				if (choice == 3 || choice == 4) {
					move_by_arrow(choice);
				}

				gotoxy(hout, 0, 23);
				printf("��Ϸ���������س����˳�.");

				//��ͣ(�˴���ҵҪ����ֻ�ܰ��س��˳���Ŀǰ��getcharʾ���������������+�س��˳�������������������Ļ��)
				while (1) {
					char ch;
					ch = _getch();
					if (ch == 13) {
						break;
					}


				}

				// �����������������߼�������ǻس����ַ�  
				// ���������κ��߼�������ֻ�Ǽ����ȴ��û�����  

			}
		}
	}



	return 0;
}
//���ͷASCII��Ϊ224 75��ֻȡһ���ַ����Kһ��
//�����������ȡֵ��ͬʱ����һ�δ�ӡ���ַ��Ὣǰһ�δ�ӡ���ַ����ǣ�����20��