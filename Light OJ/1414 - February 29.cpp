#include<bits/stdc++.h>
using namespace std;
bool ly(long long int k)
{
    if(k%400==0||(k%100!=0&&k%4==0))
        return true;

    return false;
}
int main()
{
    long long int i,j,k,l,m,n,t,d1,d2,y1,y2,x1,x2,y;
    char s1[78],s2[78],ch;
    scanf("%lld",&t);
    for(i=1; i<=t; i++)
    {
        l=0;
        scanf("%s%lld%c%lld",s1,&d1,&ch,&y1);
        scanf("%s%lld%c%lld",s2,&d2,&ch,&y2);
        l=(y2/4-y2/100+y2/400)-(y1/4-y1/100+y1/400);
        if(ly(y1)==true)l++;
        if(ly(y1)==true)
        {
            if((strcmp(s1,"January")!=0)&&strcmp(s1,"February")!=0)
                l--;
        }
        if(ly(y2)==true)
        {
            if(strcmp(s2,"January")==0)
            {
                l--;
            }
            else if(strcmp(s2,"February")==0)
            {
                if(d2<=28)
                {
                    l--;
                }
            }
        }
        printf("Case %lld: %lld\n",i,l);
    }
    return 0;
}
