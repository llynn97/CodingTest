#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int map[16]; //각행마다 체스가 놓여있는 열값 ex) map[0]=4 -> 0행 4열
//int check[16]; 
int cnt = 0;
int chess = 0;
void dfs(int chess) { //chess=>행
	if (chess == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < chess; j++) {
			if (map[j] == i || (abs(j - chess) == abs(map[j] - i))) { //chess행전까지 놓은 체스와 같은 열이거나 같은 대각선상에 있는지 확인
				//cout << j << " " << map[j] << "\n";
				check = true;
			}
		}
		if (!check) {//체스를 놓을 수 있으면
			map[chess] = i;
			dfs(chess + 1);
		}
	}

}


int main(void) {

	cin >> n;
	dfs(0);
	cout << cnt;


}