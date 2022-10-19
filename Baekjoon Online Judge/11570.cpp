#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n;
int map[2001];
int dp[2001][2001];



int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			dp[i][j] = 987654321;

		 }
	}
	dp[0][1] = 0;
	dp[1][0] = 0;
	for (int i = 0; i <= n; i++) {
		for (int j=0; j <= n; j++) {
			if (i == j) {
				continue;
		   }
			int idx = max(i, j) + 1;
			if (idx > n) {
				continue;
			}
			if (i == 0 || j == 0) {
				map[0] = map[idx];
			}
			dp[idx][j] = min(dp[idx][j], dp[i][j] + abs(map[idx] - map[i]));
			dp[i][idx] = min(dp[i][idx], dp[i][j] + abs(map[idx] - map[j]));

		}
	}
	int ans = 987654321;
	for (int i = 0; i <= n; i++) {
		
		ans = min(ans, dp[i][n]);
		ans = min(ans, dp[n][i]);
		
	}
	cout << ans;
}