/* 2351753 计科 黄保翔 */
#include <iostream>
#include <fstream>
using namespace std;
struct student {
	int no;//学号，不考虑0开头
	char name[9];//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int score;//成绩，不考虑小数点
	struct student* next;
};
int main() {
	ifstream fin;
	/*ofstream fout;*/
	fin.open("list.txt", ios::in);
	/*fout.open("13-b3-2.txt", ios::out);*/
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
				cout<<"内存分配失败"<<endl;
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
	while (count != NULL) {//输出
		/*fout << count->no << " " << count->name << " " << count->score << endl;*/
		cout << count->no << " " << count->name << " " << count->score << endl;
		count = count->next;
	}
	/*-----释放内存------*/
	student* m = NULL, * n = NULL;
	m = head;
	while (m != NULL) {//释放内存
		n = m->next;
		delete m;
		m = n;
	}

	fin.close();
	/*fout.close();*/
	
	return 0;
};