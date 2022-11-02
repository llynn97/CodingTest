#include<iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int s;
bool check[2001][2001]; //È­¸é/clip


int bfs() {
	queue <pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 0), 0));
	check[1][0] = true;
	while (!q.empty()) {
		int mon = q.front().first.first;
		int clip = q.front().first.second;
		int cnt = q.front().second;
		q.pop();
		if (mon == s) {
			return cnt;
		}
		
		if (mon>0 && mon<2000 && !check[mon][mon]) {
			check[mon][mon] = true;
			q.push(make_pair(make_pair(mon, mon), cnt+1));
		}
		if (mon > 0 && mon < 2000 && !check[mon - 1][clip]) {
			check[mon - 1][clip] = true;
			q.push(make_pair(make_pair(mon-1, clip), cnt + 1));
		}
		if (clip > 0 && (mon + clip) < 2000) {
			if (!check[mon + clip][clip]) {
				check[mon + clip][clip] = true;
				q.push(make_pair(make_pair(mon+clip, clip), cnt + 1));

			}
		}
	}
}

int main(void) {


	cin >> s;
	cout<<bfs();
	

}