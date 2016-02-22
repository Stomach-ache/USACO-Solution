/*
ID: sudawei1
PROG: shopping
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

using pii = pair<int, int>;
vector<pii> offer[110];
int pr[110], sz[110];
int t[5];
vector<int> need;
int p2[5];
int s;
map<vector<int>, int> dp;
map<int, int> id;
//int dp[6][6][6][6][6];

int dfs(vector<int> need) {
    if (dp.find(need) != dp.end()) return dp[need];
    int &ans = dp[need]; ans = 0;
    for (int i = 0; i < need.size(); ++ i) {
        ans += p2[i] * need[i];
    }
    for (int i = 0; i < s; ++ i) {
        vector<int> tmp(begin(need), end(need));
        bool flag = false;
        for (int j = 0; j < sz[i]; ++ j) if (id.find(offer[i][j].first) != id.end()) {
            int k = id[offer[i][j].first], kk = offer[i][j].second;
            tmp[k] -= kk; if (tmp[k] < 0) tmp[k] = 0;
            flag = true;
        }
        if (flag) ans = min(ans, dfs(tmp) + pr[i]);
    }
    return dp[need] = ans;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("shopping.out", "w", stdout);
    freopen("shopping.in", "r", stdin);
#endif
    scanf("%d", &s);
    for (int i = 0; i < s; ++ i) {
        int n;
        scanf("%d", &n);
        sz[i] = n;
        for (int j = 0; j < n; ++ j) {
            int c, k;
            scanf("%d %d", &c, &k);
            offer[i].emplace_back(pii(c, k));
        }
        scanf("%d", pr + i);
    }
    int b;
    scanf("%d", &b);
    for (int i = 0; i < b; ++ i) {
        int c, k, p;
        scanf("%d %d %d", &c, &k, &p);
        id[c] = i;
        t[i] = c;
        need.emplace_back(k);
        p2[i] = p;
    }

    int ans = dfs(need);
    printf("%d\n", ans);

    return 0;
}
