#include<bits/stdc++.h>
#define ll long long int
#define MOD 10056
using namespace std;

ll dp[1001][1001], ans[1001];

ll ncr(int n, int r)
{
    if(r==1)
        return n;
    if(n==r)
        return 1;
    if(dp[n][r]!=-1)
        return dp[n][r];
    return dp[n][r] = (ncr(n-1, r-1)%MOD + ncr(n-1, r)%MOD)%MOD;
}
ll calc(int n)
{
    if(n==0)
        return 1;
    if(ans[n]!=-1)
        return ans[n];
    ll cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += (ncr(n, i)*calc(n-i))%MOD;
        cnt %= MOD;
    }
    return ans[n] = cnt;
}

int main()
{
    int i, j, k, n, t;
    scanf("%d", &t);
    memset(dp, -1, sizeof(dp));
    memset(ans, -1, sizeof(ans));
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        printf("Case %d: %lld\n", i, calc(n));
    }
    return 0;
}
