#include <iostream>
#include <algorithm>

using namespace std;

int n;
int map[2200][2200];

int result[3];

bool check(int x, int y, int cnt) { //모두 1 일때
	int start = map[x][y];
	for (int i = x; i < x + cnt; i++) {
		for (int j = y; j < y + cnt; j++) {
			if (map[i][j] !=start ) {
				return false;
			}
		}
	}
	return true;

}

void f(int x, int y, int cnt) {
	
	if (check(x,y,cnt)) {
		result[map[x][y]]++;
	}
	else {
		int size = cnt / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				f(x + size * i, y + size * j, size);
			}
		}
	}
	
	

}
	
	
	
int main(void) {
		int n4 = 0;
	   cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> n4;
			n4++;
			map[i][j] = n4; // 0,1,2로 표현

		}
	}
	f(0, 0, n);
	cout << result[0] << " " << result[1] << " " << result[2];
}

	
	