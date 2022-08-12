#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, r, c;
int ans = 0;
void funcZ(int x, int y,int size) {
	if (c == x && r == y) {
		cout << ans;
		return;
	}
	else if (x + size > c && y + size > r && y <= r && x <= c) {
		funcZ(x, y, size / 2);
		funcZ(x + size / 2, y, size / 2);
		funcZ(x, y + size / 2,size/2);
		funcZ(x + size / 2, y + size / 2, size / 2);
	}
	else {
		ans += size * size;
	}
	
}

int main(void) {

	cin >> n >> r >> c;

	 funcZ(0, 0, pow(2,n));
	 


}