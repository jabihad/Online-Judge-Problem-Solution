#include<bits/stdc++.h>
using namespace std;
int u,v,w,x,y,z;
int main()
{
    int a,b,c,d,e,f,i,j,k,l,m,n,t,V;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    scanf("%d",&n);

    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    u=a,v=b,w=c,x=d,y=e,z=f;
    for(j=1;j<n;j++){
    scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
    if(a>u)u=a;
    if(b>v)v=b;
    if(c>w)w=c;
    if(d<x)x=d;
    if(e<y)y=e;
    if(f<z)z=f;
    }
    V=(x-u)*(y-v)*(z-w);
    if(V<0)V=0;
    printf("Case %d: %d\n",i,V);
    }



return 0;
}
