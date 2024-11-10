/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>

using namespace std; 
int main()
{
	int a;
	cout << "请输入一个[1..30000]间的整数:" << endl;
	cin >> a;
	cout << "万位 : " << a / 10000 << endl;
	cout << "千位 : " << a % 10000 / 1000 << endl;
	cout << "百位 : " << a % 10000 % 1000 / 100 << endl;
	cout << "十位 : " << a % 10000 % 1000 % 100 / 10 << endl;
	cout << "个位 : " << a % 10000 % 1000 % 100 % 10 << endl;

	return 0;
}
	