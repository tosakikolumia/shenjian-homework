/* 2351753 计科 黄保翔 */
/* 2351044 崔艺洋 2352614 汤佑森 2352018 刘彦 2353123 黄唯轩 2353939 赵奕涵 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
using namespace std;
int usage(const char* const procname)
{
	cout << "Usage : " << procname << " --infile hex格式文件 --outfile bin格式文件" << endl;
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

	if (strcmp(argv[1], "--infile") == 0 && strcmp(argv[3], "--outfile") == 0) {//第一个参数是--infile，第二个参数是文件名，第三个参数是--outfile，第四个参数是文件名
		infile.open(argv[2], ios::in);
		if (!infile.is_open()) {
			cout << "输入文件" << argv[2] << "打开失败" << endl;
			return 1;
		}
		outfile.open(argv[4], ios::out | ios::binary);
		if (!outfile.is_open()) {
			cout << "输出文件" << argv[4] << "打开失败" << endl;
			return 1;
		}
	}
	else if (strcmp(argv[3], "--infile") == 0 && strcmp(argv[1], "--outfile") == 0) {//第一个参数是--outfile，第二个参数是文件名，第三个参数是--infile，第四个参数是文件名
		infile.open(argv[4], ios::in);
		if (!infile.is_open()) {
			cout << "输入文件" << argv[4] << "打开失败	" << endl;
			return 1;
		}
		outfile.open(argv[2], ios::out | ios::binary);
		if (!outfile.is_open()) {
			cout << "输出文件" << argv[2] << "打开失败" << endl;
			return 1;
		}
	}
	else {//除此之外，参数不符合要求
		return usage(argv[0]);
	}
	char buffer[1024]={ 0 };
	while (1) {
		infile.getline(buffer, 1024, '\n');
		if(strlen(buffer) !=80)//如果一行不等于80个字符，说明是最后一行，退出循环
			break;
		for (int i = 10; i < 60; i ++) {//从第9个字符开始，每隔2个字符取出一个字节
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
	for (int i = 10; i < 60; i++) {//从第9个字符开始，每隔2个字符取出一个字节,最后一行不足80个字符的情况
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