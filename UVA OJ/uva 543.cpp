#include<bits/stdc++.h>
using namespace std;
int mark[1000000],nprime,prime[100000];

void sieve ()
{
    int i,j,n=1000000,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4;i<=n;i+=2)mark[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i]){
            prime[nprime++]=i;
            if(i<=limit){
                for(j=i*i;j<=n;j+=2*i){
                    mark[j]=1;
                }
            }
        }
    }
}
int main()
{
    sieve();
    int n,c;
    while(1){
        scanf("%d",&n);
        c=0;
        if(n==0)break;
        for(int i=1,j=n-1;i<=n/2;i++,j--){
           if(mark[i]==0 && mark[j]==0 && i%2==1&& j%2==1){
            printf("%d = %d + %d\n",n,i,j);break;
           }

        }

        //printf("%d\n",c);
    }
return 0;
}


