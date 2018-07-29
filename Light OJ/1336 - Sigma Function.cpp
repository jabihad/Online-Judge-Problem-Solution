#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll> v;
void calc()
{
    ll mx = 1e12;
    for(ll i=1;i*i<=mx;i+=2){
        ll temp = i*i;
        for(ll j=1;j*temp<=mx;j*=2){
            v.push_back(temp*j);
        }
    }
    sort(v.begin(), v.end());
}
int main()
{
    ll i, j, k, t, n, pos;
    calc();
    scanf("%lld", &t);
    for(i=1;i<=t;i++){
        scanf("%lld", &n);
        pos = upper_bound(v.begin(), v.end(), n) - v.begin();
        printf("Case %lld: %lld\n", i, n-pos);
    }

    return 0;
}

