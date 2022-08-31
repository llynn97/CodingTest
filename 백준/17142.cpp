#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int n, m;
int map[51][51];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector <pair<int, int>> v;
vector <pair<int, int>> virus;
bool check[11];
int check2[51][51];
int ans = 0;
int emptyPlace = 0;
int cnt3 = 0;
int minCnt = 987654321;


void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) { // 0: 아직 check 안함 1: 체크 함 2: 비활성 상태
			check2[i][j] = 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		check2[v[i].first][v[i].second] = 2; //비활성화로 초기화
	}
}


void spreadVirus() {
	queue <pair<pair<int, int>, int>> q;
	ans = 0;
	cnt3 = 0;
	for (int i = 0; i < virus.size(); i++) {
		check2[virus[i].first][virus[i].second] = 1;
		q.push(make_pair(make_pair(virus[i].first, virus[i].second), 4));

	}

	while (!q.empty()) {
		if (cnt3==emptyPlace) {
			
			break;
		}
		int qSize = q.size();
		for (int j = 0; j < qSize; j++) {
			int x = q.front().first.first;
			int y = q.front().first.second;
			int flag = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n && check2[nx][ny] != 1 && map[nx][ny] != 1) {
					if (check2[nx][ny] == 2) { //비활성화 일 경우
						check2[nx][ny] = 1;
						q.push(make_pair(make_pair(nx, ny), 4));
					}
					else if (check2[nx][ny] == 0) {
						cnt3++;
						check2[nx][ny] = 1;
						q.push(make_pair(make_pair(nx, ny), 4));
					}



				}
			}



		}
		

		if (q.size() != 0) {
			ans++;
		}
	}

	
	if (cnt3 == emptyPlace) {
		minCnt = min(minCnt, ans);
	}

}


void dfs(int cnt,int idx) {
	if (cnt == m) {
		init();
		spreadVirus();

		return;
	}
	for (int i = idx; i < v.size(); i++) {
		if (!check[i]) {
			check[i] = true;
			virus.push_back(make_pair(v[i].first, v[i].second));
			dfs(cnt + 1,i);
			check[i] = false;
			virus.pop_back();
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 0) {
				emptyPlace++;
			}
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	dfs(0,0);
	if (minCnt == 987654321) {
		cout << -1;
	}
	else {
		cout << minCnt;
	}
}