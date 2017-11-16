#include<bits/stdc++.h>
#define INF 10000
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
    bool operator<(const node &a) const
    {
        return cost>a.cost;
    }
};
vector<node>adj[123];
int taken[123],cost[123];
int prim()
{
    int ans = 0;
    cost[1] = 0;
    priority_queue<node>pq;;
    pq.push(node(1,0));
    while(!pq.empty()){
        node e = pq.top();
        pq.pop();
        int u=e.at;
        if(taken[u])continue;
        ans += e.cost;
        taken[u] = 1;
        for(int i=0;i<adj[u].size();i++){
            node f = adj[u][i];
            int v = f.at;
            if(taken[v])continue;
            if(cost[v]>f.cost){
                cost[v] = f.cost;
                pq.push(node(v,cost[v]));
            }
        }
    }
return ans;
}
int main()
{
    int i,j,k,l,t,n,c,tc,ans,ch;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=0;j<=n+5;j++){
            taken[j] = 0;cost[j] = INF;
            adj[j].clear();
        }
        tc = 0;
        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                scanf("%d",&c);
                if(k!=j && c==0)continue;
                adj[j].push_back(node(k,c));
                adj[k].push_back(node(j,c));
                tc += c;
            }
        }
        ans = tc - prim();
        ch = 0;
        for(j=1;j<=n;j++){
            if(cost[j]==INF){
                ch=1;
            }
        }
        if(ch==1)
            printf("Case %d: -1\n",i);
        else
            printf("Case %d: %d\n",i,ans);
    }
return 0;
}
