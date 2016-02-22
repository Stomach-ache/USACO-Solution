/*
ID: sudawei1
PROG: ttwo
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

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
struct State {
    int x, y, d, t;
    /*
    bool operator =(const State &b) const {
        return x == b.x && y == b.y;
    }
    */
};

using pii = pair<State, State>;
char a[11][11];
bool vis[11][11][11][11][110];

void makeMove(State &s) {
    ++ s.t;
    int x = s.x + dx[s.d], y = s.y + dy[s.d];
    if (x >= 10 || x < 0 || y >= 10 || y < 0 || a[x][y] == '*') {
        s.d = (s.d + 1) % 4;
        return ;
    }
    s.x = x, s.y = y;
}

int bfs(State a, State b) {
    queue<pii> que;
    que.push(pii(a, b));
    while (!que.empty()) {
        State cows = que.front().first;
        State FJ = que.front().second;
        que.pop();
        if (cows.x == FJ.x && cows.y == FJ.y) {
            return cows.t;
        }

        vis[cows.x][cows.y][FJ.x][FJ.y][cows.t] = true;
        makeMove(cows);
        makeMove(FJ);
        if (!vis[cows.x][cows.y][FJ.x][FJ.y][cows.t])
            que.push(pii(cows, FJ));
    }

    return 0;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("ttwo.out", "w", stdout);
    freopen("ttwo.in", "r", stdin);
#endif
    int x1, x2, y1, y2;
    for (int i = 0; i < 10; ++ i) {
        scanf("%s", a[i]);
        for (int j = 0; j < 10; ++ j) {
            if (a[i][j] == 'C') x1 = i, y1 = j;
            else if (a[i][j] == 'F') x2 = i, y2 = j;
        }
    }
    State cows = {x1, y1, 0, 0}, FJ = {x2, y2, 0, 0};
    int res = bfs(cows, FJ);
    printf("%d\n", res);

    return 0;
}
