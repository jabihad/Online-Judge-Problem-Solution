#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ax,ay,bx,by,cx,cy,dx,dy,n,i;
    int a;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
    scanf("%d%d%d%d%d%d",&ax,&ay,&bx,&by,&cx,&cy);
    if(bx>cx)
        dx=ax-(bx-cx);
    else
        dx=ax+(cx-bx);
    if(ay<by)
        dy=cy-(by-ay);
    else
        dy=cy+(ay-by);

    a=abs(ax*(by-cy)+bx*(cy-ay)+cx*(ay-by));
    printf("Case %d: %d %d %d\n",i,dx,dy,a);

    }

return 0;
}
