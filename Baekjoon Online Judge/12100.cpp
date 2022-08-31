#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;
int map[21][21];
int map2[21][21];
int ans = 0;
int n;
int num[4] = { 1,2,3,4 };
vector <int> order;
void up() {
    vector <int> v[21];
    vector <int> v2[21];
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (map[j][i] != 0) {
                v[i].push_back(map[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        while (!v[i].empty()) {
            int m = v[i].back();
            v[i].pop_back();
            if (v[i].size() != 0 && (v[i].back() == m)) {
                v[i].pop_back();
                v2[i].push_back(m * 2);
            }
            else {
                v2[i].push_back(m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = v2[i].size(); j <= n; j++) {
            v2[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[j][i] = v2[i][j];

        }
    }

}


void down() {
    vector <int> v[21];
    vector <int> v2[21]; //같 은 숫 자 합 친 후 각 열 의 남 은 숫 자 들
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[j][i] != 0) {
                v[i].push_back(map[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        while (!v[i].empty()) {
            int m = v[i].back();
            v[i].pop_back();
            if (v[i].size() != 0 && (v[i].back() == m)) {
                v[i].pop_back();
                v2[i].push_back(m * 2);
            }
            else {
                v2[i].push_back(m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = v2[i].size(); j <= n; j++) {
            v2[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = n - 1; j >= 0; j--) {
            map[j][i] = v2[i][t];
            t++;

        }
    }
}

void left() {
    vector <int> v[21];
    vector <int> v2[21];//같 은 숫 자 합 친 후 각 행 의 남 은 숫 자 들
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (map[i][j] != 0) {
                v[i].push_back(map[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        while (!v[i].empty()) {
            int m = v[i].back();
            v[i].pop_back();
            if (v[i].size() != 0 && (v[i].back() == m)) {
                v[i].pop_back();
                v2[i].push_back(m * 2);
            }
            else {
                v2[i].push_back(m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = v2[i].size(); j <= n; j++) {
            v2[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            map[i][j] = v2[i][j];

        }
    }

}

void right() {
    vector <int> v[21];
    vector <int> v2[21];//같 은 숫 자 합 친 후 각 행 의 남 은 숫 자 들
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] != 0) {
                v[i].push_back(map[i][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        while (!v[i].empty()) {
            int m = v[i].back();
            v[i].pop_back();
            if (v[i].size() != 0 && (v[i].back() == m)) {
                v[i].pop_back();
                v2[i].push_back(m * 2);
            }
            else {
                v2[i].push_back(m);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = v2[i].size(); j <= n; j++) {
            v2[i].push_back(0);
        }
    }
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = n - 1; j >= 0; j--) {
            map[i][j] = v2[i][t];
            t++;

        }
    }

}

void go(int cnt) {
    if (cnt == 5) {
        for (int i = 0; i < 5; i++) {
            if (order[i] == 1) {
                up();
            }
            else if (order[i] == 2) {
                down();
            }
            else if (order[i] == 3) {
                left();
            }
            else if (order[i] == 4) {
                right();
            }
        }

        int bignum = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] > bignum) {
                    bignum = map[i][j];
                }
            }
        }
        if (ans < bignum) {
            ans = bignum;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                map[i][j] = map2[i][j];
            }
        }

        /*   for(int i=0; i<5; i++){
            cout<<order[i]<<" ";
           }
           cout<<"\n";*/

        return;
    }
    for (int i = 0; i < 4; i++) {
        order.push_back(num[i]);
        go(cnt + 1);
        order.pop_back();
    }
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
            map2[i][j] = map[i][j];
        }
    }
   
    go(0);
    cout << ans;
    return 0;
}