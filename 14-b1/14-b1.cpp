/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;
int print_a_j(short on_off_switch) {
	for (int i = 0; i < 10; i++) {
		cout << setw(4) << setiosflags(ios::left) << char('A' + i);
	}
	cout<<endl;
	short on_of[10] = { 0 };
	short bit_x=1;//用于&运算取出对应位的值
	for (int i = 0; i < 10; i++) {
		bit_x = 1 << i;
		if (on_off_switch & bit_x) {
			on_of[i] = 1;
		}
		else {
			on_of[i] = 0;
		}
	}
	for (int i = 0; i < 10; i++) {
		if (on_of[i]) {
			cout << setw(4) << setiosflags(ios::left) << "ON";
		}
		else {
			cout << setw(4) << setiosflags(ios::left) << "OFF";
		}
	}
	cout<<endl;
	return 0;
}
int main() {
	short on_off_switch = 0;
	cout << "初始状态：0x"<< setiosflags(ios::right) << setfill('0')<<setw(4) << hex << short(on_off_switch)<<setfill(' ')<<resetiosflags(ios::right) << endl;
	print_a_j(on_off_switch);
	cout << endl;
	while (true) {
		char choice=0;//灯泡选择
		bool on_or_off=false;//开关状态
		bool is_right_input = false;//是否输入正确
		cout << "请以(\"A On /J Off\"形式输入，输入\"Q on/off\"退出)" << endl;
		char c[30];
		fgets(c, 30, stdin);
		for (int i = 0; i < 30; i++) {
			if (c[i] == ' ') {

			}
			else {
				if (c[i] >= 'a' && c[i] <= 'z') {
					c[i]=c[i]-('a'-'A');//将小写字母转为大写字母
				}
				if (((c[i] >= 'A' && c[i] <= 'J') || c[i] == 'Q') && choice == 0) {//switch的字母范围
					choice = c[i];
					continue;
				}
				if (choice != 0) {//输入了灯泡选择
					if (c[i] == 'O'&& (c[i+1] == 'N'|| c[i+1] == 'n')&& (c[i+2] == '\0'||c[i+2]=='\n'||c[i+2]=='\r')) {
						on_or_off=true;
						is_right_input = true;
						break;
					}
					else if (c[i] == 'O' && (c[i + 1] == 'F'||c[i+1] == 'f')&& (c[i + 2] == 'F'||c[i+2] == 'f')&&(c[i + 3] == '\0'||c[i+3]=='\n'||c[i+3]=='\r')) {
						is_right_input = true;
						break;
					}
					else {
						is_right_input = false;
						break;
					}
					
				}
			}
		}
		if (is_right_input == 0) {
			continue;
		}
		else {
			if (choice == 'Q') {
				break;
			}
			else {
				if (on_or_off == true) {
					on_off_switch |= (1 << (choice - 'A'));
				}
				else {
					on_off_switch &= ~(1 << (choice - 'A'));
				}
				cout << "当前状态：0x"<<setiosflags(ios::right)  << setfill('0')<<setw(4) << hex << short(on_off_switch)<<setfill(' ')<<resetiosflags(ios::right) << endl;
				print_a_j(on_off_switch);
				cout << endl;
			}
		}
	}
	return 0;
}
