#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

struct cordinate
{
    int a, b;
} cor[27];

char cell[12][12], ord[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
int l, n, vis[12][12], cost[12][12];

int bfs(int sx, int sy, int dx, int dy)
{
    queue<pii> q;
    q.push(pii(sx, sy));
    cost[sx][sy] = 0;
    vis[sx][sy] = 1;
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];
            if(tx>=0 && tx<n && ty>=0 && ty<n && vis[tx][ty]==0 && cell[tx][ty]!='#' && cell[tx][ty]<=ord[l]){
                vis[tx][ty] = 1;
                cost[tx][ty] = cost[top.first][top.second] + 1;
                if(tx==dx && ty==dy){
                    l++;
                    return cost[tx][ty];
                }
                q.push(pii(tx, ty));
            }
        }
    }
    return -1;
}
int main()
{
    int i, j, k, t, temp, cnt, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        cnt = 0;
        ans = 0;
        l = 1;
        temp = 0;
        for(j=0;j<n;j++)
            scanf("%s", &cell[j]);
        for(j=0;j<n;j++){
            for(k=0;k<n;k++){
                if(cell[j][k]>='A' && cell[j][k]<='Z'){
                    cor[cell[j][k]-65].a = j;
                    cor[cell[j][k]-65].b = k;
                    cnt++;
                }
            }
        }
        printf("Case %d: ", i);
        for(j=0;j<cnt-1;j++){
            memset(vis, 0, sizeof(vis));
            memset(cost, 0, sizeof(cost));
            temp = bfs(cor[j].a, cor[j].b, cor[j+1].a, cor[j+1].b);

            if(temp==-1){
                printf("Impossible\n");
                break;
            }
            else
                ans += temp;
        }
        if(cnt==1)
            printf("0\n");
        else if(temp!=-1)
            printf("%d\n", ans);
    }
    return 0;
}
