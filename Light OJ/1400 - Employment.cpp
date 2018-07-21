#include<bits/stdc++.h>
using namespace std;

int Rank[300][300], cur[300], boy[300][300], girl[300][300], next[300];
int main()
{
    int i, j, k, l, m, n, t, b, g;
    queue<int> q;

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        memset(cur, 0, sizeof(cur));

        for(j=1;j<=n;j++){
            for(k=1;k<=n;k++){
                scanf("%d", &boy[j][k]);
            }
            q.push(j);
            next[j] = 1;
        }

        for(j=n+1;j<=2*n;j++){
            for(k=1;k<=n;k++){
                scanf("%d", &girl[j][k]);
                Rank[j][girl[j][k]] = k;
            }
        }

        while(!q.empty()){
            b = q.front();
            g = boy[b][next[b]++];
            if(cur[g]==0){
                cur[g] = b;
                q.pop();
            }
            else if(Rank[g][b]<Rank[g][cur[g]])
            {
                q.pop();
                q.push(cur[g]);
                cur[g] = b;
            }
        }
        printf("Case %d: ", i);
        for(j=n+1;j<=2*n;j++){
            printf("(%d %d)", cur[j], j);
            if(j<2*n)
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}
