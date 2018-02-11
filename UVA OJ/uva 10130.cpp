#include<bits/stdc++.h>
using namespace std;
int dp[1110][1110],weight[1100],price[1100];
int cap,n;
int f(int i,int w)
{
    if(i==n+1)return 0;
    if(dp[i][w]!=-1)return dp[i][w];
    int profit1=0,profit2=0;
    if(w+weight[i]<=cap)
        profit1=price[i]+f(i+1,w+weight[i]);
    profit2 = f(i+1,w);
    dp[i][w]=max(profit1,profit2);
    return dp[i][w];
}
int main()
{
    int i,t,g,r=0;
    cin>>t;
    while(t--){
    r=0;
	cin>>n;
	for(i=1;i<=n;i++)
	   cin>>price[i]>>weight[i];
    cin>>g;
    for(i=1;i<=g;i++){
        memset(dp,-1,sizeof(dp));
        cin>>cap;
        r += f(1,0);
     }
    cout<<r<<endl;
    }
return 0;
}

