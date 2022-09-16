#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, m, t;
int map[54][54];
int map2[54];
int map3[54][54];
int x1, d1, k1;

void changeDir(int dir,int row) {
	
	if (dir == 1) { // 시계 방향
		for (int j = 0; j < k1; j++) {
			
			for (int i = m - 1; i >= 1; i--) {
				map2[i-1] = map[row][i];
			}
			map2[m-1] = map[row][0];
			for (int i = 0; i < m; i++) {
				map[row][i] = map2[i];
			}
		}
	}
	if (dir == 0) { //반시계 방향
		for (int j = 0; j < k1; j++) {
			for (int i = 0; i < m-1; i++) {
				map2[i + 1] = map[row][i];
			}
			map2[0] = map[row][m - 1];
			for (int i = 0; i < m; i++) {
				map[row][i] = map2[i];
			}
		}
		
	}
	
}

void copyMap() {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			map3[i][j] = map[i][j];
		}
	}
}

void rotate(int num, int dir, int k2) {
	int cnt = 0; // 인접한 숫자 개수
	int sum = 0;
	int numCnt = 0;
	int start = 1;
	while (start * num <= n) {
		changeDir(dir, start * num);
		start++;
	}
	copyMap();
	
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			int num1 = map[i][j];
			sum += num1;
			bool flag = false;
			if (num1 != 0) {
				numCnt++;
				if (map[i - 1][j] == num1) {
					cnt++;
					flag = true;
					map3[i - 1][j] = 0;
				}
				if (map[i + 1][j] == num1) {
					cnt++;
					flag = true;
					map3[i + 1][j] = 0;
				}
				if (j != 0 && map[i][j - 1] == num1) {
					cnt++;
					flag = true;
					map3[i][j - 1] = 0;
				}
				if (map[i][j + 1] == num1) {
					cnt++;
					flag = true;
					map3[i][j + 1] = 0;
				}
				if (j == m - 1 && map[i][0] == num1) {
					cnt++;
					flag = true;
					map3[i][0] = 0;
				}
			}
			if (flag) {
				map3[i][j] = 0;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = map3[i][j];
		}
	}
	
	
	if (cnt == 0) { // 인접한 수가 없을 경우
		double num3 = (double)sum / (double)numCnt; //원판에 적힌 수 평균
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] != 0) {
					if (num3 > map[i][j]) {
						map[i][j] += 1;

					}
					else if (num3 < map[i][j]) {
						map[i][j] -= 1;

					}
				}
			}
		}
	}

}

int main(void) {
	cin >> n >> m >> t;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];

		}
	}
	for (int i = 0; i < t; i++) {
		cin >> x1 >> d1 >> k1;
		rotate(x1, d1, k1);
	
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < m; j++) {
			ans += map[i][j];

		}
	}
	cout << ans;
	

	
}