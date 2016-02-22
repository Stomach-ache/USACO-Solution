/*
ID: sudawei1
PROG: barn1
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <vector>
using std::vector;

#define __DEBUGE
bool vis[210];
int main() {
#ifdef __DEBUGE
    freopen("barn1.out", "w", stdout);
    freopen("barn1.in", "r", stdin);
#endif
    int m, s, c;
    scanf("%d%d%d", &m, &s, &c);
    for (int i = 0; i < c; ++ i) {
        int x;
        scanf("%d", &x);
        vis[x] = true;
    }
    vector<int> vec;
    int i = 1;
    while (i <= s && !vis[i]) ++ i;
    while (s >= i && !vis[s]) -- s;
    int ans = s - i + 1;
    while (i <= s) {
        if (!vis[i]) {
            int j = i;
            while (j <= s && !vis[j]) ++ j;
            vec.emplace_back(j - i);
            //printf("--%d\n", j - i);
            i = j;
        } else {
            ++ i;
        }
    }
    std::sort(begin(vec), end(vec));
    for (int i = vec.size()-1, j = 0; i >= 0 && j < m-1; -- i, ++ j) {
        ans -= vec[i];
    }
    printf("%d\n", ans);

    return 0;
}
