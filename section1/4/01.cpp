/*
ID: sudawei1
PROG: ariprog
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

#define __DEBUGE
using pii = pair<int, int>;
bool vis[1000010];
int main() {
#ifdef __DEBUGE
    freopen("ariprog.out", "w", stdout);
    freopen("ariprog.in", "r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    unordered_set<int> s;
    vector<int> vec;
    for (int i = 0; i <= m; ++ i) for (int j = i; j <= m; ++ j) {
        int x = i*i + j*j;
        s.insert(x);
        vis[x] = true;
    }
    for (auto v: s) vec.emplace_back(v);
    sort(begin(vec), end(vec));
    int cc = 0, sz = vec.size();

    vector<pii> ans;
    for (int j = 0; j < sz; ++ j) {
        int a = vec[j];
        for (int i = j + 1; i < sz; ++ i) {
            int b = vec[i];
            if ((b - a) % (n-1) != 0) continue;
            int d = (b - a) / (n - 1);
            bool flag = true;
            for (int k = 1; k < n; ++ k) {
                if (!vis[a + d*k]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ++ cc;
                ans.emplace_back(pii(a, d));
                //printf("%d %d\n", v, d);
            }
        }
    }
    if (!cc) printf("NONE\n");
    else {
        sort(begin(ans), end(ans), [&](const pii&a, const pii&b) {
                if (a.second != b.second) return a.second < b.second;
                return a.first < b.first;
                });
        for (int i = 0; i < ans.size(); ++ i) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
    }

    return 0;
}
