#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

int n, w;

int x, y;
int dp[1001][1001];
vector <pair<int, int>> v;


int solve(int p1,int p2) {
	if (p1 == w || p2 == w) {
		return 0;
	}
	if (dp[p1][p2] != -1) {
		return dp[p1][p2];
	}
	int num = max(p1, p2) + 1;
	int d1 = 0;
	int d2 = 0;
	if (p1 == 0) {
		d1= abs(1 - v[num].first) + abs(1 - v[num].second);
	}
	else {
		d1 = abs(v[p1].first - v[num].first) + abs(v[p1].second - v[num].second);
	}

	if (p2 == 0) {
		d2 = abs(n - v[num].first) + abs(n - v[num].second);
	}
	else {
		d2 = abs(v[p2].first - v[num].first) + abs(v[p2].second - v[num].second);
	}

	int minP1 = solve(num, p2) + d1;
	int minP2 = solve(p1, num) + d2;

	dp[p1][p2] = min(minP1, minP2);
	
	return dp[p1][p2];

}


void solve2(int p1, int p2) {
	if (p1 == w || p2 == w) {
		return;
	}

	int num = max(p1, p2) + 1;
	int d1 = 0;
	int d2 = 0;
	if (p1 == 0) {
		d1 = abs(1 - v[num].first) + abs(1 - v[num].second);
	}
	else {
		d1 = abs(v[p1].first - v[num].first) + abs(v[p1].second - v[num].second);
	}

	if (p2 == 0) {
		d2 = abs(n - v[num].first) + abs(n - v[num].second);
	}
	else {
		d2 = abs(v[p2].first - v[num].first) + abs(v[p2].second - v[num].second);
	}
	if (dp[num][p2] + d1 < dp[p1][num] + d2) {
		cout << 1 << "\n";
		solve2(num, p2);
	}
	else {
		cout << 2 << "\n";
		solve2(p1, num);
	}
}

int main(void) {
	cin >> n;
	cin >> w;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= w; i++) {
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}

	for (int i = 0; i <= w; i++) {
		for (int j = 0; j <= w; j++) {
			dp[i][j] = -1;
		}
	}
	

	cout<<solve(0, 0);
	cout << "\n";
	solve2(0, 0);

}