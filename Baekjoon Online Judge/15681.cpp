#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n, r, q, u, v;
int U;
vector <int> map[100001];
bool check[100001];
int cnt = 0;
int dp[100001];
int dfs(int node) {
	check[node] = true;
	int ret = 1;
	for (int i = 0; i < map[node].size(); i++) {
		int next = map[node][i];
		if (!check[next]) {
			ret += dfs(next);
		}
	}
	dp[node] = ret;
	return ret;
}
int main(void) {
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++) {
		cin >> u >> v;
		map[u].push_back(v);
		map[v].push_back(u);
	}
	dfs(r);
	
	for (int i = 0; i < q; i++) {
		cin >> U; //정점 U를 루트로 함
		cout << dp[U] << "\n";
	}
}