/*
ID: sudawei1
PROG: ditch
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

struct edge {
    int to, cap, rev;
    edge() {}
    edge(int _to, int _cap, int _rev): to(_to)
                                       ,cap(_cap)
                                       ,rev(_rev)
                                        {}
};

const int MAX_V = 210;
const int INF = 1e9;
vector<edge> G[MAX_V];
int level[MAX_V];
int iter[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].push_back(edge(to, cap, G[to].size()));
    G[to].push_back(edge(from, 0, G[from].size()-1));
}

void bfs(int s) {
    memset(level, -1, sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        for (int i = 0; i < G[v].size(); ++ i) {
            edge &e = G[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    for (int &i = iter[v]; i < G[v].size(); ++ i) {
        edge &e = G[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (; ; ) {
        bfs(s);
        if (level[t] < 0) return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("ditch.out", "w", stdout);
    freopen("ditch.in", "r", stdin);
#endif
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; ++ i) {
        int si, ei, ci;
        scanf("%d %d %d", &si, &ei, &ci);
        add_edge(si, ei, ci);
    }
    printf("%d\n", max_flow(1, M));

    return 0;
}
