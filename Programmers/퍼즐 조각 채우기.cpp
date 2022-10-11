#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;

bool checkBoard[51][51];
bool checkTable[51][51];

int dx[4] = { 0,1,-1,0 };
int dy[4] = { -1,0,0,1 };
vector <vector<pair<int, int>>> v2; //퍼즐
vector <vector<pair<int, int>>> v6; //빈공간
vector<vector<int>> game_board1;
vector<vector<int>> table1;
int N;
int ans = 0;


void bfs(int x, int y) {
    queue <pair<int, int>> q;
    vector <pair<int, int>> v3;
    v3.push_back(make_pair(x, y));
    checkBoard[x][y] = true;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !checkBoard[nx][ny] && game_board1[nx][ny] == 1) {
                checkBoard[nx][ny] = true;
                q.push(make_pair(nx, ny));
                v3.push_back(make_pair(nx, ny));

            }
        }
    }
    v6.push_back(v3);

}

void findBoard() { //빈공간 v6에 넣어놓기
    for (int i = 0; i < game_board1.size(); i++) {
        for (int j = 0; j < game_board1[i].size(); j++) {
            if (game_board1[i][j] == 0 && checkBoard[i][j] == false) {
                bfs(i, j);
            }
        }
    }
}

vector<vector<pair<int, int>>> convert(int value) { // (0,0) 기준으로 변환 (퍼즐)
    vector <vector<pair<int, int>>> v4;
    for (int i = 0; i < v2.size(); i++) {
        int xMin = value;
        int yMin = value;
        vector <pair<int, int>> v3;
        for (int j = 0; j < v2[i].size(); j++) {
            xMin = min(xMin, v2[i][j].first);
            yMin = min(yMin, v2[i][j].second);
        }
        for (int j = 0; j < v2[i].size(); j++) {
            v3.push_back(make_pair(v2[i][j].first - xMin, v2[i][j].second - yMin));
        }
        v4.push_back(v3);
    }
    return v4;
}

vector<vector<pair<int, int>>> convert3(vector<vector<pair<int, int>>> before, int value) { // (0,0) 기준으로 변환 (퍼즐)
    vector <vector<pair<int, int>>> v4;
    for (int i = 0; i < before.size(); i++) {
        int xMin = value;
        int yMin = value;
        vector <pair<int, int>> v3;
        for (int j = 0; j < before[i].size(); j++) {
            xMin = min(xMin, before[i][j].first);
            yMin = min(yMin, before[i][j].second);
        }
        for (int j = 0; j < before[i].size(); j++) {
            v3.push_back(make_pair(before[i][j].first - xMin, before[i][j].second - yMin));
        }
        v4.push_back(v3);
    }
    return v4;
}

vector<vector<pair<int, int>>> convert2(int value) { // (0,0) 기준으로 변환 (빈공간)
    vector <vector<pair<int, int>>> v4;
    for (int i = 0; i < v6.size(); i++) {
        int xMin = value;
        int yMin = value;
        vector <pair<int, int>> v3;
        for (int j = 0; j < v6[i].size(); j++) {
            xMin = min(xMin, v6[i][j].first);
            yMin = min(yMin, v6[i][j].second);
        }
        for (int j = 0; j < v6[i].size(); j++) {
            v3.push_back(make_pair(v6[i][j].first - xMin, v6[i][j].second - yMin));
        }
        v4.push_back(v3);
    }
    return v4;
}

vector<pair<int, int>> rotate(vector<pair<int, int>> v) { //x,y -> -y,x
    vector<pair<int, int>> v4;
    for (int i = 0; i < v.size(); i++) {
        int afterX = -v[i].second;
        int afterY = v[i].first;
        v4.push_back(make_pair(afterX, afterY));
    }//90도 회전
    return v4;
}

void bfs2(int x, int y) { //퍼즐 v2에 넣어놓기
    queue <pair<int, int>> q;
    vector <pair<int, int>> v3;
    v3.push_back(make_pair(x, y));
    checkTable[x][y] = true;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < N && ny < N && !checkTable[nx][ny] && table1[nx][ny] == 1) {
                checkTable[nx][ny] = true;
                q.push(make_pair(nx, ny));
                v3.push_back(make_pair(nx, ny));

            }
        }
    }
    v2.push_back(v3);

}

void findPuzzle() { //퍼즐 v2에 넣어놓기
    for (int i = 0; i < table1.size(); i++) {
        for (int j = 0; j < table1[i].size(); j++) {
            if (table1[i][j] == 1 && checkTable[i][j] == false) {
                bfs2(i, j);
            }
        }
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else {
        return a.first < b.first;
    }
}



int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1;
    N = game_board.size();
    for (int i = 0; i < game_board.size(); i++) {
        vector <int> v;
        for (int j = 0; j < game_board[i].size(); j++) {
            v.push_back(game_board[i][j]);
        }
        game_board1.push_back(v);
    }

    for (int i = 0; i < table.size(); i++) {
        vector <int> v;
        for (int j = 0; j < table[i].size(); j++) {
            v.push_back(table[i][j]);
        }
        table1.push_back(v);
    }

    findPuzzle();
    findBoard();

    vector<vector<pair<int, int>>> afterBlanks = convert2(100);
    for (int i = 0; i < afterBlanks.size(); i++) {
        sort(afterBlanks[i].begin(), afterBlanks[i].end(), cmp);
    }
    vector<vector<pair<int, int>>> afterShapes = convert(100);
    vector<vector<vector<pair<int, int>>>> finalShapes;
    for (int i = 0; i < afterShapes.size(); i++) {
        vector<vector<pair<int, int>>> afterTemp;
        for (int j = 0; j < 4; j++) {
            vector <pair<int, int>> temp = rotate(afterShapes[i]);
            afterTemp.push_back(temp);
            afterShapes[i] = temp;
        }
        vector<vector<pair<int, int>>> afterRotation = convert3(afterTemp, 100);
        for (int j = 0; j < afterRotation.size(); j++) {
            sort(afterRotation[j].begin(), afterRotation[j].end(), cmp);
            finalShapes.push_back(afterRotation);
        }
    }

    int tableCheck[2501] = { false, };

    for (int i = 0; i < afterBlanks.size(); i++) {
        vector<pair<int, int>> blank = afterBlanks[i];
        bool shapeFlag = false;
        for (int j = 0; j < finalShapes.size(); j++) {
            if (tableCheck[j]) { //사용한 퍼즐이면 넘어감
                continue;
            }
            vector<vector<pair<int, int>>> fourShapes = finalShapes[j];
            if (blank.size() != fourShapes[0].size()) {
                continue;
            }
            for (int k = 0; k < fourShapes.size(); k++) {
                int oneFlag = true;
                for (int t = 0; t < blank.size(); t++) {
                    pair<int, int> bl = blank[t];
                    pair<int, int> sh = fourShapes[k][t];
                    if (bl.first == sh.first && bl.second == sh.second) {
                        continue;
                    }
                    else {
                        oneFlag = false;
                        break;
                        break;
                    }
                }
                if (oneFlag) { //4방향 중 하나가 맞았으면
                    shapeFlag = true;
                    answer += blank.size();
                }
            }
            if (shapeFlag) {
                tableCheck[j] = true;
                break;
            }
        }
    }





    return answer;
}