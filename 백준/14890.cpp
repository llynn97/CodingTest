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
				if (map[i][j + 1] > map[i][j]) { // map[i][j+1] ĭ ���� ������ ���� �������� Ȯ��
					int idx = j;
					if (l > j+1) { // ������ l���� �������� Ȯ��
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[i][idx] != (map[i][j+1] - 1) || check[i][idx]) { // ���� ���̰� 1�� �ƴϰų� �̹� ���ΰ� �ִ� ��� 
							flag2 = true;
							break;
						}
						idx--;

					}
					if (!flag2) { // ���θ� ���� �� ���� ���
						for (int k = j - l+1; k <= j; k++) {
							check[i][k] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				else if (map[i][j + 1] < map[i][j]) { //map[i][j] ĭ ���� �ڷ� ���� �������� Ȯ��
					int idx = j+1;
					if (j + l+1 > n) {
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[i][idx] != (map[i][j] - 1) || check[i][idx]) { // ���� ���̰� 1�� �ƴϰų� �̹� ���ΰ� �ִ� ��� 
							flag2 = true;
							break;
						}
						idx++;

					}
					
					if (!flag2) { // ���θ� ���� �� ���� ���
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
				if (map[j + 1][i] > map[j][i]) { // map[j+1][i] ĭ ���� ������ ���� �������� Ȯ��
					int idx = j;
					if (l > j+1) { // ������ l���� �������� Ȯ��
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[idx][i] != (map[j+1][i] - 1) || check[idx][i]) { // ���� ���̰� 1�� �ƴϰų� �̹� ���ΰ� �ִ� ��� 
							flag2 = true;
							break;
						}
						idx--;

					}
					if (!flag2) { // ���θ� ���� �� ���� ���
						for (int k = j - l + 1; k <= j; k++) {
							check[k][i] = true;
						}
					}
					else {
						flag = true;
						break;
					}
				}
				else if (map[j+1][i] < map[j][i]) { //map[j][i] ĭ ���� �ڷ� ���� �������� Ȯ��
					int idx = j + 1;
					if (j + l + 1 > n) {
						flag = true;
						break;
					}
					int num = l;
					bool flag2 = false;
					while (num--) {
						if (map[idx][i] != (map[j][i] - 1) || check[idx][i]) { // ���� ���̰� 1�� �ƴϰų� �̹� ���ΰ� �ִ� ��� 
							flag2 = true;
							break;
						}
						idx++;

					}

					if (!flag2) { // ���θ� ���� �� ���� ���
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