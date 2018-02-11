#include<bits/stdc++.h>
#define pii pair<int,int>
#define uu first
#define vv second
int vis[100][100],d[100][100],cell[100][100],ara[200];
int fx[]={-2,-2,-1,-1,1,1,2,2};
int fy[]={-1,1,-2,2,-2,2,-1,1};
//for(int i=97,j=1;j<=8;i++,j++)ara[97]=j;
using namespace std;
int bfs(int sx,int sy,int dx,int dy)
{
    vis[sx][sy]=1;
    queue<pii>q;
    q.push(pii(sx,sy));
    while(!q.empty()){
        pii top=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int tx = top.uu+fx[i];
            int ty = top.vv+fy[i];
        if(tx>=1&&tx<=8&&ty>=1&&ty<=8&&vis[tx][ty]==0){
            vis[tx][ty]=1;
            d[tx][ty]=d[top.uu][top.vv]+1;
            if(tx==dx&&ty==dy){return d[tx][ty];}
            q.push(pii(tx,ty));
           }
        }
    }
return 0;
}
int main()
{
    int r1,c1,r2,c2,x;
    char s[78];
    for(int i=97,j=1;j<=8;i++,j++)ara[i]=j;
    while(gets(s)){
        memset(vis,0,sizeof vis);
        memset(d,0,sizeof d);
       r1=ara[s[0]];
       c1=s[1]-48;
       r2=ara[s[3]];
       c2=s[4]-48;
       //printf("%d %d %d %d\n",r1,c1,r2,c2);
       if(r1==r2&&c1==c2)
         x=0;
       else
         x=bfs(r1,c1,r2,c2);
        printf("To get from %c%c to %c%c takes %d knight moves.\n",s[0],s[1],s[3],s[4],x);
    }
}

