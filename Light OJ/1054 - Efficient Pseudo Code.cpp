#include<bits/stdc++.h>
#define MOD 1000000007
#define ll long long int

using namespace std;
ll mark[100100], nprime, prime[100100];
void sieve (ll n)
{
    ll i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4; i<=n; i+=2)mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
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
ll bigmod(ll a, ll b)
{
    if(b==0)return 1 % MOD;
    ll x = bigmod(a, b/2);
    x = (x*x) % MOD;
    if(b%2 == 1)x = (x*a) % MOD;
    return x;
}
ll modinverse(ll a)
{
    return bigmod(a, MOD-2) % MOD;
}
int main()
{
    sieve(100000);
    ll i, j, k, l, t;
    ll n, m, ans;
    scanf("%lld", &t);
    for(i=1;i<=t;i++){
        ans = 1;
        vector<pair<ll, ll> >v;
        scanf("%lld%lld", &n, &m);
        v.clear();
        for(j=0;j<nprime && (prime[j]*prime[j])<=n;j++){
            ll pr = 0;
            if(n%prime[j]==0){
                while(n%prime[j]==0){
                    n /= prime[j];
                    pr++;
                }
                v.push_back(make_pair(prime[j], pr));
            }
        }
        if(n>1)
            v.push_back(make_pair(n, 1));

        for(j=0;j<v.size();j++){
            ans = (ans%MOD * (bigmod(v[j].first, v[j].second*m + 1)-1)%MOD)%MOD;
            ans = (ans%MOD * modinverse(v[j].first-1)%MOD)%MOD;
        }
        ans = (ans+MOD)%MOD;
        printf("Case %lld: %lld\n", i, ans);
    }

    return 0;
}
