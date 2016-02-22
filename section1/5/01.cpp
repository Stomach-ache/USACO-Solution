/*
ID: sudawei1
PROG: numtri
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

int a[1010][1010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("numtri.out", "w", stdout);
    freopen("numtri.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < i; ++ j) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = n - 1; i >= 1; -- i) {
        for (int j = 0; j < i; ++ j) {
            a[i][j] += max(a[i+1][j], a[i+1][j+1]);
        }
    }
    printf("%d\n", a[1][0]);

    return 0;
}
