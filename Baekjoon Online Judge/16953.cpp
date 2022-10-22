#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

long long a, b;
int ans = 987654321;

void dfs(long long num,int cnt) {
	//cout << "num: " << num << "\n";
	if (num == b) {
		ans = min(ans, cnt);
		return;
	}
	if (num > 1000000001) {
		return;
	}

	
	
	dfs(num*2, cnt + 1);
	dfs(stoll(to_string(num)+"1"), cnt + 1);
	
}

int main(void) {

	cin >> a >> b;
	dfs(a, 0);
	if (ans == 987654321) {
		cout << "-1";
	}
	else {
		cout << ans+1;
	}

}