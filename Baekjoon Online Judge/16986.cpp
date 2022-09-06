#include <iostream>
#include <algorithm>
#include <string>
#include <vector>


using namespace std;

int n, k;
int map[10][10];
int order[4][21];
int vicCnt[4];
bool check[10];
vector <int> v;
int gamer1, gamer2;



void init() {
	for (int i = 1; i <= 3; i++) {
		vicCnt[i] = 0;
	}
}
// 지우 경희 민호 순  1 2 3 
bool doGame() {
	int round = 1;
	int idxJw = 1;
	int idxMh = 1;
	int idxKh = 1;
	while (true) {
		if (vicCnt[1] >= k) {
			return true;
		}
		if (vicCnt[2] >= k || vicCnt[3] >= k) {
			return false;
		}
		if (idxJw > n) {
			return false;
		}

		int next;
		if ((gamer1 == 1 && gamer2 == 2) || (gamer2 == 1 && gamer1 == 2)) {
			next = 3;
		}
		if ((gamer1 == 2 && gamer2 == 3) || (gamer2 == 2 && gamer1 == 3)) {
			next = 1;
		}
		if ((gamer1 == 1 && gamer2 == 3) || (gamer2 == 1 && gamer1 == 3)) {
			next = 2;
		}

		int num1 = 0;
		int num2 = 0;
		if (gamer1 == 1) {
			num1 = order[gamer1][idxJw];
		}

		if (gamer1 == 2) {
			num1 = order[gamer1][idxKh];
		}
		if (gamer1 == 3) {
			num1 = order[gamer1][idxMh];
		}

		if (gamer2 == 1) {
			num2 = order[gamer2][idxJw];
		}

		if (gamer2 == 2) {
			num2 = order[gamer2][idxKh];
		}
		if (gamer2 == 3) {
			num2 = order[gamer2][idxMh];
		}


		if (gamer1 == 1 || gamer2 == 1) {
			idxJw++;
		}
		if (gamer1 == 2 || gamer2 == 2) {
			idxKh++;
		}
		if (gamer1 == 3 || gamer2 == 3) {
			idxMh++;
		}


		if (map[num1][num2] == 2) { // 상성 확인

			vicCnt[gamer1]++;
			gamer2 = next;
		}
		else if (map[num1][num2] == 0) {

			vicCnt[gamer2]++;

			gamer1 = gamer2;
			gamer2 = next;
		}
		else { //비겼을 때

			if (gamer1 > gamer2) {
				vicCnt[gamer1]++;
				gamer2 = next;

			}
			else {
				vicCnt[gamer2]++;

				gamer1 = gamer2;
				gamer2 = next;
			}
		}



		round++;
	}
	return false;


}

void dfs(int cnt) { // 손동작 순서 정하기
	if (cnt == n) {
		for (int i = 0; i < v.size(); i++) {
			order[1][i + 1] = v[i];
		}
		init();
		gamer1 = 1; //승자
		gamer2 = 2; // 그 다음 순서
		if (doGame()) {
			cout << 1;
			exit(0);
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!check[i]) {
			v.push_back(i);
			check[i] = true;
			dfs(cnt + 1);
			v.pop_back();
			check[i] = false;
		}
	}
}
int main(void) {

	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 1; i <= 20; i++) {
		cin >> order[2][i];
	}
	for (int i = 1; i <= 20; i++) {
		cin >> order[3][i];
	}
	if (n < k) {
		cout << 0;

	}
	else {
		gamer1 = 1; //승자
		gamer2 = 2; // 그 다음 순서
		dfs(0);
		cout << 0;
	}




}