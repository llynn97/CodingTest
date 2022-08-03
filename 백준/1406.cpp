#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

stack <char> s1;
stack <char> s2;
string s;
string answer = "";
int num;
char a,b;
vector <char> v;
int main(void) {
	cin >> s;
	cin >> num;
	for (int i = 0; i < s.length(); i++) {
		s1.push(s[i]);
	}
	for (int i = 0; i < num; i++) {
		cin >> a;
		if (a == 'P') {
			cin >> b;
		}

		if (a == 'L') {
			if (!s1.empty()) {
				char a1 = s1.top();
				s1.pop();
				s2.push(a1);
			}
		}
		else if(a == 'D') {
			if (!s2.empty()) {
				char a2 = s2.top();
				s2.pop();
				s1.push(a2);
			}
		}
		else if (a == 'B') {
			if (!s1.empty()) {
				s1.pop();
			}
		}
		else  {
			s1.push(b);
		}
	}
	while (!s1.empty()) {
		v.push_back(s1.top());
		s1.pop();
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		answer += v[i];
	}
	while (!s2.empty()) {
		answer += s2.top();
		s2.pop();
	}
	cout << answer;


}