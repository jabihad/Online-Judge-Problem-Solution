#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll amount[1010], n, m;
bool check(ll capacity)
{
    int i = 0, cont = 1;
    ll cur = 0;
    while(i<n){
        if(amount[i]>capacity)
            return false;
        if(cur+amount[i]<=capacity){
            cur = cur + amount[i];
            i++;
        }
        else{
            if(cont==m)return false;
            cont++;
            cur = 0;
        }
    }
    return true;
}
int main()
{
    int i, j, k, t;
    ll lo, hi, mid, ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lld%lld",&n, &m);
        for(j=0;j<n;j++)
            scanf("%lld",&amount[j]);
        lo = 0;
        hi = 10000000000;
        while(lo<=hi){
            mid = (lo + hi)/2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        printf("Case %d: %lld\n",i,ans);
    }
    return 0;
}

