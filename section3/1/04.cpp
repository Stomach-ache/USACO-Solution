/*
ID: sudawei1
PROG: contact
LANG: C++11
*/
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <climits>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
using namespace std;

using pii = pair<int, int>;
int val[13][200010];

struct State {
    int cnt, val, len;
    bool operator <(const State &b) const {
        if (cnt != b.cnt) return cnt > b.cnt;
        if (len != b.len) return len < b.len;
        return val < b.val;
    }
};

typedef set<State>::iterator Iter;
Iter Next(Iter x) {
    return ++ x;
}

string toBinary(int x, int len) {
    string ans = "";
    while (x > 0) {
        ans.push_back((x&1) + '0');
        x >>= 1;
    }
    while (ans.length() < len) ans.push_back('0');
    reverse(begin(ans), end(ans));
    return ans;
}

char s[100];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("contact.out", "w", stdout);
    freopen("contact.in", "r", stdin);
#endif
    int A, B, N;
    scanf("%d %d %d", &A, &B, &N);
    string a;
    while (~scanf("%s", s)) a += s;
    int n = a.length();
    for (int i = 1; i <= B; ++ i) {
        for (int j = 0; j+i <= n; ++ j) {
            val[i][j] = (val[i - 1][j]<<1) + (a[i+j-1]=='1'? 1: 0);
        }
    }

    map<pii, int> cc;
    for (int i = A; i <= B; ++ i) {
        for (int j = 0; j+i <= n; ++ j) {
            ++ cc[pii(val[i][j], i)];
        }
    }
    set<State> ans;
    for (auto p: cc) {
        ans.insert(State{p.second, p.first.first, p.first.second});
    }
    int top = 0;
    for (auto it = begin(ans); it != end(ans); ) {
        printf("%d\n", it->cnt);
        printf("%s", toBinary(it->val, it->len).c_str());
        auto it2 = Next(it);
        int c = 1, flag = 1;
        while (it2 != end(ans) && it2->cnt == it->cnt) {
            ++ c;
            if (flag) printf(" ");
            flag = 1;
            printf("%s", toBinary(it2->val, it2->len).c_str());
            if (c % 6 == 0) {
                printf("\n");
                flag = 0;
            }
            ++ it2;
        }
        if (c % 6 != 0) printf("\n");
        it = it2;
        ++ top;
        if (top == N) break;
    }

    return 0;
}
