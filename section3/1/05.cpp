/*
ID: sudawei1
PROG: stamps
LANG: C++11
*/
/*
#include <stdio.h>
#define MAXINT 10000000
#define maxn 2000010
int f[maxn];
int v[100];
int n,k;
int main()
{
    freopen("stamps.in","r",stdin);
    freopen("stamps.out","w",stdout);
    
    
    
    return 0;
}

*/

#include <cstdio>

#define __DEBUGE
//int a[55];
//int dp[2][2000010];

#define MAXINT 10000000
#define maxn 2000010
int f[maxn];
int v[100];
int main() {
#ifdef __DEBUGE
    //ifstream fin("stamps.in");
    //ofstream fout("stamps.out");
    freopen("stamps.out", "w", stdout);
    freopen("stamps.in", "r", stdin);
#endif

int k, n;
scanf("%d%d",&k,&n);
    for (int i=1;i<=n;++i) scanf("%d",&v[i]);
    int i=1,min;
    while (1)
    {
          min=MAXINT;
          for (int j=1;j<=n;++j)
              if ((i-v[j]>=0)&&(f[i-v[j]]+1<min))
                 min=f[i-v[j]]+1;
          if (min>k) break;
          f[i]=min;
          ++i;
    }
    
    printf("%d\n",i-1);

/*
    int N, K, maxn = 0;
    //fin >> K >> N;
    scanf("%d %d", &K, &N);
    for (int i = 0; i < N; ++ i) {
        //fin >> a[i];
        scanf("%d", a + i);
        if (a[i] > maxn) maxn = a[i];
    }
    maxn *= K;
    dp[0][0] = true;
    int cur = 1;
    for (int i = 1; i <= K; ++ i) {
        for (int j = 0; j < N; ++ j) {
            for (int k = 0; k < maxn; ++ k) {
                if (a[j]+k <= maxn && dp[cur^1][k]) dp[cur][k+a[j]] = true;
            }
        }
        for (int k = 0; k <= maxn; ++ k) {
            dp[cur][k] |= dp[cur^1][k];
			dp[cur^1][k] = false;
        }
        cur ^= 1;
    }

    for (int i = 1; i <= maxn+1; ++ i) if (!dp[cur^1][i]) {
        printf("%d\n", i - 1);
        break;
    }
*/
    return 0;
}
