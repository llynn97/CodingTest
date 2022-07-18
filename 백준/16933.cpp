#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int n, m, k;
char map[1001][1001];
bool check[1001][1001][11];

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void bfs() {
	queue <pair<pair<pair<int, int>, pair<int, int>>, int >> q; // ÁÂÇ¥, ºÎ¼ø º® ¼ö , °æ·Î¼ö ,³·=1/¹ã=0
	q.push(make_pair(make_pair(make_pair(0, 0), make_pair(0, 1)), 1));
	check[0][0][0] = true;
	while (!q.empty()) {
		int x = q.front().first.first.second;
		int y = q.front().first.first.first;
		int wall = q.front().first.second.first;
		int cnt = q.front().first.second.second;
		int day = q.front().second;
		q.pop();
		if (x == m - 1 && y == n - 1) {
			cout << cnt;
			return;
		}
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int day1 = 0;
			if (ny >= 0 && nx >= 0 && nx < m && ny < n) {
				if (map[ny][nx] == '0') {
					if (!check[ny][nx][wall]) {
						check[ny][nx][wall] = true;
						if (day == 1) {
							day1 = 0;
						}
						if (day == 0) {
							day1 = 1;
						}
						q.push(make_pair(make_pair(make_pair(ny, nx), make_pair(wall, cnt + 1)), day1));

					}
				}
				if (map[ny][nx] == '1' && wall < k) {
					if (!check[ny][nx][wall + 1]) {
						if (day == 0) { //¹ãÀÌ¸é ³·ÀÌ µÇ±â ±îÁö ±â´Ù¸®±â

							q.push(make_pair(make_pair(make_pair(y, x), make_pair(wall, cnt + 1)), 1));
						}

						if (day == 1) { //³·ÀÌ¸é º® ºÎ¼ö±â
							
								check[ny][nx][wall + 1] = true;
								q.push(make_pair(make_pair(make_pair(ny, nx), make_pair(wall + 1, cnt + 1)), 0));
							
						}
					}
					
				}
			}
		}
	}
	cout << "-1";
}



int main(void) {
	string s;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
		}
	}

	bfs();
}