/* 2351753 �ƿ� �Ʊ��� */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include <iostream>
using namespace std;

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
bool is_valid_time(int h, int m = 0, int s = 0); // �ж�ʱ���Ƿ���Ч
/* Time������� */ 
class Time {
protected:
	/* �����������⣬�������ٶ����κ����ݳ�Ա */ 
	int hour;
	int minute;
	int second;
public:
	/* ������Ҫ�ĳ�Ա��������Ԫ���������� */
		/* ������Ҫ�ĳ�Ա��������Ԫ���������� */
	Time(); // Ĭ�Ϲ��캯��
	Time(int h, int m, int s); // ���캯��
	void set(int h, int m, int s); // ����ʱ��
	void set(int h, int m); // ����ʱ�ͷ�
	void set(int h); // ����Сʱ
	void get(int& h, int& m, int& s) const; // ��ȡʱ��
	void show() const; // ��ʾʱ��
	Time(const int& time); // ת�����캯��
	Time& operator++(); // ǰ������
	Time operator++(int); // ��������
	Time& operator--(); // ǰ���Լ�
	Time operator--(int); // �����Լ�
	operator int() const; // ת��Ϊ����
	friend Time operator+(const Time& t1, const int& seconds); // ʱ��ӷ�
	friend Time operator+(const int& seconds, const Time& t1); // ʱ��ӷ�, ����ֵ����
	friend Time operator-(const Time& t1, const int& seconds); // ʱ�����
	friend int operator-(const Time& t1, const Time& t2); // ʱ��ıȽ�
	friend ostream& operator<<(ostream& os, const Time& t); // ʱ�����
	friend istream& operator>>(istream& is, Time& t); // ʱ������
	friend bool operator==(const Time& t1, const Time& t2); // ʱ�����
	friend bool operator!=(const Time& t1, const Time& t2); // ʱ�䲻��
	friend bool operator<(const Time& t1, const Time& t2); // ʱ��С��
	friend bool operator<=(const Time& t1, const Time& t2); // ʱ��С�ڵ���
	friend bool operator>(const Time& t1, const Time& t2); // ʱ�����
	friend bool operator>=(const Time& t1, const Time& t2); // ʱ����ڵ���

	/* ���������Ԫ����������б�Ҫ�� */
};