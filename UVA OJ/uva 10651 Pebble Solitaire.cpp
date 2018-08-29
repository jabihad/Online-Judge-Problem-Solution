#include<bits/stdc++.h>
using namespace std;

int m=12, dp[1<<17 + 2];
int Set(int N, int pos)
{
    return N = N | (1<<pos);
}
int reset(int N, int pos)
{
    return N = N & ~(1<<pos);
}
bool check(int N, int pos)
{
    return (bool) (N & (1<<pos));
}
int bitCount(int mask)
{
    int bits = __builtin_popcount(mask);
    if(bits==m)
        return bits;
    for(int i=0;i<m-1;i++)
        if((mask & 1<<i)!=0 && (mask & 1<<(i+1))!=0)
           return -1;
    return bits;
}
int call(int mask)
{
    int bits, ans;
    if(dp[mask]!=-1)
        return dp[mask];
    bits = bitCount(mask);
    if(bits!=-1)
        return dp[mask] = bits;
    ans = 1<<28;
    for(int i=0;i<m;i++){
        if(check(mask, i) && check(mask, i+1)){
            if(i+2<m && check(mask, i+2)==0){
                bits = reset(mask, i);
                bits = reset(bits, i+1);
                bits = Set(bits, i+2);
                ans = min(call(bits), ans);
            }
            if(i-1>=0 && check(mask, i-1)==0){
                bits = reset(mask, i+1);
                bits = reset(bits, i);
                bits = Set(bits, i-1);
                ans = min(call(bits), ans);
            }
        }
    }
    return dp[mask] = ans;
}

int main()
{
    int i, j, k, t, mask, ans, l;
    string s;
    cin>>t;
    for(i=1;i<=t;i++){
        memset(dp, -1, sizeof(dp));
        mask = 0;
        cin>>s;
        for(j=0;s[j];j++)
            if(s[j]=='o')
               mask = Set(mask, j);
        ans = call(mask);

        cout<<ans<<endl;
    }
    return 0;
}
