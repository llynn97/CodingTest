#include <iostream>
#include <string>
#include <vector>


using namespace std;

long long t, n, x;
int main(void) {
	cin >> t;
	
	while (t--) {
		cin >> n;
		vector<long long> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		long long result = 0;
		long long maxNum = -1;
		for (int i = n - 1; i >= 0; i--) {
			maxNum = max(v[i], maxNum);
			result += maxNum - v[i];
		}
		cout << result << "\n";
		

	}
}