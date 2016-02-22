/*
ID: sudawei1
PROG: transform
LANG: C++11
*/

#include <cstdio>
#include <algorithm>

#define __DEBUG

char s[12][12], t[12][12], a[12][12];
int n;

void rotate() {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            a[i][j] = s[n - j - 1][i];
        }
    }
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            s[i][j] = a[i][j];
        }
    }
}

void reflect() {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n/2; ++ j) {
            std::swap(s[i][j], s[i][n - j - 1]);
        }
    }
}

bool check() {
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < n; ++ j) {
            if (s[i][j] != t[i][j]) return false;
        }
    }
    return true;
}

void print() {
    for (int i = 0; i < n; ++ i) printf("%s\n", s[i]);
}

int main(void) {
#ifdef __DEBUG
    freopen("transform.in", "r", stdin);
    freopen("transform.out", "w", stdout);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%s", s[i]);
    }
    for (int i = 0; i < n; ++ i) {
        scanf("%s", t[i]);
    }

    int ans = 0;
    for (int i = 1; i <= 7; ++ i) {
        if (i <= 3) {
            rotate();
            if (check()) {
                ans = i;
                break;
            }
        } else if (i == 4) {
            rotate();
            reflect();
            if (check()) {
                ans = i;
                break;
            }
        } else if (i == 5) {
            for (int j = 1; j <= 3; ++ j) {
                rotate();
                if (check()) {
                    ans = i;
                    break;
                }
            }
            if (ans) break;
            rotate();
        } else if (i == 6) {
            reflect();
            if (check()) {
                ans = i;
                break;
            }
        } else {
            ans = i;
        }
    }
    printf("%d\n", ans);

    return 0;
}
