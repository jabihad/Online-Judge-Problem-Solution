#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;

    scanf("%d",&n);

    double ara[n],ci[n],sq[n],pi=2*(acos(0.0));
    for(i=0; i<n; i++)
    {
        scanf("%lf",&ara[i]);
    }
    for(i=0; i<n; i++)
    {
        sq[i]=4*ara[i]*ara[i];
        ci[i]=pi*ara[i]*ara[i];
        printf("Case %d: %.2lf\n",i+1,sq[i]-ci[i]);
    }

    return 0;
}
