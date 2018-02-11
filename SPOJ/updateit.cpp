#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll tree[10100], n;
ll query(int idx)
{
    ll sum=0;
    while(idx>0){
        sum += tree[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int value)
{
    while(idx<=n){
        tree[idx] += value;
        idx += idx & (-idx);
    }
}
void range_update(int a, int b, int value)
{
    update(a, value);
    update(b+1, -value);
}
int main()
{
    int t, i, j, a, b, u, q, v, idx;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &u);
        memset(tree, 0, sizeof(tree));
        for(i=1;i<=u;i++){
            scanf("%d%d%d", &a, &b, &v);
            range_update(a+1, b+1, v);
        }
        scanf("%d",&q);
        for(i=1;i<=q;i++){
            scanf("%d", &idx);
            printf("%lld\n", query(idx+1));
        }
    }
    return 0;
}

