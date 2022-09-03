#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int v, e;
int a, b, c = 0;
int ans = 0;
vector<pair<int, int>> node[10001]; //<end,가중치> [시작점]
bool check[10001];
//1->2,3

void Kruskal(int idx) {

	priority_queue<pair<int, int >> pq; // 가중치
	pq.push(make_pair(0, idx));
	//check[idx] = true;
	while (!pq.empty()) {
		int j = pq.top().second;
		int num = -pq.top().first;
		pq.pop();
		if (check[j]) {

			continue;

		}
		check[j] = true;
		ans += num;

		for (int i = 0; i < node[j].size(); i++) {

			pq.push(make_pair(-node[j][i].second, node[j][i].first));

		}


	}


}

int main() {
	cin >> v >> e;
	for (int i = 0; i < e; i++) {
		cin >> a >> b >> c;
		node[a].push_back(make_pair(b, c));
		node[b].push_back(make_pair(a, c));


	}
	Kruskal(1);
	cout << ans;
}