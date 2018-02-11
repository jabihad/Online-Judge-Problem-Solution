#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100100];
int vis[10100];
stack<int> s;

void dfs(int source)
{
    int u = source;
    vis[u] = 1;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v = adj[u][i];
        if(vis[v]==0)
            dfs(v);
    }
    s.push(u);
}
int main()
{
    int i, k, n, m, u, v, source, res=0, t;

    scanf("%d", &t);
    for(k=1; k<=t; k++)
    {

        scanf("%d%d",&n, &m);
        for(i=1; i<=n; i++)
        {
            adj[i].clear();
            vis[i] = 0;
        }
        res = 0;

        for(i=1; i<=m; i++)
        {
            scanf("%d%d",&u, &v);
            adj[u].push_back(v);
        }
        for(i=1; i<=n; i++)
            if(vis[i] == 0)
                dfs(i);

        memset(vis, 0, sizeof vis);
        while(!s.empty())
        {
            u = s.top();
            if(vis[u]==0)
            {
                res++;
                dfs(u);
            }
            s.pop();
        }
        printf("Case %d: %d\n", k, res);
    }

    return 0;
}


