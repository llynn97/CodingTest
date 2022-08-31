#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
char map[1001][1001];
int map2[1001][1001];
int answer[1001][1001];
bool check[1001][1001];
bool check2[10001];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue <pair<int, int>> que;
int idx;
vector <int> v;

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			map2[i][j] = -1;
		}
	}
}

void init2() {
	for (int i = 0; i <= idx; i++) {
		check2[i] = false;
	}
}



int bfs(int x, int y,int cnt){
	int count = 1;
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	map2[x][y] = cnt;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m && map[ny][nx]=='0'&&!check[ny][nx]) {
				count++;
				check[ny][nx] = true;
				map2[ny][nx] = cnt;
				q.push(make_pair(ny, nx));
			}
		}
	}
	return count;
}

int main(void) {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			
		}
	}
	init();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '0' && !check[i][j]) {
				int number = bfs(i, j,idx);
				v.push_back(number);
				idx++;
				
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				int num = 0;
				init2();
				for (int k = 0; k < 4; k++) {
					int ny = i + dy[k];
					int nx = j + dx[k];
					if (ny >= 0 && nx >= 0 && nx < m && ny < n) {
						if (map2[ny][nx] != -1) {
							if (!check2[map2[ny][nx]]) {
								check2[map2[ny][nx]] = true;
								num += v[map2[ny][nx]];
							}
						}
					}
				}
				answer[i][j] = num+1;
			}
		}
	}

   


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << answer[i][j];
		}
		cout << "\n";
	}

}