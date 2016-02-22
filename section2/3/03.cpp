/*
ID: sudawei1
PROG: zerosum
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
#include <map>
#include <unordered_set>
using namespace std;

vector<string> res;
vector<int> ans;
int n;

int calc() {
    int n = ans.size();
    int res = 0;
    for (int i = 0; i < n; ++ i) {
        int j = i, k = j;
        if (ans[j] < 0) {
            ++ k;
        }
        int tmp = 0;
        while (k < n && ans[k] >= 0) {
            if (ans[k] > 0)
                tmp = tmp * 10 + ans[k];
            ++ k;
        }
        if (j == 0 || ans[j] == -1) res += tmp;
        else if (ans[j] == -2) res -= tmp;
    }
    return res;
}

// -1: +, -2: -, 0: ' ', -3: none
void dfs(int i) {
    if (i > n) {
        if (calc() == 0) {
            string tmp = "";
            for (int i = 0; i < ans.size(); ++ i) {
                if (ans[i] == -1) tmp.push_back('+');
                else if (ans[i] == -2) tmp.push_back('-');
                else if (ans[i] == 0) tmp.push_back(' ');
                else tmp.push_back('0' + ans[i]);
            }
            res.emplace_back(tmp);
        }
        return ;
    }

    ans.push_back(-1);
    ans.push_back(i);
    dfs(i + 1);
    ans.pop_back();
    ans.pop_back();

    ans.push_back(-2);
    ans.push_back(i);
    dfs(i + 1);
    ans.pop_back();
    ans.pop_back();

    ans.push_back(0);
    ans.push_back(i);
    dfs(i + 1);
    ans.pop_back();
    ans.pop_back();
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("zerosum.out", "w", stdout);
    freopen("zerosum.in", "r", stdin);
#endif
    scanf("%d", &n);
    ans.push_back(1);
    dfs(2);
    sort(begin(res), end(res));
    for (string s: res) printf("%s\n", s.c_str());

    return 0;
}
