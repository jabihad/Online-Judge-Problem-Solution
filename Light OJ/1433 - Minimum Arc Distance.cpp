#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,t;
    double ox,oy,ax,ay,bx,by;
    double r,o,a,b,c,ang,s;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf%lf%lf%lf",&ox,&oy,&ax,&ay,&bx,&by);
        r=sqrt((ox-ax)*(ox-ax)+(oy-ay)*(oy-ay));
        a=r;
        b=r;
        c=sqrt((ax-bx)*(ax-bx)+(ay-by)*(ay-by));
        //printf("%lf %lf %lf\n",a,b,c);
        ang=acos((a*a+b*b-c*c)/(2.0*a*b));
        s=r*ang;
        printf("Case %d: %.8lf\n",i,s);
    }

return 0;
}
