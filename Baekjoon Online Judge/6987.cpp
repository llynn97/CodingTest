#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int map[7][4];
int map2[7][4];
int a, b, c;
int d;


bool answer[4];
int t1[15] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int t2[15] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

void dfs(int idx,int cnt) {
	if (cnt == 15) {
		if (answer[idx]) {
			return;
		}
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				if (map[i][j] != map2[i][j]) {
					return;
				}
			}
		}
		answer[idx] = true;
		return;
	}
	int team1 = t1[cnt];
	int team2 = t2[cnt];

	map2[team1][0] += 1;
	map2[team2][2] += 1;
	dfs(idx,cnt+1);
	map2[team1][0] -= 1;
	map2[team2][2] -= 1;

	
	map2[team1][1] += 1;
	map2[team2][1] += 1;
	dfs(idx, cnt + 1);
	map2[team1][1] -= 1;
	map2[team2][1] -= 1;


	map2[team1][2] += 1;
	map2[team2][0] += 1;
	dfs(idx, cnt + 1);
	map2[team1][2] -= 1;
	map2[team2][0] -= 1;


}




int main(void) {
	int idx = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 6; j++) {
			for (int k = 0; k < 3; k++) {
				cin >> map[j][k];
			}
		}
		dfs(i, 0);
	}
   
	for (int i = 0; i < 4; i++) {
		if (answer[i]) {
			cout << "1" << " ";
		}
		else {
			cout << "0" << " ";
		}
	}

}