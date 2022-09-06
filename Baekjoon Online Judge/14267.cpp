#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;
vector <int> v[100001];

int dp[100001];
bool check[100001];
int n, m, a,b;

void dfs(int node) {

	
	for (int i = 0; i < v[node].size(); i++) {
		int num = v[node][i];
		dp[num] += dp[node];
		dfs(num);
		
		
	}
	
	
}
int main(void) {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		if (a == -1) {
			continue;
		}
		v[a].push_back(i);
		

	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		dp[a] += b;
	}
	dfs(1);
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << " ";
	}
	
}