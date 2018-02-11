#include<bits/stdc++.h>
using namespace std;
int vis[10000],dis[10000],ch[5];
int bfs(int so,int de)
{
    queue<int> q;
    q.push(so);
    vis[so]=1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        ch[3] =  u%10;
        ch[2] = (u/10)%10;
        ch[1] = (u/100)%10;
        ch[0] = (u/1000)%10;
        for(int i=0;i<4;i++){
            ch[i]+=1;
            ch[i]%=10;
            int v = ch[0]*1000+ch[1]*100+ch[2]*10+ch[3];
            if(vis[v]==0){
                dis[v] = dis[u]+1;
                vis[v] = 1;
                q.push(v);if(v==de)return dis[de];
            }
            ch[3] =  u%10;
            ch[2] = (u/10)%10;
            ch[1] = (u/100)%10;
            ch[0] = (u/1000)%10;
        }
        for(int i=0;i<4;i++){
            ch[i]-=1;
            if(ch[i]==-1)ch[i] = 9;
            int v = ch[0]*1000+ch[1]*100+ch[2]*10+ch[3];
            if(vis[v]==0){
                dis[v] = dis[u]+1;
                vis[v] = 1;
                q.push(v);if(v==de)return dis[de];
            }
            ch[3] =  u%10;
            ch[2] = (u/10)%10;
            ch[1] = (u/100)%10;
            ch[0] = (u/1000)%10;
        }
    }
return -1;
}
int main()
{
    int n,x,so=0,de=0,bn,r,y;
    cin>>n;
    while(n--){
        memset(vis,0,sizeof vis);
        memset(dis,0,sizeof dis);
        so=de=0;
        for(int i=0,j=1000;i<4;i++,j/=10){
            cin>>x;
            so+=x*j;
        }
        for(int i=0,j=1000;i<4;i++,j/=10){
            cin>>x;
            de+=x*j;
        }
        cin>>bn;
        for(int i=0;i<bn;i++){
            y = 0;
           for(int k=0,j=1000;k<4;k++,j/=10){
            cin>>x;
            y+=x*j;
         }
         vis[y] = 1;
        }
        if(vis[so]==1||vis[de]==1)
            cout<<-1<<endl;
        else if(so==de)
            cout<<0<<endl;
        else{
        r = bfs(so,de);
        cout<<r<<endl;
        }
    }
return 0;
}
