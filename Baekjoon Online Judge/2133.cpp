#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int dp[31];
int main(void) {
	 
	cin >> n;
	dp[0] = 1;
	dp[1] = 0;
	dp[2] = 3;
	if (n % 2 != 0) {
		cout << "0";
	}
	else {
		
		for (int i = 4; i <= n; i = i + 2) {
			dp[i] = dp[i - 2] * dp[2];
			for (int j = i - 4; j >= 0; j = j - 2) {
				dp[i] += (dp[j] * 2);
			}
		}
		cout << dp[n];
	}
	
}