/* 2351753 计科 黄保翔 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <limits>
#include "17-b1-TStringAdv.h"
using namespace std;
/* 给出 TStringAdv 类的所有成员函数的体外实现 */
//构造函数的实现
TStringAdv::TStringAdv() :TString() {}
TStringAdv::TStringAdv(const char* s) :TString(s) {}
TStringAdv::TStringAdv(const TStringAdv& s) :TString(s) {}
//析构函数的实现
TStringAdv::~TStringAdv() {}
//转换构造函数的实现
TStringAdv::TStringAdv(const TString& s) : TString(s) {}

//assign
TStringAdv& TStringAdv::assign(const TStringAdv& ts2) {
	*this = ts2;
	return *this;
}
TStringAdv& TStringAdv::assign(const  char* s) {
	*this = s;
	return *this;
}
/*append*/
TStringAdv&TStringAdv ::append(const TStringAdv& ts2) {
     *this += ts2;
      return *this;
}
TStringAdv& TStringAdv::append(const char* s) {
     *this += s;
      return *this;
}
TStringAdv& TStringAdv::append(const char& c) {
     *this += c;
      return *this;
}
//insert
TStringAdv& TStringAdv::insert(const TStringAdv& ts2, int pos) {
    pos -= 1; // 因为插入位置是从1开始的
    if(pos < 0 || pos > length())
        return *this;  // 新字符串的长度
    if(ts2.empty())
        return *this;
    // 新字符串的长度
    int newLength = length() + ts2.length();
    char* newStr = new(nothrow) char[newLength + 1]; // +1 为了终止符'\0'
    if (newStr == NULL) {
       cout<<"Memory allocation failed!"<<endl;
       return *this;
    }
    // 复制当前字符串的前部分
    memcpy(newStr, content, pos);
    newStr[pos] = '\0'; // 在插入位置添加终止符

    // 复制要插入的字符串
    strcat(newStr, ts2.content);

    // 继续复制原字符串的后部分
    strcat(newStr, content + pos);

    // 更新当前对象的字符串内容
    delete[] content; // 释放原有内存
    content = newStr; // 更新指针
    len = newLength; // 更新长度
    return *this; // 返回当前对象
}
TStringAdv& TStringAdv::insert(const char* s, int pos) {
    TStringAdv ts2(s);
    if(ts2.empty())
        return *this;
    return insert(ts2, pos);
}
TStringAdv& TStringAdv::insert(const char& c, int pos) {
    pos -= 1; // 因为插入位置是从1开始的
    if (pos < 0 || pos > length()) {
        return *this; // 返回当前对象，未进行插入
    }
    // 新字符串的长度
    int newLength = length() + 1; // +1 为了插入一个字符
    char* newStr = new(nothrow) char[newLength + 1]; // +1 为了放终止符 '\0'
    if (newStr == NULL) {
        cout << "Memory allocation failed!" << endl;
        return *this;
    }
    //考虑c为'\0'的情况
    // 复制当前字符串的前部分
    strncpy(newStr, content, pos);
    //cout << "newStr  " << newStr << endl;
    newStr[pos] = c; // 在插入位置插入字符
    newStr[pos+1] = '\0'; // 在插入位置添加终止符
    if(c != '\0')
    // 复制原字符串的后部分
        strcat(newStr, content + pos);
    //cout << "newStr  " << newStr << endl;
    // 更新当前对象的字符串内容
    int temp_len = strlen(newStr);
    char* temp = new(nothrow) char[temp_len+1];
    if(temp == NULL)
    {
        cout<<"Memory allocation failed!"<<endl;
        return *this;
    }
    strncpy(temp, newStr, temp_len);
    temp[temp_len] = '\0';
    delete[] content; // 释放原有内存
    delete[] newStr;
    content = temp; // 更新指针
    len = temp_len; // 更新长度
    return *this; // 返回当前对象
}
//erase
TStringAdv& TStringAdv::erase(const TStringAdv& ts2) {
    *this -= ts2;
    return *this;
}
TStringAdv& TStringAdv::erase(const char* s) {
    *this -= s;
    return *this;
}
TStringAdv& TStringAdv::erase(const char& c) {
    *this -= c;
    return *this;
}
//substr
TStringAdv TStringAdv::substr(const int pos, const int len) const {
    // 如果 pos 小于 0 或 pos 超过当前字符串长度，返回空串
    if (pos < 1 || pos > this->len) {
        return TStringAdv();  // 返回空的 TStringAdv 对象
    }
    if (len <= 0)
        return TStringAdv();
    // 如果 len 为 -1，表示取到字符串末尾
    int sub_len = (len == INT_MAX) ? (this->len - pos + 1) : len;

    // 如果 pos + sub_len 超过了字符串的长度，截取到字符串的末尾
    sub_len = (pos-1 + sub_len > this->len) ? (this->len - pos+1) : sub_len;

    // 分配内存并生成子串
    char* sub_content = new(nothrow) char[sub_len + 1];  // +1 是为了存放终止符 '\0'
    if (sub_content == NULL) {
        return TStringAdv();  // 返回空的 TStringAdv 对象
    }
    memcpy(sub_content, content + pos-1, sub_len);
    sub_content[sub_len] = '\0';  // 确保子串以 '\0' 结束

    // 创建 TStringAdv 对象并返回
    TStringAdv result(sub_content);
    delete[] sub_content;  // 释放临时内存
    return result;
}
char& TStringAdv::at(const int n) {
    return (*this)[n];
}
int TStringAdvLen(const TStringAdv& str) {
    return TStringLen(str);
}
TStringAdv operator+(const TStringAdv& str1, const TStringAdv& str2) {
    return TStringAdv(TString(str1) + TString(str2));
}
TStringAdv operator+(const TStringAdv& str1, const char& c) {
    return TString(str1) + c;
}
TStringAdv operator+(const char& c, const TStringAdv& str2) {
    return c + TString(str2);
}
TStringAdv operator+(const TStringAdv& str1, const char* str2) {
    return TString(str1) + str2;
}
TStringAdv operator+(const char* str1, const TStringAdv& str2) {
    return str1 + TString(str2);
}

TStringAdv& TStringAdv::operator+=(const TStringAdv& str) {
    return *this = *this + str;
}
TStringAdv& TStringAdv::operator+=(const char& c) {
    return *this = *this + c;
}