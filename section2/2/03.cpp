/*
ID: sudawei1
PROG: runround
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

bool check(int n) {
    int digit[10], len = 0;
    bool vis[10] = {false};
    while (n > 0) {
        digit[len ++] = n % 10;
        if (vis[n % 10]) return false;
        vis[n % 10] = true;
        if (vis[0]) return false;
        n /= 10;
    }
    memset(vis, false, sizeof(vis));
    int i = len - 1;
    for (int k = len - 1; k >= 0; -- k) {
        int j = digit[i];
        if (vis[j]) return false;
        vis[j] = true;
        while (j > 0) {
            -- i, -- j;
            if (i < 0) i = len - 1;
        }
    }
    return i == len - 1;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("runround.out", "w", stdout);
    freopen("runround.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = n + 1; ; ++ i) {
        if (check(i)) {
            printf("%d\n", i);
            break;
        }
    }

    return 0;
}
