#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int num, a, target;

int main(void) {
	cin >> num;
	vector<int> v;
	for (int i = 0; i < num; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> target;
	sort(v.begin(), v.end());
	int l = 0;
	int r = num - 1;
	int cnt = 0;
	while (1) {
		if (l >= r) {
			break;
		}
		int sum = v[l] + v[r];
		if (sum == target) {
			l++;
			r--;
			cnt++;

		}
		else if (sum > target) {
			r--;
		}
		else {
			l++;
		}
	}
	cout << cnt;


}