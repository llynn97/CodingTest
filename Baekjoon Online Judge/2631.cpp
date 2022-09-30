#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n;
int v[201];
int dp[201];
int ans;

int main(void) {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (v[i] > v[j] && dp[j] >= dp[i]) {
				dp[i] += 1;
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << n - ans;
}