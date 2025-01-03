/* 2351753 �ƿ� �Ʊ��� */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif

#include <iostream>
using namespace std;

/* ��ȫTString��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class TString {
protected:
	char* content;
	int   len;
	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
	/* ˽�к��� */
	bool empty() const;
public:
	/* ������Ҫ������������ݳ�Ա����Ա��������Ԫ������ */
	/* ���캯����������������ֵ������ȳ�ʼ����ʽ*/
	TString();//Ĭ�Ϲ��캯��
	TString(const char* str);//�������캯��,Tstring s1("hello");
	TString(const TString& str);//�������캯��,Tstring s2=s1;
	~TString();
	int  length() const;
	const char* c_str() const;//�����ַ������ݵ�char*
	TString& operator=(const char* str);//��ֵ�����,Tstring s2="hello";
	TString& operator=(const TString& str);//��ֵ�����,Tstring s2=s1;
	/*������+=����*/
	TString& operator+=(const TString& str);
	TString& operator+=(const char* str);
	TString& operator+=(const char ch);
	/*-ɾ������*/
	TString operator-(const TString& str);
	TString operator-(const char* str);
	TString operator-(const char ch);
	/*��ɾ������*/
	TString& operator-=(const TString& str);
	TString& operator-=(const char* str);
	TString& operator-=(const char ch);
	/**���Ʋ���*/
	TString operator*(const int num);
	/**=�Ը��Ʋ���*/
	TString& operator*=(const int num);
	/*����ת����*/
	TString operator!();
	/*[]ȡ�ַ�*/
	char& operator[](const int index);
	/*�������*/
	friend istream& operator>>(istream& is, TString& str);
	friend ostream& operator<<(ostream& os, const TString& str);
	/*+���Ӳ���*/
	/*�������������*/
	friend TString operator+(const TString& str1, const TString& str2);
	/*�����ַ����������*/
	friend TString operator+(const TString& str1, const char* str2);
	friend TString operator+(const char* str1, const TString& str2);
	/*����������뵥���ַ�*/
	friend TString operator+(const TString& str1, const char ch);
	friend TString operator+(const char ch, const TString& str2);
	/*�Ƚϲ���*/
	friend bool operator> (const TString& str1, const TString& str2);
	friend bool operator< (const TString& str1, const TString& str2);
	friend bool operator>= (const TString& str1, const TString& str2);
	friend bool operator<= (const TString& str1, const TString& str2);
	friend bool operator== (const TString& str1, const TString& str2);
	friend bool operator!= (const TString& str1, const TString& str2);
	//
	friend bool operator> (const TString& str1, const char* str2);
	friend bool operator< (const TString& str1, const char* str2);
	friend bool operator>= (const TString& str1, const char* str2);
	friend bool operator<= (const TString& str1, const char* str2);
	friend bool operator== (const TString& str1, const char* str2);
	friend bool operator!= (const TString& str1, const char* str2);
	//
	friend bool operator> (const char* str1, const TString& str2);
	friend bool operator< (const char* str1, const TString& str2);
	friend bool operator>= (const char* str1, const TString& str2);
	friend bool operator<= (const char* str1, const TString& str2);
	friend bool operator== (const char* str1, const TString& str2);
	friend bool operator!= (const char* str1, const TString& str2);
	friend int TStringLen(const TString& str);

};

/* ���������ȫ�ֺ�����Ҫ������д�ڴ˴� */
/* �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� */
#define MAX_READ_IN_LEN 1024 //�������ַ�����������
