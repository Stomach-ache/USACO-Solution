/*
ID: sudawei1
PROG: ride
LANG: C++11
*/

#include <cstdio>
#include <cstring>

int main(void) {
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    char s[10], t[10];
    scanf("%s %s", s, t);
    int a = 1, b = 1;
    for (int i = 0; s[i]; ++ i) a *= s[i] - 'A' + 1;
    for (int i = 0; t[i]; ++ i) b *= t[i] - 'A' + 1;
    if (a % 47 == b % 47) printf("GO\n");
    else printf("STAY\n");

    return 0;
}

