/*
ID: sudawei1
PROG: range
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

char a[255][255];
int sum[255][255];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("range.out", "w", stdout);
    freopen("range.in", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++ i) {
        scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= N; ++ i) {
        for (int j = 1; j <= N; ++ j) {
            sum[j][i] = sum[j - 1][i] + a[j][i] - '0';
        }
    }
    map<int, int> ans;
    for (int i = 1; i <= N; ++ i) {
        for (int j = i + 1; j <= N; ++ j) {
            int cc = 0;
            for (int k = 1; k <= N; ++ k) {
                if (sum[j][k] - sum[i-1][k] == (j - i + 1)) {
                    ++ cc;
                } else {
                    cc = 0;
                }
                if (cc == j - i + 1) {
                    ++ ans[cc];
                    -- cc;
                }
            }
        }
    }
    for (auto &p: ans) {
        printf("%d %d\n", p.first, p.second);
    }

    return 0;
}
