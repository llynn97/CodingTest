#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int n, m, U, V;
bool check[100010];
bool cycle[100010];
vector <int> v[100010];
int cnt2, cnt1;

void dfs(int node, int prev) {
	check[node] = true;
	for (int i = 0; i < v[node].size(); i++) {
		int num = v[node][i];
		if (!check[num]) {
			dfs(num, node);
		}
		else if (!cycle[num] && prev != num ) {
			cnt2++;
			
		}

	}
	cycle[node] = true;
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> U >> V;
		v[U].push_back(V);
		v[V].push_back(U);

	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			
			dfs(i, 0);
			cnt1++;
			
		}
	}
	cout << cnt1 - 1 + cnt2;
}