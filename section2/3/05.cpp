/*
ID: sudawei1
PROG: concom
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

bool con[110][110];
int per[110][110];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("concom.out", "w", stdout);
    freopen("concom.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if (c > 50) con[a][b] = true;
        per[a][b] = c;
    }

    for (int i = 1; i <= 100; ++ i) {
        con[i][i] = true;
        bool flag = true;
        while (flag) {
            flag = false;
            for (int j = 1; j <= 100; ++ j) if (!con[i][j]) {
                int sum = 0;
                for (int k = 1; k <= 100; ++ k) if (con[i][k]) {
                    sum += per[k][j];
                }
                if (sum > 50) flag = con[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= 100; ++ i) for (int j = 1; j <= 100; ++ j) {
        if (i != j && con[i][j]) printf("%d %d\n", i, j);
    }

    return 0;
}
