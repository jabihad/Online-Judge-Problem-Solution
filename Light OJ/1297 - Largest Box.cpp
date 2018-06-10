#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i, j, k, t;
    double a, b, c, ans, l, w, x;

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf", &l, &w);
        a = 12.0;
        b = -4.0 * (l+w);
        c = l*w;
        x = (-b - sqrt (b*b - 4.0*a*c)) / (2.0*a);
        ans = (l - 2*x) * (w - 2*x) * x;
        printf ("Case %d: %lf\n", i, ans);
    }

    return 0;
}

