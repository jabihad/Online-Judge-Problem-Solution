#include<bits/stdc++.h>
using namespace std;
int main()
{
   int i,j,k,l,m,n,t,d,has,sc,x;
   char ch[567];
   scanf("%d",&t);
   for(i=1;i<=t;i++){
    scanf("%d",&n);
    d=has=sc=0;
    scanf("%s",ch);
    x=strlen(ch);
    for(j=0;ch[j];j++){
            if(ch[j]=='.')
                d++;
       else if(ch[j]=='#')
                has++;

            if(d==0&&has==1)
                has--;
       else if((d==2&&has==1)||(d==1&&has==2)){
                sc++;d=has=0;
            }
       else if(d==3&&has==0){
                sc++;d=has=0;}
       else if((d==2||d==1)&&(has==0||has==1)&&j==x-1){
                sc++;d=has=0;
       }

       }



    printf("Case %d: %d\n",i,sc);
}



return 0;
}
