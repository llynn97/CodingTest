#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int map[1010][1010];
int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int n = board.size();
    int m = board[0].size();

    int answer = 0;

    for (int i = 0; i < skill.size(); i++) {
        int type = skill[i][0];
        int r1 = skill[i][1];
        int c1 = skill[i][2];
        int r2 = skill[i][3];
        int c2 = skill[i][4];
        int degree = skill[i][5];
        if (type == 1) { //공격일 때
            degree = -degree;
        }
        map[r1][c1] += degree;
        map[r2 + 1][c2 + 1] += degree;
        map[r1][c2 + 1] -= degree;
        map[r2 + 1][c1] -= degree;

    }
    //왼-> 오 이동하며 합해줌
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < m; j++) {
            map[i][j + 1] += map[i][j];
        }
    }
    //위-> 아래 이동하며 합해줌
    for (int j = 0; j <= m; j++) {
        for (int i = 0; i < n; i++) {
            map[i + 1][j] += map[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] + map[i][j] > 0) {
                answer++;
            }
        }
    }
    return answer;

}