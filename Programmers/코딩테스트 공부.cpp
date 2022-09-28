#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int maxAlp;
int maxCop;

int dp[151][151];

int solve(int alp, int cop, vector<vector<int>>& problems) {
    if (alp >= maxAlp && cop >= maxCop) {
        return 0;
    }
    if (alp > maxAlp) {
        alp = maxAlp;
    }
    if (cop > maxCop) {
        cop = maxCop;
    }

    int& ret = dp[alp][cop];
    if (ret != 0) {
        return ret;
    }
    ret = 987654321;

    for (int i = 0; i < problems.size(); i++) {
        if (alp >= problems[i][0] && cop >= problems[i][1]) {
            ret = min(ret, solve(alp + problems[i][2], cop + problems[i][3], problems) + problems[i][4]);
        }
    }
    ret = min(ret, solve(alp + 1, cop, problems) + 1);
    ret = min(ret, solve(alp, cop + 1, problems) + 1);

    //dp[alp][cop]=ret;
    return ret;
}

int solution(int alp, int cop, vector<vector<int>> problems) {
    int answer = 0;
    for (int i = 0; i < problems.size(); i++) {
        maxAlp = max(maxAlp, problems[i][0]);
        maxCop = max(maxCop, problems[i][1]);
    }
    answer = solve(alp, cop, problems);
    return answer;
}