#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int k;
int num;

long long ans;

stack <int> st;

int main(void) {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> num;
		if (num == 0) {
			st.pop();
		}
		else {
			st.push(num);
		}

	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}

	cout << ans;
}