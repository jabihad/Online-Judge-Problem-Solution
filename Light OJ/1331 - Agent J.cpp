#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1.0)
int main()
{
    int i,t;
    double r1,r2,r3,a,b,c,A,B,C,tri,area;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf",&r1,&r2,&r3);
        a=r1+r2;
        b=r2+r3;
        c=r3+r1;
        A=acos((b*b+c*c-a*a)/(2*b*c));
        B=acos((c*c+a*a-b*b)/(2*a*c));
        C=acos((b*b+a*a-c*c)/(2*b*a));
        tri=(b*c*sin(A))/2.0;
        area=tri-(pi*r3*r3*A)/(2*pi)-(pi*r1*r1*B)/(2*pi)-(pi*r2*r2*C)/(2*pi);
        printf("Case %d: %.10lf\n",i,area);

    }
return 0;
}
