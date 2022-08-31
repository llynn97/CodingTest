#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>


using namespace std;

int n,m;
int map[51][51]; //0:빈칸, 1:벽, 2:바이러스 놓을수 있는 칸
bool check[51][51];
bool check2[15];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
vector <pair<int, int>> virus;
vector < pair<int, int>> v;
vector < pair<int, int>> v2;
vector < pair<int, int>> v3;

int ans = 987654321;
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}


bool checkMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1) {
				continue;
			}
			if (!check[i][j]) {
				return false;
			}
		}
	}
	return true;
}


void spreadVirus() {
	queue < pair<int, int>> q;
	for (int i = 0; i < v2.size(); i++) {
		int x = v2[i].first;
		int y = v2[i].second;
		q.push(make_pair(x, y));
		check[x][y] = true;
	}
	int cnt = 0;
	while (!q.empty()) {
		int s = q.size();
		for (int j = 0; j < s; j++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[nx][ny] && map[nx][ny]!=1) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));

				}
			}
		}
		if (q.size() != 0) {
			cnt++;
		}

	}
	if (checkMap()) {
		ans = min(ans, cnt);
	}
	
	
}

   

void dfs(int cnt,int idx) { // m개 바이러스 정하기
	if (cnt == m) {
		init();
	
		spreadVirus();
		return;
	}
	for (int i = idx; i < virus.size(); i++) {
		if (check2[i]) {
			continue;
		}
		check2[i] = true;
		v2.push_back(make_pair(virus[i].first, virus[i].second));
		dfs(cnt + 1,i);
		v2.pop_back();
		check2[i] = false;

		
	}

}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2) {
				virus.push_back(make_pair(i, j));
			}
		}
	}
	
	
	dfs(0,0);
	if (ans == 987654321) {
		cout << -1;
			
	}
	else {
		cout << ans;
	}
}