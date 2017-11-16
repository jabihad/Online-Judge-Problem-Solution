#include<bits/stdc++.h>
using namespace std;
int ara[200],wa[200];
int main()
{
    int i,j,k,l,m,n,t,d=0;
    char s[100];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);d=0;k=1;
        printf("Case %d:\n",i);
        for(j=1;j<=n;j++){

        scanf("%s",s);
        if(s[0]=='d'){scanf("%d",&m);d+=m;}
        else {printf("%d\n",d);}

    }
    }

    return 0;
}
