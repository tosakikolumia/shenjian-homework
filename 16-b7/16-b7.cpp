/* 2351753 计科 黄保翔 */
#include <iostream>
#include <cstring>
#include "16-b7.h"
using namespace std;
ostream& operator<< (ostream& os, const week& w) {
	const char* week_day[] = { "星期日","星期一", "星期二", "星期三","星期四","星期五","星期六" };
	if (w< week::sun || w > week::sat) {
		os << "错误";
		return os;
	}
	os << week_day[int(w)];
	return os;
}
istream& operator>> (istream& is, week& w) {
	char temp[10] = { 0 };
	is >> temp;
	for (int i = 0; i < 10; i++) {
		if (temp[i] >= 'A' && temp[i] <= 'Z')
			temp[i] += 32;//转化为小写字母
	}
	if (strcmp(temp, "sun") == 0)
		w = week::sun;
	else if (strcmp(temp, "mon") == 0)
		w = week::mon;
	else if (strcmp(temp, "tue") == 0)
		w = week::tue;
	else if (strcmp(temp, "wed") == 0)
		w = week::wed;
	else if (strcmp(temp, "thu") == 0)
		w = week::thu;
	else if (strcmp(temp, "fri") == 0)
		w = week::fri;
	else if (strcmp(temp, "sat") == 0)
		w = week::sat;
	else
		w = week(ERROR_ENUM);
	return is;
}
week& operator++(week& w) {
	int i = int(w);
	if (i + 1 > 6)
		w = week(0);
	else
		w = week(i + 1);
	return w;
}
week& operator--(week& w) {
	int i = int(w);
	if (i - 1 < 0)
		w = week(6);
	else
		w = week(i - 1);
	return w;
}
week operator++(week& w, int) {
	week tmp = w;
	int i = int(w);
	if (i + 1 > 6)
		w = week(0);
	else
		w = week(i + 1);
	return tmp;
}
week operator--(week& w, int) {
	week tmp = w;
	int i = int(w);
	if (i - 1 < 0)
		w = week(6);
	else
		w = week(i - 1);
	return tmp;
}
week operator+(const week w1, const int n) {
	week temp;
	int i = int(w1);
	i += (n % 7);
	if (i > 6)
		i -= 7;
	temp = week(i);
	return temp;
}
week operator-(const week w1, const int n) {
	week temp;
	int i = int(w1);
	i -= (n % 7);
	if (i < 0)
		i += 7;
	temp = week(i);
	return temp;
}
week& operator+= (week& w1, int n) {
	w1 = w1 + n;
	return w1;
}
week& operator-= (week& w1, int n) {
	w1 = w1 - n;
	return w1;
}