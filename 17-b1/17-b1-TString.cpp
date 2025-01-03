/* 2351753 计科 黄保翔 */

/* 允许添加需要的头文件、宏定义等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <cstring>
#include "17-b1-TString.h"
using namespace std;

/* 给出 TString 类的所有成员函数的体外实现 */
TString::TString() {
    len = 0;
    content = nullptr;
}
TString::TString(const char* str) {
    if (str == nullptr||strcmp(str,"")==0) {
        len = 0;
        content = nullptr;
    }
    else {
        len = strlen(str);
        content = new(nothrow )char[len + 1];//开一个大小为n+1的空间
        if (content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            len = 0;
            content = nullptr;
        }
        strcpy(content, str);
    }
}
TString::TString(const TString& str) {
    if (str.content != nullptr) {
        len = str.len;
        content = new(nothrow)char[len + 1];
        if (content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            len = 0;
            content = nullptr;
        }
        strcpy(content, str.content);
    }
    else {
        len = 0;
        content = nullptr;
    }
}
TString::~TString() {
    if (content != nullptr) {
        delete[] content;
        content = nullptr;
    }
}
TString& TString::operator=(const TString& str) {
    if (this != &str) {//如果不是赋值给自身，否则直接返回自身
        if (content != nullptr) {//如果原来有内容，先释放掉
            delete[] content;
            content = nullptr;
        }
        if (str.content != nullptr) {
            len = str.len;
            content = new(nothrow )char[len + 1];
            if(content == nullptr){
                cout << "Memory allocation failed!" << endl;
                len = 0;
                content = nullptr;
            }
            strcpy(content, str.content);
        }
        else {
            len = 0;
            content = nullptr;
        }
    }
    return *this;
}
TString& TString::operator=(const char* str) {
    if (content != nullptr) {//如果原来有内容，先释放掉
        delete[] content;
        content = nullptr;
    }
    if (str == nullptr) {
        len = 0;
        content = nullptr;
    }
    else {
        len = strlen(str);
        content = new(nothrow) char[len + 1];
        if (content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            len = 0;
            content = nullptr;
        }

        strcpy(content, str);
    }
    return *this;
}
/*取字符串操作实现*/
const char* TString::c_str() const {
    return content;
}
/*取字符串大小实现*/
int TString::length() const {
    return len;
}
/*自连接操作*/
TString& TString ::operator+=(const TString& str) {
    if (str.content == nullptr)
        return *this;
    if (content == nullptr) {
        *this = str;
        return *this;
    }
    len = len + str.len;
    char* newContent = new(nothrow) char[len + 1];
    if (newContent == nullptr) {    
        cout << "Memory allocation failed!" << endl;
        return *this;
    }
    strcpy(newContent, content);
    strcat(newContent, str.content);
    delete[] content;
    content = newContent;
    return *this;
}
TString& TString::operator+=(const char* str) {
    if (str == nullptr)
        return *this;
    if (content == nullptr) {
        *this = str;
        return *this;
    }
    int len2 = strlen(str);
    len = len + len2;
    char* newContent = new(nothrow) char[len + 1];
    if (newContent == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return *this;
    }
    strcpy(newContent, content);
    strcat(newContent, str);
    delete[] content;
    content = newContent;
    return *this;
}
TString& TString::operator+=(const char ch) {
    len = len + 1;
    if (content == nullptr) {
        content = new(nothrow) char[len + 1];
        if (content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return *this;
        }
        content[0] = ch;
        content[1] = '\0';
        return *this;
    }
    char* newContent = new(nothrow) char[len + 1];
    if (newContent == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return *this;
    }
    strcpy(newContent, content);
    newContent[len - 1] = ch;
    newContent[len] = '\0';
    delete[] content;
    content = newContent;
    return *this;
}
/*-删除操作*/
TString TString::operator-(const TString& str) {
    TString result;
    if (str.content == nullptr || content == nullptr) {
        result = *this;
        return result;
    }
    char* find = strstr(content, str.content);
    if (find == nullptr) {//如果没有找到，直接返回原字符串
        result = *this;
    }
    else {
        int pos = find - content;
        result.len = len - str.len;
        result.content = new(nothrow) char[result.len + 1];
        if (result.content == nullptr) {
                cout << "Memory allocation failed!" << endl;
                return result;
        }
        strncpy(result.content, content, pos);
        strncpy(result.content + pos, content + pos + str.len, result.len - pos);
        result.content[result.len] = '\0';
    }
    return result;
}
TString TString::operator-(const char* str) {
    TString result;
    if (str == nullptr || content == nullptr) {
        result = *this;
        return result;
    }
    char* find = strstr(content, str);
    if (find == nullptr) {//如果没有找到，直接返回原字符串
        result = *this;
    }
    else {
        int pos = find - content;
        result.len = len - strlen(str);
        result.content = new(nothrow) char[result.len + 1];
        if (result.content == nullptr) {
                cout << "Memory allocation failed!" << endl;
                return result;
        }
        strncpy(result.content, content, pos);
        strncpy(result.content + pos, content + pos + strlen(str), result.len - pos);
        result.content[result.len] = '\0';
    }
    return result;
}
TString TString::operator-(const char ch) {
    TString result;
    if (content == nullptr) {
        result = *this;
        return result;
    }
    char* find = strchr(content, ch);
    if (find == nullptr) {//如果没有找到，直接返回原字符串
        result = *this;
    }
    else {
        int pos = find - content;
        result.len = len - 1;
        result.content = new(nothrow) char[result.len + 1];
        if (result.content == nullptr) {
                cout << "Memory allocation failed!" << endl;
                return result;
        }
        strncpy(result.content, content, pos);
        strncpy(result.content + pos, content + pos + 1, result.len - pos);
        result.content[result.len] = '\0';
    }
    return result;
}
/*自删除操作*/
TString& TString::operator-=(const TString& str) {
    *this = *this - str;
    return *this;
}
TString& TString::operator-=(const char* str) {
    *this = *this - str;
    return *this;
}
TString& TString::operator-=(const char ch) {
    *this = *this - ch;
    return *this;
}
/**复制操作实现*/
TString TString:: operator*(const int num) {
    TString result;
    if (content != nullptr) {
        result.len = len * num;
        result.content = new(nothrow) char[result.len + 1];
        if (result.content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return result;
        }
        for (int i = 0; i < num; i++) {
            strncpy(result.content + i * len, content, len);
        }
        result.content[result.len] = '\0';
    }
    else {
        result.len = 0;
        result.content = nullptr;
    }
    return result;
}
/**=自复制操作实现*/
TString& TString::operator*=(const int num) {
    *this = *this * num;
    return *this;
}
/*！反转操作实现*/
TString TString:: operator!() {
    TString result;
    if (content != nullptr) {
        result.len = len;
        result.content = new(nothrow) char[len + 1];
        if (result.content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return result;
        }
        for (int i = 0; i < len; i++) {
            result.content[i] = content[len - 1 - i];
        }
        result.content[len] = '\0';
    }
    else {
        result.len = 0;
        result.content = nullptr;
    }
    return result;
}
char& TString::operator[](const int index) {
    return content[index];
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/*友元函数，输入输出的实现*/
istream& operator>>(istream& is, TString& str) {
    char* temp = new(nothrow) char[MAX_READ_IN_LEN];
    if (temp == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return is;
    }
    is >> temp;
    int len = strlen(temp);
    str.len = len;
    str.content = new(nothrow) char[len + 1];
    if (str.content == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return is;
    }
    strcpy(str.content, temp);
    delete[] temp;
    return is;
}
ostream& operator<<(ostream& os, const TString& str) {
    if (str.content != nullptr && str.content[0] != '\0') {
        os << str.content;
    }
    else
        os << "<EMPTY>";//空字符串输出为<empty>
    return os;
}
/*连接操作实现*/
TString operator+(const TString& str1, const TString& str2) {
    TString result;
    if (str1.content == nullptr) {
        result = str2;
        return result;
    }
    if (str2.content == nullptr) {
        result = str1;
        return result;
    }
    result.len = str1.len + str2.len;
    result.content = new(nothrow) char[result.len + 1];
    if (result.content == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return result;
    }
    strcpy(result.content, str1.content);
    strcat(result.content, str2.content);
    return result;
}
TString operator+(const TString& str1, const char* str2) {
    TString result;
    if (str1.content == nullptr) {
        result = str2;
        return result;
    }
    if (str2 == nullptr) {
        result = str1;
        return result;
    }
    int len2 = strlen(str2);
    result.len = str1.len + len2;
    result.content = new(nothrow) char[result.len + 1];
    if (result.content == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return result;
    }
    strcpy(result.content, str1.content);
    strcat(result.content, str2);
    return result;
}
TString operator+(const char* str1, const TString& str2) {
    TString result;
    if (str2.content == nullptr) {
        result = str1;
        return result;
    }
    if (str1 == nullptr) {
        result = str2;
        return result;
    }
    int len2 = strlen(str1);
    result.len = str2.len + len2;
    result.content = new(nothrow) char[result.len + 1];
    if (result.content == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return result;  
    }
    strcpy(result.content, str1);
    strcat(result.content, str2.content);
    return result;
}
TString operator+(const TString& str1, const char ch) {
    TString result;
    if (str1.content == nullptr) {
        result.len = 1;
        result.content = new(nothrow) char[2];
        if (result.content == nullptr) {
            cout << "Memory allocation failed!" << endl;
            return result;
        }
        result.content[0] = ch;
        result.content[1] = '\0';
        return result;
    }
    result.len = str1.len + 1;
    result.content = new(nothrow) char[result.len + 1];
    if (result.content == nullptr) {    
        cout << "Memory allocation failed!" << endl;
        return result;
    }
    strcpy(result.content, str1.content);
    result.content[str1.len] = ch;
    result.content[result.len] = '\0';
    return result;
}
TString operator+(const char ch, const TString& str2) {
    TString result;
    if (str2.content == nullptr) {
        result.len = 1;
        result.content = new(nothrow) char[2];
        if (result.content == nullptr) {    
        cout << "Memory allocation failed!" << endl;
        return result;
        }
        result.content[0] = ch;
        result.content[1] = '\0';
        return result;
    }
    result.len = str2.len + 1;
    result.content = new(nothrow) char[result.len + 1];
    if (result.content == nullptr) {
        cout << "Memory allocation failed!" << endl;
        return result;
    }
    result.content[0] = ch;
    strcpy(result.content + 1, str2.content);
    result.content[result.len] = '\0';
    return result;
}
bool operator>(const TString& str1, const TString& str2) {
    if (str1.empty())
        return false;
    if (str2.empty())
        return true;
    return strcmp(str1.content, str2.content) > 0;
}
bool operator<(const TString& str1, const TString& str2) {
    if (str1.empty())
        return (!str2.empty());
    if (str2.empty())
        return false;
    return strcmp(str1.content, str2.content) < 0;
}
bool operator==(const TString& str1, const TString& str2) {
    if (str1.empty() && str2.empty())
        return true;
    if (str1.empty() || str2.empty())
        return false;
    return strcmp(str1.content, str2.content) == 0;
}
bool operator!=(const TString& str1, const TString& str2) {
    return !(str1 == str2);
}
bool operator>=(const TString& str1, const TString& str2) {
    return !(str1 < str2);
}
bool operator<=(const TString& str1, const TString& str2) {
    return !(str1 > str2);
}
/**/
bool operator>(const TString& str1, const char* str2) {
    if (str1.empty())
        return false;
    if (str2 == nullptr || strcmp(str2, "") == 0)
        return true;
    return strcmp(str1.content, str2) > 0;
}

bool operator<(const TString& str1, const char* str2) {
    if (str1.empty())
        return (str2 != nullptr && strcmp(str2, "") != 0);
    if (str2 == nullptr || strcmp(str2, "") == 0)
        return false;
    return strcmp(str1.content, str2) < 0;
}
bool operator<=(const TString& str1, const char* str2) {
    return !(str1 > str2);
}
bool operator>=(const TString& str1, const char* str2) {
    return !(str1 < str2);
}
bool operator==(const TString& str1, const char* str2) {
    if (str1.empty() && (str2 == nullptr || strcmp(str2, "") == 0))
        return true;
    if (str1.empty() || (str2 == nullptr || strcmp(str2, "") == 0))
        return false;
    return strcmp(str1.content, str2) == 0;
}
bool operator!=(const TString& str1, const char* str2) {
    return !(str1 == str2);
}
/**/
bool operator>(const char* str1, const TString& str2) {
    return !(str2 >= str1);
}
bool operator<(const char* str1, const TString& str2) {
    return !(str2 <= str1);
}
bool operator<=(const char* str1, const TString& str2) {
    return !(str2 < str1);
}
bool operator>=(const char* str1, const TString& str2) {
    return !(str2 > str1);
}
bool operator==(const char* str1, const TString& str2) {
    return str2 == str1;
}
bool operator!=(const char* str1, const TString& str2) {
    return str2 != str1;
}
int TStringLen(const TString& str) {
    return str.len;
}

/*私有函数的实现*/
bool TString::empty() const {
    return (content == nullptr || content[0] == '\0');
}