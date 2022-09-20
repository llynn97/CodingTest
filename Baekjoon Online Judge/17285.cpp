#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int order[11];
int moveNum[4]; // 각 경로 별로 움직여야하는 최대 칸 수 //21 13 17 23 
int map[4][30]; //점수 
bool visit[4][30]; //이미 윷이 있는지
bool check[4][30]; // 경로가 겹치는 점
int ans = 0;
vector < pair<pair<int, int>, pair<int, bool>>> yut[4]; //파란색 원의 번호, 윷 위치, 윷 점수, 윷이 도착했는지 

void init() {
	moveNum[0] = 21; //파란색을 건너지 않는 경우
	moveNum[1] = 13; //파란색10을 지날때
	moveNum[2] = 17; //파란색20을 지날때 
	moveNum[3] = 23; //파란색30을 지날때
	check[1][9] = check[1][10] = check[1][11] = check[1][12] = true;
	check[2][13] = check[2][14] = check[2][15] = check[2][16] = true;
	check[3][19] = check[3][20] = check[3][21] = check[3][22] = true;
	check[0][1] = check[0][2] = check[0][3] = check[0][4] = check[0][20] = true;
	for (int i = 1; i <= 20; i++) {
		map[0][i] = 2 * i;

	}
	map[1][6] = 13;
	map[1][7] = 16;
	map[1][8] = 19;
	map[1][9] = 25;
	map[1][10] = 30;
	map[1][11] = 35;
	map[1][12] = 40;
	map[2][11] = 22;
	map[2][12] = 24;
	map[2][13] = 25;
	map[2][14] = 30;
	map[2][15] = 35;
	map[2][16] = 40;
	map[3][16] = 28;
	map[3][17] = 27;
	map[3][18] = 26;
	map[3][19] = 25;
	map[3][20] = 30;
	map[3][21] = 35;
	map[3][22] = 40;
	for (int i = 1; i <= 5; i++) {
		map[1][i] = map[0][i];
	}
	for (int i = 1; i <= 10; i++) {
		map[2][i] = map[0][i];
	}
	for (int i = 1; i <= 15; i++) {
		map[3][i] = map[0][i];
	}
	
}
vector < pair<pair<pair<int, int>, pair<int, bool>>,bool>> getState(int idx, int idx2) {
	vector < pair<pair<pair<int, int>, pair<int, bool>>, bool>> v;
	int prev = yut[idx].front().first.second; //윷 현재 위치
	int next = yut[idx].front().first.second + order[idx2]; //이동하려는 위치
	int startCircle = yut[idx].front().first.first; //시작한 파란색 원 번호
	bool selectCircle = false; // 이동해서 파란색 원인지
	bool finish = false; //도착했는지 여부
	if (startCircle == 0) { //아직 파란색에서 시작하지 않았을 때
		if (prev == 5 || prev == 10 || prev == 15) { //파란색에서 시작했을 때
			selectCircle = true;
			startCircle = prev / 5; //파란색 원의 번호
		}
	}
	if (next >= moveNum[startCircle]) {
		finish = true;
	}
	v.push_back(make_pair(make_pair(make_pair(prev, next), make_pair(startCircle, finish)),selectCircle));
	return v;
	
}

bool checkVisit2(int circle, int pos) { // 경로에 겹치는 점에 다른 윷이 존재하는지
	if (circle == 0) { //파란색에서 시작한 적이 없을 때
		if (pos == 20) { //20번은 모든 경로가 지나는 점
			if (visit[1][12] == true || visit[2][16] == true || visit[3][22] == true) {
				return false;
			}
			else {
				if (visit[0][pos] == true) {
					return false;
				}
			}
		}
	 }
	else if (circle == 1) { //파란색 10에서 시작했을 때 
		if (visit[2][pos + 4] == true || visit[3][pos + 10] == true) {
			return false;
		}
		if (pos == 12) {
			if (visit[0][20] == true) {
				return false;
			}
		}
	}
	else if (circle == 2) {
		if (visit[1][pos - 4] == true || visit[3][pos + 6] == true) {
			return false;
		}
		if (pos == 16) {
			if (visit[0][20] == true) {
				return false;
			}
		}
	}
	else if (circle == 3) {
		if (visit[1][pos - 10] == true || visit[2][pos - 6] == true) {
			return false;
		}
		if (pos == 22) {
			if (visit[0][20] == true) {
				return false;
			}
		}
	}
	return true;
}


