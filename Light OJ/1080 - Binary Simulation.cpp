#include<bits/stdc++.h>
using namespace std;

int tree[100100], n;
int query(int idx)
{
    int sum = 0;
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
void range_update(int a, int b)
{
    update(a, 1);
    update(b+1, -1);
}
int main()
{
    int i, j, k, t, q, u, a, b;
    char s[100100], ch[3];

    scanf("%d", &t);
    for(i=1;i<=t;i++){
        memset(tree, 0, sizeof(tree));

        scanf("%s", s);
        getchar();

        n = strlen(s);

        scanf("%d", &q);
        getchar();

        printf("Case %d:\n", i);

        for(k=1;k<=q;k++){
            scanf("%s", ch);
            getchar();

            if(strcmp(ch,"I")==0){
                scanf("%d%d", &a, &b);
                range_update(a, b);
            }
            else{
                scanf("%d", &a);
                if(s[a-1]=='1')
                    printf("%d\n", 1^(query(a)%2));
                else
                    printf("%d\n", query(a)%2);
            }
        }
    }
    return 0;
}
