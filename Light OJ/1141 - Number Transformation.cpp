#include<bits/stdc++.h>
using namespace std;

vector<int> adj[1100];
int visited[2000], dis[2000], s, t, flag;
void PrimeFactors(int m)
{
    int c = 0, n = m;
    while(n%2==0 && n != 2){
        if(c==0){
            adj[m].push_back(2);
            c = 1;
        }
        n /= 2;
    }
    c = 0;
    for(int i=3;i<=sqrt(n);i+=2){
        c = 0;
        while(n%i==0){
            if(c==0){
                adj[m].push_back(i);
                c = 1;
            }
            n /= i;
        }
    }
    if(n>2 && n!=m)
        adj[m].push_back(n);
}
void bfs(int source)
{
    int u, v, i;
    queue<int> q;
    q.push(source);
    visited[source] = 1;
    dis[source] = 0;
    flag = 0;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        PrimeFactors(u);

        for(i=0; i<adj[u].size(); i++)
        {
            v = u + adj[u][i];
            if(v>t)continue;
            if(visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
                dis[v] = dis[u] + 1;
            }
            if(v==t){
                flag = 1;
                break;
            }

        }
        if(v==t)break;
        adj[u].clear();
    }
}

int main()
{
    int i, j, k, l, T;

    scanf("%d", &T);
    for(i=1;i<=T;i++){

        scanf("%d%d", &s, &t);

        memset(dis, 0, sizeof dis);
        memset(visited, 0, sizeof visited);

        bfs(s);

        printf("Case %d: ", i);
        if(s==t)
            printf("0\n");
        else if(flag)
            printf("%d\n", dis[t]);
        else
            printf("-1\n");
    }
    return 0;
}
