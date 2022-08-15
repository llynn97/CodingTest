#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
char map[11][11];
int redX, redY, blueX, blueY, holeX, holeY;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
bool check[11][11][11][11];

int ans = 0;

int bfs() {
	queue <pair<pair<pair<int, int>, pair<int, int>>, int>> q;
	q.push (make_pair(make_pair(make_pair(redX, redY), make_pair(blueX, blueY)),0));
	check[redX][redY][blueX][blueY] = true;
	while (!q.empty()) {
		int rX = q.front().first.first.first;
		int rY = q.front().first.first.second;
		int bX = q.front().first.second.first;
		int bY = q.front().first.second.second;
		int cnt = q.front().second;
		q.pop();
		if (cnt >= 10) {
			
			return 987654321;
		}
		
		for (int i = 0; i < 4; i++) {
			
			int nrX = rX;
			int nrY = rY;
			int nbX = bX;
			int nbY = bY;
			int flag = 0;
			while (true) {
				flag = 0;
				if (map[nrX][nrY] == 'O') {
					flag = 1;
				}
				else if (map[nrX + dx[i]][nrY + dy[i]] != '#') { //���� ����
					if (nrY + dy[i] != nbY || nrX + dx[i] != nbX) {
						nrY += dy[i];
						nrX += dx[i];
					}
					else { // �Ķ� ������ ��ġ�� ������ �̵� ����
						flag = 1;
					}
				}
				else { // ���� ��� �̵� ����
					flag = 1;
				}

				if (map[nbX][nbY] == 'O') {
					flag += 1;
				}
				else if (map[nbX + dx[i]][nbY + dy[i]] != '#') {
					if (nbY + dy[i] != nrY || nbX + dx[i] != nrX) {
						nbY += dy[i];
						nbX += dx[i];
					}
					else { // ���� ������ ������ �� 
						if (map[nrX][nrY] == 'O') { //���� ��, �Ķ� �� ���ÿ� �� ���
							nbX = nrX;
							nbY = nrY;
						}
						flag += 1;
					}
				}
				else {//���� ���
					flag += 1;
				}

				if (flag >= 2) {
					break;
				}
			}
			if (map[nbX][nbY] == 'O') {
				continue;
			}
			if (map[nrX][nrY] == 'O') {
				return cnt + 1;
			}
			if (check[nrX][nrY][nbX][nbY]) {
				continue;
			}
			check[nrX][nrY][nbX][nbY] = true;
			q.push(make_pair(make_pair(make_pair(nrX, nrY), make_pair(nbX, nbY)), cnt+1));

		
		}

		
	

			
			
		
	}

	return 987654321;
}


int main(void) {
	string s;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) {
			map[i][j] = s[j];
			if (map[i][j] == 'R') {
				redX = i;
				redY = j;
			}
			if (map[i][j] == 'B') {
				blueX = i;
				blueY = j;
			}
			
		}
	}

	
	

	ans = bfs();
	if (ans == 987654321) {
		cout << "-1";
	}
	else {
		cout << ans;

	}
}