/*
ID: sudawei1
PROG: subset
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
ll dp[1010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("subset.out", "w", stdout);
    freopen("subset.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int sum = (1 + n) * n / 2;
    if (sum % 2) {
        printf("0\n");
    } else {
        sum >>= 1;
        dp[0] = 1;
        for (int i = 1; i <= n; ++ i) {
            for (int j = sum - i; j >= 0; -- j) if (dp[j]) {
                dp[j + i] += dp[j];
            }
        }
        printf("%lld\n", dp[sum]/2);
    }

    return 0;
}
