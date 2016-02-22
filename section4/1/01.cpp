/*
ID: sudawei1
PROG: nuggets
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
#include <queue>
#include <map>
#include <unordered_set>
using namespace std;

constexpr int oo = 130000;
bool dp[oo];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("nuggets.out", "w", stdout);
    freopen("nuggets.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int a[10];
    int g = 0;
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        g = __gcd(g, a[i]);
    }
    sort(a, a + n);
    if (a[0] == 1 || g != 1) {
        printf("0\n");
    } else {
        dp[0] = true;
        for (int i = 0; i < oo; ++ i) if (dp[i]) {
            for (int j = 0; j < n; ++ j) if (a[j] + i <= oo){
                dp[a[j] + i] = true;
            }
        }
        for (int i = oo; i >= 0; -- i) if (!dp[i]) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
