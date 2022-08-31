#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>


using namespace std;
vector <int> v[501];
bool check[501];
int n, m, x, y;
int ans = 0;

void init() {
	for (int i = 1; i <= n; i++) {
		v[i].clear();

	}
	for (int i = 1; i <= n; i++) {
		check[i] = false;
	}

}

bool dfs(int cnt, int before) {
	check[cnt] = true;
	for (int i = 0; i < v[cnt].size(); i++) {
		int num = v[cnt][i];
		
		if (num == before) {
			continue;
		}
		else if (check[num]) {
			 return false;
		 }
		else {
			if (!dfs(num, cnt)) {
				return false;
			}
		}
	}
	return true;
}

// 1->2  before: 1 /  3 before:2  / 


int main(void) {
	int cnt = 0;
	while (true) {
		cin >> n >> m;
		if (n == 0 && m ==0) {
			break;
		}
		init();
		ans = 0;
		cnt++;
		for (int i = 0; i < m; i++) {
			cin >> x >> y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				if (dfs(i, 0)) {
					ans++;
				}
			}
		}
		cout << "Case " << cnt << ": ";
		if (ans > 1)
			cout << "A forest of " << ans << " trees." << '\n';
		else if (ans == 1)
			cout << "There is one tree." << '\n';
		else if (ans == 0)
			cout << "No trees." << '\n';
	}
}