#include<bits/stdc++.h>
using namespace std;

int nprime,prime[665000];
bitset<10000009> mark;
void sieve (int n)
{
    int i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4; i<=n; i+=2)mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=2*i)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
int main()
{
    int i, j, k, t, n, cnt=0;

    sieve(10000000);
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        cnt = 0;
        for(j=0;j<nprime && prime[j]<=n/2;j++){
            if(n>=prime[j]){
                if(mark[n-prime[j]]==0)
                    cnt++;
            }
        }
        printf("Case %d: %d\n", i, cnt);
    }

return 0;
}
