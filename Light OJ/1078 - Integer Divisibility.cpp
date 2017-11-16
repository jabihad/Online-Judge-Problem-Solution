#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j=0, k, l, m, n, t, d, r, tmp;
    scanf("%d",&t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d",&n, &d);
        tmp = d;
        j = 0;
        while(1)
        {
            r = tmp%n;
            if(r==0)break;
            r *= 10;
            tmp = d+r;
            j++;
        }
        printf("Case %d: %d\n",i, j+1);
    }

    return 0;
}

