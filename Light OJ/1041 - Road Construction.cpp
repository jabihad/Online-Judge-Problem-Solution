#include<bits/stdc++.h>
#define INF 10000000
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
vector<node>adj[11000];
int taken[11000],cost[11000],ans=0;
map<string,int>m;
int prim()
{
    int city = 0;
    priority_queue<node>pq;
    cost[1] = 0;
    pq.push(node(1,0));
    while(!pq.empty()){
        node e = pq.top();pq.pop();
        int u = e.at;
        if(taken[u])continue;
        ans += e.cost;
        taken[u] = 1;
        city++;
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
return city;
}
int main()
{
    //freopen("file.txt","w",stdout);
    int i,j,k,t,n,u,v,w,dif=0,res;
    string r,s;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        dif =  0;
        scanf("%d",&n);
        for(j=0;j<=3*n;j++){
            taken[j] = 0;
            cost[j] = INF;
            adj[j].clear();
            m.clear();
        }
        for(j=1;j<=n;j++){
            cin>>r>>s>>w;
            if(m[r]==0)m[r]=++dif;
            if(m[s]==0)m[s]=++dif;
            adj[m[r]].push_back(node(m[s],w));
            adj[m[s]].push_back(node(m[r],w));
        }
        ans=0;
        res = prim();
        if(res==dif){
            printf("Case %d: %d\n",i,ans);
        }
        else
            printf("Case %d: Impossible\n",i);
    }
return 0;
}
