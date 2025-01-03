/* 2351753 �ƿ� �Ʊ��� */

/* ���������Ҫ��ͷ�ļ����궨��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include <limits>
#include "17-b1-TStringAdv.h"
using namespace std;
/* ���� TStringAdv ������г�Ա����������ʵ�� */
//���캯����ʵ��
TStringAdv::TStringAdv() :TString() {}
TStringAdv::TStringAdv(const char* s) :TString(s) {}
TStringAdv::TStringAdv(const TStringAdv& s) :TString(s) {}
//����������ʵ��
TStringAdv::~TStringAdv() {}
//ת�����캯����ʵ��
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
    pos -= 1; // ��Ϊ����λ���Ǵ�1��ʼ��
    if(pos < 0 || pos > length())
        return *this;  // ���ַ����ĳ���
    if(ts2.empty())
        return *this;
    // ���ַ����ĳ���
    int newLength = length() + ts2.length();
    char* newStr = new(nothrow) char[newLength + 1]; // +1 Ϊ����ֹ��'\0'
    if (newStr == NULL) {
       cout<<"Memory allocation failed!"<<endl;
       return *this;
    }
    // ���Ƶ�ǰ�ַ�����ǰ����
    memcpy(newStr, content, pos);
    newStr[pos] = '\0'; // �ڲ���λ�������ֹ��

    // ����Ҫ������ַ���
    strcat(newStr, ts2.content);

    // ��������ԭ�ַ����ĺ󲿷�
    strcat(newStr, content + pos);

    // ���µ�ǰ������ַ�������
    delete[] content; // �ͷ�ԭ���ڴ�
    content = newStr; // ����ָ��
    len = newLength; // ���³���
    return *this; // ���ص�ǰ����
}
TStringAdv& TStringAdv::insert(const char* s, int pos) {
    TStringAdv ts2(s);
    if(ts2.empty())
        return *this;
    return insert(ts2, pos);
}
TStringAdv& TStringAdv::insert(const char& c, int pos) {
    pos -= 1; // ��Ϊ����λ���Ǵ�1��ʼ��
    if (pos < 0 || pos > length()) {
        return *this; // ���ص�ǰ����δ���в���
    }
    // ���ַ����ĳ���
    int newLength = length() + 1; // +1 Ϊ�˲���һ���ַ�
    char* newStr = new(nothrow) char[newLength + 1]; // +1 Ϊ�˷���ֹ�� '\0'
    if (newStr == NULL) {
        cout << "Memory allocation failed!" << endl;
        return *this;
    }
    //����cΪ'\0'�����
    // ���Ƶ�ǰ�ַ�����ǰ����
    strncpy(newStr, content, pos);
    //cout << "newStr  " << newStr << endl;
    newStr[pos] = c; // �ڲ���λ�ò����ַ�
    newStr[pos+1] = '\0'; // �ڲ���λ�������ֹ��
    if(c != '\0')
    // ����ԭ�ַ����ĺ󲿷�
        strcat(newStr, content + pos);
    //cout << "newStr  " << newStr << endl;
    // ���µ�ǰ������ַ�������
    int temp_len = strlen(newStr);
    char* temp = new(nothrow) char[temp_len+1];
    if(temp == NULL)
    {
        cout<<"Memory allocation failed!"<<endl;
        return *this;
    }
    strncpy(temp, newStr, temp_len);
    temp[temp_len] = '\0';
    delete[] content; // �ͷ�ԭ���ڴ�
    delete[] newStr;
    content = temp; // ����ָ��
    len = temp_len; // ���³���
    return *this; // ���ص�ǰ����
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
    // ��� pos С�� 0 �� pos ������ǰ�ַ������ȣ����ؿմ�
    if (pos < 1 || pos > this->len) {
        return TStringAdv();  // ���ؿյ� TStringAdv ����
    }
    if (len <= 0)
        return TStringAdv();
    // ��� len Ϊ -1����ʾȡ���ַ���ĩβ
    int sub_len = (len == INT_MAX) ? (this->len - pos + 1) : len;

    // ��� pos + sub_len �������ַ����ĳ��ȣ���ȡ���ַ�����ĩβ
    sub_len = (pos-1 + sub_len > this->len) ? (this->len - pos+1) : sub_len;

    // �����ڴ沢�����Ӵ�
    char* sub_content = new(nothrow) char[sub_len + 1];  // +1 ��Ϊ�˴����ֹ�� '\0'
    if (sub_content == NULL) {
        return TStringAdv();  // ���ؿյ� TStringAdv ����
    }
    memcpy(sub_content, content + pos-1, sub_len);
    sub_content[sub_len] = '\0';  // ȷ���Ӵ��� '\0' ����

    // ���� TStringAdv ���󲢷���
    TStringAdv result(sub_content);
    delete[] sub_content;  // �ͷ���ʱ�ڴ�
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