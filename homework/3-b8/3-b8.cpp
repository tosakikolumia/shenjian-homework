/* 2351753 ��08 �Ʊ��� */
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    bool p = 0;
    while (!p) {
        cout << "������x��ֵ[-10 ~ +65]" << endl;
        int n = 1, i;
        double e = 1, t = 1, fenzi, fenmu, x;
        cin >> x;
        if (x < -10 || x>65) {
            cout << "����Ƿ�������������" << endl;         
        }
        else {
            while (fabs(t) >= 1e-6) {
                fenzi = 1;
                fenmu = 1;
                for (i = 1; i <= n; ++i) {
                    fenmu *= i;
                }
                for (i = 1; i <= n; ++i) {
                    fenzi *= x;
                }
                t = fenzi / fenmu;
                if (fabs(t) >= 1e-6) {
                    e = e + t;
                }
                else {
                    break;
                }
                n = n + 1;
            }
            cout << "e^" << x << "=" << setprecision(10) << e << endl;
            p = 1;
        }
    }
    

    return 0;
}