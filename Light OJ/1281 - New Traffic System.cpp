#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct node
{
    int at,cost,state;
    node(){}
    node(int _at,int _cost,int _state)
    {
        at = _at;
        cost = _cost;
        state = _state;
    }
};
struct graphnode
{
    int v,w,is_proposed_road;
    graphnode(){}
    graphnode(int _v,int _w,int _is_proposed_road)
    {
        v = _v;
        w = _w;
        is_proposed_road = _is_proposed_road;
    }
};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
int dis[10005][12];
vector<graphnode>adj[10005];
int dijk(int n,int d)
{
    priority_queue<node>pq;
    dis[0][0] = 0;
    pq.push(node(0,0,0));
    while(!pq.empty()){
        node e = pq.top();
        pq.pop();
        int u,cost_u,state_u;
        u = e.at;
        cost_u = e.cost;
        state_u = e.state;
        if(u==n-1)return e.cost;
        if(cost_u!=dis[u][state_u])continue;
        for(int i=0;i<adj[u].size();i++){
            int v,cost_uv,pr,state_v;
            v = adj[u][i].v;
            cost_uv = adj[u][i].w;
            pr = adj[u][i].is_proposed_road;
            if(state_u+pr<=d and cost_u+cost_uv < dis[v][state_u+pr]){
                dis[v][state_u+pr] = cost_u+cost_uv;
                state_v = state_u+pr;
                pq.push(node(v,dis[v][state_u+pr],state_v));

            }
        }
    }
return -1;
}
int main()
{
    int t,n,m,k,d,i,j,l,u,v,w,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d%d",&n,&m,&k,&d);
        for(j=0;j<=n+2;j++){
            adj[j].clear();
        }
        for(j=0;j<=n+2;j++){
            for(l=0;l<=d+2;l++){
                dis[j][l] = INF;
            }
        }
        for(j=0;j<m;j++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(graphnode(v,w,0));
        }
        for(j=0;j<k;j++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back(graphnode(v,w,1));
        }
        r = dijk(n,d);
        printf("Case %d: ",i);
        if(r==-1)
           printf("Impossible\n");
        else
            printf("%d\n",r);
    }
return 0;
}
