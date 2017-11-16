#include<bits/stdc++.h>
using namespace std;

string ans[105][105];
int dp[105][105], m, n;
char x[105], y[105];

void lcs()
{
    int i, j;
    for(i=0; i<=m; i++)
        dp[i][0] = 0;
    for(j=0; j<=n; j++)
        dp[0][j] = 0;

    for(i=1; i<=m; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                dp[i][j] = dp[i-1][j-1]+1;
                ans[i][j] = ans[i-1][j-1] + x[i-1];
            }
            else if(dp[i-1][j]>dp[i][j-1])
            {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = ans[i-1][j];
            }
            else if(dp[i-1][j]<dp[i][j-1])
            {
                dp[i][j] = dp[i][j-1];
                ans[i][j] = ans[i][j-1];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
                ans[i][j] = min(ans[i-1][j],ans[i][j-1]);
            }
        }
    }

}
int main()
{
    int i, j, k, t;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%s%s",x,y);
        m = strlen(x);
        n = strlen(y);
        lcs();
        printf("Case %d: ",i);
        if(dp[m][n]==0)
            printf(":(\n");
        else
            cout<<ans[m][n]<<endl;
    }

    return 0;
}
