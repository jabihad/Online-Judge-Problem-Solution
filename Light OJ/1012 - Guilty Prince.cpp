#include<bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
int row,col,i,visited[25][25];
int fx[]={1,-1,0,0};
int fy[]={0,0,1,-1};
char s[25][25];
bool valid(int x,int y)
{
    return x>=0 and y>=0 and x<row and y<col and s[x][y]=='.';
}
int bfs(int x,int y)
{
    int r=1;
    queue <pii> Q;
    Q.push(pii(x,y));
    visited[x][y]=i;
    while(!Q.empty()){
        pii temp = Q.front();
        Q.pop();
        int u=temp.first,v=temp.second;
        for(int j=0;j<4;j++){
            int ux = u+fx[j];
            int uy = v+fy[j];
            if(!valid(ux,uy))continue;
            if(visited[ux][uy]==i)continue;
            visited[ux][uy]=i;
            r++;
            Q.push(pii(ux,uy));
        }
    }
    return r;
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&col,&row);
        for(int j=0;j<row;j++){
            scanf("%s",s[j]);
            for(int k=0;s[j][k];k++){
                if(s[j][k]=='@')
                    x=j,y=k;
            }
        }
     printf("Case %d: %d\n",i,bfs(x,y));
    }
return 0;
}
