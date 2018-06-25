#include<bits/stdc++.h>
using namespace std;

int cnt(int n, int m)
{
    int ans=0, i;
    for(i=m;;i*=m){
        if(n/i>0)
            ans += n/i;
        else
            break;
    }
    return ans;
}

int main()
{
    int i, j, k, l, m, n, t, r, p, q, n2, n5, d2, d5, oth2, oth5, ans;
    cin>>t;
    for(i=1;i<=t;i++){
        oth2 = oth5 = 0;
        cin>>n>>r>>p>>q;
        n2 = cnt(n, 2);
        n5 = cnt(n, 5);
        d2 = cnt(r, 2) + cnt(n-r, 2);
        d5 = cnt(r, 5) + cnt(n-r, 5) ;
        while(p%2==0){
            p /= 2;
            oth2++;
        }
        while(p%5==0){
            p /= 5;
            oth5++;
        }
        ans = max(0, min(n2-d2+oth2*q, n5-d5+oth5*q));

        printf("Case %d: %d\n", i, ans);
    }

return 0;
}
