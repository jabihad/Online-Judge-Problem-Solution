#include<bits/stdc++.h>
using namespace std;
map<string,string>par;
map<string,int>frnd;
int mx;
string find(string node)
{
    if(par[node]=="")
        return node;
    return par[node]=find(par[node]);
}
void join(string node1,string node2)
{
    string u,v;
    u = find(node1);
    v = find(node2);
    if(u!=v)
    {
        par[u]=v;
        if(frnd[u]==0)frnd[u]=1;
        if(frnd[v]==0)frnd[v]=1;
        frnd[v] += frnd[u];
    }
    mx = max(mx,frnd[v]);
}
int main()
{
    int i,j,k,l,m,n,t;
    string node1,node2;
    while(1)
    {
        mx = 0;
        cin>>n>>m;
        if(m==0)mx=1;
        if(n==m and m==0)break;
        par.clear();
        frnd.clear();
        for(i=0; i<n; i++)
            cin>>node1;
        for(i=0; i<m; i++)
        {
            cin>>node1>>node2;
            join(node1,node2);
        }
        cout<<mx<<endl;
    }
    return 0;
}


