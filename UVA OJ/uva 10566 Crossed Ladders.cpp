#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, t, it;
    double x, y, c, w, p, q;
    while(scanf("%lf%lf%lf",&x, &y, &c)!=EOF)
    {
        double lo, hi, mid,dc;
        lo = 0;
        hi = max(x*x, y*y);
        it = 100;
        while(it--)
        {
            mid = (lo + hi)/2;
            p = sqrt(x*x-mid*mid);
            q = sqrt(y*y-mid*mid);
            dc = 1/(1/p + 1/q);
            if(dc>c)
                lo = mid;
            else
                hi = mid;
        }
        printf("%.3lf\n",lo);

    }
    return 0;
}

