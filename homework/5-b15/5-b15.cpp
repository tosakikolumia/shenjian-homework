/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;

int main() 
{
	char str[3][128] = { 0 };
	cout << "�������1��" << endl;
	fgets(str[0], 128, stdin);
	cout << "�������2��" << endl;
	fgets(str[1], 128, stdin);
	cout << "�������3��" << endl;
	fgets(str[2], 128, stdin);
	int count1=0, count2=0, count3=0, count4=0, count5=0;
	for (int i=0; i < 3; i++) {
		for (int j = 0; str[i][j]; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
				count1++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				count2++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9') {
				count3++;
			}
			else if (str[i][j] == ' ') {
				count4++;
			}
			else {
				count5++;
			}
		}
	}
	cout << "��д : " << count1 << endl;
	cout << "Сд : " << count2 << endl;
	cout << "���� : " << count3 << endl;
	cout << "�ո� : " << count4 << endl;
	cout << "���� : " << count5 << endl;
	return 0;
}