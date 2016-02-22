/*
ID: sudawei1
PROG: rockers
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

int N, T, M;
int a[22];
int dp[22][22][22];

int dfs(int i, int lft, int unused) {
    if (i >= N) return 0;
    //if (unused < 0) return 0;
    if (dp[i][lft][unused] != -1) {
        return dp[i][lft][unused];
    }
    int &ans = dp[i][lft][unused];
    ans = 0;

    if (lft >= a[i]) {
        ans = max(ans, dfs(i + 1, lft - a[i], unused) + 1);
    }
    ans = max(ans, dfs(i + 1, lft, unused));
    if (unused > 0) {
        ans = max(ans, dfs(i, T, unused - 1));
    }
    return ans;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("rockers.out", "w", stdout);
    freopen("rockers.in", "r", stdin);
#endif
    memset(dp, -1, sizeof(dp));
    scanf("%d %d %d", &N, &T, &M);
    for (int i = 0; i < N; ++ i) scanf("%d", a + i);
    int ans = dfs(0, 0, M);
    printf("%d\n", ans);

    return 0;
}
