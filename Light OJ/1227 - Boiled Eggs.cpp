#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,t,p,q,x,sum;

    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&n,&p,&q);vector<int>v;
        for(j=0;j<n;j++){
            scanf("%d",&x);
            v.push_back(x);
        }
        sort(v.begin(),v.end());
        sum=0;
        for(j=0,k=1;j<n;j++,k++){
            sum+=v[j];
            if(sum>q||k>p)
                break;
        }
        printf("Case %d: %d\n",i,k-1);
    }


return 0;
}
