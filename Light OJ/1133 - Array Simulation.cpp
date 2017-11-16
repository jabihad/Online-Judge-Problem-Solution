#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l,m,n,t,x,d,y,z,n1,i1;
    char ch;

    scanf("%d",&t);
    for(i1=1;i1<=t;i1++){
        vector<int>v;
        scanf("%d%d",&n,&m);n1=n;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            v.push_back(x);

        }
        while(m--){
        cin>>ch;
        if(ch=='S'){
            scanf("%d",&d);
            for(i=0;i<n;i++)
                v[i]+=d;
        }
        else if(ch=='M'){
            scanf("%d",&d);
            for(i=0;i<n;i++)
                v[i]*=d;
        }
        else if(ch=='D'){
            scanf("%d",&d);
            for(i=0;i<n;i++)
                v[i]/=d;
        }
        else if(ch=='R')
            reverse(v.begin(),v.end());
        else if(ch=='P'){
            scanf("%d%d",&y,&z);
            swap(v[y],v[z]);
        }
        }
        printf("Case %d:\n",i1);
        for(j=0;j<n;j++){
             printf("%d",v[j]);
                if(j!=n-1)
                    printf(" ");
        }printf("\n");
    }
return 0;
}
