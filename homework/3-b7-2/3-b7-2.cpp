/* 2351753 ��08 �Ʊ��� */
#include <iostream>  
#include <cmath>  
using namespace std;
int main()
{
	cout << "����������ֵ��" << endl;
	double a;
	int rmb50, rmb20, rmb10, rmb5, rmb1, rmb05, rmb01, rmb005, rmb002, rmb001;
	cin >> a;
	rmb50= static_cast<int>(a / 50);
	a = a - rmb50 * 50;
	rmb20 = static_cast<int>(a / 20);
	a = a - rmb20 * 20;
	rmb10 = static_cast<int>(a / 10);
	a = a - rmb10 * 10;
	rmb5 = static_cast<int> (a / 5);
	a = a - rmb5 * 5;
	rmb1 = static_cast<int>( a / 1);
	a = a - rmb1 * 1;
	rmb05 = static_cast<int>(a / 0.5);
	a = a - rmb05 * 0.5;
	rmb01 = static_cast<int>(a / 0.1);
	a = a - rmb01 * 0.1;
	rmb005 = static_cast<int>(a / 0.05);
	a = a - rmb005 * 0.05;
	rmb002 = static_cast<int>( a / 0.02);
	a = a - rmb002 * 0.02;
	rmb001 = static_cast<int>(a / 0.01);
	a = a - rmb001 * 0.01;
	cout << "��" << (rmb50 + rmb20 + rmb10 + rmb5 + rmb1 + rmb05 + rmb01 + rmb005 + rmb002 + rmb001)<<"�����㣬�������£�"<<endl;
	if (rmb50 != 0) {
		cout << "50Ԫ : " << rmb50 << "��" << endl;
	}
	if (rmb20 != 0) {
		cout << "20Ԫ : " << rmb20<< "��" << endl;
	}
	if (rmb10 != 0) {
		cout << "10Ԫ : " << rmb10 << "��" << endl;
	}
	if (rmb5 != 0) {
		cout << "5Ԫ  : " << rmb5 << "��" << endl;
	}
	if (rmb1 != 0) {
		cout << "1Ԫ  : " << rmb1 << "��" << endl;
	}
	if (rmb05 != 0) {
		cout << "5��  : " << rmb05 << "��" << endl;
	}
	if (rmb01 != 0) {
		cout << "1��  : " << rmb01 << "��" << endl;
	}
	if (rmb005 != 0) {
		cout << "5��  : " << rmb005 << "��" << endl;
	}
	if (rmb002 != 0) {
		cout << "2��  : " << rmb002 << "��" << endl;
	}
	if (rmb001 != 0) {
		cout << "1��  : " << rmb001 << "��" << endl;
	}
	return 0;
}