#include<bits/stdc++.h>
#define mx 100100
using namespace std;

int tree[3*mx], ara[mx];

void init(int node, int b, int e)
{
    if(b==e)
    {
        tree[node] = ara[b];
        return;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    init(left, b, mid);
    init(right, mid+1, e);
    tree[node] = tree[left] + tree[right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i > e || j < b)
        return 0;
    else if(b >= i && e <= j)
        return tree[node];
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    int p1 = query(left, b, mid, i, j);
    int p2 = query(right, mid+1, e, i, j);
    return p1+p2;
}
void update(int node, int b, int e, int i, int newvalue, int type)
{
    if(b > i || e < i)
        return;
    else if(b >= i && e <= i)
    {
        if(type)
            tree[node] += newvalue;
        else
            tree[node] = 0;
        return ;
    }
    int left = node << 1;
    int right = (node << 1) + 1;
    int mid = (b+e) >> 1;
    update(left, b, mid, i, newvalue, type);
    update(right, mid+1, e, i,newvalue, type);
    tree[node] = tree[left] + tree[right];
}
int main()
{
    int t, i,j, n, q, a, b, c, res;

    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {

        scanf("%d%d",&n, &q);

        for(j=0; j<n; j++)
            scanf("%d",&ara[j]);
        init(1, 0, n-1);
        printf("Case %d:\n", i);
        for(j=1; j<=q; j++)
        {
            scanf("%d", &a);
            if(a==1)
            {
                scanf("%d",&b);
                res = query(1, 0, n-1, b, b);
                update(1, 0, n-1, b, 0, 0);
                printf("%d\n", res);
            }
            else if(a==2)
            {
                scanf("%d%d", &b, &c);
                update(1, 0, n-1, b, c, 1);
            }
            else if(a==3)
            {
                scanf("%d%d", &b, &c);
                res = query(1, 0, n-1, b, c);
                printf("%d\n", res);
            }
        }
    }
    return 0;
}
