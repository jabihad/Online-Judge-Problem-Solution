#include<bits/stdc++.h>
#define pi pair<int, int>
using namespace std;

int visited[21][21], dis[21][21], hx, hy, n, m;
char s[21][21];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
void bfs(int x, int y)
{
    int ux, uy, vx, vy, i, c=0;
    queue<pi> q;

    q.push(pi(x, y));
    visited[x][y] = 1;
    dis[x][y] = 0;

    while(!q.empty())
    {
        ux = q.front().first;
        uy = q.front().second;

        q.pop();

        for(i=0; i<4; i++)
        {
            vx = ux + dx[i];
            vy = uy + dy[i];
            if(vx<0 || vx>=n || vy<0 || vy>=m || s[vx][vy]=='#' || s[vx][vy]=='m')
                continue;
            if(visited[vx][vy] == 0)
            {
                q.push(pi(vx, vy));
                visited[vx][vy] = 1;
                dis[vx][vy] = dis[ux][uy] + 1;
                if(s[vx][vy]=='h'){

                    c = 1;
                    break;
                }
            }
        }
        if(c==1)break;
    }
}

int main()
{
    int i, j, k, l, t, ax, ay, bx, by, cx, cy, res, a, b, c;

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d", &n, &m);

        for(j=0;j<n;j++){
            getchar();
            for(k=0;k<m;k++){
                scanf("%c", &s[j][k]);
                if(s[j][k]=='a')
                    ax = j, ay = k;
                else if(s[j][k]=='b')
                    bx = j, by = k;
                else if(s[j][k]=='c')
                    cx = j, cy = k;
                else if(s[j][k]=='h')
                    hx = j, hy = k;
            }
        }
        memset(visited, 0, sizeof visited);
        memset(dis, 0, sizeof dis);
        bfs(ax, ay);
        a = dis[hx][hy];

        memset(visited, 0, sizeof visited);
        memset(dis, 0, sizeof dis);
        bfs(bx, by);
        b = dis[hx][hy];

        memset(visited, 0, sizeof visited);
        memset(dis, 0, sizeof dis);
        bfs(cx, cy);
        c = dis[hx][hy];

        res = max(a, max(b, c));

        printf("Case %d: %d\n", i, res);
    }

    return 0;
}

