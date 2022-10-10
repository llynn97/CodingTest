#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, k;
int multiTap[101];
int order[101];
int ans = 0;

int main(void) {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> order[i];
	}
	for (int i = 0; i < k; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (multiTap[j] == order[i]) {
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		for (int j = 0; j < n; j++) {
			if (multiTap[j] == 0) {
				multiTap[j] = order[i];
				flag = true;
				break;
			}
		}
		if (flag) {
			continue;
		}
		int idx2 = -1;
		int ansIdx = -1;
		for (int j = 0; j < n; j++) {
			int lastIdx = 0;
			int next = i + 1;
			while (next < k && order[next] != multiTap[j]) {
				next++;
				lastIdx++;
			}
			if (lastIdx > idx2) {
				idx2 = lastIdx;
				ansIdx = j;
			}
		}
		ans++;
		multiTap[ansIdx] = order[i];
	}

	cout << ans;

}