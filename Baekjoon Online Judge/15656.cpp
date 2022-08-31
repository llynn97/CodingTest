#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;
int n, m, cnt;
vector <int> v1;
vector <int> v2;
bool check[10001];

void go(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << v2[i] << " ";
		}
		cout << "\n";
		return;
	}
	else {
		for (int i = 0; i < n; i++) {
			
			v2.push_back(v1[i]);
			go(cnt + 1);
			v2.pop_back();
		
		}
	}
}
int main() {
	cin >> n >> m;
	v1.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> v1[i];
	}
	sort(v1.begin(), v1.end());
	go(0);
	return 0;
}