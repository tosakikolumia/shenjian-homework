/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <time.h>
/* �������Ҫ���˴��������ͷ�ļ� */
#include <limits>
using namespace std;

/* �����峣����/�궨�壬����������ȫ�ֱ��� */

/* ��������Լ���Ҫ�ĺ��� */

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ӡĳ����ҵ�������Ϣ������ǵ���������ӱ��
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int print(const char* prompt, const bool landlord, const unsigned long long player)
{
	/* ֻ�����岻���������������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
	/*0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000*/
	/*������С��       2    A     K    Q     J   T    9   8     7    6    5   4    3   */
	cout<<prompt;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 4; j++) {
			if (player & (1ULL << (i * 4 + j))) {//�ж��Ƿ��и���
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
				}//��ɫ
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
				}//����
				if(i==13&&j==0)
					cout<<"BJ";//��ʾ����
				else if(i==13&&j==1)
					cout<<"RJ";//��ʾС��
				cout<<" ";//�ո�ָ�
			}

		}
	}
	if (landlord) {
		cout << "(����)" << endl;
	}
	else {
		cout << endl;
	}
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ����ƣ����������������
  ���������
  �� �� ֵ��
  ˵    ����
 ***************************************************************************/
int deal(unsigned long long* player)
{
	/* ֻ�����岻����ʮ���������͵ļ򵥱��������ܶ�������������ṹ�塢string�� */
	unsigned long long allcards; //������
	srand(static_cast<unsigned int>(time(NULL))); //�����������
	allcards = 0xFFFFFFFFFFFFFFFFULL; //��ʼ��������
	unsigned long long mask; //����
	int random_num; //�����
	int i, j; //ѭ������
	for ( i = 1; i <= 17; i++) {//��17����
		cout << "��" << i << "�ֽ�����" << endl;
		for ( j = 0; j < 3; j++) {
			random_num = rand() % 54; //�����ȡһ����
			if (allcards & (1ULL << (random_num))) {//�����ȡһ���ƣ��ô�����
				mask = 1ULL << (random_num); //����
				player[j] |= mask; //�����������
				allcards &= ~mask; //����������ȥ������
			}
			else { //�����ȡһ���ƣ��ô�����
				j--; //���³���
			}
		}
		print("�׵��ƣ�", 0, player[0]);
		print("�ҵ��ƣ�",0, player[1]);
		print("�����ƣ�", 0, player[2]);
	}
	int landlord;
	while (1) {
		cout << "��ѡ��һ������[0-2]��" << endl;
		cin >> landlord;   //����x�ķ�ʽ������ cin>>int�ͱ�����������������ʽ
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
		random_num = rand() % 54; //�����ȡһ����
		if (allcards & (1ULL << (random_num))) {//�����ȡһ���ƣ��ô�����
			mask = 1ULL << (random_num); //����
			player[landlord] |= mask; //�����������
			allcards &= ~mask; //����������ȥ������
		}
		else { //�����ȡһ���ƣ��ô�����
			j--; //���³���
		}
	}

	return landlord; //�˴��޸�Ϊѡ���ĵ���(0-2)
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main��������׼�޸�
 ***************************************************************************/
int main()
{
	unsigned long long player[3] = { 0 }; //���������ҵķ�����Ϣ
	int landlord; //����0-2��ʾ�ĸ�����ǵ���

	cout << "���س�����ʼ����";
	while (getchar() != '\n')
		;

	landlord = deal(player);
	print("�׵��ƣ�", (landlord == 0), player[0]);
	print("�ҵ��ƣ�", (landlord == 1), player[1]);
	print("�����ƣ�", (landlord == 2), player[2]);

	return 0;
}