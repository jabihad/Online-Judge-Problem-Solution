#include<bits/stdc++.h>
using namespace std;
int ara[4000],che[4000];
int main()
{
    int i,j,k,l,m,n,p,t,w,x,y,z,c;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d%d%d",&n,&m,&w);
        for(j=1,y=1;j<=n;j++){
            for(k=1;k<=w;k++,y++){
                scanf("%d",&x);
                ara[y]=x;
            }
        }
        scanf("%d",&p);
        for(k=1;k<=p;k++){
            scanf("%d",&x);
            che[x]=1;
        }
        c=0;
        for(j=1,y=1;j<=n;j++){
            for(k=1,z=0;k<=w;k++,y++){
                 if((ara[y]<0&&che[abs(ara[y])]==0)||(ara[y]>0&&che[abs(ara[y])]==1))
                 z++;
            }
            if(z==0){c=1;break;}
        }
        if(c==1)
            printf("Case %d: No\n",i);
        else
            printf("Case %d: Yes\n",i);
for(j=0;j<4000;j++){ara[j]=che[j]=0;}

    }
return 0;
}
