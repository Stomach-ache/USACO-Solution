/*
ID: sudawei1
PROG: namenum
LANG: C++11
*/

#include <map>
#include <cstdio>
#include <cstring>

#define __DEBUG

char s[5010][15];
std::map<char, int> id = {
    {'A', 2}, {'B', 2}, {'C', 2}, {'D', 3}, {'E', 3}, {'F', 3},
    {'G', 4}, {'H', 4}, {'I', 4}, {'J', 5}, {'K', 5}, {'L', 5},
    {'M', 6}, {'N', 6}, {'O', 6}, {'P', 7}, {'R', 7}, {'S', 7},
    {'T', 8}, {'U', 8}, {'V', 8}, {'W', 9}, {'X', 9}, {'Y', 9}
};
int main(void) {
    freopen("dict.txt", "r", stdin);
    int cc = 0;
    while (~scanf("%s", s[cc])) cc ++;
#ifdef __DEBUG
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
#endif
    long long n;
    scanf("%lld", &n);
    bool flag = false;
    for (int i = 0; i < cc; ++ i) {
        long long num = 0;
        for (int j = 0; s[i][j]; ++ j) {
            num = num * 10 + id[s[i][j]];
        }
        if (num == n) {
            printf("%s\n", s[i]);
            flag = true;
        }
    }
    if (!flag) printf("NONE\n");

    return 0;
}
