#include<bits/stdc++.h>
using namespace std;

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
int w[17][17], n, dp[1<<15 + 2];
int call(int mask)
{
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];
    int mn = 1<<28;
    for(int i=0; i<n; i++)
    {
        if(check(mask, i)==0)
        {
            int price = w[i][i];
            for(int j=0; j<n; j++)
            {
                if(i!=j && check(mask, j)!=0)
                {
                    price += w[i][j];
                }
            }
            int ret = price + call(Set(mask, i));
            mn = min(mn, ret);
        }
    }
    return dp[mask] = mn;
}

int main()
{

    int i, j, k, t;
    scanf("%d", &t);
    for(k=1; k<=t; k++)
    {
        memset(dp, -1, sizeof(dp));
        scanf("%d", &n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                scanf("%d",&w[i][j]);
            }
        }

        int ret=call(0);
        printf("Case %d: %d\n", k, ret);
    }

    return 0;
}
