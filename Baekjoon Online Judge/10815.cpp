#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int num[500000];
int num2[500000];
int num3[500000];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> num2[i];
	}
	sort(num, num + n);
	for (int i = 0; i < m; i++) {
		if (binary_search(num, num + n, num2[i]) != false) {
			num3[i] = 1;
		}
		else {
			num3[i] = 0;
		}
	}
	for (int i = 0; i < m; i++) {
		cout << num3[i] << " ";
	}




	return 0;
}