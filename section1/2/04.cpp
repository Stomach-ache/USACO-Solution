/*
ID: sudawei1
PROG: palsquare
LANG: C++11
*/

#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>
#include <iostream>
using std::string;

#define __DEBUG

bool isPalindromic(const string &s) {
    int n = s.length();
    for (int i = 0; i < n/2; ++ i) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

string toBaseX(int x, int n) {
    string ans = "";
    int cc = 0;
    while (n > 0) {
        int r = n % x;
        n /= x;
        char ch;
        if (r >= 10) ch = r - 10 + 'A';
        else ch = r + '0';
        ans += ch;
        ++ cc;
    }

    for (int i = 0; i < cc/2; ++ i) {
        std::swap(ans[i], ans[cc - 1 - i]);
    }
    return ans;
}

int main(void) {
#ifdef __DEBUG
    freopen("palsquare.in", "r", stdin);
    freopen("palsquare.out", "w", stdout);
#endif
    int B;
    scanf("%d", &B);
    for (int i = 1; i <= 300; ++ i) {
        if (isPalindromic(toBaseX(B, i*i))) {
            printf("%s %s\n", toBaseX(B, i).c_str(), toBaseX(B, i*i).c_str());
        }
    }

    return 0;
}
