#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll ara[2010];
int main()
{
    ll i, j, k, t, n;
    ll lo, hi, mid, ans;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&n);
        for(j=0;j<n;j++)
            scanf("%lld",&ara[j]);
        sort(ara,ara+n);
        ans = 0;
        for(j=0;j<n-2;j++){
            for(k=j+1;k<n-1;k++){
                lo = k+1;
                hi = n-1;
                while(lo<=hi){
                    mid = (lo + hi)/2;
                    if(ara[j]+ara[k]<=ara[mid]){
                        hi = mid - 1;
                    }
                    else
                        lo = mid + 1;
                }
                ans += hi-k;
            }
        }
        printf("Case %lld: %lld\n",i, ans);
    }
    return 0;
}

