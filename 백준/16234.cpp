#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
bool nochange; //인 구 이 동 이 있 는 지 확 인
int n, l, r;

int map[51][51];
bool check[51][51];

int ny[4] = { 0,0,1,-1 };
int nx[4] = { 1,-1,0,0 };

void bfs(int i, int j) {
	int sc = 1;
	int sum = map[i][j];
	queue <pair<int, int>> q;
	queue <pair<int, int>> q2; //다 시 인 구 조 정 할 좌 표 넣 음
	q.push(make_pair(i, j));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		//	cout<<map[x][y]<<"\n";
		q2.push(make_pair(x, y));
		q.pop();
		for (int i = 0; i < 4; i++) {
			int dy = y + ny[i];
			int dx = x + nx[i];
			if (dy < n && dx < n && dy >= 0 && dx >= 0) {
				if (!check[dx][dy] && (abs(map[x][y] - map[dx][dy]) >= l && abs(map[x][y] - map[dx][dy]) <= r)) {
					check[dx][dy] = true;
					sc++;
					//	cout<<map[dx][dy]<<" ";
					sum += map[dx][dy];
					q.push(make_pair(dx, dy));

				}
			}
		}
	}
	if (sc >= 2) {
		//cout<<sum<<" "<<sc<<"\n";
		int change = sum / sc;
		while (!q2.empty()) {
			int x1 = q2.front().first;
			int y1 = q2.front().second;
			//	cout<<x1<<","<<y1<<"\n";
			q2.pop();
			map[x1][y1] = change;

			nochange = true;


		}
	}
	/*for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<"\n";
	}*/
}

int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int ans = 0;
	nochange = true;
	while (nochange == true) {
		nochange = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == false) {
					check[i][j] = true;
					bfs(i, j);
				}
			}
		}
		if (nochange == true) {
			ans++;
		}
	}
	cout << ans;


	return 0;
}