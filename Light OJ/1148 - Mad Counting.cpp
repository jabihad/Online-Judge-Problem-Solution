#include<bits/stdc++.h>
using namespace std;

int ara[1000100];
int main()
{
    int i, j, k, n, t, x, res, tmp;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
        scanf("%d",&n);
        set<int>s;
        set<int>::iterator it;
        res = 0;
        for(j=1;j<=n;j++){
            scanf("%d",&x);
            ara[x]++;
            s.insert(x);
        }
        for(it=s.begin();it!=s.end();it++){
            tmp = *it;
            if(ara[tmp]<=tmp + 1){
                res += tmp + 1;
            }
            else{
                res += ((ara[tmp]+tmp)/(tmp+1)) * (tmp+1);
            }
        ara[tmp] = 0;
        }
        printf("Case %d: %d\n",i, res);
    }
    return 0;
}
