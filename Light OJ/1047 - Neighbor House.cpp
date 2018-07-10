#include<bits/stdc++.h>
using namespace std;

int dp[25][4], col[25][4], n;

int call(int idx, int color)
{
    if(idx>=n)
        return 0;
    if(dp[idx][color]!=-1)
        return dp[idx][color];
    int c1, c2;
    if(color==0){
        c1 = col[idx][1] + call(idx+1, 1);
        c2 = col[idx][2] + call(idx+1, 2);
    }
    else if(color==1){
        c1 = col[idx][0] + call(idx+1, 0);
        c2 = col[idx][2] + call(idx+1, 2);
    }
    else if(color==2){
        c1 = col[idx][0] + call(idx+1, 0);
        c2 = col[idx][1] + call(idx+1, 1);
    }
    return dp[idx][color] = min(c1, c2);
}
int main()
{
    int i, j, t, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        ans = INT_MAX;
        scanf("%d", &n);
        for(j=0;j<n;j++)
            scanf("%d%d%d", &col[j][0], &col[j][1], &col[j][2]);
        for(j=0;j<3;j++){
            memset(dp, -1, sizeof(dp));
            ans = min(ans, col[0][j] + call(1, j));
        }
        printf("Case %d: %d\n", i, ans);

    }

    return 0;
}
