#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

long long dp[201][201];
int n, k;

int main(void) {
	cin >> n >> k;
	for (int i = 0; i <= k; i++) {
		dp[1][i] = i;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1])% 1000000000;
		}
	}

	cout << dp[n][k];
}