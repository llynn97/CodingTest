#include <iostream>
#include <string>
#include <algorithm>
#include <stack>


using namespace std;

stack <char> st;

bool wrong;

int main(void) {
	string s;
	cin >> s;
	int temp = 1;
	int ans = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') {
			temp *= 2;
			st.push('(');
			
		}
		if (s[i] == ')') {
			if (st.empty()) {
				wrong = true;
				break;
			}
			else if (st.top() == '(') {
				if (s[i-1] == '(') {
					ans += temp;
				}
				temp /= 2;
				st.pop();
					
			}
			else {
				wrong = true;
				break;
			}
		}
		if (s[i] == '[') {
			temp *= 3;
			st.push('[');
		}
		if (s[i] == ']') {
			
			if (st.empty() ) {
				wrong = true;
			}
			else if (st.top() == '[') {
				if (s[i - 1] == '[') {
					ans += temp;
			     }
				temp /= 3;
				st.pop();
			}
			else {
				wrong = true;
				break;
			}
		}
	}

	if (!st.empty() || wrong) {
		cout << "0";
	}
	else {
		cout << ans;
	}
}