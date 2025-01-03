/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif

#include <iostream>
using namespace std;

/* 补全TString类的定义，所有成员函数均体外实现，不要在此处体内实现 */
class TString {
protected:
	char* content;
	int   len;
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	/* 私有函数 */
	bool empty() const;
public:
	/* 根据需要定义所需的数据成员、成员函数、友元函数等 */
	/* 构造函数、析构函数、赋值运算符等初始化方式*/
	TString();//默认构造函数
	TString(const char* str);//拷贝构造函数,Tstring s1("hello");
	TString(const TString& str);//拷贝构造函数,Tstring s2=s1;
	~TString();
	int  length() const;
	const char* c_str() const;//拷贝字符串内容到char*
	TString& operator=(const char* str);//赋值运算符,Tstring s2="hello";
	TString& operator=(const TString& str);//赋值运算符,Tstring s2=s1;
	/*自连接+=操作*/
	TString& operator+=(const TString& str);
	TString& operator+=(const char* str);
	TString& operator+=(const char ch);
	/*-删除操作*/
	TString operator-(const TString& str);
	TString operator-(const char* str);
	TString operator-(const char ch);
	/*自删除操作*/
	TString& operator-=(const TString& str);
	TString& operator-=(const char* str);
	TString& operator-=(const char ch);
	/**复制操作*/
	TString operator*(const int num);
	/**=自复制操作*/
	TString& operator*=(const int num);
	/*！反转操作*/
	TString operator!();
	/*[]取字符*/
	char& operator[](const int index);
	/*输入操作*/
	friend istream& operator>>(istream& is, TString& str);
	friend ostream& operator<<(ostream& os, const TString& str);
	/*+连接操作*/
	/*连接两个类对象*/
	friend TString operator+(const TString& str1, const TString& str2);
	/*连接字符串与类对象*/
	friend TString operator+(const TString& str1, const char* str2);
	friend TString operator+(const char* str1, const TString& str2);
	/*连接类对象与单个字符*/
	friend TString operator+(const TString& str1, const char ch);
	friend TString operator+(const char ch, const TString& str2);
	/*比较操作*/
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

/* 如果有其它全局函数需要声明，写于此处 */
/* 如果有需要的宏定义、只读全局变量等，写于此处 */
#define MAX_READ_IN_LEN 1024 //最大读入字符串长度限制
