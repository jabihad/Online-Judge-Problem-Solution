// https://en.wikipedia.org/wiki/Rook_polynomial
/*
The classical rooks problem immediately gives the value of r8, the coefficient in front of the highest order term of the rook polynomial.
Indeed, its result is that 8 non-attacking rooks can be arranged on an 8 × 8 chessboard in r8 = 8! = 40320 ways.
Let us generalize this problem by considering an m × n board, that is, a board with m ranks (rows) and n files (columns).
The problem becomes: In how many ways can one arrange k rooks on an m × n board in such a way that they do not attack each other?
It is clear that for the problem to be solvable, k must be less or equal to the smaller of the numbers m and n; otherwise one cannot avoid
placing a pair of rooks on a rank or on a file. Let this condition be fulfilled.
Then the arrangement of rooks can be carried out in two steps.
First, choose the set of k ranks on which to place the rooks. Since the number of ranks is m, of which k must be chosen, 
this choice can be done in ncr(m, k) ways.
Similarly, the set of k files on which to place the rooks can be chosen in ncr(n, k) ways.
Because the choice of files does not depend on the choice of ranks, according to the products rule there are
ncr(m, k) * ncr(n, k) ways to choose the square on which to place the rook.
However, the task is not yet finished because k ranks and k files intersect in k2 squares.
By deleting unused ranks and files and compacting the remaining ranks and files together, one obtains a new board of k ranks and k files.
It was already shown that on such board k rooks can be arranged in k! ways (so that they do not attack each other).
Therefore, the total number of possible non-attacking rooks arrangements is:
ncr(n, k) * ncr(m, k) * k!
*/
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

ll dp[31][31], fact[31];
ll ncr(ll n, ll k)
{
    if(k==1)
        return n;
    if(n==k)
        return 1;
    if(dp[n][k]!=-1)
        return dp[n][k];
    if(k==0)
        return dp[n][n];

    return dp[n][k] = ncr(n-1, k-1) + ncr(n-1, k);
}
int main()
{
    ll i, j, k, t, n;
    scanf("%lld", &t);
    memset(dp, -1, sizeof(dp));
    fact[0] = 1;
    for(i=1;i<=30;i++)
        fact[i] = fact[i-1]*i;
    for(i=1;i<=t;i++){
        scanf("%lld%lld", &n, &k);
        if(k>n){
            printf("Case %lld: 0\n", i);
            continue;
        }
        ll ans = ncr(n, k) * ncr(n, k) * fact[k];

        printf("Case %lld: %lld\n", i, ans);

    }
    return 0;
}
