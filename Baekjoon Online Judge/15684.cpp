#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

int n, m, h;
int map[31][11];

int ans;


bool move() {
	for (int j = 1; j <= n; j++) {
		int col = j;
		for (int i = 1; i <= h; i++) {
			if (map[i][col]) {
				col++;
			}
			else if (map[i][col - 1]) {
				col--;
			}
		}
		if (col != j) {
			return false;
		}
	}
	return true;
}

void makeLine(int cnt2, int cnt, int x, int y) {
	if (cnt==cnt2) {
		if (move()) {
			cout << cnt;
			exit(0);
		}
		return;
	}
	
	for (int i = x; i <= h; i++) {
		for (int j = y; j <= n - 1; j++) {
			if (map[i][j] == 1 || map[i][j - 1] == 1 || map[i][j + 1] == 1) {
				continue;
			}
			map[i][j] = 1;
			makeLine(cnt2,cnt + 1, i,j);
			map[i][j] = 0;




		}
		y = 1;
	}

	
}

void countNum() {
	int cnt = 0;
	while (true) {
		if (cnt > 3) {
			break;
		}
		makeLine(cnt,0,1,1);
		cnt++;
	}
}






int main(void) {
	int a, b;
	cin >> n >> m >> h;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = 1;
		
	}
	countNum();
	
	cout << "-1";
}