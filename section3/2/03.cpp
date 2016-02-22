/*
ID: sudawei1
PROG: spin
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

int speed[5], w[5], b[5][5], e[5][5];

bool check() {
    for (int k = 0; k < 360; ++ k) {
        int c = 0;
        for (int i = 0; i < 5; ++ i) {
            for (int j = 0; j < w[i]; ++ j) {
                bool flag = false;
                for (int t = b[i][j]; ;) {
                    if (t == k) {
                        flag = true;
                        break;
                    }
                    if (t == e[i][j]) break;
                    t = (t + 1) % 360;
                }
                if (flag) {
                    ++ c;
                    break;
                }
            }
        }
        if (c == 5) return true;
    }
    return false;
}

void step() {
    for (int i = 0; i < 5; ++ i) {
        for (int j = 0; j < w[i]; ++ j) {
            b[i][j] += speed[i];
            e[i][j] += speed[i];
            b[i][j] %= 360;
            e[i][j] %= 360;
        }
    }
}


#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("spin.out", "w", stdout);
    freopen("spin.in", "r", stdin);
#endif
    for (int i = 0; i < 5; ++ i) {
        scanf("%d", speed + i);
        scanf("%d", w + i);
        for (int j = 0; j < w[i]; ++ j) {
            scanf("%d %d", &b[i][j], &e[i][j]);
            e[i][j] = (e[i][j] + b[i][j]) % 360;
        }
    }

    for (int i = 0; i < 360; ++ i) {
        if (check()) {
            printf("%d\n", i);
            return 0;
        }
        step();
    }
    printf("none\n");

    return 0;
}
