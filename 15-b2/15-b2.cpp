/* 2351753 �ƿ� �Ʊ��� */
/* 2351044 ������ 2352614 ����ɭ 2352018 ���� 2353123 ��Ψ�� 2353939 ���Ⱥ� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
int usage(const char* const procname)
{
	cout << "Usage : " << procname << " --infile hex��ʽ�ļ� --outfile bin��ʽ�ļ�" << endl;
	cout << "        " << procname << " --infile a.hex --outfile a.bin" << endl;
	return 0;
}
	

int main(int argc, char* argv[])
{
	if (argc!= 5) {
		return usage(argv[0]);
	}
	ifstream infile;
	ofstream outfile;

	if (strcmp(argv[1], "--infile") == 0 && strcmp(argv[3], "--outfile") == 0) {//��һ��������--infile���ڶ����������ļ�����������������--outfile�����ĸ��������ļ���
		infile.open(argv[2], ios::in);
		if (!infile.is_open()) {
			cout << "�����ļ�" << argv[2] << "��ʧ��" << endl;
			return 1;
		}
		outfile.open(argv[4], ios::out | ios::binary);
		if (!outfile.is_open()) {
			cout << "����ļ�" << argv[4] << "��ʧ��" << endl;
			return 1;
		}
	}
	else if (strcmp(argv[3], "--infile") == 0 && strcmp(argv[1], "--outfile") == 0) {//��һ��������--outfile���ڶ����������ļ�����������������--infile�����ĸ��������ļ���
		infile.open(argv[4], ios::in);
		if (!infile.is_open()) {
			cout << "�����ļ�" << argv[4] << "��ʧ��	" << endl;
			return 1;
		}
		outfile.open(argv[2], ios::out | ios::binary);
		if (!outfile.is_open()) {
			cout << "����ļ�" << argv[2] << "��ʧ��" << endl;
			return 1;
		}
	}
	else {//����֮�⣬����������Ҫ��
		return usage(argv[0]);
	}
	char buffer[1024]={ 0 };
	while (1) {
		infile.getline(buffer, 1024, '\n');
		if(strlen(buffer) !=80)//���һ�в�����80���ַ���˵�������һ�У��˳�ѭ��
			break;
		for (int i = 10; i < 60; i ++) {//�ӵ�9���ַ���ʼ��ÿ��2���ַ�ȡ��һ���ֽ�
			if(buffer[i]==' '||buffer[i]=='-')
				continue;
			int temp = 0;
			if (buffer[i] >= '0' && buffer[i] <= '9') {
				temp = buffer[i] - '0';
			}
			else if (buffer[i] >= 'a' && buffer[i] <= 'f') {
				temp = buffer[i] - 'a' + 10;
			}
			else {
				continue;
			}
			temp <<= 4;
			if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9') {
				temp |= buffer[i + 1] - '0';
			}
			else if (buffer[i + 1] >= 'a' && buffer[i + 1] <= 'f') {
				temp |= buffer[i + 1] - 'a' + 10;
			}
			else {
				continue;
			}
			outfile << char(temp);
		}
	}
	for (int i = 10; i < 60; i++) {//�ӵ�9���ַ���ʼ��ÿ��2���ַ�ȡ��һ���ֽ�,���һ�в���80���ַ������
		if (buffer[i] == ' ' || buffer[i] == '-')
			continue;
		int temp = 0;
		if (buffer[i] >= '0' && buffer[i] <= '9') {
			temp = buffer[i] - '0';
		}
		else if (buffer[i] >= 'A' && buffer[i] <= 'F') {
			temp = buffer[i] - 'A' + 10;
		}
		else if (buffer[i] >= 'a' && buffer[i] <= 'f') {
			temp = buffer[i] - 'a' + 10;
		}
		else {
			continue;
		}
		temp <<= 4;
		if (buffer[i + 1] >= '0' && buffer[i + 1] <= '9') {
			temp |= buffer[i + 1] - '0';
		}
		else if (buffer[i + 1] >= 'A' && buffer[i + 1] <= 'F') {
			temp |= buffer[i + 1] - 'A' + 10;
		}
		else if (buffer[i + 1] >= 'a' && buffer[i + 1] <= 'f') {
			temp |= buffer[i + 1] - 'a' + 10;
		}
		else {
			continue;
		}
		outfile << char(temp);
	}


	infile.close();
	outfile.close();
	return 0;	
	

}