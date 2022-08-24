#include <iostream>
#include <string>
#include <algorithm>
#include <vector>


using namespace std;

int n, m, k;
int a[11][11];
int map[11][11]; // 양분
int x, y, z;
vector <int> tree[11][11] ; // 살아 있는 나무
vector <int> dieTree[11][11]; //죽어 있는 나무

vector <int> v;

bool tmp(int a, int b) {
	return a > b;
}

int countTree() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cnt += tree[i][j].size();
		}
	}
	
	return cnt;
}

void plantTree(int x1, int y1) {
	for (int i = 0; i <= 1; i++) {
		for (int j = 0; j <= 1; j++) {
			if (i == 0 && j == 0) { continue; }
			if (x1 + i >= 0 && y1 + j >= 0 && x1 + i < n && y1 + j < n) { tree[x1 + i][y1 + j].push_back(1); }
			if (x1 - i >= 0 && y1 - j >= 0 && x1 - i < n && y1 - j < n) { tree[x1 - i][y1 - j].push_back(1); }
		}
	}
	if (x1 - 1 >= 0 && y1 + 1 >= 0 && x1 - 1 < n && y1 + 1 < n) { tree[x1 - 1][y1 + 1 ].push_back(1); }
	if (x1 + 1 >= 0 && y1 - 1 >= 0 && x1 + 1 < n && y1 - 1 < n) { tree[x1 + 1][y1 - 1].push_back(1); }


}

void changeSeason() {
	//봄
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int num = tree[i][j].size();
			
			sort(tree[i][j].begin(), tree[i][j].end(), tmp); //내림차순 정렬
			for (int p = num-1; p >= 0; p--) {
				int age = tree[i][j][p];
				
				
					if (age > map[i][j]) {
						dieTree[i][j].push_back(age);
						
					}
					else {
						v.push_back(age+1);
						map[i][j] -= age;
					}
				
			   
			}
			
			while (tree[i][j].size() != 0) {
				tree[i][j].pop_back();
			}
			while (v.size() != 0) {
				tree[i][j].push_back(v.back());
				v.pop_back();
			}
			
		}
	}
	//여름
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			while (dieTree[i][j].size() != 0) {
				map[i][j] += dieTree[i][j].back() / 2;
				dieTree[i][j].pop_back();
			}
		}
	}

	//가을
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int p = 0; p < tree[i][j].size(); p++) {
				
					if (tree[i][j][p] % 5 == 0) {
						plantTree(i,j);
					}
				
			}
		}
	}

	//겨울
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] += a[i][j];
		}
	}
	
}

int main(void) {
	cin >> n >> m >> k;
	bool check = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 5;
		}
	}
	

	while (k--) {

		changeSeason();
		if (countTree() == 0) {
			check = true;
			break;
		}
	}
	if (check) {
		cout << 0;
	}
	else {
		cout<< countTree();
	}
}