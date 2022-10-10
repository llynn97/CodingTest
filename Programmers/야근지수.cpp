#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int N;
priority_queue <int, vector<int>, less<int>> q;



long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    N = n;
    for (int i = 0; i < works.size(); i++) {
        q.push(works[i]);
        sum += works[i];
    }
    if (sum <= n) {
        return 0;
    }

    while (true) {
        if (n == 0) {
            break;
        }
        int num = q.top();
        q.pop();
        if (num > 1) {
            q.push(num - 1);
        }
        n--;
    }
    while (!q.empty()) {
        cout << q.top() << "\n";
        answer += q.top() * q.top();
        q.pop();
    }

    return answer;
}