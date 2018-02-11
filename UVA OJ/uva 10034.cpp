#include<bits/stdc++.h>
#define pii pair<double,int>
#define vpi vector<pii>
#define ff first
#define ss second
using namespace std;
vpi V[3005];
int vis[3005]= {0};
double prim(int n)
{
    priority_queue<pii> p;
    double cost=0;
    p.push(pii(0,n));
    while(!p.empty())
    {
        pii tem = p.top();
        p.pop();
        int v = tem.ss;
        if(!vis[v])
        {
            vis[v] = 1;
            cost += -tem.ff;
            for(int i=0; i<V[v].size(); i++)
                if(!vis[V[v][i].ss])
                    p.push(pii(-(V[v][i].ff),V[v][i].ss));
        }
    }
    return cost;
}
int main()
{
    int t,n,l,j,i,a;
    double x[10100],y[10100],d,r=0;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        for(j=1; j<=1000; j++)
        {
            V[j].clear();
            vis[j]=0;
        }
        r=0;
        scanf("%d",&n);
        for(j=1; j<=n; j++)
            scanf("%lf%lf",&x[j],&y[j]);

        for(j=1; j<n; j++)
        {
            for(int k=j+1; k<=n; k++)
            {
                d=sqrt((x[j]-x[k])*(x[j]-x[k])+(y[j]-y[k])*(y[j]-y[k]));
                V[j].push_back(pii(d,k));
                V[k].push_back(pii(d,j));
            }
        }
        r = prim(1);
        printf("%.2lf\n",r);
        if(i<t)printf("\n");
    }
    return 0;
}
