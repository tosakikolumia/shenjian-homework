/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <string>
#define N 10
using namespace std;
void input(string name [10], string number[10], int score[10]) {
	for (int i = 0; i < 10; i++) {
		cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
		cin >> number[i];
		cin >> name[i];
		cin >> score[i];
	}
}
void rak(string name[10], string number[10], int score[10]) 
{
	int t;
	string temp1;
	string temp2;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (score[j] < score[j + 1]) { 
			     t = score[j];
				temp1 = name[j];
				temp2 = number[j];
				score[j] = score[j + 1];
				name[j] = name[j + 1];
				number[j] = number[j + 1];
				score[j + 1] = t;
				number[j + 1] = temp2;
				name[j + 1] = temp1;
			}
		}
	}
}
void output(string name[10], string number[10], int score[10]) {
	cout << "����������(�ɼ�����):" << endl;
	for (int i = 9; i >= 0; i--) {
		if (score[i] < 60) {
			cout << name[i] << " " << number[i] << " " << score[i] << endl;
		}
	}

}
int main() {
	string name[10];
	string number[10];
	int score[10] = { 0 };
	input(name, number, score);
	rak(name, number, score);
	output(name, number, score);
	return 0;
}