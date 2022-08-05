#include <iostream>
#include <string>
#include <queue>
#include <algorithm>


using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue < pair<int, int>> q2; // ����Ǿ��ִ� �ѿ��

char map[12][6]; //�ѿ� �ʵ�
bool check[12][6];


void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			check[i][j] = false;
		}
	}
}

int bfs2(int x, int y) {

	char st = map[x][y]; //����Ǿ� �ִ� �ѿ䰡 �ִ��� Ȯ���� �ѿ� ����
	int cnt = 1; //st���� st�� ����Ǿ� �ִ� �ѿ� ����
	q2.push(make_pair(x, y));
	check[x][y] = true;
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) { // st�� ���� �����̰� ����Ǿ������� q2 �� ���� 
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < 6 && ny < 12 && !check[ny][nx] && map[ny][nx] == st) {
				check[ny][nx] = true;
				q.push(make_pair(ny, nx));
				cnt++;
				q2.push(make_pair(ny, nx)); //map[x][y]�� ����� �ѿ並 q2�� ����

			}
		}
	}
	return cnt;
}

int bfs() {  
	int cnt2 = 0; //����� �ѿ䰡 4�� �̻� �Ǿ� ��Ʈ�� Ƚ��
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.') {
				init();
				int num2 = bfs2(i, j);
				if (num2>= 4) { // ����Ǿ� �ִ� �ѿ䰡 4�� �̻��� ��츸 ��Ʈ��

					while (!q2.empty()) {
						int y = q2.front().first;
						int x = q2.front().second;
						map[y][x] = '.';   // �ѿ並 ��Ʈ���� ��ĭ���� �ٲ�
						q2.pop();
						cnt2++;
					}

				}
				else { //4�� �̸��� ��� q2 �ʱ�ȭ
					while (!q2.empty()) {
						q2.pop();
					}
				}
			}
		}
	}
	return cnt2;
}



void downPuyo() { //�ѿ���� �Ʒ��� ����߸�
	vector <char> v; // ������ ��ĭ�� �ƴ� �ѿ���� ����
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[j][i] != '.') {
				v.push_back(map[j][i]);
			}
		}
		if (v.size() != 0) {
			int idx = 11;
			for (int j = v.size() - 1; j >= 0; j--) { // map�ؿ������� v�� ����� �ѿ並 ä����
				map[idx][i] = v[j];
				idx--;
			}
			for (int j = idx; j >= 0; j--) { //�������� ��ĭ���� ä����
				map[j][i] = '.';
			}

			v.clear();
		}
		
		
	}

}

int main(void) {
	int ans = 0; //���� ����
	string s;
	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++) {
			map[i][j] = s[j];
		}
	}
	while (true) {
		
		int num = bfs(); //�ѿ並 ��Ʈ�� Ƚ��
	
		if (num == 0) { //��Ʈ�� �ѿ䰡 ���� ��� stop
			break;
		}
		ans++;
		downPuyo();
		
		
	}
	cout << ans;

}