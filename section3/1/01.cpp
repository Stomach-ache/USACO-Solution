/*
ID: sudawei1
PROG: agrinet
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

int a[110][110];
int dist[110];
bool vis[110];

int Prim(int n) {
    int ans = 0;
    for (int i = 0; i < n; ++ i) dist[i] = a[0][i];
    vis[0] = true;
    for (int i = 1; i < n; ++ i) {
        int tmp = 0x3f3f3f3f, id = 0;
        for (int i = 0; i < n; ++ i) if (!vis[i]) {
            if (tmp > dist[i]) tmp = dist[i], id = i;
        }
        vis[id] = true;
        ans += tmp;
        for (int i = 0; i < n; ++ i) {
            if (dist[i] > a[id][i]) {
                dist[i] = a[id][i];
            }
        }
    }
    return ans;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("agrinet.out", "w", stdout);
    freopen("agrinet.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            scanf("%d", &a[i][j]);
        }
    }

    int ans = Prim(n);
    printf("%d\n", ans);

    return 0;
}
