#include <iostream>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

char map[51][51];
int ans[51][51];
int m, n;
int cnt = 0;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
queue <pair<int, int>> land;

void bfs() {
	while (!land.empty()) {
		int lx = land.front().second;
		int ly = land.front().first;
		land.pop();
		memset(ans, 0, sizeof(ans));
		queue <pair<int, int>> q;
		q.push(make_pair(ly, lx));

		while (!q.empty()) {
			int x = q.front().second;
			int y = q.front().first;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m) {
					continue;
				}
				if (map[ny][nx] == 'W' || (lx == nx && ly == ny)) {
					continue;
				}
				if (ans[ny][nx] == 0 || ans[ny][nx] > ans[y][x] + 1) {
					ans[ny][nx] = ans[y][x] + 1;
					q.push(make_pair(ny, nx));
				}

			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (ans[i][j] > cnt) {
					cnt = ans[i][j];
				}
			}
		}
	}
}

int main() {
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'L') {
				land.push(make_pair(i, j));
			}
		}
	}
	bfs();
	cout << cnt;
	return 0;
}