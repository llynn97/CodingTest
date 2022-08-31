#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>


using namespace std;

int n;
int map[101][101];
int x, y, d, g;
int dy[4] = { 1,0,-1,0 };// 오른 , 위, 왼 , 아래
int dx[4] = { 0,-1,0,1 };
vector <int> v;
vector <int> v2;
/*
  0 1
  0 1 2 1
  0 1 2 1 2 3 2 1
*/

void check(int x, int y, int d, int g) {
	int tx = x;
	int ty = y;
	v.push_back(d);
	if (g >= 1) {
		for (int i = 1; i <= g; i++) {
			for (int j = v.size() - 1; j >= 0; j--) {
				v2.push_back(v[j]);
			}
			for (int j = 0; j < v2.size(); j++) {
				v.push_back((v2[j] + 1) % 4);
			}

			v2.clear();
		}
	}

	map[ty][tx] = 1;
	for (int i = 0; i < v.size(); i++) {
		int ny = ty + dy[v[i]];
		int nx = tx + dx[v[i]];
		map[ny][nx] = 1;
		tx = nx;
		ty = ny;
	}
	v.clear();
	v2.clear();

}

int countSquare() {
	int cnt = 0;
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1) {
				cnt++;
			}
		}

	}
	return cnt;
}

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y >> d >> g; //d: 시작 방향  g: 세대 
		check(y, x, d, g);

	}


	cout << countSquare();


}