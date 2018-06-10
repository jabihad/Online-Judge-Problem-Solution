#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, l, m, n, t, T1, T2, c, x, y;

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d", &n, &c);
        printf("Case %d: ", i);
        if(n==0)
           printf("0\n");
        else{

            T1 = c/(2*n);
            T2 = c/(2*n)+1;
            x = T1 * (c-n*T1);
            y = T2 * (c-n*T2);
            if(x>=y)
                printf("%d\n", T1);
            else
                printf("%d\n", T2);
        }
    }


    return 0;
}

