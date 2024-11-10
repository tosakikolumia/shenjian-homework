/* 2351753 信08 黄保翔 */
#include <iostream>
using namespace std;
int main() {
	cout << "请输入成绩（最多1000个），负数结束输入" << endl;
	int number[1000];
	int score[101][2];
	int i = 0, j = 0;
	bool leap = 1;
	for (j = 0; j < 101; j++) {
		score[j][0] = j;  // 存储数字本身   
		score[j][1] = 0;
	}
	for (i = 0; i < 1000; i++) {
		cin >> number[i];
		if (number[i] < 0) {
			leap = 0;
			if (i == 0) {
				cout << "无有效输入" << endl;
				return 0;
			}
			break;
		}
	}
	cin.clear();
	cin.ignore(65536, '\n');

	cout << "输入的数组为:" << endl;
	int i2 = 0;
	if (leap) {
		for (i2; i2 <= i; i2 = i2 + 1) {
			cout << number[i2]<<" ";
			if ((i2 + 1) % 10 == 0) {
				if (i2 != i) {
					cout << endl;
				}

			}
		}
	}
	else {
		for (i2; i2 < i; i2 = i2 + 1) {
			cout << number[i2]<<" ";
			if ((i2 + 1) % 10 == 0) {
				if (i2 != i - 1) {
					cout << endl;
				}
			}

		}
	}
	if ((i2 + 1) % 10 != 0) {
		cout << endl;
	}
	cout << "分数与名次的对应关系为:" << endl;

	for (i = 0; i < i2 + 1; i++) {
		for (j = 0; j < 101; j++) {
			if (number[i] == score[j][0]) {
				score[j][1]++;
			}

		}

	}
	int rank[101];
	for (i = 0; i < 101; i++) {
		rank[i] = score[i][1];
	}
	for (i = 100; i >= 0; i--) {
		if (i < 100) {
			score[i][1] = score[i + 1][1] + score[i][1];
		}
	}
	for (i = 100; i >= 0; i--) {
		if (rank[i] > 0) {
			for (j = 1; j <= rank[i]; j++) {
				cout << score[i][0] << " " << score[i][1]-rank[i]+1 << endl;
			}
		}
	}

	return 0;
}