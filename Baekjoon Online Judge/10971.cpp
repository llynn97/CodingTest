#include<iostream>
#include <string>
#include <algorithm>


using namespace std;

int n;
int check[11];
int w[11][11];
int ans = 987654321;
void dfs(int k, int d,int cnt) {

	if (cnt == n) {
		if (w[k][0] != 0) {
			ans = min(d + w[k][0], ans);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!check[i] && w[k][i] != 0) {
			check[i] = true;
			dfs(i, d + w[k][i],cnt+1);
			check[i] = false;
		}
	}

}

int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> w[i][j];
		}
	}
	check[0] = true;
	dfs(0, 0, 1);
	cout << ans;


}