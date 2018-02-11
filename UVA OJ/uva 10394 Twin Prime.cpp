#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
using namespace std;
ll mark[30000000],nprime=1,prime[20001000],tp,tprime[20001000];
vector<pii> p;
void sieve ()
{
    ll n=20005000,i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4;i<=n;i+=2)mark[i]=1;

    for(i=3;i<=n;i+=2)
    {
        if(!mark[i]){
            prime[nprime]=i;
            if(abs(prime[nprime]-prime[nprime-1])==2){
                p.push_back(pii(prime[nprime-1],prime[nprime]));
                tp++;
            }
            if(i<=limit){
                for(j=i*i;j<=n;j+=2*i){
                    mark[j]=1;
                }
            }nprime++;
        }
    }
}
int main()
{
    sieve();
    ll n,i,j=0;

    while(scanf("%lld",&n)!=EOF){
        printf("(%lld, %lld)\n",p[n-1].first,p[n-1].second);
    }
return 0;
}







