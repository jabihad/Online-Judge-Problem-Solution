#include<bits/stdc++.h>
#define ll long long int
#define INF LLONG_MAX
using namespace std;
struct node
{
    ll at,cost;
    node() {}
    node(ll _at,ll _cost)
    {
        at = _at;
        cost = _cost;
    }

};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
priority_queue<node>pq;
vector<node>adj[5111];
ll d[5111],sd[5111];
void dijkstra(ll s,ll des)
{
    d[s]=0;
    pq.push(node(s,0));
    while(!pq.empty())
    {
        node e = pq.top();
        ll u = e.at;
        ll dis = e.cost;
        pq.pop();
        for(ll i=0; i<adj[u].size(); i++)
        {
            ll v,cost_uv;
            v = adj[u][i].at;
            cost_uv = adj[u][i].cost;
            if((d[v]-cost_uv)>dis)
            {
                sd[v] = d[v];
                d[v] = dis+cost_uv;
                pq.push(node(v,d[v]));
            }
            else if((dis<sd[v]-cost_uv) && (d[v]-cost_uv)!=dis)
            {
                sd[v] = dis+cost_uv;
                pq.push(node(v,sd[v]));
            }
        }
    }
}
int main()
{
    ll t,n,r,i,j,u,v,w;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld%lld",&n,&r);
        for(j=1; j<=n; j++)
        {
            d[j]=sd[j] = LLONG_MAX;
            adj[j].clear();
        }
        for(j=1; j<=r; j++)
        {
            scanf("%lld%lld%lld",&u,&v,&w);
            adj[u].push_back(node(v,w));
            adj[v].push_back(node(u,w));
        }
        dijkstra(1,n);
        printf("Case %lld: %lld\n",i,sd[n]);
    }
    return 0;
}
