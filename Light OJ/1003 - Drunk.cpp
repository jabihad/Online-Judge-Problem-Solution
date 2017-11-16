#include<bits/stdc++.h>
using namespace std;

vector<int>l, adj[21000];
queue<int>q;
int indegree[21000], n;
map<string,int> mp;

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
    int i, j, sz, k, m, u, v;
    int t;
    string r, s;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=1;j<=2*n;j++){
            adj[j].clear();
            indegree[j] = 0;
        }

        l.clear();
        while(!q.empty()){q.pop();}
        mp.clear();

        for(j=1,k=1;j<=n;j++){
            cin>>r>>s;
            if(mp[r]==0)mp[r] = k++;
            if(mp[s]==0)mp[s] = k++;
            adj[mp[r]].push_back(mp[s]);
            indegree[mp[s]]++;
        }

        for(j=1; j<k; j++)
            if(indegree[j]==0)
                q.push(j);

    top_sort();

    sz = l.size();
    if(sz==k-1)
        printf("Case %d: Yes\n",i);
    else
        printf("Case %d: No\n",i);

    }
    return 0;
}

