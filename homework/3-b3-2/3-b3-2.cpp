/* 2351753 信08 黄保翔 */
#include <iostream>  
#include <cmath>  
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	 int k;
	double d;
	k = static_cast<int>(a / 10);//缩小，没有将该数整体扩大
	cout << "十亿位 : " << static_cast<int>(a / 1000000000) << endl;
	cout << "亿位   : " << k % 100000000 / 10000000 << endl;
	cout << "千万位 : " << k % 100000000 % 10000000 / 1000000 << endl;
	cout << "百万位 : " << k % 100000000 % 10000000 % 1000000 / 100000 << endl;
	cout << "十万位 : " << k % 100000000 % 10000000 % 1000000 % 100000 / 10000 << endl;
	cout << "万位   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000 << endl;
	cout << "千位   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100 << endl;
	cout << "百位   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10 << endl;
	cout << "十位   : " << k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1 << endl;
	d = a / 10 - k;
	cout << "圆     : " << static_cast<int>(static_cast<int>(round(d * 1000)) / 100) << endl;//系统函数可以直接使用，包括课上未介绍过的，具体可自行查阅
	cout << "角     : " << static_cast<int>(static_cast<int>(round(d * 1000)) % 100 / 10) << endl;
	cout << "分     : " << static_cast<int>(static_cast<int>(round(d * 1000)) % 100 % 10 / 1) << endl;
	
	return 0;
}


   