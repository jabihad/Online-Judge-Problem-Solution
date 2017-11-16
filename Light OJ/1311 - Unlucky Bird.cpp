#include<bits/stdc++.h>
using namespace std;

int main()
{
    double v1,v2,v3,a1,a2,a3,d,x;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf%lf%lf",&v1,&v2,&v3,&a1,&a2);
        d=(v1*v1)/(2*a1)+(v2*v2)/(2*a2);
        x=max(v1/a1,v2/a2)*v3;
        printf("Case %d: %.10lf %.10lf\n",i,d,x);
    }

return 0;
}
