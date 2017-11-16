#include<bits/stdc++.h>

using namespace std;
int main()
{
    long long int c,i,j,n,m,k,r,on,sum,t,sum_n=0,sum_m,a,p,sum1,sum2;

    cin>>t;
    for(i=1;i<=t;i++){sum=c=0;
    cin>>n>>m;
    sum_m=0;
    sum_n=(n*(n+1))/2;
    sum=(m*(m+1)+(n/(2*m)-1)*2*m*m)*(n/(2*m));
    //printf("%lld\n",sum);



//printf("%lld %lld\n",sum1,sum2);
   printf("Case %lld: %lld\n",i,sum_n-sum);

    }

return 0;
}
