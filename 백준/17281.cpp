#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n;
int map[50][9];
bool check[9];
vector <int> v;
int order[9];
int map2[5]; 
int nowOrder,score;

void init() {
	for (int i = 0; i <= 4; i++) {
		map2[i] = 0;
	}
}



int doGame(int orderIdx,int idx) {
	int outCount = 0;
	int num = 0;
	int i = orderIdx;
	while(true){
		if (map[idx][order[i]] == 0) { //아웃 일 때 
			outCount++;
		}
		else if (map[idx][order[i]] == 1) {
			for (int j = 3; j >= 1; j--) {
				if (map2[j] > 0) {
					if (j + 1 >= 4) {
						num++;
						map2[j] = 0;
					}
					else {
						map2[j + 1] = map2[j];
						map2[j] = 0;

					}
				}
			}
			map2[1] = order[i] + 1;
		}
		else if (map[idx][order[i]] == 2) {
			for (int j = 3; j >= 1; j--) {
				if (map2[j] > 0) {
					if (j + 2 >= 4) {
						num++;
						map2[j] = 0;
					}
					else {
						map2[j + 2] = map2[j];
						map2[j] = 0;
					}
				}
			}
			map2[2] = order[i] + 1;
		}
		else if (map[idx][order[i]] == 3) {
			for (int j = 3; j >= 1; j--) {
				if (map2[j] > 0) {
					if (j + 3 >= 4) {
						num++;
						map2[j] = 0;
					}
					else {
						map2[j + 3] = map2[j];
						map2[j] = 0;
					}
				}
			}
			map2[3] = order[i] + 1;
		}
		else if (map[idx][order[i]] == 4) { //홈런일 때 
			for (int j = 3; j >= 1; j--) {
				if (map2[j] > 0) {
					num++;
					map2[j] = 0;
				}
			}
			num++;
		}
		if (outCount == 3) {
			nowOrder = (i + 1) % 9;
			
			return num;
			break;
		}
		i = (i + 1) % 9;
	
	}

}

void decideOrder(int cnt) {
	if (cnt == 8) {
		int idx = 0;
		for (int i = 0; i < 9; i++) {
			if (i == 3) {
				continue;
			}
			order[i] = v[idx];
			idx++;
		}
	
		
		
		
		int num3 = 0;
		int ans = 0;
		while (num3<=n-1) { //n이닝동안 게임 진행
			init();
			int num4 = doGame(nowOrder, num3);
			
			ans += num4;
			num3++;
		}
	
		score = max(score, ans);
		nowOrder = 0;
		return;

		

	
	}
	for (int i = 0; i < 9; i++) {
		if (i == 0) {
			continue;
		}
		if (!check[i]) {
			check[i] = true;
			v.push_back(i);
			decideOrder(cnt + 1);
			check[i] = false;
			v.pop_back();
		}
		
	}
	
}

int main(void) {
	cin >> n;
	order[3] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> map[i][j];
		}
	}

	decideOrder(0);

	cout << score;
}