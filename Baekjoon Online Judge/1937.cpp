#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n;
int map[501][501];
int dp[501][501];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int dfs(int x, int y) {

	int& ret = dp[x][y];
	if (ret != 0) {
		return ret;
	}

	ret = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && ny < n && nx < n && map[x][y] < map[nx][ny]) {
		  ret=max(ret, dfs(nx, ny)+1);
		}
	}
	return ret;
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			answer = max(answer, dfs(i, j));
		}
	}
	cout << answer;
}