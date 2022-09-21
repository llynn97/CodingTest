#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

map <string, int> m1; //차 번호: 요금
map <string, int> m2;

vector <pair<string, int>> v;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    for (int i = 0; i < records.size(); i++) { //시각 차량번호 내역
        string s = records[i];
        int idx = s.find(' ');
        string time = s.substr(0, idx);
        s = s.substr(idx + 1, s.length() - 1);
        idx = s.find(' ');
        string carNum = s.substr(0, idx);
        string IO = s.substr(idx + 1, s.length() - 1);

        idx = time.find(':');
        string hour = time.substr(0, idx);
        string min = time.substr(idx + 1, hour.length());
        int time2 = stoi(hour) * 60 + stoi(min);

        if (IO == "OUT") {
            if (m2.find(carNum) == m2.end()) {

                m2[carNum] = (time2 - m1[carNum]);

            }
            else {

                m2[carNum] += (time2 - m1[carNum]);

            }

            m1.erase(carNum);
        }
        else {
            m1[carNum] = time2;
        }



    }
    int last = 23 * 60 + 59;
    map <string, int> ::iterator i;
    for (i = m1.begin(); i != m1.end(); i++) {
        if (m2.find(i->first) == m2.end()) {
            m2[i->first] = (last - i->second);
        }
        else {
            m2[i->first] += (last - i->second);
        }


    }
   
    for (i = m2.begin(); i != m2.end(); i++) {
        int num1 = fees[1]; //기본요금
        string carnum = i->first;
        int time3 = i->second;
        if (time3 > fees[0]) {
            time3 -= fees[0];
            if (time3 % fees[2] != 0) {
                num1 += (time3 / fees[2] + 1) * fees[3];
            }
            else {
                num1 += (time3 / fees[2]) * fees[3];
            }
        }
        v.push_back(make_pair(carnum, num1));
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++) {
        answer.push_back(v[i].second);
    }
    return answer;
}