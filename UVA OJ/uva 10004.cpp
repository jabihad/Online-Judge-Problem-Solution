#include<bits/stdc++.h>
using namespace std;
vector<int>adj[300];
int vis[300];
bool bipartite()
{
    vis[0]=1;
    queue<int>q;
    q.push(0);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(vis[adj[u][i]]==-1){
                vis[adj[u][i]]=1-vis[u];
                q.push(adj[u][i]);
            }
            else if(vis[adj[u][i]]==vis[u])
                return false;
        }
    }
return true;
}
int main()
{
    bool z;
    int n,l,x,y;
    while(1){
    scanf("%d",&n);if(n==0)break;
    for(int i=0;i<300;i++){vis[i]=-1;adj[i].clear();}

    scanf("%d",&l);
    for(int i=0;i<l;i++){
        scanf("%d%d",&x,&y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    if(bipartite())
        printf("BICOLORABLE.\n");
    else
        printf("NOT BICOLORABLE.\n");

    }
return 0;
}
