#include<iostream>
#include <string>
#include <algorithm>

using namespace std;

int dp[17][1 << 16];
int n;
int d[17][17];

int dfs(int k, int visit) {

	int &ret = dp[k][visit];
	if (ret != -1) {
		return ret;
	}
	if (visit == (1 << n) - 1) {
		if (d[k][0] !=  0) {
			return d[k][0];
		}
		return 987654321;
	}
	ret = 987654321;

	
	for (int i = 0; i < n; i++) {
		
		if ((visit & (1 << i)) || d[k][i] == 0) {
			continue;
			
		}
		ret = min(ret, dfs(i, (visit | (1 << i))) + d[k][i]);
	}
	return ret;
}
int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> d[i][j];
		}
	}
	for (int i = 0; i < 17; i++) {
		for (int j = 0; j < (1 << 16); j++) {
			dp[i][j] = -1;
		}
	}
	int ans = dfs(0, 1);

	cout << ans;




}