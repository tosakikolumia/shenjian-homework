/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include "16-b4.h"
using namespace std;

/* ���� Date ������г�Ա����������ʵ�� */

/*���캯��*/
Date::Date() {
    this->year = 2000;
    this->month = 1;
    this->day = 1;
}
Date::Date(int year, int month, int day) {
    this->year = (year > 2099 || year < 1900) ? 2000 : year;
    this->month = (month > 12 || month < 1) ? 1 : month;
    this->day = (day > daysOfMonth(this->year, this->month) || day < 1) ? 1 : day;
}
//set����
void Date::set(int year, int month, int day) {
    if(year!=0)//���year������0�������year
        this->year = (year > 2099 || year < 1900) ? 2000 : year;
    if(month!=0)//���month������0�������month
        this->month = (month > 12 || month < 1) ? 1 : month;
    if(day!=0)//���day������0�������day
        this->day = (day > daysOfMonth(this->year, this->month) || day < 1) ? 1 : day;
    else//���򣬱���ԭ��ֵ,��ҲҪ��֤�Ϸ�
        this->day = (this->day > daysOfMonth(this->year, this->month) || this->day < 1) ? 1 : this->day;
}
void Date::set(int year, int month) {
    if(year!=0)//���year������0�������year
        this->year = (year > 2099 || year < 1900) ? 2000 : year;
   
    if(month!=0)//���month������0�������month
        this->month = (month > 12 || month < 1) ? 1 : month;
    
}
void Date::set(int year) {
    if(year!=0)
        this->year = (year > 2099 || year < 1900) ? 2000 : year;
}
//get����
void Date::get(int& year, int& month, int& day) const {
    year = this->year;
    month = this->month;
    day = this->day;
}
//show����
void Date::show() const{
    cout << year << "��" << month << "��" << day << "��" << endl;
}
//ת�����캯��
Date::Date(const int& time) {
    int days_from_1900 = time;//��1900��1��1�յ���ǰ���ڵ�����
    int year = 1900;
    int month = 1;
    int day = 1;
    int days_of_year = 0;
    days_of_year = (is_leap_year(year) ? 366 : 365);
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
    if (day <= 0) {//�������С��1������Ϊ�ϸ���
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
//����ת������
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
    return days_from_1900;
}
Date& Date::operator++() {//ǰ��++���������
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
    if (this->year > 2099) {//�����ݴ���2099������Ϊ2099��12��31��
        this->year = 2099;
        this->month = 12;
        this->day = 31;
    }
    return *this;
}
Date Date::operator++(int) {//����++���������
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
    if (this->year > 2099) {
        this->year = 2099;
        this->month = 12;
        this->day = 31;
    }
    return d;
}
Date& Date::operator--() {//ǰ��--���������
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
    if (this->year < 1900) {
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
    return *this;
}
Date Date::operator--(int) {//����--���������
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
    if (this->year < 1900) {//������С��1900������Ϊ1900��1��1��
        this->year = 1900;
        this->month = 1;
        this->day = 1;
    }
    return d;
}
/* �������Ҫ������ȫ�ֺ�����ʵ�֣�����д�ڴ˴� */
/*�����жϺ���*/
bool is_leap_year(int year) {
    if (year % 4 == 0 && year % 100 != 0) //�ܱ�4���������ܱ�100����
        return true;
    else if (year % 400 == 0) //�ܱ�400����
        return true;
    else
        return false;
}
/*��ȡĳ��ĳ�µ�����*/
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

//��Ԫ����
Date operator+(const Date& d, const int& t) {//+���������
    Date d2;
    int days_from_1900 = int(d) + t;//��ʽ����תΪint��
    d2 = Date(days_from_1900);//�ٴ���ʽ���ù��캯��
    if (d2.year > 2099) {//�����ݴ���2099������Ϊ2099��12��31��
        d2.year = 2099;
        d2.month = 12;
        d2.day = 31;
    }
    return d2;
}
Date operator+(const int& t, const Date& d) {//+���������
    Date d2;
    int days_from_1900 = d + t;//��ʽ����תΪint��
    d2 = Date(days_from_1900);//�ٴ���ʽ���ù��캯��
    if (d2.year > 2099) {//�����ݴ���2099������Ϊ2099��12��31��
        d2.year = 2099;
        d2.month = 12;
        d2.day = 31;
    }
    return d2;
}
int operator-(const Date& d1, const Date& d2) {//-���������
    int days_from_1900 = int (d1) - int (d2);//��ʽ����תΪint��
    return days_from_1900;
}
Date operator-(const Date& d, const int& t) {//-���������
    Date d2;
    int days_from_1900 = int(d) - t;//��ʽ����תΪint��
    d2 = Date(days_from_1900);//�ٴ���ʽ���ù��캯��
    if (d2.year < 1900) {//������С��1900������Ϊ1900��1��1��
        d2.year = 1900;
        d2.month = 1;
        d2.day = 1;
    }
    return d2;
}
ostream& operator<<(ostream& os, const Date& d) {//������������
    os << d.year << "��" << d.month << "��" << d.day << "��";
    return os;
}
istream& operator>>(istream& is, Date& d) {//�������������
    int year, month, day;
    is >> year >> month >> day;
    d.set(year, month, day);
    return is;
}
bool operator<(const Date& d1, const Date& d2) {//<���������
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
bool operator==(const Date& d1, const Date& d2) {//==���������
    if (d1.year == d2.year && d1.month == d2.month && d1.day == d2.day)
        return true;
    else
        return false;
}
bool operator!=(const Date& d1, const Date& d2) {//!=���������
    if (d1.year != d2.year || d1.month != d2.month || d1.day != d2.day)
        return true;
    else
        return false;
}
bool operator>(const Date& d1, const Date& d2) {//>���������
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
bool operator<=(const Date& d1, const Date& d2) {//<=���������
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
bool operator>=(const Date& d1, const Date& d2) {//>=���������
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
