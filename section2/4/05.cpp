/*
ID: sudawei1
PROG: fracdec
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
    freopen("fracdec.out", "w", stdout);
    freopen("fracdec.in", "r", stdin);
#endif
    int N, D;
    scanf("%d %d", &N, &D);
    int x = N / D;
    printf("%d.", x);
    int cnt = 1;
    if (x == 0) ++ cnt;
    while (x > 0) {
        ++ cnt;
        x /= 10;
    }
    N %= D;
    if (N == 0) {
        printf("0\n");
    } else {
        map<int, int> cc;
        vector<char> vec;
        int i = 0;
        while (N > 0) {
            if (cc.find(N) != cc.end()) {
                vec.insert(begin(vec) + cc[N], '(');
                vec.push_back(')');
                break;
            }
            cc[N] = i ++;
            int x = N * 10 / D;
            vec.push_back('0' + x);
            N = N * 10 % D;
        }
        for (int i = 0; i < vec.size(); ++ i) {
            if (cnt % 76 == 0) printf("\n");
            printf("%c", vec[i]);
            ++ cnt;
        }
        printf("\n");
    }

    return 0;
}
