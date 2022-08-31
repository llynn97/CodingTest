#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int map[5][5][5];
bool check[5][5][5];
int smap[5][5][5]; //90도 회전하는 배열
int smap2[5][5][5];  //판 순서 바꾸는 배열

bool check1[5] = { false, };

int n1=0;
vector <int> v;
int ans = 987654321;
int dx[6] = { 0,0,1,-1,0,0 };
int dy[6] = { 1,-1,0,0,0,0 };
int dk[6] = { 0,0,0,0,1,-1 };

void initCheck() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				check[i][j][k] = false;
			}
		}
	}
}


void rotateMap(int idx) { // map[][][idx]을 90도 시계방향 회전
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			smap[j][5 - i - 1][idx] = map[i][j][idx];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			map[i][j][idx] = smap[i][j][idx];
		}
	}
}

int bfs(int x, int y, int k, int cnt, int x1, int y2, int k2) {
	queue <pair<pair<int, int>, pair<int, int>>> q;
	q.push(make_pair(make_pair(x, y), make_pair(k, cnt)));
	check[x][y][k] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second.first;
		int cnt = q.front().second.second;
		if (x == x1 && y == y2 && k == k2) {
			return cnt;
		}
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nk = k + dk[i];
			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && nk >= 0 && nk < 5 && smap2[nx][ny][nk] == 1 && !check[nx][ny][nk]) {
				check[nx][ny][nk] = true;
				q.push(make_pair(make_pair(nx, ny), make_pair(nk, cnt + 1)));
			}
		}
		
	}

	return -1;

}

void moveMap() { //입구를 정해서 출구까지 이동하기
	
	initCheck();
	int num2 = bfs(0, 0, 0, 0, 4, 4, 4); //출구까지 이동한 횟수
	if (num2 != -1) {
		ans = min(ans, num2);
	}
}

void changeMap(int cnt) { //판 순서 바꾸기
	
	
	if (cnt == 5) {
		int idx2 = 0;
		for (int i = 0; i < v.size(); i++) {
			int idx = v[i];
			
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					smap2[j][k][idx2] = map[j][k][idx];
				}
			}
			idx2++;
		}
		if (smap2[0][0][0] != 0 && smap2[4][4][4] != 0) {
			moveMap();
		}

		return;
	}
	for (int i = 0; i < 5; i++) {
		if (v.size() == 0 || (v.size() != 0 && !check1[i])) {
			check1[i] = true;
			v.push_back(i);
			changeMap(cnt + 1);
			v.pop_back();
			check1[i] = false;
		}
	}
}





void decideMap() { //1줄씩 90도 시계방향으로 회전해가며 판을 쌓음
	for (int k = 0; k < 4; k++) {
		rotateMap(n1);
		for (int l = 0; l < 4; l++) {
			rotateMap(n1 + 1);
			for (int m = 0; m < 4; m++) {
				rotateMap(n1 + 2);
				for (int n = 0; n < 4; n++) {
					rotateMap(n1 + 3);
					for (int p = 0; p < 4; p++) {
						rotateMap(n1 + 4);

						changeMap(0);
						
					}
				}
			}
		}
	
	}
}





int main(void) {
	for (int k = 0; k < 5; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				cin >> map[i][j][k];
			}
		}
	}
	
	decideMap();
	

	if (ans == 987654321) {
		cout << "-1";
	}
	else {
		cout << ans;
	}

	
	
}