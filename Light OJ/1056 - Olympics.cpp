#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, t;
    double l, w, s, r, angle, on;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf : %lf",&l, &w);
        r = sqrt((l/2)*(l/2) + (w/2)*(w/2));
        angle = atan(w/l);
        s = r * 2 * angle;
        on = 400/(2*l + 2*s);
        l = l * on;
        w = w * on;
        printf("Case %d: %.8lf %.8lf\n",i, l, w);
    }
    return 0;
}
