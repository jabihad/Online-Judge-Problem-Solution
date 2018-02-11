#include<bits/stdc++.h>
using namespace std;
vector<int>adj[300];
map<int,string>m;
map<string,int>mp;
int vis[300],d[300],ara[300];
bool dif(string x,string y)
{
    if(x.length()!=y.length())
        return false;
    int c=0;
    for(int i=0;i<x.length();i++){
        if(x[i]!=y[i])
            c++;
    }
    if(c>1)return false;
    return true;
}
int bfs(string a,string b)
{
    int dis=0,v;
    vis[mp[a]]=1;
    queue<int>q;
    q.push(mp[a]);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0;i<adj[u].size();i++){
            if(vis[adj[u][i]]==0){
                v = adj[u][i];
                vis[v]=1;
                d[v]=d[u]+1;
                if(adj[u][i]==mp[b]){return d[v];}
                q.push(v);
            }
        }
    }
return 0;
}
int main()
{
    string a,b,s;
    int n;
    bool c = false;char input[100];
    scanf("%d",&n);
    while(n--){
            int j=0;
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
        for(int i=0;i<301;i++)adj[i].clear();m.clear();mp.clear();
        while(1){
            cin>>a;
            if(a=="*")break;
            mp[a]=j;///a = string
             m[j]=a;///j = int
            j++;
        }
        if(c)printf("\n");c = true;
        for(int i=0;i<j;i++){
            for(int k=i+1,l=0;k<j;k++,l++){
                if(dif(m[i],m[k])){
                    adj[i].push_back(k);
                    adj[k].push_back(i);
                }
            }
        }
    string start,to,line;
    int pos;
    getline(cin,line);
    getline(cin,line);
    while(line != ""){
      pos = line.find(" ");
      start = line.substr(0,pos);
      to = line.substr(pos+1,line.size());
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
      cout<<start<<" "<<to<<" "<<bfs(start,to)<<endl;
      if(!getline(cin,line))
        break;
    }
    }
return 0;
}

