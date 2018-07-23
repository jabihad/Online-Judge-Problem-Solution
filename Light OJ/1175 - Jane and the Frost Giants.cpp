#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;

int vis[201][201], dj[201][201], df[201][201], r, c;
int fx[] = {1, -1, 0, 0};
int fy[] = {0, 0, 1, -1};
char cell[201][201];
vector<pii> v;

void bfsf()
{
    memset(vis, 0, sizeof(vis));
    memset(df, 1000000, sizeof(df));
    queue<pii>q;
    for(int i=0;i<v.size();i++){
        vis[v[i].first][v[i].second] = 1;
        df[v[i].first][v[i].second] = 0;
        q.push(v[i]);
    }
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];
            if(tx>=0 && tx<r && ty>=0 && ty<c && vis[tx][ty]==0 && cell[tx][ty]!='#'){
                vis[tx][ty] = 1;
                df[tx][ty] = df[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }
}
int bfsj(int x, int y)
{
    memset(vis, 0, sizeof(vis));
    memset(dj, 1000000, sizeof(dj));
    queue<pii> q;
    q.push(pii(x, y));
    dj[x][y] = 0;
    vis[x][y] = 1;
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        if(top.first==0 || top.first==r-1 || top.second==0 || top.second==c-1)
                return dj[top.first][top.second];
        for(int i=0;i<4;i++){
            int tx = top.first + fx[i];
            int ty = top.second + fy[i];

            if(tx>=0 && tx<r && ty>=0 && ty<c && vis[tx][ty]==0 && cell[tx][ty]!='#' && dj[top.first][top.second]+1<df[tx][ty]){
                vis[tx][ty] = 1;
                dj[tx][ty] = dj[top.first][top.second] + 1;
                q.push(pii(tx, ty));
            }
        }
    }
    return -1;
}
int main()
{
    int i, j, k, t, x, y, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d", &r, &c);
        for(j=0;j<r;j++)
            scanf("%s", cell[j]);
        for(j=0;j<r;j++){
            for(k=0;k<c;k++){
                if(cell[j][k]=='F')
                    v.push_back(pii(j, k));
                else if(cell[j][k]=='J')
                    x = j, y = k;
            }
        }
        bfsf();
        ans = bfsj(x, y);
        if(ans==-1)
            printf("Case %d: IMPOSSIBLE\n", i);
        else
            printf("Case %d: %d\n", i, ans+1);
        v.clear();
    }
    return 0;
}
