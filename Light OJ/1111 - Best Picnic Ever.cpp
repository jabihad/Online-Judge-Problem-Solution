#include<bits/stdc++.h>
using namespace std;

vector<int> adj[10100];
int vis[1010][1010], s[110];

void dfs(int source, int node)
{
    int u = source;
    vis[u][node] = 1;
    for(int i=0; i<adj[node].size(); i++)
    {
        int v = adj[node][i];
        if(vis[u][v]==0)
            dfs(u, v);
    }
}
int main()
{
    int i, j, l, n, m, k, t, u, v, res;

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d", &k, &n, &m);

        memset(vis, 0, sizeof vis);
        res = 0;
        for(j=1;j<=n;j++)
            adj[j].clear();

        for(j=1;j<=k;j++)
            scanf("%d", &s[j]);
        for(j=1;j<=m;j++){
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
        }
        for(j=1;j<=k;j++)
            dfs(s[j], s[j]);
        for(j=1;j<=n;j++){
            int cnt = 0;
            for(l=1;l<=k;l++){
                if(vis[s[l]][j]==1)
                    cnt++;
            }
            if(cnt==k)
                res++;

        }
        printf("Case %d: %d\n", i, res);

    }

    return 0;
}
