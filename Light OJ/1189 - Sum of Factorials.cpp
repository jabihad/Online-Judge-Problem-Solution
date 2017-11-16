#include<bits/stdc++.h>
using namespace std;
long long int ara[10000],ans[789],c;

void fib()
{
    ara[0]=1;
    for(int i=1;i<=20;i++){
        ara[i]=i*ara[i-1];
        //if(ara[i]>=1000000000000000000)break;
    }
}
int main()
{
    long long int i,j,k,l,m,n,x;
    fib();
    scanf("%lld",&m);
    for(x=1;x<=m;x++){
    scanf("%lld",&n);
    for(i=20,j=0;i>=0;i--){
            if(ara[i]<=n){
                    ans[j++]=i;
                    n-=ara[i];
            }
            if(n<=0)break;
    }
    if(n==0){
        printf("Case %lld: ",x);
    for(i=j-1;i>=0;i--){
        printf("%lld!",ans[i]);
        if(i!=0)printf("+");
        }printf("\n");
    }
    else printf("Case %lld: impossible\n",x);
    }

return 0;
}
