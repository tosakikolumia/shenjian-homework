/* 2351753 计科 黄保翔 */
#include <iostream>
#include <cmath>
using namespace std;

/* 从此处到标记替换行之间，给出各种类的定义及实现
	1、不允许定义全局变量（不含const和#define）
	2、不允许添加其它系统头文件
*/ 
//矩形计算求积分
class integral
{
protected:
	double low, high;
	int number;
	const char* name;
public:
	integral();
    virtual double value() const = 0; //虚函数，子类必须实现
	friend istream& operator>>(istream& is, integral& s);
};
class integral_sin : public integral
{
public:
	integral_sin();
	double value() const;
	
};
class integral_cos : public integral
{
public:
	integral_cos();
	double value() const;
	
};
class integral_exp : public integral
{
public:
	integral_exp();
	double value() const;

};
integral::integral(){
	low = 0;
	high = 0;
	number = 0;
	name = "";
}
integral_sin::integral_sin() : integral() {
	name = "sinxdx";
}
double integral_sin::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//每小格宽度
	for (i = 1; i <= number; i++) {
		sum += ((sin(low + i * weight)) * weight);
	}
	cout << "sinxdx["<<low<<"~"<<high<<"/n="<<number<<"] : "<<sum<<endl;

	return sum;
}
integral_cos::integral_cos() : integral() {
	name = "cosxdx";
	
}
double integral_cos::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//每小格宽度
	for (i = 1; i <= number; i++) {
		sum += ((cos(low + i * weight)) * weight);
	}
	cout << "cosxdx[" << low << "~" << high << "/n=" << number << "] : "<<sum<<endl;
	return sum;
}
integral_exp::integral_exp() : integral() {
	name = "e^xdx";
	
}
double integral_exp::value() const
{
	int  i;
	double sum = 0;
	double weight = fabs(low - high) / number;//每小格宽度
	for (i = 1; i <= number; i++) {
		sum += ((exp(low + i * weight)) * weight);
	}
	cout << "e^xdx[" << low << "~" << high << "/n=" << number << "] : "<<sum<<endl;
	return sum;
}
istream& operator>>(istream& is, integral& s) {
	while(1)
	{
		cout<<"请输入"<<s.name<<"的下限、上限及区间划分数量"<<endl;
		is >> s.low >> s.high >> s.number;
		if (is.fail() || s.number <= 0 || s.low > s.high) {
			cout << "输入有误，请重新输入！" << endl;
			is.clear();
			is.ignore(65536, '\n');
		}
		else {
			break;
		}
	}
	return is;
}




/* -- 替换标记行 -- 本行不要做任何改动 -- 本行不要删除 -- 在本行的下面不要加入任何自己的语句，作业提交后从本行开始会被替换 -- 替换标记行 -- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：fun_integral不准动，思考一下，integral应如何定义
***************************************************************************/
void fun_integral(integral& fRef)
{
	cin >> fRef;	//输入上下限、划分数
	cout << fRef.value() << endl;
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	integral_sin s1;
	integral_cos s2;
	integral_exp s3;

	fun_integral(s1); //计算sinxdx的值
	fun_integral(s2); //计算cosxdx的值
	fun_integral(s3); //计算expxdx的值

	return 0;
}

//注：矩形计算取右值，输出为正常double格式

