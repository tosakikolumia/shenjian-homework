/* 2351753 信08 黄保翔 */
#include <iostream>
#include <cmath>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "大写结果是:" << endl;
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen, zero=0;
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
	yuan = static_cast<int>(static_cast<int>(round(d * 1000)) / 100);//系统函数可以直接使用，包括课上未介绍过的，具体可自行查阅
	jiao = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 / 10);
	fen = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 % 10 / 1);
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {			
			daxie(shiyi, zero);
			cout << "拾";
		}

		if (yi != 0) {
			zero = (shiyi != 0);
			daxie(yi, zero);

		}
		cout << "亿";

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			daxie(qianwan, zero);
			cout << "仟";
		}
		else {
			zero = ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0));
			daxie(qianwan, zero);
		}

		if (baiwan != 0) {
			daxie(baiwan, zero);
			cout << "佰";
		}
		else {
			zero = ((shiwan != 0 || wan != 0) && qianwan != 0);
			daxie(baiwan, zero);
			
		}
		if (shiwan != 0) {
			daxie(shiwan, zero);
			cout << "拾";
		}
		else {
			zero = ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0));
			daxie(shiwan, zero);
			
		}
		if (wan != 0) {
			daxie(wan, zero);

		}
		cout << "万";
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			daxie(qian, zero);
			cout << "仟";
		}
		else {
			zero = ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0));
			daxie(qian, zero);
			
		}
		if (bai != 0) {
			daxie(bai, zero);
			cout << "佰";
		}
		else {
			zero = ((shi != 0 || yuan != 0) && qian != 0);
				daxie(bai, zero);
			
		}
		if (shi != 0) {
			daxie(shi, zero);
			cout << "拾";
		}
		else {
			zero = ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0));
			daxie(shi, zero);
			
		}
		if (yuan != 0) {
			daxie(yuan, zero);
		}
		cout << "圆";
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			cout << "圆";
		}
		else {
			zero = (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && shi == 0 && bai == 0 && yuan == 0 && jiao == 0 && fen == 0);
			daxie(yuan, zero);
			if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && shi == 0 && bai == 0 && yuan == 0 && jiao == 0 && fen == 0) {
				cout << "圆";
			}
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			daxie(jiao, zero);
			cout << "角";
		}
		else {
			zero = (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0);
			daxie(jiao, zero);
		}
		if (fen != 0) {
			daxie(fen, zero);
			cout << "分";
		}
		else {
			cout << "整";
		}
	}
	else {
		cout << "整";
	}


	cout << endl;
	
	/* 按需完成 */
	return 0;
}