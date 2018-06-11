#include<bits/stdc++.h>
using namespace std;

int mark[10015], nprime, prime[2000], factor[10015];
string s;
void sieve (int n)
{
    int i,j,limit=sqrt(n*1.)+2;
    mark[1]=1;
    prime[nprime++]=2;
    for(i=4; i<=n; i+=2)mark[i]=1;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            prime[nprime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=2*i)
                {
                    mark[j]=1;
                }
            }
        }
    }
}
void factorize(int num)
{
    int i, j, k, p;
    for(i=0;i<nprime && (prime[i]*prime[i])<=num;i++){
        p = 0;
        if(num%prime[i]==0){
            while(num%prime[i]==0){
                num /= prime[i];
                p++;
            }
            factor[prime[i]] = max(factor[prime[i]], p);
        }
    }
    if(num>1)factor[num] = max(factor[num], 1);
}
void multiply(int n)
{
    int i, carry = 0;
    for(i=0;i<s.size();i++){
        carry += (s[i]-48)*n;
        s[i] = (carry%10) + 48;
        carry /= 10;
    }
    while(carry){
        s += (carry % 10 + 48);
        carry /= 10;
    }
}
int main()
{
    int i, j, l, t, n, x;
    sieve(10005);
    scanf("%d", &t);
    for(i=1;i<=t;i++){
        s = "1";
        memset(factor, 0, sizeof(factor));
        scanf("%d", &n);
        for(j=1;j<=n;j++){
            scanf("%d", &x);
            factorize(x);
        }
        for(j=0;j<nprime;j++){
            if(factor[prime[j]]==0)
                continue;

            for(l=1;l<=factor[prime[j]];l++){
                multiply(prime[j]);
            }
        }
        reverse(s.begin(), s.end());
        printf("Case %d: ", i);
        cout<<s<<endl;
    }

    return 0;
}
