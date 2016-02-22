/*
ID: sudawei1
PROG: msquare
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
#include <unordered_set>
using namespace std;

struct State {
    int a[8];
    string ans;
};

int get_id(State a) {
    int h = 0;
    for (int i = 0; i < 8; ++ i) h = h * 10 + a.a[i];
    return h;
}

void funcA(State &a) {
    for (int i = 0; i < 4; ++ i) swap(a.a[i], a.a[7-i]);
    a.ans.push_back('A');
}

void funcB(State &a) {
    int i = a.a[3], j = a.a[4];
    for (int i = 2; i >= 0; -- i) {
        a.a[i+1] = a.a[i];
    }
    for (int i = 4; i < 7; ++ i) {
        a.a[i] = a.a[i + 1];
    }
    a.a[0] = i, a.a[7] = j;
    a.ans.push_back('B');
}

void funcC(State &a) {
    int i = a.a[1];
    a.a[1] = a.a[6]; a.a[6] = a.a[5];
    a.a[5] = a.a[2], a.a[2] = i;
    a.ans.push_back('C');
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("msquare.out", "w", stdout);
    freopen("msquare.in", "r", stdin);
#endif
    unordered_set<int> vis;
    State a;
    for (int i = 0; i < 8; ++ i) scanf("%d", &a.a[i]);
    queue<State> que;
    que.emplace(State{1,2,3,4,5,6,7,8});
    int ret = get_id(a);
    State cur, newS;
    while (!que.empty()) {
        cur = que.front(); que.pop();
        int id = get_id(cur);
        vis.insert(id);
        if (id == ret) {
            int n = cur.ans.length();
            printf("%d\n", n);
            for (int i = 1; i <= n; ++ i) {
                printf("%c", cur.ans[i - 1]);
                if (i % 60 == 0) printf("\n");
            }
            if (n % 60 != 0) printf("\n");
            if (n == 0) printf("\n");
            return 0;
        }
        newS = cur;
        funcA(newS);
        if (vis.find(get_id(newS)) == end(vis)) {
            que.emplace(newS);
        }
        newS = cur;
        funcB(newS);
        if (vis.find(get_id(newS)) == end(vis)) {
            que.emplace(newS);
        }
        newS = cur;
        funcC(newS);
        if (vis.find(get_id(newS)) == end(vis)) {
            que.emplace(newS);
        }
    }

    return 0;
}
