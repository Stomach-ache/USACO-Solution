/*
ID: sudawei1
PROG: buylow
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
using namespace std;


const int maxn = 100;

struct BigInteger {
    int len, s[maxn + 5];

    //初始化与赋值
    BigInteger() {
        memset(s,0,sizeof(s));
        len = 1;//因为0的存在
    }

    BigInteger operator = (const char *num) {
        memset(s,0,sizeof(s));
        len = strlen(num);
        for(int i = 0; i < len; ++i)
            s[i] = num[len - i - 1] - '0';//倒序转化成数字
        return *this;
    }

    BigInteger operator = (int num) {
        memset(s,0,sizeof(s));
        char ts[maxn + 5];
        sprintf(ts,"%d",num);
        *this = ts;
        return *this;
    }

    BigInteger(int num) {
        *this = num;
    }

    BigInteger(const char *num) {
        *this = num;
    }
    //BigInteger的str型转化
    string str() const{
        string res = "";
        for(int i = len - 1; i >= 0; --i)
            res +=  (char)(s[i] + '0');
        if(res == "")
            res = "0";
        return res;
    }
    //运算符重载
    //高精度加
    BigInteger operator + (const BigInteger & b) const {
        BigInteger sum;
        sum.len = 0;
        for(int i = 0, g = 0; g || i < max(len,b.len); ++i){
            int x = g;//x:暂存和,g:进位
            if(i < len) x += s[i];
            if(i < b.len) x += b.s[i];
            sum.s[sum.len++] = x % 10;
            g = x / 10;
        }
        return sum;
    }

    //高精度减
    BigInteger operator - (const BigInteger & b) const {
        BigInteger dif;
        int maxlen = (len > b.len) ? len : b.len;
        for(int i = 0; i < maxlen; ++i){
            dif.s[i] += s[i] - b.s[i];
            if(dif.s[i] < 0){
                dif.s[i] += 10;
                --dif.s[i + 1];
            }
        }
        dif.len = maxlen;
        while(dif.s[dif.len - 1] == 0 && dif.len > 1)
            --dif.len;
        return dif;
    }

    //高精度乘,实际上加和乘对进位的处理有所不同
    BigInteger operator * (const BigInteger &b) const {
        BigInteger pro;
        pro.len = 0;
        for(int i = 0; i < len; ++i){
            for(int j = 0; j < b.len; ++j){
                pro.s[i + j] += (s[i] * b.s[j]);
                pro.s[i + j + 1] += pro.s[i + j] / 10;
                pro.s[i + j] %= 10;
            }
        }
        pro.len = len + b.len + 1;//这里注意pro.len初始值可能是题目数字范围两倍
        while(pro.s[pro.len - 1] == 0 && pro.len > 1)
            --pro.len;//最后一位不管是不是0都不能让len - 1
        if(pro.s[pro.len])
            ++pro.len;//这句有待商讨
        return pro;
    }

    //高精度乘以低精度
    BigInteger operator * (const int num) const {
        int c = 0,t;
        BigInteger pro;
        for(int i = 0; i < len; ++i) {
            t = s[i] * num + c;
            pro.s[i] = t % 10;
            c = t / 10;
        }
        pro.len = len;
        while(c != 0) {
            pro.s[pro.len++] = c % 10;
            c /= 10;
        }
        return pro;
    }

    //高精度除,模拟连减
    BigInteger operator / (const BigInteger & b) const {
        BigInteger quo,f;
        for(int i = len - 1; i >= 0; --i){
            f = f * 10;
            f.s[0] = s[i];
            while(f >= b){
                f = f - b;
                ++quo.s[i];
            }
        }
        quo.len = len;
        while(quo.s[quo.len - 1] == 0 && quo.len > 1)
            --quo.len;
        return quo;
    }

    //高精度取模
    BigInteger operator % (const BigInteger & b) const {
        BigInteger rem;
        for(int i = len - 1; i >= 0; --i) {
            rem = rem * 10;
            rem.s[0] = s[i];
            while(rem >= b){
                rem = rem - b;
            }
        }
        rem.len = len;
        while(rem.s[rem.len - 1] == 0 && rem.len > 1) {
            --rem.len;
        }
        return rem;
    }
    //比较运算符
    bool operator < (const BigInteger & b) const {
        if(len != b.len) return len < b.len;
        for(int i = len - 1; i >= 0; --i)//从高位开始比较
            if(s[i] != b.s[i])
                return s[i] < b.s[i];
        //如果 本身 == b
        return false;
    }

    bool operator > (const BigInteger &b) const {
        return b < *this;//代表 本身 > b
    }

    bool operator <= (const BigInteger &b) const {
        return !(b < *this);//带表 !(本身 > b)
    }

    bool operator >= (const BigInteger &b) const {
        return !(*this < b);
    }

    bool operator != (const BigInteger &b) const {
        return *this < b || b < *this;
    }

    bool operator == (const BigInteger &b) const {
        return !(*this < b) && !(b < *this);
    }

    friend istream & operator >> (istream & in,BigInteger & x) {
        string ts;
        in >> ts;
        x = ts.c_str();
        return in;
    }
    friend ostream & operator << (ostream & out,const BigInteger & x) {
        out << x.str();
        return out;
    }
};


BigInteger cnt[5010];
int a[5010], dp[5010];
#define __DEBUGE
int main() {
#ifdef __DEBUGE
    freopen("buylow.out", "w", stdout);
    freopen("buylow.in", "r", stdin);
#endif
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; ++ i) {
        scanf("%d", a + i);
    }
    for (int i = N; i >= 1; -- i) {
        int Max = 0;
        for (int j = i + 1; j <= N; ++ j) if (a[j] < a[i]) {
            if (Max < dp[j]) {
                Max = dp[j];
            }
        }
        dp[i] = Max + 1;
        if (Max == 0) cnt[i] = 1;
        set<int> vis;
        for (int j = i + 1; j <= N; ++ j) if (dp[j] == Max && a[j] < a[i]) {
            if (vis.find(a[j]) == end(vis)) {
                vis.insert(a[j]);
                cnt[i] = cnt[i] + cnt[j];
            }
        }
    }

    int len = 0, id = 0;
    for (int i = 1; i <= N; ++ i) {
        if (len < dp[i]) {
            len = dp[i];
            id = i;
        }
    }
    printf("%d ", len);
    BigInteger ans = 0;
    set<int> vis;
    for (int j = 1; j <= N; ++ j) if (dp[j] == dp[id]) {
        if (vis.find(a[j]) == end(vis)) {
            vis.insert(a[j]);
            ans = ans + cnt[j];
        }
    }
    string res = "";
    for(int i = ans.len - 1; i >= 0; --i)
        res +=  (ans.s[i] + '0');
    if(res == "")
        res = "0";
    printf("%s\n", res.c_str());


    return 0;
}
