#include<bits/stdc++.h>
#define ll long long int
#define M 1000000007
using namespace std;

ll fact[2000010];
ll bigmod(ll a, ll b)
{
    if(b==0)return 1 % M;
    ll x = bigmod(a, b/2);
    x = (x*x) % M;
    if(b%2 == 1)x = (x*a) % M;
    return x;
}
ll modinverse(ll a)
{
    return bigmod(a, M-2) % M;
}
int main()
{
    ll i, j, k, t, n, nom, den, ans;
    fact[0] = 1ll;
    for(i=1;i<=2000005;i++)
        fact[i] = (fact[i-1]*i) % M;

    scanf("%lld", &t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld", &n, &k);
        nom = fact[n+k-1];
        den = (fact[n]*fact[k-1])%M;
        den = bigmod(den, M-2);
        ans = (nom*den)%M;

        printf("Case %lld: %lld\n", i, ans);

    }

    return 0;
}
