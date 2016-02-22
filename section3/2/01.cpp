/*
ID: sudawei1
PROG: fact4
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

int get(int n, int x) {
    int res = 0, y = x;
    while (n >= y) {
        res += n / y;
        y = y * x;
    }
    return res;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("fact4.out", "w", stdout);
    freopen("fact4.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    int c2 = get(n, 2), c5 = get(n, 5);
    c2 = c5 = min(c2, c5);
    int ans = 1;
    for (int i = 2; i <= n; ++ i) {
        int x = i;
        while (c2 > 0 && x % 2 == 0) -- c2, x /= 2;
        while (c5 > 0 && x % 5 == 0) -- c5, x /= 5;
        ans = ans * x % 10;
    }
    printf("%d\n", ans);

    return 0;
}
