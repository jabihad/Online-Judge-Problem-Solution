#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
struct node
{
    int at,cost;
    node(){}
    node(int _at,int _cost){
        at = _at;
        cost = _cost;
    }
};
bool operator<(node a,node b)
{
    return a.cost>b.cost;
}
vector<node>adj[21000];
priority_queue<node>pq;
int dist[21000];
void dijkstra(int s)
{
    dist[s] = 0;
    pq.push(node(s,0));
    while(!pq.empty()){
        node u = pq.top();
        pq.pop();
        if(u.cost!=dist[u.at])
            continue;
        for(int i=0;i<adj[u.at].size();i++){
            node e;
            e.at = adj[u.at][i].at;
            e.cost = adj[u.at][i].cost;
            if(dist[e.at]>max(dist[u.at],adj[u.at][i].cost)){
               dist[e.at] = min(dist[e.at],max(dist[u.at],adj[u.at][i].cost));
               pq.push(node(e.at,dist[e.at]));
            }
        }

    }
}
int main()
{
    int i,j,t,n,m,u,v,c,s;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&m);
        for(j=0;j<=2*n;j++){
            adj[j].clear();
            dist[j]=INF;
        }
        for(j=1;j<=m;j++){
            scanf("%d%d%d",&u,&v,&c);
            adj[u].push_back(node(v,c));
            adj[v].push_back(node(u,c));
        }
        scanf("%d",&s);
        dijkstra(s);
        printf("Case %d:\n",i);
        for(j=0;j<n;j++){
            if(dist[j]==INF)
               printf("Impossible\n");
            else
               printf("%d\n",dist[j]);
        }
    }
return 0;
}
