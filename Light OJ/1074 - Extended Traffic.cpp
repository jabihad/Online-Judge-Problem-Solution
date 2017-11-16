#include<bits/stdc++.h>
#define INF 1000000
using namespace std;

struct edge
{
    int u, v, w;
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
};
vector<edge> adj;
int dis[210], n, ara[210];
void Bellmanford()
{
    int i, step;
    for(i=1; i<=n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for(step=1; step<=n; step++)
    {
        int up = 0;
        for(i=0; i<adj.size(); i++)
        {
            if(dis[adj[i].u] + adj[i].w < dis[adj[i].v])
            {
                dis[adj[i].v] = dis[adj[i].u] + adj[i].w;
                up = 1;
            }
        }
        if(up==0)break;
    }
}
int main()
{
    int i, j, k, l, m, t, u, v, q;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        adj.clear();
        scanf("%d",&n);
        for(j=1; j<=n; j++)
            scanf("%d",&ara[j]);
        scanf("%d",&m);
        for(j=1; j<=m; j++)
        {
            scanf("%d%d",&u,&v);
            adj.push_back(edge(u, v, (ara[v]-ara[u])*(ara[v]-ara[u])*(ara[v]-ara[u])));
        }
        Bellmanford();
        scanf("%d",&q);
        printf("Case %d:\n",i);
        for(j=1; j<=q; j++)
        {
            scanf("%d",&v);
            if(dis[v]<3 || dis[v]>100000)
                printf("?\n");
            else
                printf("%d\n",dis[v]);
        }
    }

    return 0;
}

