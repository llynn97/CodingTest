#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int a, b, c;
vector <pair<int, int>> v[1001];
int INF = 987654321;
int d[1001];
int dp[1001];

void dijkstra(int idx) {
	d[idx] = 0;
	dp[idx] = 1;
	priority_queue<pair<int, int>> pq;
	pq.push(make_pair(0, idx));
	while (!pq.empty()) {
		int j = pq.top().second; //선택한 노드
		int num = -pq.top().first; //비용
		pq.pop();
		for (int i = 0; i < v[j].size(); i++) {
			if ((num + v[j][i].second) < d[v[j][i].first]) {
				d[v[j][i].first] = num + v[j][i].second;
				pq.push(make_pair(-d[v[j][i].first], v[j][i].first));
			}
			if (num > d[v[j][i].first]) {
				dp[j] += dp[v[j][i].first];
			}
		}
	}
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back(make_pair(b, c));
		v[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i <= n; i++) {
		d[i] = INF;
	}
	dijkstra(2);
	cout << dp[1];
	


}