/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <cmath>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
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
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "��д�����:" << endl;
	int k, shiyi, yi, qianwan, baiwan, shiwan, wan, qian, bai, shi, yuan, jiao, fen, zero=0;
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
			daxie(shiyi, zero);
			cout << "ʰ";
		}

		if (yi != 0) {
			zero = (shiyi != 0);
			daxie(yi, zero);

		}
		cout << "��";

	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			daxie(qianwan, zero);
			cout << "Ǫ";
		}
		else {
			zero = ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0));
			daxie(qianwan, zero);
		}

		if (baiwan != 0) {
			daxie(baiwan, zero);
			cout << "��";
		}
		else {
			zero = ((shiwan != 0 || wan != 0) && qianwan != 0);
			daxie(baiwan, zero);
			
		}
		if (shiwan != 0) {
			daxie(shiwan, zero);
			cout << "ʰ";
		}
		else {
			zero = ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0));
			daxie(shiwan, zero);
			
		}
		if (wan != 0) {
			daxie(wan, zero);

		}
		cout << "��";
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			daxie(qian, zero);
			cout << "Ǫ";
		}
		else {
			zero = ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0));
			daxie(qian, zero);
			
		}
		if (bai != 0) {
			daxie(bai, zero);
			cout << "��";
		}
		else {
			zero = ((shi != 0 || yuan != 0) && qian != 0);
				daxie(bai, zero);
			
		}
		if (shi != 0) {
			daxie(shi, zero);
			cout << "ʰ";
		}
		else {
			zero = ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0));
			daxie(shi, zero);
			
		}
		if (yuan != 0) {
			daxie(yuan, zero);
		}
		cout << "Բ";
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			cout << "Բ";
		}
		else {
			zero = (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && shi == 0 && bai == 0 && yuan == 0 && jiao == 0 && fen == 0);
			daxie(yuan, zero);
			if (shiyi == 0 && yi == 0 && qianwan == 0 && baiwan == 0 && shiwan == 0 && wan == 0 && qian == 0 && shi == 0 && bai == 0 && yuan == 0 && jiao == 0 && fen == 0) {
				cout << "Բ";
			}
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			daxie(jiao, zero);
			cout << "��";
		}
		else {
			zero = (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0);
			daxie(jiao, zero);
		}
		if (fen != 0) {
			daxie(fen, zero);
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
	
	/* ������� */
	return 0;
}