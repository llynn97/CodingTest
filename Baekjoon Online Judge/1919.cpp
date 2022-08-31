#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string s1;
string s2;
int alpha[26];
int main(void) {
	int cnt = 0;
	cin >> s1;
	cin >> s2;
	for (int i = 0; i < 26; i++) {
		alpha[i] = -1;
	}
	for (int i = 0; i < s1.length(); i++) {
		char a = s1[i];
		int b = a - 'a';
		if (alpha[b] == -1) {
			alpha[b] = 1;
		}
		else {
			alpha[b]++;
		}
	}
	for (int i = 0; i < s2.length(); i++) {
		char a = s2[i];
		int b = a - 'a';
		if (alpha[b] >= 1) {
			cnt++;
			alpha[b]--;
		}
	}
	int answer = s1.length() + s2.length() - 2 * cnt;
	cout << answer;

}