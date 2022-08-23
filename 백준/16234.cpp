#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <math.h>

using namespace std;

int n, r, l;
int map[50][50];
int check[50][50];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int cnt = 0; // 인구 차이가 l 이상 r 이하 난 횟수
int ans;
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = 0;
		}
	}
}

void bfs(int x, int y) {
	int tx = x;
	int ty = y;
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = 1;
	int num = 1;
	int sum = map[x][y];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && check[nx][ny] == 0) {
				if (abs(map[x][y] - map[nx][ny]) >= l && abs(map[x][y] - map[nx][ny]) <= r) {
					check[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					num++;
					sum += map[nx][ny];
				}
			}
		}
     }
	if (num == 1) { //인구 이동이 없음
		check[tx][ty] = 2;
	}
	else {
		int popu = sum / num;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 1) {
					
					check[i][j] = 2;
					map[i][j] = popu;
				}
			}
		}
		cnt++;

	}
}



int main(void) {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	

	while (true) {
		
		init();
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 0) {
					bfs(i, j);
				}
			}
		}
		if (cnt == 0) {
			break;
		}
		ans++;
		

	}

	cout << ans;
}