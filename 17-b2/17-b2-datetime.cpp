/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
#include "17-b2-datetime.h"
using namespace std;

/* --- 给出DateTime类的成员函数的体外实现(含友元及其它必要的公共函数)  --- */ 
DateTime::DateTime(int year, int month, int day, int hour, int minute, int second) {
    if (is_valid_date(year, month, day) && is_valid_time(hour, minute, second)) {
        set(year, month, day, hour, minute, second);
    }
    else {
        set();
    }
}

DateTime::DateTime() {}
void DateTime::set(int year, int month, int day, int hour, int minute, int second) {
    if (is_valid_date(year, month, day) && is_valid_time(hour, minute, second)) {
        Date::set(year, month, day);
        Time::set(hour, minute, second);
    }
    else {
        set();
    }
}
void DateTime::set(int year, int month, int day, int hour, int minute) {
    Date::set(year, month, day);
    Time::set(hour, minute);
}
void DateTime::set(int year, int month, int day, int hour) {
    Date::set(year, month, day);
    Time::set(hour);
}
void DateTime::set(int year, int month, int day) {
    Date::set(year, month, day);
}
void DateTime::set(int year, int month) {
    Date::set(year, month);
}
void DateTime::set(int year) {
    Date::set(year);
}
void DateTime::set() {
    set(1900, 1, 1, 0, 0, 0);
}
void DateTime::show() const {
    cout << static_cast<Date>(*this) << " ";
    Time::show();
}
void DateTime::get(int& year, int& month, int& day, int& hour, int& minute, int& second) const {
    Date::get(year, month, day);
    Time::get(hour, minute, second);
}
DateTime::DateTime(const long long& time){
    // 1. 计算天数和秒数
    long long total_seconds = time;
    long long days = total_seconds / (24 * 3600);  // 计算总天数
    days %= 73049;//循环计算，直到得到正确的日期
    long long remaining_seconds = total_seconds % (24 * 3600); // 计算剩余秒数
    // 如果剩余秒数是负数，调整为正数并向前借一天
    if (remaining_seconds < 0) {
        remaining_seconds += 24 * 3600;  // 增加一天的秒数
        days -= 1;  // 减去一天的天数
    }
    static_cast<Date&>(*this) = int(days);  // 使用天数构造日期
    static_cast<Time&>(*this) = int(remaining_seconds);  // 使用秒数构造时间
}

DateTime::operator long long() const {
    return static_cast<long long>(Date(year, month,day)) * 24 * 3600 + static_cast<long long>(Time(hour, minute, second));
}
ostream& operator<<(ostream& os, const DateTime& dt) {
    Date d(dt.year, dt.month, dt.day);
    Time t(dt.hour, dt.minute, dt.second);
    os <<d <<' '<<t;
    return os;
}
istream& operator>>(istream& is, DateTime& dt) {
    int year, month, day, hour, minute, second;
    is >> year >> month >> day >> hour >> minute >> second;
    if (year >= 1900 && year <= 2099 && month >= 1 && month <= 12 && day >= 1 && day <= daysOfMonth(year, month) && hour >= 0 && hour <= 23 && minute >= 0 && minute <= 59 && second >= 0 && second <= 59) {
       dt.set(year, month, day, hour, minute, second);
    }
    else{
        dt.set();
    }
    return is;
}
bool operator == (const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1) == Date(dt2) && Time(dt1) == Time(dt2);
}
bool operator!=(const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1)!= Date(dt2) || Time(dt1)!= Time(dt2);
}
bool operator < (const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1) < Date(dt2) || (Date(dt1) == Date(dt2) && Time(dt1) < Time(dt2));
}
bool operator <= (const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1) < Date(dt2) || (Date(dt1) == Date(dt2) && Time(dt1) <= Time(dt2));
}
bool operator > (const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1) > Date(dt2) || (Date(dt1) == Date(dt2) && Time(dt1) > Time(dt2));
}
bool operator >= (const DateTime& dt1, const DateTime& dt2) {
    return Date(dt1) > Date(dt2) || (Date(dt1) == Date(dt2) && Time(dt1) >= Time(dt2));
}

DateTime operator+(const DateTime& dt, const long long& seconds) {
    //
   long long time = static_cast<long long>(dt);
   time += seconds;
   DateTime res(time);
   return res;
}
DateTime operator+(const long long& seconds,const DateTime& dt) {
    return dt + seconds;
}
DateTime operator+(const DateTime& dt, const int& seconds) {
    return dt + (long long)seconds;
}
DateTime operator+(const int& seconds, const DateTime& dt) {
    return dt + (long long)seconds;
}

DateTime operator-(const DateTime& dt, const long long& seconds) {
    long long time = static_cast<long long>(dt);
    time -= seconds;
    DateTime res(time);
    return res;
}
DateTime operator-(const DateTime& dt, const int& seconds) {
    return dt - (long long)seconds;
}
long long operator-(const DateTime& dt1, const DateTime& dt2) {
    long long days = static_cast<long long>(Date(dt1) - Date(dt2));
    long long seconds = static_cast<long long>(Time(dt1) - Time(dt2));
    if (seconds < 0) {
        seconds += 24 * 3600;  // 增加一天的秒数
        days -= 1;              // 日期差值减1天
    }
    return days * 24 * 3600 + seconds;
}

DateTime& DateTime::operator++() {
    static_cast<Time&>(*this)++;
    if (static_cast<Time&>(*this) == Time(0, 0, 0)) {
        static_cast<Date&>(*this)++;
    }
    return *this;
}
DateTime DateTime::operator++(int) {
    DateTime res(*this);
    ++(*this);
    return res;
}
DateTime& DateTime::operator--() {
    static_cast<Time&>(*this)--;
    if (static_cast<Time&>(*this) == Time(23, 59, 59)) {
        static_cast<Date&>(*this)--;
    }
    return *this;
}
DateTime DateTime::operator--(int) {
    DateTime res(*this);
    --(*this);
    return res;
}
DateTime operator+(const DateTime& dt, const long int& seconds) {
    //
    return dt + (long long)seconds;
}
DateTime operator+(const long int& seconds, const DateTime& dt) {
    //
    return dt + (long long)seconds;
}
DateTime operator-(const DateTime& dt, const long int& seconds) {
    //
    return dt - (long long)seconds;
}