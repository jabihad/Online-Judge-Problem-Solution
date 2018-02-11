#include<bits/stdc++.h>
using namespace std;
int prime[1000000],nprime,mark[1005000],ans[1005000];
void sieve()
{
    int i,j,n=1000000,limit = sqrt(n);
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    for(i=3;i<=n;i+=2){
        if(!mark[i]){
            prime[nprime++]=i;
            if(i<=limit){
                for(j=i*i;j<=n;j+=i*2)
                    mark[j]=1;
            }
        }
    }
}
int digsum(int n)
{
    int t=0;
    while(n!=0){
        t+=n%10;
        n/=10;
    }
return t;
}
int main()
{
    sieve();
    int n,a,b,x,s,c=1;
    ans[2]=1;
    for(int j=3;j<=1005000;j+=2){
        s = digsum(j);
    if(mark[s]==0 && mark[j]==0)
        c++;
    ans[j]=ans[j+1]=c;
    }
    scanf("%d",&n);
    for(int k=1;k<=n;k++){
      scanf("%d%d",&a,&b);
      printf("%d\n",ans[b]-ans[a-1]);
    }
return 0;
}

