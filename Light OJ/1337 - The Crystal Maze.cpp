#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

struct p
{
    int a=0, b=0;
} par[505][505];

int vis[505][505], cost[505][505];
char cell[505][505];
int fx[5] = {1, -1, 0, 0};
int fy[5] = {0, 0, 1, -1};
int n, m;


int bfs(int x, int y)
{
    int cnt = 0;
    vis[x][y] = 1;
    queue<pii> q;
    q.push(pii(x, y));
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m && vis[tx][ty]==0 && cell[tx][ty]!='#'){
                    if(cell[tx][ty]=='C')
                        cnt++;
                    vis[tx][ty]=1;
                    q.push(pii(tx,ty));
                    par[tx][ty].a = x;
                    par[tx][ty].b = y;
            }
        }
    }
    return cost[x][y] = cnt;
}
int main()
{
    int i, j, k, t, q, x, y, res;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d", &n, &m, &q);
        for(j=0;j<n;j++)
            scanf("%s", cell[j]);
        printf("Case %d:\n", i);
        memset(vis, 0, sizeof(vis));
        for(j=1;j<=q;j++){
            scanf("%d%d", &x, &y);
            x--;
            y--;
            if(vis[x][y]==0){
                res = bfs(x, y);
                par[x][y].a = x;
                par[x][y].b = y;
            }

            else
                res = cost[par[x][y].a][par[x][y].b];

            printf("%d\n", res);
        }
    }

    return 0;
}
