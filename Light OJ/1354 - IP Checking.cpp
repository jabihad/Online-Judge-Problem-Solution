#include<bits/stdc++.h>
using namespace std;

int b2d(char s[])
{
    int i,j,k,l,m=0;
    l=strlen(s);
    for(i=l-1,j=0;i>=0;i--,j++){
        m=m+(s[i]-48)*pow(2,j);
    }
return m;
}

int main()
{
    int a[78],b,c,d,a1[78],b1,c1,d1,i,j,k,l,m,n,t,x;
    char ch;
    scanf("%d",&t);
    for(i=1;i<=t;i++){x=0;
    scanf("%d%c%d%c%d%c%d",&a[0],&ch,&a[1],&ch,&a[2],&ch,&a[3]);
    scanf("%d%c%d%c%d%c%d",&a1[0],&ch,&a1[1],&ch,&a1[2],&ch,&a1[3]);
    for(j=0;j<4;j++){
    char s[78];
    sprintf(s,"%d",a1[j]);
    l=b2d(s);//printf("%d\n",l);
    if(l==a[j])x++;
    }
    //cout<<endl<<x<<endl;
    if(x==4)
        printf("Case %d: Yes\n",i);
    else
        printf("Case %d: No\n",i);




    }

return 0;
}
