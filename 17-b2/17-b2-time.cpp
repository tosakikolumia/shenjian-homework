/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <iomanip>
#include "17-b2-time.h"
using namespace std;
bool is_valid_time(int h, int m, int s) {
    return (h >= 0 && h < 24 && m >= 0 && m < 60 && s >= 0 && s < 60);
}
/* --- ����Time��ĳ�Ա����������ʵ��(����Ԫ��������Ҫ�Ĺ�������)  --- */ 
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
/* ת�����캯�� */
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
/* ����ת������ */
Time::operator int() const {
    return this->hour * 3600 + this->minute * 60 + this->second;
}

Time& Time::operator++() { // ǰ������
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
            this->hour = (this->hour + 1) % 24; // ѭ����0��
        }
    }
    return *this;
}
Time Time::operator++(int) { // ��������
    Time t = *this;
    ++(*this);
    return t;
}
Time& Time::operator--() { // ǰ���Լ�
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
            this->hour = (this->hour + 23) % 24; // ѭ����23��
        }
    }
    return *this;
}
Time Time::operator--(int) { // �����Լ�
    Time t = *this;
    --(*this);
    return t;
}

Time operator+(const Time& t, const int& seconds) { // + ���������
    Time t2;
    int total_seconds = (int(t) + seconds) % (24 * 3600);
    t2 = Time(total_seconds); // ת�����캯��
    return t2;
}

Time operator+(const int& seconds, const Time& t) { // + ���������
    return t + seconds; // ���������ʵ��
}

 Time operator-(const Time& t, const int& seconds) { // - ���������
    Time t2;
    int total_seconds = (int(t) - seconds + (24 * 3600)) % (24 * 3600);
    t2 = Time(total_seconds); // ת�����캯��
    return t2;
}

 int operator-(const Time& t1, const Time& t2) { // - ���������
     return int(t1) - int(t2); // ��ʽ����ת��Ϊ��
 }

 ostream& operator<<(ostream& os, const Time& t) { // ������������
     os << setfill('0') << setw(2) << t.hour << ":" << setw(2) << t.minute << ":" << setw(2) << t.second;
     return os;
 }

 istream& operator>>(istream& is, Time& t) { // �������������
     int h, m, s;
     is >> h >> m >> s;
     t.set(h, m, s);
     return is;
 }

bool operator<(const Time& t1, const Time& t2) { // < ���������
    return int(t1) < int(t2); // ��ʽ����ת��Ϊ��
 }

 bool operator<=(const Time& t1, const Time& t2) { // <= ���������
    return int(t1) <= int(t2); // ��ʽ����ת��Ϊ��
 }

 bool operator>(const Time& t1, const Time& t2) { // > ���������
    return int(t1) > int(t2); // ��ʽ����ת��Ϊ��
 }

 bool operator>=(const Time& t1, const Time& t2) { // >= ���������
    return int(t1) >= int(t2); // ��ʽ����ת��Ϊ��
 }

 bool operator==(const Time& t1, const Time& t2) { // == ���������
    return int(t1) == int(t2); // ��ʽ����ת��Ϊ��
 }

 bool operator!=(const Time& t1, const Time& t2) { // != ���������
    return int(t1) != int(t2); // ��ʽ����ת��Ϊ��
 }  