/*
ID: sudawei1
PROG: skidesign
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
#include <set>
using namespace std;

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("skidesign.out", "w", stdout);
    freopen("skidesign.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    vector<int> vec;
    for (int i = 0; i < n; ++ i) {
        int x;
        scanf("%d", &x);
        vec.emplace_back(x);
    }
    sort(begin(vec), end(vec));

    int res = INT_MAX;
    for (int i = 1; i <= 100; ++ i) {
        int ans = 0;
        for (int j = 0; j < n; ++ j) {
            if (vec[j] < i) ans += (i - vec[j]) * (i - vec[j]);
            else if (vec[j] - i > 17) ans += (vec[j]-i-17) * (vec[j]-i-17);
        }
        res = min(res, ans);
    }
    printf("%d\n", res);

    return 0;
}
