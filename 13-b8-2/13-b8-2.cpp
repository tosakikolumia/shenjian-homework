/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
/* --���ĳ����������Ҫ���˴�������������ĸ�ʽ����ͷ�ļ� --*/
#if defined (__MINGW32__)|| defined (__MINGW64__) //DevC++
     #include <cstdio>
#elif defined __linux__       //Linux
    #include <cstdio>
#endif
using namespace std;

int main()
{
	char a[80];

#if defined (__MINGW32__)|| defined (__MINGW64__)  //DevC++
	gets(a);
#elif defined _MSC_VER       //VS2022
	gets_s(a);
#elif defined __linux__       //Linux
	fgets(a, 80, stdin); //����Ҫ�������Ļس�
#endif

	cout << a << endl;
	return 0;
}/*__cplusplus*/