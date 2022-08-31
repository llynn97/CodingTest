#include <iostream>
#include <vector>

using namespace std;
int map[21][21];

int dx[4] = { 0,0,-1, 1 };
int dy[4] = { 1,-1,0,0 };
int dice[7] = { 0, };
int sdice[7] = { 0, };
int n, m, k, x, y;
int p;


void moveDice(int num) {
	if (num == 1) {
		sdice[1] = dice[4];
		sdice[2] = dice[2];
		sdice[3] = dice[1];
		sdice[4] = dice[6];
		sdice[5] = dice[5];

		sdice[6] = dice[3];
	}
	else if (num == 2) {
		sdice[1] = dice[3];
		sdice[2] = dice[2];
		sdice[3] = dice[6];
		sdice[4] = dice[1];
		sdice[5] = dice[5];

		sdice[6] = dice[4];
	}
	else if (num == 3) {
		sdice[1] = dice[5];
		sdice[2] = dice[1];
		sdice[3] = dice[3];
		sdice[4] = dice[4];
		sdice[5] = dice[6];

		sdice[6] = dice[2];
	}
	else if (num == 4) {
		sdice[1] = dice[2];
		sdice[2] = dice[6];
		sdice[3] = dice[3];
		sdice[4] = dice[4];
		sdice[5] = dice[1];

		sdice[6] = dice[5];
	}
}
int main(void) {
	cin >> n >> m >> x >> y >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int order;
		cin >> order;
		int nx = x + dx[order - 1];
		int ny = y + dy[order - 1];

		if (nx >= 0 && ny >= 0 && nx < n && ny < m) {
			moveDice(order);

			if (map[nx][ny] == 0) {
				map[nx][ny] = sdice[6];
			}
			else {
				sdice[6] = map[nx][ny];
				map[nx][ny] = 0;
			}
			cout << sdice[1] << "\n";
			for (int j = 0; j < 7; j++) {
				dice[j] = sdice[j];
			}
			x = nx;
			y = ny;

		}



	}

	return  0;



}