#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int n, m,r,c,d;
int map[50][50];
bool check[50][50];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = 0;

void bfs() {
	queue <pair<pair<int, int>, int>> q; //좌표, 방향
	q.push(make_pair(make_pair(r, c), d));
	check[r][c] = true;
	ans = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		
		bool check3 = false;
		int nextDir = 0;
		int dir2 = dir;
		for (int i = 0; i < 4; i++) { // 청소할 곳이 없을 경우 왼쪽 방향으로 회전
			if (!check3) {
				if (dir2 == 0) nextDir = 3;
				if (dir2 == 1) nextDir = 0;
				if (dir2 == 2) nextDir = 1;
				if (dir2 == 3) nextDir = 2;
				int nx = x + dx[nextDir];
				int ny = y + dy[nextDir];
				if (nx >= 0 && ny >= 0 && nx < n && ny < m && map[nx][ny] == 0 && !check[nx][ny]) {
					ans++;
					check[nx][ny] = true;
					
					check3 = true;
					q.push(make_pair(make_pair(nx, ny), nextDir));
				}
				if (!check3) {
					dir2 = nextDir;
				}
			}
			
		}
		if (!check3) { // 네 방향 모두 청소를 했거나 벽일 경우 후진한 좌표 확인
			int backDir = 0;
			if (dir == 0) backDir = 2;
			if (dir == 1) backDir = 3;
			if (dir == 2) backDir = 0;
			if (dir == 3) backDir = 1;
			int bx = x + dx[backDir];
			int by = y + dy[backDir];
			if (bx >= 0 && by >= 0 && bx < n && by < m && map[bx][by] != 1) { // 후진한 곳이 벽이 아니면 탐색
				q.push(make_pair(make_pair(bx, by), dir));
			}
		}
	}
	

}

int main(void) {
	cin >> n >> m;
	cin >> r >> c >> d;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	bfs();
	cout << ans;


}