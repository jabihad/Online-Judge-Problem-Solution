#include<bits/stdc++.h>
using namespace std;
vector<int>adj[25000];
int color[25000];
int bfs(int s)
{
    int c1=0,c2=0;
    queue<int>q;
    q.push(s);
    color[s]=1;c1++;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(color[adj[u][i]]==0){
                if(color[u]==1){
                    color[adj[u][i]]=2;
                    c2++;
                }
                else{
                    color[adj[u][i]]=1;
                    c1++;
                }
                q.push(adj[u][i]);
            }
        }
    }
    return max(c1,c2);
}
int main()
{
    int i,j,k,t,dual,u,v,ara[220000],s=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        s = 0;
        scanf("%d",&dual);
        for(j=1,k=1;j<=dual;j++){
            scanf("%d%d",&u,&v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            ara[k++] = u;
            ara[k++] = v;
        }
        for(j=1;j<=2*dual;j++){
            if(color[ara[j]]==0){
                s += bfs(ara[j]);
            }
        }
        printf("Case %d: %d\n",i,s);
        for(j=1;j<=21000;j++){
           color[j]=0;
           adj[j].clear();
        }
   }
return 0;
}
