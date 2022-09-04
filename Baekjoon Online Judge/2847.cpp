#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int map[20001];
int n,maxNum;
int ans;
int main(void) {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	maxNum = map[n - 1]-1;
	for (int i = n - 2; i >= 0; i--) {
		if (maxNum > map[i]) {
			maxNum = map[i]-1;
			continue;
		}
		ans += (map[i] - maxNum);
		maxNum -= 1;
	}
	cout << ans;
}