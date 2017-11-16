#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t, i, j;
    double ab, ac, bc, r, ad;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%lf%lf%lf%lf",&ab, &ac, &bc, &r);
        ad = ab * sqrt(r/(1+r));
        printf("Case %d: %.10lf\n", i, ad);
    }

    return 0;
}
