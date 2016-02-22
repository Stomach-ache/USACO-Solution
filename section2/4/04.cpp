/*
ID: sudawei1
PROG: comehome
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

int d[60][60];
bool has[60];

int get_id(char ch) {
    if (isupper(ch)) return ch - 'A';
    else return ch - 'a' + 26;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("comehome.out", "w", stdout);
    freopen("comehome.in", "r", stdin);
#endif
    int n;
    scanf("%d", &n);
    memset(d, 0x3f, sizeof(d));
    for (int i = 0; i < n; ++ i) {
        getchar();
        char u, v;
        int w;
        scanf("%c %c %d", &u, &v, &w);
        //printf("%c %c %d\n", u, v, w);
        d[get_id(v)][get_id(u)] = d[get_id(u)][get_id(v)] = min(d[get_id(u)][get_id(v)], w);
        if (isupper(u)) has[get_id(u)] = true;
        if (isupper(v)) has[get_id(v)] = true;
    }
    for (int i = 0; i < 55; ++ i) d[i][i] = 0;
    for (int k = 0; k < 55; ++ k) {
        for (int i = 0; i < 55; ++ i) {
            for (int j = 0; j < 55; ++ j) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int ans = 0x3f3f3f3f, id = -1;
    for (int i = 0; i < 55; ++ i) if (has[i] && i != 25) {
        if (ans > d[i][get_id('Z')]) {
            ans = d[i][get_id('Z')];
            id = i;
        }
    }
    printf("%c %d\n", id<26? id+'A': id-26+'a', ans);

    return 0;
}
