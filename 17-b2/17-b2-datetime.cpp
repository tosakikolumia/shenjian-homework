/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <iomanip>
#include "17-b2-datetime.h"
using namespace std;

/* --- ����DateTime��ĳ�Ա����������ʵ��(����Ԫ��������Ҫ�Ĺ�������)  --- */ 
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
    // 1. ��������������
    long long total_seconds = time;
    long long days = total_seconds / (24 * 3600);  // ����������
    days %= 73049;//ѭ�����㣬ֱ���õ���ȷ������
    long long remaining_seconds = total_seconds % (24 * 3600); // ����ʣ������
    // ���ʣ�������Ǹ���������Ϊ��������ǰ��һ��
    if (remaining_seconds < 0) {
        remaining_seconds += 24 * 3600;  // ����һ�������
        days -= 1;  // ��ȥһ�������
    }
    static_cast<Date&>(*this) = int(days);  // ʹ��������������
    static_cast<Time&>(*this) = int(remaining_seconds);  // ʹ����������ʱ��
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
        seconds += 24 * 3600;  // ����һ�������
        days -= 1;              // ���ڲ�ֵ��1��
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