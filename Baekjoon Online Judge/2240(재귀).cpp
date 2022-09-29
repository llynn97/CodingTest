#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int pum[1005];
int dp[3][31][1005];
int T, W,num;


int solve(int t, int w, int dir ) { // 시간 , 이동 횟수, 자두의 위치
	if (t > T || w > W) {
		return 0;
	}
	int& ret= dp[dir][w][t];  // memoization
	if (ret != -1) {
		return ret;
	}
	ret = 0;
	int dir2 = 0;
	if (dir == 1) {
		dir2 = 2;
	}
	else {
		dir2 = 1;
	}

	if (dir == pum[t]) { //현재 위치에 자두가 떨어질 때 
		
		ret = max(solve(t+1,w,dir),solve(t+1,w+1,dir2)) + 1;
	}
	else {
		ret = solve(t + 1, w, dir);
		if (w < W) {
			ret = max(ret, solve(t + 1, w + 1, dir2)+1);
		}
	}
	

	return ret;
}


int main(void) {
	cin >> T >> W;
	for (int i = 1; i <= T; i++) {
		cin >> pum[i];
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 31; j++) {
			for (int k = 0; k < 1005; k++) {
				dp[i][j][k] = -1;
			}
		}
	}
	cout<<solve(1, 0, 1);
}