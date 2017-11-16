#include<bits/stdc++.h>
using namespace std;
char ara[67123];
void d2b(int n)
{   int i=1,j,k,l;
    for(i=0;; i++)
    {   ara[i]=(n%2)+'0';
        n/=2;
        if(n==0)
        {ara[i+1]='0';ara[i+2]='\0';break;}
    }
}
int b2d(char n[])
{   int i,j,k,l,x=0;
    l=strlen(n);
    for(i=0;n[i];i++){
        x+=(n[i]-48)*pow(2,i);
    }
return x;
}
int main()
{
    int i,j,k,l,m,n,c=0,zero=0,one=0,x,y,z,d,qw;
    scanf("%d",&n);
    for(z=1;z<=n;z++){
            scanf("%d",&x);d=0;
    d2b(x);
    zero=one=c=0;
    for(i=0;ara[i];i++){
        if(ara[i]=='1'&&ara[i+1]=='0'){
            ara[i]='0';ara[i+1]='1';k=i-1;/*printf("k = %d ",k);*/i++;break;
        }

    }
    for(i=k;i>=0;i--){
        if(ara[i]=='1')one++;
        else zero++;
    }
    //printf("%d %d\n",zero,one);//if(d==1)zero--;
    for(i=k,j=1;j<=zero;j++,i--)
        ara[i]='0';
    for(k=i,j=1;j<=one;j++,k--)
        ara[k]='1';
    /*for(i=strlen(ara);i>=0;i--)
    printf("%c",ara[i]);
    printf("\n");*/
    y=b2d(ara);
    printf("Case %d: %d\n",z,y);

    }
    return 0;
}
