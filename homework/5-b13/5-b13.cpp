/* 2351753 信08 黄保翔 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	int landmine[28][12] = { 0 };
	int x, y;//用于标注雷的坐标
	for (int i = 1; i <= 50; i++) {
		x = rand() % 26 + 1;
		y = rand() % 10 + 1;
		landmine[x][y] = 10;
	}

	while(1){
		int count = 0;//计数器
		for (int i = 1; i < 27; i++) {
			for (int j = 1; j < 11; j++) {
				if (landmine[i][j] == 10) {
					count++;
				}
			}
		}
		if (count < 50) {
			x = rand() % 26 + 1;
			y = rand() % 10 + 1;
			landmine[x][y] = 10;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= 26; i++) {
		for (int j = 1; j <= 10; j++) {
			int number = 0;
			if (landmine[i][j] != 10) {
				if (landmine[i - 1][j - 1] == 10) {
					number++;
				}
				if (landmine[i][j - 1] == 10) {
					number++;
				}
				if (landmine[i + 1][j - 1] == 10) {
					number++;
				}
				if (landmine[i - 1][j] == 10) {
					number++;
				}
				if (landmine[i + 1][j] == 10) {
					number++;
				}
				if (landmine[i - 1][j + 1] == 10) {
					number++;
				}
				if (landmine[i][j + 1] == 10) {
					number++;
				}
				if (landmine[i + 1][j + 1] == 10) {
					number++;
				}
				landmine[i][j] = number;
			}	
		}
	}
	for (int j = 1; j <= 10; j++) {
		for (int i = 1; i <= 26; i++) {
			if (landmine[i][j] == 10) {
				cout << "* ";
			} 
			else {
				cout << landmine[i][j] << " ";
			}
		}
		cout << endl;
	}

	return 0;
}