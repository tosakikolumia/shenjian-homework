/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include "17-b2-date.h"
#include "17-b2-time.h"
#include <iostream>
/* 如果有其它全局函数需要声明，写于此处 */

/* DateTime类的基本要求：
	1、不允许定义任何数据成员
	2、尽量少定义成员函数 
*/

class DateTime:public Date, public Time {
protected:
	/* 不允许再定义任何数据成员 */ 

public:
	/* 不允许再定义任何数据成员，允许需要的成员函数及友元函数的声明 */
	DateTime();
	DateTime(int year, int month, int day, int hour, int minute, int second);
	//set函数的重载
	void set(int year, int month, int day, int hour, int minute, int second);
	void set(int year, int month, int day, int hour, int minute);
	void set(int year, int month, int day, int hour);
	void set(int year, int month, int day);
	void set(int year, int month);
	void set(int year);
	void set();
	void get(int& year, int& month, int& day, int& hour, int& minute, int& second) const; // 获取日期和时间
	void show() const; // 显示日期和时间
	DateTime(const long long& time); 
	operator long long() const;

	friend DateTime operator+(const DateTime& dt, const long long& seconds); // 日期时间加long long
	friend DateTime operator+(const DateTime& dt, const int& seconds); // 日期时间加int
	friend DateTime operator+(const long long& seconds,const DateTime& dt);/* long long加日期时间 */
	friend DateTime operator+(const int& seconds, const DateTime& dt2); // int加日期时间
	friend DateTime operator-(const DateTime& dt, const int& seconds); // 日期时间减int
	friend DateTime operator-(const DateTime& dt, const long long& t); // 日期时间减时间
	friend long long operator-(const DateTime& dt1, const DateTime& dt2); // 日期时间相差的天数
	friend DateTime operator+(const DateTime& dt, const long int& seconds); // 日期时间加long int
	friend DateTime operator+(const long int& seconds, const DateTime& dt2); // long int加日期时间
	friend DateTime operator-(const DateTime& dt, const long int& t); // 日期时间减long int
	friend ostream& operator<<(ostream& os, const DateTime& dt); // 输出运算符重载
	friend istream& operator>>(istream& is, DateTime& dt); // 输入运算符重载
	friend bool operator==(const DateTime& dt1, const DateTime& dt2); // 日期时间相等
	friend bool operator!=(const DateTime& dt1, const DateTime& dt2); // 日期时间不等
	friend bool operator< (const DateTime& dt1, const DateTime& dt2); // 日期时间小于
	friend bool operator<=(const DateTime& dt1, const DateTime& dt2); // 日期时间小于等于
	friend bool operator>(const DateTime& dt1, const DateTime& dt2); // 日期时间大于
	friend bool operator>=(const DateTime& dt1, const DateTime& dt2); // 日期时间大于等于

	/*++，--*/
	DateTime& operator++(); // ++前缀
	DateTime operator++(int); // ++后缀
	DateTime& operator--(); // --前缀
	DateTime operator--(int); // --后缀
	/* 允许加入友元声明（如果有必要） */

};
