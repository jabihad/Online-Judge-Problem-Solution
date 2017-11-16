#include<bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,k,lp,mp,n,t,s,d,et;
    cin>>t;
    for(i=1;i<=t;i++){
        cin>>mp>>lp;
        et=0;
    if(lp>=mp){
        et=lp*4+19;
    }

    else{
        et=(mp-lp+mp)*4+19;
    }
 printf("Case %d: %d\n",i,et);


    }
return 0;
}
