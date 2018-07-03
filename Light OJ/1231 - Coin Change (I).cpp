#include<bits/stdc++.h>
#define MOD 100000007
using namespace std;

int dp[55][2000], a[55], c[55], n, k;

int call(int i, int amount)
{
    if(i>n){
        if(amount==k)
            return 1;
        return 0;
    }
    if(amount>k)
        return 0;
    if(amount==k)
        return 1;
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    int res=0;
    for(int j=1;j<=c[i];j++){
        if(amount+a[i]*j<=k)
            res += call(i+1, amount+a[i]*j)%MOD;
        else break;
    }
    res += call(i+1, amount)%MOD;

    return dp[i][amount] = res%MOD;
}

int main()
{
    int i, j, t, res;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        memset(dp, -1, sizeof(dp));

        scanf("%d%d", &n, &k);
        for(j=1;j<=n;j++)
            scanf("%d", &a[j]);
        for(j=1;j<=n;j++)
            scanf("%d", &c[j]);

        res = call(1, 0);
        printf("Case %d: %d\n", i, res);
    }

return 0;
}
