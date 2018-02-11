#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll tree1[100005], tree2[100005];
int n;
ll query(ll* ft, int idx)
{
    ll sum = 0;
    while(idx>0)
    {
        sum += ft[idx];
        idx -= idx & (-idx);
    }
    return sum;
}
ll range_query(int i, int j)
{
    ll q1, q2;
    q1 = query(tree1, i-1) * (i-1) - query(tree2, i-1);
    q2 = query(tree1, j) * j - query(tree2, j);

    return q2-q1;
}
void update(ll* ft, int idx, ll v)
{
    while(idx<=n)
    {
        ft[idx] += v;
        idx += idx & (-idx);
    }
}
void range_update(int i, int j, ll v)
{
    update(tree1, i, v);
    update(tree1, j + 1, -v);
    update(tree2, i, v * (i - 1));
    update(tree2, j + 1, -v * j);
}

int main()
{
    int i, j, k, t, q, x, y, cmd;
    ll v;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {

        scanf("%d%d", &n, &q);

        memset(tree1, 0, sizeof tree1);
        memset(tree2, 0, sizeof tree2);

        while (q--)
        {
            scanf("%d%d%d", &cmd, &x, &y);
            if(cmd == 0)
            {
                scanf("%lld", &v);
                range_update(x, y, v);
            }
            else
                printf("%lld\n", range_query(x, y));
        }
    }
    return 0;
}

