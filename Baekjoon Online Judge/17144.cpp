#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int r, c, t;
int map[51][51];
int smap[51][51];
int robotX2;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

void init() {
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			smap[i][j] = 0;
		}
	}
}

int changeDir1(int di) { //위
	if (di == 0) return 1;
	if (di == 1) return 2;
	if (di == 2) return 3;
	if (di == 3) return 0;

}

int changeDir2(int di) { //아래
	if (di == 0) return 3;
	if (di == 3) return 2;
	if (di == 2) return 1;
	if (di == 1) return 0;

}

void spreadDust() { //미세먼지 확산
	
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] > 0) {
				int cnt = 0;
				int size = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx >= 1 && ny >= 1 && ny <= c && nx <= r && map[nx][ny] != -1) {
						smap[nx][ny] += size;
						cnt++;
					}
				}
				smap[i][j] += (map[i][j] - map[i][j] / 5 * cnt);
			}
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] != -1) {
				map[i][j] = smap[i][j];
			}
		}
	}
}

void purifyAir() { //공기청정기 동작
	
	//위(반시계 방향)
	int kx = robotX2 - 1;
	int ky = 2;
	int x = robotX2 - 1;
	int y = 2;
	int dir = 0;
	while (true) {
		
		int size = map[x][y];
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx<1 || ny<1 || nx>r || ny>c) {
			dir = changeDir1(dir);
		}
		x += dx[dir];
		y += dy[dir];
		if (kx == x && y == 1) { //미세먼지 정화

			break;
		}
		smap[x][y] = size;
	}
	//아래(시계방향)
	kx = robotX2;
	x = robotX2;
	y = 2;
	dir = 0;
	while (true) {
		
		int size = map[x][y];
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (nx<1 || ny<1 || nx>r || ny>c) {
			dir = changeDir2(dir);
		}
		x += dx[dir];
		y += dy[dir];
		if (kx == x && y == 1) { //미세먼지 정화

			break;
		}
		smap[x][y] = size;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (((i >= 2 && i <= robotX2 - 2) && (j >= 2 && j <= c - 1)) || ((i >= robotX2 + 1 && i <= r - 1) && (j >= 2 && j <= c - 1))) {
				continue;
			}
			map[i][j] = smap[i][j];
		}
	}
	map[robotX2 - 1][1] = -1;
	map[robotX2][1] = -1;

}

int main(void) {
	int ans = 0;
	cin >> r >> c >> t;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				robotX2 = i;
			}
		}
	}
	while (t--) {
		init();
		spreadDust();
		
		init();
		purifyAir();
		
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (map[i][j] > 0) {
				ans += map[i][j];
			}
		}
	}
	cout << ans;
}