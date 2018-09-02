#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[22][1<<17], num[20], n, k, base;

ll Set(ll N, ll pos)
{
    return N = N | (1<<pos);
}
ll reset(ll N, ll pos)
{
    return N = N & ~(1<<pos);
}
bool check(ll N, ll pos)
{
    return (bool) (N & (1<<pos));
}
ll call(ll rem, ll mask)
{
    ll i, temp=0;
    if(mask == (1<<n)-1){
        if(rem==0)
            return 1;
        return 0;
    }
    if(dp[rem][mask]!=-1)
        return dp[rem][mask];
    for(i=0;i<n;i++){
        if(check(mask, i)==0){
            temp += call((rem*base + num[i])%k, Set(mask, i));
        }

    }
    return dp[rem][mask] = temp;
}
int main()
{
    ll i, j, ans, t;
    string s;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>base>>k>>s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        for(j=0;s[j];j++){
            if(s[j]>='0' && s[j]<='9')
               num[j] = s[j]-'0';
            else{
                num[j] = s[j]-'A' + 10;
            }
        }

        ans = call(0, 0);

        cout<<"Case "<<i<<": "<<ans<<endl;

    }

    return 0;
}
