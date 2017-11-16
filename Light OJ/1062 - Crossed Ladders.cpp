#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, t, it;
    double x, y, c, w, p, q;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf",&x, &y, &c);
        double lo, hi, mid,dc;
        lo = 0;
        hi = max(x*x, y*y);
        it = 100;
        while(it--){
            mid = (lo + hi)/2;
            p = sqrt(x*x-mid*mid);
            q = sqrt(y*y-mid*mid);
            dc = 1/(1/p + 1/q);
            if(dc>c)
                lo = mid;
            else
                hi = mid;
        }
        printf("Case %d: %.10lf\n",i, lo);
    }
    return 0;
}

