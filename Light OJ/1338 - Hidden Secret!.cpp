#include<bits/stdc++.h>
using namespace std;
int ara[200],wa[200];
int main()
{
    int i,j,k,l1,l2,m,n,t;
    char s[300],q[300];
    scanf("%d",&t);
    //cin>>t;
    getchar();
    for(i=1; i<=t; i++)
    {
        gets(s);
        for(j=0,l1=0; s[j]; j++)
        {
            if(s[j]==' ')continue;
            if(s[j]>='A'&&s[j]<='Z')
            {
                s[j]=s[j]+'a'-'A';
                ara[s[j]]++;l1++;
            }
            else
                ara[s[j]]++;l1++;
        }
        gets(q);
        for(j=0,l2=0; q[j]; j++)
        {
            if(q[j]==' ')continue;
            if(q[j]>='A'&&q[j]<='Z')
            {
                q[j]=q[j]+'a'-'A';
                wa[q[j]]++;l2++;
            }
            else
                wa[q[j]]++;l2++;
        }
        int c=0;
                for(j=97;j<=122;j++){
                    if(ara[j]!=wa[j])
                    {
                        c=1;break;
                    }
                }
                if(c==0)
                    printf("Case %d: Yes\n",i);

                else
                    printf("Case %d: No\n",i);
            for(j=97;j<=122;j++){
                    wa[j]=ara[j]=0;
                }



    }



    return 0;
}
