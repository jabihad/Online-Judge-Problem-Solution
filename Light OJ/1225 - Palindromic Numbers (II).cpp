#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,j,k,l,m,n,o,p,q,r,t;
    char s[2097];
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
       scanf("%s",s);r=0;
       l=strlen(s);
       for(j=0,k=l-1;j<l/2;j++,k--){
        if(s[j]==s[k])
            r++;
       }
       if(r==l/2)
        printf("Case %d: Yes\n",i);
       else
        printf("Case %d: No\n",i);

    }


return 0;
}
