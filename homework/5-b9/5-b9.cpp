/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;
bool row(int array[9][9])
{
	bool z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0, z9 = 0;
	bool leap = 1;
	for (int row = 0; row < 9; row++) {
		for (int column = 0; column < 9; column++) {
			switch (array[row][column]) {
				case 1:
					z1 = 1;
					break;
				case 2:
					z2 = 1;
					break;
				case 3:
					z3 = 1;
					break;
				case 4:
					z4 = 1;
					break;
				case 5:
					z5 = 1;
					break;
				case 6:
					z6 = 1;
					break;
				case 7:
					z7 = 1;
					break;
				case 8:
					z8 = 1;
					break;
				case 9:
					z9 = 1;
					break;
				default: break;
			}
			
		}
		if (z1 && z2 && z3 && z4 && z5 && z6 && z7 && z8 && z9) {

		}
		else {
			leap = 0;
		}
	}
	if (leap) {
		return true;
	}
	else {
		return false;
	}
}
bool column(int array[9][9])
{
	bool z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0, z9 = 0;
	bool leap = 1;
	for (int column = 0; column < 9; column++) {
		for (int row = 0; row < 9; row++) {
			switch (array[row][column]) {
				case 1:
					z1 = 1;
					break;
				case 2:
					z2 = 1;
					break;
				case 3:
					z3 = 1;
					break;
				case 4:
					z4 = 1;
					break;
				case 5:
					z5 = 1;
					break;
				case 6:
					z6 = 1;
					break;
				case 7:
					z7 = 1;
					break;
				case 8:
					z8 = 1;
					break;
				case 9:
					z9 = 1;
					break;
				default: break;
			}
			
		}
		if (z1 && z2 && z3 && z4 && z5 && z6 && z7 && z8 && z9) {

		}
		else {
			leap = 0;
		}
	}
	if (leap) {
		return true;
	}
	else {
		return false;
	}
}
bool _3_3(int array[9][9])
{
	bool z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0, z9 = 0;
	bool leap = 1;
	for (int column = 0; column <9; column=column+3) {
		for (int row = 0; row < 9; row = row + 3) {
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					
					switch (array[row+i][column+j]) {
						case 1:
							z1 = 1;
							break;
						case 2:
							z2 = 1;
							break;
						case 3:
							z3 = 1;
							break;
						case 4:
							z4 = 1;
							break;
						case 5:
							z5 = 1;
							break;
						case 6:
							z6 = 1;
							break;
						case 7:
							z7 = 1;
							break;
						case 8:
							z8 = 1;
							break;
						case 9:
							z9 = 1;
							break;
						default: break;
					}
				}
			}
			if (z1 && z2 && z3 && z4 && z5 && z6 && z7 && z8 && z9) {

			}
			else {
				leap = 0;
			}
		}		
	}
	if (leap) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	int shudu[9][9];
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			while (1) {
				cin >> shudu[i][j];
				if (cin.fail()) {
					cin.clear();
					cin.ignore(65536, '\n');
					cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
					continue;
				}
				else {
					if (shudu[i][j] < 1 || shudu[i][j]> 9) {
						cout << "�����������" << i + 1 << "��" << j + 1 << "��(���о���1��ʼ����)��ֵ" << endl;
						continue;
					}
				}
				break;
			}
			
			
		}
	}
	if (row(shudu) && column(shudu) && _3_3(shudu)) {
		cout << "�������Ľ�" << endl;
	}
	else {
		cout << "���������Ľ�" << endl;
	}
	
	
}