/*
ID: sudawei1
PROG: nocows
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

constexpr int MOD = 9901;
int dp[110][210], sum[110][210];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    ofstream fout("nocows.out");
    ifstream fin("nocows.in");
#endif
    int n, k;
    fin >> n >> k;
    sum[1][1] = dp[1][1] = 1;
    for (int i = 2; i <= k; ++ i) {
        for (int j = 1; j <= n; j += 2) {
            for (int lft = 1; lft < j-1; lft += 2) {
                dp[i][j] += dp[i - 1][j - lft - 1] * sum[i - 2][lft] % MOD;
                dp[i][j] += dp[i - 1][lft] * sum[i - 2][j - lft - 1] % MOD;
                dp[i][j] += dp[i - 1][lft] * dp[i - 1][j - 1 - lft] % MOD;
            }
            dp[i][j] %= MOD;
            if (dp[i][j] < 0) dp[i][j] += MOD;
            sum[i][j] = sum[i - 1][j] + dp[i][j];
            sum[i][j] %= MOD;
        }
    }
    fout << dp[k][n] << endl;

    return 0;
}
