#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>


using namespace std;

stack <int> s;

int n;
int map[1000001];
vector <int>v;
int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = n - 1; i >= 0; i--) {
		int num = map[i];
		while (!s.empty()) {
			if (s.top() >num) {
				v.push_back(s.top());
				break;
			}
			s.pop();
		}
		if (s.empty() ) {
			v.push_back(-1);
			s.push(num);
		}
		else {
			
				s.push(num);
			
			
		}
		
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		cout << v[i] << " ";
	}
}