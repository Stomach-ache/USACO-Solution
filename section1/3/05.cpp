/*
ID: sudawei1
PROG: wormhole
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
#include <set>
using namespace std;

int n, ans = 0;
bool vis[20];
using pii = pair<int, int>;
map<pii, int> id;
pii p[20];
map<int, int> go;
#define fst first
#define snd second
int has[20];

bool check() {
    for (int i = 0; i < n; ++ i) {
        bool cc[20] = {false};
        int j = i;
        while (true) {
            if (cc[j]) return true;
            cc[j] = true;
            if (-1 == has[go[j]]) break;
            j = has[go[j]];
        }
    }

    return false;
}

void dfs(int cur, int cnt) {
    if (cnt == n) {
        if (check()) {
            ++ ans;
            /*
            for (auto p: go) {
                cerr << p.fst << ' ' << p.snd << endl;
            }
            */
        }
        return ;
    }
    if (vis[cur]) dfs(cur + 1, cnt);
    for (int i = cur + 1; i < n; ++ i) if (!vis[cur] && !vis[i]) {
        go[cur] = i; go[i] = cur;
        vis[i] = vis[cur] = true;
        dfs(cur + 1, cnt + 2);
        vis[i] = vis[cur] = false;
    }
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("wormhole.out", "w", stdout);
    freopen("wormhole.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = pii(x, y);
        id[p[i]] = i;
    }
    for (int i = 0; i < n; ++ i) {
        int k = -1;
        for (int j = 0; j < n; ++ j) if (i != j) {
            if (p[j].fst > p[i].fst && p[j].snd == p[i].snd) {
                if (k != -1) {
                    if (p[j].fst < p[k].fst) k = j;
                } else {
                    k = j;
                }
            }
        }
        has[i] = k;
    }

    dfs(0, 0);
    printf("%d\n", ans);

    return 0;
}
