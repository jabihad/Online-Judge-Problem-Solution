#include<bits/stdc++.h>
using namespace std;
struct node
    {
        int x,y;
    }   ara[2000];
bool comp(node a,node b)
    {
        if(a.x<b.x)
            return true;
        else if(a.x>b.x)return false;
        else if(a.x==b.x){
            if(a.y>b.y)return true;
            else return false;
        }return false;
    }
void divisor()
{
    int i,j,k,l,m,n,d=0;
    for(i=1;i<=1000;i++){d=0;k=sqrt(i);
        for(j=1;j<=k;j++){
            if(i%j==0)d+=2;
        }
        if(sqrt(i)==k)d--;
        ara[i].x=d;
        ara[i].y=i;
    }
}
int main()
{
    int i,j,k,m,n;
    divisor();
    sort(ara,ara+1001,comp);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
            scanf("%d",&m);
            printf("Case %d: %d\n",i,ara[m].y);
    }
return 0;
}
