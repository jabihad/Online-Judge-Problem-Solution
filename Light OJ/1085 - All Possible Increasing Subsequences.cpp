#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int tree[100100], a[100100], n, cnt;
int query(int idx)
{
    int sum = 0;
    while(idx>0){
        sum = (sum + tree[idx]) % MOD;
        idx -= idx & (-idx);
    }
    return sum;
}
void update(int idx, int value)
{
    while(idx<=n){
        tree[idx] = (tree[idx] + value) % MOD;
        idx += idx & (-idx);
    }
}
int main()
{
    int i, j, k, t, res, ans;

    scanf("%d", &t);
    for(i=1;i<=t;i++){

        cnt = 0;
        ans = 0;
        res = 0;
        memset(tree, 0, sizeof tree);
        memset(a, 0, sizeof a);

        scanf("%d", &n);
        for(j=0;j<n;j++)
            scanf("%d", &a[j]);

        vector<int> b(a, a+n);
        map<int, int>m;

        sort(b.begin(), b.end());

        for(j=0;j<n;j++){
            if(m.count(b[j])==0){
                m[b[j]] = ++cnt;
            }
        }
        for(j=0;j<n;j++){
            res = query(m[a[j]]-1) + 1;
            ans = (ans + res) % MOD;
            update(m[a[j]], res);
        }
        printf("Case %d: %d\n",i, ans);
    }

    return 0;
}
