/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip>

using namespace std; 
int main()
{
	int a;
	cout << "������һ��[1..30000]�������:" << endl;
	cin >> a;
	cout << "��λ : " << a / 10000 << endl;
	cout << "ǧλ : " << a % 10000 / 1000 << endl;
	cout << "��λ : " << a % 10000 % 1000 / 100 << endl;
	cout << "ʮλ : " << a % 10000 % 1000 % 100 / 10 << endl;
	cout << "��λ : " << a % 10000 % 1000 % 100 % 10 << endl;

	return 0;
}
	