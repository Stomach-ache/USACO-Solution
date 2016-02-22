/*
ID: sudawei1
PROG: holstein
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <unordered_set>
using namespace std;

inline int bitcount(int n) {
    return __builtin_popcount(n);
}

int a[30], b[20][30], c[30];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("holstein.out", "w", stdout);
    freopen("holstein.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
    }
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &b[i][j]);
        }
    }

    int ans = 0x3f3f3f3f;
    for (int i = 1; i < (1<<m); ++ i) {
        for (int j = 0; j < n; ++ j) c[j] = a[j];
        for (int j = 0; j < m; ++ j) if (i & (1<<j)) {
            for (int k = 0; k < n; ++ k) c[k] -= b[j][k];
        }
        bool flag = true;
        for (int j = 0; j < n; ++ j) if (c[j] > 0) {
            flag = false;
            break;
        }
        if (flag) {
            if (bitcount(ans) > bitcount(i)) {
                ans = i;
            } else if (bitcount(ans) == bitcount(i)) {
                if (ans > i) ans = i;
            }
        }
    }
    printf("%d", bitcount(ans));
    for (int i = 0; i < m; ++ i) if (ans & (1<<i)) {
        printf(" %d", i + 1);
    }
    printf("\n");

    return 0;
}
