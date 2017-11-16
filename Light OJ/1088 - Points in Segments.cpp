#include<bits/stdc++.h>
using namespace std;

int ara[100100];
int main()
{
    int i, j, t, n, q, a, b, x;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n, &q);
        for(j=0;j<n;j++)
            scanf("%d",&ara[j]);

        printf("Case %d:\n",i);
        for(j=0;j<q;j++){
            scanf("%d%d",&a,&b);
            a = lower_bound(ara,ara+n,a)-ara;
            b = upper_bound(ara+a,ara+n,b)-ara;
            printf("%d\n",b-a);
        }

    }
    return 0;

}
