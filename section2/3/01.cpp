/*
ID: sudawei1
PROG: prefix
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

bool dp[200010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    ofstream fout("prefix.out");
    ifstream fin("prefix.in");
#endif
    vector<string> sub;
    string s;
    while (fin >> s && s[0] != '.') sub.emplace_back(s);
    string t = "0";
    while (fin >> s) t += s;

    int n = sub.size(), m = t.length();
    dp[0] = true;
    for (int i = 1; i < m; ++ i) if (dp[i - 1]) {
        for (int j = 0; j < n; ++ j) if (i + sub[j].length() <= m) {
            if (sub[j] == t.substr(i, sub[j].length())) {
                dp[i + sub[j].length() - 1] = true;
            }
        }
    }
    for (int i = m - 1; i >= 0; -- i) if (dp[i]) {
        fout << i << endl;
        break;
    }

    return 0;
}
