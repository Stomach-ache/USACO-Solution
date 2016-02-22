/*
ID: sudawei1
PROG: kimbits
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

using ll = long long;
ll C[35][35];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("kimbits.out", "w", stdout);
    freopen("kimbits.in", "r", stdin);
#endif
    C[0][0] = 1;
    for (int i = 1; i < 32; ++ i) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; ++ j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    ll N, L, I;
    scanf("%lld %lld %lld", &N, &L, &I);
    for (int i = N; i >= 1; -- i) {
        ll sum = 0;
        for (int j = 0; j <= L; ++ j) sum += C[i - 1][j];
        if (sum < I) {
            printf("1");
            I -= sum;
            -- L;
        } else {
            printf("0");
        }
    }
    printf("\n");

    return 0;
}
