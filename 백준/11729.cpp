#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int start, int mid, int end, int n) {
	if (n == 1) {
		cout << start << " " << end<<"\n";
	}
	else {
		hanoi(start, end, mid, n - 1);
		cout << start << " " << end << "\n";
		hanoi(mid, start, end, n - 1);
	}
}

int main(void) {
	int num;
	cin >> num;
	cout << (int)pow(2, num) - 1<< "\n";
	hanoi(1, 2, 3, num);

}