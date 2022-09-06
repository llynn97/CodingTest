#include <iostream>
#include <unordered_map>

using namespace std;

int n, m, card;
unordered_map <int, int> hm;

int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		hm[card]++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> card;
		cout << hm[card] << " ";
	}
}