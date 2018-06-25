#include<bits/stdc++.h>
using namespace std;

double ara[100100];
int main()
{
    int i, j, k, t, n=0, rem;
    double ans;

    for(i=1,k=1;i<=100000;i++){
        for(j=1;j<=1000;j++,k++){
            ara[i] += 1.0/(k*1.0);
        }
        ara[i] += ara[i-1];
    }
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        ans = 0;
        scanf("%d", &n);
        ans += ara[n/1000];
        rem = n%1000;
        k = (n/1000)*1000 + 1;
        for(j=k;j<=n;j++)
            ans += 1.0/(j*1.0);

        printf("Case %d: %.10lf\n", i, ans);
    }

return 0;
}
