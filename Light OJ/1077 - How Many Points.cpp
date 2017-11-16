#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll gcd(ll x, ll y)
{
  while (y != 0)
  {
    ll temp = y;
    y = x % y;
    x = temp;
  }
  return x;
}
int main()
{
    ll i,j,k,l,t,a,b,c,d,res,p,q,r,s;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        if(a>c)swap(a,c);
        if(b>d)swap(b,d);
        res = gcd(c-a,d-b)+1;
        printf("Case %lld: %lld\n",i,res);
    }
return 0;
}
