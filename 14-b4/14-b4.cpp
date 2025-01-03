/* 2351753 �ƿ� �Ʊ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;
struct avaliable_options {
	const char* option;//����
	const char* description;//����
	int option_attech;//���Ӳ���
	int upper_limit;//����
	int lower_limit;//����
	//��Χ

	int* default_value;//Ĭ��ֵ
	
	int* value;//��ǰֵ
	
};	

bool isValidIPv4(const char* ip) { // �ж��Ƿ�Ϊ IP ��ַ
	int count = 0;     // ��ļ���
	int num = 0;       // ��ǰ�ε���ֵ
	int num_count = 0; // �εļ���
	bool lastWasDot = false; // �����һ���ַ��Ƿ�Ϊ��

	for (unsigned int i = 0; i <= strlen(ip); i++) {
		char c = ip[i]; // ��ȡ��ǰ�ַ�

		if (c == '.' || c == '\0') {
			if (lastWasDot) // ����Ƿ��������ĵ�
				return false; // ����������ĵ㣬�򷵻� false

			if (num < 0 || num > 255)
				return false; // У�鵱ǰ��

			num_count++; // ���Ӷμ���
			if (c != '\0')
				count++; // ���ӵ����

			lastWasDot = true; // ���õ�ǰ�ַ�Ϊ��
			num = 0; // ����Ϊ��һ����
		}
		else if (c >= '0' && c <= '9') { // ����Ƿ�Ϊ����
			num = num * 10 + (c - '0'); // ��������
			lastWasDot = false; // ��һ���ַ����ǵ�
		}
		else {
			return false; // �Ƿ��ַ�
		}
	}

	return count == 3 && num_count == 4; // Ӧ���� 4 �� 3 ����
}

int usage(const char* const procname, const  avaliable_options options[], int option_count)//��ӡ������Ϣ
{
	cout << "Usage: " << procname;
	for (int i = 0; i < option_count; i++) {
		cout << " [" << options[i].option;
		if (options[i].description != NULL) {
			cout << " " << options[i].description;
		}
		cout << "]";
	}
	cout << " " << "IP��ַ";
	cout<<endl;
	cout<<setw(7)<<" " << "==================================" << endl;
	cout<<setw(7) << " " << " ���� ���Ӳ��� ��Χ        Ĭ��ֵ"<< endl;
	cout<<setw(7) << " " << "==================================" << endl;
	for (int i = 0; i < option_count; i++) {
		cout << setw(8) << " ";
		cout<< setw(4) << setiosflags(ios::left) << options[i].option << " ";
		
		cout << setw(8) << setiosflags(ios::left) << options[i].option_attech << " ";
		
		char str[30];
		sprintf(str, "[%d..%d]", options[i].lower_limit, options[i].upper_limit);
		
		cout << setw(11) << setiosflags(ios::left) << str << " ";

		cout << setw(6) << setiosflags(ios::left);
		for (int j = 0; j < options[i].option_attech; j++) 
			cout << options[i].default_value[j]<<" ";
		if (options[i].option_attech == 0) {
			cout << options[i].default_value[0] << " ";
		}
		cout << endl;
	}
	cout<<setw(7)<<" "<<"=================================="<<endl;

	return 0;
}
int main(int argc, char* argv[]) {
	/*[-l ��С] [-n ����] [-t]*/
	avaliable_options options[] = {
		{"-l", "��С",1,64000,32,NULL,NULL},
		{"-n", "����",1,1024,1,NULL,NULL},
		{"-t", NULL,0,1,0,NULL,NULL},
		{NULL, NULL,0,0,0,NULL,NULL}
	};//��ѡ���� 
//��������
	
	int option_count;
	for (option_count = 0; options[option_count].option != NULL; option_count++);
	for (int i = 0; i < option_count; i++) {//��ÿ��������ֵĬ��ֵ����ռ�
		if (options[i].option_attech == 0) {
			options[i].value = new(nothrow) int[1];
			if (options[i].value == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return 0;
			}
			options[i].default_value = new(nothrow) int[1];
			if (options[i].default_value == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return 0;
			}
		}
		else {
			options[i].value = new(nothrow) int[options[i].option_attech];
			if (options[i].value == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return 0;
			}
			options[i].default_value = new(nothrow) int[options[i].option_attech];
			if (options[i].default_value == NULL) {
				cout << "�ڴ����ʧ��" << endl;
				return 0;
			}
		}
	}
	/*�����ֶ�����ֵ*/
	options[0].default_value[0] = 64;
	options[0].value[0] = 64;
	options[1].default_value[0] = 4;
	options[1].value[0] = 4;
	options[2].default_value[0] = 0;
	options[2].value[0] = 0;

	if (argc <= 1) {
		usage(argv[0], options, option_count);
		return 0;
	}

	char ip[16];
	if (isValidIPv4(argv[argc-1])) {//���ж��Ƿ�ΪIP��ַ
		strcpy(ip, argv[argc-1]);
	}
	else {
		cout << "IP��ַ����" << endl;
		return 0;
	}

	for (int i = 1; i < argc-1; i++) {
		if (strncmp(argv[i], "-", 1) == 0) {//�ж��Ƿ�Ϊѡ��
			bool found = false;
			for (int j = 0; j < option_count; j++) {




				if (strcmp(argv[i], options[j].option) == 0) {
					found = true;
					if (options[j].option_attech == 0) {
						options[j].value[0] = 1;
						break;
					}
					for(int k = 0; k < options[j].option_attech; k++){//���￼�Ƕ�����Ӳ���
						if (strncmp(argv[i + k + 1], "-", 1) != 0 &&atoi(argv[i + k + 1]) != 0 && (i + k + 1) < argc-1) {//�ж��Ƿ��и��Ӳ���
							if ((atoi(argv[i+k + 1])) >= options[j].lower_limit && (atoi(argv[i+k + 1])) <= options[j].upper_limit) {
								options[j].value[k] = atoi(argv[i + k + 1]);
							}
						}
						else {
							if (strncmp(argv[i+1], "-", 1) == 0) {//���������ִ�����
								cout<<"����"<<argv[i]<<"û�к�������"<<endl;
								return 0;
							}
							else {
								cout << "����" << argv[i] << "û�к�������" << endl;
								return 0;
							}
						}
					}
					i += options[j].option_attech;//�������Ӳ���
					break;
				}
			}
			if (!found) {
				cout << "����"<<argv[i]<<"������" << endl;
				return 0;
			}

		}
		else {//����ip��Ҳ����ָ��
			cout << "����" << argv[i] << "������-��ͷ�ĺϷ�����" << endl;
			return 0;
		}

		/*--*/
	}
	cout << "�������ͨ��" << endl;
	for (int i = 0; i < option_count; i++) {
		cout << options[i].option << " ������";
		for (int j = 0; j < options[i].option_attech; j++) {
			cout << options[i].value[j] << " ";
		}
		if(options[i].option_attech == 0)
			cout << options[i].value[0];
		cout << endl;
		
	}
	cout << "IP��ַ��" << ip << endl;

	/*�ͷ��ڴ�*/
	for (int i = 0; i < option_count; i++) {
		// �ͷ�Ϊÿ����������Ŀռ�
		if (options[i].option_attech == 0) {
			delete[] options[i].value;           // �ͷŵ��� int
			delete[] options[i].default_value;   // �ͷŵ��� int
		}
		else {
			delete[] options[i].value;            // �ͷ� int ����
			delete[] options[i].default_value;    // �ͷ� int ����
		}
	}

	return 0;

}

