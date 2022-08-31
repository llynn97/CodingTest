#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
int n, k, cnt, result;
vector <int> v;
bool check[100001];

void bfs(int x, int num) {
	result = 3423523;
	queue <pair<int, int>> q;
	q.push(make_pair(x, 0));
	check[x] = true;
	while (!q.empty()) {
		x = q.front().first;
		num = q.front().second;
		check[x] = true;
		q.pop();
		if (x == k) {
			cnt = num;
			result = min(result, num);

		}
		if (x - 1 >= 0 && x - 1 <= 100000) {
			if (!check[x - 1]) {
				q.push(make_pair(x - 1, num + 1));
			}

		}
		if (x + 1 >= 0 && x + 1 <= 100000) {
			if (!check[x + 1]) {
				q.push(make_pair(x + 1, num + 1));
			}

		}
		if (2 * x >= 0 && 2 * x <= 100000) {
			if (!check[2 * x]) {
				q.push(make_pair(2 * x, num));
			}

		}
	}

}
int main() {
	cin >> n >> k;
	bfs(n, 0);
	cout << result;
	return 0;
}