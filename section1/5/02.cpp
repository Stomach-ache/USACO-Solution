/*
ID: sudawei1
PROG: pprime
LANG: C++11
*/
#include <cstdio>
#include <cmath>

int digit[12], len = 0;
bool isPalindrome(int n) {
    len = 0;
    while (n > 0) {
        digit[++ len] = n % 10;
        n /= 10;
    }
    for (int i = 1; i <= len/2; ++ i) {
        if (digit[i] != digit[len-i+1]) return false;
    }
    return true;
}

bool isPrime(int n) {
    for (int i = 2; i*i <= n; ++ i) {
        if (n % i == 0) return false;
    }
    return true;
}

#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("pprime.out", "w", stdout);
    freopen("pprime.in", "r", stdin);
#endif
    int a, b;
    scanf("%d %d", &a, &b);
    if (a % 2 == 0) ++ a;
    for (int i = a; i <= b && i < 1000000; i += 2) {
        if (isPalindrome(i) && isPrime(i)) {
            printf("%d\n", i);
        }
    }

    // generate seven digits palindrome.
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; ++ d2) {
            for (int d3 = 0; d3 <= 9; ++ d3) {
                for (int d4 = 0; d4 <= 9; ++ d4) {
                    int n = d1*1000000 + d2*100000 + d3*10000 + d4*1000 + d3*100 + d2*10 + d1;
                    if (n >= a && n <= b && isPrime(n)) {
                        printf("%d\n", n);
                    }
                }
            }
        }
    }

    // generate eight digits palindrome.
    for (int d1 = 1; d1 <= 9; d1 += 2) {
        for (int d2 = 0; d2 <= 9; ++ d2) {
            for (int d3 = 0; d3 <= 9; ++ d3) {
                for (int d4 = 0; d4 <= 9; ++ d4) {
                    int n = d1*10000000 + d2*1000000 + d3*100000 + d4*10000 + d4*1000 + d3*100 + d2*10 + d1;
                    if (n >= a && n <= b && isPrime(n)) {
                        printf("%d\n", n);
                    }
                }
            }
        }
    }

    return 0;
}
