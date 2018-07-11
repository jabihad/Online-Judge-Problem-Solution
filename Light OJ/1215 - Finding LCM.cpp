#include<bits/stdc++.h>
#define ll long long int
using namespace std;

bitset<1000005> mark;
vector<ll> prime;
void sieve (int n)
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
    ll i, j, k, l, t, a, b, ans, cnt1, cnt2, cnt3;

    sieve(1000000);

    scanf("%lld", &t);
    for(i=1;i<=t;i++){

        scanf("%lld%lld%lld", &a, &b, &l);
        if(l%a!=0 || l%b!=0){
            printf("Case %lld: impossible\n", i);
            continue;
        }
        ans = 1ll;

        for(j=0;j<prime.size() && prime[j]<=l;j++){
            cnt1 = cnt2 = cnt3 = 0;
            while(l%prime[j]==0){
                l /= prime[j];
                cnt1++;
                if(a%prime[j]==0){
                    a /= prime[j];
                    cnt2++;
                }
                if(b%prime[j]==0){
                    b /= prime[j];
                    cnt3++;
                }
            }
            if(cnt1>max(cnt2, cnt3)){
                for(int ii=1;ii<=cnt1;ii++)
                    ans *= prime[j];

            }
        }

        printf("Case %lld: %lld\n", i, ans);
        //printf("%lld\n", prime.size());

    }

    return 0;
}
