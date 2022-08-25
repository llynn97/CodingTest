#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>


using namespace std;

int n;
int map[21][21];
bool check[21][21];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int nowX, nowY;
int sharkSize;
int minCnt, minX, minY;
int fishCnt; //먹은 물고기 수
int ans = 0;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

int bfs(int x, int y) {
	queue <pair<pair<int, int>,int>> q;
	q.push(make_pair(make_pair(x, y),0));
	check[x][y] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (x == nowX && y == nowY) {
			
			return cnt;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[nx][ny] &&  map[nx][ny] <= sharkSize) {
				
				check[nx][ny] = true;
				q.push(make_pair(make_pair(nx, ny), cnt + 1));
			}
		}
	}
	
	return 0;
	
}

bool findFish() {
	int cnt = 0; //먹을 수 있는 물고기 수 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == nowX && j == nowY) {
				continue;
				
			}
			if (map[i][j]!=0 && map[i][j] < sharkSize ) {
				init();
				
				
				int num2 = bfs(i, j);
				if (num2 != 0) {
					cnt++;
					if (num2 < minCnt) {
						minCnt = num2;
						minX = i;
						minY = j;
					}
					else if (num2 == minCnt) {
						if (minX > i) {
							minX = i;
							minY = j;
						}
						else if (minX == i) {
							if (minY > j) {
								minY = j;
							}
						}
					}
				}
			}
		}
	}
	if (cnt == 0) {
		return false;
	}
	return true;
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				nowX = i;
				nowY = j;
				map[i][j] = 0;
			}
		}
		
	}
	sharkSize = 2;

	while (true) {
		minCnt = 987654321;
		if (!findFish()) {
			break;
		}
		map[minX][minY] = 0;
		ans += minCnt;
		fishCnt += 1;
		nowX = minX;
		nowY = minY;
		if (fishCnt >= sharkSize) {
			sharkSize += 1;
			fishCnt = 0;
		}


	}

	cout << ans;
}