/*
ID: sudawei1
PROG: game1
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

int a[110], s[110];
int dp[110][110];

int dfs(int l, int r) {
    if (l == r) return a[l];
    if (dp[l][r] != -1) return dp[l][r];
    dp[l][r] = max(s[r] - s[l] - dfs(l+1, r) + a[l]
            , s[r - 1] - s[l - 1] - dfs(l, r - 1) + a[r]);
    return dp[l][r];
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("game1.out", "w", stdout);
    freopen("game1.in", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    memset(dp, -1, sizeof(dp));
    for (int i = 1; i <= N; ++ i) {
        scanf("%d", a + i);
        s[i] = s[i - 1] + a[i];
    }
    dfs(1, N);

    printf("%d %d\n", dp[1][N], s[N] - dp[1][N]);

    return 0;
}
