#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll prime[7892],nprime,mark[788797],p;
void sieve()
{
    ll i,j,n=46350,limit = sqrt(n);
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
void segment_sieve(ll a,ll b)
{
    if(a==1)a=2;
    memset(mark,0,sizeof mark);
    ll i,j,sqrtb = sqrt(b)+2;
    for(i=0;i<nprime && prime[i]<=sqrtb;i++){
        ll j = prime[i]*prime[i];
        if(j<a)j=((a+prime[i]-1)/prime[i])*prime[i];
        for(;j<=b;j+=prime[i])
            mark[j-a]=1;
    }
    //if(a%2==0)i=a+1;
    for(i=a;i<=b;i++){
        if(!mark[i-a])
            p++;
    }

}
int main()
{
    ll a,b,i,t;
    sieve();
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
    scanf("%lld%lld",&a,&b);

    segment_sieve(a,b);
    printf("Case %lld: %lld\n",i,p);
    p=0;

    }
return 0;
}
