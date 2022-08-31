#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int n;

stack <pair<int, int>> st;
long long ans = 0;

int main(void) {
	int num = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		
		while (!st.empty()&&st.top().first<num) {
			ans += st.top().second;
			st.pop();
		}
		if (st.empty()) {
			st.push(make_pair(num, 1));
		}
		else {
			if (st.top().first == num) {
				int cnt = st.top().second;
				st.pop();
				if (!st.empty()) {
					ans++;
				}
				ans += cnt;
				st.push(make_pair(num, cnt + 1));
			}
			else {
				ans += 1;
				st.push(make_pair(num, 1));
			}
			
		}
		
	}

	cout << ans;

}


