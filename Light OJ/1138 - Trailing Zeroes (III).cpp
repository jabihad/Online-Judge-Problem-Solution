#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll solve(ll num)
{
    ll ans = 0;
    while(num){
        ans += num/5;
        num /= 5;
    }
    return ans;
}
ll binary(ll n)
{
    ll lo = 1, hi = 500000000, mid, q;
    while(lo<=hi){
        mid = (lo + hi)/2;
        q = solve(mid);
        if(q<n)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}
int main()
{
    int i, j, t;
    ll q, ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld",&q);
        ans = binary(q);
        if(q==solve(ans))
            printf("Case %d: %lld\n",i,ans);
        else
            printf("Case %d: impossible\n",i);
    }
    return 0;

}

