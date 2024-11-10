/* 2351753 ��08 �Ʊ��� */

#include <cstdio>   //NULL
//������������κ�ϵͳͷ�ļ�

/* ----- ���������κ���ʽ��ȫ�ֱ���/ȫ������/ֻ��ȫ�ֱ���/�궨��!!!!! ----- */

/* ����ʵ�ֲ��֣�{ }�ڵĶ����������������Ŀǰ��returnֻ��һ��ʾ�����ɸı� */
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strlen(const char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    const char* pp = str;
    for (str; *str; str++);
    return str-pp;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcat(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int p1 = tj_strlen(s1);
    int p2 = tj_strlen(s2);
    char* p = s1;
    if (s1 == NULL) {
        return 0;
    }
    if (s2 == NULL) {
        return s1;
    }
    for (p += p1; *s2; s2++) {
        *p = *s2;
        p++;
    }
    *p = 0;
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncat(char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    char* p = s1;
    const char* p2 = s2;
    int x = len;
    if (s1 == NULL) {
        return 0;
    }
    if (s2 == NULL) {
        return s1;
    }
    if (len > tj_strlen(s2)) {
        x = tj_strlen(s2);
    }
    for (p += tj_strlen(s1); s2<p2+x; s2++) {
        *p = *s2;
        p++;
    }

    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strcpy(char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL) {
        return NULL;
    }
    if (s2 == NULL) {
        *s1 = 0;
        return s1;
    }
    int p2 = tj_strlen(s2);
    char* p = s1;
    for (p; p<s1+p2+1; s2++) {
        *p = *s2;
        p++;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strncpy(char *s1, const char *s2, const int len)
{
    if (s1 == NULL) {
        return NULL;
    }
    if (s2 == NULL) {
        return s1;
    }
    int x = len;
    if (len > tj_strlen(s2)) {
        x = tj_strlen(s2);
    }
    char* p = s1;
    const char* p2 = s2;
    for (p; s2 < p2 + x; s2++) {
        *p = *s2;
        p++;
    }
    return s1;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcmp(const char *s1, const char *s2)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL&&s2!=NULL) {
        return -1;
    }
    if (s2 == NULL&&s1!=NULL) {
        return 1;
    }
    if (s2 == NULL && s1 == NULL) {
        return 0;
    }
    int len, a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    len = (a < b ? a : b);
    const char* p = s1;
    for (s1; s1 < p + len + 1; ) {
        if (*s2 != *s1) {
            return int(*s1 - *s2);
        }
        s1++;
        s2++;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasecmp(const char *s1, const char *s2)
{
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s2 == NULL && s1 != NULL) {
        return 1;
    }
    if (s2 == NULL && s1 == NULL) {
        return 0;
    }
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    int len, a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    len = (a < b ? a : b);
    const char* p = s1;
    for (s1; s1 < p + len + 1;) {      

        if (*s1 != *s2) {
            char temp1 = *s1, temp2 = *s2;
            if (*s1 >= 'A' && *s1 <= 'Z') {
                 temp1 = *s1 - ('A' - 'a');
            }
            if (*s2 >= 'A' && *s2 <= 'Z') {
                temp2 = *s2 - ('A' - 'a');
            }
            if (temp1 != temp2) {
                return temp1 - temp2;
            }
            else {
                s1++;
                s2++;
                continue;
            }
        }
        s1++;
        s2++;
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strncmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s2 == NULL && s1 != NULL) {
        return 1;
    }
    if (s2 == NULL && s1 == NULL) {
        return 0;
    }
    int a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    const char* p1 = s1;
    if (len <= a && len <= b) {
        for (s1; s1 < p1+len; ) {
            if (*s1 != *s2) {
                return *s1 - *s2;
            }
            s1++;
            s2++;
        }
    }
    else {
        int x = (a < b ? a : b);
        for (s1; s1 < p1 + x+1  ; ) {

            if (*s1 != *s2) {
                return *s1 - *s2;
            }
            s1++;
            s2++;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strcasencmp(const char *s1, const char *s2, const int len)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (s1 == NULL && s2 != NULL) {
        return -1;
    }
    if (s2 == NULL && s1 != NULL) {
        return 1;
    }
    if (s2 == NULL && s1 == NULL) {
        return 0;
    }
    int a, b;
    a = tj_strlen(s1);
    b = tj_strlen(s2);
    const char* p = s1;
    if (len <= a && len <= b) {
        for (s1; s1 < p + len;) {
            char temp1 = *s1, temp2 = *s2;
            if (*s1 != *s2) {
                if (*s1 >= 'A' && *s1 <= 'Z') {
                    temp1 = *s1 - ('A' - 'a');
                }
                if (*s2 >= 'A' && *s2 <= 'Z') {
                    temp2 = *s2 - ('A' - 'a');
                }
                if (temp1 != temp2) {
                    return temp1 - temp2;
                }
                else {
                    s1++;
                    s2++;
                    continue;
                }
            }
            s1++;
            s2++;
        }
    }
    else {
        int x = (a < b ? a : b);
        for (s1; s1 < p + x +1;) {
            if (*s1 != *s2) {
                char temp1 = *s1, temp2 = *s2;
                if (*s1 >= 'A' && *s1 <= 'Z') {
                    temp1 = *s1 - ('A' - 'a');
                }
                if (*s2 >= 'A' && *s2 <= 'Z') {
                    temp2 = *s2 - ('A' - 'a');
                }
                if (temp1 != temp2) {
                    return temp1 - temp2;
                }
                else {
                    s1++;
                    s2++;
                    continue;
                }
            }
            s1++;
            s2++;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strupr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return NULL;
    }
    char* p = str;
    
    for (p; *p; p++) {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p + ('A' - 'a');
        }
    }
    
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strlwr(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return NULL;
    }
    char* p = str;
    for (p; *p; p++) {
        if (*p >= 'A' && *p <= 'Z') {
            *p = *p - ('A' - 'a');
        }
    }
    return str;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    const char* p = str;
    for (str; *str; str++) {
        if (*str == ch) {
            return str - p + 1;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL||substr==NULL) {
        return 0;
    }
    int a = tj_strlen(str);
    int b = tj_strlen(substr);
    const char* start = str;
    for (str; *str;str++) {
        if (*substr == *str) {
            const char* p = str;
            const char* p2 = substr;
            for (substr; *substr; substr++,str++) {
                if (*substr != *str) {
                    substr = p2;
                    str = p;
                    break;
                }
                if (*(substr + 1) == 0)
                    return p - start + 1;
            }
        }

    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrchr(const char *str, const char ch)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL) {
        return 0;
    }
    int a = tj_strlen(str);
    const char* p = str + a;
    for (p-=1; p>=str; p--) {
        if (*p == ch) {
            return p- str + 1;
        }
    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int tj_strrstr(const char *str, const char *substr)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (str == NULL||substr==NULL) {
        return 0;
    }
    int a = tj_strlen(str);
    int b = tj_strlen(substr);
    const char* end = str + a;
    const char* end2 = substr + b;
    for (end-=1; end >= str; end--) {
        if (*(end2-1) == *(end)) {
            const char* p = end;
            for (end2 -= 1; end2 >= substr; end2--,end--) {
                if (*end2 != *end) {
                    end2 = substr + b;
                    end = p;
                    break;
                }
                if (end2 == substr) {
                    return p - str - b + 2;
                }
            }
        }

    }
    return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
char *tj_strrev(char *str)
{
    /* ע�⣺�����ڲ��������κ���ʽ�����飨������̬���飩 */
    if (tj_strlen(str) != 0) {
        char* start = str;
        char * end = str + tj_strlen(str) - 1;
        char temp;
        while (start < end) {
            temp = *start;
            *start = *end;
            *end = temp;
            start++;
            end--;
        }
    }
    return str;
}
