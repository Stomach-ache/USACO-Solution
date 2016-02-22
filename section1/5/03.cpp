/*
ID: sudawei1
PROG: sprime
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
#include <queue>
#include <cmath>
#include <map>
#include <unordered_set>
using namespace std;

#define __DEBUGE
using pii = pair<int, int>;

bool isPrime(int n) {
    for (int i = 2; i*i <= n; ++ i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
#ifdef __DEBUGE
    freopen("sprime.out", "w", stdout);
    freopen("sprime.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    queue<pii> que;
    que.emplace(pii(2, 1));
    que.emplace(pii(3, 1));
    que.emplace(pii(5, 1));
    que.emplace(pii(7, 1));
    while (!que.empty()) {
        int num = que.front().first, len = que.front().second;
        que.pop();
        if (len == n) {
            printf("%d\n", num);
        } else {
            for (int i = 1; i <= 9; i += 2) {
                int x = num * 10 + i;
                if (isPrime(x)) que.emplace(pii(x, len + 1));
            }
        }
    }

    return 0;
}
