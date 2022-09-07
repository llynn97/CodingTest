#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;

int n,a,b,c;
int map[100001][2];

int lastNode = 0;
int edgeCount = 0;
int rightCount = 0;

void inOrder(int node) {
	if (node == -1) {
	
		return;
	}
	
	inOrder(map[node][0]);
	edgeCount++;
	lastNode = node;
	
	inOrder(map[node][1]);
}

void dfs(int node) {
	if (node == lastNode) {
		return;
	}
	rightCount++;
	dfs(map[node][1]);
}


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		map[a][0] = b;
		map[a][1] = c;
	}
	inOrder(1);
	dfs(1);
	
	cout << (edgeCount - 1) * 2 - rightCount << " ";
}