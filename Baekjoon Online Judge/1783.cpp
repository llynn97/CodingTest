#include<iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int n, m;
int answer;
int main(void) {

	cin >> n >> m;

	if (n == 1) {
		answer = 1;
	}
	else if (n == 2) {
		answer = min(4, (m + 1) / 2);
	}
	else {
		if (m <= 6) {
			answer = min(m, 4);
		}
		else {
			answer = m - 2;
		}
	}
	cout << answer;
}