#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


using namespace std;

int n;
char map[64][64];

bool check(int x, int y, int cnt) {
	char start = map[x][y];
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (start != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void f(int x, int y, int cnt) {
	if (check(x, y, cnt)) {
		cout << map[x][y];
	}
	else {
		cout << "(";
		int size = cnt / 2;
		f(x, y, size);
		f(x, y + size, size);
		f(x + size, y, size);
		f(x + size, y + size, size);
		cout << ")";
	}
	
}

int main(void) {
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	f(0, 0, n);
}