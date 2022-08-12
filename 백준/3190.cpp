#include <queue>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, l;

int X;
char c;
int map[101][101];
queue <pair<int, char>> dirs;
queue <pair<int, int>> snake;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int cnt = 0; //�ɸ� �ð�

int changeDir(char s, int dir) {
	int dir2 = 0;
	if (s == 'L') { //�������� ȸ��
		dir2 = (dir + 3) % 4;
	}
	if (s == 'D') { //���������� ȸ��
		dir2 = (dir + 1) % 4;
	}
	
	return dir2;
}

void doGame() {
	queue <pair<pair<int, int>, int>> q; //��ǥ , ����
	q.push(make_pair(make_pair(0, 0), 1));
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second;
		q.pop();
		if (!dirs.empty() && cnt == dirs.front().first) {
			dir = changeDir(dirs.front().second, dir);
			dirs.pop();
		}
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		cnt++;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n || map[nx][ny]==2) { // ���̰ų� �ڱ��ڽŸ��� ��� ���� ����
			break;
		}
		else {
			if (map[nx][ny] != 1) { // �̵��� ĭ�� ����� ���� ��, ������ ��ġ�� ĭ�� 0���� �ٲ���
				if (!snake.empty()) {
					map[snake.front().first][snake.front().second] = 0;
					snake.pop();
				}
				
			}
			
			q.push(make_pair(make_pair(nx, ny), dir));
			snake.push(make_pair(nx, ny));
			map[nx][ny] = 2; //���� �ִ� ĭ�� 2
		}
		
		
		

	}
}

int main(void) {
	int p = 0;
	int t = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> p >> t;
		map[p-1][t-1] = 1; //����� 1
	}
	cin >> l;
	for (int i = 0; i < l; i++) {
		cin >> X >> c;
		dirs.push(make_pair(X, c));
	}
	snake.push(make_pair(0, 0));
	doGame();
	cout << cnt;
}