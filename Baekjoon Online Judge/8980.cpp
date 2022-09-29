#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, C, M;
int a, b, c;
vector <pair<pair<int, int>,int>> v;
int truck[2001];
int ans = 0;

bool cmp(pair<pair<int, int>,int> a1, pair<pair<int, int>, int> b1) {
	if (a1.first.second == b1.first.second) {
		return a1.first.first < b1.first.first;
	}
	else {
		return a1.first.second < b1.first.second;
	}
}

int main(void) {
	cin >> N >> C;
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;
		v.push_back(make_pair(make_pair(a, b),c));
		
	}
	sort(v.begin(), v.end(),cmp);

	for (int i = 0; i < M; i++) {
		int start = v[i].first.first;
		int end = v[i].first.second;
		int box = v[i].second;
		int max_box = 0;
		for (int j = start; j < end; j++) {
			max_box = max(max_box, truck[j]); //마을마다 트럭에 실어야할 박스 최대 무게
		}
		int capacity = min(box,C - max_box);
		for (int j = start; j < end; j++) {
			truck[j] += capacity;
		}
		ans += capacity;
	}
	cout << ans;
	
}