#include<bits/stdc++.h>
using namespace std;

double sum[1000010],res;
void f()
{
    sum[0]=0;
    for(int i=1;i<=1000000;i++)
       sum[i]=sum[i-1]+log10(i);
}
int main()
{
    int i,j,k,l,m,t,n,b,ans;
    scanf("%d",&t);
    f();
    for(i=1;i<=t;i++){
        scanf("%d%d",&n,&b);
        res=sum[n];
        res=(res/log10(b))+1;
        ans=res;
        printf("Case %d: %d\n",i,ans);


    }


return 0;
}
