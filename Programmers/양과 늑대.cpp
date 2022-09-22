#include <string>
#include <vector>

using namespace std;
vector <int> v[20];
int answer = 1;


void dfs(int idx, int wolf, int sheep, vector <int> nextNode, vector <int> info) {
    int animal = info[idx];
    if (animal == 0) {
        sheep++;
    }
    else {
        wolf++;
    }
    answer = max(answer, sheep);
    if (wolf >= sheep) {
        return;
    }
    for (int i = 0; i < nextNode.size(); i++) {
        vector <int> next = nextNode;
        next.erase(next.begin() + i);
        for (int j = 0; j < v[nextNode[i]].size(); j++) {
            next.push_back(v[nextNode[i]][j]);
        }
        dfs(nextNode[i], wolf, sheep, next, info);
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {


    for (int i = 0; i < edges.size(); i++) {
        v[edges[i][0]].push_back(edges[i][1]);
    }
    vector <int> nextNode;
    for (int i = 0; i < v[0].size(); i++) {
        nextNode.push_back(v[0][i]);
    }
    dfs(0, 0, 0, nextNode, info);
    return answer;
}