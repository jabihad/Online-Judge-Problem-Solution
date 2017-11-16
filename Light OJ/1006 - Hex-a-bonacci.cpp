#include<stdio.h>

long long int dp[78090],i;

long long int a, b, c, d, e, f;
long long int fn( long long int n ) {
         if( n == 0 ) dp[n]=a;
    else if( n == 1 ) dp[n]=b;
    else if( n == 2 ) dp[n]=c;
    else if( n == 3 ) dp[n]=d;
    else if( n == 4 ) dp[n]=e;
    else if( n == 5 ) dp[n]=f;
    else if(dp[n]==-1)
{dp[n]=((fn(n-1))%10000007 + (fn(n-2))%10000007 + (fn(n-3))%10000007 +(fn(n-4))%10000007 +(fn(n-5))%10000007 + (fn(n-6))%10000007);return dp[n];}
    return  dp[n];
}
int main() {
    long long int n, caseno = 0, cases;
    scanf("%lld", &cases);
    while( cases-- ) {for(i=0;i<=15000;i++)dp[i]=-1;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &e, &f, &n);
        printf("Case %lld: %lld\n", ++caseno, fn(n)%10000007);
    }
    return 0;
}
