#include <iostream>
#include <string>
#include <algorithm>
#include <vector>



using namespace std;

int h, w;
int map[501][501];
int block[501];
int answer = 0;

int main(void) { // 3 2 1 0
	cin >> h >> w; // 4 4
	for (int i = 0; i < w; i++) {  
		cin >> block[i];
		int j = h - 1;
		int num = block[i];
		while (num--) {
			map[j][i] = 2;
			j--;
		}

	}
	if (w < 3) {
		cout << "0";
	}
	else {
		for (int i = 0; i < w - 2; i++) {
			int num2 = block[i]; //비교할 인덱스 블록개수
			bool check = false;
			int idx = -1;
			int num3 = -1;     //블록개수
			for (int j = i + 2; j < w; j++) {
				if (num3 < block[j]) {
					idx = j;
					num3 = block[j];
				}
			}
			if (num2 >= num3) { //num3기준으로 
				for (int j = i + 1; j <= idx - 1; j++) {
					answer += num3 - block[j];
				}

			}
			else {
				for (int j = i + 1; j <= idx - 1; j++) {
					answer += num2 - block[j];
				}
			}
			i = idx - 1;
		}

		/*for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cout << map[i][j];
			}
			cout << "\n";
		}*/

		cout << answer;
	}
	
}