#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int T, W;
int dp[1001][32][3]; // 시간, 이동횟수, 위치
int plum[1001][3];
int num;
int result;
int main(void) {
	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> num;
		plum[i][num] = 1;
	}
	dp[1][0][1] = plum[1][1];
	dp[1][1][2] = plum[1][2];
	result = max(dp[1][0][1], dp[1][1][2]);
	
	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= W; j++) {
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][2]) + plum[i][1];
			dp[i][j][2] = max(dp[i - 1][j - 1][1], dp[i - 1][j][2]) + plum[i][2];
			result = max(max(result, dp[i][j][1]), dp[i][j][2]);
		}
	}
	cout << result;

}