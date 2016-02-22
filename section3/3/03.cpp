/*
ID: sudawei1
PROG: camelot
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

using ll = long long;
int dx1[] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy1[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dx2[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy2[] = {0, -1, -1, -1, 0, 1, 1, 1};
int dist1[30][30][30][30];
int dist2[30][30];
ll sum[30][30];

constexpr int oo = 0x3f3f3f3f;

using pii = pair<int, int>;
#define fst first
#define snd second
int n, m;
void bfs(int x, int y, int dx[], int dy[], int dist[][30]) {
    queue<pii> que;
    que.emplace(pii(x, y));
    dist[x][y] = 0;
    while (!que.empty()) {
        pii cur = que.front(); que.pop();
        for (int i = 0; i < 8; ++ i) {
            int xx = cur.fst + dx[i];
            int yy = cur.snd + dy[i];
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            if (dist[xx][yy] != oo) continue;
            dist[xx][yy] = dist[cur.fst][cur.snd] + 1;
            que.emplace(pii(xx, yy));
        }
    }

    return ;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("camelot.out", "w", stdout);
    freopen("camelot.in", "r", stdin);
#endif

    scanf("%d %d\n", &n, &m);
    memset(dist1, 0x3f, sizeof(dist1));
    memset(dist2, 0x3f, sizeof(dist2));
    pii king;
    vector<pii> knight;
    char y; int x;
    scanf("%c %d\n", &y, &x);
    king.fst = x - 1, king.snd = y - 'A';
    bfs(king.fst, king.snd, dx2, dy2, dist2);
    vector<pii> nb;
    for (int i = -2; i <= 2; ++ i) {
        for (int j = -2; j <= 2; ++ j) {
            int xx = king.fst + i ;
            int yy = king.snd + j;
            if (xx < 0 || xx >= n || yy < 0 || yy >= m) continue;
            nb.emplace_back(pii(xx, yy));
        }
    }
    while (~scanf("%c %d\n", &y, &x)) {
        knight.emplace_back(pii(x-1, y-'A'));
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            bfs(i, j, dx1, dy1, dist1[i][j]);
        }
    }
    /*
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            printf("%d\n", dist2[i][j]);
        }
    }
    */

    ll ans = INT_MAX;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            ll tmp = dist2[i][j];
            for (auto &p: knight) {
                tmp += dist1[p.fst][p.snd][i][j];
            }
            sum[i][j] = tmp - dist2[i][j];
            ans = min(ans, tmp);
        }
    }
    //printf("--%d\n", ans);

    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            for (auto k: knight) {
                for (auto &p: nb) {
                    ans = min(ans, sum[i][j] - dist1[k.fst][k.snd][i][j]
                            + dist1[k.fst][k.snd][p.fst][p.snd]
                            + dist1[p.fst][p.snd][i][j]
                            + dist2[p.fst][p.snd]);
                }
            }
        }
    }
    printf("%lld\n", ans);

    return 0;
}
