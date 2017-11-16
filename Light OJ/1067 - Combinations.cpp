#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll bigmod(ll a,ll b,ll m)
{
    if(b==0) return 1%m;
    ll x = bigmod(a,b/2,m);
    x = (x*x)%m;
    if(b%2==1)x = (x*a)%m;
    return x;
}
int fact[1000100];
int main()
{
    ll i,j,t,n,k,m=1000003,p,q,r,s;
    fact[0]=1;
    for(i=1;i<=1000003;i++)
        fact[i] = (fact[i-1]*i)%m;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld",&n,&k);
        p = fact[n];
        q = bigmod(fact[k],m-2,m);
        r = bigmod(fact[n-k],m-2,m);
        s = (q*r)%m;
        p = (p*s)%m;
        printf("Case %lld: %lld\n",i,p);
    }
return 0;
}
