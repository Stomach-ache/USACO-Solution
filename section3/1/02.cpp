/*
ID: sudawei1
PROG: inflate
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

int dp[10010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("inflate.out", "w", stdout);
    freopen("inflate.in", "r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        int v, w;
        scanf("%d %d", &v, &w);
        for (int j = w; j <= n; ++ j) {
            dp[j] = max(dp[j], dp[j - w] + v);
        }
    }
    printf("%d\n", dp[n]);

    return 0;
}
