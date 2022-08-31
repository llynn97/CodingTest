#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int map[100005];
int dp[100005];
int num[100005];
vector <int> v;
int n;

int main(void) {
	cin >> n;
	for (int i = n-1; i >= 1; i--) {
		dp[i] = dp[i + 1] + 1;
		num[i] = i + 1;
		if (i * 3 <= n) {
			if (dp[i] > dp[i * 3] + 1) {
				dp[i] = dp[i * 3] + 1;
				num[i] = i * 3;
			}
			
		}
		if (i * 2 <= n) {
			if (dp[i] > dp[i * 2] + 1) {
				dp[i] = dp[i * 2] + 1;
				num[i] = i * 2;
			}
		}
		
	}
	int cnt = 1;
	v.push_back(1);
	while (true) {
		if (cnt == n) {
			break;
		}
		cnt = num[cnt];
		v.push_back(cnt);
	}
	cout << dp[1] << "\n";
	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
}