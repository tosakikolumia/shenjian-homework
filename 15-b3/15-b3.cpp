/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
int usage(const char* const procname)
{
	cout << "Usage : " << procname << " --check �ļ��� | --convert { wtol|ltow } Դ�ļ��� Ŀ���ļ���" << endl;
	cout << "        " << procname << " --check a.txt" << endl;
	cout << "        " << procname << " --convert wtol a.win.txt a.linux.txt" << endl;
	cout << "        " << procname << " --convert ltow a.linux.txt a.win.txt" << endl;
	return 0;
}
void check(ifstream& fin, bool& iswin, bool& islinux) {
	while (!fin.eof()) {
		char c;
		fin.get(c);
		streamoff pos = fin.tellg();
		if (c == '\n') {
			fin.seekg(-2, ios::cur);//����һ���ַ�
			if ((c = fin.get()) == '\r')//�ж��Ƿ�Ϊwindows��ʽ�ļ�
				iswin = true;//��\r\n��β
			else
				islinux = true;//ֻ��\n��β
			fin.seekg(pos);//���˵�ԭ����λ��

		}


	}
}
int main(int argc, char* argv[]) {
	if (argc == 3 || argc == 5) {}
	else
		return usage(argv[0]);
	if (strcmp(argv[1], "--check") == 0) {
		ifstream fin(argv[2], ios::binary);//�Զ����Ʒ�ʽ���ļ�����ֹ����\r\n��β
		if (!fin) {
			cout << "�ļ���ʧ��" << argv[2] << endl;
			return 1;
		}
		bool iswin = false;//�ж��Ƿ�Ϊwindows��ʽ�ļ�,��\r\n��β
		bool islinux = false;//�ж��Ƿ�Ϊlinux��ʽ�ļ���ֻ��\n��β
		check(fin, iswin, islinux);
		if (iswin&&!islinux)//�ж��Ƿ�Ϊwindows��ʽ�ļ�
			cout << "windows��ʽ" << endl;
		else if (islinux&&!iswin)//�ж��Ƿ�Ϊlinux��ʽ�ļ�
			cout << "linux��ʽ" << endl;
		else//�ж��Ƿ�Ϊδ֪��ʽ�ļ�
			cout << "�ļ���ʽδ֪" << endl;
		fin.close();
		return 0;
	
	}
	else if (strcmp(argv[1], "--convert") == 0) {
		if (argc!= 5)
			return usage(argv[0]);
		if (strcmp(argv[2], "wtol") == 0) {
			int count = 0;
			ifstream fin(argv[3], ios::binary);
			if (!fin) {
				cout << "�����ļ�" << argv[3] << "��ʧ��" << endl;
				return 1;
			}
			bool iswin = false;
			bool islinux = false;
			check(fin, iswin, islinux);//�ж������ļ��Ƿ�Ϊwindows��ʽ�ļ�
			if (!(iswin && !islinux)) {//�ж��Ƿ�Ϊwindows��ʽ�ļ�
				cout << "�ļ���ʽ�޷�ʶ��" << endl;
				fin.close();
				return 1;
			}
			ofstream fout(argv[4], ios::binary);
			if (!fout) {
				cout << "����ļ�" << argv[4] << "��ʧ��" << endl;
				return 1;
			}
			char c;
			fin.clear();//����ļ�״̬
			fin.seekg(0, ios::beg);//�ص��ļ���ͷ
			while ((c = fin.get())!= EOF) {
				if (c == '\r'&& fin.peek() == '\n') {
					count++;
					continue;
				}
				fout<<c;
			}
			cout << "ת����ɣ�ȥ��" << count << "��0x0D" << endl;
			fout.close();
			fin.close();
			return 0;
		}
		else if (strcmp(argv[2], "ltow") == 0) {
			int count = 0;
			ifstream fin(argv[3],ios::binary);
			if (!fin) {
				cout << "�ļ���ʧ��" << argv[3] << endl;
				return 1;
			}
			bool iswin = false;
			bool islinux = false;
			check(fin, iswin, islinux);//�ж������ļ��Ƿ�Ϊlinux��ʽ�ļ�
			if (!(islinux && !iswin)) {//�ж��Ƿ�Ϊlinux��ʽ�ļ�
				cout << "�ļ���ʽ�޷�ʶ��" << endl;
				fin.close();
				return 1;
			}
			ofstream fout(argv[4],ios::binary);
			if (!fout) {
				cout << "�ļ���ʧ��" << argv[4] << endl;
				return 1;
			}
			char c;
			fin.clear();
			fin.seekg(0, ios::beg);
			while ((c = fin.get())!= EOF) {
				if (c == '\n') {
					count++;
					fout.put('\r');
				}
					
				fout.put(c);
			}
			cout << "ת����ɣ�����" << count << "��0x0D" << endl;
			fout.close();
			fin.close();
			return 0;
		}
		else
			return usage(argv[0]);
	}
	else
		return usage(argv[0]);
		
		
	
}