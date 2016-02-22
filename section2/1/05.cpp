/*
ID: sudawei1
PROG: hamming
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

int dist(int a, int b) {
    return __builtin_popcount(a^b);
}

int N, B, D;
vector<int> vec;
void dfs(int i, int c) {
    if (c == N) {
        int j = 0;
        for (int i = 0; i < N/10; ++ i) {
            for (int k = 0; k < 10; ++ k) {
                printf("%d%c", vec[j ++], k == 9? '\n': ' ');
            }
        }
        for (int i = 0; i < N % 10; ++ i) {
            printf("%d%c", vec[j ++], i == N%10-1? '\n': ' ');
        }
        return ;
    }

    bool flag = true;
    for (int j = 0; j < c; ++ j) if (dist(i, vec[j]) < D) {
        flag = false;
        break;
    }
    if (flag) {
        vec.emplace_back(i);
        dfs(i + 1, c + 1);
        vec.pop_back();
    } else {
        dfs(i + 1, c);
    }
}


#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("hamming.out", "w", stdout);
    freopen("hamming.in", "r", stdin);
#endif
    scanf("%d %d %d", &N, &B, &D);
    dfs(0, 0);

    return 0;
}
