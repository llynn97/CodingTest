#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

priority_queue <int,vector<int>,greater<int>> q;
vector<pair<int, int>> v;
int n, a, b;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	sort(v.begin(), v.end());
	q.push(v[0].second);
	for (int i = 1; i < v.size(); i++) {
		q.push(v[i].second);
		if (v[i].first >= q.top()) {
			q.pop();
		}
	}
	cout << q.size();
}