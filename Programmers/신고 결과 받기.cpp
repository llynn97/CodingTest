#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map <string, vector<string>> m1; //ID 별 신고한 사람
map <string, int> m2;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    for (int i = 0; i < report.size(); i++) {
        string str = report[i];
        int idx = str.find(' ');
        string name1 = str.substr(0, idx); //신고한 사람
        string name2 = str.substr(idx + 1, str.length()); //신고 당한 사람
        if (m1.find(name2) == m1.end()) {
            m1[name2].push_back(name1);
        }
        else {
            vector <string> ::iterator it;
            it = find(m1[name2].begin(), m1[name2].end(), name1);
            if (it == m1[name2].end()) {
                m1[name2].push_back(name1);
            }

        }

    }
    map <string, vector<string>> ::iterator i;
    for (i = m1.begin(); i != m1.end(); i++) {
        string name = i->first;
        vector <string> s = i->second;
        if (s.size() >= k) {
            for (int i = 0; i < s.size(); i++) {
                if (m2.find(s[i]) == m2.end()) {
                    m2[s[i]] = 1;
                }
                else {
                    m2[s[i]]++;
                }
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        if (m2.find(id_list[i]) != m2.end()) {
            answer.push_back(m2[id_list[i]]);
        }
        else {
            answer.push_back(0);
        }
    }

    return answer;
}