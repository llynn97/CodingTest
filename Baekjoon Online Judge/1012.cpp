# include <iostream>
# include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t, m, k, n; //m:가로길이 n:세로길이
int map[51][51];
int check[51][51];
int ans = 0;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void init() {
	for (int i = 0; i < 51; i++) {
		for (int j = 0; j < 51; j++) {
			map[i][j] = 0;
			check[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
				if (map[ny][nx] == 1 && check[ny][nx] == 0) {
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));

				}
			}
		}
	}


}

int main(void) {
	int x, y;
	cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		ans = 0;
		cin >> m >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> x >> y;
			map[y][x] = 1;
		}


		for (int p = 0; p < n; p++) {
			for (int k = 0; k < m; k++) {
				if (map[p][k] == 1 && check[p][k] == 0) {
					check[p][k] = 1;
					bfs(p, k);
					ans++;

				}
			}
		}
		cout << ans << "\n";
	}


}