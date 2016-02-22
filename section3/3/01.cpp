/*
ID: sudawei1
PROG: fence
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

vector<int> G[510];
vector<int> ans;
int deg[510];
int vis[510][510];

void dfs(int u) {
    for (auto &v: G[u]) if (vis[u][v]) {
        -- vis[u][v]; -- vis[v][u];
        dfs(v);
    }
    ans.emplace_back(u);
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("fence.out", "w", stdout);
    freopen("fence.in", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
        ++ deg[u]; ++ deg[v];
        ++ vis[u][v]; ++ vis[v][u];
    }
    for (int i = 1; i <= 500; ++ i) {
        sort(begin(G[i]), end(G[i]));
    }
    int s = 500;
    for (int i = 1; i <= 500; ++ i) {
        if (deg[i] % 2 == 1) {
            s = i;
            break;
        } else {
            if (s > i) s = i;
        }
    }
    dfs(s);
    reverse(begin(ans), end(ans));
    for (auto &v: ans) printf("%d\n", v);

    return 0;
}
