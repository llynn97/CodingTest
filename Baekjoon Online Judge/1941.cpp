#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>


using namespace std;

char map[6][6];
bool select[26];
int ans;
bool check[26][26];
bool check2[26][26]; //bfs 체크
int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

void init() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			check[i][j] = false;
			check2[i][j] = false;
		}
	}
}

bool checkFour() {
	int cnt = 0;
	for (int i = 0; i < 25; i++) {
		if (select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			if (map[x][y] == 'S') {
				cnt++;
			}
			
		}
	}
	if (cnt >= 4) {
		return true;
	}
	return false;
}

bool bfs() {
	queue < pair<int, int>> q;
	

	bool flag = false;

	for (int i = 0; i < 25; i++) {
		
		if (select[i] == true) {
			int x = i / 5;
			int y = i % 5;
			check[x][y] = true;
			if (!flag) {
				q.push(make_pair(x, y));
				check2[x][y] = true;
				flag = true;
			}
		}
	}
	int cnt = 1;
	bool flag2 = false;
	while (!q.empty()) {
		
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (cnt == 7) {
			flag2 = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && ny < 5 && nx < 5) {
				if (check[nx][ny] == true && check2[nx][ny] == false) {
					check2[nx][ny] = true;
					cnt++;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	if (flag2) {
		return true;
	}
	
		return false;
	
	

}

void dfs(int idx,int cnt) {
	if (cnt == 7) {
		if (checkFour()) { //이다솜파가 4명 이상일 때 
			init();
			if (bfs()) {
				ans++;
			}
		}
		return;
	}
	for (int i = idx; i < 25; i++) {
		if (select[i] == false) {
			select[i] = true;
			dfs(i, cnt + 1);
			select[i] = false;
		}
	}
}

int main(void) {
	string s;
	for (int i = 0; i < 5; i++) {
		cin >> s;
		for (int j = 0; j < 5; j++) {
			map[i][j] = s[j];
		}
	}
	dfs(0, 0);
	cout << ans;
}