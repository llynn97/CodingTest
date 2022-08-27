#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int n, a, b;
vector <int> v[100001];
int ans[100001];
bool check[100001];

void dfs(int k) {

	for (int i = 0; i < v[k].size(); i++) {
		int num = v[k][i];
		if (!check[num]) {
			check[num] = true;
			ans[num] = k;
			dfs(num);
		}
	}
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	check[1] = true;
	dfs(1);
	for (int i = 2; i <= n; i++) {
		cout << ans[i] << "\n";
	}
}