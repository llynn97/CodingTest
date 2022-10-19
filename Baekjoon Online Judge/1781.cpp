#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>

using namespace std;
int map[200001];
int n;
int a, b;
vector <pair<int, int>> v;
priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

long long ans = 0;
int tim = 1;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		if (pq.size() < v[i].first) {
			pq.push(make_pair(v[i].second, v[i].first));
		}
		else {
			if (pq.top().first < v[i].second) { // 컵라면 수가 더 많으면
				pq.pop();
				pq.push(make_pair(v[i].second, v[i].first));
			}
		}
	}
	while (!pq.empty()) {
		ans += pq.top().first;
		
		pq.pop();
	}

	cout << ans;




}