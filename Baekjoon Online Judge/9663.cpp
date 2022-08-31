#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n;
int map[16]; //���ึ�� ü���� �����ִ� ���� ex) map[0]=4 -> 0�� 4��
//int check[16]; 
int cnt = 0;
int chess = 0;
void dfs(int chess) { //chess=>��
	if (chess == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		bool check = false;
		for (int j = 0; j < chess; j++) {
			if (map[j] == i || (abs(j - chess) == abs(map[j] - i))) { //chess�������� ���� ü���� ���� ���̰ų� ���� �밢���� �ִ��� Ȯ��
				//cout << j << " " << map[j] << "\n";
				check = true;
			}
		}
		if (!check) {//ü���� ���� �� ������
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