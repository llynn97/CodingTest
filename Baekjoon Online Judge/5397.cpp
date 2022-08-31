#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

stack <char> s1;
stack <char> s2;
vector <char> v;

int main(void) {
	string s;
	string ans = "";
	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		ans = "";
		for (int j = 0; j < s.length(); j++) {
			char s3 = s[j];
			if (s3 == '<') {
				if (!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
				
			}
			else if (s3 == '>'){
				if (!s2.empty()) {
					s1.push(s2.top());
					s2.pop();
				}
				
			}
			else if (s3 == '-') {
				if (!s1.empty()) {
					s1.pop();
				}
				
			}
			else {
				s1.push(s3);
			}
		}
		while (!s1.empty()) {
			v.push_back(s1.top());
			s1.pop();
		}
		for (int j = v.size() - 1; j >= 0; j--) {
			ans += v[j];
		}
		v.clear();
		while (!s2.empty()) {
			ans += s2.top();
			s2.pop();
		}
		cout << ans << "\n";
	}
}