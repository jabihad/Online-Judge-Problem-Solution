#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bitset<10000010> mark;
vector<ll> prime;

void sieve (ll n)
{
    ll i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime.push_back(2);
    for(i=4; i<=n; i+=2)mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime.push_back(i);
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=2*i)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
int main()
{
    ll i, j, k, t, n, cnt, ans;
    sieve(10000005);
    scanf("%lld", &t);
    for(i=1;i<=t;i++){
         scanf("%lld", &n);
         ans = 1;
         for(j=0;j<prime.size() && prime[j]*prime[j]<=n;j++){
            cnt = 0;
            while(n%prime[j]==0){
                n /= prime[j];
                cnt++;
            }
            if(j>0)
                ans *= (cnt+1);
         }
         if(n>2)
            ans *= 2;

         printf("Case %lld: %lld\n", i, ans-1);
    }

    return 0;
}
