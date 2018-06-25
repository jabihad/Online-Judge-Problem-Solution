#include<bits/stdc++.h>
#define sz 100010
using namespace std;

int ara[sz];
struct st
{
    int mn, mx;
} tree[sz*3];

void init(int node, int b, int e)
{
    if(b == e){
        tree[node].mn = ara[b];
        tree[node].mx = ara[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].mn = min(tree[Left].mn, tree[Right].mn);
    tree[node].mx = max(tree[Left].mx, tree[Right].mx);
}
int mn_query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MAX;
    if (b >= i && e <= j)
        return tree[node].mn;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = mn_query(Left, b, mid, i, j);
    int p2 = mn_query(Right, mid + 1, e, i, j);
    return min(p1, p2);

}
int mx_query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MIN;
    if (b >= i && e <= j)
        return tree[node].mx;
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = mx_query(Left, b, mid, i, j);
    int p2 = mx_query(Right, mid + 1, e, i, j);
    return max(p1, p2);

}

int main()
{
    int i, j, k, t, n, d, ans=0;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d", &n, &d);
        for(j=1;j<=n;j++)
            scanf("%d", &ara[j]);
        init(1, 1, n);
        ans = 0;
        for(j=1;j<=n-d+1;j++)
            ans = max(ans, abs(mn_query(1, 1, n, j, j+d-1)-mx_query(1, 1, n, j, j+d-1)));
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}

