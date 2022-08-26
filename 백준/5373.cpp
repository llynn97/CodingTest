#include<iostream>
#include<cstring>
#include<vector>
#include<string>

using namespace std;

int n, tc;
vector < pair<char, char>> v;
vector <char> cube[7];

int selectNum(char dir) {
	if (dir == 'U') return 1; //À§
	else if (dir == 'D') return 2; //¾Æ·¡
	else if (dir == 'F') return 3; //¾Õ
	else if (dir == 'B') return 4; //µÚ
	else if (dir == 'L') return 5; //¿Þ 
	else if (dir == 'R') return 6; //¿À
}

void rotate1(char num, char dir) {
	int num1 = selectNum(num);
	if (dir == '+') {
		int tmp1 = cube[num1].at(0);
		cube[num1].at(0) = cube[num1].at(6);
		cube[num1].at(6) = cube[num1].at(8);
		cube[num1].at(8) = cube[num1].at(2);
		cube[num1].at(2) = tmp1;

		int tmp2 = cube[num1].at(1);
		cube[num1].at(1) = cube[num1].at(3);
		cube[num1].at(3) = cube[num1].at(7);
		cube[num1].at(7) = cube[num1].at(5);
		cube[num1].at(5) = tmp2;

	}
	else if (dir == '-') {
		int tmp1 = cube[num1].at(0);
		cube[num1].at(0) = cube[num1].at(2);
		cube[num1].at(2) = cube[num1].at(8);
		cube[num1].at(8) = cube[num1].at(6);
		cube[num1].at(6) = tmp1;

		int tmp2 = cube[num1].at(1);
		cube[num1].at(1) = cube[num1].at(5);
		cube[num1].at(5) = cube[num1].at(7);
		cube[num1].at(7) = cube[num1].at(3);
		cube[num1].at(3) = tmp2;

	}
}

