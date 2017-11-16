#include<bits/stdc++.h>
#define ll long long int
using namespace std;
vector<ll> v;
int main()
{
    ll t,p,l,i,j,limit,c,q,x;
    scanf("%lld",&t);
    for(i=1;i<=t;i++){
        c=0;v.clear();
        scanf("%lld%lld",&p,&l);
        p-=l;q = p;
        limit = sqrt(p)+1;
        for(j=1;j<limit;j++){
               if(q%j==0){
                    x = q/j;
               if(x>l)
                 v.push_back(x),c=1;
               if(j>l&&j!=x)
                 v.push_back(j),c=1;
               }
        }
        sort(v.begin(),v.end());
        if(c==0)
            printf("Case %lld: impossible",i);
        else{
            printf("Case %lld: ",i);
            for(j=0;j<v.size();j++){
                if(j<v.size()-1)
                    printf("%lld ",v[j]);
                else
                    printf("%lld",v[j]);
            }
        }
        printf("\n");
    }
return 0;
}
