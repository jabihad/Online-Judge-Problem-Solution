#include<bits/stdc++.h>
using namespace std;
int main()
{
    double a,b,c,d,e,f,g,h,s,ar,tr;
    int i,j,k,l,t;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
        e=abs(c-a);
        s=(b+d+e)/2.0;
        ar=sqrt(s*(s-b)*(s-d)*(s-e));
        h=(2*ar)/(e);
        tr=((a+c)*h)/2.0;
        printf("Case %d: %.8lf\n",i,tr);

    }


return 0;
}
