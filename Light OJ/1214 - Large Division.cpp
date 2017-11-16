#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k=0,l,m,n,r=0,va[56789],b,t,x;
    char s[23456];
    scanf("%lld",&t);
    for(x=1;x<=t;x++){r=0;k=0;
    scanf("%s%lld",s,&b);
    if(b<0)b=-b;
    if(s[0]=='-')k=1;
    for(i=k,j=0;s[i];i++,j++){
        va[j]=(r*10+(s[i]-48))/b;
        r=(r*10+(s[i]-48))%b;
    }
    if(r==0)
         printf("Case %lld: divisible\n",x);
    else
         printf("Case %lld: not divisible\n",x);
    }
return 0;
}
