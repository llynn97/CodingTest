#include <iostream>
#include <string>


using namespace std;

int map[10];

void init() {
	for (int i = 0; i < 10; i++) {
		map[i] = 0;
	}
}

int main(void) {
	int ans = 0;
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int num = s[i] - '0';
		
		map[num]++;
	}
	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9) {
			continue;
		}
		ans = max(ans, map[i]);
    }
	int num2 = (map[6] + map[9])/2;
	if ((map[6]+map[9]) % 2 == 0) {
		ans = max(ans, num2);
	}
	else {
		ans = max(ans, num2 + 1);
	}

	cout << ans;

}