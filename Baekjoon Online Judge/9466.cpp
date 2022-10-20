#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int t;
int map[100001];
bool check[100001];
bool done[100001];
int n;
int cnt;
int ans = 0;

void init(int n2) {
	for (int i = 0; i <= n2; i++) {
		check[i] = false;
	    done[i] = false;
	}
}





void hasCycle(int idx) {
	check[idx] = true;
	int next = map[idx];
	if (!check[next]) {
		hasCycle(next);
	}
	else if (!done[next]) { //방문은 했지만 사이클이 아직 아닌 경우
		//ex)4->7->6->4 0->2->2
		for (int i = next; i != idx; i = map[i]) {
			cnt++;
		
		}
		cnt++;
	}
	done[idx] = true;
}

int main(void) {
	cin >> t;
	while (t--) {
		
		cnt = 0;
		cin >> n;
		init(n);
		for (int i = 1; i <= n; i++) {
			cin >> map[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!check[i]) {
				hasCycle(i);
			}
			
			
		}

		cout <<n-cnt << "\n";

	}

}