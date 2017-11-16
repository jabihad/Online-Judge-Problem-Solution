#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x1,x2,y1,y2,m,n,t,c,x,y,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        scanf("%d",&c);
        printf("Case %d:\n",i);
        while(c--){
            scanf("%d%d",&x,&y);
            if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }

return 0;
}

