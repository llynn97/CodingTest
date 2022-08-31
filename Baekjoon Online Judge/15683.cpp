#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int n, m;
int map[9][9];
int copyMap[9][9];
vector <pair<pair<int, int>, pair<int, int>>> v;
int cctv_num;
int answer = 987654321;

int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
void copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyMap[i][j] = map[i][j];
		}
	}
}
void right(int x, int y) {
	for (int i = y + 1; i < m; i++) {
		if (copyMap[x][i] == 6) {
			break;
		}
		if (1 <= copyMap[x][i] && copyMap[x][i] <= 5) {
			continue;
		}
		copyMap[x][i] = -1;
	}
}

void left(int x, int y) {
	for (int i = y - 1; i >= 0; i--) {
		if (copyMap[x][i] == 6) {
			break;
		}
		if (1 <= copyMap[x][i] && copyMap[x][i] <= 5) {
			continue;
		}
		copyMap[x][i] = -1;
	}
}

void up(int x, int y) {
	for (int i = x - 1; i >= 0; i--) {
		if (copyMap[i][y] == 6) {
			break;
		}
		if (1 <= copyMap[i][y] && copyMap[i][y] <= 5) {
			continue;
		}
		copyMap[i][y] = -1;
	}
}

void down(int x, int y) {
	for (int i = x + 1; i < n; i++) {
		if (copyMap[i][y] == 6) {
			break;
		}
		if (1 <= copyMap[i][y] && copyMap[i][y] <= 5) {
			continue;
		}
		copyMap[i][y] = -1;
	}
}

void checkArea() {
	copy();
	for (int i = 0; i < v.size(); i++) {
		if (v[i].second.first == 1) { //cctv번호가 1번일때
			if (v[i].second.second == 0) {
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1) {
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2) {
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3) {
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 2) {
			if (v[i].second.second == 0 || v[i].second.second==1) {
				right(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			if (v[i].second.second == 2 || v[i].second.second == 3) {
				up(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 3) {
			if (v[i].second.second == 0) {
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1) {
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2) {
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3) {
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 4) {
			if (v[i].second.second == 0) {
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 1) {
				up(v[i].first.first, v[i].first.second);
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 2) {
				right(v[i].first.first, v[i].first.second);
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
			}
			else if (v[i].second.second == 3) {
				down(v[i].first.first, v[i].first.second);
				left(v[i].first.first, v[i].first.second);
				up(v[i].first.first, v[i].first.second);
			}
		}
		else if (v[i].second.first == 5) {
			right(v[i].first.first, v[i].first.second);
			left(v[i].first.first, v[i].first.second);
			up(v[i].first.first, v[i].first.second);
			down(v[i].first.first, v[i].first.second);
		}
	}
}

int countNum() { //사각지대(=0) 개수 세기
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 0) {
				sum++;
			}
		}
	}
	return sum;
}

void setCCTV(int cnt) {
	if (cnt == cctv_num) {
		checkArea();
		answer = min(answer, countNum());
		return;
	}

	v[cnt].second.second = 0;
	setCCTV(cnt + 1);

	v[cnt].second.second = 1;
	setCCTV(cnt + 1);

	v[cnt].second.second = 2;
	setCCTV(cnt + 1);

	v[cnt].second.second = 3;
	setCCTV(cnt + 1);
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (1 <= map[i][j] && map[i][j] <= 5) {
				v.push_back(make_pair(make_pair(i, j), make_pair(map[i][j], -1)));
			}
		}
	}
	cctv_num = v.size();

	setCCTV(0);
	cout << answer;
}