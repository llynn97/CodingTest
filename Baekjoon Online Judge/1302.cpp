#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n, t;
string s[1000];
bool check[1000];
int num[1000] = { 0, };
vector <string> v;

int main() {
	cin >> n;
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] == s[j]) {
				if (check[j] == false) {
					check[i] = check[j] = true;
					num[i]++;
				}
			}


		}

	}
	for (int i = 0; i < n; i++) {
		if (max < num[i]) {
			max = num[i];
			t = i;
		}
	}

	for (int i = 0; i < n; i++) {
		if (max == num[i]) {
			cnt++;
		}
	}

	if (cnt == 1) {
		cout << s[t];
	}
	else if (cnt > 1) {
		for (int i = 0; i < n; i++) {
			if (num[i] == max) {
				v.push_back(s[i]);
			}
		}
		sort(v.begin(), v.end());
		cout << v[0];
	}




	return 0;
}