bool checkVisit(vector < pair<pair<pair<int, int>, pair<int, bool>>, bool>> v, int idx) { //윷이 움직일 수 있는지
	if (check[v.front().first.second.first][v.front().first.first.second] == true) { //점을 지나는 경로가 여러개 일때 

		if (checkVisit2(v.front().first.second.first, v.front().first.first.second) == false) { // 윷이 있는지 확인
			
			return false;
		}
	}
	if (visit[v.front().first.second.first][v.front().first.first.second] == true) {
		
		return false;
	}
	
	return true;
	
}

void moveYut(vector < pair<pair<pair<int, int>, pair<int, bool>>, bool>> v,int idx ,bool flag) {
	if (flag == true) {
		if (v.front().first.second.second == true) { // 움직여서 윷이 도착했을 때
			visit[v.front().first.second.first][v.front().first.first.first] = false; //현재 좌표 방문 체크 해제
			yut[idx].front().first.second = v.front().first.first.second;
			yut[idx].front().second.second = true; //도착완료
		}
		else {
			if (v.front().second == true) { // 이번에 움직여서 파란색 점에서 이동 시작일 경우
				yut[idx].front().first.first = v.front().first.second.first;
				visit[0][v.front().first.first.first] = false;
			}
			else {
				visit[yut[idx].front().first.first][v.front().first.first.first] = false;
			}
			visit[yut[idx].front().first.first][v.front().first.first.second] = true;
			yut[idx].front().first.second = v.front().first.first.second;
			yut[idx].front().second.first = yut[idx].front().second.first + map[yut[idx].front().first.first][v.front().first.first.second];
		}
	}
	else { // 실행 취소
		if (v.front().first.second.second == true) { //도착했으면
			visit[v.front().first.second.first][v.front().first.first.first] = true;
			yut[idx].front().first.second = v.front().first.first.first;
			yut[idx].front().second.second = false;
		}
		else {
			if (v.front().second == true) {
				visit[0][v.front().first.first.first] = true;
				visit[yut[idx].front().first.first][v.front().first.first.second] = false;
				yut[idx].front().first.second = v.front().first.first.first;
				yut[idx].front().second.first = yut[idx].front().second.first - map[yut[idx].front().first.first][v.front().first.first.second];
				yut[idx].front().first.first = 0;
			}
			else {
				visit[yut[idx].front().first.first][v.front().first.first.first] = true;
				visit[yut[idx].front().first.first][v.front().first.first.second] = true;
				yut[idx].front().first.second = v.front().first.first.first;
				yut[idx].front().second.first = yut[idx].front().second.first - map[yut[idx].front().first.first][v.front().first.first.second];
			}
		}
		
	}
	
}


void dfs(int cnt) {
	if (cnt == 10) {
		int tmp = 0;
		for (int i = 0; i < 4; i++) {
			tmp += yut[i].front().second.first;
			
		}
		if (ans < tmp) {
			ans = tmp;
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (yut[i].front().second.second == true) { //윷이 이미 도착했으면 넘어감
			continue;
		}
		vector < pair<pair<pair<int, int>, pair<int, bool>>,bool>> v=getState(i, cnt);
		if (checkVisit(v, i) == false) {
			continue;
		}
		moveYut(v, i, true);
		dfs(cnt + 1);
		moveYut(v, i, false);
	}
}

int main(void) {
	for (int i = 0; i < 10; i++) {
		cin >> order[i];
	}
	init();
	dfs(0);
	cout << ans;
	

}

