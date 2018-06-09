#include<bits/stdc++.h>
using namespace std;

int josephus(int n, int k)
{
    if(n==1)
        return 0;
    return (josephus(n-1, k)+k)%n; /// Remainder is taken to limit the indices below n
}
int main()
{
    int i, j, k, n, t, ans;
    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
        scanf("%d%d", &n, &k);
        ans = josephus(n, k)+1;    /// This gives the solution in 0 indexing system,
                                   /// To get answer in 1 indexing system we have to add 1 to ans

        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}

