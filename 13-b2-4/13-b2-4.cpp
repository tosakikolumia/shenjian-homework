/* 2351753 计科 黄保翔 */
#include <iostream>
#include <fstream>
using namespace std;
struct student {
	int no;//学号，不考虑0开头
	char name[9];//姓名，最长4个汉字(无生僻字，均为双字节 GB 汉字)
	int score;//成绩，不考虑小数点
	int rank;//名次
};


int main() {
	int num;
	ifstream fin;
	ofstream fout;
	fin.open("student.txt", ios::in);
	/*fout.open("13-b2-4_student_out_cpp.txt", ios::out);*/
	if (fin.is_open() == 0) {
		cout << "打开输入文件失败" << endl;
		return -1;
	}
	//if (fout.is_open() == 0) {
	//	cout << "打开输出文件失败" << endl;
	//	fin.close();//关闭输入文件
	//	return -1;
	//}
	fin >> num;//读取学生数量
	student* L = new(nothrow) student[num];
	if (L == NULL) {
		cout << "内存分配失败" << endl;
		return -1;
	}
	/*-----------------输入学生信息----------------*/
	for (int i = 0; i < num; i++) {
		fin >> L[i].no >> L[i].name >> L[i].score;
	}
	/*-----------------进行排序----------------*/
	for (int i = 0; i < num - 1; i++) {
		for (int j = 0; j < num - i - 1; j++) {
			if (L[j].score < L[j + 1].score) {
				student temp_score = L[j];
				L[j] = L[j + 1];
				L[j + 1] = temp_score;
			}
		}
	}
	/*-------------------将排序后的成员进行排名赋值----------------------*/
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].score == L[i - 1].score) {
			L[i].rank = L[i - 1].rank; // 相同分数名次相同
		}
		else {
			L[i].rank = i + 1; // 名次从1开始
		}
	}
	/*-------------------重新根据学号进行排名----------------------*/
	int start, end;
	for (int i = 0; i < num; ++i) {
		if (i > 0 && L[i].rank == L[i - 1].rank) {
			start = i - 1;//找到相同名次的开始位置
			int j;
			for (j = i; j < num && L[j].rank == L[j - 1].rank; j++);
			end = j - 1;//找到相同名次的结束位置
			for (int m = start; m < end; m++) {//排序
				for (int n = start; n < end - m + start; n++) {
					if (L[n].no > L[n + 1].no) {
						struct student temp_no = L[n];
						L[n] = L[n + 1];
						L[n + 1] = temp_no;
					}
				}
			}
			i = end;//跳过相同名次的后续成员
		}

	}
	/*-----------------输出学生信息----------------*/
	for (int i = 0; i < num; i++) {
		/*fout << L[i].no << " " << L[i].name << " " << L[i].score << " " << L[i].rank << endl;*/
		cout << L[i].no << " " << L[i].name << " " << L[i].score << " " << L[i].rank << endl;
	}
	fin.close();
	/*fout.close();*/
	delete[] L;
	return 0;
};