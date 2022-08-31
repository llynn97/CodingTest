#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;
char a, b, c;
int map[27][2];

void preOrder(int k) { //전위 순회
	if (k == -1) {
		return;
	}
	cout << (char)('A' + k);
	preOrder(map[k][0]);
	preOrder(map[k][1]);

}

void inOrder(int k) { //중위 순회
	if (k == -1) {
		return;
	}
	inOrder(map[k][0]);
	cout << (char)('A' + k);
	inOrder(map[k][1]);
}

void postOrder(int k) {//후위 순위
	if (k == -1) {
		return;
	}
	postOrder(map[k][0]);
	postOrder(map[k][1]);
	cout << (char)('A' + k);
}
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b == '.') {
			map[a-'A'][0] = -1;
		
		}
		else {
			map[a -'A'][0] = b - 'A';
		}
		if (c == '.') {
			map[a - 'A'][1] = -1;
			

		}
		else {
			map[a - 'A'][1] = c - 'A';
		}
		
	}
	preOrder(0);
	cout << "\n";
	inOrder(0);
	cout << "\n";
	postOrder(0);
}