#include <iostream>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;

int n;
int A[21][21];
int map[21][21];
int check[6];
bool check2[21][21];
int popu[6];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };



int diff(int x, int y, int d1, int d2) {
	vector<int> population(5, 0);

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			//1번 선거구
			if (r < x + d1 && c <= y && !(r >= x && c >= y - (r - x))) {
				population[0] += A[r][c];
			}
			//2번 선거구
			else if (r <= x + d2 && c > y && !(r >= x && c <= y + (r - x))) {
				population[1] += A[r][c];
			}
			//3번 선거구
			else if (r >= x + d1 && c < y - d1 + d2 && !(r <= x + d1 + d2 && c >= (y - d1 + d2 - (x + d1 + d2 - r)))) {
				population[2] += A[r][c];
			}
			//4번 선거구
			else if (r > x + d2 && c >= y - d1 + d2 && !(r <= x + d1 + d2 && c <= (y - d1 + d2 + (x + d1 + d2 - r)))) {
				population[3] += A[r][c];
			}
			//5번 선거구
			else {
				population[4] += A[r][c];
			}
		}
	}

	sort(population.begin(), population.end());

	return population[4] - population[0];
}






int main(void) {
	cin >> n;
	int ans = 987654321;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> A[i][j];
		}
		
	}
	for (int x = 1; x <= n - 2; x++) {
		for (int y = 2; y <= n - 1; y++) {
			for (int d1 = 1; d1 <= y - 1 && d1 <= n - x - 1; d1++) {
				for (int d2 = 1; d2 <= n - y && d2 <= n - x - 1; d2++) {
					
					ans=min(ans,diff(x, y, d1, d2));
				}
			}
		}
	}
	cout << ans;
	
}