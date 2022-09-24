#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
using namespace std;

map <string, string> m1;


vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int idx1 = today.find('.');
    int toYear = stoi(today.substr(0, idx1));

    today = today.substr(idx1 + 1, today.length() - 1);
    idx1 = today.find('.');
    int toMonth = stoi(today.substr(0, idx1));

    int toDay = stoi(today.substr(idx1 + 1, today.length() - 1));

    string strToday = to_string(toYear);
    if (toMonth < 10) {
        strToday += "0" + to_string(toMonth);
    }
    else {
        strToday += to_string(toMonth);
    }
    if (toDay < 10) {
        strToday += "0" + to_string(toDay);
    }
    else {
        strToday += to_string(toDay);
    }

    for (int i = 0; i < terms.size(); i++) {
        string str = terms[i];
        int idx = str.find(' ');
        string sortAl = str.substr(0, idx);
        string date = str.substr(idx + 1, str.length() - 1);
        m1[sortAl] = date;
    }
    for (int i = 0; i < privacies.size(); i++) {
        string str2 = privacies[i];
        int idx2 = str2.find(' ');
        string date = str2.substr(0, idx2);
        string sortAl2 = str2.substr(idx2 + 1, str2.length() - 1);

        idx2 = date.find('.');
        int year = stoi(date.substr(0, idx2));
        date = date.substr(idx2 + 1, date.length() - 1);
        idx2 = date.find('.');
        int month = stoi(date.substr(0, idx2));
        int day = stoi(date.substr(idx2 + 1, date.length() - 1));

        int month3 = stoi(m1[sortAl2]); //유효기간
        int num = month3 + month;
        int year2 = year + (num / 12);
        int month2 = num % 12;
        if (month2 == 0) {
            month2 = 12;
            year2 -= 1;
        }
        string endDate = to_string(year2);
        if (month2 < 10) {
            endDate += "0" + to_string(month2);
        }
        else {
            endDate += to_string(month2);
        }
        if (day < 10) {
            endDate += "0" + to_string(day);
        }
        else {
            endDate += to_string(day);
        }
        cout << strToday << "," << endDate << "\n";
        if (strToday >= endDate) {
            answer.push_back(i + 1);
        }
    }
    return answer;
}