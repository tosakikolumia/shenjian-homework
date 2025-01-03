/* 2351753 �ƿ� �Ʊ��� */
/* 2353123 ��Ψ�� 2353939 ���Ⱥ� 2352614 ����ɭ */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include "17-b1-TStringAdv.h"
using namespace std;

#if defined(__linux) || defined(__linux__)
#include <sys/time.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س�������";
	while (getchar() != '\n')
		;
	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	struct timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);

	return (ts.tv_sec * 1000 + ts.tv_nsec / 1000000);
}

#else
#include <Windows.h>
#include <conio.h>
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
void wait_for_enter()
{
	cout << endl << "���س���������Ctrl+C�ж�ִ��";

	char ch;
	while (1) {
		ch = _getch();
		if (ch == '\3')
			exit(-1);	//Ctrl+Cǿ���ж�
		if (ch == '\r')
			break; //����ѭ��
	}

	cout << endl << endl;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
long get_cur_msec(void)
{
	return GetTickCount(); //ȡ��ǰϵͳʱ�䣬��λ����
}

#endif

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int memory_speed_test(int op)
{
	const int MAX_TEMP = 64 * 1024;
	const int MAX_BYTES = 100 * 1024 * 1024;

	TStringAdv s1;
	int     total, len, i;
	int     MB_count, MB_prev_count;
	char* temp;
	long    t_start, t_end, t_cur, t_prev;
	char* crc_str;

	if ((temp = new(nothrow) char[MAX_TEMP]) == nullptr) {
		cout << "�޷�����" << MAX_TEMP << "�ֽڵ���ʱ�ռ䣬������ֹ��������ٴ�����" << endl;
		return -1;
	}

	cout << "�ڴ����ܲ���";
	switch (op) {
		case 0:
			cout << "(s1=s1+str��ʽ)";
			break;
		case 1:
			cout << "(s1+=str��ʽ)";
			break;
		case 2:
			cout << "(s1+=s2��ʽ)";
			break;
		default:
			cout << "���Բ��������" << endl;
			return -1;
	} //end of switch
	cout << endl;
	cout << "ע�����1���������ò�ͬ����Լ1-10���ӣ����ڴ�ľ���������100MB�ֽ�Ϊ��������" << endl;
	cout << "          2����VS2022�²���ʱ���ȴ�������������۲����й����б�����ռ�õ��ڴ�ֵ" << endl;
	cout << "          3��VS2022������ڴ�ľ�������ִ�����ʾ����ʱ���Թ۲�����������б�����ռ�õ��ڴ�ֵ" << endl;
	cout << "             - ����ȵ��ڴ�ľ��ٴ���������������ܻ���Ϊ���ڴ���޷���" << endl;
	cout << "          4��Linux�������£�ÿ����ͨ�û����������ڴ����¼ʱ����ʾ�����������ռ�ʧ��" << endl;
	cout << "             - �����ڴ����ܲ�����Windows��ͨ��������Linux����" << endl;

	//Ϊ��ֹǰ��ఴ�س����´˴���ͣ�٣���������continue���ܼ���
	while (1) {
		char tmp[80];
		cout << "������continue�����" << endl;
		cin >> tmp;
		cin.ignore(INT_MAX, '\n'); //�����س�
		if (strcmp(tmp, "continue") == 0)
			break;
	}

	crc_str = new(nothrow) char[MAX_BYTES + MAX_TEMP]; //���루100MB+64KB���ռ�
	if (crc_str == nullptr) {
		cout << "�޷�����" << MAX_BYTES + MAX_TEMP << "�ֽڵ�У��ռ䣬������ֹ��������ٴ�����" << endl;
		delete[]temp;
		return -1;
	}
	*crc_str = 0; //��Ϊ�մ�

	t_prev = t_start = get_cur_msec(); //ȡ��ǰϵͳʱ�䣬��λ����
	MB_prev_count = 0;
	srand((unsigned int)time(0));
	total = 0;
	while (1) {
		len = (MAX_TEMP / 2) + rand() % (MAX_TEMP / 2);	// ���Ƴ�����[32768..65535]֮��

		for (i = 0; i < len; i++)
			temp[i] = ' ' + rand() % 95;	//����������ַ����
		temp[len] = 0;
		total += len;
		switch (op) {
			case 0:
				s1 = s1 + temp;
				break;
			case 1:
				s1 += temp;
				break;
			case 2:
				TStringAdv s2(temp);
				s1 += s2;
				break;
		} //end of switch

		strcat(crc_str, temp);

		MB_count = s1.length() / (1024 * 1024);
		if (MB_count - MB_prev_count >= 1) {
			MB_prev_count = MB_count;

			t_cur = get_cur_msec();   //ȡ��ǰϵͳʱ��

			cout << "s1���г��ȣ�" << setw(10) << s1.length() / (1024.0 * 1024) << " MB�ֽڣ��������� " << setw(5) << len << " �ֽڣ�����ʱ"
				<< setw(10) << (t_cur - t_start) / 1000.0 << "�룬����1MB��ʱ" << setw(10) << (t_cur - t_prev) / 1000.0 << "��" << endl;
			t_prev = t_cur;
		}
		else
			cout << "s1���г��ȣ�" << setw(10) << s1.length() / (1024.0 * 1024) << " MB�ֽڣ��������� " << setw(5) << len << " �ֽ�" << endl;

		if (s1.length() == 0 || s1.length() > MAX_BYTES)	//��100MB���ڴ�ľ������
			break;
	}//end of while (1)

	t_end = get_cur_msec();   //ȡ��ǰϵͳʱ��

	cout << "time=" << (t_end - t_start) / 1000.0 << endl;

	if (s1.length() == 0) {
		cout << "�ڴ���䵽�� " << total / (1024 * 1024) << " MB�ֽں��ڴ�ľ�����������еĴ���" << endl;

#if !(defined(__linux) || defined(__linux__))
		cout << endl << "�۲�����������б�������ڴ�ռ�����..." << endl;
		wait_for_enter();
#endif
		delete[]temp;
		delete[]crc_str;
		exit(-1);
	}
	else
		cout << "�ڴ���䵽����100MB�����Խ���" << endl;

	int check1 = (s1 != crc_str);			//TStringAdv��ʽ�Ƚ������Ƿ����
	int check2 = strcmp(s1.c_str(), crc_str);	//strcmp��ʽ�Ƚ������Ƿ����

	delete[]temp;	//�ͷ���ʱ��
	delete[]crc_str; //�ͷ�У�鴮

	if (check1 || check2)
		cout << "s1�ۼ���֤������������ʵ�ֲ���" << endl;
	else {
		cout << "    ���β��Ժ�ʱ " << (t_end - t_start) / 1000.0 << "��" << endl;
		if (op == 0) {
			cout << "�ڴ����ܲ���(s1=s1+str��ʽ)" << endl;
#if !(defined(__linux) || defined(__linux__))
			cout << "    ��ʦ�Ļ�����CPU��Intel i7-9700F , �ڴ棺DDR4 2666MHz������VS2022-Debug-x86����ĳ��򣬴�Լ��ʱ150-180��" << endl;
#else
			cout << "    Linux�����������У���Լ��ʱ135-155�루�������ͬʱ���ԣ�ƫ����ܽϴ�" << endl;
#endif
		}
		else {
			cout << "�ڴ����ܲ���" << ((op == 1) ? "(s1 += str��ʽ)" : "(s1 += s2��ʽ)") << endl;
#if !(defined(__linux) || defined(__linux__))
			cout << "    ��ʦ�Ļ�����CPU��Intel i7-9400F , �ڴ棺DDR4 2666MHz������VS2022-Debug-x86����ĳ��򣬴�Լ��ʱ80-100��" << endl;
#else
			cout << "    Linux�����������У���Լ��ʱ70-90�루�������ͬʱ���ԣ�ƫ����ܽϴ�" << endl;
#endif
		}
		cout << "    ��˵������ֻ����ͬ�������µ�����ʱ����пɱ���" << endl;
		cout << "              ���ʱ�����̫�󣬳�CPU���ڴ�����ܲ����⣬���п������㷨����" << endl;

#if !(defined(__linux) || defined(__linux__))
		cout << endl << "�۲�����������б�������ڴ�ռ�����(��������115MB)..." << endl;
#endif
		wait_for_enter();
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
int main()
{
	if (1) {
		if (1) {
			const TStringAdv s1;                 //s1Ϊ��
			const TStringAdv s2 = nullptr;        //s2Ϊ��
			const TStringAdv s3(nullptr);         //s3Ϊ��
			const TStringAdv s4 = "";            //s4Ϊ��
			const TStringAdv s5("");             //s5Ϊ��
			const TStringAdv s6("teststr2");      //s6Ϊ"teststr2"
			const TStringAdv s7 = "teststr3";     //s7Ϊ"teststr3"

			cout << "������󲢳�ʼ������(nullptr���ַ���������ʼ��)" << endl;

			cout << "s1Ӧ����<EMPTY>�� ʵ�������" << s1 << endl;
			cout << "s2Ӧ����<EMPTY>�� ʵ�������" << s2 << endl;
			cout << "s3Ӧ����<EMPTY>�� ʵ�������" << s3 << endl;
			cout << "s4Ӧ����<EMPTY>�� ʵ�������" << s4 << endl;
			cout << "s5Ӧ����<EMPTY>�� ʵ�������" << s5 << endl;
			cout << "s6Ӧ����teststr2��ʵ�������" << s6 << endl;
			cout << "s7Ӧ����teststr3��ʵ�������" << s7 << endl;

			wait_for_enter();
		}

		if (1) {
			const TStringAdv s0 = "teststr1";
			const char* str1 = "teststr2";
			const char  str2[] = "teststr3";
			const char* str3 = nullptr;
			const char  str4[] = "";
			const TStringAdv s1 = s0, s2 = str1, s3 = str2, s4 = str3, s5 = str4;
			const TStringAdv s6(s0), s7(str1), s8(str2), s9(str3), s10(str4);

			cout << "������󲢳�ʼ������(TStringAdv�����ַ�ָ�롢�ַ�����)" << endl;

			cout << "s1 Ӧ����teststr1�� ʵ�������" << s1 << endl;
			cout << "s2 Ӧ����teststr2�� ʵ�������" << s2 << endl;
			cout << "s3 Ӧ����teststr3�� ʵ�������" << s3 << endl;
			cout << "s4 Ӧ����<EMPTY>��  ʵ�������" << s4 << endl;
			cout << "s5 Ӧ����<EMPTY>��  ʵ�������" << s5 << endl;
			cout << "s6 Ӧ����teststr1�� ʵ�������" << s6 << endl;
			cout << "s7 Ӧ����teststr2�� ʵ�������" << s7 << endl;
			cout << "s8 Ӧ����teststr3�� ʵ�������" << s8 << endl;
			cout << "s9 Ӧ����<EMPTY>��  ʵ�������" << s9 << endl;
			cout << "s10Ӧ����<EMPTY>��  ʵ�������" << s10 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;

			cout << "����cin����" << endl;

			cout << "���ڼ���������Hello" << endl;
			cin >> s1;
			cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

			cout << "���ڼ���������Hello 123" << endl;
			cin >> s1;
			cout << "s1Ӧ����Hello��ʵ�������" << s1 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("Hello"), s2;

			cout << "��ֵ��������" << endl;

			cout << "s1Ӧ����Hello��  ʵ�������" << s1 << endl;

			s2 = s1;
			cout << "s2Ӧ����Hello��  ʵ�������" << s2 << endl;

			s1 = "Hi";
			cout << "s1Ӧ����Hi��     ʵ�������" << s1 << endl;

			s2 = "";
			cout << "s2Ӧ����<EMPTY>��ʵ�������" << s2 << endl;

			s1 = nullptr;
			cout << "s1Ӧ����<EMPTY>��ʵ�������" << s1 << endl;

			s1 = "Hello";
			cout << "s1Ӧ����Hello��  ʵ�������" << (s1 = s1) << endl;
			cout << "s1Ӧ����Hello��  ʵ�������" << (s1 = s1 = s1 = s1 = s1) << endl;
			cout << "s1Ӧ����Hello��  ʵ�������" << (((s1 = s1) = s1) = s1) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s0, s1("tong"), s2("ji"), s3;

			cout << "����(+)����(����TStringAdv��)" << endl;

			s3 = s1 + s2;
			cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

			s3 = s2 + s1;
			cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

			s3 = s1 + s0;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = s0 + s2;
			cout << "s3ӦΪji��    ʵ�������" << s3 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("tong"), s2, s3;

			cout << "����(+)����(TStringAdv����ַ�������)" << endl;

			s3 = s1 + "ji";
			cout << "s3ӦΪtongji�� ʵ�������" << s3 << endl;

			s3 = "ji" + s1;
			cout << "s3ӦΪjitong�� ʵ�������" << s3 << endl;

			s3 = s1 + "";
			cout << "s3ӦΪtong��   ʵ�������" << s3 << endl;

			s3 = s1 + nullptr;
			cout << "s3ӦΪtong��   ʵ�������" << s3 << endl;

			s3 = "" + s1;
			cout << "s3ӦΪtong��   ʵ�������" << s3 << endl;

			s3 = nullptr + s1;
			cout << "s3ӦΪtong��   ʵ�������" << s3 << endl;

			s3 = s2 + nullptr;
			cout << "s3ӦΪ<EMPTY>��ʵ�������" << s3 << endl;

			s3 = nullptr + s2;
			cout << "s3ӦΪ<EMPTY>��ʵ�������" << s3 << endl;

			s3 = s2 + "";
			cout << "s3ӦΪ<EMPTY>��ʵ�������" << s3 << endl;

			s3 = "" + s2;
			cout << "s3ӦΪ<EMPTY>��ʵ�������" << s3 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("tong"), s3;
			const char* str1 = "ji", * str2 = "", * str3 = nullptr, * str4 = NULL;

			cout << "����(+)����(TStringAdv����ַ�ָ��)" << endl;

			s3 = s1 + str1;
			cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

			s3 = str1 + s1;
			cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

			s3 = s1 + str2;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = str2 + s1;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = s1 + str3;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = str3 + s1;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = s1 + str4;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = str4 + s1;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("tong"), s3;
			char str1[] = "ji", str2[] = "";

			cout << "����(+)����(TStringAdv����ַ�����)" << endl;

			s3 = s1 + str1;
			cout << "s3ӦΪtongji��ʵ�������" << s3 << endl;

			s3 = str1 + s1;
			cout << "s3ӦΪjitong��ʵ�������" << s3 << endl;

			s3 = s1 + str2;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			s3 = str2 + s1;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("Hello"), s3;
			char c = '!';

			cout << "����(+)����(TStringAdv����ַ�)" << endl;

			s3 = s1 + c;
			cout << "s3ӦΪHello!��ʵ�������" << s3 << endl;

			s3 = c + s1;
			cout << "s3ӦΪ!Hello��ʵ�������" << s3 << endl;

			s1 = "ello";
			cout << "s3ӦΪHello!��ʵ�������" << 'H' + s1 + c << endl;

			s1 = "hina";
			cout << "s3ӦΪChina!��ʵ�������" << (s1 = 'C' + s1 + c) << endl;

			wait_for_enter();
		}

		if (1) {
			const TStringAdv s1("��"), s3 = "��", s5 = "Ҳ";
			TStringAdv s;
			const char* str2 = "��", str4[] = "��";
			const char c = '!';

			cout << "����(+)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;
			s = s1 + str2 + s3 + str4 + s5 + c;
			cout << "sӦ���ǿ�������Ҳ!��ʵ�������" << s << endl;

			cout << "sӦ����Ҳ��������!��ʵ�������" << (s = s5 + s1 + str2 + s3 + str4[0] + str4[1] + c) << endl;
			cout << "sӦ������Ҳ������!��ʵ�������" << (s = str4 + s5 + s1.c_str() + str2 + s3 + c) << endl;
			cout << "sӦ��������Ҳ����!��ʵ�������" << (s = s3 + str4 + s5 + s1 + str2[0] + &str2[1] + c) << endl;
			cout << "sӦ����������Ҳ��!��ʵ�������" << (s = str2 + s3 + str4 + s5.c_str() + s1.c_str() + c) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("tong"), s2 = "ji", s3;

			cout << "������(+=)�򵥲���(TStringAdv���TStringAdv��)" << endl;

			s1 += s2;
			cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

			s1 = "tong";
			s2 += s1;
			cout << "s2ӦΪjitong��ʵ�������" << s2 << endl;

			s1 = "tong";
			s1 += s3;
			cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

			s1 = "tong";
			s3 += s1;
			cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;
			const char* str1 = "tong", * str2 = nullptr, * str3 = NULL, str4[] = "ji", str5[] = "";

			cout << "������(+=)�򵥲���(TStringAdv����ַ�ָ�롢�ַ����顢�ַ����������ַ�����)" << endl;

			s1 = "ji";
			s1 += str1;
			cout << "s1ӦΪjitong��ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += str2;
			cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += str3;
			cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += str4;
			cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += str5;
			cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += "ji";
			cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

			s1 = "tong";
			s1 += 'j';
			s1 += 'i';
			cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("This is a pencil"), s2("is"), s3;

			cout << "ɾ��(-)����(TStringAdv���TStringAdv��)" << endl;

			cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - s2) << endl;
			s3 = s1 - s2;
			cout << "s3ӦΪTh  a pencil��  ʵ�������" << s3 << endl;

			s1 = "This is a pencil";
			cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1 - s2 - s2 - s2 - s2 - s2 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("This is a pencil"), s2;
			const char* str1 = "is";
			const char str2[] = "is";

			cout << "ɾ��(-)����(TStringAdv���charָ�뼰����)" << endl;

			cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - str1) << endl;
			s2 = s1 - str1;
			cout << "s2ӦΪTh  a pencil��  ʵ�������" << s2 << endl;

			s1 = "This is a pencil";
			cout << "s1ӦΪTh is a pencil��ʵ�������" << (s1 = s1 - str2) << endl;
			s2 = s1 - str2;
			cout << "s2ӦΪTh  a pencil��  ʵ�������" << s2 << endl;

			s1 = "This is a pencil";
			cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1 - str1 - str1 - str1 - str1 - str1 << endl;

			s1 = "This is a pencil";
			cout << "s1ӦΪTh  a pencil��  ʵ�������" << s1 - str2 - str2 - str2 - str2 - str2 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("This is a pencil"), s2;
			char c1 = 'i';

			cout << "ɾ��(-)����(TStringAdv���char�ַ�)" << endl;

			cout << "s1ӦΪThs is a pencil��ʵ�������" << (s1 = s1 - c1) << endl;
			s2 = s1 - c1;
			cout << "s2ӦΪThs s a pencil�� ʵ�������" << s2 << endl;

			s1 = "This is a pencil";
			cout << "s2ӦΪThs s a pencl��  ʵ�������" << (s1 - c1 - c1 - c1 - c1 - c1 - c1 - c1) << endl;

			s1 = "This is a pencil";
			cout << "s1ӦΪThi is a pencil��ʵ�������" << (s1 = s1 - 's') << endl;
			s2 = s1 - 's';
			cout << "s2ӦΪThi i a pencil�� ʵ�������" << s2 << endl;

			s1 = "This is a pencil";
			cout << "s2ӦΪThi i a pencil�� ʵ�������" << (s1 - 's' - 's' - 's' - 's' - 's' - 's') << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;
			const TStringAdv s2 = "is";
			const char* str3 = "pen", str4[] = "a";
			const char c = ' ';

			cout << "��ɾ��(-=)�򵥲���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪTh is a red pencil�� ʵ�������" << (s1 -= s2) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪThis is a red cil��  ʵ�������" << (s1 -= str3) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪThis is  red pencil��ʵ�������" << (s1 -= str4) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪThisis a red pencil��ʵ�������" << (s1 -= c) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;
			const TStringAdv s2 = "is";
			const char* str3 = "pen", str4[] = "a";
			const char c = ' ';

			cout << "��ɾ��(-=)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪTh  a red pencil��   ʵ�������" << ((s1 -= s2) -= s2) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪThis is  red cil��   ʵ�������" << ((s1 -= str3) -= str4) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪThisisaredpencil��   ʵ�������" << ((((s1 -= c) -= c) -= c) -= c) << endl;

			s1 = "This is a red pencil";
			cout << "s1ӦΪTh��                 ʵ�������" << ((((((((((((s1 -= s2) -= s2) -= str3) -= str4) -= c) -= c) -= c) -= c) -= "red") -= 'c') -= 'i') -= 'l') << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("Hello"), s2;

			cout << "����(*)����(TStringAdv���int)" << endl;

			s2 = s1 * 2;
			cout << "s2ӦΪHelloHello��     ʵ�������" << s2 << endl;
			cout << "s1ӦΪHelloHelloHello��ʵ�������" << (s1 = s1 * 3) << endl;

			TStringAdv s3;
			cout << "s3ӦΪ<EMPTY>��        ʵ�������" << (s3 * 5) << endl;
			cout << "s3ӦΪ<EMPTY>��        ʵ�������" << (s3 = s3 * 5) << endl;

			int i, n = 100;
			s1 = "Hello";
			s2 = s1 * n;
			for (i = 1; i < n; i++)
				s2 = s2 - s1;
			cout << "s2ӦΪHello��          ʵ�������" << s2 << endl;

			s1 = "Hello";
			s2 = s1 * n;
			for (i = 0; i < n; i++)
				s2 = s2 - 'l';
			for (i = 0; i < n; i++)
				s2 = s2 - 'l';
			for (i = 0; i < n; i++)
				s2 = s2 - 'o';
			for (i = 0; i < n; i++)
				s2 = s2 - 'H';
			for (i = 1; i < n; i++)  //ע�⣬ֻ�����ѭ���Ǵ�1��ʼ������1��
				s2 = s2 - 'e';
			cout << "s2ӦΪe��              ʵ�������" << s2 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;

			cout << "�Ը���(*=)����(TStringAdv���int)" << endl;

			s1 = "Hello";
			cout << "s1ӦΪHelloHello��                       ʵ�������" << (s1 *= 2) << endl;
			s1 += '!';
			cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (s1 *= 3) << endl;

			s1 = "Hello";
			cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (((s1 *= 2) += '!') *= 3) << endl;

			//		�ر���ԣ����������е�ע�ͣ������������ᱨ�����������˵�����������⣬������Ԥ�ڵ����壨Ϊʲô����ϸ��!!!��
			//		cout << "s1ӦΪHelloHello!HelloHello!HelloHello!��ʵ�������" << (((s1 *= 2) + '!') *= 3) << endl;

			s1 = nullptr;
			cout << "s1ӦΪ<EMPTY>��                          ʵ�������" << (s1 *= 100) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1;

			cout << "������(+=)/��ɾ��(-=)/�Ը���(*=)�ۺϲ���" << endl;

			s1 = "Hello";
			cout << "s1ӦΪHello!Hello!Hello!��ʵ�������" << ((s1 += '!') *= 3) << endl;

			s1 = "Hello";
			cout << "s1ӦΪHeo!Heo!Heo!Heo!��  ʵ�������" << (((s1 += '!') -= "ll") *= 4) << endl;

			s1 = "Hello";
			cout << "s1ӦΪHellHello!��        ʵ�������" << (((s1 *= 2) -= 'o') += '!') << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1("This is a pencil");

			cout << "��ת(!)����" << endl;

			cout << " s1ӦΪThis is a pencil��ʵ�������" << s1 << endl;
			cout << "!s1ӦΪlicnep a si sihT��ʵ�������" << !s1 << endl;
			cout << " s1��ΪThis is a pencil��ʵ�������" << s1 << endl;

			s1 = nullptr;
			cout << " s1ӦΪ<EMPTY>��         ʵ�������" << s1 << endl;
			cout << "!s1ӦΪ<EMPTY>��         ʵ�������" << !s1 << endl;
			cout << " s1��Ϊ<EMPTY>��         ʵ�������" << s1 << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "house", s2 = "horse", s3 = "house", s4 = "", s5 = nullptr;

			cout << "�Ƚ��������(����TStringAdv��)" << endl;

			cout << "��1=" << s1 << " ��2=" << s2 << "   > ���ӦΪ1��ʵ�ʣ�" << (s1 > s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "   >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "   < ���ӦΪ0��ʵ�ʣ�" << (s1 < s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "   <=���ӦΪ0��ʵ�ʣ�" << (s1 <= s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "   ==���ӦΪ0��ʵ�ʣ�" << (s1 == s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "   !=���ӦΪ1��ʵ�ʣ�" << (s1 != s2) << endl;

			cout << "��1=" << s1 << " ��3=" << s3 << "   > ���ӦΪ0��ʵ�ʣ�" << (s1 > s3) << endl;
			cout << "��1=" << s1 << " ��3=" << s3 << "   >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s3) << endl;
			cout << "��1=" << s1 << " ��3=" << s3 << "   < ���ӦΪ0��ʵ�ʣ�" << (s1 < s3) << endl;
			cout << "��1=" << s1 << " ��3=" << s3 << "   <=���ӦΪ1��ʵ�ʣ�" << (s1 <= s3) << endl;
			cout << "��1=" << s1 << " ��3=" << s3 << "   ==���ӦΪ1��ʵ�ʣ�" << (s1 == s3) << endl;
			cout << "��1=" << s1 << " ��3=" << s3 << "   !=���ӦΪ0��ʵ�ʣ�" << (s1 != s3) << endl;

			cout << "��1=" << s1 << " ��4=" << s4 << " > ���ӦΪ1��ʵ�ʣ�" << (s1 > s4) << endl;
			cout << "��1=" << s1 << " ��4=" << s4 << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s4) << endl;
			cout << "��1=" << s1 << " ��4=" << s4 << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < s4) << endl;
			cout << "��1=" << s1 << " ��4=" << s4 << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= s4) << endl;
			cout << "��1=" << s1 << " ��4=" << s4 << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == s4) << endl;
			cout << "��1=" << s1 << " ��4=" << s4 << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != s4) << endl;

			cout << "��1=" << s1 << " ��5=" << s5 << " > ���ӦΪ1��ʵ�ʣ�" << (s1 > s5) << endl;
			cout << "��1=" << s1 << " ��5=" << s5 << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s5) << endl;
			cout << "��1=" << s1 << " ��5=" << s5 << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < s5) << endl;
			cout << "��1=" << s1 << " ��5=" << s5 << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= s5) << endl;
			cout << "��1=" << s1 << " ��5=" << s5 << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == s5) << endl;
			cout << "��1=" << s1 << " ��5=" << s5 << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != s5) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "house";

			cout << "�Ƚ��������(TStringAdv����ַ�������1)" << endl;

			cout << "��1=" << s1 << " ����=horse" << "     > ���ӦΪ1��ʵ�ʣ�" << (s1 > "horse") << endl;
			cout << "��1=" << s1 << " ����=horse" << "     >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "horse") << endl;
			cout << "��1=" << s1 << " ����=horse" << "     < ���ӦΪ0��ʵ�ʣ�" << (s1 < "horse") << endl;
			cout << "��1=" << s1 << " ����=horse" << "     <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "horse") << endl;
			cout << "��1=" << s1 << " ����=horse" << "     ==���ӦΪ0��ʵ�ʣ�" << (s1 == "horse") << endl;
			cout << "��1=" << s1 << " ����=horse" << "     !=���ӦΪ1��ʵ�ʣ�" << (s1 != "horse") << endl;

			cout << "��1=" << s1 << " ����=house" << "     > ���ӦΪ0��ʵ�ʣ�" << (s1 > "house") << endl;
			cout << "��1=" << s1 << " ����=house" << "     >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "house") << endl;
			cout << "��1=" << s1 << " ����=house" << "     < ���ӦΪ0��ʵ�ʣ�" << (s1 < "house") << endl;
			cout << "��1=" << s1 << " ����=house" << "     <=���ӦΪ1��ʵ�ʣ�" << (s1 <= "house") << endl;
			cout << "��1=" << s1 << " ����=house" << "     ==���ӦΪ1��ʵ�ʣ�" << (s1 == "house") << endl;
			cout << "��1=" << s1 << " ����=house" << "     !=���ӦΪ0��ʵ�ʣ�" << (s1 != "house") << endl;

			cout << "��1=" << s1 << " ����=" << "          > ���ӦΪ1��ʵ�ʣ�" << (s1 > "") << endl;
			cout << "��1=" << s1 << " ����=" << "          >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "") << endl;
			cout << "��1=" << s1 << " ����=" << "          < ���ӦΪ0��ʵ�ʣ�" << (s1 < "") << endl;
			cout << "��1=" << s1 << " ����=" << "          <=���ӦΪ0��ʵ�ʣ�" << (s1 <= "") << endl;
			cout << "��1=" << s1 << " ����=" << "          ==���ӦΪ0��ʵ�ʣ�" << (s1 == "") << endl;
			cout << "��1=" << s1 << " ����=" << "          !=���ӦΪ1��ʵ�ʣ�" << (s1 != "") << endl;

			cout << "��1=" << s1 << " ����=<nullptr>" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 > nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != nullptr) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = nullptr, s2 = "";

			cout << "�Ƚ��������(TStringAdv����ַ�������2)" << endl;
			/* �յ�TStringAdv��nullptr��"" ����Ϊ��ȣ������ϣ�nullptr�ǵ�ַ��""�Ǵ���û�пɱ��ԣ����Ǵ˴������⴦�� */
			cout << "��1=" << s1 << " ��2=" << s2 << "    > ���ӦΪ0��ʵ�ʣ�" << (s1 > s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "    >=���ӦΪ1��ʵ�ʣ�" << (s1 >= s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "    < ���ӦΪ0��ʵ�ʣ�" << (s1 < s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "    <=���ӦΪ1��ʵ�ʣ�" << (s1 <= s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "    ==���ӦΪ1��ʵ�ʣ�" << (s1 == s2) << endl;
			cout << "��1=" << s1 << " ��2=" << s2 << "    !=���ӦΪ0��ʵ�ʣ�" << (s1 != s2) << endl;

			cout << "��1=" << s1 << " ����=" << "          > ���ӦΪ0��ʵ�ʣ�" << (s1 > "") << endl;
			cout << "��1=" << s1 << " ����=" << "          >=���ӦΪ1��ʵ�ʣ�" << (s1 >= "") << endl;
			cout << "��1=" << s1 << " ����=" << "          < ���ӦΪ0��ʵ�ʣ�" << (s1 < "") << endl;
			cout << "��1=" << s1 << " ����=" << "          <=���ӦΪ1��ʵ�ʣ�" << (s1 <= "") << endl;
			cout << "��1=" << s1 << " ����=" << "          ==���ӦΪ1��ʵ�ʣ�" << (s1 == "") << endl;
			cout << "��1=" << s1 << " ����=" << "          !=���ӦΪ0��ʵ�ʣ�" << (s1 != "") << endl;

			cout << "��1=" << s1 << " ����=<nullptr>" << " > ���ӦΪ0��ʵ�ʣ�" << (s1 > nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " <=���ӦΪ1��ʵ�ʣ�" << (s1 <= nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " ==���ӦΪ1��ʵ�ʣ�" << (s1 == nullptr) << endl;
			cout << "��1=" << s1 << " ����=<nullptr>" << " !=���ӦΪ0��ʵ�ʣ�" << (s1 != nullptr) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "house";
			const char* str2 = "horse", * str3 = "house", * str4 = "", * str5 = nullptr, * str6 = NULL;

			cout << "�Ƚ��������(TStringAdv����ַ�ָ��)" << endl;

			cout << "��1=" << s1 << " ��2=" << str2 << "     > ���ӦΪ1��ʵ�ʣ�" << (s1 > str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << "     >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << "     < ���ӦΪ0��ʵ�ʣ�" << (s1 < str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << "     <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << "     ==���ӦΪ0��ʵ�ʣ�" << (s1 == str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << "     !=���ӦΪ1��ʵ�ʣ�" << (s1 != str2) << endl;

			cout << "��1=" << s1 << " ��3=" << str3 << "     > ���ӦΪ0��ʵ�ʣ�" << (s1 > str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << "     >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << "     < ���ӦΪ0��ʵ�ʣ�" << (s1 < str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << "     <=���ӦΪ1��ʵ�ʣ�" << (s1 <= str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << "     ==���ӦΪ1��ʵ�ʣ�" << (s1 == str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << "     !=���ӦΪ0��ʵ�ʣ�" << (s1 != str3) << endl;

			cout << "��1=" << s1 << " ��4=" << str4 << "*        > ���ӦΪ1��ʵ�ʣ�" << (s1 > str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "*        >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "*        < ���ӦΪ0��ʵ�ʣ�" << (s1 < str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "*        <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "*        ==���ӦΪ0��ʵ�ʣ�" << (s1 == str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "*        !=���ӦΪ1��ʵ�ʣ�" << (s1 != str4) << endl;

			cout << "��1=" << s1 << " ��5=<nullptr>" << " > ���ӦΪ1��ʵ�ʣ�" << (s1 > str5) << endl;
			cout << "��1=" << s1 << " ��5=<nullptr>" << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str5) << endl;
			cout << "��1=" << s1 << " ��5=<nullptr>" << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < str5) << endl;
			cout << "��1=" << s1 << " ��5=<nullptr>" << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str5) << endl;
			cout << "��1=" << s1 << " ��5=<nullptr>" << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == str5) << endl;
			cout << "��1=" << s1 << " ��5=<nullptr>" << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != str5) << endl;

			cout << "��1=" << s1 << " ��6=<NULL>" << "    > ���ӦΪ1��ʵ�ʣ�" << (s1 > str6) << endl;
			cout << "��1=" << s1 << " ��6=<NULL>" << "    >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str6) << endl;
			cout << "��1=" << s1 << " ��6=<NULL>" << "    < ���ӦΪ0��ʵ�ʣ�" << (s1 < str6) << endl;
			cout << "��1=" << s1 << " ��6=<NULL>" << "    <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str6) << endl;
			cout << "��1=" << s1 << " ��6=<NULL>" << "    ==���ӦΪ0��ʵ�ʣ�" << (s1 == str6) << endl;
			cout << "��1=" << s1 << " ��6=<NULL>" << "    !=���ӦΪ1��ʵ�ʣ�" << (s1 != str6) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "house";
			char str2[] = "horse", str3[] = "house", str4[] = "";

			cout << "�Ƚ��������(TStringAdv����ַ�����)" << endl;

			cout << "��1=" << s1 << " ��2=" << str2 << " > ���ӦΪ1��ʵ�ʣ�" << (s1 > str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << " <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << " ==���ӦΪ0��ʵ�ʣ�" << (s1 == str2) << endl;
			cout << "��1=" << s1 << " ��2=" << str2 << " !=���ӦΪ1��ʵ�ʣ�" << (s1 != str2) << endl;

			cout << "��1=" << s1 << " ��3=" << str3 << " > ���ӦΪ0��ʵ�ʣ�" << (s1 > str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << " >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << " < ���ӦΪ0��ʵ�ʣ�" << (s1 < str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << " <=���ӦΪ1��ʵ�ʣ�" << (s1 <= str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << " ==���ӦΪ1��ʵ�ʣ�" << (s1 == str3) << endl;
			cout << "��1=" << s1 << " ��3=" << str3 << " !=���ӦΪ0��ʵ�ʣ�" << (s1 != str3) << endl;

			cout << "��1=" << s1 << " ��4=" << str4 << "      > ���ӦΪ1��ʵ�ʣ�" << (s1 > str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "      >=���ӦΪ1��ʵ�ʣ�" << (s1 >= str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "      < ���ӦΪ0��ʵ�ʣ�" << (s1 < str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "      <=���ӦΪ0��ʵ�ʣ�" << (s1 <= str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "      ==���ӦΪ0��ʵ�ʣ�" << (s1 == str4) << endl;
			cout << "��1=" << s1 << " ��4=" << str4 << "      !=���ӦΪ1��ʵ�ʣ�" << (s1 != str4) << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "tong", s2;

			cout << "�󳤶Ȳ���(length()����)" << endl;

			cout << "s1Ϊtong��     ����ӦΪ4�� ʵ�ʣ�" << s1.length() << endl;
			cout << "s2Ϊ<nullptr>������ӦΪ0�� ʵ�ʣ�" << s2.length() << endl;
			s2 = s1 + "ji";
			cout << "s2Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << s2.length() << endl;

			cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << (s1 += (s2 = "ji")).length() << endl;
			cout << "��Ϊtongji��   ����ӦΪ8�� ʵ�ʣ�" << (s1 += "ji").length() << endl;
			cout << "��Ϊtongji��   ����ӦΪ12��ʵ�ʣ�" << (s2 += s1 + "ji").length() << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "tong", s2;

			cout << "�󳤶Ȳ���(TStringAdvLen()����)" << endl;

			cout << "s1Ϊtong��     ����ӦΪ4�� ʵ�ʣ�" << TStringLen(s1) << endl;
			cout << "s2Ϊ<nullptr>������ӦΪ0�� ʵ�ʣ�" << TStringLen(s2) << endl;
			cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringLen(s1 + (s2 = "ji")) << endl;
			cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringLen(s1 + "ji") << endl;
			cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringLen(s2 = s1 + "ji") << endl;
			cout << "��Ϊtong��     ����ӦΪ4�� ʵ�ʣ�" << TStringLen(s1 + nullptr) << endl;

			cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringLen(s1 += (s2 = "ji")) << endl;
			cout << "��Ϊtongji��   ����ӦΪ8�� ʵ�ʣ�" << TStringLen(s1 += "ji") << endl;
			cout << "��Ϊtongji��   ����ӦΪ12��ʵ�ʣ�" << TStringLen(s2 += s1 + "ji") << endl;

			wait_for_enter();
		}

		if (1) {
			TStringAdv s1 = "house";
			TStringAdv s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };
			int i, j;
			char ch = 'P';

			cout << "[]���������" << endl;

			cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
			for (i = 0; i < s1.length(); i++)
				cout << s1[i] << ' ';
			cout << endl << endl;

			cout << "��1��" << s1 << "�����δ�ӡ�ַ�intֵ�Ľ���ǣ���Խ�����ǰ4��3ֵ�����ţ���" << endl;
			for (i = -4; i < s1.length() + 4; i++)
				cout << int(s1[i]) << ' ';
			cout << endl << endl;

			s1[0] = s1[0] - 32;
			cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
			for (i = 0; i < s1.length(); i++)
				cout << s1[i] << ' ';
			cout << endl << endl;

			s1[1] = 'A';
			s1[2] = ch;
			ch += 32;
			s1[3] = ch;
			s1[4] = 'Y';
			cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
			for (i = 0; i < s1.length(); i++)
				cout << s1[i] << ' ';
			cout << endl << endl;

			cout << "��2������4���ַ��������δ�ӡ�ַ��Ľ���ǣ�" << endl;
			for (i = 0; i < 4; i++) {
				cout << setw(16) << s2[i] << " => ";
				for (j = 0; j < s2[i].length(); j++)
					cout << s2[i][j] << ' ';
				cout << endl;
			}
			cout << endl;

			cout << "��2������4���ַ���������ĸ��д�����δ�ӡ�ַ��Ľ���ǣ�" << endl;
			for (i = 0; i < 4; i++) {
				s2[i][0] -= 32;
				cout << setw(16) << s2[i] << " => ";
				for (j = 0; j < s2[i].length(); j++)
					cout << s2[i][j] << ' ';
				cout << endl;
			}
			cout << endl;

			wait_for_enter();
		}
	}
	/*-------------------------			TStringAdv��(2)����		-------------------------*/
	///////////assign/////////////
	if (1) {
		TStringAdv s0 = "original";
		TStringAdv s1, s2, s3;
		const char* str1 = "assign test 1";
		const char* str2 = nullptr;
		const char str3[] = "";

		cout << "assign ��������" << endl;

		// ���� assign(const TStringAdv& ts2)
		s1.assign(s0);
		cout << "s1 Ӧ����original�� ʵ�������" << s1 << endl;

		s2.assign(s1);
		cout << "s2 Ӧ����original�� ʵ�������" << s2 << endl;

		// ���� assign(const char* s)
		s3.assign(str1);
		cout << "s3 Ӧ����assign test 1�� ʵ�������" << s3 << endl;

		s3.assign(str2);
		cout << "s3 Ӧ����<EMPTY>�� ʵ�������" << s3 << endl;

		s3.assign(str3);
		cout << "s3 Ӧ����<EMPTY>�� ʵ�������" << s3 << endl;

		// ������ʽ����
		s1.assign(s2).assign("chained test");
		cout << "s1 Ӧ����chained test�� ʵ�������" << s1 << endl;

		wait_for_enter();
	}
	if (1) {
		TStringAdv s1("tong"), s2 = "ji", s3;

		cout << "������(append)�򵥲���(TStringAdv���TStringAdv��)" << endl;

		s1.append(s2);
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "tong";
		s2.append(s1);
		cout << "s2ӦΪjitong��ʵ�������" << s2 << endl;

		s1 = "tong";
		/*s1 += s3;*/
		s1.append(s3);
		cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

		s1 = "tong";
		/*s3 += s1;*/
		s3.append(s1);
		cout << "s3ӦΪtong��  ʵ�������" << s3 << endl;

		wait_for_enter();
	}

	
	if (1) {
		TStringAdv s1;
		const char* str1 = "tong", * str2 = nullptr, * str3 = NULL, str4[] = "ji", str5[] = "";

		cout << "������(append)�򵥲���(TStringAdv����ַ�ָ�롢�ַ����顢�ַ����������ַ�����)" << endl;

		s1 = "ji";
		s1.append(str1);
		cout << "s1ӦΪjitong��ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append(str2);
		cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append(str3);
		cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append(str4);
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append(str5);
		cout << "s1ӦΪtong��  ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append("ji");
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		s1 = "tong";
		s1.append('j');
		s1.append('i');
		cout << "s1ӦΪtongji��ʵ�������" << s1 << endl;

		wait_for_enter();
	}
	//////////////////////insert/////////////	
	if (1) {
		TStringAdv s1 = "original";
		TStringAdv s2 = "inserted";
		const char* str1 = "string insert";
		const char* str2 = nullptr;
		const char str3[] = "";
		char ch = 'C';

		cout << "insert ��������" << endl;

		// ���� insert(const TStringAdv& ts2, int pos)
		s1.insert(s2, 4);
		cout << "s1 Ӧ���� oriinsertedginal�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(s2, 1);
		cout << "s1 Ӧ���� insertedoriginal�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(s2, 20); // ������Χ��������Ч
		cout << "s1 Ӧ���� original�� ʵ�������" << s1 << endl;

		// ���� insert(const char* s, int pos)
		s1 = "original";
		s1.insert(str1, 9);
		cout << "s1 Ӧ���� originalstring insert�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(str1, 1);
		cout << "s1 Ӧ���� string insertoriginal�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(str2, 4); // nullptr ������Ч
		cout << "s1 Ӧ���� original�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(str3, 4); // ���ַ���������Ч
		cout << "s1 Ӧ���� original�� ʵ�������" << s1 << endl;

		// ���� insert(const char& c, int pos)
		s1 = "original";
		s1.insert(ch, 4);
		cout << "s1 Ӧ���� oriCginal�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert(ch, 20); // ������Χ��������Ч
		cout << "s1 Ӧ���� original�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert('\0', 4); // ����β�㣬�ͷź�������
		cout << "s1 Ӧ���� ori�� ʵ�������" << s1 << endl;

		s1 = "original";
		s1.insert('\0', 1); // ���⴦���ÿ�
		cout << "s1 Ӧ���� <EMPTY>�� ʵ�������" << s1 << endl;

		wait_for_enter();
	}
	/*//////////erase/////////////*/
	if (1) {
		TStringAdv s1;
		const TStringAdv s2 = "is";
		const char* str3 = "pen", str4[] = "a";
		const char c = ' ';

		cout << "��ɾ��(erase)�򵥲���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1 = "This is a red pencil";
		/*cout << "s1ӦΪTh is a red pencil�� ʵ�������" << (s1 -= s2) << endl;*/
		cout << "s1ӦΪTh is a red pencil�� ʵ�������" << (s1.erase(s2)) << endl;
		s1 = "This is a red pencil";
		/*cout << "s1ӦΪThis is a red cil��  ʵ�������" << (s1 -= str3) << endl;*/
		cout << "s1ӦΪThis is a red cil��  ʵ�������" << (s1.erase(str3)) << endl;
		s1 = "This is a red pencil";
	/*	cout << "s1ӦΪThis is  red pencil��ʵ�������" << (s1 -= str4) << endl;*/
		cout << "s1ӦΪThis is  red pencil��  ʵ�������" << (s1.erase(str4)) << endl;
		s1 = "This is a red pencil";
		/*cout << "s1ӦΪThisis a red pencil��ʵ�������" << (s1 -= c) << endl;*/
		cout << "Thisis a red pencil��  ʵ�������" << (s1.erase(c)) << endl;
		wait_for_enter();
	}

	if (1) {
		TStringAdv s1;
		const TStringAdv s2 = "is";
		const char* str3 = "pen", str4[] = "a";
		const char c = ' ';

		cout << "��ɾ��(erase)�ۺϲ���(TStringAdv���TStringAdv�ࡢ�ַ�ָ�롢�ַ����顢�ַ�)" << endl;

		s1 = "This is a red pencil";
		/*cout << "s1ӦΪTh  a red pencil��   ʵ�������" << ((s1 -= s2) -= s2) << endl;*/
		cout << "s1ӦΪTh  a red pencil��   ʵ�������" << ((s1.erase(s2) .erase(s2) ).erase(s2)) << endl;
		s1 = "This is a red pencil";
		/*cout << "s1ӦΪThis is  red cil��   ʵ�������" << ((s1 -= str3) -= str4) << endl;*/
		cout << "s1ӦΪThisis  red cil��   ʵ�������" << ((s1.erase(str3).erase(str4)).erase(c)) << endl;
		s1 = "This is a red pencil";
		/*"cout << "s1ӦΪThisisaredpencil��   ʵ�������" << ((((s1 -= c) -= c) -= c) -= c) << endl;""*/
		cout << "s1ӦΪThisisaredpencil��   ʵ�������" << ((((s1.erase(c) .erase(c) ).erase(c)).erase(c)).erase(c)) << endl;
		s1 = "This is a red pencil";
		/*cout << "s1ӦΪTh��                 ʵ�������" << ((((((((((((s1 -= s2) -= s2) -= str3) -= str4) -= c) -= c) -= c) -= c) -= "red") -= 'c') -= 'i') -= 'l') << endl;*/
		cout << "s1ӦΪTh��                 ʵ�������" << ((((((((((((s1.erase(s2) .erase(s2) ).erase(str3).erase(str4)).erase(c)).erase(c)) .erase(c)).erase(c)) .erase("red")).erase('c')).erase('i')).erase('l')) ))<< endl;
		wait_for_enter();
	}
	/*//////////substr/////////////*/
	if (1) {
		TStringAdv s1 = "This is a substring test example";

		cout << "substr �����򵥲���" << endl;

		// ���� substr(pos, len) ���������
		cout << "s1ӦΪThis��                 ʵ�������" << s1.substr(1, 4) << endl;
		cout << "s1ӦΪsubstring��           ʵ�������" << s1.substr(11, 9) << endl;

		// ���� len ȱʡ��ȡ��β��
		cout << "s1ӦΪsubstring test example��ʵ�������" << s1.substr(11) << endl;

		// ���� pos+len �����ַ�������
		cout << "s1ӦΪtest example��         ʵ�������" << s1.substr(20, 100) << endl;

		// ���� len = 0�����ؿմ�
		cout << "s1ӦΪ<EMPTY>��              ʵ�������" << s1.substr(1, 0) << endl;

		// ���� pos ������Χ�����ؿմ�
		cout << "s1ӦΪ<EMPTY>��              ʵ�������" << s1.substr(50) << endl;

		// ���� pos �Ƿ������ؿմ�
		cout << "s1ӦΪ<EMPTY>��              ʵ�������" << s1.substr(-5) << endl;

		// ���� len �Ƿ������ؿմ�
		cout << "s1ӦΪ<EMPTY>��              ʵ�������" << s1.substr(1, -3) << endl;

		// ���Կ��ַ���
		TStringAdv s2 = "";
		cout << "���ַ���ӦΪ<EMPTY>��        ʵ�������" << s2.substr(1, 3) << endl;

		wait_for_enter();
	}

	if (1) {
		TStringAdv s1 = "Comprehensive test for substr function";

		cout << "substr �����ۺϲ���" << endl;

		// ��ʽ���ò���
		cout << "s1ӦΪtest��                 ʵ�������" << s1.substr(1, 18).substr(15, 4) << endl;

		// ��ν�ȡֱ��β��
		cout << "s1ӦΪfor��              ʵ�������"
			<< s1.substr(17).substr(4, 3) << endl;

		// ��ȡ�������ȡ���Ӵ�
		cout << "s1ӦΪr s��                 ʵ�������"
			<< s1.substr(22).substr(1, 3) << endl;

		// �����Ƿ��������ؿմ�
		cout << "s1ӦΪ<EMPTY>��             ʵ�������"
			<< s1.substr(50).substr(1, 5) << endl;

		// �ۺϽ�ȡ��߽紦��
		cout << "s1ӦΪComprehensive��       ʵ�������"
			<< s1.substr(1, 13).substr(1, 13).substr(1, 50) << endl;

		wait_for_enter();
	}

	/*------------------------------at()��������------------------------------------*/
	if (1) {
		TStringAdv s1 = "house";
		TStringAdv s2[4] = { "yangpu", "sipingroad", "tongji", "shanghai" };
		int i, j;

		cout << "at()��������" << endl;

		// 1. ��ӡ��1���ַ����޸Ĵ�1�ĵ�һ���ַ�
		cout << "��1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (i = 0; i < s1.length(); i++)
			cout << s1.at(i) << ' ';  // ʹ��at()������ȡ�ַ�
		cout << endl << endl;

		// 2. ��ӡ��1���ַ���ͨ��at()�޸�����һ���ַ�
		s1.at(0) = 'H';  // ����һ���ַ��޸�Ϊ'H'
		cout << "�޸ĺ�1��" << s1 << "�����δ�ӡ�ַ��Ľ���ǣ�";
		for (i = 0; i < s1.length(); i++)
			cout << s1.at(i) << ' ';
		cout << endl << endl;

		// 3. ����Խ�����at()��������ӡ�����
		cout << "����Խ����ʣ�at(-1)��at(length())����" << endl;
		try {
			cout << s1.at(-1) << endl; // ������Ч����
		}
		catch (const std::out_of_range& e) {
			cout << "����: " << e.what() << endl;
		}
		try {
			cout << s1.at(s1.length()) << endl; // ���ʳ�����Χ������
		}
		catch (const std::out_of_range& e) {
			cout << "����: " << e.what() << endl;
		}
		cout << endl;
		// 4. �޸Ĵ�2�����е��ַ�����ӡ���
		cout << "��2������4���ַ��������δ�ӡ�ַ��Ľ���ǣ�" << endl;
		for (i = 0; i < 4; i++) {
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++) {
				s2[i].at(j) = (j % 2 == 0) ? 'X' : s2[i].at(j);  // ÿ���ַ�����ż��λ�ø�Ϊ'X'
				cout << s2[i].at(j) << ' ';
			}
			cout << endl;
		}
		cout << endl;

		// 5. �޸Ĵ�2�����еĵ�һ���ַ�����ӡ���
		cout << "��2������4���ַ���������ĸ�޸ĺ�Ľ���ǣ�" << endl;
		for (i = 0; i < 4; i++) {
			s2[i].at(0) = 'Y';  // �޸�����ĸΪ'Y'
			cout << setw(16) << s2[i] << " => ";
			for (j = 0; j < s2[i].length(); j++)
				cout << s2[i].at(j) << ' ';
			cout << endl;
		}
		cout << endl;

		wait_for_enter();
	}
	/*------------------------------TStringAdvLen()��������--------------------------*/
	if (1) {
		TStringAdv s1 = "tong", s2;

		cout << "�󳤶Ȳ���(TStringAdvLen()����)" << endl;

		cout << "s1Ϊtong��     ����ӦΪ4�� ʵ�ʣ�" << TStringAdvLen(s1) << endl;
		cout << "s2Ϊ<nullptr>������ӦΪ0�� ʵ�ʣ�" << TStringAdvLen(s2) << endl;
		TString s3 ;
		s3 = (s1 + (s2 = "ji"));
		cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringAdvLen(s1 + (s2 = "ji")) << endl;
		cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringAdvLen(s1 + "ji") << endl;
		cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringAdvLen(s2 = s1 + "ji") << endl;
		cout << "��Ϊtong��     ����ӦΪ4�� ʵ�ʣ�" << TStringAdvLen(s1 + nullptr) << endl;

		cout << "��Ϊtongji��   ����ӦΪ6�� ʵ�ʣ�" << TStringAdvLen(s1 += (s2 = "ji")) << endl;
		cout << "��Ϊtongji��   ����ӦΪ8�� ʵ�ʣ�" << TStringAdvLen(s1 += "ji") << endl;
		cout << "��Ϊtongji��   ����ӦΪ12��ʵ�ʣ�" << TStringAdvLen(s2 += s1 + "ji") << endl;

		wait_for_enter();
	}
	if (1) {
		//memory_speed_test(0);
		//memory_speed_test(1);
		//memory_speed_test(2);
	}

#if !(defined(__linux) || defined(__linux__))
	system("pause"); //Linux����Ҫ
#endif

	return 0;
}
