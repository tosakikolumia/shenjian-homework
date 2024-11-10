/* 2351753 信08 黄保翔 */
#include <iostream>
using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;
	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
	gets_s (str);
	p = str;
	pa = a;
	while (*p!=0) {
		is_num = 0;
		if (*p >= '0' && *p <= '9') {
			*pa = *p-'0';
			for (p+=1; *p >= '0' && *p <= '9'; p++) {
				*pa = *pa * 10 + *p-'0';
			}
			pa++;
			is_num = 1;
		}
		if (is_num == 0) {
			p++;
		}
	}
	pnum = a;
	cout << "共有" << pa-a << "个整数" << endl;
	for (pnum; pnum<pa; pnum++) {
		cout << *pnum << " ";
	}
	cout << endl;
	return 0;
}