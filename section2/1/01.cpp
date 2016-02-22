/*
ID: sudawei1
PROG: castle
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

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int dv[] = {1, 2, 4, 8};
int a[55][55], com[55][55], cnt[10000];
int n, m;

void dfs(int x, int y, int c) {
    com[x][y] = c;
    ++ cnt[c];
    for (int i = 0; i < 4; ++ i) if (!(a[x][y]&dv[i])) {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx <= n && xx >= 1 && yy <= m && yy >= 1 && !com[xx][yy]) {
            dfs(xx, yy, c);
        }
    }
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("castle.out", "w", stdout);
    freopen("castle.in", "r", stdin);
#endif
    scanf("%d %d", &m, &n);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) {
            scanf("%d", &a[i][j]);
        }
    }

    int cc = 0;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1; j <= m; ++ j) if (!com[i][j]) {
            dfs(i, j, ++ cc);
        }
    }
    printf("%d\n", cc);
    int maxVal = 0;
    for (int i = 1; i <= cc; ++ i) maxVal = max(maxVal, cnt[i]);
    printf("%d\n", maxVal);

    int x, y, d;
    maxVal = 0;
    for (int j = 1; j <= m; ++ j) {
        for (int i = n; i >= 1; -- i) {
            if (i != 1 && (a[i][j] & 2)) {
                if (com[i][j] != com[i-1][j]) {
                    if (cnt[com[i][j]] + cnt[com[i-1][j]] > maxVal) {
                        maxVal = cnt[com[i][j]] + cnt[com[i-1][j]];
                        x = i, y = j, d = 1;
                    }
                }
            }
            if (j != m && (a[i][j] & 4)) {
                if (com[i][j] != com[i][j+1]) {
                    if (cnt[com[i][j]] + cnt[com[i][j+1]] > maxVal) {
                        maxVal = cnt[com[i][j]] + cnt[com[i][j+1]];
                        x = i, y = j, d = 0;
                    }
                }
            }
        }
    }
    printf("%d\n", maxVal);
    printf("%d %d %c\n", x, y, d? 'N': 'E');

    return 0;
}
