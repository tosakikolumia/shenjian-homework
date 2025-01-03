/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include <iostream>
using namespace std;

/* 如果有其它全局函数需要声明，写于此处 */
bool is_valid_time(int h, int m = 0, int s = 0); // 判断时间是否有效
/* Time类的声明 */ 
class Time {
protected:
	/* 除这三个以外，不允许再定义任何数据成员 */ 
	int hour;
	int minute;
	int second;
public:
	/* 允许需要的成员函数及友元函数的声明 */
		/* 允许需要的成员函数及友元函数的声明 */
	Time(); // 默认构造函数
	Time(int h, int m, int s); // 构造函数
	void set(int h, int m, int s); // 设置时间
	void set(int h, int m); // 设置时和分
	void set(int h); // 设置小时
	void get(int& h, int& m, int& s) const; // 获取时间
	void show() const; // 显示时间
	Time(const int& time); // 转换构造函数
	Time& operator++(); // 前置自增
	Time operator++(int); // 后置自增
	Time& operator--(); // 前置自减
	Time operator--(int); // 后置自减
	operator int() const; // 转换为整型
	friend Time operator+(const Time& t1, const int& seconds); // 时间加法
	friend Time operator+(const int& seconds, const Time& t1); // 时间加法, 先右值引用
	friend Time operator-(const Time& t1, const int& seconds); // 时间减法
	friend int operator-(const Time& t1, const Time& t2); // 时间的比较
	friend ostream& operator<<(ostream& os, const Time& t); // 时间输出
	friend istream& operator>>(istream& is, Time& t); // 时间输入
	friend bool operator==(const Time& t1, const Time& t2); // 时间相等
	friend bool operator!=(const Time& t1, const Time& t2); // 时间不等
	friend bool operator<(const Time& t1, const Time& t2); // 时间小于
	friend bool operator<=(const Time& t1, const Time& t2); // 时间小于等于
	friend bool operator>(const Time& t1, const Time& t2); // 时间大于
	friend bool operator>=(const Time& t1, const Time& t2); // 时间大于等于

	/* 允许加入友元声明（如果有必要） */
};