#include <iostream>
#include <string>
#include <algorithm>


using namespace std;
long long a, b, c;
int ans = 1;
int f(long long x,long long y,long long z) {
	if (y == 0) {
		return 1;
	}
	if (y == 1) {
		return x % z;
	}
	long long k = f(x, y/2, z);
	if (y % 2 == 0) {
		return k * k % z;
	}
	else {
		return k * k % z * x % z;
	}
	
	
}


int main(void) {
	cin >> a >> b >> c;
	cout<<f(a, b, c);

}