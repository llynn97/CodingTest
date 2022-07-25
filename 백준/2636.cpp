#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

int n, m;
char map[101][101];
int check[101][101];
bool check2[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int answer = 0;
int tim;
queue<pair<int, int>> q2; //녹을 치즈 좌표
 
void divAir() { //치즈 외부 내부 공기 나누기 -> 내부 공기: 0 , 외부 공기: 1  치즈:-1
	check[0][0] = 1;
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && check[ny][nx] == 0) {
				check[ny][nx] = 1;
				q.push(make_pair(ny, nx));
				q2.push(make_pair(ny, nx));

				
			}
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			check2[i][j] = false;
		}
	}
}

void divAir2() { //치즈 외부 내부 공기 나누기 -> 내부 공기: 0 , 외부 공기: 1  치즈:-1
	init();
	queue <pair<int, int>> q;
	q.push(make_pair(0, 0));
	check2[0][0] = true;
	while (!q.empty()) {
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && !check2[ny][nx] &&check[ny][nx] != -1) {
				if (check[ny][nx] == 1) {
					check2[ny][nx] = true;
					q.push(make_pair(ny, nx));
				}
				if (check[ny][nx] == 0) {
					check2[ny][nx] = true;
					check[ny][nx] = 1;
					q.push(make_pair(ny, nx));
					q2.push(make_pair(ny, nx));
				}
				


			}
		}
	}
}

void meltCheese() {
	queue <pair<int, int>> q1;
	while (!q2.empty()) {
		int x = q2.front().second;
		int y = q2.front().first;
		q2.pop();
		q1.push(make_pair(y, x));
	}
	while (!q1.empty()) {
		int x = q1.front().second;
		int y = q1.front().first;
		q1.pop();
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (nx >= 0 && ny >= 0 && nx < m && ny < n && check[ny][nx] == -1) {
				q2.push(make_pair(ny, nx));
				check[ny][nx] = 1;
			}
		}
	}
	
	
}

int cntCheese() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == -1) {
				cnt++;
			}
		}
	}
	return cnt++;
}

bool checkCheese() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (check[i][j] == -1) {
				return false;
			}
		}
	}
	return true;
}

void printCheck() {
	cout << "222==================\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << check[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "====================\n";
}




int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

	

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == '1') {
				check[i][j] = -1;
			}
			if (map[i][j] == '0') {
				check[i][j] = 0;
			}
		}
	}
	divAir();

	


	while (true) {
		if (checkCheese()) {
			break;
		}
		answer = cntCheese();
		divAir2();
		meltCheese();
		
		tim++;

	}
	cout << tim << " " << answer;
}