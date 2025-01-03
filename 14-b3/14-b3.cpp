/* 2351753 计科 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int usage(const char* const procname)
{
	cout << "Usage: " << procname << " 要检查的学号/all 匹配学号/all 源程序名/all 相似度阀值(60-100) 输出(filename/screen)" << endl << endl;
	cout << "e.g. : " << procname << " 2159999 2159998 all       80 screen" << endl;
	cout << "       " << procname << " 2159999 all     14-b1.cpp 75 result.txt" << endl;
	cout << "       " << procname << " all     all     14-b2.cpp 80 check.dat" << endl;
	cout << "       " << procname << " all     all     all       85 screen" << endl;

	return 0;
}
int main(int argc, char* argv[]) {
	if (argc != 6) {
		usage(argv[0]);
		return 0;
	}
	if (1) {//检查学号
		if (strcmp(argv[1], "all") == 0) {//全部检查

		}
		else {
			if (strlen(argv[1]) != 7) {//学号长度不正确
				cout << "要检查的学号不是7位" << endl;
				return 0;
			}
			if (atoi(argv[1])==0) {//不是数字
				cout << "要检查的学号不是7位数字" << endl;
				return 0;
			}
			else {//开头是数字
				int num = atoi(argv[1]);
				if ((num / 1000000) == 0) {//不是7位数字
					cout << "要检查的学号不是7位数字" << endl;
					return 0;
				}
			}
		}//检查学号结束
	}
	if (1) {//检查匹配学号	
		if(strcmp(argv[2], "all") == 0)//全部检查
		{
		}
		else {
			if (strlen(argv[2]) != 7) {//学号长度不正确
				cout << "要匹配的学号不是7位" << endl;
				return 0;
			}
			if (atoi(argv[2])==0) {//不是数字
				cout << "要匹配的学号不是7位数字" << endl;
				return 0;
			}
			else {//开头是数字
				int num = atoi(argv[2]);
				if ((num / 1000000) == 0) {//不是7位数字
					cout << "要匹配的学号不是7位数字" << endl;
					return 0;
				}
			}
		}
		/*检查匹配学号为all*/
		if (strcmp(argv[1], "all") == 0) {//检查学号是all
			if (strcmp(argv[2], "all") == 0) {//全部检查
			}
			else {//匹配学号不是all
				cout << "检查学号是all，匹配学号必须是all" << endl;
				return 0;
			}
		}//检查匹配学号结束
	}
	if (1) {//检查源程序名
		if (strcmp(argv[3], "all") == 0) {//全部检查
		}
		else {
			if (strlen(argv[3]) >32) {//源程序名长度不正确
				cout << "源程序文件名超过了32字节" << endl;
				return 0;
			}
		}
	}
	int threshold;
	if (1) {//检查相似度阀值
		threshold = atoi(argv[4]);
		if (threshold < 60 || threshold > 100) {//相似度阀值不正确
			strcpy(argv[4], "80");//默认设置为80
			threshold = 80;
		}
	}
	if (1) {//检查输出
		if (strcmp(argv[5], "screen") == 0) {//输出到屏幕
			
		}
		else if (strlen(argv[5]) > 32) {//源程序名长度不正确
			cout << "源程序文件名超过了32字节" << endl;
			return 0;
		}
	}
	cout<<"参数检查通过"<<endl;
	cout << "检查学号："<<argv[1]<<endl;
	cout << "匹配学号："<<argv[2]<<endl;
	cout << "源文件名："<<argv[3]<<endl;
	cout << "匹配阈值：" << threshold << endl;
	cout << "输出目标："<<argv[5]<<endl;
	return 0;
}