/*
ID: sudawei1
PROG: beads
LANG: C++11
*/

#include <cstdio>
#include <algorithm>

#define __DEBUG

bool equal(char c1, char c2) {
    if (c1 == 'w' || c2 == 'w' || c1 == c2) return true;
    return false;
}

char s[400];
int lft[400][2], rgt[400][2];
int main(void) {
#ifdef __DEBUG
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    scanf("%s", s);
    for (int i = 0; i < n; ++ i) {
        char ch[3] = "br";
        for (int k = 0; k < 2; ++ k) {
            int j = (i - 1 + n) % n, cc = 0;
            while (j != i && (s[j] == ch[k] || s[j] == 'w')) {
                j = (j - 1 + n) % n;
                ++ cc;
            }
            if (s[i] == ch[k]) {
                lft[i][k] = cc + 1;
            } else if (s[i] != 'w') {
                lft[i][k] = 1;
            } else {
                lft[i][k] = std::max(lft[i][k], cc + 1);
                lft[i][k^1] = std::max(lft[i][k^1], cc + 1);
            }
        }
    }

    for (int i = 0; i < n; ++ i) {
        char ch[3] = "br";
        for (int k = 0; k < 2; ++ k) {
            int j = (i + 1) % n, cc = 0;
            while (j != i && (s[j] == ch[k] || s[j] == 'w')) {
                j = (j + 1) % n;
                ++ cc;
            }
            if (s[i] == ch[k]) {
                rgt[i][k] = cc + 1;
            } else if (s[i] != 'w') {
                rgt[i][k] = 1;
            } else {
                rgt[i][k] = std::max(rgt[i][k], cc + 1);
                rgt[i][k^1] = std::max(rgt[i][k^1], cc + 1);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        int tmp1 = std::max(rgt[(i + 1)%n][0], rgt[(i + 1)%n][1]);
        int tmp2 = std::max(lft[i][0], lft[i][1]);
        ans = std::max(ans, std::min(tmp1 + tmp2, n));
    }
    printf("%d\n", ans);
    return 0;
}
