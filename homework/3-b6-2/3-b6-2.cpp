/* 2351753 ĞÅ08 »Æ±£Ïè */
#include <cmath>  
#include <iostream>  
using namespace std;
int main()
{
	double a;
	cout << "ÇëÊäÈë[0-100ÒÚ)Ö®¼äµÄÊı×Ö:" << endl;
	cin >> a;
	cout << "´óĞ´½á¹ûÊÇ:" << endl;
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = static_cast<int>(a / 10);//ËõĞ¡£¬Ã»ÓĞ½«¸ÃÊıÕûÌåÀ©´ó
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
	yuan = static_cast<int>(static_cast<int>(round(d * 1000)) / 100);//ÏµÍ³º¯Êı¿ÉÒÔÖ±½ÓÊ¹ÓÃ£¬°üÀ¨¿ÎÉÏÎ´½éÉÜ¹ıµÄ£¬¾ßÌå¿É×ÔĞĞ²éÔÄ
	jiao = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 / 10);
	fen = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 % 10 / 1);
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			switch (shiyi) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}

		if (yi != 0) {
			switch (yi) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			
		}
		cout << "ÒÚ";

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			switch (qianwan) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
		}
		else {
			if ((shiwan != 0 || wan != 0||baiwan!=0) && (shiyi != 0||yi!=0)) {
				cout << "Áã";
			}
		}
		if (baiwan != 0) {
			switch (baiwan) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				cout << "Áã";
			}
		}
		if (shiwan != 0) {
			switch (shiwan) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		else {
			if ((baiwan != 0&&wan!=0) && (qianwan != 0 || baiwan != 0)) {
				cout << "Áã";
			}
		}
		if (wan != 0) {
			switch (wan) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}

		}
		cout << "Íò";
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			switch (qian) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Çª";
		}
		else {
			if ((bai != 0 || yuan != 0 || shi!= 0) && (shiyi != 0 || yi != 0|| qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				cout << "Áã";
			}
		}
		if (bai != 0) {
			switch (bai) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "°Û";
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				cout << "Áã";
			}
		}
		if (shi != 0) {
			switch (shi) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "Ê°";
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				cout << "Áã";
			}
		}
		if (yuan != 0) {
			switch (yuan) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
		}
		cout << "Ô²";
	}
	else {
		if (shiyi != 0 || yi != 0|| qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0|| qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			
			cout << "Ô²";
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			cout << "Áã";
			cout << "Ô²";
		}
	}
		
		
	


	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			switch (jiao) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "½Ç";
		}
		else {
			if(shiyi!=0||yi!=0||qianwan!=0||baiwan!=0||shiwan!=0||wan!=0||qian!=0||bai!=0||shi!=0||yuan!=0)
			cout << "Áã";
		}
		if (fen != 0) {
			switch (fen) {
				case 1:
					cout << "Ò¼";
					break;
				case 2:
					cout << "·¡";
					break;
				case 3:
					cout << "Èş";
					break;
				case 4:
					cout << "ËÁ";
					break;
				case 5:
					cout << "Îé";
					break;
				case 6:
					cout << "Â½";
					break;
				case 7:
					cout << "Æâ";
					break;
				case 8:
					cout << "°Æ";
					break;
				case 9:
					cout << "¾Á";
					break;
			}
			cout << "·Ö";
		}
		else {
			cout << "Õû";
		}
	}
	else {
		cout << "Õû";
	}
	
	
	cout << endl;
	return 0;
}