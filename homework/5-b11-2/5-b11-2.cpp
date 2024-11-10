/* 2351753 信08 黄保翔 */
#include <iostream>
#include <string>
//可按需增加需要的头文件
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/
	double a;
	const char ch[] = "拾佰仟万亿圆角分整";
	while (1) {
		cout << "请输入[0-100亿)之间的数字:" << endl;
		cin >> a;   
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else {
				break;
		}
		cout << "输入错误，请重新输入" << endl;

	}
	cout << "大写结果是:" << endl;
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = static_cast<int>(a / 10);//缩小，没有将该数整体扩大
	shiyi = static_cast<int>(a / 1000000000);
	yi = k % 100000000 / 10000000;
	qianwan = k % 100000000 % 10000000 / 1000000;
	baiwan = k % 100000000 % 10000000 % 1000000 / 100000;
	shiwan = k % 100000000 % 10000000 % 1000000 % 100000 / 10000;
	wan = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
	qian = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
	bai = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
	shi = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;
	d = a / 10 - k;
	yuan = static_cast<int>(static_cast<int>(d * 1000+0.5) / 100);//系统函数可以直接使用，包括课上未介绍过的，具体可自行查阅
	jiao = static_cast<int>(static_cast<int>(d * 1000+0.5) % 100 / 10);
	fen = static_cast<int>(static_cast<int>(d * 1000+0.5) % 100 % 10 / 1);
	int count = 0;//记录result数组位置
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			result += chnstr[shiyi * 2];
			result += chnstr[shiyi * 2 + 1];
			result += ch[0];//拾
			result += ch[1];
		}
		if (yi != 0) {
			result += chnstr[yi * 2];
			result += chnstr[yi * 2 + 1];
		}
		result += ch[8];//亿
		result += ch[9];
	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			result += chnstr[qianwan * 2];
			result += chnstr[qianwan * 2 + 1];
			result += ch[4];//仟
			result += ch[5];
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (baiwan != 0) {
			result += chnstr[baiwan * 2];
			result += chnstr[baiwan * 2 + 1];
			result += ch[2];//佰
			result += ch[3];
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				result += chnstr[0];//零
				result += chnstr[1];

			}
		}
		if (shiwan != 0) {
			result += chnstr[shiwan * 2];
			result += chnstr[shiwan * 2 + 1];
			result += ch[0];//拾
			result += ch[1];
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (wan != 0) {
			result += chnstr[wan * 2];
			result += chnstr[wan * 2 + 1];
		}
		result += ch[6];//万
		result += ch[7];
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			result += chnstr[qian * 2];
			result += chnstr[qian * 2 + 1];
			result += ch[4];//仟
			result += ch[5];
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (bai != 0) {
			result += chnstr[bai * 2];
			result += chnstr[bai * 2 + 1];
			result += ch[2];//佰
			result += ch[3];
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (shi != 0) {
			result += chnstr[shi * 2];
			result += chnstr[shi * 2 + 1];
			result += ch[0];//拾
			result += ch[1];
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (yuan != 0) {
			result += chnstr[yuan * 2];
			result += chnstr[yuan * 2 + 1];
		}
		result += ch[10];//圆
		result += ch[11];
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			result += ch[10];//圆
			result += ch[11];
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			result += chnstr[0];//零
			result += chnstr[1];
			result += ch[10];//圆
			result += ch[11];
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			result += chnstr[jiao * 2];
			result += chnstr[jiao * 2 + 1];
			result += ch[12];//角
			result += ch[13];
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) {
				result += chnstr[0];//零
				result += chnstr[1];
			}
		}
		if (fen != 0) {
			result += chnstr[fen * 2];
			result += chnstr[fen * 2 + 1];
			result += ch[14];//分
			result += ch[15];
		}
		else {
			result += ch[16];//整
			result += ch[17];
		}
	}
	else {
		result += ch[16];//整
		result += ch[17];
	}



    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}