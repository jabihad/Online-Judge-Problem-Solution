#include<bits/stdc++.h>
#define INF 10000000
using namespace std;
struct node1
{
    int at,cost;
    node1(){}
    node1(int _at,int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const node1 &a) const
    {
        return cost>a.cost;
    }
};
struct node2
{
    int at,cost;
    node2(){}
    node2(int _at,int _cost)
    {
        at = _at;
        cost = _cost;
    }
    bool operator<(const node2 &a) const
    {
        return cost<a.cost;
    }
};
vector<node1>adj1[110];
vector<node2>adj2[110];
int taken[110],cost[110];
int prim1()
{
    int ans=0;
    priority_queue<node1>pq;
    cost[0] = 0;
    pq.push(node1(0,0));
    while(!pq.empty()){
        node1 e = pq.top();pq.pop();
        int u = e.at;
        if(taken[u])continue;
        ans += e.cost;
        taken[u] = 1;
        for(int i=0;i<adj1[u].size();i++){
            node1 f = adj1[u][i];
            int v = f.at;
            if(taken[v])continue;
            if(cost[v]>f.cost){
                cost[v] = f.cost;
                pq.push(node1(v,cost[v]));
            }
        }
    }
return ans;
}
int prim2()
{
    int ans=0;
    priority_queue<node2>pq;
    cost[0] = 0;
    pq.push(node2(0,0));
    while(!pq.empty()){
        node2 e = pq.top();pq.pop();
        int u = e.at;
        if(taken[u])continue;
        ans += e.cost;
        taken[u] = 1;
        for(int i=0;i<adj2[u].size();i++){
            node2 f = adj2[u][i];
            int v = f.at;
            if(taken[v])continue;
            if(cost[v]==INF || cost[v]<f.cost){
                cost[v] = f.cost;
                pq.push(node2(v,cost[v]));
            }
        }
    }
return ans;
}
int main()
{
    int i,j,k,t,n,u,v,w,r1=0,r2=0,r;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<=n;j++){
            taken[j] = 0;
            cost[j] = INF;
            adj1[j].clear();
            adj2[j].clear();
        }
        while(1){
            scanf("%d%d%d",&u,&v,&w);
            if(u==v && v==w && u==0)break;
            adj1[u].push_back(node1(v,w));
            adj1[v].push_back(node1(u,w));
            adj2[u].push_back(node2(v,w));
            adj2[v].push_back(node2(u,w));
        }
        r1 = prim1();
        for(j=0;j<=n;j++){
            taken[j] = 0;
            cost[j] = INF;
        }
        r2 = prim2();
        r = r1+r2;
        if(r%2==0){
            printf("Case %d: %d\n",i,r/2);
        }
        else{
            printf("Case %d: %d/2\n",i,r);
        }
    }
return 0;
}
