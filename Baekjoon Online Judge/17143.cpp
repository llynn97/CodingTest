#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>


using namespace std;
int R, C, M;
vector <pair<pair<int, int>, pair<pair<int, int>, int>>>  map[102][102];

int r, c, s, d, z;
int ans = 0;
int dx[4] = { -1,1,0,0 }; // 위 아래 우 좌
int dy[4] = { 0,0,1,-1 };


int changeDir(int di) {
	if (di == 1) return 2;
    if (di == 2) return 1;
    if (di == 3) return 4;
    if (di == 4) return 3;
}





void moveShark(vector<pair<pair<int, int>, pair<pair<int, int>, int>>> smap[102][102]) {

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (!map[i][j].empty()) {
				int x = map[i][j].front().first.first;
				int y = map[i][j].front().first.second;
				int speed = map[i][j].front().second.first.first;
				int dir = map[i][j].front().second.first.second;
				int size = map[i][j].front().second.second;
				map[i][j].pop_back();
				int speeds = speed;
				while (speeds--) {
					int nx = x + dx[dir - 1];
					int ny = y + dy[dir - 1];
					if (nx < 1 || ny < 1 || nx > R || ny > C) {
						dir = changeDir(dir);
						

					}
					x += dx[dir - 1];
					y += dy[dir - 1];
				}
				//cout << "s: " << size << " " << x <<" "<< y<<"\n";
				if (!smap[x][y].empty()) { // 상어가 이미 칸에 존재했을 때 
					if (smap[x][y][0].second.second < size) { //큰 상어 남기기
						smap[x][y].pop_back(); 
						smap[x][y].push_back(make_pair(make_pair(x, y), make_pair(make_pair(speed, dir), size)));
					}
				}
				else {
					smap[x][y].push_back(make_pair(make_pair(x, y), make_pair(make_pair(speed, dir), size)));
				}
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			
				map[i][j] = smap[i][j];
			
		}
	}


}
	
		
	

 
int main(void) {
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) s %= ((R - 1) * 2);
		if (d == 3 || d == 4) s %= ((C - 1) * 2);
		
		map[r][c].push_back(make_pair(make_pair(r, c), make_pair(make_pair(s, d), z)));
	}
	int idx = 0; //현재 낚시왕 열 
	
	while (true) {
		if (idx > C) {
			break;
		}
		idx++;
		for (int i = 1; i <= R; i++) { //가장 가까운 상어 잡기
			if (!map[i][idx].empty()) {
				ans += map[i][idx][0].second.second;
				map[i][idx].pop_back();
				break;
			}
		}
		vector<pair<pair<int, int>, pair<pair<int, int>, int>>> smap[102][102];
	
		moveShark(smap);
		
		
		
	}
	cout << ans;
}