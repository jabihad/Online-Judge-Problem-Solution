#include<bits/stdc++.h>
using namespace std;
map<string,string>par;
map<string,int>frnd;
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
    cout<<frnd[v]<<'\n';
}
int main()
{
    int i,j,k,l,m,n,t;
    string node1,node2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        par.clear();
        frnd.clear();
        for(i=0; i<n; i++)
        {
            cin>>node1>>node2;
            join(node1,node2);
        }
    }
    return 0;
}
