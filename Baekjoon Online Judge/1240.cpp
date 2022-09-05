#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int n, m;
int a, b, c;
vector <pair<int, int>> v[1001]; //[시작점]  끝점,거리
bool check[1005];
int dist1[1005];
void init() {
	for (int i = 0; i < 1005; i++) {
		check[i] = false;
		dist1[i] = 0;
	}
}

int bfs(int root,int end) {
	check[root] = true;
	queue<int> q;
	q.push(root);
	dist1[root] = 0;
	while (!q.empty()) {
		int root = q.front();
		q.pop();
		for (int i = 0; i < v[root].size(); i++) {
			int num = v[root][i].first;
			int dist = v[root][i].second;
			if (!check[num]) {
				check[num] = true;
				dist1[num] = dist1[root] + dist;
				q.push(num);
			}
		}
	}
	return dist1[end];
	
	
	
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		init();
		cout << bfs(a, b)<<"\n";
	}
}