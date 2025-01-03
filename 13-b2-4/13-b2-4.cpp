/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <fstream>
using namespace std;
struct student {
	int no;//ѧ�ţ�������0��ͷ
	char name[9];//�������4������(����Ƨ�֣���Ϊ˫�ֽ� GB ����)
	int score;//�ɼ���������С����
	int rank;//����
};


int main() {
	int num;
	ifstream fin;
	ofstream fout;
	fin.open("student.txt", ios::in);
	/*fout.open("13-b2-4_student_out_cpp.txt", ios::out);*/
	if (fin.is_open() == 0) {
		cout << "�������ļ�ʧ��" << endl;
		return -1;
	}
	//if (fout.is_open() == 0) {
	//	cout << "������ļ�ʧ��" << endl;
	//	fin.close();//�ر������ļ�
	//	return -1;
	//}
	fin >> num;//��ȡѧ������
	student* L = new(nothrow) student[num];
	if (L == NULL) {
		cout << "�ڴ����ʧ��" << endl;
		return -1;
	}
	/*-----------------����ѧ����Ϣ----------------*/
	for (int i = 0; i < num; i++) {
		fin >> L[i].no >> L[i].name >> L[i].score;
	}
	/*-----------------��������----------------*/
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (L[j].score < L[j + 1].score) {
				student temp_score = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp_score;
			}
		}
	}
	/*-------------------�������ĳ�Ա����������ֵ----------------------*/
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].score == L[i - 1].score) {
			L[i].rank = L[i - 1].rank; // ��ͬ����������ͬ
		}
		else {
			L[i].rank = i + 1; // ���δ�1��ʼ
		}
	}
	/*-------------------���¸���ѧ�Ž�������----------------------*/
	int start, end;
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].rank == L[i - 1].rank) {
			start = i - 1;//�ҵ���ͬ���εĿ�ʼλ��
			int j;
			for (j = i; j < num && L[j].rank == L[j - 1].rank; j++);
			end = j - 1;//�ҵ���ͬ���εĽ���λ��
			for (int m = start; m < end; m++) {//����
				for (int n = start; n < end - m + start; n++) {
					if (L[n].no > L[n + 1].no) {
						struct student temp_no = L[n];
						L[n] = L[n + 1];
						L[n + 1] = temp_no;
					}
				}
			}
			i = end;//������ͬ���εĺ�����Ա
		}

	}
	/*-----------------���ѧ����Ϣ----------------*/
	for (int i = 0; i < num; i++) {
		/*fout << L[i].no << " " << L[i].name << " " << L[i].score << " " << L[i].rank << endl;*/
		cout << L[i].no << " " << L[i].name << " " << L[i].score << " " << L[i].rank << endl;
	}
	fin.close();
	/*fout.close();*/
	delete[] L;
	return 0;
};