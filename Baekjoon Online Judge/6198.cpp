#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int n;
int temp;
stack <int> s1;
long long ans = 0;

int main(void) {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> temp;
		while (!s1.empty() && s1.top() <= temp) {
			s1.pop();
		}
		s1.push(temp);
		
		ans += s1.size() - 1;
		
	}
	cout << ans;
	
}