/* 2351753 ��08 �Ʊ��� */
#include <cmath>  
#include <iostream>  
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen;
	double d;
	k = static_cast<int>(a / 10);//��С��û�н�������������
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
	yuan = static_cast<int>(static_cast<int>(round(d * 1000)) / 100);//ϵͳ��������ֱ��ʹ�ã���������δ���ܹ��ģ���������в���
	jiao = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 / 10);
	fen = static_cast<int>(static_cast<int>(round(d * 1000)) % 100 % 10 / 1);
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			switch (shiyi) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}

		if (yi != 0) {
			switch (yi) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			
		}
		cout << "��";

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			switch (qianwan) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
		}
		else {
			if ((shiwan != 0 || wan != 0||baiwan!=0) && (shiyi != 0||yi!=0)) {
				cout << "��";
			}
		}
		if (baiwan != 0) {
			switch (baiwan) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				cout << "��";
			}
		}
		if (shiwan != 0) {
			switch (shiwan) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		else {
			if ((baiwan != 0&&wan!=0) && (qianwan != 0 || baiwan != 0)) {
				cout << "��";
			}
		}
		if (wan != 0) {
			switch (wan) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}

		}
		cout << "��";
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			switch (qian) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "Ǫ";
		}
		else {
			if ((bai != 0 || yuan != 0 || shi!= 0) && (shiyi != 0 || yi != 0|| qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				cout << "��";
			}
		}
		if (bai != 0) {
			switch (bai) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				cout << "��";
			}
		}
		if (shi != 0) {
			switch (shi) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "ʰ";
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				cout << "��";
			}
		}
		if (yuan != 0) {
			switch (yuan) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
		}
		cout << "Բ";
	}
	else {
		if (shiyi != 0 || yi != 0|| qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0|| qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			
			cout << "Բ";
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			cout << "��";
			cout << "Բ";
		}
	}
		
		
	


	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			switch (jiao) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		else {
			if(shiyi!=0||yi!=0||qianwan!=0||baiwan!=0||shiwan!=0||wan!=0||qian!=0||bai!=0||shi!=0||yuan!=0)
			cout << "��";
		}
		if (fen != 0) {
			switch (fen) {
				case 1:
					cout << "Ҽ";
					break;
				case 2:
					cout << "��";
					break;
				case 3:
					cout << "��";
					break;
				case 4:
					cout << "��";
					break;
				case 5:
					cout << "��";
					break;
				case 6:
					cout << "½";
					break;
				case 7:
					cout << "��";
					break;
				case 8:
					cout << "��";
					break;
				case 9:
					cout << "��";
					break;
			}
			cout << "��";
		}
		else {
			cout << "��";
		}
	}
	else {
		cout << "��";
	}
	
	
	cout << endl;
	return 0;
}