#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int dp[105][10][1024];

int main(void) {

	cin >> n;
	dp[1][0][1] = 0;
	dp[1][1][2] = 1;
	dp[1][2][4] = 1;
	dp[1][3][8] = 1;
	dp[1][4][16] = 1;
	dp[1][5][32] = 1;
	dp[1][6][64] = 1;
	dp[1][7][128] = 1;
	dp[1][8][256] = 1;
	dp[1][9][512] = 1;

	for (int i = 2; i <= n; i++) { //ÀÚ¸´¼ö
		for (int j = 0; j <= 9; j++) { 
			for (int k = 0; k < 1024; k++) {
				if (j == 0) {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
				else if (j == 9) {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j -1][k]) % 1000000000;
				}
				else {
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j - 1][k]) % 1000000000;
					dp[i][j][k | (1 << j)] = (dp[i][j][k | (1 << j)] + dp[i - 1][j + 1][k]) % 1000000000;
				}
		   }
		}
	}
	int ans = 0;
	for (int i = 0; i <= 9; i++) {
		ans = (ans+dp[n][i][1023])% 1000000000;
		
	}
	cout << ans;

}