#include<bits/stdc++.h>
using namespace std;
struct node
{
    int v,w;
    node(){}
    node(int _v,int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<node> adj[30010];
int vis[30010],dis[30010];
void dfs(int at)
{
    vis[at] = 1;
    for(int i=0;i<adj[at].size();i++){
        if(vis[adj[at][i].v]==0){
        dis[adj[at][i].v] = dis[at]+adj[at][i].w;
        dfs(adj[at][i].v);
        }
    }
}
int main()
{
    int i,j,t,n,a,b,c,nd,mx=0,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<=n;j++){
            vis[j] = dis[j]= 0;
            adj[j].clear();
        }
        for(j=1;j<=n-1;j++){
            scanf("%d%d%d",&a,&b,&c);
            adj[a].push_back(node(b,c));
            adj[b].push_back(node(a,c));
        }
        dfs(0);
        mx = 0;
        for(j=0;j<n;j++){
            if(dis[j]>mx){
                nd = j;
                mx = dis[j];
            }
            vis[j] = dis[j] = 0;
        }
        dfs(nd);
        r = 0;
        for(j=0;j<n;j++){
            if(dis[j]>r)
                r = dis[j];
        }
        printf("Case %d: %d\n",i,r);
    }
return 0;
}
