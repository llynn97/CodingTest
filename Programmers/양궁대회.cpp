#include <string>
#include <vector>
#include <cmath>
using namespace std;
vector<int> answer;

int maxDif = 0;

bool cmp(vector <int> v) {
    for (int i = 10; i >= 0; i--) {
        if (v[i] > answer[i]) {
            return true;
        }
        else if (v[i] < answer[i]) {
            return false;
        }
    }
}

void cntScore(vector <int> ryan, vector <int> apeach) {
    int rScore = 0;
    int aScore = 0;
    for (int i = 0; i < 11; i++) {
        if (ryan[i] > apeach[i]) {
            rScore += 10 - i;
        }
        else if (apeach[i] > 0) {
            aScore += 10 - i;
        }
    }
    int dif = rScore - aScore;
    if (dif > 0 && maxDif <= dif) {
        if (maxDif == dif && !cmp(ryan)) {
            return;
        }
        maxDif = dif;
        answer = ryan;
    }
}
void dfs(int idx, int arrows, vector<int> ryan, vector<int> apeach) {
    if (idx == 11 || arrows == 0) { //남은 화살 개수
        ryan[10] += arrows;
        cntScore(ryan, apeach);
        ryan[10] -= arrows;
        return;
    }
    if (apeach[idx] < arrows) {
        ryan[idx] += apeach[idx] + 1;
        dfs(idx + 1, arrows - apeach[idx] - 1, ryan, apeach);
        ryan[idx] -= apeach[idx] + 1;
    }
    dfs(idx + 1, arrows, ryan, apeach);

}

vector<int> solution(int n, vector<int> info) {
    vector <int> ryan(11, 0);

    dfs(0, n, ryan, info);
    if (answer.empty()) {
        answer.push_back(-1);
    }
    return answer;
}