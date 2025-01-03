/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
#include "17-b2-time.h"
using namespace std;
bool is_valid_time(int h, int m, int s) {
    return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}
/* --- 给出Time类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 
Time::Time() {
    this->hour = 0;
    this->minute = 0;
    this->second = 0;
}
Time::Time(int h, int m, int s) {
    if (is_valid_time(h, m, s)) {
        this->hour = h;
        this->minute = m;
        this->second = s;
    } else {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
}
void Time::set(int h, int m, int s) {
    if (is_valid_time(h, m, s)) {
        this->hour = h;
        this->minute = m;
        this->second = s;
    }
    else {
        this->hour = 0; 
        this->minute = 0;
        this->second = 0;
    }
}
void Time::set(int h,int m ) {
    if (is_valid_time(h, m, 0)) {
        this->hour = h;
        this->minute = m;
    }
    else {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
}
void Time::set(int h) {
    if (is_valid_time(h, 0, 0)) {
        this->hour = h;
    }
    else {
        this->hour = 0;
        this->minute = 0;
        this->second = 0;
    }
}
void Time::get(int& h, int& m, int& s) const {
    h = this->hour;
    m = this->minute;
    s = this->second;
}
void Time::show() const {
    cout << setfill('0') << setw(2) << this->hour << ":" << setw(2) << this->minute << ":" << setw(2) << this->second << endl;
}
/* 转换构造函数 */
Time::Time(const int& timeInSeconds) {
    int  total_seconds = timeInSeconds % (24 * 3600);
    if (total_seconds < 0) {
        total_seconds += 24 * 3600;
    }
    this->hour = total_seconds / 3600;
    total_seconds %= 3600;
    this->minute = total_seconds / 60;
    this->second = total_seconds % 60;
}
/* 类型转换函数 */
Time::operator int() const {
    return this->hour * 3600 + this->minute * 60 + this->second;
}

Time& Time::operator++() { // 前置自增
    if (this->second < 59) {
        this->second++;
    }
    else {
        this->second = 0;
        if (this->minute < 59) {
            this->minute++;
        }
        else {
            this->minute = 0;
            this->hour = (this->hour + 1) % 24; // 循环到0。
        }
    }
    return *this;
}
Time Time::operator++(int) { // 后置自增
    Time t = *this;
    ++(*this);
    return t;
}
Time& Time::operator--() { // 前置自减
    if (this->second > 0) {
        this->second--;
    }
    else {
        this->second = 59;
        if (this->minute > 0) {
            this->minute--;
        }
        else {
            this->minute = 59;
            this->hour = (this->hour + 23) % 24; // 循环到23。
        }
    }
    return *this;
}
Time Time::operator--(int) { // 后置自减
    Time t = *this;
    --(*this);
    return t;
}

Time operator+(const Time& t, const int& seconds) { // + 运算符重载
    Time t2;
    int total_seconds = (int(t) + seconds) % (24 * 3600);
    t2 = Time(total_seconds); // 转换构造函数
    return t2;
}

Time operator+(const int& seconds, const Time& t) { // + 运算符重载
    return t + seconds; // 复用上面的实现
}

 Time operator-(const Time& t, const int& seconds) { // - 运算符重载
    Time t2;
    int total_seconds = (int(t) - seconds + (24 * 3600)) % (24 * 3600);
    t2 = Time(total_seconds); // 转换构造函数
    return t2;
}

 int operator-(const Time& t1, const Time& t2) { // - 运算符重载
     return int(t1) - int(t2); // 隐式调用转换为秒
 }

 ostream& operator<<(ostream& os, const Time& t) { // 输出运算符重载
     os << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second;
     return os;
 }

 istream& operator>>(istream& is, Time& t) { // 输入运算符重载
     int h, m, s;
     is >> h >> m >> s;
     t.set(h, m, s);
     return is;
 }

bool operator<(const Time& t1, const Time& t2) { // < 运算符重载
    return int(t1) < int(t2); // 隐式调用转换为秒
 }

 bool operator<=(const Time& t1, const Time& t2) { // <= 运算符重载
    return int(t1) <= int(t2); // 隐式调用转换为秒
 }

 bool operator>(const Time& t1, const Time& t2) { // > 运算符重载
    return int(t1) > int(t2); // 隐式调用转换为秒
 }

 bool operator>=(const Time& t1, const Time& t2) { // >= 运算符重载
    return int(t1) >= int(t2); // 隐式调用转换为秒
 }

 bool operator==(const Time& t1, const Time& t2) { // == 运算符重载
    return int(t1) == int(t2); // 隐式调用转换为秒
 }

 bool operator!=(const Time& t1, const Time& t2) { // != 运算符重载
    return int(t1) != int(t2); // 隐式调用转换为秒
 }  