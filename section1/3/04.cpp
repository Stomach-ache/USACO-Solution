/*
ID: sudawei1
PROG: combo
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>

int n;

int mul(int a, int b) {
    if (a > b) std::swap(a, b);
    return std::min(b - a, a + n - b);
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("combo.out", "w", stdout);
    freopen("combo.in", "r", stdin);
#endif
    scanf("%d", &n);
    std::set<int> s[3];
    int d[2][3];
    for (int i = 0; i < 2; ++ i) {
        for (int j = 0; j < 3; ++ j) {
            int x;
            scanf("%d", &x);
            d[i][j] = x;
            for (int k = -2; k <= 2; ++ k) {
                int y = (x + k + n) % n;
                if (y == 0) y = n;
                s[j].insert(y);
            }
        }
    }
    int ans = 0;
    for (auto &a: s[0]) {
        for (auto &b: s[1]) {
            for (auto &c: s[2]) {
                if (abs(mul(a, d[0][0])) <= 2
                    && abs(mul(b, d[0][1])) <= 2
                    && abs(mul(c, d[0][2])) <= 2) {
                        ++ ans;
                        continue;
                    }
                if (abs(mul(a, d[1][0])) <= 2
                    && abs(mul(b, d[1][1])) <= 2
                    && abs(mul(c, d[1][2])) <= 2) {
                        ++ ans;
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
