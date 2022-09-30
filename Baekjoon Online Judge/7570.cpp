#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n,x;
int dp[1000001];
int num = 0;

int main(void) {

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		dp[x] = dp[x - 1] + 1;
		num = max(num, dp[x]);
	}

	cout << n - num;
}