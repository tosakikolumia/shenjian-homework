/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;

int trans(char *p) 
{
	int a = *p-'0';
	for (p++; *p; p++) {
		a = a * 2 + *p - '0';
	}
	return a;
}
int main() 
{
	char num[32] = {0};
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> num;
	cout << trans(num) << endl;
}