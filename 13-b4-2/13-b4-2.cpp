/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
struct student {
	int* no;//学号，不考虑0开头
	char* name;//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int* score;//成绩，不考虑小数点
	struct student* next;
};
int main() {
	ifstream fin;
	/*ofstream fout;*/
	fin.open("list.txt", ios::in);
	/*fout.open("13-b4-2.txt", ios::out);*/
	if (fin.is_open() == 0) {
		cout << "打开输入文件失败" << endl;
		return -1;
	}
	//if (fout.is_open() == 0) {
	//	cout << "打开输出文件失败" << endl;
	//	fin.close();//关闭输入文件
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
				cout << "内存分配失败" << endl;
				return -1;
			}
			/*----------学号--------------------------*/
			p->no = new(nothrow)int;
			if (p->no == NULL) {
				cout << "内存分配失败" << endl;
				return -1;
			}
			*p->no = temp_no;
			/*-------------姓名-------------------*/
			char temp_name[9];
			fin >> temp_name;
			/*scanf("%s", temp_name);*/
			temp_name[8] = '\0';//手动加0
			unsigned int length = strlen(temp_name);
			p->name = new(nothrow)char[length + 1];
			if (p->name == NULL) {
				cout << "内存分配失败" << endl;
				return -1;
			}
			strcpy(p->name, temp_name);
			/*-------------成绩-------------------*/
			p->score = new(nothrow)int;
			if (p->score == NULL) {
				cout<<"内存分配失败"<<endl;
				return -1;
			}
			fin >> *p->score;
			/*-------------链接---------------*/
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
	while (count != NULL) {//输出
		/*fout << *count->no << " " << count->name << " " << *count->score << endl;*/
		cout << *count->no << " " << count->name << " " << *count->score << endl;
		count = count->next;
	}
	/*-----释放内存------*/
	student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//释放内存
		n = m->next;
		delete m->score;//反序释放内存，防止内存泄漏
		delete m->name;
		delete m->no;
		delete[]m;
		m = n;
	}

	fin.close();
	/*fout.close();*/

	return 0;
};