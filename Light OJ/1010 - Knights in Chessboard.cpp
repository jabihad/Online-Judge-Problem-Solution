#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i,j,k,l,m,n,t,r,x,y;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&m,&n);
        if(m==1||n==1){
            r=m*n;
        }
        else if(m==2){
            if(n%2==1)
                r=m*((n+1)/2);
            else{
                x=n/2;
                if(x%2==1)
                    r=m*(x+1);
                else
                    r=m*x;
            }
        }
        else if(n==2){
            if(m%2==1)
                r=n*((m+1)/2);
            else{
                x=m/2;
                if(x%2==1)
                    r=n*(x+1);
                else
                    r=n*x;
            }
        }

        else{
            r=(m*n+1)/2;
        }

        printf("Case %d: %d\n",i,r);
    }

return 0;
}
