/* 2351753 信08 黄保翔 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <math.h>  

//可按需增加需要的头文件

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
char result[256];  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/


int main()
{
	const char ch[] = "拾佰仟万亿圆角分整";
	double a;
	int ret;
	while (1) {
		printf("请输入[0-100亿)之间的数字:\n");
		ret = scanf("%lf", &a);
		if (!ret) {
			char ch;
			while ((ch = getchar()) != '\n');
		}
		else {
				break;
		}
		printf("输入错误，请重新输入\n");

	}
	printf("大写结果是:\n");
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = (int)(a / 10);//缩小，没有将该数整体扩大
	shiyi = (int)(a / 1000000000);
	yi = k % 100000000 / 10000000;
	qianwan = k % 100000000 % 10000000 / 1000000;
	baiwan = k % 100000000 % 10000000 % 1000000 / 100000;
	shiwan = k % 100000000 % 10000000 % 1000000 % 100000 / 10000;
	wan = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 / 1000;
	qian = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 / 100;
	bai = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 / 10;
	shi = k % 100000000 % 10000000 % 1000000 % 100000 % 10000 % 1000 % 100 % 10 / 1;
	d = a / 10 - k;
	yuan = (int)((int)(d * 1000+0.5) / 100);//系统函数可以直接使用，包括课上未介绍过的，具体可自行查阅
	jiao = (int)((int)(d * 1000+0.5)) % 100 / 10;
	fen = (int)((int)(d * 1000+0.5)) % 100 % 10 / 1;
	int count = 0;//记录result数组位置
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			result[count++] = chnstr[shiyi*2];
			result[count++] = chnstr[shiyi * 2+1];
			result[count++] = ch[0];//拾
			result[count++] = ch[1];
		}
		if (yi != 0) {
			result[count++] = chnstr[yi * 2];
			result[count++] = chnstr[yi * 2 + 1];
		}
		result[count++] = ch[8];//亿
		result[count++] = ch[9];
	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			result[count++] = chnstr[qianwan * 2];
			result[count++] = chnstr[qianwan * 2 + 1];
			result[count++] = ch[4];//仟
			result[count++] = ch[5];
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (baiwan != 0) {
			result[count++] = chnstr[baiwan * 2];
			result[count++] = chnstr[baiwan * 2 + 1];
	        result[count++] = ch[2];//佰
			result[count++] = ch[3];
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];

			}
		}
		if (shiwan != 0) {
			result[count++] = chnstr[shiwan * 2];
			result[count++] = chnstr[shiwan * 2 + 1];
			result[count++] = ch[0];//拾
			result[count++] = ch[1];
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (wan != 0) {
			result[count++] = chnstr[wan * 2];
			result[count++] = chnstr[wan * 2 + 1];
		}
		result[count++] = ch[6];//万
		result[count++] = ch[7];
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			result[count++] = chnstr[qian * 2];
			result[count++] = chnstr[qian * 2 + 1];
			result[count++] = ch[4];//仟
			result[count++] = ch[5];
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (bai != 0) {
			result[count++] = chnstr[bai * 2];
			result[count++] = chnstr[bai * 2 + 1];
			result[count++] = ch[2];//佰
			result[count++] = ch[3];
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (shi != 0) {
			result[count++] = chnstr[shi * 2];
			result[count++] = chnstr[shi * 2 + 1];
			result[count++] = ch[0];//拾
			result[count++] = ch[1];
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (yuan != 0) {
			result[count++] = chnstr[yuan * 2];
			result[count++] = chnstr[yuan * 2 + 1];
		}
		result[count++] = ch[10];//圆
		result[count++] = ch[11];
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			result[count++] = ch[10];//圆
			result[count++] = ch[11];
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			result[count++] = chnstr[0];//零
			result[count++] = chnstr[1];
			result[count++] = ch[10];//圆
			result[count++] = ch[11];
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			result[count++] = chnstr[jiao * 2];
			result[count++] = chnstr[jiao * 2 + 1];
			result[count++] = ch[12];//角
			result[count++] = ch[13];
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) {
				result[count++] = chnstr[0];//零
				result[count++] = chnstr[1];
			}
		}
		if (fen != 0) {
			result[count++] = chnstr[fen * 2];
			result[count++] = chnstr[fen * 2 + 1];
			result[count++] = ch[14];//分
			result[count++] = ch[15];
		}
		else {
			result[count++] = ch[16];//整
			result[count++] = ch[17];
		}
	}
	else {
		result[count++] = ch[16];//整
		result[count++] = ch[17];
	}


	printf("%s\n", result);  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
	return 0;
}