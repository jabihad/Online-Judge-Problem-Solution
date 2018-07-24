#include<bits/stdc++.h>
using namespace std;

int main()
{
    int i, j, k, t, n, u, v, sl, sr, x;
    bool left[101], right[101];

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        memset(left, false, sizeof(left));
        memset(right, false, sizeof(right));
        sl = sr = 0;
        scanf("%d", &n);
        for(j=1;j<=n;j++){
            scanf("%d%d%d", &u, &v, &x);
            if(right[u]==false && left[v]==false){
                sl += x;
                left[v] = right[u] = true;
            }
            else{
                sr += x;
                right[v] = left[u] = true;
            }
        }
        printf("Case %d: %d\n", i, min(sl, sr));
    }

    return 0;
}
