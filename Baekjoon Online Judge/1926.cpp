#include <iostream>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int n, m;
int map[501][501];
bool check[501][501];
int cnt;
int maxPic;
int pic;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };

void bfs(int x, int y) {
	queue <pair<int, int>> q;
	check[x][y] = true;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && nx < m && ny < n && !check[ny][nx] && map[ny][nx] == 1) {
				pic++;
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1 && !check[i][j]) {
				pic = 1;
				bfs(i, j);
				cnt++;
				maxPic = max(maxPic, pic);
			}
		}
	}

	cout << cnt << "\n";
	cout << maxPic;
}