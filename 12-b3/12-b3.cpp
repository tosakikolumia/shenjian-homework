#include<iostream>
using namespace std;
int main() {
	//除已有6行外，填入语句行数不超过8行(不含注释)
	const char* month[12]{ "January","February","March","April", "May", "June", "July", "August", "September", "October", "November", "December" };
	cout << "请输入月份(1-12)" << endl;
	int num ;
	cin >> num;
	if (!cin || num > 12 || num < 1)
		cout << "Invalid" << endl;
	else
		cout << month[num - 1] << endl;
	return 0;
}
