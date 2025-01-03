/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include <iostream>
using namespace std;
/* 如果有其它全局函数需要声明，写于此处 */
bool is_leap_year(int year);//判断是否为闰年
int daysOfMonth(int year, int month);
bool is_valid_date(int year, int month = 1, int day = 1);//判断日期是否合法
/* 如果有需要的宏定义、只读全局变量等，写于此处 */

/* Date类的声明 */ 
class Date {
protected:
	/* 除这三个以外，不允许再定义任何数据成员 */ 
	int year;
	int month;
	int day;
public:
	/* 允许需要的成员函数及友元函数的声明 */
	Date();//默认构造函数
	Date(int y, int m, int d);//构造函数
	void set(int y, int m, int d);//设置日期
	void set(int y, int m);//设置年月
	void set(int y);//设置年
	void get(int& y, int& m, int& d) const;//获取日期
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
	/* 允许加入友元声明（如果有必要） */
};
