/* 2351753 ��08 �Ʊ��� */
#include <iostream>  
#include <cmath>  
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	 int k;
	double d;
	k = static_cast<int>(a / 10);//��С��û�н�������������
	cout << "ʮ��λ : " << static_cast<int>(a / 1000000000) << endl;
	cout << "��λ   : " << k % 100000000 / 10000000 << endl;
	cout << "ǧ��λ : " << k % 100000000 % 10000000 / 1000000 << endl;
	cout << "����λ : " << k % 100000000 % 10000000 % 1000000 / 100000 << endl;
	cout << "ʮ��λ : " << k % 100000000 % 10000000 % 1000000 % 100000 / 10000 << endl;
	cout << "��λ   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000 << endl;
	cout << "ǧλ   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100 << endl;
	cout << "��λ   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10 << endl;
	cout << "ʮλ   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1 << endl;
	d = a / 10 - k;
	cout << "Բ     : " << static_cast<int>(static_cast<int>(round(d * 1000)) / 100) << endl;//ϵͳ��������ֱ��ʹ�ã���������δ���ܹ��ģ���������в���
	cout << "��     : " << static_cast<int>(static_cast<int>(round(d * 1000)) % 100 / 10) << endl;
	cout << "��     : " << static_cast<int>(static_cast<int>(round(d * 1000)) % 100 % 10 / 1) << endl;
	
	return 0;
}


   