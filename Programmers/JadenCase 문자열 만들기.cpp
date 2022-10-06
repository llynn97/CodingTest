#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s) {
    string answer = "";
    string str = "";
    vector <string> v;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != ' ') {
            str += s[i];
        }
        else {
            if (str.length() != 0) {
                string str2 = "";
                for (int j = 0; j < str.length(); j++) {
                    if (j == 0) {
                        if (str[j] >= '0' && str[j] <= '9') {
                            str2 += str[j];
                        }
                        else {
                            str2 += toupper(str[j]);
                        }
                    }
                    else {
                        str2 += tolower(str[j]);
                    }
                }
                answer += str2;
            }

            answer += " ";
            str = "";
        }
    }
    if (str.length() != 0) {
        string str2 = "";
        for (int j = 0; j < str.length(); j++) {
            if (j == 0) {
                if (str[j] >= '0' && str[j] <= '9') {
                    str2 += str[j];
                }
                else {
                    str2 += toupper(str[j]);
                }
            }
            else {
                str2 += tolower(str[j]);
            }
        }
        answer += str2;
    }
    return answer;
}