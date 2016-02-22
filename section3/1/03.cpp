/*
ID: sudawei1
PROG: humble
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
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
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("humble.out", "w", stdout);
    freopen("humble.in", "r", stdin);
#endif
    int K, N;
    scanf("%d %d", &K, &N);
    vector<int> factor;
    for (int i = 0; i < K; ++ i) {
        int x;
        scanf("%d", &x);
        factor.emplace_back(x);
    }
    vector<int> ptr(K, 0), humble;
    humble.emplace_back(1);
    for (int i = 1; i <= N; ++ i) {
        vector<int> lol;
        int Min = INT_MAX;
        for (int j = 0; j < K; ++ j) {
            lol.emplace_back(factor[j] * humble[ptr[j]]);
            Min = min(Min, lol[j]);
        }
        for (int j = 0; j < K; ++ j) if (Min == lol[j]) ++ ptr[j];
        humble.emplace_back(Min);
    }
    printf("%d\n", humble[N]);

    return 0;
}
