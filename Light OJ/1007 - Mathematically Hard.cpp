#include<bits/stdc++.h>
#define ll unsigned long long
#define maxx 5000003
using namespace std;
ll phi[maxx];
void sievephi()
{
    ll i,j;
    for(i=1;i<=maxx;i++)phi[i]=i;
    phi[1]=1;
    for(i=2;i<=maxx;i++){
        if(phi[i]==i){
        for(j=i;j<=maxx;j+=i){
            phi[j]=(phi[j]/i)*(i-1);
            }
        }
    }
    for(i=2;i<=maxx;i++){
        phi[i] *= phi[i];
        phi[i]+=phi[i-1];
    }
}
int main()
{
    sievephi();
    ll i,j,k,a,b,t;
    scanf("%llu",&t);
    for(i=1;i<=t;i++){
      scanf("%llu%llu",&a,&b);
      if(a>b)swap(a,b);
      printf("Case %llu: %llu\n",i,phi[b]-phi[a-1]);
    }
return 0;
}
