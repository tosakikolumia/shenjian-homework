/* 2351753 信08 黄保翔 */
#include <iostream>
#include <cstring>
using namespace std;

int  huiwen(char *p1) {
    char* p2 = p1 + strlen(p1) - 2;//处理回车
    while (p1 < p2) {
        if (*p1 == *p2);
        else {
            cout << "no" << endl;
            return -1;
        }
        p1++;
        p2--;
    }
    cout << "yes" << endl;
    return 0;
}
int main() 
{
	char str[81] = { 0 };
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 81, stdin);
    huiwen(str);
    return 0;
}