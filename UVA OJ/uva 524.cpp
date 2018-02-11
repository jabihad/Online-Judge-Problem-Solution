#include<bits/stdc++.h>
using namespace std;
int mark[1000],nprime,prime[1000];
void sieve (int n)
{
    int i,j,limit=sqrt(n*1.)+2;
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
int used[200],number[200],r[34];
void permutation(int at,int n)
{
    int i,c = 0;
    if(at==n+1 && mark[1+number[n]]==0){
           printf("1");
        for(i=2;i<=n;i++)
            printf(" %d",number[i]);
        printf("\n");
        return;
    }
    for(i=2;i<=n;i++)if(!used[i]){
        if(mark[number[at-1]+i]==0){
        used[i] = 1;
        number[at] = i;
        permutation(at+1,n);
        used[i] = 0;
        }
    }
}
int main()
{
    int i=0,j,n;
    sieve(100);
    while(scanf("%d",&n)!=EOF){
        if(i>0)printf("\n");
        printf("Case %d:\n",++i);
        number[1] = 1;
        permutation(2,n);
        for(j=0;j<100;j++)number[j]=used[j]=0;

    }
return 0;
}

