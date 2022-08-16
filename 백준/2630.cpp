#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int map[2200][2200];

int result[2];
int n;

bool check(int x, int y , int cnt) {
	int start = map[x][y];
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (map[i][j] != start) {
				return false;
			}
		}
	}
	return true;
}

void f(int x, int y, int cnt) {
	if (check(x, y, cnt)) {
		result[map[x][y]]++;
	}
	else {
		int size = cnt / 2;
		f(x, y, size);
		f(x + size, y, size);
		f(x, y + size, size);
		f(x + size, y + size, size);
	}
	

}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	f(0, 0, n);

	cout << result[0] << "\n";
	cout << result[1];
	
}