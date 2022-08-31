#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

int r, c, k;
int map[101][101];
int ans;
int aRowSize;
int aColSize;
int check[101];
vector <pair<int, int>> v; 
vector <int> v2[101];

bool tmp(pair<int,int> a, pair<int,int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	else {
		return a.first < b.first;
	}
}

void init() {
	for (int i = 0; i < 101; i++) {
		check[i] = 0;
	}
}
void init2(int row, int colum) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < colum; j++) {
			map[i][j] = 0;
		}
	}
}

void sortRow(int sizeRow, int sizeColumn) {
	
	int maxColumn = 0;
	for (int i = 0; i < sizeRow; i++) {
		init();
		for (int j = 0; j < sizeColumn; j++) {
			int num = map[i][j];
			check[num]++;

		}
		
		for (int j = 1; j <= 100; j++) {
			if (check[j] > 0) {
				v.push_back(make_pair(check[j], j)); // È½¼ö, ¼ö
			}
		}
		
		
		int snum = v.size();
		if (v.size() > 50) {
			maxColumn = 50;
		}
		else {
			maxColumn = max(maxColumn, snum);
		}
		
		sort(v.begin(), v.end(), tmp);
		
		

		
		for (int j = 0; j < v.size(); j++) {
			v2[i].push_back(v[j].second);
			v2[i].push_back(v[j].first);
		}
		
		v.clear();
		
	}
	init2(sizeRow, sizeColumn);
	for (int i = 0; i < sizeRow; i++) {
		if (v2[i].size() > 100) {
			for (int j = 0; j < 100; j++) {

				map[i][j] = v2[i][j];

			}
		}
		else {
			for (int j = 0; j < v2[i].size(); j++) {

				map[i][j] = v2[i][j];

			}
		}
		
		
	}
	for (int i = 0; i < sizeRow; i++) {
		v2[i].clear();
	}
	
		aColSize = maxColumn * 2;
}

void sortColumn(int sizeRow, int sizeColumn) {
	
	int maxRow = 0;
	for (int i = 0; i < sizeColumn; i++) {
		init();
		for (int j = 0; j < sizeRow; j++) {
			int num = map[j][i];
			check[num]++;

		}
		
		
		for (int j = 1; j <= 100; j++) {
			if (check[j] > 0) {
				v.push_back(make_pair(check[j], j)); // È½¼ö, ¼ö
			}
		}
		int snum = v.size();
		if (v.size() > 50) {
			maxRow = 50;
		}
		else {
			maxRow = max(maxRow, snum);
		}
		
		sort(v.begin(), v.end(), tmp);
		for (int j = 0; j < v.size(); j++) {
			v2[i].push_back(v[j].second);
			v2[i].push_back(v[j].first);
		}
		v.clear();

	}
	init2(sizeRow, sizeColumn);
	for (int i = 0; i < sizeColumn; i++) {
		if (v2[i].size() > 100) {
			for (int j = 0; j < 100; j++) {

				map[j][i] = v2[i][j];

			}
		}
		else {
			for (int j = 0; j < v2[i].size(); j++) {

				map[j][i] = v2[i][j];

			}
		}
		
	}
	for (int i = 0; i < sizeColumn; i++) {
		v2[i].clear();
	}
	aRowSize = maxRow * 2;
}

int main(void) {
	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> map[i][j];
		}
	}
	
	aRowSize = 3;
	aColSize = 3;
	while (true) {
		if (ans > 100) {
			break;
		}

		if (map[r - 1][c - 1] == k) {
			break;
		}

		init();

		if (aRowSize >= aColSize) {
			
			sortRow(aRowSize,aColSize);
		}
		else {
			sortColumn(aRowSize,aColSize);
		}	

		ans++;
	}
	if (ans > 100) {
		cout << -1;
	}
	else {
		cout << ans;
	}
	
}