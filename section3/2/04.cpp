/*
ID: sudawei1
PROG: ratios
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
#include <set>
using namespace std;

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("ratios.out", "w", stdout);
    freopen("ratios.in", "r", stdin);
#endif
    int x, y, z;
    scanf("%d %d %d", &x, &y, &z);
    int a[4], b[4], c[4];
    for (int i = 0; i < 3; ++ i) {
        scanf("%d %d %d", a+i, b+i, c+i);
    }

    int a1, a2, a3, m, sum = 300;
    for (int i = 0; i < 100; ++ i) {
        for (int j = 0; j < 100; ++ j) {
            for (int k = 0; k < 100; ++ k) {
                if (i == 0 && j == 0 && k == 0) continue;
                int s1 = i*a[0]+j*a[1]+k*a[2];
                int s2 = i*b[0]+j*b[1]+k*b[2];
                int s3 = i*c[0]+j*c[1]+k*c[2];
                if (!x && s1) continue;
                if (!y && s2) continue;
                if (!z && s3) continue;
                if ((!x||s1%x==0) && (!y||s2%y==0) && (!z||s3%z==0)) {
                    set<int> s;
                    int t1 = 0, t2 = 0, t3 = 0;
                    if (x) t1 = s1 / x, s.insert(t1);
                    if (y) t2 = s2 / y, s.insert(t2);
                    if (z) t3 = s3 / z, s.insert(t3);
                    if (s.size() == 1 && sum > i+j+k) {
                        sum = i + j + k;
                        a1=i, a2=j, a3=k, m=*s.begin();
                    }
                }
            }
        }
    }
    if (sum == 300) {
        printf("NONE\n");
    } else {
        int s1 = a1*a[0]+a2*a[1]+a3*a[2];
        printf("%d %d %d %d\n", a1, a2, a3, s1/x);
    }

    return 0;
}
