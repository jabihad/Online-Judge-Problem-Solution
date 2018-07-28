/*
We have to find a cell which is reachable by every Rider with minimal move.
Each cell of the grid will be considered as the potential destination for all the rider
So we will call bfs from each cell.Then we will consider the cells (suppose (i, j) ) which contains number(jump number).
We will divide distance[i][j] by the jump number to get the minimum steps needed to go from destination to (i, j) or vice versa
Thus we will get every rider's total move to go to one destination
The result is the minimum value of every rider's total move to go to all destination
*/
#include<bits/stdc++.h>
#define pii pair<int, int>
#define INF 111132
using namespace std;

int fx[] = { 1, 1, -1, -1, 2, 2, -2, -2 };
int fy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

int dis[11][11], n, m;
char grid[11][11];

int bfs(int x, int y)
{
    int i, j;
    for(i=0;i<=n;i++){
        for(j=0;j<=m;j++)
            dis[i][j] = INF;
    }
    queue<pii> q;
    q.push(pii(x, y));
    dis[x][y] = 0;
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(i=0;i<8;i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<m && dis[tx][ty]==INF){
                dis[tx][ty] = dis[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }
    int res = 0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(grid[i][j]!='.'){
                if(dis[i][j]==INF) /// destination is not reachable by the grid[i][j]
                   return INF;
                int num = grid[i][j]-48;
                res += (dis[i][j]+num-1)/(num);
            }
        }
    }
    return res;
}
int main()
{
    int i, j, k, t, res;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        res = INF;
        scanf("%d%d", &n, &m);
        getchar();
        for(j=0;j<n;j++)
            scanf("%s", grid[j]);
        for(j=0;j<n;j++){
            for(k=0;k<m;k++){
                res = min(res, bfs(j, k)); /// Every cell is a potential destination
            }
        }
        if(res==INF)
            res = -1;

        printf("Case %d: %d\n", i, res);
    }

    return 0;
}
