#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

int ans = 987654321;


int solution(vector<int> queue1, vector<int> queue2) {
    long long sum = 0;
    long long sum2 = 0;
    int answer = 0;
    queue <int> q1;
    queue <int> q2;

    for (int i = 0; i < queue1.size(); i++) {
        sum += queue1[i];
        q1.push(queue1[i]);
    }

    for (int i = 0; i < queue2.size(); i++) {
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    int maxIdx = queue1.size() + queue2.size();
    int idx = 0;
    int idx2 = 0;
    while (idx < maxIdx && idx2 < maxIdx) {
        if (sum == sum2) {
            return answer;
        }
        answer++;
        if (sum < sum2) {
            int num = q2.front();
            q2.pop();
            q1.push(num);
            sum += num;
            sum2 -= num;
            idx2++;
        }
        else {
            int num = q1.front();
            q1.pop();
            q2.push(num);
            sum2 += num;
            sum -= num;
            idx++;
        }
    }



    return -1;
}