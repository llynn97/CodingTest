#include <iostream>
#include <string>
#include <algorithm>


using namespace std;

int n,m;
int vip[42];
int dp[42];
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> vip[i];
	}
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int answer = 1;
	int start = 0;
	for (int i = 0; i < m; i++) {
		int end = vip[i];
		answer *= dp[end -start- 1];
		start = end;
	}
	answer *= dp[n - start];
	cout << answer;
}