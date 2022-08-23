#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
int t[1500001];
int p[1500001];
int dp[1500003];
int cur_max = 0;

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t[i] >> p[i];
	}
	for (int i = 1; i <= n+1; i++) {
		cur_max = max(cur_max, dp[i]);
		if (i + t[i] <= n+1) {
			dp[i + t[i]] = max(dp[i + t[i]], cur_max + p[i]);
		}
	}
	cout << cur_max;
	
}