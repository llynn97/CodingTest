#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool tmp(int a, int b) {
    return a < b;
}
string solution(string s) {
    vector <int> v;
    string answer = "";
    while (true) {
        if (s.find(" ") == string::npos) {
            break;
        }
        int idx = s.find(' ');
        string str = s.substr(0, idx);
        v.push_back(stoi(str));
        s = s.substr(idx + 1, s.length() - 1);

    }
    v.push_back(stoi(s));
    sort(v.begin(), v.end(), tmp);
    answer += to_string(v[0]);
    answer += " ";
    answer += to_string(v[v.size() - 1]);
    return answer;
}