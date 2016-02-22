/*
ID: sudawei1
PROG: friday
LANG: C++11
*/

#include <cstdio>

#define __DEBUG

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isleap(int n) {
    return n % 400 == 0 || (n % 4 == 0 && n % 100 != 0);
}

int main(void) {
#ifdef __DEBUG
    freopen("friday.in", "r", stdin);
    freopen("friday.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    int day[7] = {0};
    int sum = 0;
    for (int i = 1900; i < 1900 + n; ++ i) {
        if (isleap(i)) month[2] = 29;
        for (int j = 1; j <= 12; ++ j) {
            ++ day[(sum + 13) % 7];
            sum += month[j];
        }
        month[2] = 28;
    }
    printf("%d %d", day[6], day[0]);
    for (int i = 1; i <= 5; ++ i) {
        printf(" %d", day[i]);
    }
    printf("\n");

    return 0;
}
