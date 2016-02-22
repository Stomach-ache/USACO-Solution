/*
ID: sudawei1
PROG: milk2
LANG: C++11
*/

#include <cstdio>
#include <vector>
#include <algorithm>
#include <climits>

#define __DEBUG

typedef std::pair<int, int> pii;
int main(void) {
#ifdef __DEBUG
    freopen("milk2.in", "r", stdin);
    freopen("milk2.out", "w", stdout);
#endif
    int n;
    scanf("%d", &n);
    std::vector<pii> vec;
    for (int i = 0; i < n; ++ i) {
        int a, b;
        scanf("%d %d", &a, &b);
        vec.emplace_back(pii(a, b));
    }
    std::sort(begin(vec), end(vec));
    int i = 0, l1 = 0, l2 = 0;
    while (i < n) {
        int l = vec[i].first, r = vec[i].second;
        int j = i, mr = r;
        while (j < n && vec[j].first <= mr) {
            mr = std::max(mr, vec[j].second);
            ++ j;
        }
        l1 = std::max(l1, mr - l);
        if (j < n) l2 = std::max(l2, vec[j].first - mr);
        i = j;
    }
    printf("%d %d\n", l1, l2);

    return 0;
}
