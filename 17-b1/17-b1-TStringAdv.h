/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif

#include <iostream>
#include <limits>
#include "17-b1-TString.h"
#if defined(__linux) || defined(__linux__)
#include <climits>
#endif
using namespace std;
class TStringAdv : public TString {
public:
	TStringAdv();
	TStringAdv(const char* s);
	TStringAdv(const TStringAdv& s);
	~TStringAdv();
	/*转换构造函数*/
	TStringAdv(const TString& s);
	//assign
	TStringAdv& assign(const TStringAdv& ts2);
	TStringAdv& assign(const  char* s);
	/*append*/
	TStringAdv& append(const TStringAdv& ts2);
	TStringAdv& append(const char* s);
	TStringAdv& append(const char& c);
	/*insert*/
	TStringAdv& insert (const TStringAdv& ts2, int pos); 
	TStringAdv& insert (const char* s, int pos); 
	TStringAdv& insert (const char& c, int pos); 
	/*erase*/
	TStringAdv& erase (const TStringAdv& ts2);
	TStringAdv& erase (const char* s);
	TStringAdv& erase (const char& c);
	//substr
	TStringAdv substr(const int pos,const int len = INT_MAX) const;
	//at
	char& at(const int n);
	//Advlen
	friend TStringAdv operator+(const TStringAdv& str1, const TStringAdv& str2);
	friend TStringAdv operator+(const char* str2,const TStringAdv& str1);
	friend TStringAdv operator+(const TStringAdv& str1, const char& c);
	friend TStringAdv operator+(const char& c, const TStringAdv& str1);
	friend TStringAdv operator+(const TStringAdv& str1, const char* str2);
	TStringAdv& operator+=(const TStringAdv& str);
	TStringAdv& operator+=(const char& c);
	friend int TStringAdvLen(const TStringAdv& str);
};
