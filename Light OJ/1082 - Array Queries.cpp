#include<bits/stdc++.h>
using namespace std;
#define mx 100050

int arr[mx];
int tree[mx*3];

void init(int node, int b, int e)
{
    if(b==e){
        tree[node] = arr[b];
        return;
    }
    int Left = 2*node;
    int Right = 2*node+1;
    int mid = (b+e)/2;
    init(Left, b, mid);
    init(Right, mid+1, e);
    tree[node] = min(tree[Left], tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return mx;
    if(b >= i && e <= j)
        return tree[node];
    int Left = node*2;
    int Right = node*2+1;
    int mid = (b+e)/2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid+1, e, i, j);
    return min(p1, p2);
}
int main()
{
    int i, j, n, t, q, a, b, res;
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        scanf("%d%d",&n, &q);
        for(j=1;j<=n;j++)
            scanf("%d", &arr[j]);
        init(1, 1, n);
        printf("Case %d:\n",i);
        for(j=1;j<=q;j++){
            scanf("%d%d",&a, &b);
            res = query(1, 1, n, a, b);
            printf("%d\n",res);
        }
    }

    return 0;
}

