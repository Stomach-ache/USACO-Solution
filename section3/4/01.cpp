/*
ID: sudawei1
PROG: heritage
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

string dfs(const string &in_order, const string &pre_order) {
    if (in_order.length() <= 1) return in_order;
    string in_lft, in_rgt, pre_lft, pre_rgt, ans;
    bool flag = true;
    for (char ch: in_order) {
        if (ch == pre_order[0]) {
            flag = false;
            continue;
        }
        if (flag) in_lft.push_back(ch);
        else in_rgt.push_back(ch);
    }
    for (int i = 1; i < pre_order.length(); ++ i) {
        if (pre_lft.length() < in_lft.length())
            pre_lft.push_back(pre_order[i]);
        else
            pre_rgt.push_back(pre_order[i]);
    }

    return dfs(in_lft, pre_lft) + dfs(in_rgt, pre_rgt) + pre_order[0];
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("heritage.out", "w", stdout);
    freopen("heritage.in", "r", stdin);
#endif
    char s[30];
    scanf("%s", s);
    string in_order(s);
    scanf("%s", s);
    string pre_order(s);

    printf("%s\n", dfs(in_order, pre_order).c_str());

    return 0;
}
