/*
ID: sudawei1
PROG: butter
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
#include <set>
using namespace std;

int cc[810], dist[810];
bool vis[810];
using pii = pair<int, int>;
vector<pii> G[810];

void Dijkstra(int s) {
    memset(dist, 0x3f, sizeof(dist));
    dist[s] = 0;
    priority_queue<pii> pq;
    pq.emplace(pii(0, s));
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        vis[u] = true;
        for (auto &p: G[u]) if (!vis[p.first]) {
            int v = p.first, w = p.second;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(pii(-dist[v], v));
            }
        }
    }

    return ;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("butter.out", "w", stdout);
    freopen("butter.in", "r", stdin);
#endif
    int N, P, C;
    scanf("%d %d %d", &N, &P, &C);
    for (int i = 1; i <= N; ++ i) {
        int x;
        scanf("%d", &x);
        ++ cc[x];
    }
    for (int i = 0; i < C; ++ i) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(pii(v, w));
        G[v].emplace_back(pii(u, w));
    }
    int ans = INT_MAX;
    for (int i = 1; i <= P; ++ i) {
        Dijkstra(i);
        int sum = 0;
        for (int j = 1; j <= P; ++ j) {
            sum += dist[j] * cc[j];
        }
        if (sum < ans) ans = sum;
        memset(vis, false, sizeof(vis));
    }
    printf("%d\n", ans);

    return 0;
}
