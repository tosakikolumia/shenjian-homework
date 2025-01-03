/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
/* 如果有需要，此处可以添加头文件 */
#include <limits>
using namespace std;

/* 允许定义常变量/宏定义，但不允许定义全局变量 */

/* 可以添加自己需要的函数 */

/***************************************************************************
  函数名称：
  功    能：打印某个玩家的牌面信息，如果是地主，后面加标记
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int print(const char* prompt, const bool landlord, const unsigned long long player)
{
	/* 只允许定义不超过三个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	/*0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000*/
	/*大王，小王       2    A     K    Q     J   T    9   8     7    6    5   4    3   */
	cout<<prompt;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 4; j++) {
			if (player & (1ULL << (i * 4 + j))) {//判断是否有该牌
				switch (j) {
					case 0:
						cout<<'\5';//club
						break;
					case 1:
						cout<<'\4';//;//diamond
						break;
					case 2:
						cout<<'\3';//heart
						break;
					case 3:
						cout<<'\6';//spade
						break;
				}//花色
				switch (i) {
					case 0:
						cout << 3;
						break;
					case 1:
						cout << 4;
						break;
					case 2:
						cout << 5;
						break;
					case 3:
						cout << 6;
						break;
					case 4:
						cout << 7;
						break;
					case 5:
						cout << 8;
						break;
					case 6:
						cout << 9;
						break;
					case 7:
						cout << 'T';
						break;
					case 8:
						cout << 'J';
						break;
					case 9:
						cout << 'Q';
						break;
					case 10:
						cout << 'K';
						break;
					case 11:
						cout << 'A';
						break;
					case 12:
						cout << '2';
						break;
				}//数字
				if(i==13&&j==0)
					cout<<"BJ";//表示大王
				else if(i==13&&j==1)
					cout<<"RJ";//表示小王
				cout<<" ";//空格分隔
			}

		}
	}
	if (landlord) {
		cout << "(地主)" << endl;
	}
	else {
		cout << endl;
	}
	return 0;
}

/***************************************************************************
  函数名称：
  功    能：发牌（含键盘输入地主）
  输入参数：
  返 回 值：
  说    明：
 ***************************************************************************/
int deal(unsigned long long* player)
{
	/* 只允许定义不超过十个基本类型的简单变量，不能定义数组变量、结构体、string等 */
	unsigned long long allcards; //所有牌
	srand(static_cast<unsigned int>(time(NULL))); //设置随机种子
	allcards = 0xFFFFFFFFFFFFFFFFULL; //初始化所有牌
	unsigned long long mask; //掩码
	int random_num; //随机数
	int i, j; //循环变量
	for ( i = 1; i <= 17; i++) {//发17轮牌
		cout << "第" << i << "轮结束：" << endl;
		for ( j = 0; j < 3; j++) {
			random_num = rand() % 54; //随机抽取一张牌
			if (allcards & (1ULL << (random_num))) {//随机抽取一张牌，该处有牌
				mask = 1ULL << (random_num); //掩码
				player[j] |= mask; //加入玩家手牌
				allcards &= ~mask; //从所有牌中去掉该牌
			}
			else { //随机抽取一张牌，该处无牌
				j--; //重新抽牌
			}
		}
		print("甲的牌：", 0, player[0]);
		print("乙的牌：",0, player[1]);
		print("丙的牌：", 0, player[2]);
	}
	int landlord;
	while (1) {
		cout << "请选择一个地主[0-2]：" << endl;
		cin >> landlord;   //读入x的方式必须是 cin>>int型变量，不允许其他方式
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}
		else {
			if (landlord >= 0 && landlord <= 2)
				break;
		}
	}

	for (j = 0; j < 3; j++) {
		random_num = rand() % 54; //随机抽取一张牌
		if (allcards & (1ULL << (random_num))) {//随机抽取一张牌，该处有牌
			mask = 1ULL << (random_num); //掩码
			player[landlord] |= mask; //加入玩家手牌
			allcards &= ~mask; //从所有牌中去掉该牌
		}
		else { //随机抽取一张牌，该处无牌
			j--; //重新抽牌
		}
	}

	return landlord; //此处修改为选定的地主(0-2)
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数，不准修改
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //存放三个玩家的发牌信息
	int landlord; //返回0-2表示哪个玩家是地主

	cout << "按回车键开始发牌";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("甲的牌：", (landlord == 0), player[0]);
	print("乙的牌：", (landlord == 1), player[1]);
	print("丙的牌：", (landlord == 2), player[2]);

	return 0;
}