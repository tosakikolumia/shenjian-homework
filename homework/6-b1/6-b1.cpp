/* 2351753 ��08 �Ʊ��� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;
	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s (str);
	p = str;
	pa = a;
	while (*p!=0) {
		is_num = 0;
		if (*p >= '0' && *p <= '9') {
			*pa = *p-'0';
			for (p+=1; *p >= '0' && *p <= '9'; p++) {
				*pa = *pa * 10 + *p-'0';
			}
			pa++;
			is_num = 1;
		}
		if (is_num == 0) {
			p++;
		}
	}
	pnum = a;
	cout << "����" << pa-a << "������" << endl;
	for (pnum; pnum<pa; pnum++) {
		cout << *pnum << " ";
	}
	cout << endl;
	return 0;
}