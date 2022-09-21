#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;


string changeNum(long long n, int k) {
    string ret = "";
    while (n) {
        ret += to_string(n % k);
        n /= k;
    }
    return string(ret.rbegin(), ret.rend());
}

bool checkPrime(string str) {
    long long num = stoll(str);
    if (num < 2) {
        return false;
    }

    long long num2 = (long long)sqrt(num);
    for (long long i = 2; i <= num2; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int countPrime(string str) {
    cout << "Str: " << str << "\n";
    int cnt = 0;
    string str2 = "";
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0') {
            if (str2.length() != 0 && checkPrime(str2)) {
                cout << str2 << "\n";
                cnt++;
            }
            str2 = "";
        }
        else {
            str2 += str[i];

        }
    }
    if (str2.length() != 0 && checkPrime(str2)) {
        cout << str2 << "\n";
        cnt++;
    }
    return cnt;
}

int solution(int n, int k) {
    long long answer = -1;

    string str3 = changeNum(n, k);

    answer = countPrime(str3);
    return answer;
}