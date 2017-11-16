#include<bits/stdc++.h>
#define INF 500
using namespace std;
int dis[101][101];
int main()
{
    int t,n,r,u,v,s,d,ans=0;
    int x,y,z,i,j,k;
    scanf("%d",&t);
    for(x=1;x<=t;x++){
        ans = 0;
        scanf("%d",&n);
        for(i=0;i<=n;i++){
            for(j=0;j<=n;j++){
                dis[i][j] = INF;
                dis[j][i] = INF;
            }
        }
        scanf("%d",&r);
        for(y=1;y<=r;y++){
            scanf("%d%d",&u,&v);
            dis[u][v] = 1;
            dis[v][u] = 1;
            dis[u][u] = 0;
            dis[v][v] = 0;
        }
        scanf("%d%d",&s,&d);
        for(k=0;k<n;k++){
            for(i=0;i<n;i++){
                for(j=0;j<n;j++){
                    if(dis[i][j]>dis[i][k]+dis[k][j]){
                        dis[i][j]=dis[i][k]+dis[k][j];
                        dis[j][i]=dis[i][k]+dis[k][j];
                    }
                }
            }
        }
        for(i=0;i<n;i++){
             ans = max(ans,dis[i][s]+dis[i][d]);
        }
        if(r==0)ans = 0;
        printf("Case %d: %d\n",x,ans);
    }
return 0;
}
