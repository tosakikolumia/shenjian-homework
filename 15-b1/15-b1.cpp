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
	cout << "Usage : " << procname << " --infile ԭʼ�ļ� [ --outfile hex��ʽ�ļ� ]" << endl;
	cout << "        " << procname << " --infile a.docx" << endl;
	cout << "        " << procname << " --infile a.docx --outfile a.hex" << endl;

	return 0;
}
void output(char* buffer, ofstream& outfile,bool have_outfile,int space) {
	if (space > 8) {//�����ֵ�̶�λ��
		if (have_outfile)
			outfile << setw(50-space*3-2+4) << setfill(' ') << "";
		else
			cout << setw(50 - space * 3 - 2+4) << setfill(' ') << "";
	}
	else {
		if (have_outfile)
			outfile << setw(50 - space * 3 + 4) << setfill(' ') << "";
		else
			cout << setw(50 - space * 3 + 4) << setfill(' ') << "";
	}
	for (int i = 0; i < space; i++) {//�������
		if (buffer[i] >= 33 && buffer[i] <= 0x7E) {
			if (have_outfile)
				outfile << buffer[i];
			else
				cout << buffer[i];

		}
		else {
			if (have_outfile)
				outfile << ".";
			else
				cout << ".";
		}
	}
}
int main(int argc, char* argv[])
{
	bool have_outfile = false;
	if (argc == 5 || argc == 3) {// �����������ȷ
	}
	else
		return usage(argv[0]);

	ifstream infile;
	ofstream outfile;
	for (int i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--infile") == 0) {
			if (i + 1 >= argc) {// infile����û�в���
				return usage(argv[0]);
			}
			infile.open(argv[i + 1], ios::binary);
			if (!infile.is_open()) {
				cout << "�����ļ�" << argv[i + 1] <<"��ʧ��!"<< endl;
				return 1;
			}
			i++;
		}
		else if (strcmp(argv[i], "--outfile") == 0) {
			if (i + 1 >= argc) {// outfile����û�в���
				return usage(argv[0]);
			}
			outfile.open(argv[i + 1]);
			have_outfile = true;
			if (!outfile.is_open()) {
				cout << "����ļ�" << argv[i + 1] << "��ʧ��!" << endl;
				return 1;
			}
			i++;
		}
	}
	char c;
	int count = 0;
	char buffer[16] = { 0 };
	while (infile.read(&c, 1)) {
		if (count % 8 == 0&&count %16!= 0) {
			if (count > 0) {
				if (have_outfile)
					outfile << "- ";
				else
					cout << "- ";
			}
				
		}
		if (count % 16 == 0) {
			if (count > 0) {

				output(buffer, outfile, have_outfile, count % 16==0?16:count%16);// ���16���ֽ�

				if (have_outfile)
					outfile << endl;
				else
					cout << endl;
			
			}
			if (have_outfile)
				outfile << hex << nouppercase << setw(8) << setfill('0') << count << "  ";
			else
				cout << hex << nouppercase << setw(8) << setfill('0') << count << "  ";
		}
		if(have_outfile)
			outfile << hex << nouppercase << setw(2) << setfill('0') << ((int)c & 0xFF) << " ";
		else
			cout << hex << nouppercase << setw(2) << setfill('0') << ((int)c & 0xFF) << " ";
		buffer[count%16] = c;
		count++;
	}
	if (1) {
		output(buffer, outfile, have_outfile, count % 16==0?16:count%16);
		if (have_outfile) {
			outfile << endl;
		}
		else {
			cout << endl;
		}
	}
	infile.close();
	if (have_outfile)
		outfile.close();
	return 0;
}