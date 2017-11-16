#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int i,j,k,l,m,n,t,a,y;
    long long int x,z;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lld",&a);
        if(a%2==1)
            printf("Case %lld: Impossible\n",i);
        else
        {
            for(j=2; j<=a; j*=2)
            {
                x=a/j;


                if(x%2==1)
                {
                    printf("Case %lld: %lld %lld\n",i,x,j);
                    break;
                }
            }

        }
    }

    return 0;
}

