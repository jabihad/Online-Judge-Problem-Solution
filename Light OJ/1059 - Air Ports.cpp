#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int u,v,w;
    edge() {}
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator<(const edge &a) const
    {
        return w<a.w;
    }
};
vector<edge> e;
int p[10005];
int find(int x)
{
    if(p[x]==x)
        return x;
    return p[x] = find(p[x]);
}
int main()
{
    int i,j,t,n,m,x,y,c,sz,a,b,ans,dif,air;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d%d",&n,&m,&air);
        for(j=1; j<=n+5; j++)
            p[j] = j;
        e.clear();
        ans = dif = 0;
        for(j=1;j<=m;j++){
            scanf("%d%d%d",&x,&y,&c);
            if(c<air)
               e.push_back(edge(x,y,c));
        }
        sort(e.begin(),e.end());
        sz = e.size();
        for(j=0;j<sz;j++){
            a = find(e[j].u);
            b = find(e[j].v);
            if(a!=b){
                dif++;
                p[a] = b;
                ans += e[j].w;
            }
        }
        printf("Case %d: %d %d\n",i,(n-dif)*air+ans,n-dif);
    }
return 0;
}
