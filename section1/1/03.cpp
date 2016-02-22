/*
ID: sudawei1
PROG: gift1
LANG: C++11
*/

#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;

#define __DEBUG

int main(void) {
#ifdef __DEBUG
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    char name[12][20];
    unordered_map<string, int> rname;
    int give[12] = {0}, recieve[12] = {0};
    for (int i = 0; i < n; ++ i) {
        scanf("%s", name[i]);
        rname[name[i]] = i;
    }
    for (int i = 0; i < n; ++ i) {
        char s[12];
        scanf("%s", s);
        int g, num;
        scanf("%d %d", &g, &num);
        if (g && num) give[rname[s]] = g - g % num;
        for (int j = 0; j < num; ++ j) {
            char t[12];
            scanf("%s", t);
            recieve[rname[t]] += g / num;
        }
    }
    for (int i = 0; i < n; ++ i) {
        printf("%s %d\n", name[i], recieve[i] - give[i]);
    }

    return 0;
}
