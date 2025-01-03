/* 2351753 计科 黄保翔 */
#include <iostream>
#include <string>
using namespace std;
template<typename T, int ROW, int COL>
class matrix {
private:
	T value[ROW][COL];
	//除此之外不允许再添加数据成员
public:
	matrix(const T(*p)[COL]);	//构造函数，用数组初始化矩阵
	matrix();	//默认构造函数，矩阵元素全部初始化为0

	//给出+的成员函数实现方式的声明
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
/* ---- 给出成员函数的体外实现/友元函数的实现，其中+的实现有成员和友元两种形式，要求放在下面的预编译中 ---- */
template<typename T, int ROW, int COL>
matrix<T, ROW, COL>::matrix(const T(*p)[COL]) {//构造函数，用数组初始化矩阵
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			value[i][j] = p[i][j];
		}
	}
}
template<typename T, int ROW, int COL>
matrix<T, ROW, COL>::matrix() {//默认构造函数，矩阵元素全部初始化为0
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


