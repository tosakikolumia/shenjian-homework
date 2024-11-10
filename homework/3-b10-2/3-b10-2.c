/* 2351753 信08 黄保翔 */
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int a, b, c, n1, n2, n3, n4, n5, n6, n7, n8, n9, n = 1;
	for (a = 111; a <= 999; ++a) {
		for (b = 111; b <= 999; ++b) {
			for (c = 111; c <= 999; ++c) {
				n1 = a / 100;
				n2 = (a / 10) % 10;
				n3 = a % 10;
				n4 = b / 100;
				n5 = (b / 10) % 10;
				n6 = b % 10;
				n7 = c / 100;
				n8 = (c / 10) % 10;
				n9 = c % 10;
				int z1 = 0, z2 = 0, z3 = 0, z4 = 0, z5 = 0, z6 = 0, z7 = 0, z8 = 0, z9 = 0;
				switch (n1) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n2) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n3) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n4) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n5) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
				}
				switch (n6) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n7) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
					default: break;
				}
				switch (n8) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
				}
				switch (n9) {
					case 1:
						z1 = 1;
						break;
					case 2:
						z2 = 1;
						break;
					case 3:
						z3 = 1;
						break;
					case 4:
						z4 = 1;
						break;
					case 5:
						z5 = 1;
						break;
					case 6:
						z6 = 1;
						break;
					case 7:
						z7 = 1;
						break;
					case 8:
						z8 = 1;
						break;
					case 9:
						z9 = 1;
						break;
				}
				if (z1 && z2 && z3 && z4 && z5 && z6 && z7 && z8 && z9 && a + b + c == 1953) {
					if (a < b && a < c && b < c) {
							printf("No.%3d : %d+%d+%d=1953\n", n, a, b, c);
						n = n + 1;
					}
				}

			}
		}
	}
	printf("total=%d\n", (n - 1));
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}