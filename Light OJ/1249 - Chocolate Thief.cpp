#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,z,h,m,n,t,v[101],w[101],x,y;
    char s[101][21];
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        for(j=1;j<=n;j++){
            scanf("%s%d%d%d",s[j],&l,&z,&h);
            v[j]=l*z*h;
            w[j]=v[j];
        }
        sort(w+1,w+n+1);
        for(j=1;j<=n;j++){
              if(w[1]==v[j])
                x=j;
              if(w[n]==v[j])
                y=j;
        }
        if(w[1]==w[n])
            printf("Case %d: no thief\n",i);

        else
            printf("Case %d: %s took chocolate from %s\n",i,s[y],s[x]);


    }


return 0;
}
