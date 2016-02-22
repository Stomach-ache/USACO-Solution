/*
ID: sudawei1
PROG: frac1
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

using pii = pair<int, int>;
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("frac1.out", "w", stdout);
    freopen("frac1.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<pii> frac;
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j <= i; ++ j) {
            int g = __gcd(i, j);
            int x = j, y = i;
            if (g) x /= g, y /= g;
            frac.emplace_back(pii(x, y));
        }
    }
    sort(begin(frac), end(frac), [](const pii &a, const pii &b) {
            return a.first * b.second < a.second * b.first;
            });
    frac.erase(unique(begin(frac), end(frac)), end(frac));
    for (int i = 0; i < frac.size(); ++ i) {
        printf("%d/%d\n", frac[i].first, frac[i].second);
    }

    return 0;
}
