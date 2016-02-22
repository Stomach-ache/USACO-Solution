/*
ID: sudawei1
PROG: maze1
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
    int x, y, t;
    /*
    bool operator =(const State &b) const {
        return x == b.x && y == b.y;
    }
    */
};

char a[210][210];
int d[210][210];
int n, m;

int bfs(queue<State> &que) {
    while (!que.empty()) {
        State s = que.front();
        que.pop();
        for (int i = 0; i < 4; ++ i) {
            if (a[s.x+dx[i]][s.y+dy[i]] != ' ') continue;
            int x = s.x + dx[i];
            int y = s.y + dy[i];
            x = x + dx[i];
            y = y + dy[i];
            if (x >= 2*n+1 || x < 0 || y >= 2*m+1 || y < 0 || d[x][y] != -1)
                continue;
            d[x][y] = s.t + 1;
            que.push(State{x, y, s.t + 1});
        }
    }

    return 0;
}

bool out(int x, int y) {
    for (int i = 0; i < 4; ++ i) {
        if (a[x+dx[i]][y+dy[i]] != ' ') continue;
        int xx = x + dx[i];
        int yy = y + dy[i];
        xx = xx + dx[i];
        yy = yy + dy[i];
        if (xx >= 2*n+1 || xx < 0 || yy >= 2*m+1 || yy < 0) {
            return true;
        }
    }
    return false;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("maze1.out", "w", stdout);
    freopen("maze1.in", "r", stdin);
#endif
    scanf("%d %d\n", &m, &n);
    queue<State> que;
    memset(d, -1, sizeof(d));
    for (int i = 0; i < n*2+1; ++ i) {
        fgets(a[i], 100, stdin);
        //printf("%s", a[i]);
    }
    for (int i = 0; i < n*2+1; ++ i) {
        for (int j = 0; j < 2*m+1; ++ j) if (a[i][j] == ' ') {
            if (i == 0 || i == n*2 || j == 0 || j == 2*m) continue;
            if (out(i, j)) {
                d[i][j] = 1;
                que.push(State{i, j, 1});
            //    printf("--%d %d\n", i, j);
            }
        }
    }
    bfs(que);
    int ans = -1;
    for (int i = 0; i < 2*n+1; ++ i) {
        for (int j = 0; j < 2*m+1; ++ j) {
            ans = max(ans, d[i][j]);
        }
    }
    printf("%d\n", ans);

    return 0;
}
