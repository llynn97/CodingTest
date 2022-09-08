#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;


int n;
long long m;
vector <long long> v;
vector <long long> v2;


int main(void) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
		v2.push_back(m);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < n; i++) {
		cout << lower_bound(v.begin(), v.end(), v2[i]) - v.begin() << " ";
	}
}