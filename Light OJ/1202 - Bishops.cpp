#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r1,c1,r2,c2,t,s=0,i;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
    scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
    s=0;
    if((r1+c1)%2==0&&(r2+c2)%2==0){
        if(abs(r1-r2)==abs(c1-c2))
            s=1;

        else
            s=2;
    }
    else if((r1+c1)%2==1&&(r2+c2)%2==1){
        if(abs(r1-r2)==abs(c1-c2))
            s=1;

        else
            s=2;
    }
    else
        s=0;
    if(s==0)
        printf("Case %d: impossible\n",i);
    else
        printf("Case %d: %d\n",i,s);

    }


return 0;
}
