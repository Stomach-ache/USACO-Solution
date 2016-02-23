/*
ID: sudawei1
PROG: job
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

using pii = pair<int, int>;
int t1[30], t2[30];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("job.out", "w", stdout);
    freopen("job.in", "r", stdin);
#endif
    int N, M1, M2;
    scanf("%d %d %d", &N, &M1, &M2);
    priority_queue<pii, vector<pii>, greater<pii>> pq, pq2;
    for (int i = 0; i < M1; ++ i) {
        scanf("%d", t1 + i);
        pq.emplace(pii(t1[i], i));
    }
    for (int i = 0; i < M2; ++ i) {
        scanf("%d", t2 + i);
        pq2.emplace(pii(t2[i], i));
    }

    vector<int> t;
    for (int i = 0; i < N; ++ i) {
        pii p = pq.top(); pq.pop();
        pq.emplace(pii(p.first + t1[p.second], p.second));
        t.emplace_back(p.first);
    }
    int ansA = t[N - 1];
    vector<int> tt;
    for (int i = 0; i < N; ++ i) {
        pii p = pq2.top(); pq2.pop();
        pq2.emplace(pii(p.first + t2[p.second], p.second));
        tt.emplace_back(p.first);
    }
    int ansB = 0;
    for (int i = 0; i < N; ++ i) {
        ansB = max(ansB, t[i] + tt[N - i - 1]);
    }
    printf("%d %d\n", ansA, ansB);

    return 0;
}
