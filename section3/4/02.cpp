/*
ID: sudawei1
PROG: fence9
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

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("fence9.out", "w", stdout);
    freopen("fence9.in", "r", stdin);
#endif
    int n, m, p;
    scanf("%d %d %d", &n, &m, &p);
    int S = p * m;
    int a = p + __gcd(n, m) + __gcd(abs(n - p), m);
    printf("%d\n", (int)((S + 2 - a) / 2));

    return 0;
}
