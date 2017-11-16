#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    double r1,r2,h,p,v;
    int i,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
            scanf("%lf%lf%lf%lf",&r1,&r2,&h,&p);
        r1=r1-((r1-r2)*(h-p))/h;
        v=(p*pi*(r1*r1+r1*r2+r2*r2))/3.0;
        printf("Case %d: %.9lf\n",i,v);
    }
return 0;
}
