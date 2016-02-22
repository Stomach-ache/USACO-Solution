/*
ID: sudawei1
PROG: dualpal
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
    freopen("dualpal.in", "r", stdin);
    freopen("dualpal.out", "w", stdout);
#endif
    int N, S;
    scanf("%d %d", &N, &S);
    for (int i = S + 1, c = 0; c < N; ++ i) {
        bool flag = false;
        int cnt = 0;
        for (int B = 2; B <= 10; ++ B) {
            if (isPalindromic(toBaseX(B, i))) {
                ++ cnt;
                if (cnt == 2) {
                    flag = true;
                    break;
                }
            }
        }
        if (flag) {
            ++ c;
            printf("%d\n", i);
        }
    }

    return 0;
}
