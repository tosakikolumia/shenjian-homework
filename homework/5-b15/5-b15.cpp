/* 2351753 信08 黄保翔 */
#include <iostream>
using namespace std;

int main() 
{
	char str[3][128] = { 0 };
	cout << "请输入第1行" << endl;
	fgets(str[0], 128, stdin);
	cout << "请输入第2行" << endl;
	fgets(str[1], 128, stdin);
	cout << "请输入第3行" << endl;
	fgets(str[2], 128, stdin);
	int count1=0, count2=0, count3=0, count4=0, count5=0;
	for (int i=0; i < 3; i++) {
		for (int j = 0; str[i][j]; j++) {
			if (str[i][j] >= 'A' && str[i][j] <= 'Z') {
				count1++;
			}
			else if (str[i][j] >= 'a' && str[i][j] <= 'z') {
				count2++;
			}
			else if (str[i][j] >= '0' && str[i][j] <= '9') {
				count3++;
			}
			else if (str[i][j] == ' ') {
				count4++;
			}
			else {
				count5++;
			}
		}
	}
	cout << "大写 : " << count1 << endl;
	cout << "小写 : " << count2 << endl;
	cout << "数字 : " << count3 << endl;
	cout << "空格 : " << count4 << endl;
	cout << "其它 : " << count5 << endl;
	return 0;
}