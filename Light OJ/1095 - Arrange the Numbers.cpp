#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

ll dp[1005][1005], fact[1005];
ll ncr(int m, int k)
{
    if(k==1)
        return m;
    if(m==k)
        return 1;
    if(dp[m][k]!=-1)
        return dp[m][k];

    return dp[m][k] = (ncr(m-1, k-1) + ncr(m-1, k)) % MOD;
}

int main()
{
    int i, j, t;
    ll n, m, k, p1, p2;
    fact[0] = 1;
    for(i=1;i<=1002;i++) fact[i] = (fact[i-1]*i)%MOD;
    memset(dp, -1, sizeof(dp));
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld", &n, &m, &k);
        p1 = ncr(m, k);
        p2 = fact[n-k];
        for(j=1;j<=m-k;j++){
            if(j%2==1)
                p2 -= (ncr(m-k, j)*fact[n-k-j])%MOD;
            else
                p2 += (ncr(m-k, j)*fact[n-k-j])%MOD;
            p2 = (p2 + MOD)%MOD;
        }
        printf("Case %d: %lld\n", i, (p1*p2)%MOD);
    }

    return 0;
}
