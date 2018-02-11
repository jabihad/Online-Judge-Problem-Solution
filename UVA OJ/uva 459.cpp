#include<bits/stdc++.h>
using namespace std;
map<string,string>par;
string find(string a)
{
    if(par[a]==a)
        return a;
    return par[a]=find(par[a]);
}
void join(string a,string b)
{
    string u,v;
    u = find(a);
    v = find(b);
    if(u!=v)
    {
        par[u] = v;
    }
}
int main()
{
    set<string>s;
    int i,j,k,l,m,n;
    string a,b,c,h,x,y;
    cin>>n;
    for(k=1; k<=n; k++)
    {
        for(i=65; i<=91; i++)
        {
            x = i;
            par[x]=x;
        }
        cin>>h;
        j = h[0];
        getchar();
        while(getline(cin,c))
        {
            if(c.size()==0)break;
            a=c[0];
            b=c[1];
            join(a,b);
        }
        for(i=65; i<=j; i++)
        {
            x = i;
            find(x);
            s.insert(par[x]);
        }
        cout<<s.size()<<'\n';
        if(k<n)cout<<'\n';
        s.clear();
        par.clear();
    }
    return 0;
}

