#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[9][9];
int smap[9][9];
bool check[9][9];
bool check2[100];
vector <pair<int, int>> v;
vector <pair<int, int>> v2;


int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int ans = 0;

void copyMap() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			smap[i][j] = map[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check[i][j] = false;
		}
	}
}
void bfs(int x, int y) {
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < m && !check[nx][ny]) {
				if (smap[nx][ny] == 0) {
					check[nx][ny] = true;
					smap[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}

	}
}
void spreadVirus() { //바이러스 퍼뜨리기 
	queue <pair<int, int>> q;
	init();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!check[i][j] && smap[i][j] == 2) {
				bfs(i, j);
			}
		}
	}

}

int countArea() { //안전영역 개수 세기
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (smap[i][j] == 0) {
				cnt++;
			}

		}
	}
	return cnt;
}

void buildWall(int idx, int cnt) { //벽을 3개 세움 
	if (cnt == 3) {
		for (int i = 0; i < v2.size(); i++) {
			map[v2[i].first][v2[i].second] = 1;
		}
		
		copyMap();
		spreadVirus();
		ans = max(ans, countArea());
		return;
	}
	
	for (int i = idx; i < v.size(); i++) {
		if (!check2[i]) {
			check2[i] = true;
			v2.push_back(make_pair(v[i].first, v[i].second));
			buildWall(idx + 1, cnt + 1);
			check2[i] = false;
			map[v[i].first][v[i].second] = 0;
			v2.pop_back();
			
		}
	}

}



int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 0) {
				v.push_back(make_pair(i, j));
			}
		}
	}

	
	
	
	buildWall(0,0);
	cout << ans;
}