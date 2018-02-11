#include<bits/stdc++.h>
using namespace std;

vector<int>l,adj[10000];
queue<int>q;
int indegree[111];

void top_sort()
{
    int u, v;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        l.push_back(u);
        for(int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                q.push(v);
        }
    }
}

int main()
{
    int i, j=0, k, n, m, u, v;
    while(1)
    {
        cin>>n>>m;
        if(n==m && m==0)break;
        for(i=1; i<=m; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
            indegree[v]++;
        }
        for(i=1; i<=n; i++)
            if(indegree[i]==0)
                q.push(i);
        top_sort();
        j = l.size();
        for(i=0; i<j; i++)
        {
            cout<<l[i];
            if(i<j-1)
                cout<<" ";
        }
        cout<<endl;
        for(i=1; i<=n; i++)
        {
            adj[i].clear();
            indegree[i]=0;
        }
        l.clear();
    }
    return 0;
}

