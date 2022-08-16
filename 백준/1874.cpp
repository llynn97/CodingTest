#include <iostream>
#include <vector>
#include <stack>


using namespace std;

int n;
int num;
stack <int> s;
vector <char> v;

int main(void) {
	int cnt = 1;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> num;
		while (cnt <= num) {
			s.push(cnt);
			cnt += 1;
			v.push_back('+');
		}
		if (s.top() == num) {
			s.pop();
			v.push_back('-');
		}
		else {
			cout << "NO";
			return 0;
		}
	}
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}