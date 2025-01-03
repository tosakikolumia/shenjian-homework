/* 2351753 �ƿ� �Ʊ��� */
#include <iostream>
#include <string>
using namespace std;
template<typename T, int ROW, int COL>
class matrix {
private:
	T value[ROW][COL];
	//����֮�ⲻ������������ݳ�Ա
public:
	matrix(const T(*p)[COL]);	//���캯�����������ʼ������
	matrix();	//Ĭ�Ϲ��캯��������Ԫ��ȫ����ʼ��Ϊ0

	//����+�ĳ�Ա����ʵ�ַ�ʽ������
	matrix operator+(const matrix& m);

	friend ostream& operator<<(ostream& os, const matrix<T, ROW, COL>& m) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				os << m.value[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}

	friend istream& operator>>(istream& is, matrix<T, ROW, COL>& m) {
		for (int i = 0; i < ROW; i++) {
			for (int j = 0; j < COL; j++) {
				is >> m.value[i][j];
			}
		}
		return is;
	}

		;
};
/* ---- ������Ա����������ʵ��/��Ԫ������ʵ�֣�����+��ʵ���г�Ա����Ԫ������ʽ��Ҫ����������Ԥ������ ---- */
template<typename T, int ROW, int COL>
matrix<T, ROW, COL>::matrix(const T(*p)[COL]) {//���캯�����������ʼ������
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			value[i][j] = p[i][j];
		}
	}
}
template<typename T, int ROW, int COL>
matrix<T, ROW, COL>::matrix() {//Ĭ�Ϲ��캯��������Ԫ��ȫ����ʼ��Ϊ0
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			value[i][j] = T{};
		}
	}
}
template<typename T, int ROW, int COL>
matrix<T, ROW, COL> matrix<T, ROW, COL>::operator+(const matrix& m)
{
	T value[ROW][COL];
	matrix<T, ROW, COL> result(value);
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			result.value[i][j] = this->value[i][j] + m.value[i][j];
		}
	}
	return result;
}


