#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,k,l,m,n,s,t,y,r,c;
    double x,z;
    cin>>t;
    for(i=1;i<=t;i++){
       cin>>s;
       x=ceil(sqrt(s));
       y=x*x;
       if(y%2==0){
        if(y-s<=x-1){
            c=x;
            r=y-s+1;
        }
        else{
            c=s-(x-1)*(x-1);
            r=x;
        }
       }
       else{
            if(y-s<=x-1){
                c=y-s+1;
                r=x;
            }
            else{
                c=x;
                r=s-(x-1)*(x-1);
            }

       }
   printf("Case %lld: %lld %lld\n",i,c,r);

    }

return 0;
}
