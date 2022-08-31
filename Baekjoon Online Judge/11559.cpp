#include <iostream>
#include <string>
#include <queue>
#include <algorithm>


using namespace std;

int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
queue < pair<int, int>> q2; // 연결되어있는 뿌요들

char map[12][6]; //뿌요 필드
bool check[12][6];


void init() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			check[i][j] = false;
		}
	}
}

int bfs2(int x, int y) {

	char st = map[x][y]; //연결되어 있는 뿌요가 있는지 확인할 뿌요 색깔
	int cnt = 1; //st포함 st와 연결되어 있는 뿌요 개수
	q2.push(make_pair(x, y));
	check[x][y] = true;
	queue < pair<int, int>> q;
	q.push(make_pair(x, y));
	while (!q.empty()) { // st와 같은 색깔이고 연결되어있으면 q2 에 넣음 
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
				q2.push(make_pair(ny, nx)); //map[x][y]와 연결된 뿌요를 q2에 넣음

			}
		}
	}
	return cnt;
}

int bfs() {  
	int cnt2 = 0; //연결된 뿌요가 4개 이상 되어 터트린 횟수
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] != '.') {
				init();
				int num2 = bfs2(i, j);
				if (num2>= 4) { // 연결되어 있는 뿌요가 4개 이상일 경우만 터트림

					while (!q2.empty()) {
						int y = q2.front().first;
						int x = q2.front().second;
						map[y][x] = '.';   // 뿌요를 터트리고 빈칸으로 바꿈
						q2.pop();
						cnt2++;
					}

				}
				else { //4개 미만인 경우 q2 초기화
					while (!q2.empty()) {
						q2.pop();
					}
				}
			}
		}
	}
	return cnt2;
}



void downPuyo() { //뿌요들을 아래로 떨어뜨림
	vector <char> v; // 열마다 빈칸이 아닌 뿌요들을 넣음
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 12; j++) {
			if (map[j][i] != '.') {
				v.push_back(map[j][i]);
			}
		}
		if (v.size() != 0) {
			int idx = 11;
			for (int j = v.size() - 1; j >= 0; j--) { // map밑에서부터 v에 저장된 뿌요를 채워줌
				map[idx][i] = v[j];
				idx--;
			}
			for (int j = idx; j >= 0; j--) { //나머지는 빈칸으로 채워줌
				map[j][i] = '.';
			}

			v.clear();
		}
		
		
	}

}

int main(void) {
	int ans = 0; //연쇄 개수
	string s;
	for (int i = 0; i < 12; i++) {
		cin >> s;
		for (int j = 0; j < 6; j++) {
			map[i][j] = s[j];
		}
	}
	while (true) {
		
		int num = bfs(); //뿌요를 터트린 횟수
	
		if (num == 0) { //터트린 뿌요가 없을 경우 stop
			break;
		}
		ans++;
		downPuyo();
		
		
	}
	cout << ans;

}