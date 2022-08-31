#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {
	int n;
	int num = 0;
	int sum = 0;
	vector <int> v;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		v.push_back(t);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++) {
		num = v[i] + num;
		sum = sum + num;
	}
	cout << sum;
	return 0;
}