/* 2351753 信08 黄保翔 */
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
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> num;
	cout << trans(num) << endl;
}