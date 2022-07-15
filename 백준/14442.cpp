#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int n, m, k;
char map[1001][1001];
bool check[1001][1001][10];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
string s;

void bfs() {
	queue < pair<pair<int, int>, pair<int, int>>> q; //좌표 ,  부순 벽의 수 , 경로 수 
	check[0][0][0] = true;
	q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));
	while (!q.empty()) {
		int x = q.front().first.second;
		int y = q.front().first.first;
		int cnt = q.front().second.first;
		int num = q.front().second.second;
		q.pop();
		if (y == n - 1 && x == m - 1) {
			cout << num;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
				if (map[ny][nx] == '0') {
					if (!check[ny][nx][cnt]) {
						check[ny][nx][cnt] = true;
						q.push(make_pair(make_pair(ny, nx), make_pair(cnt, num+1)));
					}
				}
				if (map[ny][nx] == '1' && cnt + 1 <= k) {
					if (!check[ny][nx][cnt + 1]) {
						check[ny][nx][cnt + 1] = true;
						q.push(make_pair(make_pair(ny, nx), make_pair(cnt+1, num + 1)));

					}
				}
			}
		}
	}

	cout << "-1";


}



int main(void) {
	cin >> n >> m>>k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
		}
	}
	bfs();

	




}