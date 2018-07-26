#include<bits/stdc++.h>
using namespace std;

struct node
{
    int v, w;
    node(){}
    node(int _v, int _w)
    {
        v = _v;
        w = _w;
    }
};
vector<node> adj[30010];
int vis[30010], dis1[30010], dis2[30010];
void dfs(int u, int chk)
{
    vis[u] = 1;
    for(int i=0;i<adj[u].size();i++){
        if(vis[adj[u][i].v]==0){
            if(chk==1)
                dis1[adj[u][i].v] = dis1[u] + adj[u][i].w;
            else
                dis2[adj[u][i].v] = dis2[u] + adj[u][i].w;
            dfs(adj[u][i].v, chk);
        }
    }
}
int main()
{
    int i, j, k, l, n, t, u, v, w, mx, x, y;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);

        for(j=0;j<=n;j++){
            adj[j].clear();
            vis[j] = dis1[j] = dis2[j] = 0;
        }
        for(j=1;j<n;j++){
            scanf("%d%d%d", &u, &v, &w);
            adj[u].push_back(node(v, w));
            adj[v].push_back(node(u, w));
        }

        dfs(0, 1);
        mx = 0;
        for(j=0;j<n;j++){
            if(dis1[j]>mx){
                mx = dis1[j];
                x = j;
            }
            vis[j] = dis1[j] = 0;
        }

        dfs(x, 1);
        mx = 0;
        for(j=0;j<n;j++){
            if(dis1[j]>mx){
                mx = dis1[j];
                y = j;
            }
            vis[j] = 0;
        }

        dfs(y, 2);

        printf("Case %d:\n", i);
        for(j=0;j<n;j++)
            printf("%d\n", max(dis1[j], dis2[j]));

    }

    return 0;
}
