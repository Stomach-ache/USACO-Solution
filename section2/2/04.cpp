/*
ID: sudawei1
PROG: lamps
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

int s[110];

bool check(const vector<int> &a) {
    for (int i = 0; i < a.size(); ++ i) {
        if (s[i] != -1 && s[i] != a[i]) return false;
    }
    return true;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("lamps.out", "w", stdout);
    freopen("lamps.in", "r", stdin);
#endif
    int n, m;
    scanf("%d %d", &n, &m);
    int x;
    memset(s, -1, sizeof(s));
    while (scanf("%d", &x) && x != -1) s[x-1] = 1;
    while (scanf("%d", &x) && x != -1) s[x-1] = 0;
    vector<vector<int>> ans;
    if (m % 2 == 0 || m % 3 == 0) {
        vector<int> tmp(n, 1);
        if (check(tmp)) ans.emplace_back(tmp);
    }

    vector<int> tmp(n, 0);
    if (m > 0 && check(tmp)) ans.emplace_back(tmp);
    for (int i = 0; i < n; i += 2) tmp[i] = 1;
    if (m > 0 && check(tmp)) ans.emplace_back(tmp);
    for (int i = 0; i < n; ++ i) tmp[i] ^= 1;
    if (m > 0 && check(tmp)) ans.emplace_back(tmp);
    if (m > 0 && (m % 2 == 1 || m % 3 == 1)) {
        for (int i = 0; i < n; ++ i) tmp[i] = 1;
        for (int i = 0; i < n; ++ i) {
            if ((i + 1) % 3 == 1) tmp[i] = 0;
        }
        if (check(tmp)) ans.emplace_back(tmp);
    }

    for (int i = 0; i < n; ++ i) tmp[i] = 0;
    if (m > 0 && (m % 2 == 0 || m % 3 == 0)) {
        for (int i = 0; i < n; ++ i) {
            if ((i + 1) % 3 == 1) tmp[i] ^= 1;
        }
        if (check(tmp)) ans.emplace_back(tmp);
    }
    for (int i = 0; i < n; ++ i) tmp[i] = 1;

    if (m > 0 && (m % 2 == 0 || m % 3 == 0)) {
        for (int i = 0; i < n; i += 2) tmp[i] ^= 1;
        for (int i = 0; i < n; ++ i) {
            if ((i + 1) % 3 == 1) tmp[i] ^= 1;
        }
        if (check(tmp)) ans.emplace_back(tmp);
        for (int i = 0; i < n; ++ i) tmp[i] = 1;

        for (int i = 1; i < n; i += 2) tmp[i] ^= 1;
        for (int i = 0; i < n; ++ i) {
            if ((i + 1) % 3 == 1) tmp[i] ^= 1;
        }
        if (check(tmp)) ans.emplace_back(tmp);
    }

    sort(begin(ans), end(ans), [&n](const vector<int> &a, const vector<int> &b) {
            for (int i = 0; i < n; ++ i) if (a[i] != b[i]) return a[i] < b[i];
            });
    ans.erase(unique(begin(ans), end(ans)), end(ans));
    if (ans.size() == 0) printf("IMPOSSIBLE\n");
    else {
        for (auto vec: ans) {
            for (int i = 0; i < n; ++ i) {
                printf("%d", vec[i]);
            }
            printf("\n");
        }
    }

    return 0;
}
