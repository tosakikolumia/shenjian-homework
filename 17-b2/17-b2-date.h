/* 2351753 �ƿ� �Ʊ��� */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include <iostream>
using namespace std;
/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
bool is_leap_year(int year);//�ж��Ƿ�Ϊ����
int daysOfMonth(int year, int month);
bool is_valid_date(int year, int month = 1, int day = 1);//�ж������Ƿ�Ϸ�
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */

/* Date������� */ 
class Date {
protected:
	/* �����������⣬�������ٶ����κ����ݳ�Ա */ 
	int year;
	int month;
	int day;
public:
	/* ������Ҫ�ĳ�Ա��������Ԫ���������� */
	Date();//Ĭ�Ϲ��캯��
	Date(int y, int m, int d);//���캯��
	void set(int y, int m, int d);//��������
	void set(int y, int m);//��������
	void set(int y);//������
	void get(int& y, int& m, int& d) const;//��ȡ����
	void show() const;//��ʾ����
	Date(const int& time); //ת�����캯��
	Date& operator++(); //ǰ������
	Date operator++(int); //��������
	Date& operator--(); //ǰ���Լ�
	Date operator--(int); //�����Լ�
	operator int() const; //ת��Ϊ����
	friend Date operator+(const Date& d1, const int& t); //���ڼӷ�
	friend Date operator+(const int& t, const Date& d1);//���ڼӷ�, ����ֵ����
	friend Date operator-(const Date& d1, const int& t); //���ڼ���
	friend int operator-(const Date& d1, const Date& d2); //���ڼ���
	friend ostream& operator<<(ostream& os, const Date& d); //�������
	friend istream& operator>>(istream& is, Date& d); //��������
	friend bool operator==(const Date& d1, const Date& d2); //�������
	friend bool operator!=(const Date& d1, const Date& d2); //���ڲ���
	friend bool operator<(const Date& d1, const Date& d2); //����С��
	friend bool operator<=(const Date& d1, const Date& d2); //����С�ڵ���
	friend bool operator>(const Date& d1, const Date& d2); //���ڴ���
	friend bool operator>=(const Date& d1, const Date& d2); //���ڴ��ڵ���
	/* ���������Ԫ����������б�Ҫ�� */
};
