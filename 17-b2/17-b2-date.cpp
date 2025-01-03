/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
#include "17-b2-date.h"
using namespace std;

/* --- 给出Date类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool is_valid_date(int year, int month, int day) {
    if (year < 1900 || year > 2099)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > daysOfMonth(year, month))
        return false;
    return true;
}
/*构造函数*/
Date::Date() {
    this->year = 1900;
    this->month = 1;
    this->day = 1;
}
Date::Date(int year, int month, int day) {//有一个错就设为1900年1月1日
    if (is_valid_date(year, month, day)) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else {
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
}
//set函数
void Date::set(int year, int month, int day) {
    if (is_valid_date(year, month, day)) {
        this->year = year;
        this->month = month;
        this->day = day;
    }
    else {
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
}
void Date::set(int year, int month) {
    if (is_valid_date(year, month)) {
        this->year = year;
        this->month = month;
    }
    else {//只要有错误，就置为1900年1月1日
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }

}
void Date::set(int year) {
    if (is_valid_date(year)) {
        this->year = year;
    }
    else {
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
}
//get函数
void Date::get(int& year, int& month, int& day) const {
    year = this->year;
    month = this->month;
    day = this->day;
}
//show函数
void Date::show() const {
    cout << setfill('0') << setw(4) << year << "-"<< setw(2) << month << "-"<< setw(2) << day << endl;
}
//转换构造函数
Date::Date(const int& time) {
    int days_from_1900 = time;//从1900年1月1日到当前日期的天数
    int year = 1900;
    int month = 1;
    int day = 1;
    int days_of_year = 0;
    days_of_year = (is_leap_year(year) ? 366 : 365);
    while (days_from_1900 < -73049) {
        days_from_1900 += 73049; // 循环处理，直到天数在合理范围内
    }
    days_from_1900 = (days_from_1900 % 73049 + 73049) % 73049;
    while (days_from_1900 >= days_of_year) {
        days_of_year = (is_leap_year(year) ? 366 : 365);
        days_from_1900 -= days_of_year;
        year++;
    }
    while (days_from_1900 >= daysOfMonth(year, month)) {
        days_from_1900 -= daysOfMonth(year, month);
        month++;
    }
    day += days_from_1900;
    this->year = year;
    this->month = month;
    if (day <= 0) {//如果日期小于1，则置为上个月
        if (this->month > 1) {
            this->month--;
            this->day = daysOfMonth(this->year, this->month);
        }
        else {
            this->month = 12;
            this->year--;
            this->day = daysOfMonth(this->year, this->month);
        }
    }
    else {
        this->day = day;
    }
}
//类型转换函数
Date::operator int() const {
    int days_from_1900 = 0;
    int days_of_year = 0;
    int days_of_month = 0;
    for (int i = 1900; i < year; i++) {
        if (year == 1900)
            break;
        days_of_year = (is_leap_year(i) ? 366 : 365);
        days_from_1900 += days_of_year;
    }
    for (int i = 1; i < month; i++) {
        if (month == 1)
            break;
        days_of_month = daysOfMonth(year, i);
        days_from_1900 += days_of_month;
    }
    days_from_1900 += day;
    return days_from_1900-1;//从1900年1月1日到当前日期的天数，减1
}
Date& Date::operator++() {//前置++运算符重载
    if (this->day < daysOfMonth(this->year, this->month)) {
        this->day++;
    }
    else {
        this->day = 1;
        if (this->month < 12) {
            this->month++;
        }
        else {
            this->month = 1;
            this->year++;
        }
    }
    if (this->year > 2099) {//如果年份大于2099，则循环回1900年1月1日
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
    return *this;
}
Date Date::operator++(int) {//后置++运算符重载
    Date d = *this;
    if (this->day < daysOfMonth(this->year, this->month)) {
        this->day++;
    }
    else {
        this->day = 1;
        if (this->month < 12) {
            this->month++;
        }
        else {
            this->month = 1;
            this->year++;
        }
    }
    if (this->year > 2099) {//如果年份大于2099，则循环回到1900年1月1日
        this->year = 1900;
        this->month = 1;    
        this->day = 1;
    }
    return d;
}
Date& Date::operator--() {//前置--运算符重载
    if (this->day > 1) {
        this->day--;
    }
    else {
        if (this->month > 1) {
            this->month--;
            this->day = daysOfMonth(this->year, this->month);
        }
        else {
            this->month = 12;
            this->year--;
            this->day = daysOfMonth(this->year, this->month);
        }
    }
    if (this->year < 1900) {//如果年份小于1900，则循环回到2099年12月31日
        this->year = 2099;
        this->month = 12;
        this->day = 31;
    }
    return *this;
}
Date Date::operator--(int) {//后置--运算符重载
    Date d = *this;
    if (this->day > 1) {
        this->day--;
    }
    else {
        if (this->month > 1) {
            this->month--;
            this->day = daysOfMonth(this->year, this->month);
        }
        else {
            this->month = 12;
            this->year--;
            this->day = daysOfMonth(this->year, this->month);
        }
    }
    if (this->year < 1900) {//如果年份小于1900，则循环回到2099年12月31日
        this->year = 2099;
        this->month = 12;
        this->day = 31;
    }
    return d;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/*闰年判断函数*/
bool is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0) //能被4整除但不能被100整除
        return true;
    else if (year % 400 == 0) //能被400整除
        return true;
    else
        return false;
}
/*获取某年某月的天数*/
int daysOfMonth(int year, int month) {
    switch (month) {
        case 2:
            return is_leap_year(year) ? 29 : 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

//友元函数
Date operator+(const Date& d, const int& t) {//+运算符重载
    Date d2;
    int days_from_1900 = (int(d) + t) % 73049;//隐式调用转为int型
    d2 = Date(days_from_1900);//再次显式调用构造函数
    return d2;
}
Date operator+(const int& t, const Date& d) {//+运算符重载
    Date d2;
    int days_from_1900 = (d + t) % 73049;//隐式调用转为int型
    d2 = Date(days_from_1900);//再次显式调用构造函数
    return d2;
}
int operator-(const Date& d1, const Date& d2) {//-运算符重载
    int days_from_1900 = int(d1) - int(d2);//隐式调用转为int型
    return days_from_1900;
}
Date operator-(const Date& d, const int& t) {//-运算符重载
    Date d2;
    int days_from_1900 = (int(d) - t + 73049) % 73049;//隐式调用转为int型
    d2 = Date(days_from_1900);//再次显式调用构造函数
    return d2;
}
ostream& operator<<(ostream& os, const Date& d) {//输出运算符重载
    os << setfill('0') << setw(2) << d.year<< "-"<< setw(2) << d.month << "-" << setw(2) << d.day ;
    return os;
}
istream& operator>>(istream& is, Date& d) {//输入运算符重载
    int year, month, day;
    is >> year >> month >> day;
    d.set(year, month, day);
    return is;
}
bool operator<(const Date& d1, const Date& d2) {//<运算符重载
    if (d1.year < d2.year)
        return true;
    else if (d1.year > d2.year)
        return false;
    else {
        if (d1.month < d2.month)
            return true;
        else if (d1.month > d2.month)
            return false;
        else {
            if (d1.day < d2.day)
                return true;
            else
                return false;
        }
    }
}
bool operator==(const Date& d1, const Date& d2) {//==运算符重载
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
        return true;
    else
        return false;
}
bool operator!=(const Date& d1, const Date& d2) {//!=运算符重载
    if (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day)
        return true;
    else
        return false;
}
bool operator>(const Date& d1, const Date& d2) {//>运算符重载
    if (d1.year > d2.year)
        return true;
    else if (d1.year < d2.year)
        return false;
    else {
        if (d1.month > d2.month)
            return true;
        else if (d1.month < d2.month)
            return false;
        else {
            if (d1.day > d2.day)
                return true;
            else
                return false;
        }
    }
}
bool operator<=(const Date& d1, const Date& d2) {//<=运算符重载
    if (d1.year < d2.year)
        return true;
    else if (d1.year > d2.year)
        return false;
    else {
        if (d1.month < d2.month)
            return true;
        else if (d1.month > d2.month)
            return false;
        else {
            if (d1.day <= d2.day)
                return true;
            else
                return false;
        }
    }
}
bool operator>=(const Date& d1, const Date& d2) {//>=运算符重载
    if (d1.year > d2.year)
        return true;
    else if (d1.year < d2.year)
        return false;
    else {
        if (d1.month > d2.month)
            return true;
        else if (d1.month < d2.month)
            return false;
        else {
            if (d1.day >= d2.day)
                return true;
            else
                return false;
        }
    }
}
