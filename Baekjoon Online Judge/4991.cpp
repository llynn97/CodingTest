#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;

int w, h;
char map[21][21];
bool check[21][21];
int smap[21][21];
int robotX, robotY;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,1,-1,0 };
vector <pair<int, int>> dirt;
int answer = 987654321;

int dist1[12][12]; // 칸과 칸 사이 이동시간 최솟값

void init2() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			dist1[i][j] = 0;
		}
	}
}

void init() {
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 21; j++) {
			smap[i][j] = 0;
			check[i][j] = false;
		}
	}
}
int bfs(int startX, int startY, int endX, int endY) {
	
	queue <pair<int, int>> q;
	check[startX][startY] = true;
	smap[startX][startY] = 0;
	q.push(make_pair(startX, startY));
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == endX && endY == y) {
			
			return smap[endX][endY];
			
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < h && ny < w &&!check[nx][ny] && map[nx][ny] != 'x') {
				check[nx][ny] = true;
				smap[nx][ny] = smap[x][y] + 1;
				q.push(make_pair(nx, ny));

			}
		}
		
	}
	return smap[endX][endY];
}

int main(void) {
	string s;
	while (true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}
		init2();
		dirt.clear();
		answer = 987654321;
		for (int i = 0; i < h; i++) {
			cin >> s;
			for (int j = 0; j < w; j++) {
				map[i][j] = s[j];
				if (map[i][j] == 'o') {
					robotX = i;
					robotY = j;
				}
				
				if (map[i][j] == '*') {
					dirt.push_back(make_pair(i, j));
				}
			}
		}
		dist1[0][0] = 0; // 0 은 로봇청소기
		for (int i = 0; i < dirt.size(); i++) { // 로봇청소기와 더러운 칸 사이의 이동 시간 최솟값 
			init();
			dist1[0][i + 1] = bfs(robotX, robotY, dirt[i].first, dirt[i].second);
		}

		for (int i = 0; i < dirt.size(); i++) {
			
			for (int j = i; j < dirt.size(); j++) {
				init();
				if (i == j) {
					dist1[i+1][j+1] = 0;
				}
				else {
					int num= bfs(dirt[i].first, dirt[i].second, dirt[j].first, dirt[j].second);
					dist1[i + 1][j + 1] = num;
					dist1[j + 1][i + 1] = num;
				}
			}
		}
		vector <int> order;
		for (int i = 0; i < dirt.size(); i++) {
			order.push_back(i+1);
		}
		while (next_permutation(order.begin(), order.end())){
			int idx = 0;
			int ans = 0;
			bool check2 = false;
			for (int i = 0; i < order.size(); i++) {
				if (dist1[idx][order[i]] != 0) {
					ans += dist1[idx][order[i]];
					idx = order[i];
				}
				else {
					check2 = true;
				}

			}
			if (!check2) {
				answer = min(answer, ans);
			}
				
		}
		if (answer == 987654321) {
			cout << "-1" << "\n";
		}
		else {
			cout << answer << "\n";
		}
		
		

	}

}