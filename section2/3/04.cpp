/*
ID: sudawei1
PROG: money
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

using ll = long long;
ll dp[10010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("money.out", "w", stdout);
    freopen("money.in", "r", stdin);
#endif
    int v, n;
    scanf("%d %d", &v, &n);
    vector<int> a;
    for (int i = 0; i < v; ++ i) {
        int x;
        scanf("%d", &x);
        a.emplace_back(x);
    }
    sort(begin(a), end(a));
    dp[0] = 1;
    for (int i = 0; i < v; ++ i) {
        for (int j = a[i]; j <= n; ++ j) {
            dp[j] += dp[j - a[i]];
        }
    }
    printf("%lld\n", dp[n]);

    return 0;
}
