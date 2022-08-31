#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int map[501][501];
bool check[501][501];
int ans = 0; //칸에 쓰인 수들의 합 중 최댓값

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };


void dfs(int x, int y, int cnt, int sum) {  // map 좌표 , 지금까지 연결된 칸 개수 , 지금까지 칸에 쓰인 수 합
	check[x][y] = true;
	if (cnt == 3) { //칸에 쓰인 수 합 비교후 최댓값 갱신
		ans = max(ans, sum);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && !check[nx][ny]) {

			dfs(nx, ny, cnt + 1, map[nx][ny] + sum);
			check[nx][ny] = false;
		}

	}
}



void shape1(int x, int y) {//'ㅏ' 모양
	int cnt2 = 0;
	cnt2 = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x + 1][y + 1];
	ans = max(ans, cnt2);
}

void shape2(int x, int y) { //'ㅜ' 모양
	int cnt2 = 0;
	cnt2 = map[x][y] + map[x + 1][y] + map[x + 2][y] + map[x + 1][y + 1];
	ans = max(ans, cnt2);
}

void shape3(int x, int y) { //'ㅓ' 모양
	int cnt2 = 0;
	cnt2 = map[x][y] + map[x][y + 1] + map[x][y + 2] + map[x - 1][y + 1];
	ans = max(ans, cnt2);
}

void shape4(int x, int y) { //'ㅗ' 모양
	int cnt2 = 0;
	cnt2 = map[x][y] + map[x - 1][y + 1] + map[x][y + 1] + map[x + 1][y + 1];
	ans = max(ans, cnt2);
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

			dfs(i, j, 0, map[i][j]);
			check[i][j] = false;
			if (i + 1 < n && j + 2 < m) {
				shape1(i, j);
			}
			if (i + 2 < n && j + 1 < m) {
				shape2(i, j);
			}
			if (i - 1 >= 0 && j + 2 < m) {
				shape3(i, j);
			}
			if (i - 1 >= 0 && i + 1 < n && j + 1 < m) {
				shape4(i, j);
			}
		}
	}
	cout << ans;
	return 0;
}