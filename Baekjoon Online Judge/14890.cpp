#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, l;
int map[100][100];
bool check[100][100];
bool flag = false;
int cnt;

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check[i][j] = false;
		}
	}
}

void checkRow() {
	for (int i = 0; i < n; i++) {
		init();
		int j = 0;
		flag = false;
		while (j < n - 1) {
			if (map[i][j] != map[i][j + 1]) {
				if (map[i][j + 1] > map[i][j]) { // map[i][j+1] 칸 기준 앞으로 경사로 가능한지 확인
					int idx = j;
					if (l > j+1) { // 앞으로 l개가 가능한지 확인
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[i][idx] != (map[i][j+1] - 1) || check[i][idx]) { // 높이 차이가 1이 아니거나 이미 경사로가 있는 경우 
							flag2 = true;
							break;
						}
						idx--;

					}
					if (!flag2) { // 경사로를 놓을 수 있을 경우
						for (int k = j - l+1; k <= j; k++) {
							check[i][k] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				else if (map[i][j + 1] < map[i][j]) { //map[i][j] 칸 기준 뒤로 경사로 가능한지 확인
					int idx = j+1;
					if (j + l+1 > n) {
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[i][idx] != (map[i][j] - 1) || check[i][idx]) { // 높이 차이가 1이 아니거나 이미 경사로가 있는 경우 
							flag2 = true;
							break;
						}
						idx++;

					}
					
					if (!flag2) { // 경사로를 놓을 수 있을 경우
						for (int k = j + 1; k <= j+l; k++) {
							check[i][k] = true;
						}
						j = j + l - 1;
					}
					else {
						flag = true;
						break;
					}
				}
			}

			j++;
		}

		if (!flag) {
		
			cnt++;
		}
	}
}
void checkColumn() {
	for (int i = 0; i < n; i++) {
		init();
		int j = 0;
		flag = false;
		while (j < n - 1) {
			if (map[j][i] != map[j+1][i]) {
				if (map[j + 1][i] > map[j][i]) { // map[j+1][i] 칸 기준 앞으로 경사로 가능한지 확인
					int idx = j;
					if (l > j+1) { // 앞으로 l개가 가능한지 확인
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[idx][i] != (map[j+1][i] - 1) || check[idx][i]) { // 높이 차이가 1이 아니거나 이미 경사로가 있는 경우 
							flag2 = true;
							break;
						}
						idx--;

					}
					if (!flag2) { // 경사로를 놓을 수 있을 경우
						for (int k = j - l + 1; k <= j; k++) {
							check[k][i] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				else if (map[j+1][i] < map[j][i]) { //map[j][i] 칸 기준 뒤로 경사로 가능한지 확인
					int idx = j + 1;
					if (j + l + 1 > n) {
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[idx][i] != (map[j][i] - 1) || check[idx][i]) { // 높이 차이가 1이 아니거나 이미 경사로가 있는 경우 
							flag2 = true;
							break;
						}
						idx++;

					}

					if (!flag2) { // 경사로를 놓을 수 있을 경우
						for (int k = j + 1; k <= j + l; k++) {
							check[k][i] = true;
						}
						j = j + l - 1;
					}
					else {
						flag = true;
						break;
					}
				}
			}

			j++;
		}

		if (!flag) {
			
			cnt++;
		}
	}
}



int main(void) {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	checkRow();
	checkColumn();
	cout << cnt;
}