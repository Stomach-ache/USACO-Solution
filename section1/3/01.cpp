/*
ID: sudawei1
PROG: milk
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

#define __DEBUGE
struct node {
    int p, v;
    bool operator < (const node &b) const {
        return p < b.p;
    }
}a[5010];
int main() {
#ifdef __DEBUGE
    freopen("milk.out", "w", stdout);
    freopen("milk.in", "r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        scanf("%d %d", &a[i].p, &a[i].v);
    }
    std::sort(a, a + m);
    int ans = 0;
    for (int i = 0; i < m && n > 0; ++ i) {
        if (a[i].v >= n) {
            ans += n * a[i].p;
            n = 0;
        } else {
            ans += a[i].v * a[i].p;
            n -= a[i].v;
        }
    }
    printf("%d\n", ans);

    return 0;
}
