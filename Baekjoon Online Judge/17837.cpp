#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, k;
int a, b, c;
int map[13][13];
vector <pair<int, int>> chess[13][13]; // 번호, 방향
vector <pair<int, int>> order[13];
int moveCnt = 0;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

int changeDir(int d) {
	if (d == 1)return 2;
	if (d == 2)return 1;
	if (d == 3)return 4;

	if (d == 4)return 3;

}

bool moveHorse() {
	moveCnt = 0;
	for (int i = 1; i <= k; i++) {
		int x = order[i].front().first;
		int y = order[i].front().second;
		int dir = 0;
		int horseOrder = 0; //쌓인 말 순서
		for (int j = 0; j < chess[x][y].size(); j++) {
			if (chess[x][y][j].first == i) {
				dir = chess[x][y][j].second;
				horseOrder = j;
				break;
			}
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		vector <pair<int, int>> v; //옯길 말들
		vector <pair<int, int>> v2; // 옮기지 않을 말들
		if (horseOrder > 0) {
			for (int j = 0; j < horseOrder; j++) {
				v2.push_back(make_pair(chess[x][y][j].first, chess[x][y][j].second));
			}
		}
		for (int j = horseOrder; j < chess[x][y].size(); j++) {
			v.push_back(make_pair(chess[x][y][j].first, chess[x][y][j].second));
		}
		if (nx >= 1 && ny >= 1 && nx <= n && ny <= n) {
			if (map[nx][ny] == 0) {//흰색인경우
				for (int j = 0; j < v.size(); j++) {
					chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
					order[v[j].first].front().first = nx;
					order[v[j].first].front().second = ny;
					moveCnt++;
				}
				chess[x][y].clear();
				for (int j = 0; j < v2.size(); j++) {
					chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
				}
			}
			else if (map[nx][ny] == 1) { //빨간 인경우
				reverse(v.begin(), v.end());
				for (int j = 0; j < v.size(); j++) {
					chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
					order[v[j].first].front().first = nx;
					order[v[j].first].front().second = ny;
				}
				chess[x][y].clear();
				for (int j = 0; j < v2.size(); j++) {
					chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
				}
			}
			else { //파란 인경우
				dir = changeDir(dir);
				nx = x + dx[dir];
				ny = y + dy[dir];
				chess[x][y][horseOrder].second = dir;
				if (ny >= 1 && nx >= 1 && nx <= n && ny <= n && map[nx][ny] != 2) {
					if (map[nx][ny] == 1) {
						reverse(v.begin(), v.end());
						for (int j = 0; j < v.size(); j++) {
							if (j == v.size()-1) {
								chess[nx][ny].push_back(make_pair(v[j].first, dir));
							}
							else {
								chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
							}

							order[v[j].first].front().first = nx;
							order[v[j].first].front().second = ny;
						}
						chess[x][y].clear();
						for (int j = 0; j < v2.size(); j++) {
							chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
						}
					}
					else {
						for (int j = 0; j < v.size(); j++) {
							if (j == 0) {
								chess[nx][ny].push_back(make_pair(v[j].first, dir));
							}
							else {
								chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
							}

							order[v[j].first].front().first = nx;
							order[v[j].first].front().second = ny;
						}
						chess[x][y].clear();
						for (int j = 0; j < v2.size(); j++) {
							chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
						}
					}
					
				}
				else {
					//방향만 변경
				
				}
			}
		}
		else { //범위를 벗어난 경우
			dir = changeDir(dir);
			nx = x + dx[dir];
			ny = y + dy[dir];
			chess[x][y][horseOrder].second = dir;
			if (ny >= 1 && nx >= 1 && nx <= n && ny <= n && map[nx][ny] != 2) {
				if (map[nx][ny] == 1) {
					reverse(v.begin(), v.end());
					for (int j = 0; j < v.size(); j++) {
						if (j == v.size() - 1) {
							chess[nx][ny].push_back(make_pair(v[j].first, dir));
						}
						else {
							chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
						}

						order[v[j].first].front().first = nx;
						order[v[j].first].front().second = ny;
					}
					chess[x][y].clear();
					for (int j = 0; j < v2.size(); j++) {
						chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
					}
				}
				else {
					for (int j = 0; j < v.size(); j++) {
						if (j == 0) {
							chess[nx][ny].push_back(make_pair(v[j].first, dir));
						}
						else {
							chess[nx][ny].push_back(make_pair(v[j].first, v[j].second));
						}

						order[v[j].first].front().first = nx;
						order[v[j].first].front().second = ny;
					}
					chess[x][y].clear();
					for (int j = 0; j < v2.size(); j++) {
						chess[nx][ny].push_back(make_pair(v2[j].first, v2[j].second));
					}
				}
			}
			
		}
		//말이 4개 이상 쌓였는지 확인
		//if (chess[nx][ny].size() >= 4) {

			//return false;
		//}
		
	}
	return true;
}

bool checkCnt() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (chess[i][j].size() >= 4) {
				cout << chess[i][j].size() << "\n";
				return false;
				
			}
		}
	}
	return true;
}
int main(void) {
	int cnt = 1;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		cin >> a >> b >> c;
		order[i].push_back(make_pair(a, b));
		chess[a][b].push_back(make_pair(i, c)); // 번호,방향 
	}
	while (true) {
		if (cnt > 1000) {
			cout << -1;
			break;
			
		}
		
		moveHorse();
		
		
		cout << "========================\n";
		cout << cnt << "\n";
		cout <<"size: "<< chess[3][4].size() << "\n";
		for (int i = 1; i <= k; i++) {
			cout << "Ss: " << i << "번: " << order[i].front().first << " " << order[i].front().second << "\n";
		}
		cout << "=============================\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << chess[i][j].size() << " ";
			}
			cout << "\n";
		}
		cout << "=============================\n";
		if (!checkCnt()) {
			cout << cnt;
			break;
		}

		cnt++;
	}
}