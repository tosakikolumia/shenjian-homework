/* 2351753 计科 黄保翔 */
#include <iostream>
/* --如果某编译器有需要，此处允许按条件编译的格式加入头文件 --*/
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
	fgets(a, 80, stdin); //不需要处理最后的回车
#endif

	cout << a << endl;
	return 0;
}/*__cplusplus*/