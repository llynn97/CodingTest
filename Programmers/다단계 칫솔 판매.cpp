#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

map <string, int> m;

vector <int> v[10005];
int d[10005];
bool check[10005];

void init(int n) {
    for (int i = 0; i < n; i++) {
        check[i] = false;
    }
}

void dfs(int money, int idx2) {
    if (idx2 == 10003) {
        d[idx2] += money;
        return;
    }
    int notmine = money * 0.1;
    d[idx2] += (money - notmine);
    if (notmine < 1) {
        return;
    }
    dfs(notmine, v[idx2][0]);
}

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer;
    for (int i = 0; i < enroll.size(); i++) {
        m[enroll[i]] = i;

    }
    for (int i = 0; i < referral.size(); i++) {
        string str = referral[i];
        if (str == "-") {
            v[i].push_back(10003);
        }
        else {
            v[i].push_back(m[str]);

        }
    }

    for (int i = 0; i < seller.size(); i++) {
        int idx = m[seller[i]];
        int money = amount[i] * 100;

        dfs(money, idx);

    }


    for (int i = 0; i < enroll.size(); i++) {
        answer.push_back(d[i]);
    }

    return answer;
}