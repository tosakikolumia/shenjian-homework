/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <string>
//�ɰ���������Ҫ��ͷ�ļ�
using namespace std;

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
string result;  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
    /* --���������Ҫ������ --*/
	double a;
	const char ch[] = "ʰ��Ǫ����Բ�Ƿ���";
	while (1) {
		cout << "������[0-100��)֮�������:" << endl;
		cin >> a;   
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		else {
				break;
		}
		cout << "�����������������" << endl;

	}
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
	yuan = static_cast<int>(static_cast<int>(d * 1000+0.5) / 100);//ϵͳ��������ֱ��ʹ�ã���������δ���ܹ��ģ���������в���
	jiao = static_cast<int>(static_cast<int>(d * 1000+0.5) % 100 / 10);
	fen = static_cast<int>(static_cast<int>(d * 1000+0.5) % 100 % 10 / 1);
	int count = 0;//��¼result����λ��
	if (shiyi != 0 || yi != 0) {
		if (shiyi != 0) {
			result += chnstr[shiyi * 2];
			result += chnstr[shiyi * 2 + 1];
			result += ch[0];//ʰ
			result += ch[1];
		}
		if (yi != 0) {
			result += chnstr[yi * 2];
			result += chnstr[yi * 2 + 1];
		}
		result += ch[8];//��
		result += ch[9];
	}

	if (qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0) {
		if (qianwan != 0) {
			result += chnstr[qianwan * 2];
			result += chnstr[qianwan * 2 + 1];
			result += ch[4];//Ǫ
			result += ch[5];
		}
		else {
			if ((shiwan != 0 || wan != 0 || baiwan != 0) && (shiyi != 0 || yi != 0)) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (baiwan != 0) {
			result += chnstr[baiwan * 2];
			result += chnstr[baiwan * 2 + 1];
			result += ch[2];//��
			result += ch[3];
		}
		else {
			if ((shiwan != 0 || wan != 0) && qianwan != 0) {
				result += chnstr[0];//��
				result += chnstr[1];

			}
		}
		if (shiwan != 0) {
			result += chnstr[shiwan * 2];
			result += chnstr[shiwan * 2 + 1];
			result += ch[0];//ʰ
			result += ch[1];
		}
		else {
			if ((baiwan != 0 && wan != 0) && (qianwan != 0 || baiwan != 0)) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (wan != 0) {
			result += chnstr[wan * 2];
			result += chnstr[wan * 2 + 1];
		}
		result += ch[6];//��
		result += ch[7];
	}

	if (qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
		if (qian != 0) {
			result += chnstr[qian * 2];
			result += chnstr[qian * 2 + 1];
			result += ch[4];//Ǫ
			result += ch[5];
		}
		else {
			if ((bai != 0 || yuan != 0 || shi != 0) && (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0)) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (bai != 0) {
			result += chnstr[bai * 2];
			result += chnstr[bai * 2 + 1];
			result += ch[2];//��
			result += ch[3];
		}
		else {
			if ((shi != 0 || yuan != 0) && qian != 0) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (shi != 0) {
			result += chnstr[shi * 2];
			result += chnstr[shi * 2 + 1];
			result += ch[0];//ʰ
			result += ch[1];
		}
		else {
			if ((bai != 0 && yuan != 0) && (qian != 0 || bai != 0)) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (yuan != 0) {
			result += chnstr[yuan * 2];
			result += chnstr[yuan * 2 + 1];
		}
		result += ch[10];//Բ
		result += ch[11];
	}
	else {
		if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || shi != 0 || bai != 0 || yuan != 0) {
			result += ch[10];//Բ
			result += ch[11];
		}
		else if (jiao != 0 || fen != 0) {

		}
		else {
			result += chnstr[0];//��
			result += chnstr[1];
			result += ch[10];//Բ
			result += ch[11];
		}
	}





	if (jiao != 0 || fen != 0) {
		if (jiao != 0) {
			result += chnstr[jiao * 2];
			result += chnstr[jiao * 2 + 1];
			result += ch[12];//��
			result += ch[13];
		}
		else {
			if (shiyi != 0 || yi != 0 || qianwan != 0 || baiwan != 0 || shiwan != 0 || wan != 0 || qian != 0 || bai != 0 || shi != 0 || yuan != 0) {
				result += chnstr[0];//��
				result += chnstr[1];
			}
		}
		if (fen != 0) {
			result += chnstr[fen * 2];
			result += chnstr[fen * 2 + 1];
			result += ch[14];//��
			result += ch[15];
		}
		else {
			result += ch[16];//��
			result += ch[17];
		}
	}
	else {
		result += ch[16];//��
		result += ch[17];
	}



    cout << result << endl;  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}