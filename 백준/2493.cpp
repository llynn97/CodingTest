#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int n;
stack <pair<int, int>> st1;

int main(void) {
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (!st1.empty()) {
			if (num < st1.top().first) {
				cout << st1.top().second << " ";
				break;
			}
			st1.pop();
		}
		if (st1.empty()) {
			cout << "0" << " ";
		}
		st1.push(make_pair(num, i + 1));
		

	}
	
	

	
	

}