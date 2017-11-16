#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,l,m,n,t,a,b,c,sum=0,r=0;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&a,&b);
        r=(b-a+1)-(ceil(b/3.0)-ceil((a-1)/3.0));
        printf("Case %d: %d\n",i,r);

    }



return 0;
}
