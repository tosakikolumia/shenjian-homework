/* 2351753 计科 黄保翔 */
#include <iostream>
#include <iomanip>
using namespace std;

const char* sp = "=====================================";

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：每个数字宽度为8，右对齐
***************************************************************************/
template <typename T, size_t N1, size_t N2>
void matrix_print(const char* p, T(&array)[N1][N2])	//将...替换为相应内容
{
	/* 按需增加内容 */
	cout << p << endl;
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N2; j++) {
			cout << setiosflags(ios::right) << setw(8) << array[i][j];
			if (j == N2 - 1) {
				cout << endl;
			}
		}
	}
	

	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
template <typename T1, typename T2, typename T3, size_t N1, size_t N2>
void matrix_addition(T1(&t_add)[N1][N2], T2(&t1)[N1][N2],T3(&t2)[N1][N2])	//将...替换为相应内容
{
	/* 按需增加内容 */
	cout << "源矩阵1 : 行=" << N1 << " 列=" << N2 << " 占用空间=" << sizeof(t1) << "字节" << endl;
	cout << "源矩阵2 : 行=" << N1 << " 列=" << N2 << " 占用空间=" << sizeof(t2) << "字节" << endl;
	for (int i = 0; i < N1; i++) {
		for (int j = 0; j < N2; j++) {
			t_add[i][j] = t1[i][j] + t2[i][j];
		}
	}
	cout << "和矩阵  : 行=" << N1 << " 列=" << N2 << " 占用空间=" << sizeof(t_add) << "字节" << endl;
	return;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
template <typename T1, typename T2, typename T3, size_t N1, size_t N2, size_t N3>
void matrix_multiplication(T1(&t_mul)[N1][N3], T2(&t1)[N1][N2], T3(&t2)[N2][N3])	//将...替换为相应内容
{
	/* 按需增加内容 */
	for (int i = 0; i < N1; i++) {//初始化
		for (int j = 0; j < N3; j++) {
			t_mul[i][j] = 0;
		}
	}
	cout << "源矩阵1 : 行=" << N1 << " 列=" << N2 << " 占用空间=" << sizeof(t1) << "字节" << endl;
	cout << "源矩阵2 : 行=" << N2 << " 列=" << N3 << " 占用空间=" << sizeof(t2) << "字节" << endl;
	cout << "积矩阵  : 行=" << N1 << " 列=" << N3 << " 占用空间=" << sizeof(t_mul) << "字节" << endl;
	for (int i = 0; i < N1; ++i) {
		for (int j = 0; j < N3; ++j) {
			for (int k = 0; k < N2; ++k) {
				t_mul[i][j] += static_cast<T1>(t1[i][k] * t2[k][j]);
			}
		}
	}
	return;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准更改
***************************************************************************/
int main()
{
	int t1[3][4] = {
		{1,2,3,4},
		{5,6,7,8},
		{9,10,11,12}
	};
	int t2[3][4] = {
		{12,11,10,9},
		{8,7,6,5},
		{4,3,2,1}
	};
	int t3[4][2] = {
		{1, 2},
		{3, 4},
		{5, 6},
		{7, 8}
	};
	int t_add[3][4], t_mul[3][2];

	cout << sp << endl;
	matrix_print("加法运算，源矩阵1：", t1);
	matrix_print("加法运算，源矩阵2：", t2);
	matrix_addition(t_add, t1, t2);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("加法运算，和矩阵 ：", t_add);
	cout << sp << endl;
	matrix_print("乘法运算，源矩阵1：", t1);
	matrix_print("乘法运算，源矩阵2：", t3);
	matrix_multiplication(t_mul, t1, t3);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("乘法运算，积矩阵 ：", t_mul);
	cout << sp << endl;

	double d1[2][4] = {
		{1.1, 2.2, 3.3, 4.4},
		{5.5 ,6.6, 7.7, 8.8}
	};
	double d2[2][4] = {
		{8.8, 7.7, 6.6, 5.5},
		{4.4, 3.3, 2.2, 1.1}
	};
	double d_add[2][4];
	/* 不要问为什么矩阵乘法数据类型不同，故意的 */
	float f3[4][3] = {
		{12.12f, 11.11f, 10.10f},
		{9.9f, 8.8f, 7.7f},
		{6.6f, 5.5f, 4.4f},
		{3.3f, 2.2f, 1.1f}
	};
	int i_mul[2][3];

	matrix_print("加法运算，源矩阵1：", d1);
	matrix_print("加法运算，源矩阵2：", d2);
	matrix_addition(d_add, d1, d2);	//将d1和d2的和放入d_add中，人工保证三个矩阵行列一致
	matrix_print("加法运算，和矩阵 ：", d_add);
	cout << sp << endl;
	matrix_print("乘法运算，源矩阵1：", d1);
	matrix_print("乘法运算，源矩阵2：", f3);
	matrix_multiplication(i_mul, d1, f3);	//将t1和t2的和放入t_add中，人工保证三个矩阵行列一致
	matrix_print("乘法运算，积矩阵 ：", i_mul);
	cout << sp << endl;

	return 0;
}