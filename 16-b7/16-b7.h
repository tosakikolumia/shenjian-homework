/* 2351753 计科 黄保翔 */
#if defined(__linux) || defined(__linux__)
#else
#pragma once
#endif
#include <iostream>
using namespace std;

enum week { sun, mon, tue, wed, thu, fri, sat };

/* 允许添加相应的函数声明 */
#define ERROR_ENUM -1
ostream& operator<< (ostream& os, const week& w);
istream& operator>> (istream& is, week& w);
week& operator++ (week& w);
week& operator-- (week& w);
week operator++ (week& w, int);
week operator-- (week& w, int);
week operator+ (const week w1, const int n);
week operator- (const week w1, const int n);
week& operator+= (week& w1, const int n);
week& operator-= (week& w1, const int n);
