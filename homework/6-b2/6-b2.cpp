/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <cstring>
using namespace std;

int  huiwen(char *p1) {
    char* p2 = p1 + strlen(p1) - 2;//����س�
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
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
	fgets(str, 81, stdin);
    huiwen(str);
    return 0;
}