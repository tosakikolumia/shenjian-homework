/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct student {
	int* no;//ѧ�ţ�������0��ͷ
	char* name;//�������4������(����Ƨ�֣���Ϊ˫�ֽ� GB ����)
	int* score;//�ɼ���������С����
	struct student* next;
};
int main() {
	ifstream fin;
	/*ofstream fout;*/
	fin.open("list.txt", ios::in);
	/*fout.open("13-b4-2.txt", ios::out);*/
	if (fin.is_open() == 0) {
		cout << "�������ļ�ʧ��" << endl;
		return -1;
	}
	//if (fout.is_open() == 0) {
	//	cout << "������ļ�ʧ��" << endl;
	//	fin.close();//�ر������ļ�
	//	return -1;
	//}
	student* head = NULL, * p = NULL, * q = NULL;
	int i = 0;
	while (1) {
		int temp_no;
		fin >> temp_no;
		if (temp_no == 9999999) {
			break;
		}
		else {
			if (i > 0) {
				q = p;
			}
			p = new(nothrow)student;
			if (p == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return -1;
			}
			/*----------ѧ��--------------------------*/
			p->no = new(nothrow)int;
			if (p->no == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return -1;
			}
			*p->no = temp_no;
			/*-------------����-------------------*/
			char temp_name[9];
			fin >> temp_name;
			/*scanf("%s", temp_name);*/
			temp_name[8] = '\0';//�ֶ���0
			unsigned int length = strlen(temp_name);
			p->name = new(nothrow)char[length + 1];
			if (p->name == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return -1;
			}
			strcpy(p->name, temp_name);
			/*-------------�ɼ�-------------------*/
			p->score = new(nothrow)int;
			if (p->score == NULL) {
				cout<<"�ڴ����ʧ��"<<endl;
				return -1;
			}
			fin >> *p->score;
			/*-------------����---------------*/
			p->next = NULL;
			if (i == 0) {
				head = p;
			}
			else {
				q->next = p;

			}

		}
		i++;
	}
	student* count = NULL;
	count = head;
	while (count != NULL) {//���
		/*fout << *count->no << " " << count->name << " " << *count->score << endl;*/
		cout << *count->no << " " << count->name << " " << *count->score << endl;
		count = count->next;
	}
	/*-----�ͷ��ڴ�------*/
	student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//�ͷ��ڴ�
		n = m->next;
		delete m->score;//�����ͷ��ڴ棬��ֹ�ڴ�й©
		delete m->name;
		delete m->no;
		delete[]m;
		m = n;
	}

	fin.close();
	/*fout.close();*/

	return 0;
};