/*
ID: sudawei1
PROG: cowtour
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
char a[200][200];
double d[200][200];
bool vis[200][200];
double farthest[200];
constexpr double oo = 1e12;

double dist(pii a, pii b) {
    return sqrt((0.0 + a.first - b.first) * (a.first - b.first) + (0.0 + a.second - b.second) * (a.second - b.second));
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("cowtour.out", "w", stdout);
    freopen("cowtour.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    pii p[200];
    for (int i = 0; i < n; ++ i) {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i] = pii(x, y);
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%s", a[i]);
    }
    //printf("--hello\n");
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) if (a[i][j] == '1') {
            vis[i][j] = true;
            d[i][j] = dist(p[i], p[j]);
        } else {
            d[i][j] = oo;
        }
        vis[i][i] = true;
        d[i][i] = 0.0;
    }
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (vis[i][k] && vis[k][j]) {
                    vis[i][j] = true;
                }
            }
        }
    }
    for (int k = 0; k < n; ++ k) {
        for (int i = 0; i < n; ++ i) {
            for (int j = 0; j < n; ++ j) {
                if (vis[i][k] && vis[k][j]) {
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
                }
            }
        }
    }
    for (int i = 0; i < n; ++ i) {
        double tmp = 0;
        for (int j = 0; j < n; ++ j) if (vis[i][j]) {
            tmp = max(tmp, d[i][j]);
        }
        farthest[i] = tmp;
    }

    double ans = oo;
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) if (!vis[i][j]) {
            ans = min(ans, dist(p[i], p[j]) + farthest[i] + farthest[j]);
        }
    }
    for (int i = 0; i < n; ++ i) ans = max(ans, farthest[i]);
    printf("%.6f\n", ans);

    return 0;
}
