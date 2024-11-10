/* 2351753 ÐÅ08 »Æ±£Ïè */
#include <iostream>
using namespace std;
int main() {
	int lamp[100];
	int i,j;
	for (i = 0; i < 100; i++) {
		lamp[i] = 0;
	}
	for (i = 0; i < 100; i++) {
		for (j = 1; (i + 1) * j <= 100; j++) {
			if (lamp[(i + 1) * j - 1] == 1) {
				lamp[(i + 1) * j - 1] = 0;
			}
			else {
				lamp[(i + 1) * j - 1] = 1;
			}
		}
	}

	for (i = 0; i < 100; i++) {
		if (lamp[i] == 1) {
			if (i+1 == 100) {
				cout << i + 1;
			}
			else {
				cout << i + 1 << " ";
			}
			
		}

	}
	cout << endl;
	return 0;
}