/* 2351753 信08 黄保翔 */
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
	cout << "请输入三角形的两边及其夹角（角度）" << endl;
	int a, b, c;
	float s;
	cin >> a >> b >> c;
	const double pi = 3.14159;
	s = a * b * sin(c * pi / 180) / 2;
	cout << "三角形面积为" << " : ";
	cout << setiosflags(ios::fixed) << setprecision(3) << s << endl;

	return 0;
}