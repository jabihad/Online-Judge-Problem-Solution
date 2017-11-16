#include<bits/stdc++.h>
using namespace std;
int mark[210],nprime,prime[100],ara[111];
set<int>s;
set <int>::iterator it;
void sieve ()
{
    int i,j,n=200,limit=sqrt(n*1.)+2;
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
    int i,j,k,t,n,x,y,z,l;
    scanf("%d",&t);
    sieve();
    for(i=1;i<=t;i++){
        memset(ara,0,sizeof ara);
        scanf("%d",&n);
        for(j=2;j<=n;j++){
            y = j;
            for(k=0;prime[k]<=n;k++){
                while(y%prime[k]==0){
                    ara[prime[k]]++;
                    y /= prime[k];
                    s.insert(prime[k]);
                }
            }
        }
        x = s.size();
        printf("Case %d: %d = ",i,n);
        for(it=s.begin(),j=1;it!=s.end();it++,j++){
            printf("%d (%d)",*it,ara[*it]);
            if(j<x)
                printf(" * ");
            else printf("\n");
        }
        s.clear();
    }
return 0;
}
