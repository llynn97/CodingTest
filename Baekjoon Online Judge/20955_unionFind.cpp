#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int n, m, U, V;
bool cycle[100010];
int parent[100100];
int cnt2, cnt1;

void init() {
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
}

int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	return parent[x] = find(parent[x]);
}

void union_group(int x, int y) {
	int px = find(x);
	int py = find(y);
	if (px != py) {
		parent[py] = px;
	}
}

int main(void) {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		cin >> U >> V;
		if (find(U) != find(V)) {
			union_group(U, V);
		}
		else {
			cnt2++;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (find(i) == i) {
			cnt1++;
		}
	}
	cout << cnt1 - 1 + cnt2;

}