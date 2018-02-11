#include<bits/stdc++.h>
using namespace std;

vector<int>l,adj[300];
set<int>q;
int indegree[300];
map<string,int> m1,m3;
map<int,string> m2;

void top_sort()
{
    set<int>::iterator it;
    int u, v;
    while(!q.empty())
    {
        it = q.begin();
        u = *it;
        q.erase(u);
        l.push_back(u);
        for(int i=0; i<adj[u].size(); i++)
        {
            v = adj[u][i];
            indegree[v]--;
            if(indegree[v]==0)
                q.insert(v);
        }
    }
}

int main()
{
    int i, j=0, k=1, n, m, u, v;
    string p[111], r, s;
    while(cin>>n){
        for(i=1,j=0;i<=n;i++){
            cin>>p[i];
            m1[p[i]] = ++j;
            m2[j] = p[i];
        }
        cin>>m;
        for(i=1;i<=m;i++){
            cin>>r>>s;
            indegree[m1[s]]++;
            adj[m1[r]].push_back(m1[s]);

        }
        for(i=1;i<=n;i++){
            if(indegree[m1[p[i]]]==0){
                q.insert(m1[p[i]]);
            }
        }
        top_sort();
        j = l.size();
        printf("Case #%d: Dilbert should drink beverages in this order: ",k);
        for(i=0;i<j;i++){
            cout<<m2[l[i]];
            if(i<j-1)
                cout<<" ";
        }
        cout<<"."<<endl<<endl;
        for(i=1;i<=111;i++){
            adj[i].clear();
            indegree[i] = 0;
        }
        m1.clear();
        m2.clear();
        l.clear();
        k++;

    }
    return 0;
}
