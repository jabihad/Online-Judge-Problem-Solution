#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,t,tl,ara[20];
    scanf("%d",&t);
    ara[0]=2;
    for(i=1;i<=t;i++){tl=0;
    scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%d",&ara[j]);
            l=ara[j]-ara[j-1];
            tl+=l/5;
            if(l%5)
            tl++;
        }
        printf("Case %d: %d\n",i,tl);
    }
return 0;
}
