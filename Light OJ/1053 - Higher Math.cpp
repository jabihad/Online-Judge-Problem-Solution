#include<stdio.h>

int main()
{
    int a,b,c,i,n;
    scanf("%d",&n);
    long long int ara[n],ara2[n],ara3[n];

    for(i=0; i<n; i++)
    {
        scanf("%lld %lld %lld",&ara[i],&ara2[i],&ara3[i]);
    }

    for(i=0; i<n; i++)
    {
        if((ara[i]*ara[i]==ara2[i]*ara2[i]+ara3[i]*ara3[i])||(ara2[i]*ara2[i]==ara[i]*ara[i]+ara3[i]*ara3[i])||(ara3[i]*ara3[i]==ara2[i]*ara2[i]+ara[i]*ara[i]))
            printf("Case %d: yes\n",i+1);
        else
        {
            printf("Case %d: no\n",i+1);
        }
    }
    return 0;
}
