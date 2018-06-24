#include<bits/stdc++.h>
#define sz 30010
using namespace std;

int ara[sz], tree[sz*3], n;

void init(int node, int b, int e)
{
    if(b == e){
        tree[node] = b;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    if(ara[tree[Left]] < ara[tree[Right]])
        tree[node] = tree[Left];
    else tree[node] = tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return -1;
    if(b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid+1, e, i, j);
    if(p1 == -1)return p2;
    if(p2 == -1)return p1;
    if(ara[p1] < ara[p2])
        return p1;
    return p2;

}
int area(int b, int e)
{
    if(b > e)
        return 0;
    if(b == e)
        return tree[b];
    int mnIndex = query(1, 1, n, b, e);
    int ans = max(area(b, mnIndex-1), area(mnIndex + 1, e));
    return ans = max(ans, (e-b+1)*ara[mnIndex]);
}
int main()
{
    int i, j, k, t, ans;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d", &n);
        for(j=1;j<=n;j++)
            scanf("%d", &ara[j]);
        init(1, 1, n);
        ans = area(1, n);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
