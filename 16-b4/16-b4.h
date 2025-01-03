/* 2351753 计科 黄保翔 */
#if defined _MSC_VER || __MINGW32__
#pragma once
#endif
#include <iostream>
using namespace std;

/* 如果有其它全局函数需要声明，写于此处 */
bool is_leap_year(int year);//判断是否为闰年
int daysOfMonth(int year, int month);
/* 如果有需要的宏定义、只读全局变量等，写于此处 */

/* 补全Date类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class Date {
private:
	int year;
	int month;
	int day;
	/* 不允许添加数据成员 */
public:
	/* 根据需要定义所需的成员函数、友元函数等(不允许添加数据成员) */
	Date();//默认构造函数
	Date(int y, int m, int d);//构造函数
	void set(int y, int m, int d);//设置日期
	void set(int y, int m);//设置年月
	void set(int y);//设置年
	void get(int& y, int& m, int& d) const ;//获取日期
	void show() const;//显示日期
	Date(const int& time); //转换构造函数
	Date& operator++(); //前置自增
	Date operator++(int); //后置自增
	Date& operator--(); //前置自减
	Date operator--(int); //后置自减
	operator int() const; //转换为整型
	friend Date operator+(const Date& d1, const int& t); //日期加法
	friend Date operator+(const int& t, const Date& d1);//日期加法, 先右值引用
	friend Date operator-(const Date& d1, const int& t); //日期减法
	friend int operator-(const Date& d1, const Date& d2); //日期减法
	friend ostream& operator<<(ostream& os, const Date& d); //日期输出
	friend istream& operator>>(istream& is, Date& d); //日期输入
	friend bool operator==(const Date& d1, const Date& d2); //日期相等
	friend bool operator!=(const Date& d1, const Date& d2); //日期不等
	friend bool operator<(const Date& d1, const Date& d2); //日期小于
	friend bool operator<=(const Date& d1, const Date& d2); //日期小于等于
	friend bool operator>(const Date& d1, const Date& d2); //日期大于
	friend bool operator>=(const Date& d1, const Date& d2); //日期大于等于
};

