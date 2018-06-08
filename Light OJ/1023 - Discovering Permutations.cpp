#include<bits/stdc++.h>
using namespace std;

int main()
{
    char ch[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int c=0, n, m, t, i, j;
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        int ara[27] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};
        c = 0;
        scanf("%d%d", &n, &m);

        printf("Case %d:\n", i);
        do
        {
            for(j=0; j<n; j++)
                printf("%c", ch[ara[j]]);

            printf("\n");

            c++;
            if(c==m)break;
        }
        while(next_permutation(ara, ara+n));

    }

    return 0;
}

