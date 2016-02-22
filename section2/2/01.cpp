/*
ID: sudawei1
PROG: preface
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

char a[] = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
int c[7];

void make(int n) {
    int i = 0;
    while (n > 0) {
        int x = n % 10;
        n /= 10;
        if (x > 0) {
            if (x <= 3) c[0 + i] += x;
            else {
                if (x >= 4 && x <= 8) ++ c[1 + i];
                if (x == 4 ||x == 6 || x == 9) ++ c[0 + i];
                if (x == 7) c[0 + i] += 2;
                if (x == 8) c[0 + i] += 3;
                if (x == 9) ++ c[2 + i];
            }
        }
        i += 2;
    }
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("preface.out", "w", stdout);
    freopen("preface.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i) {
        make(i);
    }
    for (int i = 0; i < 7; ++ i) if (c[i]) {
        printf("%c %d\n", a[i], c[i]);
    }

    return 0;
}
