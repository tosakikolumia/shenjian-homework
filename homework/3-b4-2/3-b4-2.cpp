/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	cout << "�����������ε����߼���нǣ��Ƕȣ�" << endl;
	int a, b, c;
	float s;
	cin >> a >> b >> c;
	const double pi = 3.14159;
	s = a * b * sin(c * pi / 180) / 2;
	cout << "���������Ϊ" << " : ";
	cout << setiosflags(ios::fixed) << setprecision(3) << s << endl;

	return 0;
}