/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
int usage(const char* const procname)
{
	cout << "Usage : " << procname << " --check 文件名 | --convert { wtol|ltow } 源文件名 目标文件名" << endl;
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
			fin.seekg(-2, ios::cur);//回退一个字符
			if ((c = fin.get()) == '\r')//判断是否为windows格式文件
				iswin = true;//有\r\n结尾
			else
				islinux = true;//只有\n结尾
			fin.seekg(pos);//回退到原来的位置

		}


	}
}
int main(int argc, char* argv[]) {
	if (argc == 3 || argc == 5) {}
	else
		return usage(argv[0]);
	if (strcmp(argv[1], "--check") == 0) {
		ifstream fin(argv[2], ios::binary);//以二进制方式打开文件，防止出现\r\n结尾
		if (!fin) {
			cout << "文件打开失败" << argv[2] << endl;
			return 1;
		}
		bool iswin = false;//判断是否为windows格式文件,有\r\n结尾
		bool islinux = false;//判断是否为linux格式文件，只有\n结尾
		check(fin, iswin, islinux);
		if (iswin&&!islinux)//判断是否为windows格式文件
			cout << "windows格式" << endl;
		else if (islinux&&!iswin)//判断是否为linux格式文件
			cout << "linux格式" << endl;
		else//判断是否为未知格式文件
			cout << "文件格式未知" << endl;
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
				cout << "输入文件" << argv[3] << "打开失败" << endl;
				return 1;
			}
			bool iswin = false;
			bool islinux = false;
			check(fin, iswin, islinux);//判断输入文件是否为windows格式文件
			if (!(iswin && !islinux)) {//判断是否为windows格式文件
				cout << "文件格式无法识别" << endl;
				fin.close();
				return 1;
			}
			ofstream fout(argv[4], ios::binary);
			if (!fout) {
				cout << "输出文件" << argv[4] << "打开失败" << endl;
				return 1;
			}
			char c;
			fin.clear();//清除文件状态
			fin.seekg(0, ios::beg);//回到文件开头
			while ((c = fin.get())!= EOF) {
				if (c == '\r'&& fin.peek() == '\n') {
					count++;
					continue;
				}
				fout<<c;
			}
			cout << "转换完成，去除" << count << "个0x0D" << endl;
			fout.close();
			fin.close();
			return 0;
		}
		else if (strcmp(argv[2], "ltow") == 0) {
			int count = 0;
			ifstream fin(argv[3],ios::binary);
			if (!fin) {
				cout << "文件打开失败" << argv[3] << endl;
				return 1;
			}
			bool iswin = false;
			bool islinux = false;
			check(fin, iswin, islinux);//判断输入文件是否为linux格式文件
			if (!(islinux && !iswin)) {//判断是否为linux格式文件
				cout << "文件格式无法识别" << endl;
				fin.close();
				return 1;
			}
			ofstream fout(argv[4],ios::binary);
			if (!fout) {
				cout << "文件打开失败" << argv[4] << endl;
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
			cout << "转换完成，加入" << count << "个0x0D" << endl;
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