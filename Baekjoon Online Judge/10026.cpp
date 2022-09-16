#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;
int n;
char map[101][101];
bool check[101][101];
char color1[101][101];//적록색약 아닐때
char color2[101][101]; //적록색약일때
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };

void bfs(int x, int y)

{
	queue <pair<int, int>> q;
	q.push(make_pair(x, y));
	check[x][y] = true;
	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second;
		char color = map[px][py];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
				if (color == map[nx][ny] && !check[nx][ny]) {
					check[nx][ny] = true;
					q.push(make_pair(nx, ny));
				}
			}

		}
	}

}


int main() {
	string s;
	cin >> n;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				cnt1++;
				bfs(i, j);


			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 'G') {
				map[i][j] = 'R';
			}
			check[i][j] = false;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!check[i][j]) {
				cnt2++;
				bfs(i, j);


			}
		}
	}
	cout << cnt1 << " " << cnt2;



}