#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, t, m;
    scanf("%d",&t);
    char name[45];
    for(i=1;i<=t;i++){
        scanf("%d%s",&m, name);
        if(strcmp(name,"Bob")==0){
            if(m%3==0)
                printf("Case %d: Alice\n",i);
            else
                printf("Case %d: Bob\n",i);
        }
        else{
            if(m%3==1)
                printf("Case %d: Bob\n",i);
            else
                printf("Case %d: Alice\n",i);
        }
    }

    return 0;
}
