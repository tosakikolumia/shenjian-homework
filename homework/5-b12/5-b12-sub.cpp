/* 2351753 信08 黄保翔 */
#include <iostream>
using namespace std;
/* 函数实现部分，{ }内的东西可以任意调整，目前的return 0只是一个示例，可改变 */

/* 不允许定义任何形式的外部全局、静态全局、宏定义、只读变量 */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlen(const char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int i;
    for (i = 0; i < 0x7fffffff; i++) {
        if (str[i] == 0) {
            break;
        }
    }
    return i; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcat(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int p = tj_strlen(s1);
    int p2= tj_strlen(s2);
    int j = 0;
    for (int i = p; i < p + p2 + 1; i++) {
        s1[i] = s2[j];
        j++;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncat(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int x = len;
    if (len > tj_strlen(s2)) {
        x = tj_strlen(s2);
    }
    int p = tj_strlen(s1);
    int j = 0;
    for (int i = p; i < p + x ; i++) {
        s1[i] = s2[j];
        j++;
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcpy(char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int p2 = tj_strlen(s2);
    for (int i = 0; i < p2+1; i++) {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncpy(char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int x = len;
    if (len > tj_strlen(s2)) {
        x = tj_strlen(s2);
    }
    for (int i = 0; i < x ; i++) {
        s1[i] = s2[i];
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len, a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    len = (a < b ? a : b);
    for (int i = 0; i <len+1 ; i++) {
        if (int(s1[i]) != int(s2[i])) {
            return int(s1[i]) - int(s2[i]);
        }
    }
    return 0;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/

int tj_strcasecmp(const char s1[], const char s2[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int len, a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    len = (a < b ? a : b);
    for (int i = 0; i < len+1; i++) {
        int temp1 = 0, temp2 = 0;
        if (int(s1[i]) != int(s2[i])) {
            if (s1[i] >= 'A' && s1[i] <= 'Z') {
                temp1 = s1[i] - ('A' - 'a');
                if (s2[i] >= 'A' && s2[i] <= 'Z') {
                    temp2 = s2[i] - ('A' - 'a');
                }
                else {
                    temp2 = int(s2[i]);
                }
                if (temp1 != temp2) {
                    return temp1 - temp2;
                }
            }
            else{
                temp1 = int(s1[i]);
                if (s2[i] >= 'A' && s2[i] < 'Z') {
                    temp2 = s2[i] - ('A' - 'a');
                }
                else {
                    temp2 = int(s2[i]);
                }
                if (temp1 != temp2) {
                    return temp1 - temp2;
                }
            }
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strncmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    if (len < a && len < b) {
        for (int i = 0; i < len; i++) {
            if (int(s1[i]) != int(s2[i])) {
                return int(s1[i]) - int(s2[i]);
            }
        }
    }
    else {
        int x = (a < b ? a : b);
        for (int i = 0; i < x+1; i++) {
            if (int(s1[i]) != int(s2[i])) {
                return int(s1[i]) - int(s2[i]);
            }
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    if (len < a && len < b) {
        for (int i = 0; i < len ; i++) {
            int temp1 = 0, temp2 = 0;
            if (int(s1[i]) != int(s2[i])) {
                if (s1[i] >= 'A' && s1[i] <= 'Z') {
                    temp1 = s1[i] - ('A' - 'a');
                    if (s2[i] >= 'A' && s2[i] <= 'Z') {
                        temp2 = s2[i] - ('A' - 'a');
                    }
                    else {
                        temp2 = int(s2[i]);
                    }
                    if (temp1 != temp2) {
                        return temp1 - temp2;
                    }
                }
                else {
                    temp1 = int(s1[i]);
                    if (s2[i] >= 'A' && s2[i] < 'Z') {
                        temp2 = s2[i] - ('A' - 'a');
                    }
                    else {
                        temp2 = int(s2[i]);
                    }
                    if (temp1 != temp2) {
                        return temp1 - temp2;
                    }
                }
            }
        }
    }
    else {
        int x = (a < b ? a : b);
        for (int i = 0; i < x +1; i++) {
            int temp1 = 0, temp2 = 0;
            if (int(s1[i]) != int(s2[i])) {
                if (s1[i] >= 'A' && s1[i] <= 'Z') {
                    temp1 = s1[i] - ('A' - 'a');
                    if (s2[i] >= 'A' && s2[i] <= 'Z') {
                        temp2 = s2[i] - ('A' - 'a');
                    }
                    else {
                        temp2 = int(s2[i]);
                    }
                    if (temp1 != temp2) {
                        return temp1 - temp2;
                    }
                }
                else {
                    temp1 = int(s1[i]);
                    if (s2[i] >= 'A' && s2[i] < 'Z') {
                        temp2 = s2[i] - ('A' - 'a');
                    }
                    else {
                        temp2 = int(s2[i]);
                    }
                    if (temp1 != temp2) {
                        return temp1 - temp2;
                    }
                }
            }
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strupr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    for (int i = 0; i < a; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = int(str[i] + ('A' - 'a'));
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strlwr(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    for (int i = 0; i < a; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = int(str[i] - ('A' - 'a'));
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strchr(const char str[], char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    for (int i = 0; i < a; i++) {
        if (str[i] == ch) {
            return i + 1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    int b = tj_strlen(substr);
    for(int i = 0;i<a;i++){
        if (substr[0] == str[i]) {
            for (int j=0; j < b; j++) {
                if (str[i + j] != substr[j]) {
                    break;
                }
                if (j == b - 1) {
                    return i+1;
                }
            }
        }
       
    }
    return 0; //return值可根据需要修改

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrchr(const char str[], const char ch)
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    for (int i = a-1; i >= 0; i--) {
        if (str[i] == ch) {
            return i + 1;
        }
    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrstr(const char str[], const char substr[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    int a = tj_strlen(str);
    int b = tj_strlen(substr);
    for (int i = a-1; i>=0; i--) {
        if (substr[b-1] == str[i]) {
            for (int j = b-1; j>=0; j--) {
                if (str[i -(b - 1 - j)] != substr[j]) {
                    break;
                }
                if (j == 0) {
                    return i + 1 - b + 1;
                }
            }
        }

    }
    return 0; //return值可根据需要修改
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int tj_strrev(char str[])
{
    /* 注意：函数内不允许定义任何形式的数组（包括静态数组） */
    if (tj_strlen(str) != 0) {
        int start = 0;
        int end = tj_strlen(str) - 1;
        char temp;
        while (start < end) {
            temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
    }
    return 0; //return值可根据需要修改
}
