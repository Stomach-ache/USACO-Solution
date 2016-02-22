/*
ID: sudawei1
PROG: crypt1
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>

bool digit[10];
int len(int n) {
    int cc = 0;
    while (n > 0) {
        ++ cc;
        if (!digit[n % 10]) return 10;
        n /= 10;
    }
    return cc;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("crypt1.out", "w", stdout);
    freopen("crypt1.in", "r", stdin);
#endif
    int n, a[10];
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", &a[i]);
        digit[a[i]] = true;
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            for (int k = 0; k < n; ++ k) {
                int p1 = a[i]*100+a[j]*10+a[k];
                for (int s = 0; s < n; ++ s) {
                    if (len(p1 * a[s]) != 3) continue;
                    for (int t = 0; t < n; ++ t) {
                        if (len(p1 * a[t]) != 3) continue;
                        if (len(p1*a[s] + p1*a[t]*10) != 4) continue;
                        ++ ans;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}
