#include<bits/stdc++.h>
using namespace std;

int n, val[17][17], dp[17][1<<16 + 2];
int Set(int N, int pos)
{
    return N = N | (1<<pos);
}
int reset(int N, int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N, int pos)
{
    return (bool) (N & (1<<pos));
}
int call(int pos, int mask)
{
    if(pos>=n)
        return 0;
    if(dp[pos][mask]!=-1)
        return dp[pos][mask];
    int res = -1;
    for(int i=0;i<n;i++){
        if(check(mask, i)==0){
            dp[pos][mask] = max(dp[pos][mask], val[pos][i] + call(pos+1, Set(mask, i)));
        }
    }
    return dp[pos][mask];
}
int main()
{
    int i, j, k, l, t, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        memset(dp, -1, sizeof(dp));
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                scanf("%d", &val[j][k]);
            }
        }
        ans = call(0, 0);
        printf("Case %d: %d\n", i, ans);

    }

    return 0;
}
