/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int usage(const char* const procname)
{
	cout << "Usage: " << procname << " Ҫ����ѧ��/all ƥ��ѧ��/all Դ������/all ���ƶȷ�ֵ(60-100) ���(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2159999 2159998 all       80 screen" << endl;
	cout << "       " << procname << " 2159999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}
int main(int argc, char* argv[]) {
	if (argc != 6) {
		usage(argv[0]);
		return 0;
	}
	if (1) {//���ѧ��
		if (strcmp(argv[1], "all") == 0) {//ȫ�����

		}
		else {
			if (strlen(argv[1]) != 7) {//ѧ�ų��Ȳ���ȷ
				cout << "Ҫ����ѧ�Ų���7λ" << endl;
				return 0;
			}
			if (atoi(argv[1])==0) {//��������
				cout << "Ҫ����ѧ�Ų���7λ����" << endl;
				return 0;
			}
			else {//��ͷ������
				int num = atoi(argv[1]);
				if ((num / 1000000) == 0) {//����7λ����
					cout << "Ҫ����ѧ�Ų���7λ����" << endl;
					return 0;
				}
			}
		}//���ѧ�Ž���
	}
	if (1) {//���ƥ��ѧ��	
		if(strcmp(argv[2], "all") == 0)//ȫ�����
		{
		}
		else {
			if (strlen(argv[2]) != 7) {//ѧ�ų��Ȳ���ȷ
				cout << "Ҫƥ���ѧ�Ų���7λ" << endl;
				return 0;
			}
			if (atoi(argv[2])==0) {//��������
				cout << "Ҫƥ���ѧ�Ų���7λ����" << endl;
				return 0;
			}
			else {//��ͷ������
				int num = atoi(argv[2]);
				if ((num / 1000000) == 0) {//����7λ����
					cout << "Ҫƥ���ѧ�Ų���7λ����" << endl;
					return 0;
				}
			}
		}
		/*���ƥ��ѧ��Ϊall*/
		if (strcmp(argv[1], "all") == 0) {//���ѧ����all
			if (strcmp(argv[2], "all") == 0) {//ȫ�����
			}
			else {//ƥ��ѧ�Ų���all
				cout << "���ѧ����all��ƥ��ѧ�ű�����all" << endl;
				return 0;
			}
		}//���ƥ��ѧ�Ž���
	}
	if (1) {//���Դ������
		if (strcmp(argv[3], "all") == 0) {//ȫ�����
		}
		else {
			if (strlen(argv[3]) >32) {//Դ���������Ȳ���ȷ
				cout << "Դ�����ļ���������32�ֽ�" << endl;
				return 0;
			}
		}
	}
	int threshold;
	if (1) {//������ƶȷ�ֵ
		threshold = atoi(argv[4]);
		if (threshold < 60 || threshold > 100) {//���ƶȷ�ֵ����ȷ
			strcpy(argv[4], "80");//Ĭ������Ϊ80
			threshold = 80;
		}
	}
	if (1) {//������
		if (strcmp(argv[5], "screen") == 0) {//�������Ļ
			
		}
		else if (strlen(argv[5]) > 32) {//Դ���������Ȳ���ȷ
			cout << "Դ�����ļ���������32�ֽ�" << endl;
			return 0;
		}
	}
	cout<<"�������ͨ��"<<endl;
	cout << "���ѧ�ţ�"<<argv[1]<<endl;
	cout << "ƥ��ѧ�ţ�"<<argv[2]<<endl;
	cout << "Դ�ļ�����"<<argv[3]<<endl;
	cout << "ƥ����ֵ��" << threshold << endl;
	cout << "���Ŀ�꣺"<<argv[5]<<endl;
	return 0;
}