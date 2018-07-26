#include<bits/stdc++.h>
using namespace std;


vector<int> adj[101];
int color[101][3];
void dfs(int u, int col)
{
    if(col!=0)
        color[u][col] = 1;
    int nextcol = 1;
    if(col==1)
        nextcol = 2;
    for(int i=0;i<adj[u].size();i++){
        if(color[adj[u][i]][nextcol]==0)
            dfs(adj[u][i], nextcol);
    }

}
int main()
{
    int i, j, k, t, n, m, u, v, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d", &n, &m);
        memset(color, 0, sizeof(color));
        for(j=1;j<=n;j++)adj[j].clear();
        ans = 0;
        for(j=1;j<=m;j++){
            scanf("%d%d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1, 0);
        for(j=1;j<=n;j++)
            if(color[j][2])
                ans++;
        printf("Case %d: %d\n", i, ans);

    }

    return 0;
}
