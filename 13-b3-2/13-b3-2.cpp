/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <fstream>
using namespace std;
struct student {
	int no;//ѧ�ţ�������0��ͷ
	char name[9];//�������4������(����Ƨ�֣���Ϊ˫�ֽ� GB ����)
	int score;//�ɼ���������С����
	struct student* next;
};
int main() {
	ifstream fin;
	/*ofstream fout;*/
	fin.open("list.txt", ios::in);
	/*fout.open("13-b3-2.txt", ios::out);*/
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
		fin>>temp_no;
		if (temp_no == 9999999) {
			break;
		}
		else {
			if (i > 0) {
				q = p;
			}
			p = new(nothrow)student;
			if (p == NULL) {
				cout<<"�ڴ����ʧ��"<<endl;
				return -1;
			}
			p->no = temp_no;
			fin>>p->name;
			fin>>p->score;
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
		/*fout << count->no << " " << count->name << " " << count->score << endl;*/
		cout << count->no << " " << count->name << " " << count->score << endl;
		count = count->next;
	}
	/*-----�ͷ��ڴ�------*/
	student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//�ͷ��ڴ�
		n = m->next;
		delete m;
		m = n;
	}

	fin.close();
	/*fout.close();*/
	
	return 0;
};