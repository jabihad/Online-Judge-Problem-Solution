#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct node
{
    int at,cost;
    node(){}
    node(int _at,int _cost)
    {
        at = _at;
        cost = _cost;
    }
};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
vector<node>adj[110];
priority_queue<node>pq;
int dis[110];
void dijk()
{
    dis[1] = 0;
    pq.push(node(1,0));
    while(!pq.empty()){
        node e = pq.top();
        pq.pop();
        int u , cost_u;
        u = e.at;
        cost_u = e.cost;
        if(cost_u!=dis[u])continue;
        for(int i=0;i<adj[u].size();i++){
            int v, cost_uv;
            v = adj[u][i].at;
            cost_uv = adj[u][i].cost;
            if(dis[v]>cost_u+cost_uv){
                dis[v] = cost_u+cost_uv;
                pq.push(node(v,dis[v]));
            }
        }
    }
}
int main()
{
    int i,j,k,t,n,m,u,v,w;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        for(j=1;j<=n;j++){
            dis[j] = INF;
            adj[j].clear();
        }
        for(j=1;j<=m;j++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(node(v,w));
            adj[v].push_back(node(u,w));
        }
        dijk();
        if(dis[n]==INF)
            printf("Case %d: Impossible\n",i);
        else
            printf("Case %d: %d\n",i,dis[n]);
    }
return 0;
}
