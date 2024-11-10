/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/
void f(int word)
{
	if (word == 65) {
		cout << 'A';
		return;
	}
	cout << char(word);
	f(word - 1);
	cout << char(word);

}
void print_tower(int n, int order)
{
	static int num = n;/* 允许按需定义最多一个静态局部变量（也可以不定义） */
	if(order==1){	

		if (n == 65) {

			cout << setw(num - n) << " ";
			cout << 'A' << endl;
			return;
		}
		if ((num - n) > 0) {
			cout << setw(num - n) << " ";
		}
		f(n);/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
		cout << endl;

		print_tower(n - 1, order);
	}
	
	if (order == 0) {
		if (n == 65) {
			cout << setw(num-n) << " ";
			f(65);
			cout << endl;
			return;
		}
		print_tower(n - 1, order);	
		if ((num - n) > 0) {
			cout << setw(num - n) << " ";
		}
		f(n);/* 按需实现，函数中不允许任何形式的循环，函数允许调用其它函数 */
		cout << endl;
	}

}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}

	/* 正三角字母塔(中间为A) */
	cout  << setw((end_ch - 65) * 2+1 )<<setfill('=')<<"=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 65) * 2+1) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,0); //正序打印 A~结束字符 
	cout << endl;

	/* 倒三角字母塔(中间为A) */
	cout << setw((end_ch - 65) * 2+1) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 65) * 2+1) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 1); //逆序打印 A~结束字符 
	cout << endl;

	/* 合起来就是漂亮的菱形（中间为A） */
	cout << setw((end_ch - 65) * 2+1) << setfill('=') << "=" << setfill(' ') << endl;  /* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << setw((end_ch - 65) * 2+1) << setfill('=') << "=" << setfill(' ') << endl; /* 按字母塔最大宽度输出= */
	print_tower(end_ch, 0);   //打印 A~结束字符的正三角 
	print_tower(end_ch-1, 1);   //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}