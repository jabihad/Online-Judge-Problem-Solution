#include<bits/stdc++.h>

using namespace std;
int main()
{
    int i,j,n,k,r,on;
    cin>>n;
    for(i=1;i<=n;i++){
            cin>>k;on=0;
    for(j=1;;j++){
        r=k%2;
        if(r==1)on++;
        k/=2;
        if(k==0)break;
    }
    if(on%2==0)
        printf("Case %d: even\n",i);
    else
        printf("Case %d: odd\n",i);

    }

return 0;
}