void roatate2(char num,char dir) {
	// 1:À§ / 2:¾Æ·¡ / 3:¾Õ / 4:µÚ / 5:¿Þ / 6:¿À
	if (num == 'U') { //À­¸é
		if (dir == '+') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[6].at(0);
			tmp2 = cube[6].at(1);
			tmp3 = cube[6].at(2);

			cube[6].at(0) = cube[4].at(0);
			cube[6].at(1) = cube[4].at(1);
			cube[6].at(2) = cube[4].at(2);

			cube[4].at(0) = cube[5].at(0);
			cube[4].at(1) = cube[5].at(1);
			cube[4].at(2) = cube[5].at(2);

			cube[5].at(0) = cube[3].at(0);
			cube[5].at(1) = cube[3].at(1);
			cube[5].at(2) = cube[3].at(2);


			cube[3].at(0) = tmp1;
			cube[3].at(1) = tmp2;
			cube[3].at(2) = tmp3;
		}
		else if (dir == '-') {
			char tmp1, tmp2, tmp3;

			tmp1 = cube[6].at(0);
			tmp2 = cube[6].at(1);
			tmp3 = cube[6].at(2);

			cube[6].at(0) = cube[3].at(0);
			cube[6].at(1) = cube[3].at(1);
			cube[6].at(2) = cube[3].at(2);

			cube[3].at(0) = cube[5].at(0);
			cube[3].at(1) = cube[5].at(1);
			cube[3].at(2) = cube[5].at(2);

			cube[5].at(0) = cube[4].at(0);
			cube[5].at(1) = cube[4].at(1);
			cube[5].at(2) = cube[4].at(2);


			cube[4].at(0) = tmp1;
			cube[4].at(1) = tmp2;
			cube[4].at(2) = tmp3;
		}
	}
	else if (num == 'D') { //¾Æ·§¸é
		if (dir == '-') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[3].at(6);
			tmp2 = cube[3].at(7);
			tmp3 = cube[3].at(8);

			cube[3].at(6) = cube[6].at(6);
			cube[3].at(7) = cube[6].at(7);
			cube[3].at(8) = cube[6].at(8);

			cube[6].at(6) = cube[4].at(6);
			cube[6].at(7) = cube[4].at(7);
			cube[6].at(8) = cube[4].at(8);

			cube[4].at(6) = cube[5].at(6);
			cube[4].at(7) = cube[5].at(7);
			cube[4].at(8) = cube[5].at(8);


			cube[5].at(6) = tmp1;
			cube[5].at(7) = tmp2;
			cube[5].at(8) = tmp3;
		}
		else if (dir == '+') {
			char tmp1, tmp2, tmp3;

			tmp1 = cube[3].at(6);
			tmp2 = cube[3].at(7);
			tmp3 = cube[3].at(8);

			cube[3].at(6) = cube[5].at(6);
			cube[3].at(7) = cube[5].at(7);
			cube[3].at(8) = cube[5].at(8);

			cube[5].at(6) = cube[4].at(6);
			cube[5].at(7) = cube[4].at(7);
			cube[5].at(8) = cube[4].at(8);

			cube[4].at(6) = cube[6].at(6);
			cube[4].at(7) = cube[6].at(7);
			cube[4].at(8) = cube[6].at(8);


			cube[6].at(6) = tmp1;
			cube[6].at(7) = tmp2;
			cube[6].at(8) = tmp3;
		}
	}
	else if (num == 'F') {  //¾Õ¸é
		if (dir == '+') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[1].at(6);
			tmp2 = cube[1].at(7);
			tmp3 = cube[1].at(8);

			cube[1].at(6) = cube[5].at(8);
			cube[1].at(7) = cube[5].at(5);
			cube[1].at(8) = cube[5].at(2);

			cube[5].at(8) = cube[2].at(2);
			cube[5].at(5) = cube[2].at(1);
			cube[5].at(2) = cube[2].at(0);

			cube[2].at(2) = cube[6].at(0);
			cube[2].at(1) = cube[6].at(3);
			cube[2].at(0) = cube[6].at(6);


			cube[6].at(0) = tmp1;
			cube[6].at(3) = tmp2;
			cube[6].at(6) = tmp3;
		}
		else if (dir == '-') {
			char tmp1, tmp2, tmp3;

			tmp1 = cube[1].at(6);
			tmp2 = cube[1].at(7);
			tmp3 = cube[1].at(8);

			cube[1].at(6) = cube[6].at(0);
			cube[1].at(7) = cube[6].at(3);
			cube[1].at(8) = cube[6].at(6);

			cube[6].at(0) = cube[2].at(2);
			cube[6].at(3) = cube[2].at(1);
			cube[6].at(6) = cube[2].at(0);

			cube[2].at(2) = cube[5].at(8);
			cube[2].at(1) = cube[5].at(5);
			cube[2].at(0) = cube[5].at(2);


			cube[5].at(8) = tmp1;
			cube[5].at(5) = tmp2;
			cube[5].at(2) = tmp3;
		}
	}
	else if (num == 'B') { //µÞ¸é 
	if (dir == '+') {
		char tmp1, tmp2, tmp3;
		tmp1 = cube[1].at(0);
		tmp2 = cube[1].at(1);
		tmp3 = cube[1].at(2);

		cube[1].at(0) = cube[6].at(2);
		cube[1].at(1) = cube[6].at(5);
		cube[1].at(2) = cube[6].at(8);

		cube[6].at(2) = cube[2].at(8);
		cube[6].at(5) = cube[2].at(7);
		cube[6].at(8) = cube[2].at(6);

		cube[2].at(8) = cube[5].at(6);
		cube[2].at(7) = cube[5].at(3);
		cube[2].at(6) = cube[5].at(0);


		cube[5].at(6) = tmp1;
		cube[5].at(3) = tmp2;
		cube[5].at(0) = tmp3;
	}
	else if (dir == '-') {
		char tmp1, tmp2, tmp3;

		tmp1 = cube[1].at(0);
		tmp2 = cube[1].at(1);
		tmp3 = cube[1].at(2);

		cube[1].at(0) = cube[5].at(6);
		cube[1].at(1) = cube[5].at(3);
		cube[1].at(2) = cube[5].at(0);

		cube[5].at(6) = cube[2].at(8);
		cube[5].at(3) = cube[2].at(7);
		cube[5].at(0) = cube[2].at(6);

		cube[2].at(8) = cube[6].at(2);
		cube[2].at(7) = cube[6].at(5);
		cube[2].at(6) = cube[6].at(8);


		cube[6].at(2) = tmp1;
		cube[6].at(5) = tmp2;
		cube[6].at(8) = tmp3;
	  }
    }
	else if (num == 'L') { //¿ÞÂÊ¸é 
		if (dir == '+') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[3].at(0);
			tmp2 = cube[3].at(3);
			tmp3 = cube[3].at(6);

			cube[3].at(0) = cube[1].at(0);
			cube[3].at(3) = cube[1].at(3);
			cube[3].at(6) = cube[1].at(6);

			cube[1].at(0) = cube[4].at(8);
			cube[1].at(3) = cube[4].at(5);
			cube[1].at(6) = cube[4].at(2);

			cube[4].at(8) = cube[2].at(0);
			cube[4].at(5) = cube[2].at(3);
			cube[4].at(2) = cube[2].at(6);


			cube[2].at(0) = tmp1;
			cube[2].at(3) = tmp2;
			cube[2].at(6) = tmp3;
		}
		else if (dir == '-') {
			char tmp1, tmp2, tmp3;

			tmp1 = cube[3].at(0);
			tmp2 = cube[3].at(3);
			tmp3 = cube[3].at(6);

			cube[3].at(0) = cube[2].at(0);
			cube[3].at(3) = cube[2].at(3);
			cube[3].at(6) = cube[2].at(6);

			cube[2].at(0) = cube[4].at(8);
			cube[2].at(3) = cube[4].at(5);
			cube[2].at(6) = cube[4].at(2);

			cube[4].at(8) = cube[1].at(0);
			cube[4].at(5) = cube[1].at(3);
			cube[4].at(2) = cube[1].at(6);


			cube[1].at(0) = tmp1;
			cube[1].at(3) = tmp2;
			cube[1].at(6) = tmp3;
		}
	}
	else if (num == 'R') { //¿À¸¥ÂÊ¸é 
		if (dir == '+') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[3].at(2);
			tmp2 = cube[3].at(5);
			tmp3 = cube[3].at(8);

			cube[3].at(2) = cube[2].at(2);
			cube[3].at(5) = cube[2].at(5);
			cube[3].at(8) = cube[2].at(8);

			cube[2].at(2) = cube[4].at(6);
			cube[2].at(5) = cube[4].at(3);
			cube[2].at(8) = cube[4].at(0);

			cube[4].at(6) = cube[1].at(2);
			cube[4].at(3) = cube[1].at(5);
			cube[4].at(0) = cube[1].at(8);


			cube[1].at(2) = tmp1;
			cube[1].at(5) = tmp2;
			cube[1].at(8) = tmp3;
		}
		else if (dir == '-') {
			char tmp1, tmp2, tmp3;
			tmp1 = cube[3].at(2);
			tmp2 = cube[3].at(5);
			tmp3 = cube[3].at(8);

			cube[3].at(2) = cube[1].at(2);
			cube[3].at(5) = cube[1].at(5);
			cube[3].at(8) = cube[1].at(8);

			cube[1].at(2) = cube[4].at(6);
			cube[1].at(5) = cube[4].at(3);
			cube[1].at(8) = cube[4].at(0);

			cube[4].at(6) = cube[2].at(2);
			cube[4].at(3) = cube[2].at(5);
			cube[4].at(0) = cube[2].at(8);


			cube[2].at(2) = tmp1;
			cube[2].at(5) = tmp2;
			cube[2].at(8) = tmp3;

		}
	}
	rotate1(num, dir);
  }

    

    



int main(void) {
	string s;
	cin >> tc;
	for (int j = 1; j <= tc; j++) {
		v.clear();
		for (int i = 0; i <= 6; i++) {
			cube[i].clear();
		}
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> s;
			char a = s[0];
			char b = s[1];
			v.push_back(make_pair(a, b));
		}
		for (int i = 0; i < 9; i++) {
			cube[1].push_back('w'); //À§
			cube[2].push_back('y'); //¾Æ·¡
			cube[3].push_back('r'); //¾Õ
			cube[4].push_back('o'); //µÚ
			cube[5].push_back('g'); //¿Þ
			cube[6].push_back('b'); //¿À


		}
		for (int i = 0; i < v.size(); i++) {
			roatate2(v[i].first, v[i].second);
		}
		int cnt1 = 1;
		for (int i = 0; i < 9; i++) {
			cout << cube[1].at(i);
			if (cnt1 == 3) {
				cout << "\n";
				cnt1 = 0;
			}
			cnt1++;
		}

	}

	
	

}