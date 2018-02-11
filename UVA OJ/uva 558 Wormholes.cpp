#include<bits/stdc++.h>
#define INF 1000010
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
int n, dis[1010], flag;

void Bellmanford()
{
    int i, j;
    for(i=0; i<=n; i++)
        dis[i] = INF;
    dis[0] = 0;
    for(i=1; i<=n; i++)
    {
        int up = 1;
        for(j=0; j<adj.size(); j++)
        {
            if(dis[adj[j].u] + adj[j].w < dis[adj[j].v])
            {
                dis[adj[j].v] = dis[adj[j].u] + adj[j].w;
                up = 0;
            }
        }
        if(up)break;
    }
    flag = 0;
    for(i=1; i<=n; i++)
    {
        for(j=0; j<adj.size(); j++)
        {
            if(dis[adj[j].u] + adj[j].w < dis[adj[j].v])
            {
                dis[adj[j].v] = dis[adj[j].u] + adj[j].w;
                flag = 1;
            }
        }
    }
}
int main()
{
    int i, j, t, m, u, v, w;
    scanf("%d",&t);
    while(t--)
    {
        adj.clear();
        scanf("%d%d",&n,&m);
        for(i=1; i<=m; i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            adj.push_back(edge(u, v, w));
        }
        Bellmanford();
        if(flag)
            cout<<"possible\n";
        else
            cout<<"not possible\n";
    }
    return 0;
}
