#include <bits/stdc++.h>
using namespace std;
long long int mark[1000007],nprime,prime[90000];
void sieve (long long int n)
{
    long long int i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4;i<=n;i+=2)mark[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i]){
            prime[nprime++]=i;
            if(i<=limit){
                for(j=i*i;j<=n;j+=2*i){
                    mark[j]=1;
                }
            }
        }
    }
}
long long int primeFact(long long int n)
{
    long long int i,x,ans=1;
    x = 0;
    for(i=0;i<nprime && prime[i]*prime[i]<=n;i++){
        x = 0;
        while(n%prime[i]==0)
        {
            n/=prime[i];
            x++;
        }
        if(x>0)ans*=(x+1);
    }
    if(n>1)ans*=2;
return ans;
}
int main()
{
    sieve(1000000);
    long long int t,n,ans,i,j,k;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&n);
        ans = primeFact(n);
       printf("Case %lld: %lld\n",i,ans-1);

    }
    return 0;
}
