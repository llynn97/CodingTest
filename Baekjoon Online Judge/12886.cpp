#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>


using namespace std;
int temp[3];
int a, b, c;
int answer;
bool visit[1501][1501];
queue <pair<int, int>> q;
//x: 작은 쪽   y : 큰 쪽    x+x , y-x
//10, 15, 35    :     20, 15 , 25  : 15, 20, 25    ->  30,20,10  : 10,20,30 ->   20,20,20
int main(void) {

	cin >> a >> b >> c;

	int sum = a + b + c;
	if (sum % 3 != 0) {
		answer = 0;
	}
	else {
		
		q.push(make_pair(a, b));
		visit[a][b] = true;
		while (!q.empty()) {
			int a1 = q.front().first;
			int b1 = q.front().second;
			q.pop();
			int c1 = sum - a1 - b1;
			temp[0] = a1;
			temp[1] = b1;
			temp[2] = c1;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					if (temp[i] < temp[j]) {
						int num1 = temp[i] * 2;
						int num2 = temp[j] - temp[i];
						if (visit[num1][num2]) {
							continue;
						}
						visit[num1][num2] = true;
						q.push(make_pair(num1, num2));
					}
				}
			}
			

		}
		if (visit[sum / 3][sum / 3]) {
			answer = 1;
		}

	}
	
	cout << answer;

}