/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
using namespace std;
struct avaliable_options {
	const char* option;//参数
	const char* description;//描述
	int option_attech;//附加参数
	int upper_limit;//上限
	int lower_limit;//下限
	//范围

	int* default_value;//默认值
	
	int* value;//当前值
	
};	

bool isValidIPv4(const char* ip) { // 判断是否为 IP 地址
	int count = 0;     // 点的计数
	int num = 0;       // 当前段的数值
	int num_count = 0; // 段的计数
	bool lastWasDot = false; // 检测上一个字符是否为点

	for (unsigned int i = 0; i <= strlen(ip); i++) {
		char c = ip[i]; // 获取当前字符

		if (c == '.' || c == '\0') {
			if (lastWasDot) // 检查是否有连续的点
				return false; // 如果是连续的点，则返回 false

			if (num < 0 || num > 255)
				return false; // 校验当前段

			num_count++; // 增加段计数
			if (c != '\0')
				count++; // 增加点计数

			lastWasDot = true; // 设置当前字符为点
			num = 0; // 重置为下一个段
		}
		else if (c >= '0' && c <= '9') { // 检查是否为数字
			num = num * 10 + (c - '0'); // 计算数字
			lastWasDot = false; // 上一个字符不是点
		}
		else {
			return false; // 非法字符
		}
	}

	return count == 3 && num_count == 4; // 应该有 4 段 3 个点
}

int usage(const char* const procname, const  avaliable_options options[], int option_count)//打印帮助信息
{
	cout << "Usage: " << procname;
	for (int i = 0; i < option_count; i++) {
		cout << " [" << options[i].option;
		if (options[i].description != NULL) {
			cout << " " << options[i].description;
		}
		cout << "]";
	}
	cout << " " << "IP地址";
	cout<<endl;
	cout<<setw(7)<<" " << "==================================" << endl;
	cout<<setw(7) << " " << " 参数 附加参数 范围        默认值"<< endl;
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
	/*[-l 大小] [-n 数量] [-t]*/
	avaliable_options options[] = {
		{"-l", "大小",1,64000,32,NULL,NULL},
		{"-n", "数量",1,1024,1,NULL,NULL},
		{"-t", NULL,0,1,0,NULL,NULL},
		{NULL, NULL,0,0,0,NULL,NULL}
	};//可选参数 
//解析参数
	
	int option_count;
	for (option_count = 0; options[option_count].option != NULL; option_count++);
	for (int i = 0; i < option_count; i++) {//给每个参数赋值默认值分配空间
		if (options[i].option_attech == 0) {
			options[i].value = new(nothrow) int[1];
			if (options[i].value == NULL) {
				cout << "内存分配失败" << endl;
				return 0;
			}
			options[i].default_value = new(nothrow) int[1];
			if (options[i].default_value == NULL) {
				cout << "内存分配失败" << endl;
				return 0;
			}
		}
		else {
			options[i].value = new(nothrow) int[options[i].option_attech];
			if (options[i].value == NULL) {
				cout << "内存分配失败" << endl;
				return 0;
			}
			options[i].default_value = new(nothrow) int[options[i].option_attech];
			if (options[i].default_value == NULL) {
				cout << "内存分配失败" << endl;
				return 0;
			}
		}
	}
	/*这里手动赋初值*/
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
	if (isValidIPv4(argv[argc-1])) {//先判断是否为IP地址
		strcpy(ip, argv[argc-1]);
	}
	else {
		cout << "IP地址错误" << endl;
		return 0;
	}

	for (int i = 1; i < argc-1; i++) {
		if (strncmp(argv[i], "-", 1) == 0) {//判断是否为选项
			bool found = false;
			for (int j = 0; j < option_count; j++) {




				if (strcmp(argv[i], options[j].option) == 0) {
					found = true;
					if (options[j].option_attech == 0) {
						options[j].value[0] = 1;
						break;
					}
					for(int k = 0; k < options[j].option_attech; k++){//这里考虑多个附加参数
						if (strncmp(argv[i + k + 1], "-", 1) != 0 &&atoi(argv[i + k + 1]) != 0 && (i + k + 1) < argc-1) {//判断是否有附加参数
							if ((atoi(argv[i+k + 1])) >= options[j].lower_limit && (atoi(argv[i+k + 1])) <= options[j].upper_limit) {
								options[j].value[k] = atoi(argv[i + k + 1]);
							}
						}
						else {
							if (strncmp(argv[i+1], "-", 1) == 0) {//参数后面又带参数
								cout<<"参数"<<argv[i]<<"没有后续参数"<<endl;
								return 0;
							}
							else {
								cout << "参数" << argv[i] << "没有后续参数" << endl;
								return 0;
							}
						}
					}
					i += options[j].option_attech;//跳过附加参数
					break;
				}
			}
			if (!found) {
				cout << "参数"<<argv[i]<<"不存在" << endl;
				return 0;
			}

		}
		else {//不是ip，也不是指令
			cout << "参数" << argv[i] << "不是以-开头的合法参数" << endl;
			return 0;
		}

		/*--*/
	}
	cout << "参数检查通过" << endl;
	for (int i = 0; i < option_count; i++) {
		cout << options[i].option << " 参数：";
		for (int j = 0; j < options[i].option_attech; j++) {
			cout << options[i].value[j] << " ";
		}
		if(options[i].option_attech == 0)
			cout << options[i].value[0];
		cout << endl;
		
	}
	cout << "IP地址：" << ip << endl;

	/*释放内存*/
	for (int i = 0; i < option_count; i++) {
		// 释放为每个参数分配的空间
		if (options[i].option_attech == 0) {
			delete[] options[i].value;           // 释放单个 int
			delete[] options[i].default_value;   // 释放单个 int
		}
		else {
			delete[] options[i].value;            // 释放 int 数组
			delete[] options[i].default_value;    // 释放 int 数组
		}
	}

	return 0;

}

