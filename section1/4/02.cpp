/*
ID: sudawei1
PROG: milk3
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

#define __DEBUGE
bool vis[25][25];
using pii = pair<int, int>;
int main() {
#ifdef __DEBUGE
    freopen("milk3.out", "w", stdout);
    freopen("milk3.in", "r", stdin);
#endif
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);
    vector<int> ans;

    queue<pii> que;
    que.emplace(pii(0, 0));
    while (!que.empty()) {
        int a = que.front().first, b = que.front().second;
        que.pop();
        int c = C - a - b;
        if (vis[a][b]) continue;
        vis[a][b] = true;
        if (a == 0) {
            ans.emplace_back(c);
        }
        if (a >= B - b && !vis[a-(B-b)][B]) {
            que.emplace(pii(a-(B-b), B));
        } else if (a < B - b && !vis[0][b+a]){
            que.emplace(pii(0, b+a));
        }
        if (a >= C - c && !vis[a-(C-c)][b]) {
            que.emplace(pii(a-(C-c), b));
        } else if (a < C - c && !vis[0][b]){
            que.emplace(pii(0, b));
        }
        if (b >= A - a && !vis[A][b-(A-a)]) {
            que.emplace(pii(A, b-(A-a)));
        } else if (b < A - a && !vis[a+b][0]){
            que.emplace(pii(a+b, 0));
        }
        if (b >= C - c && !vis[a][b-(C-c)]) {
            que.emplace(pii(A, b-(C-c)));
        } else if (b < C - c && !vis[a][0]){
            que.emplace(pii(a, 0));
        }
        if (c >= A - a && !vis[A][b]) {
            que.emplace(pii(A, b));
        } else if (c < A - a && !vis[a+c][b]){
            que.emplace(pii(a+c, b));
        }
        if (c >= B - b && !vis[a][B]) {
            que.emplace(pii(a, B));
        } else if (c < B - b && !vis[a][b+c]){
            que.emplace(pii(a, b+c));
        }
    }

    sort(begin(ans), end(ans));
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    int sz = ans.size();
    for (int i = 0; i < sz; ++ i) {
        printf("%d%c", ans[i], i == sz-1? '\n': ' ');
    }

    return 0;
}
