#include<bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,k,l,m,n,t,s,d;
    char ara[789];
    cin>>t;
    for(i=1;i<=t;i++){

        cin>>n;
        d=0;
        for(j=1;j<=n;j++){
            cin>>s;
            if(s>0)
                d+=s;
        }
        printf("Case %d: %d\n",i,d);

    }
return 0;
}
