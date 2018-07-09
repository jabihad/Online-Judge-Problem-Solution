#include<bits/stdc++.h>
using namespace std;

int ara[205][205], dp[205][205];
int n;
int call(int r, int c)
{
    if(r<=2*n-1 && c<=2*n-1){
        if(dp[r][c]!=-1)
            return dp[r][c];
        int res=INT_MIN;
        if(ara[r][c]!=0)
            res = max(res, call(r+1, c) + ara[r][c]);
        if(ara[r][c]!=0)
            res = max(res, call(r+1, c+1) + ara[r][c]);
        return dp[r][c] = res;
    }
    else
        return 0;
}
int main()
{
    int i, j, k, l, t, res;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        res = 0;
        memset(dp, -1, sizeof(dp));
        memset(ara, 0, sizeof(ara));
        scanf("%d", &n);
        for(j=1;j<=n;j++){
            for(k=1;k<=j;k++)
                scanf("%d", &ara[j][k]);
        }
        for(j=n+1,l=2;j<=2*n-1;j++,l++){
            for(k=l;k<=n;k++)
                scanf("%d", &ara[j][k]);
        }

        res = call(1, 1);

        printf("Case %d: %d\n", i, res);
    }


    return 0;
}
