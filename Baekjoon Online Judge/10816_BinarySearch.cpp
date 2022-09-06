#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, card;
vector <int> v;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		v.push_back(card);
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;
		cout << upper_bound(v.begin(), v.end(), card) - lower_bound(v.begin(), v.end(), card) << " ";
	}
}