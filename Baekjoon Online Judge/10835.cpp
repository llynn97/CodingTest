#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n;
int map[2][2010];
int dp[2010][2010];
int solve(int i, int j) { // i: 왼쪽더미 인덱스 j: 오른쪽더미 인덱스
	if (i >= n || j >= n) {
		return 0;
	}
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	dp[i][j] = 0;
	dp[i][j] = max(solve(i + 1, j + 1), solve(i + 1, j));

	if (map[0][i] > map[1][j]) {
		dp[i][j] = max(dp[i][j], solve(i, j + 1) + map[1][j]);
	}
	return dp[i][j];
}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) { // 왼쪽 더미
		cin >> map[0][i];
	}
	for (int i = 0; i < n; i++) { //오른쪽 더미
		cin >> map[1][i]; 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << solve(0, 0);
}
