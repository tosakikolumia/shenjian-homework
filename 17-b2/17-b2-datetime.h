/* 2351753 �ƿ� �Ʊ��� */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif


#include "17-b2-date.h"
#include "17-b2-time.h"
#include <iostream>
/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */

/* DateTime��Ļ���Ҫ��
	1�����������κ����ݳ�Ա
	2�������ٶ����Ա���� 
*/

class DateTime:public Date, public Time {
protected:
	/* �������ٶ����κ����ݳ�Ա */ 

public:
	/* �������ٶ����κ����ݳ�Ա��������Ҫ�ĳ�Ա��������Ԫ���������� */
	DateTime();
	DateTime(int year, int month, int day, int hour, int minute, int second);
	//set����������
	void set(int year, int month, int day, int hour, int minute, int second);
	void set(int year, int month, int day, int hour, int minute);
	void set(int year, int month, int day, int hour);
	void set(int year, int month, int day);
	void set(int year, int month);
	void set(int year);
	void set();
	void get(int& year, int& month, int& day, int& hour, int& minute, int& second) const; // ��ȡ���ں�ʱ��
	void show() const; // ��ʾ���ں�ʱ��
	DateTime(const long long& time); 
	operator long long() const;

	friend DateTime operator+(const DateTime& dt, const long long& seconds); // ����ʱ���long long
	friend DateTime operator+(const DateTime& dt, const int& seconds); // ����ʱ���int
	friend DateTime operator+(const long long& seconds,const DateTime& dt);/* long long������ʱ�� */
	friend DateTime operator+(const int& seconds, const DateTime& dt2); // int������ʱ��
	friend DateTime operator-(const DateTime& dt, const int& seconds); // ����ʱ���int
	friend DateTime operator-(const DateTime& dt, const long long& t); // ����ʱ���ʱ��
	friend long long operator-(const DateTime& dt1, const DateTime& dt2); // ����ʱ����������
	friend DateTime operator+(const DateTime& dt, const long int& seconds); // ����ʱ���long int
	friend DateTime operator+(const long int& seconds, const DateTime& dt2); // long int������ʱ��
	friend DateTime operator-(const DateTime& dt, const long int& t); // ����ʱ���long int
	friend ostream& operator<<(ostream& os, const DateTime& dt); // ������������
	friend istream& operator>>(istream& is, DateTime& dt); // �������������
	friend bool operator==(const DateTime& dt1, const DateTime& dt2); // ����ʱ�����
	friend bool operator!=(const DateTime& dt1, const DateTime& dt2); // ����ʱ�䲻��
	friend bool operator< (const DateTime& dt1, const DateTime& dt2); // ����ʱ��С��
	friend bool operator<=(const DateTime& dt1, const DateTime& dt2); // ����ʱ��С�ڵ���
	friend bool operator>(const DateTime& dt1, const DateTime& dt2); // ����ʱ�����
	friend bool operator>=(const DateTime& dt1, const DateTime& dt2); // ����ʱ����ڵ���

	/*++��--*/
	DateTime& operator++(); // ++ǰ׺
	DateTime operator++(int); // ++��׺
	DateTime& operator--(); // --ǰ׺
	DateTime operator--(int); // --��׺
	/* ���������Ԫ����������б�Ҫ�� */

};
